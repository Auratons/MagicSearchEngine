Magic Search Engine

This is a similarity search engine devoted to finding
Magic: The Gathering cards similar to specified one.

For compilation following must be done:

Note: the cards' database was retrieved via wget from:
    https://mtgjson.com/json/AllCards.json.zip
(Unzipped .json must be saved to src/ folder.)

For operating json files you need to download
    https://raw.githubusercontent.com/nlohmann/json/develop/src/json.hpp
and save it also to src/ folder. A submodule is not yet used because of 
size of nlohmann repository.

On the other hand, https://github.com/docopt/docopt.cpp is added as
a submodule, so for proper instantiation after cloning use:
git submodule init; git submodule update

Then: 
    ./bootstrap.sh && ./configure && make.
For debugging purposes run instead of bare ./configure:
    ./configure --prefix=/debug CPPFLAGS=-DDEBUG CXXFLAGS="-g -O0"
