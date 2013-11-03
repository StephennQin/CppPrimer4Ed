#include <iostream>
#include <string>
#include <vector>
#include <list>

using namespace std;

int main()
{
    // Part 1
    string sarray[4] = { "quasi", "simba", "frollo", "scar" };
    list<string> slist;
    slist.insert( slist.end(), sarray, sarray+4 );
    list<string>::iterator slist_iter = slist.begin();
    slist.insert( slist_iter, sarray+2, sarray+4 );
    cout << "Part 1: String Copy" << endl;
    for( slist_iter = slist.begin(); slist_iter != slist.end(); ++slist_iter )
    {
        //string stemp = *slist_iter; list<int>::reference stemp = slist.at();slist[n]
        cout << *slist_iter << endl;
    }
    //Part 2
    int a[4] = {5, 6, 7, 8};
    vector<int> v(a, a+4);
    // vector<int> v; // This still leaves v as an empty vector after for loop
    vector<int>::iterator first = v.begin();
    for( int n = 0; (first != v.end())&&(n != 5); n++)
    {
        first = v.insert( first, n );
        ++first;
    }
    cout << "\nPart 2: Vector Insert" << endl;
    for( first = v.begin(); first != v.end(); ++first )
    {
        cout << *first << endl;
    }
    v.erase( v.begin(), v.begin()+4 );
    cout << "After Erase" << endl;
    for( first = v.begin(); first != v.end(); ++first)
    {
        cout << *first << endl;
    }

    return 0;
}
