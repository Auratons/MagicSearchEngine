#include <thread>
#include <utility>

#include "database.hpp"
#include "ui.hpp"
#include "searching.hpp"

using namespace magicSearchEngine;
using namespace std;

int
main(int argc, char *argv[])
{
    JSONDatabase database;
    database.load_database();
    search_engine oraculum(database);
    console cmd_ui(cin);
    
    while (true) {
        auto command = cmd_ui.get_cmd();
        switch (command.first) {
            case cmd::error:
                cout << "Error while parsing input occured." << endl;
                return 1;
            case cmd::end_of_input:
            case cmd::exit:
                return 0;
            case cmd::none:
                this_thread::yield();
                break;
            case cmd::find:
                auto res = oraculum.search_for(command.second[1]);
                if (res == nullptr)
                    cout << "Demanded card was not found" << endl;
                else
                    cout << *(res) << endl;
                break;
        }
    }
}
