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
        if (opts.size() == 0)
            return make_pair(cmd::parse_error, opts);
        if (opts[0] == "find")
            return make_pair(cmd::find, opts);
        if (opts[0] == "similar")
            return make_pair(cmd::similar, opts);

        return make_pair(cmd::none, opts);
    }

    void
    console::bad_input() {
        cout << "Error while parsing last input occured. Use command \"help\".";
        cout << endl;
    }

    vector<string>
    console::parse_line(const string & line) {
        vector<string> tokens;
        size_t line_length = line.length();
        bool double_quote = false;
        bool simple_quote = false;
        size_t token_length;
        char dq_letter = '\"';
        char sq_letter = '\'';
        char s_letter = ' ';
        for (size_t i = 0; i < line_length; i++) {
            size_t start = i;
            if (line[i] == dq_letter) {
                double_quote = true;
            }
            else if (line[i] == sq_letter) simple_quote = true;

            if (double_quote) {
                i++;
                start++;
                while (i < line_length && line[i] != dq_letter)
                    i++;
                if (i < line_length)
                    double_quote = false;
                token_length = i - start;
                i++;
            }
            else if (simple_quote) {
                i++;
                while (i < line_length && line[i] != sq_letter)
                    i++;
                if (i < line_length)
                    simple_quote = false;
                token_length = i - start;
                i++;
            }
            else {
                while (i < line_length && line[i] != s_letter)
                    i++;
                token_length = i - start;
            }
            tokens.push_back(line.substr(start, token_length));
        }
        if (double_quote || simple_quote) {
            cout << "One of the quotes is open." << endl;
            return vector<string>();
        }
        return move(tokens);
    }
}