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

        manaCnt(std::string * c, short cnt) : color(c), count(cnt) {
        }
    };

    using layout_t = std::string *;
    using name_t = std::string;
    using names_t = std::vector<std::string>;
    using manaCost_t = std::vector<manaCnt>;
    using colors_t = std::vector<std::string *>;
    using supertypes_t = std::vector<std::string *>;
    using types_t = std::vector<std::string *>;
    using subtypes_t = std::vector<std::string *>;
    using text_t = std::string;
    using power_t = int;
    using toughness_t = int;
    using loyalty_t = int;
    using hand_t = int;
    using life_t = int;

    using card_t = const nlohmann::basic_json<std::map, std::vector,
            std::__cxx11::basic_string<char, std::char_traits<char>,
            std::allocator<char> >, bool, long, unsigned long, double,
            std::allocator, nlohmann::adl_serializer> &;

    // Forward declaration, avoiding cycle dependencies.
    class Database;

    class Card {
    private:
        Database * db;
        const layout_t layout;
        const name_t name;
        const names_t names;
        const manaCost_t manaCost;
        const colors_t colors;
        const supertypes_t supertypes;
        const types_t types;
        const subtypes_t subtypes;
        const text_t text;
        const power_t power;
        const toughness_t toughness;
        const loyalty_t loyalty;
        const hand_t hand;
        const life_t life;

    public:
//        // After quite long time spent by trying to solve this nicely, 
//        // I decided for a macro. #sorryjako
//#define SET(attr, fail) if (card.find("attr") != card.end()) attr = card["attr"]; else attr = fail

        Card(const card_t & card, Database * dat) :
        db(dat),
        name(set_name(card)),
        text(set_text(card)),
        power(set_power(card)),
        toughness(set_toughness(card)),
        loyalty(set_loyalty(card)),
        hand(set_hand(card)),
        life(set_life(card)),
        layout(parse_layout(card)),
        names(parse_names(card)),
        manaCost(parse_manaCost(card)),
        colors(parse_colors(card)),
        supertypes(parse_supertypes(card)),
        types(parse_types(card)),
        subtypes(parse_subtypes(card)) {
        }

        layout_t get_layout() const;
        name_t get_name() const;
        names_t get_names() const;
        manaCost_t get_manaCost() const;
        colors_t get_colors() const;
        supertypes_t get_supertypes() const;
        types_t get_types() const;
        subtypes_t get_subtypes() const;
        text_t get_text() const;
        power_t get_power() const;
        toughness_t get_toughness() const;
        loyalty_t get_loyalty() const;
        hand_t get_hand() const;
        life_t get_life() const;

    private:
        layout_t
        parse_layout(const card_t & card);

        names_t
        parse_names(const card_t & card);

        manaCost_t
        parse_manaCost(const card_t & card);

        colors_t
        parse_colors(const card_t & card);

        supertypes_t
        parse_supertypes(const card_t & card);

        types_t
        parse_types(const card_t & card);

        subtypes_t
        parse_subtypes(const card_t & card);

        std::string
        get_mana_symbol(std::string & s);

        name_t
        set_name(const card_t & card) {
            name_t x;
            if (card.find("name") != card.end()) {
                x = card["name"];
                return x;
            }
            else
                return "";
        }

        text_t
        set_text(const card_t & card) {
            text_t x;
            if (card.find("text") != card.end()) {
                x = card["text"];
                return x;
            }
            else
                return "";
        }

        power_t
        set_power(const card_t & card) {
            power_t x;
            if (card.find("power") != card.end()) {
                x = card["power"];
                return x;
            }
            else
                return INT_MIN;
        }

        toughness_t
        set_toughness(const card_t & card) {
            toughness_t x;
            if (card.find("toughness") != card.end()) {
                x = card["toughness"];
                return x;
            }
            else
                return INT_MIN;
        }

        loyalty_t
        set_loyalty(const card_t & card) {
            loyalty_t x;
            if (card.find("loyalty") != card.end()) {
                x = card["loyalty"];
                return x;
            }
            else
                return INT_MIN;
        }

        hand_t
        set_hand(const card_t & card) {
            hand_t x;
            if (card.find("hand") != card.end()) {
                x = card["hand"];
                return x;
            }
            else
                return INT_MIN;
        }

        life_t
        set_life(const card_t & card) {
            life_t x;
            if (card.find("life") != card.end()) {
                x = card["life"];
                return x;
            }
            else
                return INT_MIN;
        }
    };
}
#endif /* CARD_HPP */

