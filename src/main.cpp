#include "database.hpp"

int
main(int argc, char *argv[])
{
    magicSearchEngine::JSONDatabase database;
    database.load_database();
}
