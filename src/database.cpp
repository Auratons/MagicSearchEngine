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
#include <unordered_map>
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
        types["General"] = "General";
        types["Artifact"] = "Artifact";
        types["Creature"] = "Creature";
        types["Eaturecray"] = "Eaturecray"; // not in rules, special card
        types["Enchantment"] = "Enchantment";
        types["Enchant"] = "Enchant";
        types["Instant"] = "Instant";
        types["Land"] = "Land";
        types["Planeswalker"] = "Planeswalker";
        types["Sorcery"] = "Sorcery";
        types["Tribal"] = "Tribal";
        types["Plane"] = "Plane";
        types["Player"] = "Player";
        types["Phenomenon"] = "Phenomenon";
        types["Vanguard"] = "Vanguard";
        types["Scheme"] = "Scheme";
        types["Conspiracy"] = "Conspiracy";
        types["Scariest"] = "Scariest";
        types["You'll"] = "You'll";
        types["See"] = "See";
        types["Ever"] = "Ever";
        // </editor-fold>
        // <editor-fold defaultstate="collapsed" desc="subtypes instantiation">
        // eaturecray
        subtypes["Igpay"] = "Igpay"; // not in rules, special card
        // artifact
        subtypes["Clue"] = "Clue";
        subtypes["Contraption"] = "Contraption";
        subtypes["Equipment"] = "Equipment";
        subtypes["Fortification"] = "Fortification";
        subtypes["Vehicle"] = "Vehicle";
        // enchantements
        subtypes["Aura"] = "Aura";
        subtypes["Curse"] = "Curse";
        subtypes["Shrine"] = "Shrine";
        // land
        subtypes["Desert"] = "Desert";
        subtypes["Forest"] = "Forest";
        subtypes["Gate"] = "Gate";
        subtypes["Island"] = "Island";
        subtypes["Lair"] = "Lair";
        subtypes["Locus"] = "Locus";
        subtypes["Mine"] = "Mine";
        subtypes["Mountain"] = "Mountain";
        subtypes["Plains"] = "Plains";
        subtypes["Power-Plant"] = "Power-Plant";
        subtypes["Swamp"] = "Swamp";
        subtypes["Tower"] = "Tower";
        subtypes["Urza’s"] = "Urza’s";
        // planeswolkers
        subtypes["Ajani"] = "Ajani";
        subtypes["Arlinn"] = "Arlinn";
        subtypes["Ashiok"] = "Ashiok";
        subtypes["Bolas"] = "Bolas";
        subtypes["Chandra"] = "Chandra";
        subtypes["Dack"] = "Dack";
        subtypes["Daretti"] = "Daretti";
        subtypes["Domri"] = "Domri";
        subtypes["Dovin"] = "Dovin";
        subtypes["Elspeth"] = "Elspeth";
        subtypes["Freyalise"] = "Freyalise";
        subtypes["Garruk"] = "Garruk";
        subtypes["Gideon"] = "Gideon";
        subtypes["Jace"] = "Jace";
        subtypes["Karn"] = "Karn";
        subtypes["Kaya"] = "Kaya";
        subtypes["Kiora"] = "Kiora";
        subtypes["Koth"] = "Koth";
        subtypes["Liliana"] = "Liliana";
        subtypes["Nahiri"] = "Nahiri";
        subtypes["Narset"] = "Narset";
        subtypes["Nissa"] = "Nissa";
        subtypes["Nixilis"] = "Nixilis";
        subtypes["Ral"] = "Ral";
        subtypes["Saheeli"] = "Saheeli";
        subtypes["Sarkhan"] = "Sarkhan";
        subtypes["Sorin"] = "Sorin";
        subtypes["Tamiyo"] = "Tamiyo";
        subtypes["Teferi"] = "Teferi";
        subtypes["Tezzeret"] = "Tezzeret";
        subtypes["Tibalt"] = "Tibalt";
        subtypes["Ugin"] = "Ugin";
        subtypes["Venser"] = "Venser";
        subtypes["Vraska"] = "Vraska";
        subtypes["Xenagos"] = "Xenagos";
        // instants
        subtypes["Arcane"] = "Arcane";
        subtypes["Trap"] = "Trap";
        // creatures
        subtypes["Advisor"] = "Advisor";
        subtypes["Aetherborn"] = "Aetherborn";
        subtypes["Ally"] = "Ally";
        subtypes["Angel"] = "Angel";
        subtypes["Antelope"] = "Antelope";
        subtypes["Ape"] = "Ape";
        subtypes["Archer"] = "Archer";
        subtypes["Archon"] = "Archon";
        subtypes["Artificer"] = "Artificer";
        subtypes["Assassin"] = "Assassin";
        subtypes["Assembly-Worker"] = "Assembly worker";
        subtypes["Atog"] = "Atog";
        subtypes["Aurochs"] = "Aurochs";
        subtypes["Avatar"] = "Avatar";
        subtypes["Badger"] = "Badger";
        subtypes["Barbarian"] = "Barbarian";
        subtypes["Basilisk"] = "Basilisk";
        subtypes["Bat"] = "Bat";
        subtypes["Bear"] = "Bear";
        subtypes["Beast"] = "Beast";
        subtypes["Beeble"] = "Beeble";
        subtypes["Berserker"] = "Berserker";
        subtypes["Bird"] = "Bird";
        subtypes["Blinkmoth"] = "Blinkmoth";
        subtypes["Boar"] = "Boar";
        subtypes["Bringer"] = "Bringer";
        subtypes["Brushwagg"] = "Brushwagg";
        subtypes["Bureaucrat"] = "Bureaucrat";
        subtypes["Camarid"] = "Camarid";
        subtypes["Camel"] = "Camel";
        subtypes["Caribou"] = "Caribou";
        subtypes["Carrier"] = "Carrier";
        subtypes["Cat"] = "Cat";
        subtypes["Centaur"] = "Centaur";
        subtypes["Cephalid"] = "Cephalid";
        subtypes["Chicken"] = "Chicken";
        subtypes["Child"] = "Child";
        subtypes["Chimera"] = "Chimera";
        subtypes["Citizen"] = "Citizen";
        subtypes["Clamfolk"] = "Clamfolk";
        subtypes["Cleric"] = "Cleric";
        subtypes["Cockatrice"] = "Cockatrice";
        subtypes["Construct"] = "Construct";
        subtypes["Coward"] = "Coward";
        subtypes["Cow"] = "Cow";
        subtypes["Crab"] = "Crab";
        subtypes["Crocodile"] = "Crocodile";
        subtypes["Cyclops"] = "Cyclops";
        subtypes["Dauthi"] = "Dauthi";
        subtypes["Dinosaur"] = "Dinosaur";
        subtypes["Demon"] = "Demon";
        subtypes["Deserter"] = "Deserter";
        subtypes["Designer"] = "Designer";
        subtypes["Devil"] = "Devil";
        subtypes["Djinn"] = "Djinn";
        subtypes["Donkey"] = "Donkey";
        subtypes["Dragon"] = "Dragon";
        subtypes["Drake"] = "Drake";
        subtypes["Dreadnought"] = "Dreadnought";
        subtypes["Drone"] = "Drone";
        subtypes["Druid"] = "Druid";
        subtypes["Dryad"] = "Dryad";
        subtypes["Dwarf"] = "Dwarf";
        subtypes["Egg"] = "Egg";
        subtypes["Efreet"] = "Efreet";
        subtypes["Elder"] = "Elder";
        subtypes["Eldrazi"] = "Eldrazi";
        subtypes["Elemental"] = "Elemental";
        subtypes["Elephant"] = "Elephant";
        subtypes["Elf"] = "Elf";
        subtypes["Elk"] = "Elk";
        subtypes["Elves"] = "Elves";
        subtypes["Eye"] = "Eye";
        subtypes["Faerie"] = "Faerie";
        subtypes["Ferret"] = "Ferret";
        subtypes["Fish"] = "Fish";
        subtypes["Flagbearer"] = "Flagbearer";
        subtypes["Fox"] = "Fox";
        subtypes["Frog"] = "Frog";
        subtypes["Fungus"] = "Fungus";
        subtypes["Gamer"] = "Gamer";
        subtypes["Gargoyle"] = "Gargoyle";
        subtypes["Germ"] = "Germ";
        subtypes["Giant"] = "Giant";
        subtypes["Gnome"] = "Gnome";
        subtypes["Goat"] = "Goat";
        subtypes["Goblin"] = "Goblin";
        subtypes["Goblins"] = "Goblins";
        subtypes["God"] = "God";
        subtypes["Golem"] = "Golem";
        subtypes["Gorgon"] = "Gorgon";
        subtypes["Graveborn"] = "Graveborn";
        subtypes["Gremlin"] = "Gremlin";
        subtypes["Griffin"] = "Griffin";
        subtypes["Gus"] = "Gus";
        subtypes["Hag"] = "Hag";
        subtypes["Harpy"] = "Harpy";
        subtypes["Hellion"] = "Hellion";
        subtypes["Hero"] = "Hero";
        subtypes["Hippo"] = "Hippo";
        subtypes["Hippogriff"] = "Hippogriff";
        subtypes["Homarid"] = "Homarid";
        subtypes["Homunculus"] = "Homunculus";
        subtypes["Horror"] = "Horror";
        subtypes["Horse"] = "Horse";
        subtypes["Hound"] = "Hound";
        subtypes["Human"] = "Human";
        subtypes["Hydra"] = "Hydra";
        subtypes["Hyena"] = "Hyena";
        subtypes["Illusion"] = "Illusion";
        subtypes["Imp"] = "Imp";
        subtypes["Incarnation"] = "Incarnation";
        subtypes["Insect"] = "Insect";
        subtypes["Jellyfish"] = "Jellyfish";
        subtypes["Juggernaut"] = "Juggernaut";
        subtypes["Kavu"] = "Kavu";
        subtypes["Kirin"] = "Kirin";
        subtypes["Kithkin"] = "Kithkin";
        subtypes["Knight"] = "Knight";
        subtypes["Kobold"] = "Kobold";
        subtypes["Kor"] = "Kor";
        subtypes["Kraken"] = "Kraken";
        subtypes["Lamia"] = "Lamia";
        subtypes["Lammasu"] = "Lammasu";
        subtypes["Leech"] = "Leech";
        subtypes["Leviathan"] = "Leviathan";
        subtypes["Lhurgoyf"] = "Lhurgoyf";
        subtypes["Licid"] = "Licid";
        subtypes["Lizard"] = "Lizard";
        subtypes["Lord"] = "Lord";
        subtypes["Manticore"] = "Manticore";
        subtypes["Masticore"] = "Masticore";
        subtypes["Mercenary"] = "Mercenary";
        subtypes["Merfolk"] = "Merfolk";
        subtypes["Metathran"] = "Metathran";
        subtypes["Minion"] = "Minion";
        subtypes["Minotaur"] = "Minotaur";
        subtypes["Mime"] = "Mime";
        subtypes["Mole"] = "Mole";
        subtypes["Monger"] = "Monger";
        subtypes["Mongoose"] = "Mongoose";
        subtypes["Monk"] = "Monk";
        subtypes["Monkey"] = "Monkey";
        subtypes["Moonfolk"] = "Moonfolk";
        subtypes["Mummy"] = "Mummy";
        subtypes["Mutant"] = "Mutant";
        subtypes["Myr"] = "Myr";
        subtypes["Mystic"] = "Mystic";
        subtypes["Naga"] = "Naga";
        subtypes["Nautilus"] = "Nautilus";
        subtypes["Nephilim"] = "Nephilim";
        subtypes["Nightmare"] = "Nightmare";
        subtypes["Nightstalker"] = "Nightstalker";
        subtypes["Ninja"] = "Ninja";
        subtypes["Noggle"] = "Noggle";
        subtypes["Nomad"] = "Nomad";
        subtypes["Nymph"] = "Nymph";
        subtypes["Octopus"] = "Octopus";
        subtypes["Ogre"] = "Ogre";
        subtypes["Ooze"] = "Ooze";
        subtypes["Orb"] = "Orb";
        subtypes["Orc"] = "Orc";
        subtypes["Orgg"] = "Orgg";
        subtypes["Ouphe"] = "Ouphe";
        subtypes["Ox"] = "Ox";
        subtypes["Oyster"] = "Oyster";
        subtypes["Paratrooper"] = "Paratrooper";
        subtypes["Pegasus"] = "Pegasus";
        subtypes["Pentavite"] = "Pentavite";
        subtypes["Pest"] = "Pest";
        subtypes["Phelddagrif"] = "Phelddagrif";
        subtypes["Phoenix"] = "Phoenix";
        subtypes["Pilot"] = "Pilot";
        subtypes["Pincher"] = "Pincher";
        subtypes["Pirate"] = "Pirate";
        subtypes["Plant"] = "Plant";
        subtypes["Praetor"] = "Praetor";
        subtypes["Prism"] = "Prism";
        subtypes["Processor"] = "Processor";
        subtypes["Rabbit"] = "Rabbit";
        subtypes["Rat"] = "Rat";
        subtypes["Rebel"] = "Rebel";
        subtypes["Reflection"] = "Reflection";
        subtypes["Rhino"] = "Rhino";
        subtypes["Rigger"] = "Rigger";
        subtypes["Rogue"] = "Rogue";
        subtypes["Sable"] = "Sable";
        subtypes["Salamander"] = "Salamander";
        subtypes["Samurai"] = "Samurai";
        subtypes["Sand"] = "Sand";
        subtypes["Saproling"] = "Saproling";
        subtypes["Satyr"] = "Satyr";
        subtypes["Scarecrow"] = "Scarecrow";
        subtypes["Scion"] = "Scion";
        subtypes["Scorpion"] = "Scorpion";
        subtypes["Scout"] = "Scout";
        subtypes["Serf"] = "Serf";
        subtypes["Serpent"] = "Serpent";
        subtypes["Servo"] = "Servo";
        subtypes["Shade"] = "Shade";
        subtypes["Shaman"] = "Shaman";
        subtypes["Shapeshifter"] = "Shapeshifter";
        subtypes["Sheep"] = "Sheep";
        subtypes["Ship"] = "Ship";
        subtypes["Siren"] = "Siren";
        subtypes["Skeleton"] = "Skeleton";
        subtypes["Slith"] = "Slith";
        subtypes["Sliver"] = "Sliver";
        subtypes["Slug"] = "Slug";
        subtypes["Snake"] = "Snake";
        subtypes["Soldier"] = "Soldier";
        subtypes["Soltari"] = "Soltari";
        subtypes["Spawn"] = "Spawn";
        subtypes["Specter"] = "Specter";
        subtypes["Spellshaper"] = "Spellshaper";
        subtypes["Sphinx"] = "Sphinx";
        subtypes["Spider"] = "Spider";
        subtypes["Spike"] = "Spike";
        subtypes["Spirit"] = "Spirit";
        subtypes["Splinter"] = "Splinter";
        subtypes["Sponge"] = "Sponge";
        subtypes["Squid"] = "Squid";
        subtypes["Squirrel"] = "Squirrel";
        subtypes["Starfish"] = "Starfish";
        subtypes["Surrakar"] = "Surrakar";
        subtypes["Survivor"] = "Survivor";
        subtypes["Tetravite"] = "Tetravite";
        subtypes["Thalakos"] = "Thalakos";
        subtypes["Thopter"] = "Thopter";
        subtypes["Thrull"] = "Thrull";
        subtypes["Townsfolk"] = "Townsfolk"; // not in rules, special card
        subtypes["Treefolk"] = "Treefolk";
        subtypes["Triskelavite"] = "Triskelavite";
        subtypes["Troll"] = "Troll";
        subtypes["Turtle"] = "Turtle";
        subtypes["Unicorn"] = "Unicorn";
        subtypes["Vampire"] = "Vampire";
        subtypes["Vedalken"] = "Vedalken";
        subtypes["Viashino"] = "Viashino";
        subtypes["Volver"] = "Volver";
        subtypes["Waiter"] = "Waiter";
        subtypes["Wall"] = "Wall";
        subtypes["Warrior"] = "Warrior";
        subtypes["Weird"] = "Weird";
        subtypes["Werewolf"] = "Werewolf";
        subtypes["Whale"] = "Whale";
        subtypes["Wizard"] = "Wizard";
        subtypes["Wolf"] = "Wolf";
        subtypes["Wolverine"] = "Wolverine";
        subtypes["Wombat"] = "Wombat";
        subtypes["Worm"] = "Worm";
        subtypes["Wraith"] = "Wraith";
        subtypes["Wurm"] = "Wurm";
        subtypes["Yeti"] = "Yeti";
        subtypes["Zombie"] = "Zombie";
        subtypes["Zubera"] = "Zubera";
        subtypes["Lady"] = "Lady";
        subtypes["of"] = "of";
        subtypes["Proper"] = "Proper";
        subtypes["Etiquette"] = "Etiquette";
        // planes
        subtypes["Alara"] = "Alara";
        subtypes["Arkhos"] = "Arkhos";
        subtypes["Azgol"] = "Azgol";
        subtypes["Belenon"] = "Belenon";
        subtypes["Bolas’s Meditation Realm"] = "Bolas’s Meditation Realm";
        subtypes["Dominaria"] = "Dominaria";
        subtypes["Equilor"] = "Equilor";
        subtypes["Ergamon"] = "Ergamon";
        subtypes["Fabacin"] = "Fabacin";
        subtypes["Innistrad"] = "Innistrad";
        subtypes["Iquatana"] = "Iquatana";
        subtypes["Ir"] = "Ir";
        subtypes["Kaldheim"] = "Kaldheim";
        subtypes["Kamigawa"] = "Kamigawa";
        subtypes["Karsus"] = "Karsus";
        subtypes["Kephalai"] = "Kephalai";
        subtypes["Kinshala"] = "Kinshala";
        subtypes["Kolbahan"] = "Kolbahan";
        subtypes["Kyneth"] = "Kyneth";
        subtypes["Lorwyn"] = "Lorwyn";
        subtypes["Luvion"] = "Luvion";
        subtypes["Mercadia"] = "Mercadia";
        subtypes["Mirrodin"] = "Mirrodin";
        subtypes["Moag"] = "Moag";
        subtypes["Mongseng"] = "Mongseng";
        subtypes["Muraganda"] = "Muraganda";
        subtypes["New Phyrexia"] = "New Phyrexia";
        subtypes["Phyrexia"] = "Phyrexia";
        subtypes["Pyrulea"] = "Pyrulea";
        subtypes["Rabiah"] = "Rabiah";
        subtypes["Rath"] = "Rath";
        subtypes["Ravnica"] = "Ravnica";
        subtypes["Regatha"] = "Regatha";
        subtypes["Segovia"] = "Segovia";
        subtypes["Serra’s Realm"] = "Serra’s Realm";
        subtypes["Shadowmoor"] = "Shadowmoor";
        subtypes["Shandalar"] = "Shandalar";
        subtypes["Ulgrotha"] = "Ulgrotha";
        subtypes["Valla"] = "Valla";
        subtypes["Vryn"] = "Vryn";
        subtypes["Wildfire"] = "Wildfire";
        subtypes["Xerex"] = "Xerex";
        subtypes["Zendikar"] = "Zendikar";
        subtypes["Legend"] = "Legend (obsolete)";
        // </editor-fold>
        // <editor-fold defaultstate="collapsed" desc="supertypes instantiation">
        supertypes["Basic"] = "Basic";
        supertypes["Legendary"] = "Legendary";
        supertypes["Ongoing"] = "Ongoing";
        supertypes["Snow"] = "Snow";
        supertypes["World"] = "World";
        // </editor-fold>
        // <editor-fold defaultstate="collapsed" desc="layout instantiation">
        layout[""] = "";
        layout["normal"] = "normal";
        layout["split"] = "split";
        layout["flip"] = "flip";
        layout["double-faced"] = "double-faced";
        layout["token"] = "token";
        layout["plane"] = "plane";
        layout["scheme"] = "scheme";
        layout["phenomenon"] = "phenomenon";
        layout["leveler"] = "leveler";
        layout["vanguard"] = "vanguard";
        layout["meld"] = "meld";
        // </editor-fold>
        // <editor-fold defaultstate="collapsed" desc="colors instantiation">
        colors["Blue"] = "blue";
        colors["White"] = "white";
        colors["Green"] = "green";
        colors["Red"] = "red";
        colors["Black"] = "black";
        // </editor-fold>
        // <editor-fold defaultstate="collapsed" desc="mana instantiation">
        mana["U"] = "blue";
        mana["W"] = "white";
        mana["G"] = "green";
        mana["R"] = "red";
        mana["B"] = "black";
        mana["C"] = "colorless";
        mana["0"] = "0";
        mana["1"] = "generic";
        mana["2"] = "2 generic";
        mana["3"] = "3 generic";
        mana["4"] = "4 generic";
        mana["5"] = "5 generic";
        mana["6"] = "6 generic";
        mana["7"] = "7 generic";
        mana["8"] = "8 generic";
        mana["9"] = "9 generic";
        mana["10"] = "10 generic";
        mana["11"] = "11 generic";
        mana["12"] = "12 generic";
        mana["13"] = "13 generic";
        mana["14"] = "14 generic";
        mana["15"] = "15 generic";
        mana["16"] = "16 generic";
        mana["17"] = "17 generic";
        mana["18"] = "18 generic";
        mana["19"] = "19 generic";
        mana["20"] = "20 generic";
        mana["1000000"] = "1000000 generic";
        mana["X"] = "X generic";
        mana["W/U"] = "white/blue";
        mana["W/B"] = "white/black";
        mana["U/B"] = "blue/black";
        mana["U/R"] = "blue/red";
        mana["B/R"] = "black/red";
        mana["B/G"] = "black/green";
        mana["R/G"] = "red/green";
        mana["R/W"] = "red/white";
        mana["G/W"] = "green/white";
        mana["G/U"] = "green/blue";
        mana["2/W"] = "generic/white";
        mana["2/U"] = "generic/blue";
        mana["2/B"] = "generic/black";
        mana["2/R"] = "generic/red";
        mana["2/G"] = "generic/green";
        mana["W/P"] = "white/-2life";
        mana["U/P"] = "blue/-2life";
        mana["B/P"] = "black/-2life";
        mana["R/P"] = "red/-2life";
        mana["G/P"] = "green/-2life";
        mana["S"] = "snow generic";
        mana["hw"] = "half white";
        mana["Y"] = "Y";
        mana["Z"] = "Z";
        // </editor-fold>
        was_db_loaded = true;
        cards = load_cards(data);
        ifs.close();

    }

    std::vector<Card>
    JSONDatabase::load_cards(const json & data) {
        std::vector<Card> cards_;

        for (auto && card : data) {
            Card entry{card, this};
            cards_.push_back(entry);
        }

        return std::move(cards_);
    }

    const std::unordered_map<std::string, std::string> &
    JSONDatabase::get_types() const {
        if (was_db_loaded)
            return types;
        else
            throw bad_optional_access(db_not_loaded);
    }

    const std::unordered_map<std::string, std::string> &
    JSONDatabase::get_subtypes() const {
        if (was_db_loaded)
            return subtypes;
        else
            throw bad_optional_access(db_not_loaded);
    }

    const std::unordered_map<std::string, std::string> &
    JSONDatabase::get_supertypes() const {
        if (was_db_loaded)
            return supertypes;
        else
            throw bad_optional_access(db_not_loaded);
    }

    const std::vector<Card> &
    JSONDatabase::get_cards() const {
        if (was_db_loaded)
            return cards;
        else
            throw bad_optional_access(db_not_loaded);
    }

    const std::unordered_map<std::string, std::string> &
    JSONDatabase::get_layout() const {
        if (was_db_loaded)
            return layout;
        else
            throw bad_optional_access(db_not_loaded);
    }

    const std::unordered_map<std::string, std::string> &
    JSONDatabase::get_colors() const {
        if (was_db_loaded)
            return colors;
        else
            throw bad_optional_access(db_not_loaded);
    }

    const std::unordered_map<std::string, std::string> &
    JSONDatabase::get_mana() const {
        if (was_db_loaded)
            return mana;
        else
            throw bad_optional_access(db_not_loaded);
    }
}