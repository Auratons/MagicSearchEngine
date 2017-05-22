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

#include "searching.hpp"
#include "database.hpp"

using namespace std;

namespace magicSearchEngine {

    void
    search_engine::create_index(const std::vector<Card> & cards) {
        // <editor-fold defaultstate="collapsed" desc="stop_words instantiation">
        stop_words.push_back("hence");
        stop_words.push_back("her");
        stop_words.push_back("here");
        stop_words.push_back("hereafter");
        stop_words.push_back("hereby");
        stop_words.push_back("herein");
        stop_words.push_back("here's");
        stop_words.push_back("hereupon");
        stop_words.push_back("hers");
        stop_words.push_back("herself");
        stop_words.push_back("he's");
        stop_words.push_back("hi");
        stop_words.push_back("him");
        stop_words.push_back("himself");
        stop_words.push_back("his");
        stop_words.push_back("hither");
        stop_words.push_back("hopefully");
        stop_words.push_back("how");
        stop_words.push_back("howbeit");
        stop_words.push_back("however");
        stop_words.push_back("hundred");
        stop_words.push_back("i");
        stop_words.push_back("i'd");
        stop_words.push_back("ie");
        stop_words.push_back("if");
        stop_words.push_back("ignored");
        stop_words.push_back("i'll");
        stop_words.push_back("i'm");
        stop_words.push_back("immediate");
        stop_words.push_back("in");
        stop_words.push_back("inasmuch");
        stop_words.push_back("inc");
        stop_words.push_back("inc.");
        stop_words.push_back("indeed");
        stop_words.push_back("indicate");
        stop_words.push_back("indicated");
        stop_words.push_back("indicates");
        stop_words.push_back("inner");
        stop_words.push_back("inside");
        stop_words.push_back("insofar");
        stop_words.push_back("instead");
        stop_words.push_back("into");
        stop_words.push_back("inward");
        stop_words.push_back("is");
        stop_words.push_back("isn't");
        stop_words.push_back("it");
        stop_words.push_back("it'd");
        stop_words.push_back("it'll");
        stop_words.push_back("its");
        stop_words.push_back("it's");
        stop_words.push_back("itself");
        stop_words.push_back("i've");
        stop_words.push_back("j");
        stop_words.push_back("just");
        stop_words.push_back("k");
        stop_words.push_back("keep");
        stop_words.push_back("keeps");
        stop_words.push_back("kept");
        stop_words.push_back("know");
        stop_words.push_back("known");
        stop_words.push_back("knows");
        stop_words.push_back("l");
        stop_words.push_back("last");
        stop_words.push_back("lately");
        stop_words.push_back("later");
        stop_words.push_back("latter");
        stop_words.push_back("latterly");
        stop_words.push_back("least");
        stop_words.push_back("less");
        stop_words.push_back("lest");
        stop_words.push_back("let");
        stop_words.push_back("let's");
        stop_words.push_back("like");
        stop_words.push_back("liked");
        stop_words.push_back("likely");
        stop_words.push_back("likewise");
        stop_words.push_back("little");
        stop_words.push_back("look");
        stop_words.push_back("looking");
        stop_words.push_back("looks");
        stop_words.push_back("low");
        stop_words.push_back("lower");
        stop_words.push_back("ltd");
        stop_words.push_back("m");
        stop_words.push_back("made");
        stop_words.push_back("mainly");
        stop_words.push_back("make");
        stop_words.push_back("makes");
        stop_words.push_back("many");
        stop_words.push_back("may");
        stop_words.push_back("maybe");
        stop_words.push_back("mayn't");
        stop_words.push_back("me");
        stop_words.push_back("mean");
        stop_words.push_back("meantime");
        stop_words.push_back("meanwhile");
        stop_words.push_back("merely");
        stop_words.push_back("might");
        stop_words.push_back("mightn't");
        stop_words.push_back("mine");
        stop_words.push_back("minus");
        stop_words.push_back("miss");
        stop_words.push_back("more");
        stop_words.push_back("moreover");
        stop_words.push_back("most");
        stop_words.push_back("mostly");
        stop_words.push_back("mr");
        stop_words.push_back("mrs");
        stop_words.push_back("much");
        stop_words.push_back("must");
        stop_words.push_back("mustn't");
        stop_words.push_back("my");
        stop_words.push_back("myself");
        stop_words.push_back("n");
        stop_words.push_back("name");
        stop_words.push_back("namely");
        stop_words.push_back("nd");
        stop_words.push_back("near");
        stop_words.push_back("nearly");
        stop_words.push_back("necessary");
        stop_words.push_back("need");
        stop_words.push_back("needn't");
        stop_words.push_back("needs");
        stop_words.push_back("neither");
        stop_words.push_back("never");
        stop_words.push_back("neverf");
        stop_words.push_back("neverless");
        stop_words.push_back("nevertheless");
        stop_words.push_back("new");
        stop_words.push_back("next");
        stop_words.push_back("nine");
        stop_words.push_back("ninety");
        stop_words.push_back("no");
        stop_words.push_back("nobody");
        stop_words.push_back("non");
        stop_words.push_back("none");
        stop_words.push_back("nonetheless");
        stop_words.push_back("noone");
        stop_words.push_back("no-one");
        stop_words.push_back("nor");
        stop_words.push_back("normally");
        stop_words.push_back("not");
        stop_words.push_back("nothing");
        stop_words.push_back("notwithstanding");
        stop_words.push_back("novel");
        stop_words.push_back("now");
        stop_words.push_back("nowhere");
        stop_words.push_back("o");
        stop_words.push_back("obviously");
        stop_words.push_back("of");
        stop_words.push_back("off");
        stop_words.push_back("often");
        stop_words.push_back("oh");
        stop_words.push_back("ok");
        stop_words.push_back("okay");
        stop_words.push_back("old");
        stop_words.push_back("on");
        stop_words.push_back("once");
        stop_words.push_back("one");
        stop_words.push_back("ones");
        stop_words.push_back("one's");
        stop_words.push_back("only");
        stop_words.push_back("onto");
        stop_words.push_back("opposite");
        stop_words.push_back("or");
        stop_words.push_back("other");
        stop_words.push_back("others");
        stop_words.push_back("otherwise");
        stop_words.push_back("ought");
        stop_words.push_back("oughtn't");
        stop_words.push_back("our");
        stop_words.push_back("ours");
        stop_words.push_back("ourselves");
        stop_words.push_back("out");
        stop_words.push_back("outside");
        stop_words.push_back("over");
        stop_words.push_back("overall");
        stop_words.push_back("own");
        stop_words.push_back("p");
        stop_words.push_back("particular");
        stop_words.push_back("particularly");
        stop_words.push_back("past");
        stop_words.push_back("per");
        stop_words.push_back("perhaps");
        stop_words.push_back("placed");
        stop_words.push_back("please");
        stop_words.push_back("plus");
        stop_words.push_back("possible");
        stop_words.push_back("presumably");
        stop_words.push_back("probably");
        stop_words.push_back("provided");
        stop_words.push_back("provides");
        stop_words.push_back("q");
        stop_words.push_back("que");
        stop_words.push_back("quite");
        stop_words.push_back("qv");
        stop_words.push_back("r");
        stop_words.push_back("rather");
        stop_words.push_back("rd");
        stop_words.push_back("re");
        stop_words.push_back("really");
        stop_words.push_back("reasonably");
        stop_words.push_back("recent");
        stop_words.push_back("recently");
        stop_words.push_back("regarding");
        stop_words.push_back("regardless");
        stop_words.push_back("regards");
        stop_words.push_back("relatively");
        stop_words.push_back("respectively");
        stop_words.push_back("right");
        stop_words.push_back("round");
        stop_words.push_back("s");
        stop_words.push_back("said");
        stop_words.push_back("same");
        stop_words.push_back("saw");
        stop_words.push_back("say");
        stop_words.push_back("saying");
        stop_words.push_back("says");
        stop_words.push_back("second");
        stop_words.push_back("secondly	");
        stop_words.push_back("see");
        stop_words.push_back("seeing");
        stop_words.push_back("seem");
        stop_words.push_back("seemed");
        stop_words.push_back("seeming");
        stop_words.push_back("seems");
        stop_words.push_back("seen");
        stop_words.push_back("self");
        stop_words.push_back("selves");
        stop_words.push_back("sensible");
        stop_words.push_back("sent");
        stop_words.push_back("serious");
        stop_words.push_back("seriously");
        stop_words.push_back("seven");
        stop_words.push_back("several");
        stop_words.push_back("shall");
        stop_words.push_back("shan't");
        stop_words.push_back("she");
        stop_words.push_back("she'd");
        stop_words.push_back("she'll");
        stop_words.push_back("she's");
        stop_words.push_back("should");
        stop_words.push_back("shouldn't");
        stop_words.push_back("since");
        stop_words.push_back("six");
        stop_words.push_back("so");
        stop_words.push_back("some");
        stop_words.push_back("somebody");
        stop_words.push_back("someday");
        stop_words.push_back("somehow");
        stop_words.push_back("someone");
        stop_words.push_back("something");
        stop_words.push_back("sometime");
        stop_words.push_back("sometimes");
        stop_words.push_back("somewhat");
        stop_words.push_back("somewhere");
        stop_words.push_back("soon");
        stop_words.push_back("sorry");
        stop_words.push_back("specified");
        stop_words.push_back("specify");
        stop_words.push_back("specifying");
        stop_words.push_back("still");
        stop_words.push_back("sub");
        stop_words.push_back("such");
        stop_words.push_back("sup");
        stop_words.push_back("sure");
        stop_words.push_back("t");
        stop_words.push_back("take");
        stop_words.push_back("taken");
        stop_words.push_back("taking");
        stop_words.push_back("tell");
        stop_words.push_back("tends");
        stop_words.push_back("th");
        stop_words.push_back("than");
        stop_words.push_back("thank");
        stop_words.push_back("thanks");
        stop_words.push_back("thanx");
        stop_words.push_back("that");
        stop_words.push_back("that'll");
        stop_words.push_back("thats");
        stop_words.push_back("that's");
        stop_words.push_back("that've");
        stop_words.push_back("the");
        stop_words.push_back("their");
        stop_words.push_back("theirs");
        stop_words.push_back("them");
        stop_words.push_back("themselves");
        stop_words.push_back("then");
        stop_words.push_back("thence");
        stop_words.push_back("there");
        stop_words.push_back("thereafter");
        stop_words.push_back("thereby");
        stop_words.push_back("there'd");
        stop_words.push_back("therefore");
        stop_words.push_back("therein");
        stop_words.push_back("there'll");
        stop_words.push_back("there're");
        stop_words.push_back("theres");
        stop_words.push_back("there's");
        stop_words.push_back("thereupon");
        stop_words.push_back("there've");
        stop_words.push_back("these");
        stop_words.push_back("they");
        stop_words.push_back("they'd");
        stop_words.push_back("they'll");
        stop_words.push_back("they're");
        stop_words.push_back("they've");
        stop_words.push_back("thing");
        stop_words.push_back("things");
        stop_words.push_back("think");
        stop_words.push_back("third");
        stop_words.push_back("thirty");
        stop_words.push_back("this");
        stop_words.push_back("thorough");
        stop_words.push_back("thoroughly");
        stop_words.push_back("those");
        stop_words.push_back("though");
        stop_words.push_back("three");
        stop_words.push_back("through");
        stop_words.push_back("throughout");
        stop_words.push_back("thru");
        stop_words.push_back("thus");
        stop_words.push_back("till");
        stop_words.push_back("to");
        stop_words.push_back("together");
        stop_words.push_back("too");
        stop_words.push_back("took");
        stop_words.push_back("toward");
        stop_words.push_back("towards");
        stop_words.push_back("tried");
        stop_words.push_back("tries");
        stop_words.push_back("truly");
        stop_words.push_back("try");
        stop_words.push_back("trying");
        stop_words.push_back("t's");
        stop_words.push_back("twice");
        stop_words.push_back("two");
        stop_words.push_back("u");
        stop_words.push_back("un");
        stop_words.push_back("under");
        stop_words.push_back("underneath");
        stop_words.push_back("undoing");
        stop_words.push_back("unfortunately");
        stop_words.push_back("unless");
        stop_words.push_back("unlike");
        stop_words.push_back("unlikely");
        stop_words.push_back("until");
        stop_words.push_back("unto");
        stop_words.push_back("up");
        stop_words.push_back("upon");
        stop_words.push_back("upwards");
        stop_words.push_back("us");
        stop_words.push_back("use");
        stop_words.push_back("used");
        stop_words.push_back("useful");
        stop_words.push_back("uses");
        stop_words.push_back("using");
        stop_words.push_back("usually");
        stop_words.push_back("v");
        stop_words.push_back("value");
        stop_words.push_back("various");
        stop_words.push_back("versus");
        stop_words.push_back("very");
        stop_words.push_back("via");
        stop_words.push_back("viz");
        stop_words.push_back("vs");
        stop_words.push_back("w");
        stop_words.push_back("want");
        stop_words.push_back("wants");
        stop_words.push_back("was");
        stop_words.push_back("wasn't");
        stop_words.push_back("way");
        stop_words.push_back("we");
        stop_words.push_back("we'd");
        stop_words.push_back("welcome");
        stop_words.push_back("well");
        stop_words.push_back("we'll");
        stop_words.push_back("went");
        stop_words.push_back("were");
        stop_words.push_back("we're");
        stop_words.push_back("weren't");
        stop_words.push_back("we've");
        stop_words.push_back("what");
        stop_words.push_back("whatever");
        stop_words.push_back("what'll");
        stop_words.push_back("what's");
        stop_words.push_back("what've");
        stop_words.push_back("when");
        stop_words.push_back("whence");
        stop_words.push_back("whenever");
        stop_words.push_back("where");
        stop_words.push_back("whereafter");
        stop_words.push_back("whereas");
        stop_words.push_back("whereby");
        stop_words.push_back("wherein");
        stop_words.push_back("where's");
        stop_words.push_back("whereupon");
        stop_words.push_back("wherever");
        stop_words.push_back("whether");
        stop_words.push_back("which");
        stop_words.push_back("whichever");
        stop_words.push_back("while");
        stop_words.push_back("whilst");
        stop_words.push_back("whither");
        stop_words.push_back("who");
        stop_words.push_back("who'd");
        stop_words.push_back("whoever");
        stop_words.push_back("whole");
        stop_words.push_back("who'll");
        stop_words.push_back("whom");
        stop_words.push_back("whomever");
        stop_words.push_back("who's");
        stop_words.push_back("whose");
        stop_words.push_back("why");
        stop_words.push_back("will");
        stop_words.push_back("willing");
        stop_words.push_back("wish");
        stop_words.push_back("with");
        stop_words.push_back("within");
        stop_words.push_back("without");
        stop_words.push_back("wonder");
        stop_words.push_back("won't");
        stop_words.push_back("would");
        stop_words.push_back("wouldn't");
        stop_words.push_back("x");
        stop_words.push_back("y");
        stop_words.push_back("yes");
        stop_words.push_back("yet");
        stop_words.push_back("you");
        stop_words.push_back("you'd");
        stop_words.push_back("you'll");
        stop_words.push_back("your");
        stop_words.push_back("you're");
        stop_words.push_back("yours");
        stop_words.push_back("yourself");
        stop_words.push_back("yourselves");
        stop_words.push_back("you've");
        stop_words.push_back("z");
        stop_words.push_back("zero");
        // </editor-fold>
        
        string text;
        for (const Card & card : cards) {
            text = card.get_text();
            // to lower, make set intersection, push to index
        }
    }

    const Card *
    search_engine::search_for(const std::string & card_name) {
        auto & cards = db.get_cards();
        for (auto && card : cards) {
            if (card.get_name() == card_name)
                return &card;
        }
        return nullptr;
    }

    const Card *
    search_engine::find_similar(const std::string &, size_t cnt) {
        // TODO check instantiation of index
        // find the same type set or other "similar" base set
        // check intersections, use vector of score, keywords have multiplicative
        // bonus
        // than sort, tak first cnt
        auto & cards = db.get_cards();
        return &cards[0];
    }
}
