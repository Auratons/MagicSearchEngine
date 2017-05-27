#include <thread>
#include <utility>
#include <istream>
#include <map>

#include "database.hpp"
#include "ui.hpp"
#include "searching.hpp"
#include "../docopt.cpp/docopt.h"

using namespace magicSearchEngine;
using namespace std;


static const char USAGE[] =
        R"(Magic Search Engine.

    Usage:
      MagicSearchEngine find <name>
      MagicSearchEngine similar <name> [<number>]
      MagicSearchEngine (-h | --help)
      MagicSearchEngine --interactive
      MagicSearchEngine --version

    Options:
      <number>          Number of cards returned [default: 3].
      -h --help         Show this screen.
      --interactive     Run interactive mode (type 'help' there).
      --version         Show version.
)";

static const char USAGE_INTERACTIVE[] =
        R"(Magic Search Engine, interactive mode.

    Usage:
      find <name>
      similar <name> [<number>]
      MagicSearchEngine (h | help)


    Options:
      <number>          Number of cards returned [default: 3].
      -h --help         Show this screen.
)";

inline void
find(const JSONDatabase & database,
        search_engine & oraculum,
        thread & data_loading,
        const string & name) {
    if (!database.is_ready()) {
        data_loading.join();
    }
    auto res = oraculum.search_for(name);
    if (res == nullptr) {
        cout << "Demanded card was not found." << endl;
    }
    else {
        cout << *(res) << endl;
    }
}

inline void
similar(const JSONDatabase & database,
        search_engine & oraculum,
        thread & data_loading,
        const string & name,
        const string & count) {
    // Parsing count.
    int cnt = 1;
    try {
        cnt = stoi(count);
        if (cnt < 1) {
            cout << "Number must be a positive integer." << endl;
            return;
        }
    }
    catch (...) {
        cout << USAGE << endl;
        return;
    }
    // Is db loaded?
    if (!database.is_ready()) {
        data_loading.join();
    }
    // Searching.
    vector<const Card *> res;
    res = oraculum.find_similar(name, cnt); // Here cnt is >= 1.
    if (res.size() == 0) {
        cout << "Demanded card was not found." << endl;
    }
    else {
        for (const Card * card : res) {
            cout << (*card) << endl;
        }
    }
}

inline void
interactive_mode(const JSONDatabase & database,
        search_engine & oraculum,
        thread & data_loading) {
    console cmd_ui(cin);
    while (true) {
        const auto & c = cmd_ui.get_cmd();
        switch (c.first) {
            case cmd::error:
            case cmd::parse_error:
                cout << "Error while parsing last input. Use command \"help\"." << endl;
            case cmd::help:
                cout << USAGE_INTERACTIVE << endl;
                break;
            case cmd::end_of_input:
            case cmd::exit:
                return;
            case cmd::none:
                this_thread::yield();
                break;
            case cmd::find:
            {
                find(database, oraculum, data_loading, c.second[1]);
                break;
            }
            case cmd::similar:
            {
                if (c.second.size() == 2)
                    similar(database, oraculum, data_loading, c.second[1], "3");
                else
                    similar(database, oraculum, data_loading, c.second[1], c.second[2]);
                break;
            }
            default:
                this_thread::yield();
                break;
        }
    }
}

int
main(int argc, char * argv[]) {
    JSONDatabase database;
    search_engine oraculum(database);
    // We expect enough space between running this program and writing the first
    // command in interactive mode. So for fluency, we run a new thread doing
    // expensive methods separately and after command processing we only check,
    // that the user was not too fast. In case, we join the thread and simply wait.
    thread data_loading([&]() {
        database.load_database();
        oraculum.create_index();
    });

    map<string, docopt::value> args = docopt::docopt(USAGE,{argv + 1, argv + argc},
    true, // show help if requested
    "Magic Search Engine 1.0"); // version string

    if (args["find"].asBool()) {
        find(database, oraculum, data_loading, args["<name>"].asString());
    }
    else if (args["similar"].asBool()) {
        if (!args["<number>"]) {
            similar(database, oraculum, data_loading, args["<name>"].asString(), "3");
        }
        else {
            similar(database, oraculum, data_loading, args["<name>"].asString(), args["<number>"].asString());
        }
    }
    else if (args["--interactive"].asBool()) {
        interactive_mode(database, oraculum, data_loading);
    }
    
    // Avoiding destruction of detachable thread in case of script mode with
    // wrong input parameters (i.g. negative number). In this way detached
    // thread is killed with main() instead of terminating program with thread
    // exception.    
    if (data_loading.joinable())
        data_loading.detach();

    return 0;
}
