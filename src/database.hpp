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

#ifndef DATABASE_HPP
#define DATABASE_HPP

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "src/card.hpp"
#include "src/json.hpp"

namespace magicSearchEngine {

    /*
     * Serves as a contract for all possible implementations
     * of database.
     */
    class Database {
    public:        
        virtual void
        load_database() = 0;

        virtual std::vector<Card>
        get_cards() const = 0;

        virtual std::map<std::string, std::string>
        get_types() const = 0;

        virtual std::map<std::string, std::string>
        get_subtypes() const = 0;

        virtual std::map<std::string, std::string>
        get_supertypes() const = 0;

        virtual std::map<std::string, std::string>
        get_layout() const = 0;

        virtual std::map<std::string, std::string>
        get_colors() const = 0;

        virtual std::map<std::string, std::string>
        get_mana() const = 0;

        virtual ~Database() {
        };
    };

    class JSONDatabase : public Database {
    private:
        /* 
         * Question: Shall be used boolean indicator of already loaded
         * database or some magic with a static member? The first solution
         * needs if in each getter function which could have small-to-medium
         * performance decrease (frequent use of getters), but the 
         * second means allocating ~400 strings within construction of 
         * JSONDatabase object. In order the construction
         * to be cheap I decided to have a status boolean variable.
         */
        bool was_db_loaded = false;
        const char * db_not_loaded =
                "Database access before it was loaded. Firstly, call JSONDatabase::load_database().";

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
        get_cards() const override;

        std::map<std::string, std::string>
        get_types() const override;

        std::map<std::string, std::string>
        get_subtypes() const override;

        std::map<std::string, std::string>
        get_supertypes() const override;

        std::map<std::string, std::string>
        get_layout() const override;

        std::map<std::string, std::string>
        get_colors() const override;

        std::map<std::string, std::string>
        get_mana() const override;

        ~JSONDatabase() {
        }
    private:
        std::vector<Card>
        load_cards(const nlohmann::json & data);
    };

    /*
     * This exception is being used for throwing in case of 
     * unfinished initialization (of the JSONDatabase).
     */

    class bad_optional_access : public std::exception {
    protected:
        std::string msg;
    public:

        bad_optional_access(const std::string & str) : msg(str) {
        }

        virtual const char*
        what() const throw() {
            return msg.c_str();
        }
        
        ~bad_optional_access() throw() {}
    };
}

#endif /* DATABASE_HPP */

