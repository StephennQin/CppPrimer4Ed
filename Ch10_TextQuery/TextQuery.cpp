// C++ Primer 4th Edition Chapter 10 Section 10.6
#include "TextQuery.h"
#include <stdexcept>

// read input file: store each line as element in lines_of_text
void TextQuery::store_file(ifstream &is)
{
	string textline;
	while (getline(is, textline))
		lines_of_text.push_back(textline);
}

// finds whitespace-separated words in the input vector
// and puts the word in word_map along with the line number
void TextQuery::build_map()
{
	// process each line from the input vector
	for (line_no line_num = 0; line_num != lines_of_text.size(); ++line_num) {
		//we'll use line to read the text a word at a time
		istringstream line(lines_of_text[line_num]);
		string word;
		while (line >> word)
			// add this line number to the set;
			// subscript will add word to the map if it's not already there
			word_map[word].insert(line_num);
	}
}

set<TextQuery::line_no> TextQuery::run_query(const string &query_word) const
{
	//Note: must use find and not subscript the map directly
	//to avoid adding words to word_map!
	map<string, set<line_no> >::const_iterator loc = word_map.find(query_word);
	if (loc == word_map.end())
		return set<line_no>(); // not found, return empty set
	else
		return loc->second; // fetch and return set of line numbers for this word
}

string TextQuery::text_line(line_no line) const
{
	if (line < lines_of_text.size())
		return lines_of_text[line];
	throw std::out_of_range("line number out of range");
}

string make_plural(size_t ctr, const string &word, const string &ending)
{
	return (ctr == 1) ? word : word + ending;
}

ifstream &open_file(ifstream &in, const string &file)
{
	in.close();      // close in case it was already open
	in.clear();      // clear any existing errors
	// if the open fails, the stream will be in an invalid state
	in.open(file.c_str()); // open the file we were given
	return in; // condition state is good if open succeeded
}

void print_results(const set<TextQuery::line_no>& locs, const string& sought, const TextQuery &file)
{
	// if the word was found, then print count and all occurrences
	typedef set<TextQuery::line_no> line_nums;
	line_nums::size_type size = locs.size();
	cout << "\n" << sought << " occurs " << size << " " << make_plural(size, "time", "s") << endl;
	// print each line in which the word appeared
	line_nums::const_iterator it = locs.begin();
	for (; it != locs.end(); ++it) {
		cout << "\t(line" << (*it) + 1 << ")" << file.text_line(*it) << endl;
	}
}
