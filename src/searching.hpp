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
 * File:   searching.hpp
 * Author: Thomas Kremel
 *
 * Created on May 16, 2017, 10:32 PM
 */

#ifndef SEARCHING_HPP
#define SEARCHING_HPP

#include <set>
#include "database.hpp"
#include "card.hpp"

namespace magicSearchEngine {

    class search_engine {
    private:
        const Database & db;
        std::vector<std::set<std::string> > index;
        bool index_was_loaded;

    public:

        search_engine(const Database & db_) : db(db_), index_was_loaded(false) {
        }

        void
        create_index();

        const Card *
        search_for(const std::string &);

        std::vector<const Card *>
        find_similar(const std::string &, size_t cnt);

        std::vector<const Card *>
        get_type(const std::string &);

    private:
        size_t
        get_distance(const Card *, const Card *);

        size_t
        full_text(const Card * card, const Card * base_card);
    } ;
}

#endif /* SEARCHING_HPP */

