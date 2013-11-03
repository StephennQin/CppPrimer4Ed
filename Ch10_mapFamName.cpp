// C++ Primer 4th Edition Chapter 10 Exercises Section 10.3.9 Excercise 10.18
#include<iostream>
#include<utility>
#include <map>
#include<vector>
#include<string>

using namespace std;

typedef map< string, vector<string> > FamilyMap;

int main()
{
    FamilyMap Families;
    string surname, childName;
    cout << "Enter FULL names (childName surname) of each person. i.e. Jake Jiang" << endl;
    while( cin >> childName >> surname )
    {
        vector<string> chd;
        pair<FamilyMap::iterator, bool> ret = Families.insert( make_pair(surname,chd) );
        if( ! ret )
        {

        }
    }
}
