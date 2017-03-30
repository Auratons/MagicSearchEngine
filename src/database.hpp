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
 * File:   database.hpp
 * Author: Thomas Kremel
 *
 * Created on 21 March 2017, 19:32
 */

#ifndef IDATABASEFETCH_HPP
#define IDATABASEFETCH_HPP

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "src/card.hpp"
#include "src/json.hpp"

namespace magicSearchEngine {
    using json = nlohmann::json;

    /*
     * Serves as a contract for all possible implementations
     * of database.
     */
    class Database {
    public:
        virtual void
        load_database() = 0;

        virtual std::vector<Card>
        get_cards() = 0;

        virtual std::map<std::string, std::string>
        get_types() = 0;

        virtual std::map<std::string, std::string>
        get_subtypes() = 0;

        virtual std::map<std::string, std::string>
        get_supertypes() = 0;

        virtual std::map<std::string, std::string>
        get_layout() = 0;

        virtual std::map<std::string, std::string>
        get_colors() = 0;

        virtual std::map<std::string, std::string>
        get_mana() = 0;

        virtual ~Database() {
        };
    };

    class JSONDatabase : public Database {
    private:
        std::vector<Card> cards;
        std::map<std::string, std::string> types;
        std::map<std::string, std::string> subtypes;
        std::map<std::string, std::string> supertypes;
        std::map<std::string, std::string> layout;
        std::map<std::string, std::string> colors;
        std::map<std::string, std::string> mana;

    public:
        void
        load_database() override;

        std::vector<Card>
        get_cards() override;

        std::map<std::string, std::string>
        get_types() override;

        std::map<std::string, std::string>
        get_subtypes() override;

        std::map<std::string, std::string>
        get_supertypes() override;

        std::map<std::string, std::string>
        get_layout() override;

        std::map<std::string, std::string>
        get_colors() override;

        std::map<std::string, std::string>
        get_mana() override;

        ~JSONDatabase() {
        }
    private:
        std::vector<Card>
        load_cards(const json & data);
    };
}

#endif /* IDATABASEFETCH_HPP */

