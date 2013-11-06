#include<iostream>
#include<fstream>   //ifstream 的头文件
#include<set>
#include<string>
#include<vector>
#include<map>
#include <stdlib.h> //EXIT_FALURE 的头文件
#include<sstream>   //istringstream的头文件
#include<utility>   //pairs的头文件

using namespace std;

#ifndef TEXTQUERY_H_
#define TEXTQUERY_H_

class TextQuery {
public:
	typedef std::vector<std::string>::size_type line_no;
	void read_file(std::ifstream &is) {
		store_file(is);
		build_map();
	}
	std::set<line_no> run_query(const std::string &) const;
	std::string text_line(line_no) const;
private:
	void store_file(std::ifstream&);
	void build_map();
	std::vector<std::string> lines_of_text;
	std::map<std::string, std::set<line_no> > word_map;
};


ifstream &open_file(ifstream &in, const string &file);
void print_results(const set<TextQuery::line_no>& locs, const string& sought, const TextQuery &file);
#endif
