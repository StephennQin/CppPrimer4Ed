// C++ Primer 4th Edition Chapter 11 Section 11.2 Self-Practise
#include<iostream>
#include<vector>
#include<list>
#include<algorithm>   /* count, fill_n, copy, sort, unique, distance, find_first_of */
#include<numeric>     /* accumlate */
#include<iterator>    /* back_inserter */
#include<cstdlib>     /* srand, rand */
#include<ctime>       /* time */

using namespace std;

int main()
{
    int val;
    vector<int> ivec;   // empty vector
    // initialize random seed:
    srand( time(NULL) );
    // Part 1
    for ( int i = 0; i != 10; ++i )
    {
        ivec.push_back( rand() % 10 + 1 );
    }
    fill_n( back_inserter( ivec ), 5, rand() % 10 );
    vector<int>::iterator iter;
    cout << "Elements in ivec are:" << endl;
    for ( iter = ivec.begin(); iter != ivec.end(); ++iter )
    {
        cout << *iter << "\t" ;
        if ( (iter-ivec.begin()+1) % 5 == 0)
            cout <<endl;
    }
    val = rand() % 10 + 1;
    cout << count( ivec.begin(), ivec.end(), val ) << " elements equal to " << val << endl;
    cout << "The summation of elements in ivec is: " << accumulate( ivec.begin(), ivec.end(), 0.0 ) << endl;
    cout << endl;
    // Part 2
    list<int> ilst(14);
    copy( ivec.begin(), ivec.end(), ilst.begin() ); // less effective than constructor
    /* when the target container is not empty, with different last(3rd) argument leading to different results:
       begin() makes a front-to-last copy, eg: vec_original = 0 1 2 3 4 5; vec_copy = 0 1 2 3
       end() makes a last-to-front copy, eg: vec_original = 0 1 2 3 4 5; vec_copy = 2 3 4 5
       it is a circular copy, eg: when 3rd agr is ++begin(),we get vec_copy = 3 0 1 2
                                                and --end(),we get vec_copy = 3 4 5 0*/
    cout << "Elements in ivec2 or ilst are:" << endl;
    for ( list<int>::iterator ilter = ilst.begin(); ilter != ilst.end(); ++ilter )
    {
        cout << *ilter << " " ;
    }
    cout <<endl;
    vector<int> ivec2(ivec);
    sort( ivec2.begin(), ivec2.end() ); // list cannot be used to sort for there is a iterator subtraction
    cout << "After sorting:" << endl;
    for ( iter = ivec2.begin(); iter != ivec2.end(); ++iter )
    {
        cout << *iter << " " ;
    }
    cout <<endl;
    iter = unique( ivec2.begin(), ivec2.end() );
    /*template <class ForwardIterator> ForwardIterator unique (ForwardIterator first, ForwardIterator last)
    //template <class ForwardIterator, class BinaryPredicate> ForwardIterator unique (ForwardIterator first, ForwardIterator last, BinaryPredicate pred);
    { // std::unique is equivalent to this:
        if (first==last)
            return last;
        ForwardIterator result = first;
        while (++first != last)
        {
            if (!(*result == *first)) // or: if (!pred(*result,*first)) for version (2)
                *(++result)=*first;
        }
        return ++result;
    }*/
    ivec2.erase( iter, ivec2.end() );
    //ivec2.resize( distance(ivec2.begin(),iter) ); // does the same thing as erase
    cout << "After eliminating duplicates:" << endl;
    for ( iter = ivec2.begin(); iter != ivec2.end(); ++iter )
    {
        cout << *iter << " " ;
    }
    cout <<endl << endl;
    // Part 3
    ilst.resize( ivec2.size() );
    copy( ivec2.begin(), ivec2.end(), ilst.begin() );
    list<int>::iterator it = ilst.begin();
    val = 0;
    while ( ( it = find_first_of(it,ilst.end(), ivec.begin(), ivec.end()) ) != ilst.end() )
    {
        ++ val;  ++it;
    }
    cout << "Found " << val << " same values both in ivec and ilst(or ivec2)." << endl;
    return 0;
}
