/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   IDatabaseFetch.hpp
 * Author: Thomas Kremel
 *
 * Created on 21 March 2017, 19:32
 */

#ifndef IDATABASEFETCH_HPP
#define IDATABASEFETCH_HPP

#include <iostream>
#include <fstream>
#include <string>
#include "Card.hpp"
//#include "json.hpp"

namespace MagicSearchEngine {
    
    class IDatabaseFetch {
    public:
        virtual Card get_card(id_t id) = 0;
    };
    
    class JSONDatabase {
    private:
        //ifstream ifs;
    public:
        JSONDatabase(std::string s){
            
        }
    };
    
}






#endif /* IDATABASEFETCH_HPP */

