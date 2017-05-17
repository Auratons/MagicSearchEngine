/*
 * MIT License
 *
 * Copyright (c) 2017 Thomas Kremel
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */


#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include "ui.hpp"

using namespace std;

namespace magicSearchEngine {

    std::pair<cmd, vector<string>> 
    console::get_cmd() {
        string input;
        vector<string> opts;
        getline(is, input);
        if (is.eof())
            return make_pair(cmd::end_of_input, opts);
        if (is.fail())
            return make_pair(cmd::error, opts);
        if (input == "exit" || input == "quit" || input == "q")
            return make_pair(cmd::exit, opts);
        opts = parse_line(input);
        if (opts[0] == "find")
            return make_pair(cmd::find, opts);

        return make_pair(cmd::none, opts);
    }

    vector<string>
    console::parse_line(const string & line) {
        auto stream = stringstream(line);
        string op;
        size_t l = 0;
        vector<string> res;
        stream >> op; // Jump over the command itself.
        res.push_back(op);
        l += op.size();
        while (l != line.size()) {
            stream >> op;
            res.push_back(op);
            l = l + op.size() + 1; // +1 for space
        }
        return std::move(res);
    }
}