// C++ Primer 4th Edition Chapter 11 Exercises Section 11.5 Excercise 11.29
#include<iostream>
#include<fstream>
#include<sstream>
#include<string>
#include<list>
#include<algorithm>
#include<cstdlib> // header for EXIT_FALURE

using namespace std;

unsigned int val(6);
// Predicate Functions:
bool GTn( const string &s )// determine whether a length of a given word is n or more
{
    return s.size() >= val;
}

inline string make_plural( size_t ctr, const string &word, const string &ending )
{
    return ( ctr == 1 ) ? word : word + ending;
}
int main()
// int main( int argc, char **argv )
{
    /*
    if ( argc < 2 )
        {
		cerr << "No input file!" << endl;
		return EXIT_FAILURE;
		}
    */
    string fileName = "Ch11_TestText.txt";
    string line, word;
    list<string> words;
    fstream file;
    file.close();  file.clear();
    file.open( fileName.c_str() ); // file.open( argv[1] );
    if ( ! file.is_open()  )
    {
		cerr << "No input file!" << endl;
		return EXIT_FAILURE;
    }
    while ( getline(file, line) )
    {
        istringstream stream(line);
        while ( stream >> word )
        {
            words.push_back( word );
        }
    }
    cout << "File Open Sucess!\tWords are read in!" << endl;
    words.sort();
    words.unique();
    for( list<string>::iterator slst = words.begin(); slst != words.end(); ++slst )
        cout << *slst << " ";
    cout << endl << endl << "Enter the length of word you want to count:" << endl;
    cin >> val;  cin.clear();
    list<string>::size_type counter = count_if( words.begin(), words.end(), GTn );
    cout << counter << " " << make_plural( counter, "word", "s" ) << " " << val << " characters or longer" << endl;
    file.close();
    return 0;
}
