// C++ Primer 4th Edition Chapter 10 Exercises Section 10.5.2 Excercise 10.26 & 10.27
#include<iostream>
#include<map>
#include<string>

using namespace std;
typedef multimap<string, string> Author;
typedef Author::iterator AuIter;

int main()
{
    Author authors;
    string authorName, authorWork, searchItem;
    // Preparation Work : cin some items
    do{
        cout << "Enter author name(Ctrl+Z to quit):" << endl;
        cin >> authorName;
        if ( ! cin )
            break;
        cout << "Enter author's work (Ctrl+Z to quit)" << endl;
        while ( cin >> authorWork )
            authors.insert( make_pair(authorName,authorWork) );
        cin.clear();
    } while ( cin );
    cin.clear();

    // Search and Erasure work
    cout << "Who is the author that you want to erase? :" << endl;
    cin >> searchItem;
    Author::iterator iter;

    // for Exercise 10.26
    iter = authors.find( searchItem );
    if ( iter != authors.end() )
        authors.erase( searchItem );
    else
        cout << "No match found!" << endl;
    // end for Exercise 10.26

    // for Exercise 10.27
    pair<AuIter, AuIter> pos = authors.equal_range( searchItem );
    if ( pos.first != pos.second )
        authors.erase( pos.first, pos.second );
     else
        cout << "No match found!" << endl;
    // end for Exercise 10.27

    // Final stored items
    cout << "author\t\twork:" << endl;
    for( iter = authors.begin(); iter != authors.end(); iter++)
        cout << iter->first << "\t\t" << iter->second << endl;

    return 0;
}
