/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Card.hpp
 * Author: thomas
 *
 * Created on 24 March 2017, 14:35
 */

#ifndef CARD_HPP
#define CARD_HPP

#include <string>

namespace MagicSearchEngine {
    using id_t = std::string;
    using layout_t = std::string;
    using rarity_t = std::string;

    class Card {
    private:
        id_t id;
        layout_t layout;
        rarity_t rarity;
    public:

        Card(id_t id_, layout_t layout_, rarity_t rarity_) :
        id(id_), layout(layout_), rarity(rarity_) {
        }

        id_t get_id() {
            return id;
        }
        
        layout_t get_layout() {
            return layout;
        }
        
        rarity_t get_rarity(){
            return rarity;
        }
    };
}
#endif /* CARD_HPP */

