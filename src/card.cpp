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

#include <exception>
#include <string>
#include <vector>
#include "src/card.hpp"
#include "src/database.hpp"

namespace magicSearchEngine {

    /*
     * Some of these can be traits-templated, maybe in the future.
     */
    layout_t
    Card::parse_layout(const card_t & card) {
        const auto & layouts = db->get_layout();
        try {
            if (card.find("layout") != card.end())
                return const_cast<layout_t>(&(layouts.at(card["layout"])));
        } catch (const std::out_of_range &) {
            std::string msg = "Layout of " + name +
                    " does not refer to any layout in the database, check rules.";
            throw std::out_of_range(msg);
        }
        return nullptr;
    }

    names_t
    Card::parse_names(const card_t & card) {
        std::vector<std::string> names;
        if (card.find("names") != card.end()) {
            for (const auto & name : card["names"])
                names.push_back(name);
        }
        return std::move(names);
    }

    /*
     * This method expects that all mana types of one kind are in row for a card.
     */
    manaCost_t
    Card::parse_manaCost(const card_t & card) {
        const auto & db_mana = db->get_mana();
        manaCost_t cards_cost;
        try {
            if (card.find("manaCost") != card.end()) {
                std::string manaCost = card["manaCost"];
                const std::string & str = get_mana_symbol(manaCost);
                while (str.size() != 0) {
                    const auto & mana_s = const_cast<const std::map<std::string, std::string> &>(db_mana[str];
                    if (cards_cost.size() == 0 || *(cards_cost[cards_cost.size() - 1].color) != mana_s) {
                        cards_cost.emplace_back(mana_s, 1);
                    } else
                        cards_cost[cards_cost.size() - 1].count++;
                    str = get_mana_symbol(manaCost);
                }

            }
        } catch (const std::out_of_range &) {
            std::string msg = "One of mana symbols of " + name +
                    " does not refer to any mana symbol in the database, check rules.";
            throw std::out_of_range(msg);
        }
        return std::move(cards_cost);
    }

    /*
     * This method does not check validity of mana string from db.
     */
    const std::string
    Card::get_mana_symbol(std::string & s) {
        std::string mana;
        if (s.size() != 0) {
            size_t i = 1;
            while (s[i] != '}') {
                mana.append(&s[i]);
                ++i;
            }
            s.erase(0, i + 1);
        }
        return std::move(mana);
    }

    colors_t
    Card::parse_colors(const card_t & card) {
        const auto & db_colors = db->get_colors();
        colors_t card_colors;
        try {
            if (card.find("colors") != card.end()) {
                for (auto && color : card["colors"])
                    card_colors.push_back(&(db_colors.at(color)));
            }
        } catch (const std::out_of_range &) {
            std::string msg = "One of colors of " + name +
                    " does not refer to any color in the database, check rules.";
            throw std::out_of_range(msg);
        }
        return std::move(card_colors);
    }

    supertypes_t
    Card::parse_supertypes(const card_t & card) {
        const auto & db_supertypes = db->get_supertypes();
        supertypes_t card_supertypes;
        try {
            if (card.find("supertypes") != card.end()) {
                for (auto && supertype : card["supertypes"])
                    card_supertypes.push_back(&(db_supertypes.at(supertype)));
            }
        } catch (const std::out_of_range &) {
            std::string msg = "One of supertypes of " + name +
                    " does not refer to any supertype in the database, check rules.";
            throw std::out_of_range(msg);
        }
        return std::move(card_supertypes);
    }

    types_t
    Card::parse_types(const card_t & card) {
        const auto & db_types = db->get_types();
        types_t card_types;
        try {
            if (card.find("types") != card.end()) {
                for (auto && type : card["types"])
                    card_types.push_back(&(db_types.at(type)));
            }
        } catch (const std::out_of_range &) {
            std::string msg = "One of types of " + name +
                    " does not refer to any type in the database, check rules.";
            throw std::out_of_range(msg);
        }
        return std::move(card_types);
    }

    subtypes_t
    Card::parse_subtypes(const card_t & card) {
        const auto & db_subtypes = db->get_subtypes();
        subtypes_t card_subtypes;
        try {
            if (card.find("subtypes") != card.end()) {
                for (auto && subtype : card["subtypes"])
                    card_subtypes.push_back(&(db_subtypes.at(subtype)));
            }
        } catch (const std::out_of_range &) {
            std::string msg = "One of subtypes of " + name +
                    " does not refer to any subtype in the database, check rules.";
            throw std::out_of_range(msg);
        }
        return std::move(card_subtypes);
    }

    /*
     * Only getters follows.
     */

    layout_t
    Card::get_layout() const {
        return layout;
    }

    name_t
    Card::get_name() const {
        return name;
    }

    names_t
    Card::get_names() const {
        return names;
    }

    manaCost_t
    Card::get_manaCost() const {
        return manaCost;
    }

    colors_t
    Card::get_colors() const {
        return colors;
    }

    supertypes_t
    Card::get_supertypes() const {
        return supertypes;
    }

    types_t
    Card::get_types() const {
        return types;
    }

    subtypes_t
    Card::get_subtypes() const {
        return subtypes;
    }

    text_t
    Card::get_text() const {
        return text;
    }

    power_t
    Card::get_power() const {
        return power;
    }

    toughness_t
    Card::get_toughness() const {
        return toughness;
    }

    loyalty_t
    Card::get_loyalty() const {
        return loyalty;
    }

    hand_t
    Card::get_hand() const {
        return hand;
    }

    life_t
    Card::get_life() const {
        return life;
    }
}

