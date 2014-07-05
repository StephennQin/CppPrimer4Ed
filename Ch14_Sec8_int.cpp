// C++ Primer 4th Edition Chapter 14 Exercises Section 14.8.1 Excercise 14.33 & 14.34
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <ctime>

using namespace std;

class GT
{
public:
    GT ( int val = 0 ): bound(val) {}
    bool operator() ( const int &val ) { return val > bound; }
private:
    int bound;
};

class EQ
{
public:
    EQ ( int val = 0 ): bound(val) {}
    bool operator() ( const int &val ) { return val == bound; }
private:
    int bound;
};

int main()
{
    int val(0),newVal(0);
    vector<int> ivec;

    srand( time(NULL) );
    for( int i = 0; i != 10; i++) {
        val = rand() %20 + 1;
        ivec.push_back( val );
        cout << val<< "\t";
    }
    cout << endl;

    //
    cout << "The threshold value you want to use:" << endl;
    cin >> val;
    vector<int>::iterator iter = find_if( ivec.begin(), ivec.end(), GT(val) );
    if( iter != ivec.end() ) {
        cout << "The first element greater than " << val << " is: " << *iter << endl;
    }
    else {
        cout << "No element is greater than " << val << endl;
    }
    cin.clear();

    //
    cout << "The specific value you want to replace, and the new value:" << endl;
    cin >> val >> newVal;
    replace_if( ivec.begin(), ivec.end(), EQ(val), newVal );
    for( iter = ivec.begin(); iter != ivec.end(); iter++ ) {
        cout << *iter << "\t";
    }
    cout << endl;

    return 0;
}
