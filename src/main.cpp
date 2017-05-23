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
    database.load_database();
    search_engine oraculum(database);
    oraculum.create_index();
    console cmd_ui(cin);

    while (true) {
        auto command = cmd_ui.get_cmd();
        switch (command.first) {
            case cmd::error:
                cmd_ui.bad_input();
                return 1;
            case cmd::end_of_input:
            case cmd::exit:
                return 0;
            case cmd::none:
                this_thread::yield();
                break;
            case cmd::find:
            {
                auto res = oraculum.search_for(command.second[1]);
                if (res == nullptr)
                    cout << "Demanded card was not found." << endl;
                else
                    cout << *(res) << endl;
                break;
            }
            default:
                this_thread::yield();
                break;
        }
    }
}
