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
    FamilyMap children;
    string surname, childName;
	do{
		cout << "Enter surname (Ctrl+Z to exit):" << endl;
		cin >> surname;
		if ( !cin )
			break;
		vector<string> chd;
		pair<FamilyMap::iterator, bool> ret = children.insert(make_pair(surname,chd));
		if ( !ret.second ) {
			cout << "repeated surname:" << surname <<endl;
			continue;
		}
		cout << "Enter children's name: (Ctrl+Z to exit):" << endl;
		while( cin >> childName )
			ret.first->second.pushback( childName );
		cin.clear();
	} while ( cin );
	cin.clear();
	cout << "Enter a surname to search:" << endl;
	cin >> surname;
	FamilyMap::iterator ret = children.find( surname );
	if ( ret == children.end() )
		cout << "No matched surname " << surname << " found"  << endl;
	else {
		cout << "Children have this " << surname << " surname are:"  << endl;
		for( vector<sting>::iterator iter = ret->second.begin();
			iter != ret->second.end(); iter++ )
			cout << *iter++ << endl;
	}
	return 0;
}
