#include <iostream>
#include <string>
using namespace std;
int main()
{
    const int bufSize(521);
    const string s("This is a constant string type value\0");
    cout << bufSize <<endl;
    cout << s <<endl;
    return 0;
}
