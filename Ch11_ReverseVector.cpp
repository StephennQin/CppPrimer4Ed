// C++ Primer 4th Edition Chapter 11 Section 11.3.3  Exercise Section 13.3.3 Exercise 11.19 - 11.22
#include <iostream>
#include <iterator>     // std::istream_iterator
#include <vector>
#include <list>
#include <algorithm>
#include <cstdlib> // header for EXIT_FALURE

using namespace std;

int main()
{
    int ia[] = {0,1,2,3,4,5,6,7,8,9};
    vector<int> ivec(ia,ia+10);
    vector<int>::iterator iter;
    vector<int>::reverse_iterator r_iter;
    // for Exercise 11.19
    for( r_iter = ivec.rbegin(); r_iter != ivec.rend(); ++r_iter )
        cout << *r_iter << "\t";
    cout << endl;
    // for Exercise 11.20
    for( iter = --ivec.end(); iter >= ivec.begin(); --iter )
        cout << *iter << "\t";
    cout << endl;
    //for Exercise 11.21
    int ival(0);
    cout << "Input the number you want to search (0-9):" << endl;
    cin >> ival;
    r_iter = find( ivec.rbegin(), ivec.rend(), ival );
    if ( r_iter == ivec.rend() )
        cout << "No element is " << ival << endl;
    else
        cout << "Match found! The last occurance of" << ival
            << " is at position " << *r_iter.base() //*(--r_iter)
            <<endl;

    return 0;
}
