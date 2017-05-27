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

/* 
 * File:   ui.hpp
 * Author: Thomas Kremel
 *
 * Created on May 16, 2017, 3:02 PM
 */

#ifndef UI_HPP
#define UI_HPP

#include <iostream>
#include <vector>
#include <string>
#include <utility>

namespace magicSearchEngine {

    enum class cmd {
        end_of_input,
        none,
        exit,
        error,
        parse_error,
        find,
        similar,
        help
    } ;

    class user_interface {
    public:
        virtual std::pair<cmd, std::vector<std::string> >
        get_cmd() = 0;

        virtual
        ~user_interface() {
        }
    } ;

    class console : public user_interface {
    private:
        std::istream & is;

    public:

        explicit
        console(std::istream & is_) : is(is_) {
        }

        std::pair<cmd, std::vector<std::string> >
        get_cmd() override;

        ~console() {
        }

    private:
        std::vector<std::string>
        parse_line(const std::string &);
    } ;
}

#endif /* UI_HPP */

