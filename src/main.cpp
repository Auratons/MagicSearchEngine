#include <thread>
#include <utility>
#include <istream>

#include "database.hpp"
#include "ui.hpp"
#include "searching.hpp"

using namespace magicSearchEngine;
using namespace std;

int
main(int argc, char *argv[]) {
    JSONDatabase database;
    search_engine oraculum(database);
    // We expect enough space between running this program and writing the first
    // command within its interface. So for fluency, we run a new thread doing
    // expensive methods separately and after command processing we only check,
    // that the user was not too fast. In case, we join the thread and simply wait.
    thread data_loading([&]() {
        database.load_database();
        oraculum.create_index();
    });
    console cmd_ui(cin);

    while (true) {
        auto command = cmd_ui.get_cmd();
        switch (command.first) {
            case cmd::error:
            case cmd::parse_error:
                cmd_ui.bad_input();
            case cmd::end_of_input:
            case cmd::exit:
                return 0;
            case cmd::none:
                this_thread::yield();
                break;
            case cmd::find:
            {
                if (!database.is_ready()) {
                    data_loading.join();
                }
                auto res = oraculum.search_for(command.second[1]);
                if (res == nullptr) {
                    cout << "Demanded card was not found." << endl;
                }
                else {
                    cout << *(res) << endl;
                }
                break;
            }
            case cmd::similar:
            {
                if (!database.is_ready()) {
                    data_loading.join();
                }
                auto && res = oraculum.find_similar(command.second[1], 3);
                if (res.size() == 0) {
                    cout << "Demanded card was not found." << endl;
                }
                for (auto && card : res) {
                    cout << *card << endl;
                }
            }
            default:
                this_thread::yield();
                break;
        }
    }
}
