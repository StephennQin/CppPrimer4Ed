// C++ Primer 4th Edition Chapter 11 Section 11.3.1 Self-Practise & Exercise Section 13.3.1 Exercise 11.15
#include<iostream>
#include<algorithm>   /* replace_copy, unique_copy */
#include<vector>
#include<list>
#include<iterator>

using namespace std;

int main ()
{
    int myints[] = { 10, 20, 30, 30, 20, 10, 10, 20 };
    vector<int> ivec (8);
    list<int> ilst( myints, myints+8);
    // copy( myints, myints+8, back_inserter(ilst) );
    replace_copy( myints, myints+8, ivec.begin(), 20, 99 );
    cout << "vector<int> ivec contains:" << endl;
    for ( vector<int>::iterator iter =ivec.begin(); iter !=ivec.end(); ++iter )
        cout << *iter << "\t";
    cout << endl;
    list<int>::iterator it = find( ilst.begin(), ilst.end(), 30 );
    replace_copy( ivec.begin(), ivec.end(), inserter(ilst, it), 10, 100 );
    cout << "list<int> ilst contains:" << endl;
    for (  it=ilst.begin(); it!=ilst.end(); ++it )
        cout << *it << "\t";
    cout << endl;
    // for Exercise 11.15
    ivec.clear();
    unique_copy( ilst.begin(), ilst.end(), back_inserter(ivec) );
    /*
    template <class InputIterator, class OutputIterator>
    OutputIterator unique_copy (InputIterator first, InputIterator last, OutputIterator result)
    {
        if (first==last) return last;
            *result = *first;
        while (++first != last) {
            typename iterator_traits<InputIterator>::value_type val = *first;
            if (!(*result == val))   // or: if (!pred(*result,val)) for version (2)
                *(++result)=val;
        }
        return ++result;
    }
    */
    /* if ivec is not empty, we can use:
        vector<int>::iterator iter = unique_copy( ilst.begin(), ilst.end(), ivec.end() );
        cout << *iter << endl; */
    cout << "vector<int> ivec contains:" << endl;
    for ( vector<int>::iterator iter =ivec.begin(); iter !=ivec.end(); ++iter )
        cout << *iter << "\t";
    cout << endl;

    return 0;
}
