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
#include <stdexcept>
#include <algorithm>
#include "src/card.hpp"
#include "src/database.hpp"

namespace magicSearchEngine {

    /*
     * Some of these can be traits-templated, maybe in the future.
     */
    const layout_t
    Card::parse_layout(const card_t & card) {
        const auto & layouts = db->get_layout();
        try {
            if (card.find("layout") != card.end()) {
                return const_cast<layout_t> (layouts.at(card["layout"]));
            }
        }
        catch (const std::out_of_range &) {
            std::string msg = "Layout of " + name +
                    " does not refer to any layout in the database, check rules.";
            throw std::out_of_range(msg);
        }
        return const_cast<layout_t> (layouts.at(""));
    }

    const names_t
    Card::parse_names(const card_t & card) {
        std::vector<std::string> names;
        if (card.find("names") != card.end()) {
            for (std::string name_ : card["names"]) {
                names.push_back(name_);
            }
        }
        return std::move(names);
    }

    /*
     * This method expects that all mana types of one kind are in row for a card.
     */
    const manaCost_t
    Card::parse_manaCost(const card_t & card) {
        const auto & db_mana = db->get_mana();
        manaCost_t cards_cost;
        try {
            if (card.find("manaCost") != card.end()) {
                std::string manaCost = card.at("manaCost");
                std::string str = get_mana_symbol(manaCost);
                while (str.size() != 0) {
                    const auto & mana_s = db_mana.at(str);
                    if (cards_cost.size() == 0 || *(cards_cost[cards_cost.size() - 1].color) != mana_s) {
                        cards_cost.push_back(manaCnt(&mana_s, 1));
                    }
                    else {
                        cards_cost[cards_cost.size() - 1].count++;
                    }
                    str = get_mana_symbol(manaCost);
                }

            }
        }
        catch (const std::out_of_range &) {
            std::string msg = "One of mana symbols of " + name +
                    " does not refer to any mana symbol in the database, check rules.";
            throw std::out_of_range(msg);
        }
        return std::move(cards_cost);
    }

    /*
     * This method does not check validity of mana string from db.
     * FIXME: Do you really change the parameter s?
     */
    std::string
    Card::get_mana_symbol(std::string & s) {
        std::string mana;
        if (s.size() != 0) {
            size_t i = 1;
            while (s[i] != '}') {
                mana.append(1, s[i]);
                ++i;
            }
            s.erase(0, i + 1);
        }
        return std::move(mana);
    }

    const colors_t
    Card::parse_colors(const card_t & card) {
        const auto & db_colors = db->get_colors();
        colors_t card_colors;
        try {
            if (card.find("colors") != card.end()) {
                for (const std::string & color : card["colors"]) {
                    card_colors.push_back(&(db_colors.at(color)));
                }
            }
        }
        catch (const std::out_of_range &) {
            std::string msg = "One of colors of " + name +
                    " does not refer to any color in the database, check rules.";
            throw std::out_of_range(msg);
        }
        return std::move(card_colors);
    }

    const supertypes_t
    Card::parse_supertypes(const card_t & card) {
        const auto & db_supertypes = db->get_supertypes();
        supertypes_t card_supertypes;
        try {
            if (card.find("supertypes") != card.end()) {
                for (const std::string & supertype : card["supertypes"]) {
                    card_supertypes.push_back(&(db_supertypes.at(supertype)));
                }
            }
        }
        catch (const std::out_of_range &) {
            std::string msg = "One of supertypes of " + name +
                    " does not refer to any supertype in the database, check rules.";
            throw std::out_of_range(msg);
        }
        return std::move(card_supertypes);
    }

    const types_t
    Card::parse_types(const card_t & card) {
        const auto & db_types = db->get_types();
        types_t card_types;
        try {
            if (card.find("types") != card.end()) {
                for (const std::string & type : card["types"]) {
                    card_types.push_back(&(db_types.at(type)));
                }
            }
        }
        catch (const std::out_of_range &) {
            std::string msg = "One of types of " + name +
                    " does not refer to any type in the database, check rules.";
            throw std::out_of_range(msg);
        }
        return std::move(card_types);
    }

    const subtypes_t
    Card::parse_subtypes(const card_t & card) {
        const auto & db_subtypes = db->get_subtypes();
        subtypes_t card_subtypes;
        try {
            if (card.find("subtypes") != card.end()) {
                for (const std::string & subtype : card["subtypes"]) {
                    card_subtypes.push_back(&(db_subtypes.at(subtype)));
                }
            }
        }
        catch (const std::out_of_range &) {
            std::string msg = "One of subtypes of " + name +
                    " does not refer to any subtype in the database, check rules.";
            throw std::out_of_range(msg);
        }
        return std::move(card_subtypes);
    }

    /*
     * Only getters follows.
     */

    const layout_t &
    Card::get_layout() const {
        return layout;
    }

    const name_t &
    Card::get_name() const {
        return name;
    }

    const names_t &
    Card::get_names() const {
        return names;
    }

    const manaCost_t &
    Card::get_manaCost() const {
        return manaCost;
    }

    const colors_t &
    Card::get_colors() const {
        return colors;
    }

    const supertypes_t &
    Card::get_supertypes() const {
        return supertypes;
    }

    const types_t &
    Card::get_types() const {
        return types;
    }

    const subtypes_t &
    Card::get_subtypes() const {
        return subtypes;
    }

    const text_t &
    Card::get_text() const {
        return text;
    }

    //    const power_t &
    //    Card::get_power() const {
    //        return power;
    //    }
    //
    //    const toughness_t &
    //    Card::get_toughness() const {
    //        return toughness;
    //    }

    const loyalty_t &
    Card::get_loyalty() const {
        return loyalty;
    }

    const hand_t &
    Card::get_hand() const {
        return hand;
    }

    const life_t &
    Card::get_life() const {
        return life;
    }
}

