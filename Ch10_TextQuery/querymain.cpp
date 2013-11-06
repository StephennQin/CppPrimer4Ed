#include "TextQuery.h"

using namespace std;

int main(int argc, char **argv) {
	ifstream infile;
	if (argc < 2 || !open_file(infile, argv[1])) {
		cerr << "No input file!" << endl;
		return EXIT_FAILURE;
	}
	TextQuery tq;
	tq.read_file(infile);
	while (true) {
		cout << "enter word to look for,or q to quit" << endl;
		string s;
		cin >> s;
		if (!cin || s == "q")
			break;
		set<TextQuery::line_no> locs = tq.run_query(s);
		print_results(locs, s, tq);
	}
	return 0;
}
