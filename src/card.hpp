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
 * File:   card.hpp
 * Author: Thomas Kremel
 *
 * Created on 24 March 2017, 14:35
 */

#ifndef CARD_HPP
#define CARD_HPP

#include <string>
#include <vector>
#include <limits.h>
#include "src/json.hpp"

namespace magicSearchEngine {

    struct manaCnt {
    public:
        const std::string * color;
        short count;

        manaCnt(const std::string * c, short cnt) : color(c), count(cnt) {
        }

        friend std::ostream & operator<<(std::ostream & os, const manaCnt & m);
    } ;

    inline std::ostream & operator<<(std::ostream & os, const manaCnt & m) {
        os << *(m.color) << ": " << m.count;
    }

    struct feature {
        int whole_part;
        bool half;
        bool asterics;

        feature() : whole_part(INT_MIN), half(false), asterics(false) {
        }

        feature(int wp, bool hf, bool as) : whole_part(wp), half(hf), asterics(as) {
        }

        friend std::ostream & operator<<(std::ostream & os, const feature & f);
    } ;

    inline std::ostream & operator<<(std::ostream & os, const feature & f) {
        if (f.whole_part != INT_MIN)
            os << f.whole_part;
        if (f.half)
            os << ".5";
        if (f.whole_part != INT_MIN && f.asterics)
            os << "+*";
        if (f.asterics)
            os << "*";
    }

    using layout_t     = std::string;                       // Default: ""
    using name_t       = std::string;                       // Default: ""
    using names_t      = std::vector<std::string>;
    using manaCost_t   = std::vector<manaCnt>;
    using colors_t     = std::vector<const std::string *>;
    using supertypes_t = std::vector<const std::string *>;
    using types_t      = std::vector<const std::string *>;
    using subtypes_t   = std::vector<const std::string *>;
    using text_t       = std::string;                       // Default: ""
    using power_t      = feature;                           // Default: {INT_MIN, false, false}
    using toughness_t  = feature;                           // Default: {INT_MIN, false, false}
    using loyalty_t    = int;                               // Default: INT_MIN
    using hand_t       = int;                               // Default: INT_MIN
    using life_t       = int;                               // Default: INT_MIN
    using card_t       = const nlohmann::basic_json<std::map, std::vector,
            std::__cxx11::basic_string<char, std::char_traits<char>,
            std::allocator<char> >, bool, long, unsigned long, double,
            std::allocator, nlohmann::adl_serializer> &;

    // Forward declaration, avoiding cycle dependencies.
    class Database;

    class Card {
    private:
        const Database* db;
        layout_t        layout;
        name_t          name;
        names_t         names;
        manaCost_t      manaCost;
        colors_t        colors;
        supertypes_t    supertypes;
        types_t         types;
        subtypes_t      subtypes;
        text_t          text;
        power_t         power;
        toughness_t     toughness;
        loyalty_t       loyalty;
        hand_t          hand;
        life_t          life;

    public:
        Card(const card_t & card, const Database * dat);
        friend std::ostream & operator<<(std::ostream &, const Card &) ;
        /*
         * Getters.
         */
        const layout_t &     get_layout() const;
        const name_t &       get_name() const;
        const names_t &      get_names() const;
        const manaCost_t &   get_manaCost() const;
        const colors_t &     get_colors() const;
        const supertypes_t & get_supertypes() const;
        const types_t &      get_types() const;
        const subtypes_t &   get_subtypes() const;
        const text_t &       get_text() const;
        const power_t &      get_power() const;
        const toughness_t &  get_toughness() const;
        const loyalty_t &    get_loyalty() const;
        const hand_t &       get_hand() const;
        const life_t &       get_life() const;

    private:
        /*
         * Setters. JSON card record can, but mustn't contain field, so the
         * following methods must check presence of given field and if absent,
         * fill card with some predefined default variable (see usings above).
         */
        void set_name(const card_t & card);
        void set_text(const card_t & card);
        void set_power(const card_t & card);
        void set_toughness(const card_t & card);
        void set_loyalty(const card_t & card);
        void set_hand(const card_t & card);
        void set_life(const card_t & card);
        // Following setters parse more complicated input (slower).
        void set_layout(const card_t & card);
        void set_names(const card_t & card);
        void set_manaCost(const card_t & card);
        void set_colors(const card_t & card);
        void set_supertypes(const card_t & card);
        void set_types(const card_t & card);
        void set_subtypes(const card_t & card);

        // An auxiliary method for set_manaCost.
        std::string
        get_mana_symbol(std::string & s);
    } ;
}
#endif /* CARD_HPP */

