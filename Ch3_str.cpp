#include <iostream>
#include <vector>

using namespace std;
int main()
{
    // empty vector
    vector<int> ivec;
    int val;
    // give each element a new value
    for (vector<int>::size_type ix = 0;
                                ix != 10; ++ix)
          ivec.push_back(ix);

    cout << "ivec.size: " << ivec.size() << endl;  // prints 10

    // reset the elements in the vector to zero
    for (vector<int>::size_type ix = 0; ix != ivec.size(); ++ix)
        ivec[ix] = 0;

    // is there anything to print?
    if (ivec.empty() == false) {
        cout << "vector contents: " << endl;
        // print each element separated by a newline
        for (vector<int>::size_type ix = 0;
                          ix != ivec.size(); ++ix)
            cout << ivec[ix] << endl;
     }
     return 0;
}
