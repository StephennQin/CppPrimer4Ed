// C++ Primer 4th Edition Chapter 14 Exercises Section 14.8.1 Excercise 14.35 & 14.36
#include <iostream>
#include<fstream>
#include<sstream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <ctime>

using namespace std;

// comparison function to be used to sort by word length
bool isShorter( const string &s1, const string &s2 )
{
    return s1.size() < s2.size();
}
inline string make_plural( size_t ctr, const string &word, const string &ending )
{
    return ( ctr == 1 ) ? word : word + ending;
}
class GT_cls{
public:
     GT_cls( size_t val = 0 ): bound(val) {}
     bool operator()( const string &s )
     {
         return s.size() >= bound;
     }
private:
    string::size_type bound;
};
class WGR_cls{ // WR = Within the Given Range
public:
     WGR_cls( size_t val1 = 0, size_t  val2 = 0 ): maxLen(val1), minLen(val2)
     {
         if( val1 < val2 ){
            minLen = val1;
            maxLen = val2;
         }
     }
     bool operator()( const string &s )
     {
         return ( s.size() >= minLen ) && ( s.size() <= maxLen );
     }
private:
    string::size_type maxLen, minLen;
};

int main( int argc, char **argv )
{
    string fileName = "Ch11_TestText.txt";
    string line, word;
    int val(0), maxLen(0), minLen(0);
    vector<string> words;
    fstream file;
    file.close();  file.clear();
//    if( argc < 2 ){
//        cerr << "No input files!" << endl;
//        return EXIT_FAILURE;
//    }
//    file.open( argv[1] );
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
    sort( words.begin(), words.end() );
    vector<string>::iterator ster = unique( words.begin(), words.end() );
    words.erase( ster, words.end() );
    stable_sort( words.begin(), words.end(), isShorter );// sort words by size, but maintain alphabetic order for words of the same size
    cout << "Enter the length of word you want to count:" << endl;
    cin >> val;  cin.clear();
    vector<string>::size_type counter = count_if( words.begin(), words.end(), GT_cls(val) );
    cout << counter << " " << make_plural( counter, "word", "s" ) << " " << val << " characters or longer" << endl;

    cout << "Enter the range of word lenth you want to count(2 integer numbers):" << endl;
    cin >> maxLen >> minLen;  cin.clear();
    counter = count_if( words.begin(), words.end(), WGR_cls(maxLen, minLen) );
    cout << counter << " " << make_plural( counter, "word", "s" ) << " between " << maxLen << " and " << minLen << " characters" << endl;

    file.close();
    return 0;
}
