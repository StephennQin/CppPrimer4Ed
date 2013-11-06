// C++ Primer 4th Edition Chapter 10 Exercises Section 10.6.4 Excercise 10.32
#ifndef TEXTQUERY_H
#define TEXTQUERY_H

#include<iostream>
#include<fstream>   // hearder for ifstream
#include<string>
#include<vector>
#include<map>
#include <stdlib.h> // hearder for EXIT_FALURE
#include<sstream>   // hearder for istringstream
#include<utility>   // hearder for pairs
#include<cstring>
#include<cctype>

using namespace std;

class TextQuery {
public:
    typedef string::size_type str_size;
	typedef vector<string>::size_type line_no;
	/*  interface:
     	*   read_file builds internal data structures for the given file
     	*   run_query finds the given word and returns set of lines on which it appears
     	*   text_line returns a requested line from the input file
	*/
	void read_file(ifstream &is) {
		store_file(is);
		build_map();
	}
	vector<line_no> run_query(const string &) const;
	string text_line(line_no) const;
private:
    	// utility functions used by read_file
	void store_file(ifstream&); // store input file
	void build_map(); // associated each word with a set line numbers
	// remember the whole input file
	vector<string> lines_of_text;
	// map word to set of the lines on which it occurs
	map<string, vector<line_no> > word_map;
	static string cleanup_str(const string&);
};


ifstream &open_file(ifstream &in, const string &file);
void print_results(const vector<TextQuery::line_no>& locs, const string& sought, const TextQuery &file);
#endif
