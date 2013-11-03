#include <cstddef>
#include <iostream>
#include <string>
#include <bitset>

using namespace std;

int main()
{

    string str("1111111000000011001101");
    bitset<32> bitvec(str);
    cout<<bitvec<<endl;
    string mystring;
    bitvec.set();
    mystring=bitvec.to_string<char,char_traits<char>,allocator<char> >();
    cout << "mystring: " << mystring << endl;

    return 0;
}
