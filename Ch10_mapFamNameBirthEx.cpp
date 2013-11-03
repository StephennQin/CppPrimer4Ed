// C++ Primer 4th Edition Chapter 10 Exercises Section 10.3.9 Excercise 10.19
#include<iostream>
#include<utility>
#include <map>
#include<vector>
#include<string>

using namespace std;
typedef vector< pair<string,string> > PersonMap;
typedef map< string, PersonMap > FamilyMap;

int main()
{
    FamilyMap children;
    string surname, childName, birthDay;
	do{
		cout << "Enter surname (Ctrl+Z to exit):" << endl;
		cin >> surname;
		if ( !cin )
			break;
		PersonMap chd;
		pair<FamilyMap::iterator, bool> ret = children.insert(make_pair(surname,chd));
		if ( !ret.second ) {
			cout << "repeated surname:" << surname <<endl;
			continue;
		}
		cout << "Enter children's name: (Ctrl+Z to exit):" << endl;
		while( cin >> childName >> birthDay )
			ret.first->second.pushback( make_pair(childName, birthDay) );
		cin.clear();
	} while ( cin );
	cin.clear();
	// Search a surname
	cout << "Enter a surname to search:" << endl;
	cin >> surname;
	FamilyMap::iterator ret = children.find( surname );
	if ( ret == children.end() )
		cout << "No matched surname " << surname << " found"  << endl;
	else {
		cout << "Children have this " << surname << " surname are:"  << endl;
		for( vector<sting>::iterator iter = ret->second.begin();
			iter != ret->second.end(); iter++ )
			cout << "Name: "<< iter->first <<"\t\tBithday:" << iter->second << endl;
	}
	return 0;
}
