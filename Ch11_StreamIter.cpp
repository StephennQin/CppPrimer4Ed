// C++ Primer 4th Edition Chapter 11 Section 11.3.2 Self-Practise & Exercise Section 13.3.2 Exercise 11.16 & 11.18
#include <iostream>
#include <fstream>
#include <iterator>     // std::istream_iterator
#include <vector>
#include <algorithm>
#include <cstdlib> // header for EXIT_FALURE

using namespace std;

int main()
{
    // Self-exercise
    cout << "Enter integers to initialize a int type vector.( Ctrl+Z to end )" << endl;
    istream_iterator<int> in_iter(cin), eof;
    ostream_iterator<int> out_iter( cout, "\t" );

    vector<int> ivec(in_iter,eof);
    /*
    while ( in_iter != eof )
        ivec.push_back( *in_iter++ );
    */
    vector<int>::iterator iter = ivec.begin();

    while ( iter != ivec.end() )
        *out_iter++ = *iter++;
    cout << endl;

    sort( ivec.begin(), ivec.end() );
    unique_copy( ivec.begin(), ivec.end(), out_iter );
    cout << endl;


    // for Exercise 11.16
    string fileName = "Ch11_TestText.txt";
    /* // designate a specific file
    cout << "Enter the name of input file:" << endl;
    cin >> fileName;
    */
    fstream file;
    file.close();  file.clear();
    file.open( fileName.c_str() );
    if ( ! file.is_open()  )
    {
		cerr << "No input file!" << endl;
		return EXIT_FAILURE;
    }
    ostream_iterator<string> out_str_iter( cout, " " );
    istream_iterator<string> in_str_iter( file ), str_eof;
    copy( in_str_iter, str_eof, out_str_iter );
    file.close();


    //  for Exercise 11.18
    cin.clear();    cin.sync();    cout << endl;
    ofstream oddFile( "oddfile.dat" );
    ofstream evenFile( "evenfile.dat" );
    if ( !oddFile || !evenFile )
    {
		cerr << "Cannot open output file!" << endl;
		return EXIT_FAILURE;
    }
    cout << "Enter integers to proceed.( Ctrl+Z to end )" << endl;
    ostream_iterator<int> out_odd_iter( oddFile, " " );
    ostream_iterator<int> out_even_iter( evenFile, "\n" );
    while ( in_iter != eof )
    {
        if ( *in_iter % 2 == 0 )
            *out_even_iter++ = *in_iter;
        else
            *out_odd_iter++ = *in_iter;
        ++in_iter;
    }
    oddFile.close();    evenFile.close();

    return 0;
}
