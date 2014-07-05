// C++ Primer 4th Edition Chapter 11 Exercises Section 11.2.3 Excercise 11.9 & 11.10
#include<iostream>
#include<fstream>
#include<sstream>
#include<string>
#include<vector>
#include<algorithm>
#include<cstdlib> // header for EXIT_FALURE

using namespace std;

int val(6);
// Predicate Functions:
bool isShorter( const string &s1, const string &s2 ) // comparison function to be used to sort by word length
{
    return s1.size() < s2.size();
}
bool GTn( const string &s )// determine whether a length of a given word is n or more
{
    return s.size() >= val;
}

class GT_cls
{
public:
    GT_cls ( size_t val = 0 ): bound(val) {}
    bool operator() ( const string &s ) { return s.size() >= bound; }
private:
    string::size_type bound;
};

inline string make_plural( size_t ctr, const string &word, const string &ending )
{
    return ( ctr == 1 ) ? word : word + ending;
}
int main()
{
    string fileName = "Ch11_TestText.txt";
    string line, word;
    vector<string> words;
    fstream file;
    file.close();  file.clear();
    file.open( fileName.c_str() );
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
    sort( words.begin(), words.end() ); // sort words alphabetically so we can find the duplicates
    /* eliminate duplicate words:
     * unique reorders words so that each word appears once in the
     *       front portion of words and returns an iterator one past the unique range;
     * erase uses a vector operation to remove the nonunique elements
     */
    vector<string>::iterator ster = unique( words.begin(), words.end() );
    words.erase( ster, words.end() );
    stable_sort( words.begin(), words.end(), isShorter );// sort words by size, but maintain alphabetic order for words of the same size
    cout << "Enter the length of word you want to count:" << endl;
    cin >> val;  cin.clear();
    // for Exercise 11.9
    vector<string>::size_type counter = count_if( words.begin(), words.end(), GTn );
    //vector<string>::size_type counter = count_if( words.begin(), words.end(), GT_cls(val) );

    /*
    // for Exercise 11.10
    vector<string>::size_type counter = 0;
    ster = words.begin();
    while ( (ster = find_if( ster, words.end(),GTn )) != words.end() )
    {
        ++counter;  ++ster;
    }
    */
    cout << counter << " " << make_plural( counter, "word", "s" ) << " " << val << " characters or longer" << endl;
    file.close();
    return 0;
}
