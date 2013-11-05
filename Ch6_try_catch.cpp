// C++ Primer 4th Edition Chapter 6 Section 6.13
#include<iostream>
#include<string>
#include<stdexcept>
//#include<cstdlib>

using namespace std;

double func( double x, double y );

int main()
{
    double x = 0;  // numerator
    double y = 1;  // denominator
    double res = 0;  // results
    cout << "Please enter 2 values:"<<endl;
    while ( cin >> x >> y )
    {
        try
        {
            res = func( x, y );
            cout << "The result of " << x <<'\/' << y << " is: " << res << endl;
        }
        catch ( runtime_error err )
        {
            cerr << err.what() << "Try again?  Enter y or n" << endl;
            char c;
            cin >> c;
            if ( cin && c == 'n' )
                break;  // exit(1);
        }
    }
    return 0;
}

double func( double x, double y )
{
    if ( y == 0 )
    {
        throw runtime_error("The denominator cannot be ZERO!\n");
    }
    return (x/y);
}
