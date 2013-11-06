// C++ Primer 4th Edition Chapter 10 Exercises Section 10.6.4 Exercise 10.32

#include "myTextQuery.h"

using namespace std;

int main(int argc, char **argv)
{
    // open the file from which user will query words
	ifstream infile;
	if (argc < 2 || !open_file(infile, argv[1])) {
		cerr << "No input file!" << endl;
		return EXIT_FAILURE;
	}
	TextQuery tq;
	tq.read_file(infile); // builds query map
	// iterate with the user: prompt for a word to find and print results
	// loop indefinitely; the loop exit is inside the while
	while (true) {
		cout << "enter word to look for,or q to quit" << endl;
		string s;
		cin >> s;
		// change letters into lower case
		string ret;
		for ( string::const_iterator it = s.begin(); it != s.end(); ++it)
		//for ( string::iterator it = s.begin(); it != s.end(); ++it)
			ret += tolower( *it );
			// *it = tolower( *it );
		s = ret;
		// stop if hit eof on input or a 'q' is entered
		if (!cin || s == "q")
			break;
        	// get the vector set of line numbers on which this word appears
		vector<TextQuery::line_no> locs = tq.run_query(s);
		// print count and all occurrences, if any
		print_results(locs, s, tq);
	}
	return 0;
}
