// C++ Primer 4th Edition Chapter 10 Exercises Section 10.4.2 Exercise 10.25
#include<iostream>
#include<set>
#include<vector>
#include<string>
#include<cstdlib>
#include<ctime>
using namespace std;
int main()
{
    vector<string> books;
    set<string> readedBooks;
    string name;
    // Generate Booklist
    cout << "Enter names for books you'd like to read (Ctrl+Z to quit)" << endl;
    while ( cin >> name )
        books.push_back( name );
    cin.clear();
    bool timeOver = false;
    string answer, bookName;
    // Set seed for random generator
    srand( (unsigned) time(NULL) );
    // Simulation for months gone
    while ( !timeOver && !books.empty() )
    {
        cout << "Would you like to read a book? (Y/N)" << endl;
        cin >> answer;
        if ( answer[0] == 'y' || answer[0] == 'Y' )
        {
            int i = rand() % books.size(); // Generate a pseudo random number
            bookName = books[i];
            cout << "You can read this book (radom pick): " << bookName << endl;
            readedBooks.insert( bookName );
            books.erase( books.begin() + i );
            // Read Confirmation
            cout << "Did you read it? (Y/N)" << endl;
            cin >> answer;
             if ( answer[0] == 'n' || answer[0] == 'N' ) // The book is not read
             {
                 readedBooks.erase( bookName );
                 books.push_back( bookName );
             }
        }
        cout << "Time Over? (Y/N)" << endl;
        cin >> answer;
        if ( answer[0] == 'y' || answer[0] == 'Y' )
        {
            timeOver = true; // Simulation for virtual 6 months gone
        }
    }
    if ( timeOver )
    {
        cout << "books read: " << endl;
        for ( set<string>::iterator sit = readedBooks.begin(); sit != readedBooks.end(); ++sit )
            cout << *sit << endl;
        cout << "books not read: " << endl;
        for ( vector<string>::iterator vit = books.begin(); vit != books.end(); ++vit )
            cout << *vit << endl;
    }
    else
        cout << "Congratulations! You have read all these books." << endl;
    return 0;
}
