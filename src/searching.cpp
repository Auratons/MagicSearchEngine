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

#include <algorithm>
#include <unordered_set>
#include <set>
#include <sstream>
#include <cmath>
#include "searching.hpp"
#include "database.hpp"

using namespace std;

namespace magicSearchEngine {

    /*
     * For each card reads its text, divides it to words, converts the word to
     * lowercase, exclude duplicities, stop words and stores set of resulting
     * words in index for fast full-text search.
     */
    void
    search_engine::create_index() {
        unordered_set<string> stop_words;
        // <editor-fold defaultstate="collapsed" desc="stop_words instantiation">
        stop_words.insert("");
        stop_words.insert("a");
        stop_words.insert("able");
        stop_words.insert("about");
        stop_words.insert("above");
        stop_words.insert("abroad");
        stop_words.insert("according");
        stop_words.insert("accordingly");
        stop_words.insert("across");
        stop_words.insert("actually");
        stop_words.insert("adj");
        stop_words.insert("after");
        stop_words.insert("afterwards");
        stop_words.insert("again");
        stop_words.insert("against");
        stop_words.insert("ago");
        stop_words.insert("ahead");
        stop_words.insert("ain't");
        stop_words.insert("all");
        stop_words.insert("allow");
        stop_words.insert("allows");
        stop_words.insert("almost");
        stop_words.insert("alone");
        stop_words.insert("along");
        stop_words.insert("alongside");
        stop_words.insert("already");
        stop_words.insert("also");
        stop_words.insert("although");
        stop_words.insert("always");
        stop_words.insert("am");
        stop_words.insert("amid");
        stop_words.insert("amidst");
        stop_words.insert("among");
        stop_words.insert("amongst");
        stop_words.insert("an");
        stop_words.insert("and");
        stop_words.insert("another");
        stop_words.insert("any");
        stop_words.insert("anybody");
        stop_words.insert("anyhow");
        stop_words.insert("anyone");
        stop_words.insert("anything");
        stop_words.insert("anyway");
        stop_words.insert("anyways");
        stop_words.insert("anywhere");
        stop_words.insert("apart");
        stop_words.insert("appear");
        stop_words.insert("appreciate");
        stop_words.insert("appropriate");
        stop_words.insert("are");
        stop_words.insert("aren't");
        stop_words.insert("around");
        stop_words.insert("as");
        stop_words.insert("a's");
        stop_words.insert("aside");
        stop_words.insert("ask");
        stop_words.insert("asking");
        stop_words.insert("associated");
        stop_words.insert("at");
        stop_words.insert("available");
        stop_words.insert("away");
        stop_words.insert("awfully");
        stop_words.insert("b");
        stop_words.insert("back");
        stop_words.insert("backward");
        stop_words.insert("backwards");
        stop_words.insert("be");
        stop_words.insert("became");
        stop_words.insert("because");
        stop_words.insert("become");
        stop_words.insert("becomes");
        stop_words.insert("becoming");
        stop_words.insert("been");
        stop_words.insert("before");
        stop_words.insert("beforehand");
        stop_words.insert("begin");
        stop_words.insert("behind");
        stop_words.insert("being");
        stop_words.insert("believe");
        stop_words.insert("below");
        stop_words.insert("beside");
        stop_words.insert("besides");
        stop_words.insert("best");
        stop_words.insert("better");
        stop_words.insert("between");
        stop_words.insert("beyond");
        stop_words.insert("both");
        stop_words.insert("brief");
        stop_words.insert("but");
        stop_words.insert("by");
        stop_words.insert("c");
        stop_words.insert("came");
        stop_words.insert("can");
        stop_words.insert("cannot");
        stop_words.insert("cant");
        stop_words.insert("can't");
        stop_words.insert("caption");
        stop_words.insert("cause");
        stop_words.insert("causes");
        stop_words.insert("certain");
        stop_words.insert("certainly");
        stop_words.insert("changes");
        stop_words.insert("clearly");
        stop_words.insert("c'mon");
        stop_words.insert("co");
        stop_words.insert("co.");
        stop_words.insert("com");
        stop_words.insert("come");
        stop_words.insert("comes");
        stop_words.insert("concerning");
        stop_words.insert("consequently");
        stop_words.insert("consider");
        stop_words.insert("considering");
        stop_words.insert("contain");
        stop_words.insert("containing");
        stop_words.insert("contains");
        stop_words.insert("corresponding");
        stop_words.insert("could");
        stop_words.insert("couldn't");
        stop_words.insert("course");
        stop_words.insert("c's");
        stop_words.insert("currently");
        stop_words.insert("d");
        stop_words.insert("dare");
        stop_words.insert("daren't");
        stop_words.insert("definitely");
        stop_words.insert("described");
        stop_words.insert("despite");
        stop_words.insert("did");
        stop_words.insert("didn't");
        stop_words.insert("different");
        stop_words.insert("directly");
        stop_words.insert("do");
        stop_words.insert("does");
        stop_words.insert("doesn't");
        stop_words.insert("doing");
        stop_words.insert("done");
        stop_words.insert("don't");
        stop_words.insert("down");
        stop_words.insert("downwards");
        stop_words.insert("during");
        stop_words.insert("e");
        stop_words.insert("each");
        stop_words.insert("edu");
        stop_words.insert("eg");
        stop_words.insert("eight");
        stop_words.insert("eighty");
        stop_words.insert("either");
        stop_words.insert("else");
        stop_words.insert("elsewhere");
        stop_words.insert("end");
        stop_words.insert("ending");
        stop_words.insert("enough");
        stop_words.insert("entirely");
        stop_words.insert("especially");
        stop_words.insert("et");
        stop_words.insert("etc");
        stop_words.insert("even");
        stop_words.insert("ever");
        stop_words.insert("evermore");
        stop_words.insert("every");
        stop_words.insert("everybody");
        stop_words.insert("everyone");
        stop_words.insert("everything");
        stop_words.insert("everywhere");
        stop_words.insert("ex");
        stop_words.insert("exactly");
        stop_words.insert("example");
        stop_words.insert("except");
        stop_words.insert("f");
        stop_words.insert("fairly");
        stop_words.insert("far");
        stop_words.insert("farther");
        stop_words.insert("few");
        stop_words.insert("fewer");
        stop_words.insert("fifth");
        stop_words.insert("first");
        stop_words.insert("five");
        stop_words.insert("followed");
        stop_words.insert("following");
        stop_words.insert("follows");
        stop_words.insert("for");
        stop_words.insert("forever");
        stop_words.insert("former");
        stop_words.insert("formerly");
        stop_words.insert("forth");
        stop_words.insert("forward");
        stop_words.insert("found");
        stop_words.insert("four");
        stop_words.insert("from");
        stop_words.insert("further");
        stop_words.insert("furthermore");
        stop_words.insert("g");
        stop_words.insert("get");
        stop_words.insert("gets");
        stop_words.insert("getting");
        stop_words.insert("given");
        stop_words.insert("gives");
        stop_words.insert("go");
        stop_words.insert("goes");
        stop_words.insert("going");
        stop_words.insert("gone");
        stop_words.insert("got");
        stop_words.insert("gotten");
        stop_words.insert("greetings");
        stop_words.insert("h");
        stop_words.insert("had");
        stop_words.insert("hadn't");
        stop_words.insert("half");
        stop_words.insert("happens");
        stop_words.insert("hardly");
        stop_words.insert("has");
        stop_words.insert("hasn't");
        stop_words.insert("have");
        stop_words.insert("haven't");
        stop_words.insert("having");
        stop_words.insert("he");
        stop_words.insert("he'd");
        stop_words.insert("he'll");
        stop_words.insert("hello");
        stop_words.insert("help");
        stop_words.insert("hence");
        stop_words.insert("her");
        stop_words.insert("here");
        stop_words.insert("hereafter");
        stop_words.insert("hereby");
        stop_words.insert("herein");
        stop_words.insert("heres");
        stop_words.insert("hereupon");
        stop_words.insert("hers");
        stop_words.insert("herself");
        stop_words.insert("hes");
        stop_words.insert("hi");
        stop_words.insert("him");
        stop_words.insert("himself");
        stop_words.insert("his");
        stop_words.insert("hither");
        stop_words.insert("hopefully");
        stop_words.insert("how");
        stop_words.insert("howbeit");
        stop_words.insert("however");
        stop_words.insert("hundred");
        stop_words.insert("i");
        stop_words.insert("id");
        stop_words.insert("ie");
        stop_words.insert("if");
        stop_words.insert("ignored");
        stop_words.insert("ill");
        stop_words.insert("im");
        stop_words.insert("immediate");
        stop_words.insert("in");
        stop_words.insert("inasmuch");
        stop_words.insert("inc");
        stop_words.insert("inc.");
        stop_words.insert("indeed");
        stop_words.insert("indicate");
        stop_words.insert("indicated");
        stop_words.insert("indicates");
        stop_words.insert("inner");
        stop_words.insert("inside");
        stop_words.insert("insofar");
        stop_words.insert("instead");
        stop_words.insert("into");
        stop_words.insert("inward");
        stop_words.insert("is");
        stop_words.insert("isnt");
        stop_words.insert("it");
        stop_words.insert("itd");
        stop_words.insert("itll");
        stop_words.insert("its");
        stop_words.insert("its");
        stop_words.insert("itself");
        stop_words.insert("ive");
        stop_words.insert("j");
        stop_words.insert("just");
        stop_words.insert("k");
        stop_words.insert("keep");
        stop_words.insert("keeps");
        stop_words.insert("kept");
        stop_words.insert("know");
        stop_words.insert("known");
        stop_words.insert("knows");
        stop_words.insert("l");
        stop_words.insert("last");
        stop_words.insert("lately");
        stop_words.insert("later");
        stop_words.insert("latter");
        stop_words.insert("latterly");
        stop_words.insert("least");
        stop_words.insert("less");
        stop_words.insert("lest");
        stop_words.insert("let");
        stop_words.insert("lets");
        stop_words.insert("like");
        stop_words.insert("liked");
        stop_words.insert("likely");
        stop_words.insert("likewise");
        stop_words.insert("little");
        stop_words.insert("look");
        stop_words.insert("looking");
        stop_words.insert("looks");
        stop_words.insert("low");
        stop_words.insert("lower");
        stop_words.insert("ltd");
        stop_words.insert("m");
        stop_words.insert("made");
        stop_words.insert("mainly");
        stop_words.insert("make");
        stop_words.insert("makes");
        stop_words.insert("many");
        stop_words.insert("may");
        stop_words.insert("maybe");
        stop_words.insert("maynt");
        stop_words.insert("me");
        stop_words.insert("mean");
        stop_words.insert("meantime");
        stop_words.insert("meanwhile");
        stop_words.insert("merely");
        stop_words.insert("might");
        stop_words.insert("mightnt");
        stop_words.insert("mine");
        stop_words.insert("minus");
        stop_words.insert("miss");
        stop_words.insert("more");
        stop_words.insert("moreover");
        stop_words.insert("most");
        stop_words.insert("mostly");
        stop_words.insert("mr");
        stop_words.insert("mrs");
        stop_words.insert("much");
        stop_words.insert("must");
        stop_words.insert("mustnt");
        stop_words.insert("my");
        stop_words.insert("myself");
        stop_words.insert("n");
        stop_words.insert("name");
        stop_words.insert("namely");
        stop_words.insert("nd");
        stop_words.insert("near");
        stop_words.insert("nearly");
        stop_words.insert("necessary");
        stop_words.insert("need");
        stop_words.insert("neednt");
        stop_words.insert("needs");
        stop_words.insert("neither");
        stop_words.insert("never");
        stop_words.insert("neverf");
        stop_words.insert("neverless");
        stop_words.insert("nevertheless");
        stop_words.insert("new");
        stop_words.insert("next");
        stop_words.insert("nine");
        stop_words.insert("ninety");
        stop_words.insert("no");
        stop_words.insert("nobody");
        stop_words.insert("non");
        stop_words.insert("none");
        stop_words.insert("nonetheless");
        stop_words.insert("noone");
        stop_words.insert("no-one");
        stop_words.insert("nor");
        stop_words.insert("normally");
        stop_words.insert("not");
        stop_words.insert("nothing");
        stop_words.insert("notwithstanding");
        stop_words.insert("novel");
        stop_words.insert("now");
        stop_words.insert("nowhere");
        stop_words.insert("o");
        stop_words.insert("obviously");
        stop_words.insert("of");
        stop_words.insert("off");
        stop_words.insert("often");
        stop_words.insert("oh");
        stop_words.insert("ok");
        stop_words.insert("okay");
        stop_words.insert("old");
        stop_words.insert("on");
        stop_words.insert("once");
        stop_words.insert("one");
        stop_words.insert("ones");
        stop_words.insert("ones");
        stop_words.insert("only");
        stop_words.insert("onto");
        stop_words.insert("opposite");
        stop_words.insert("or");
        stop_words.insert("other");
        stop_words.insert("others");
        stop_words.insert("otherwise");
        stop_words.insert("ought");
        stop_words.insert("oughtnt");
        stop_words.insert("our");
        stop_words.insert("ours");
        stop_words.insert("ourselves");
        stop_words.insert("out");
        stop_words.insert("outside");
        stop_words.insert("over");
        stop_words.insert("overall");
        stop_words.insert("own");
        stop_words.insert("p");
        stop_words.insert("particular");
        stop_words.insert("particularly");
        stop_words.insert("past");
        stop_words.insert("per");
        stop_words.insert("perhaps");
        stop_words.insert("placed");
        stop_words.insert("please");
        stop_words.insert("plus");
        stop_words.insert("possible");
        stop_words.insert("presumably");
        stop_words.insert("probably");
        stop_words.insert("provided");
        stop_words.insert("provides");
        stop_words.insert("q");
        stop_words.insert("que");
        stop_words.insert("quite");
        stop_words.insert("qv");
        stop_words.insert("r");
        stop_words.insert("rather");
        stop_words.insert("rd");
        stop_words.insert("re");
        stop_words.insert("really");
        stop_words.insert("reasonably");
        stop_words.insert("recent");
        stop_words.insert("recently");
        stop_words.insert("regarding");
        stop_words.insert("regardless");
        stop_words.insert("regards");
        stop_words.insert("relatively");
        stop_words.insert("respectively");
        stop_words.insert("right");
        stop_words.insert("round");
        stop_words.insert("s");
        stop_words.insert("said");
        stop_words.insert("same");
        stop_words.insert("saw");
        stop_words.insert("say");
        stop_words.insert("saying");
        stop_words.insert("says");
        stop_words.insert("second");
        stop_words.insert("secondly	");
        stop_words.insert("see");
        stop_words.insert("seeing");
        stop_words.insert("seem");
        stop_words.insert("seemed");
        stop_words.insert("seeming");
        stop_words.insert("seems");
        stop_words.insert("seen");
        stop_words.insert("self");
        stop_words.insert("selves");
        stop_words.insert("sensible");
        stop_words.insert("sent");
        stop_words.insert("serious");
        stop_words.insert("seriously");
        stop_words.insert("seven");
        stop_words.insert("several");
        stop_words.insert("shall");
        stop_words.insert("shant");
        stop_words.insert("she");
        stop_words.insert("shed");
        stop_words.insert("shell");
        stop_words.insert("shes");
        stop_words.insert("should");
        stop_words.insert("shouldnt");
        stop_words.insert("since");
        stop_words.insert("six");
        stop_words.insert("so");
        stop_words.insert("some");
        stop_words.insert("somebody");
        stop_words.insert("someday");
        stop_words.insert("somehow");
        stop_words.insert("someone");
        stop_words.insert("something");
        stop_words.insert("sometime");
        stop_words.insert("sometimes");
        stop_words.insert("somewhat");
        stop_words.insert("somewhere");
        stop_words.insert("soon");
        stop_words.insert("sorry");
        stop_words.insert("specified");
        stop_words.insert("specify");
        stop_words.insert("specifying");
        stop_words.insert("still");
        stop_words.insert("sub");
        stop_words.insert("such");
        stop_words.insert("sup");
        stop_words.insert("sure");
        stop_words.insert("t");
        stop_words.insert("take");
        stop_words.insert("taken");
        stop_words.insert("taking");
        stop_words.insert("tell");
        stop_words.insert("tends");
        stop_words.insert("th");
        stop_words.insert("than");
        stop_words.insert("thank");
        stop_words.insert("thanks");
        stop_words.insert("thanx");
        stop_words.insert("that");
        stop_words.insert("thatll");
        stop_words.insert("thats");
        stop_words.insert("thats");
        stop_words.insert("thatve");
        stop_words.insert("the");
        stop_words.insert("their");
        stop_words.insert("theirs");
        stop_words.insert("them");
        stop_words.insert("themselves");
        stop_words.insert("then");
        stop_words.insert("thence");
        stop_words.insert("there");
        stop_words.insert("thereafter");
        stop_words.insert("thereby");
        stop_words.insert("thered");
        stop_words.insert("therefore");
        stop_words.insert("therein");
        stop_words.insert("therell");
        stop_words.insert("therere");
        stop_words.insert("theres");
        stop_words.insert("theres");
        stop_words.insert("thereupon");
        stop_words.insert("thereve");
        stop_words.insert("these");
        stop_words.insert("they");
        stop_words.insert("theyd");
        stop_words.insert("theyll");
        stop_words.insert("theyre");
        stop_words.insert("theyve");
        stop_words.insert("thing");
        stop_words.insert("things");
        stop_words.insert("think");
        stop_words.insert("third");
        stop_words.insert("thirty");
        stop_words.insert("this");
        stop_words.insert("thorough");
        stop_words.insert("thoroughly");
        stop_words.insert("those");
        stop_words.insert("though");
        stop_words.insert("three");
        stop_words.insert("through");
        stop_words.insert("throughout");
        stop_words.insert("thru");
        stop_words.insert("thus");
        stop_words.insert("till");
        stop_words.insert("to");
        stop_words.insert("together");
        stop_words.insert("too");
        stop_words.insert("took");
        stop_words.insert("toward");
        stop_words.insert("towards");
        stop_words.insert("tried");
        stop_words.insert("tries");
        stop_words.insert("truly");
        stop_words.insert("try");
        stop_words.insert("trying");
        stop_words.insert("ts");
        stop_words.insert("twice");
        stop_words.insert("two");
        stop_words.insert("u");
        stop_words.insert("un");
        stop_words.insert("under");
        stop_words.insert("underneath");
        stop_words.insert("undoing");
        stop_words.insert("unfortunately");
        stop_words.insert("unless");
        stop_words.insert("unlike");
        stop_words.insert("unlikely");
        stop_words.insert("until");
        stop_words.insert("unto");
        stop_words.insert("up");
        stop_words.insert("upon");
        stop_words.insert("upwards");
        stop_words.insert("us");
        stop_words.insert("use");
        stop_words.insert("used");
        stop_words.insert("useful");
        stop_words.insert("uses");
        stop_words.insert("using");
        stop_words.insert("usually");
        stop_words.insert("v");
        stop_words.insert("value");
        stop_words.insert("various");
        stop_words.insert("versus");
        stop_words.insert("very");
        stop_words.insert("via");
        stop_words.insert("viz");
        stop_words.insert("vs");
        stop_words.insert("w");
        stop_words.insert("want");
        stop_words.insert("wants");
        stop_words.insert("was");
        stop_words.insert("wasnt");
        stop_words.insert("way");
        stop_words.insert("we");
        stop_words.insert("wed");
        stop_words.insert("welcome");
        stop_words.insert("well");
        stop_words.insert("well");
        stop_words.insert("went");
        stop_words.insert("were");
        stop_words.insert("were");
        stop_words.insert("werent");
        stop_words.insert("weve");
        stop_words.insert("what");
        stop_words.insert("whatever");
        stop_words.insert("whatll");
        stop_words.insert("whats");
        stop_words.insert("whatve");
        stop_words.insert("when");
        stop_words.insert("whence");
        stop_words.insert("whenever");
        stop_words.insert("where");
        stop_words.insert("whereafter");
        stop_words.insert("whereas");
        stop_words.insert("whereby");
        stop_words.insert("wherein");
        stop_words.insert("wheres");
        stop_words.insert("whereupon");
        stop_words.insert("wherever");
        stop_words.insert("whether");
        stop_words.insert("which");
        stop_words.insert("whichever");
        stop_words.insert("while");
        stop_words.insert("whilst");
        stop_words.insert("whither");
        stop_words.insert("who");
        stop_words.insert("whod");
        stop_words.insert("whoever");
        stop_words.insert("whole");
        stop_words.insert("wholl");
        stop_words.insert("whom");
        stop_words.insert("whomever");
        stop_words.insert("whos");
        stop_words.insert("whose");
        stop_words.insert("why");
        stop_words.insert("will");
        stop_words.insert("willing");
        stop_words.insert("wish");
        stop_words.insert("with");
        stop_words.insert("within");
        stop_words.insert("without");
        stop_words.insert("wonder");
        stop_words.insert("wont");
        stop_words.insert("would");
        stop_words.insert("wouldnt");
        stop_words.insert("x");
        stop_words.insert("y");
        stop_words.insert("yes");
        stop_words.insert("yet");
        stop_words.insert("you");
        stop_words.insert("youd");
        stop_words.insert("youll");
        stop_words.insert("your");
        stop_words.insert("youre");
        stop_words.insert("yours");
        stop_words.insert("yourself");
        stop_words.insert("yourselves");
        stop_words.insert("youve");
        stop_words.insert("z");
        stop_words.insert("zero");
        // </editor-fold>

        const vector<Card> & cards = db.get_cards();
        for (const Card & card : cards) {
            istringstream text(card.get_text());
            string word;
            set<string> bucket;
            while (text >> word) {
                // We build index only for lowercase words.
                transform(word.begin(), word.end(), word.begin(), ::tolower);
                // Also we want to remove punctuation from whitespace-cut words.
                word.erase(remove_if(word.begin(), word.end(), [](char x) {
                    return ispunct(x); }), word.end());
                // Stop words also do not contain punctuation (you'll).
                if (stop_words.count(word) == 0) {
                    bucket.insert(word);
                }
            }
            index.push_back(move(bucket));
        }
        index_was_loaded = true;
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

    struct {

        bool operator()(pair<size_t, const Card *> a, pair<size_t, const Card *> b) const {
            return a.first < b.first;
        }
    } customLess;

    vector<const Card *>
    search_engine::find_similar(const std::string & card_name, size_t cnt) {
        // Firstly we check if the search_engine is properly instantiated.
        if (!index_was_loaded)
            throw bad_optional_access("Firstly you must create_index().");
        // Then we linearly find the card to which we search for similar.
        const Card * base_card = search_for(card_name);
        if (!base_card) {
            return move(vector<const Card *>());
        }
        // We find and sort subsets of all cards that share types of base_card.
        using cards_with_type = vector<const Card *>;
        vector<cards_with_type> base_sets;
        for (const string * type : base_card->get_types()) {
            vector<const Card *> typeset = get_type(*type);
            sort(typeset.begin(), typeset.end());
            base_sets.push_back(typeset);
        }
        // Now we find intersection of all typesets.
        vector<const Card *> & intersection = base_sets[0];
        if (base_sets.size() != 1) {
            size_t j = base_sets.size();
            for (size_t i = 1; i < j; ++i) {
                vector<const Card *> temp;
                set_intersection(intersection.begin(), intersection.end(),
                        base_sets[i].begin(), base_sets[i].end(),
                        back_inserter(temp));
                swap(temp, intersection);
            }
        }
        // Let's delete base_card from intersection.
        auto && it = find(begin(intersection), end(intersection), base_card);
        if (it != end(intersection))
            intersection.erase(it);
        // Now we define a vector space for fields of cards and turn all fields
        // to numeral values. For text fields we use method from full-text search.
        // The vector space has dimension of 9 for layout, manaCost, colors, text,
        // power, toughness, loyalty, hand, life.
        vector<pair<size_t, const Card *> > distances;
        for (const Card * card : intersection) {
            distances.push_back(make_pair(get_distance(card, base_card), card));
        }
        sort(begin(distances), end(distances), customLess);
        vector<const Card *> res;
        size_t j = (cnt < distances.size()) ? cnt : distances.size();
        for (size_t i = 0; i < j; ++i) {
            res.push_back(distances[i].second);
        }
        return move(res);
    }

    /*
     * Returns all cards that as a one of them types have specified type.
     * The result is intended to be used for making set intersection in
     * similarity search. Vector is used, because there is an assumption about
     * db.get_cards(). Cards in json file are sorted, so as an assumption sorting
     * probably sorted vector will be cheaper than logarithmic adding to std::set.
     */
    vector<const Card *>
    search_engine::get_type(const string & type) {
        vector<const Card *> res;
        const vector<Card> & cards = db.get_cards();
        for (const Card & card : cards) {
            const types_t & card_types = card.get_types();
            // Typically, size of card_types is 1,2, only for one it's more.
            for (auto && type_ : card_types) {
                if ((*type_) == type)
                    res.push_back(&card);
            }
        }
        return move(res);
    }

    /*
     * A crucial method. Determines distance between two cards. Current 
     * implementation is simple, for better results a small research and setting
     * multiplicative constants should be conducted.
     */
    size_t
    search_engine::get_distance(const Card * card, const Card * base_card) {
        size_t layout_d = 0;
        float power_d = 0;
        float toughness_d = 0;
        size_t loyalty_d = 0;
        size_t hand_d = 0;
        size_t life_d = 0;
        size_t text_d = 0;
        size_t colors_d = 0;

        auto && to_float = [](const feature & f1, const feature & f2) {
            float res = 0;
            res = abs(f1.whole_part - f2.whole_part);
            res += 0.5 * abs((int) f1.half - (int) f2.half);
            res += 50 * abs((int) f1.asterics - (int) f2.asterics);
            return res;
        };
        auto && dist_colors = [](const vector<const string *> & a,
                const vector<const std::string *> & b) -> size_t {
                    vector<const string *> intersection;
                    set_intersection(begin(a), end(a), begin(b), end(b), back_inserter(intersection));
                    if (intersection.size() == 0)
                        return 50;
                    if (intersection.size() == a.size() && intersection.size() == b.size())
                        return 0;
                    if (intersection.size() != a.size() && intersection.size() == b.size())
                        return 10;
                    if (intersection.size() == a.size() && intersection.size() != b.size())
                        return 10;
                    else
                        return 40;
                };
        if (card->get_layout() != base_card->get_layout())
            layout_d = 1;
        power_d = to_float(card->get_power(), base_card->get_power());
        toughness_d = to_float(card->get_toughness(), base_card->get_toughness());
        loyalty_d = abs(card->get_loyalty() - base_card->get_loyalty());
        hand_d = abs(card->get_hand() - base_card->get_hand());
        life_d = abs(card->get_life() - base_card->get_life());
        text_d = full_text(card, base_card);
        colors_d = dist_colors(card->get_colors(), base_card->get_colors());

        // We don't need return actual distance with the square root, since we
        // need only comparability between "distances", only the sum of the
        // squares is sufficient.
        return pow(layout_d, 2) +
                pow(power_d, 2) +
                pow(toughness_d, 2) +
                pow(loyalty_d, 2) +
                pow(hand_d, 2) +
                pow(life_d, 2) +
                pow(text_d, 2);
    }

    /*
     * Determines distance on text-axis. Firstly we find intersection of indices
     * for both cards, then evaluate each word in intersection. If the word is
     * within keywords, it has bigger weight, otherwise smaller. We add up weights,
     * then return distance as a reciprocal of the sum times 100 since closer
     * cards means smaller distance in some dimension.
     */
    size_t
    search_engine::full_text(const Card * card, const Card * base_card) {
        size_t c_pos = card - &(db.get_cards()[0]);
        size_t bc_pos = base_card - &(db.get_cards()[0]);
        vector<string> intersection;
        set<string> c_ind = index[c_pos];
        set<string> bc_ind = index[bc_pos];
        set_intersection(begin(c_ind), end(c_ind),
                begin(bc_ind), end(bc_ind),
                back_inserter(intersection));
        size_t res = 0;
        for (const string & word : intersection) {
            if (db.get_keyword_abilities().count(word) +
                    db.get_keyword_actions().count(word) == 0) {
                res++;
            }
            else {
                res += 2;
            }
        }
        if (intersection.size() == 0)
            res = 100;
        else
            res = 100 / res;
        return res;
    }
}
