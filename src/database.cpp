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

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <exception>
#include "src/database.hpp"
#include "src/card.hpp"
#include "src/json.hpp"

namespace magicSearchEngine {
    using json = nlohmann::json;    
    
    /*
     * Only definitions of member functions of the JSON
     * database implementation follows.
     */

    /*
     * This instantiates maps which serve as a databases of types,
     * where all card members have pointers to strings in these maps.
     * Motivation: space efficiency, fast lookup, simple outputting
     * of type's string representation.
     * 
     * All know -types, colors etc. you can find in comprehensive rules at:
     * http://magic.wizards.com/en/game-info/gameplay/rules-and-formats/rules
     */
    void
    JSONDatabase::load_database() {
        std::ifstream ifs{"./src/AllCards.json"};
        json data = json::parse(ifs);
        // <editor-fold defaultstate="collapsed" desc="types instantiation">
        types["general"] = "general";
        types["artifacts"] = "artifacts";
        types["creatures"] = "creatures";
        types["enchantments"] = "enchantments";
        types["instants"] = "instants";
        types["lands"] = "lands";
        types["planeswalkers"] = "planeswalkers";
        types["sorceries"] = "sorceries";
        types["tribals"] = "tribals";
        types["planes"] = "planes";
        types["phenomena"] = "phenomena";
        types["vanguards"] = "vanguards";
        types["schemes"] = "schemes";
        types["conspiracies"] = "conspiracies";
        // </editor-fold>
        // <editor-fold defaultstate="collapsed" desc="subtypes instantiation">
        // artifact
        subtypes["clue"] = "clue";
        subtypes["contraption"] = "contraption";
        subtypes["equipment"] = "equipment";
        subtypes["fortification"] = "fortification";
        subtypes["vehicle"] = "vehicle";
        // enchantements
        subtypes["aura"] = "aura";
        subtypes["curse"] = "curse";
        subtypes["shrin"] = "shrin";
        // land
        subtypes["desert"] = "desert";
        subtypes["forest"] = "forest";
        subtypes["gate"] = "gate";
        subtypes["island"] = "island";
        subtypes["lair"] = "lair";
        subtypes["locus"] = "locus";
        subtypes["mine"] = "mine";
        subtypes["mountain"] = "mountain";
        subtypes["plains"] = "plains";
        subtypes["power plant"] = "power plant";
        subtypes["swamp"] = "swamp";
        subtypes["tower"] = "tower";
        subtypes["urza's"] = "urza's";
        // planeswolkers
        subtypes["jani"] = "jani";
        subtypes["arlinn"] = "arlinn";
        subtypes["ashiok"] = "ashiok";
        subtypes["bolas"] = "bolas";
        subtypes["chandra"] = "chandra";
        subtypes["dack"] = "dack";
        subtypes["daretti"] = "daretti";
        subtypes["domri"] = "domri";
        subtypes["dovin"] = "dovin";
        subtypes["elspeth"] = "elspeth";
        subtypes["freyalise"] = "freyalise";
        subtypes["garruk"] = "garruk";
        subtypes["gideon"] = "gideon";
        subtypes["jace"] = "jace";
        subtypes["karn"] = "karn";
        subtypes["kaya"] = "kaya";
        subtypes["kiora"] = "kiora";
        subtypes["koth"] = "koth";
        subtypes["liliana"] = "liliana";
        subtypes["nahiri"] = "nahiri";
        subtypes["narset"] = "narset";
        subtypes["nissa"] = "nissa";
        subtypes["nixilis"] = "nixilis";
        subtypes["ral"] = "ral";
        subtypes["saheeli"] = "saheeli";
        subtypes["sarkhan"] = "sarkhan";
        subtypes["sorin"] = "sorin";
        subtypes["tamiyo"] = "tamiyo";
        subtypes["teferi"] = "teferi";
        subtypes["tezzeret"] = "tezzeret";
        subtypes["tibalt"] = "tibalt";
        subtypes["ugin"] = "ugin";
        subtypes["venser"] = "venser";
        subtypes["vraska"] = "vraska";
        subtypes["xenagos"] = "xenagos";
        // instants
        subtypes["arcane"] = "arcane";
        subtypes["trap"] = "trap";
        // creatures
        subtypes["advisor"] = "advisor";
        subtypes["aetherborn"] = "aetherborn";
        subtypes["ally"] = "ally";
        subtypes["angel"] = "angel";
        subtypes["antelope"] = "antelope";
        subtypes["ape"] = "ape";
        subtypes["archer"] = "archer";
        subtypes["archon"] = "archon";
        subtypes["artificer"] = "artificer";
        subtypes["assassin"] = "assassin";
        subtypes["assembly worker"] = "assembly worker";
        subtypes["atog"] = "atog";
        subtypes["aurochs"] = "aurochs";
        subtypes["avatar"] = "avatar";
        subtypes["badger"] = "badger";
        subtypes["barbarian"] = "barbarian";
        subtypes["basilisk"] = "basilisk";
        subtypes["bat"] = "bat";
        subtypes["bear"] = "bear";
        subtypes["beast"] = "beast";
        subtypes["beeble"] = "beeble";
        subtypes["berserker"] = "berserker";
        subtypes["bird"] = "bird";
        subtypes["blinkmoth"] = "blinkmoth";
        subtypes["boar"] = "boar";
        subtypes["bringer"] = "bringer";
        subtypes["brushwagg"] = "brushwagg";
        subtypes["camarid"] = "camarid";
        subtypes["camel"] = "camel";
        subtypes["caribou"] = "caribou";
        subtypes["carrier"] = "carrier";
        subtypes["cat"] = "cat";
        subtypes["centaur"] = "centaur";
        subtypes["cephalid"] = "cephalid";
        subtypes["chimera"] = "chimera";
        subtypes["citizen"] = "citizen";
        subtypes["cleric"] = "cleric";
        subtypes["cockatrice"] = "cockatrice";
        subtypes["construct"] = "construct";
        subtypes["coward"] = "coward";
        subtypes["crab"] = "crab";
        subtypes["crocodile"] = "crocodile";
        subtypes["cyclops"] = "cyclops";
        subtypes["dauthi"] = "dauthi";
        subtypes["demon"] = "demon";
        subtypes["deserter"] = "deserter";
        subtypes["devil"] = "devil";
        subtypes["djinn"] = "djinn";
        subtypes["dragon"] = "dragon";
        subtypes["drake"] = "drake";
        subtypes["dreadnought"] = "dreadnought";
        subtypes["drone"] = "drone";
        subtypes["druid"] = "druid";
        subtypes["dryad"] = "dryad";
        subtypes["dwarf"] = "dwarf";
        subtypes["efreet"] = "efreet";
        subtypes["elder"] = "elder";
        subtypes["eldrazi"] = "eldrazi";
        subtypes["elemental"] = "elemental";
        subtypes["elephant"] = "elephant";
        subtypes["elf"] = "elf";
        subtypes["elk"] = "elk";
        subtypes["eye"] = "eye";
        subtypes["faerie"] = "faerie";
        subtypes["ferret"] = "ferret";
        subtypes["fish"] = "fish";
        subtypes["flagbearer"] = "flagbearer";
        subtypes["fox"] = "fox";
        subtypes["frog"] = "frog";
        subtypes["fungus"] = "fungus";
        subtypes["gargoyle"] = "gargoyle";
        subtypes["germ"] = "germ";
        subtypes["giant"] = "giant";
        subtypes["gnome"] = "gnome";
        subtypes["goat"] = "goat";
        subtypes["goblin"] = "goblin";
        subtypes["god"] = "god";
        subtypes["golem"] = "golem";
        subtypes["gorgon"] = "gorgon";
        subtypes["graveborn"] = "graveborn";
        subtypes["gremlin"] = "gremlin";
        subtypes["griffin"] = "griffin";
        subtypes["hag"] = "hag";
        subtypes["harpy"] = "harpy";
        subtypes["hellion"] = "hellion";
        subtypes["hippo"] = "hippo";
        subtypes["hippogriff"] = "hippogriff";
        subtypes["homarid"] = "homarid";
        subtypes["homunculus"] = "homunculus";
        subtypes["horror"] = "horror";
        subtypes["horse"] = "horse";
        subtypes["hound"] = "hound";
        subtypes["human"] = "human";
        subtypes["hydra"] = "hydra";
        subtypes["hyena"] = "hyena";
        subtypes["illusion"] = "illusion";
        subtypes["imp"] = "imp";
        subtypes["incarnation"] = "incarnation";
        subtypes["insect"] = "insect";
        subtypes["jellyfish"] = "jellyfish";
        subtypes["juggernaut"] = "juggernaut";
        subtypes["kavu"] = "kavu";
        subtypes["kirin"] = "kirin";
        subtypes["kithkin"] = "kithkin";
        subtypes["knight"] = "knight";
        subtypes["kobold"] = "kobold";
        subtypes["kor"] = "kor";
        subtypes["kraken"] = "kraken";
        subtypes["lamia"] = "lamia";
        subtypes["lammasu"] = "lammasu";
        subtypes["leech"] = "leech";
        subtypes["leviathan"] = "leviathan";
        subtypes["lhurgoyf"] = "lhurgoyf";
        subtypes["licid"] = "licid";
        subtypes["lizard"] = "lizard";
        subtypes["manticore"] = "manticore";
        subtypes["masticore"] = "masticore";
        subtypes["mercenary"] = "mercenary";
        subtypes["merfolk"] = "merfolk";
        subtypes["metathran"] = "metathran";
        subtypes["minion"] = "minion";
        subtypes["minotaur"] = "minotaur";
        subtypes["mole"] = "mole";
        subtypes["monger"] = "monger";
        subtypes["mongoose"] = "mongoose";
        subtypes["monk"] = "monk";
        subtypes["monkey"] = "monkey";
        subtypes["moonfolk"] = "moonfolk";
        subtypes["mutant"] = "mutant";
        subtypes["myr"] = "myr";
        subtypes["mystic"] = "mystic";
        subtypes["naga"] = "naga";
        subtypes["nautilus"] = "nautilus";
        subtypes["nephilim"] = "nephilim";
        subtypes["nightmare"] = "nightmare";
        subtypes["nightstalker"] = "nightstalker";
        subtypes["ninja"] = "ninja";
        subtypes["noggle"] = "noggle";
        subtypes["nomad"] = "nomad";
        subtypes["nymph"] = "nymph";
        subtypes["octopus"] = "octopus";
        subtypes["ogre"] = "ogre";
        subtypes["ooze"] = "ooze";
        subtypes["orb"] = "orb";
        subtypes["orc"] = "orc";
        subtypes["orgg"] = "orgg";
        subtypes["ouphe"] = "ouphe";
        subtypes["ox"] = "ox";
        subtypes["oyster"] = "oyster";
        subtypes["pegasus"] = "pegasus";
        subtypes["pentavite"] = "pentavite";
        subtypes["pest"] = "pest";
        subtypes["phelddagrif"] = "phelddagrif";
        subtypes["phoenix"] = "phoenix";
        subtypes["pilot"] = "pilot";
        subtypes["pincher"] = "pincher";
        subtypes["pirate"] = "pirate";
        subtypes["plant"] = "plant";
        subtypes["praetor"] = "praetor";
        subtypes["prism"] = "prism";
        subtypes["processor"] = "processor";
        subtypes["rabbit"] = "rabbit";
        subtypes["rat"] = "rat";
        subtypes["rebel"] = "rebel";
        subtypes["reflection"] = "reflection";
        subtypes["rhino"] = "rhino";
        subtypes["rigger"] = "rigger";
        subtypes["rogue"] = "rogue";
        subtypes["sable"] = "sable";
        subtypes["salamander"] = "salamander";
        subtypes["samurai"] = "samurai";
        subtypes["sand"] = "sand";
        subtypes["saproling"] = "saproling";
        subtypes["satyr"] = "satyr";
        subtypes["scarecrow"] = "scarecrow";
        subtypes["scion"] = "scion";
        subtypes["scorpion"] = "scorpion";
        subtypes["scout"] = "scout";
        subtypes["serf"] = "serf";
        subtypes["serpent"] = "serpent";
        subtypes["servo"] = "servo";
        subtypes["shade"] = "shade";
        subtypes["shaman"] = "shaman";
        subtypes["shapeshifter"] = "shapeshifter";
        subtypes["sheep"] = "sheep";
        subtypes["siren"] = "siren";
        subtypes["skeleton"] = "skeleton";
        subtypes["slith"] = "slith";
        subtypes["sliver"] = "sliver";
        subtypes["slug"] = "slug";
        subtypes["snake"] = "snake";
        subtypes["soldier"] = "soldier";
        subtypes["soltari"] = "soltari";
        subtypes["spawn"] = "spawn";
        subtypes["specter"] = "specter";
        subtypes["spellshaper"] = "spellshaper";
        subtypes["sphinx"] = "sphinx";
        subtypes["spider"] = "spider";
        subtypes["spike"] = "spike";
        subtypes["spirit"] = "spirit";
        subtypes["splinter"] = "splinter";
        subtypes["sponge"] = "sponge";
        subtypes["squid"] = "squid";
        subtypes["squirrel"] = "squirrel";
        subtypes["starfish"] = "starfish";
        subtypes["surrakar"] = "surrakar";
        subtypes["survivor"] = "survivor";
        subtypes["tetravite"] = "tetravite";
        subtypes["thalakos"] = "thalakos";
        subtypes["thopter"] = "thopter";
        subtypes["thrull"] = "thrull";
        subtypes["treefolk"] = "treefolk";
        subtypes["triskelavite"] = "triskelavite";
        subtypes["troll"] = "troll";
        subtypes["turtle"] = "turtle";
        subtypes["unicorn"] = "unicorn";
        subtypes["vampire"] = "vampire";
        subtypes["vedalken"] = "vedalken";
        subtypes["viashino"] = "viashino";
        subtypes["volver"] = "volver";
        subtypes["wall"] = "wall";
        subtypes["warrior"] = "warrior";
        subtypes["weird"] = "weird";
        subtypes["werewolf"] = "werewolf";
        subtypes["whale"] = "whale";
        subtypes["wizard"] = "wizard";
        subtypes["wolf"] = "wolf";
        subtypes["wolverine"] = "wolverine";
        subtypes["wombat"] = "wombat";
        subtypes["worm"] = "worm";
        subtypes["wraith"] = "wraith";
        subtypes["wurm"] = "wurm";
        subtypes["yeti"] = "yeti";
        subtypes["zombie"] = "zombie";
        subtypes["zubera"] = "zubera";
        // planes
        subtypes["alara"] = "alara";
        subtypes["arkhos"] = "arkhos";
        subtypes["azgol"] = "azgol";
        subtypes["belenon"] = "belenon";
        subtypes["bolas's meditation realm"] = "bolas's meditation realm";
        subtypes["dominaria"] = "dominaria";
        subtypes["equilor"] = "equilor";
        subtypes["ergamon"] = "ergamon";
        subtypes["fabacin"] = "fabacin";
        subtypes["innistrad"] = "innistrad";
        subtypes["iquatana"] = "iquatana";
        subtypes["ir"] = "ir";
        subtypes["kaldheim"] = "kaldheim";
        subtypes["kamigawa"] = "kamigawa";
        subtypes["karsus"] = "karsus";
        subtypes["kephalai"] = "kephalai";
        subtypes["kinshala"] = "kinshala";
        subtypes["kolbahan"] = "kolbahan";
        subtypes["kyneth"] = "kyneth";
        subtypes["lorwyn"] = "lorwyn";
        subtypes["luvion"] = "luvion";
        subtypes["mercadia"] = "mercadia";
        subtypes["mirrodin"] = "mirrodin";
        subtypes["moag"] = "moag";
        subtypes["mongseng"] = "mongseng";
        subtypes["muraganda"] = "muraganda";
        subtypes["new phyrexia"] = "new phyrexia";
        subtypes["phyrexia"] = "phyrexia";
        subtypes["pyrulea"] = "pyrulea";
        subtypes["rabiah"] = "rabiah";
        subtypes["rath"] = "rath";
        subtypes["ravnica"] = "ravnica";
        subtypes["regatha"] = "regatha";
        subtypes["segovia"] = "segovia";
        subtypes["serra's realm"] = "serra's realm";
        subtypes["shadowmoor"] = "shadowmoor";
        subtypes["shandalar"] = "shandalar";
        subtypes["ulgrotha"] = "ulgrotha";
        subtypes["valla"] = "valla";
        subtypes["vryn"] = "vryn";
        subtypes["wildfire"] = "wildfire";
        subtypes["xerex"] = "xerex";
        subtypes["zendikar"] = "zendikar";

        // </editor-fold>
        // <editor-fold defaultstate="collapsed" desc="supertypes instantiation">
        supertypes["basic"] = "basic";
        supertypes["legendary"] = "legendary";
        supertypes["ongoing"] = "ongoing";
        supertypes["snow"] = "snow";
        supertypes["world"] = "world";
        // </editor-fold>
        // <editor-fold defaultstate="collapsed" desc="layout instantiation">
        layout["normal"] = "normal";
        layout["split"] = "split";
        layout["flip"] = "flip";
        layout["double faced"] = "double faced";
        layout["token"] = "token";
        layout["plane"] = "plane";
        layout["scheme"] = "scheme";
        layout["phenomenon"] = "phenomenon";
        layout["leveler"] = "leveler";
        layout["vanguard"] = "vanguard";
        layout["meld"] = "meld";
        // </editor-fold>
        // <editor-fold defaultstate="collapsed" desc="colors instantiation">
        colors["blue"] = "blue";
        colors["white"] = "white";
        colors["green"] = "green";
        colors["red"] = "red";
        colors["black"] = "black";
        // </editor-fold>
        // <editor-fold defaultstate="collapsed" desc="mana instantiation">
        mana["blue"] = "blue";
        mana["white"] = "white";
        mana["green"] = "green";
        mana["red"] = "red";
        mana["black"] = "black";
        mana["colorless"] = "colorless";
        mana["x"] = "x";
        // </editor-fold>
        cards = load_cards(data);
        ifs.close();
        
        was_db_loaded = true;
    }

    std::vector<Card>
    JSONDatabase::load_cards(const json & data) {
        std::vector<Card> cards;

        for (auto && card : data) {
            Card entry{card, this};
            cards.push_back(entry);
        }

        return std::move(cards);
    }

    std::map<std::string, std::string>
    JSONDatabase::get_types() const {
        if (was_db_loaded)
            return types;
        else
            throw bad_optional_access(db_not_loaded);
    }

    std::map<std::string, std::string>
    JSONDatabase::get_subtypes() const {
        if (was_db_loaded)
            return subtypes;
        else
            throw bad_optional_access(db_not_loaded);
    }

    std::map<std::string, std::string>
    JSONDatabase::get_supertypes() const {
        if (was_db_loaded)
            return supertypes;
        else
            throw bad_optional_access(db_not_loaded);
    }

    std::vector<Card>
    JSONDatabase::get_cards() const {
        if (was_db_loaded)
            return cards;
        else
            throw bad_optional_access(db_not_loaded);
    }

    std::map<std::string, std::string>
    JSONDatabase::get_layout() const {
        if (was_db_loaded)
            return layout;
        else
            throw bad_optional_access(db_not_loaded);
    }

    std::map<std::string, std::string>
    JSONDatabase::get_colors() const {
        if (was_db_loaded)
            return colors;
        else
            throw bad_optional_access(db_not_loaded);
    }

    std::map<std::string, std::string>
    JSONDatabase::get_mana() const {
        if (was_db_loaded)
            return mana;
        else
            throw bad_optional_access(db_not_loaded);
    }
}