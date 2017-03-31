This is a similarity search engine devoted to finding
Magic: The Gathering cards similar to specified one.

For compilation following must be done:

The cards' database can be downloaded via wget for instance from:
    https://mtgjson.com/json/AllCards.json.zip
Unzipped .json must be saved to src/ folder.

For operating json files you need to download
    https://raw.githubusercontent.com/nlohmann/json/develop/src/json.hpp
and save it also to src/ folder.

Then: 
    ./bootstrap.sh && ./configure && make.
For debugging purposes run instead of bare ./configure:
    ./configure --prefix=/debug CPPFLAGS=-DDEBUG CXXFLAGS="-g -O0"
