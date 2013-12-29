// C++ Primer 4th Edition Chapter 10 Exercises Section 10.5.2 Exercise 10.26 & 10.27 & 10.28
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

    // Final stored items Output
    cout << "author\t\twork:" << endl;
    for( iter = authors.begin(); iter != authors.end(); iter++)
        cout << iter->first << "\t\t" << iter->second << endl;

    // for Exercise 10.28
    iter = authors.begin();
    if ( iter == authors.end() )
    {
        cout << "Empty multimap!" << endl;
        return 0;
    }
    string currAuthor, preAuthor;
    do{
        currAuthor = iter->first;
        if ( preAuthor.empty() || currAuthor[0] != preAuthor[0] )
            cout << "Author Names Begining with '" << currAuthor[0] << "' :" <<endl;
        cout << currAuthor;
        for (pos = authors.equal_range(currAuthor); pos.first != pos.second; pos.first++)
            cout << ", " << pos.first->second;
        cout << endl;
        iter = pos.second;
        preAuthor = currAuthor;
    } while ( iter != authors.end() );
    // end for Exercise 10.28

    return 0;
}
