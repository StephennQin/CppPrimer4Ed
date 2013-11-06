// C++ Primer 4th Edition Chapter 10 Section 10.3.9
// A Word Transformation Map
#include <map>
#include <vector>
#include <iostream>
#include <fstream>
#include <string>
#include <stdexcept>
#include <sstream>

using std::map; using std::string; using std::vector;
using std::ifstream; using std::cout; using std::endl;
using std::getline; using std::make_pair;
using std::runtime_error; using std::istringstream;

ifstream& open_file(ifstream&, const string&);

int main(int argc, char **argv)
{
    // map to hold the word transformation pairs:
    // key is the word to look for in the input; value is word to use in the output
    map<string, string> trans_map;
    string key, value;

    if (argc != 3)
        throw runtime_error("wrong number of arguments");

    // open transformation file and check that open succeeded
    ifstream map_file;
    if (!open_file(map_file, argv[1]))
        throw runtime_error("no transformation file");
    // read the transformation map and build the map
    while (map_file >> key >> value)
        trans_map.insert(make_pair(key, value));
{
    // ok: let's display it
    map<string, string>::iterator map_it = trans_map.begin();

    //cout << "Here is our transformation map: \n\n";
    while (map_it != trans_map.end()) {
        cout << "key: "   << map_it->first;
        if (map_it->first.size() == 1)
            cout << "       ";
        if (map_it->first.size() == 3)
            cout << "     ";
        else if (map_it->first.size() == 4)
            cout << "    ";
        else if (map_it->first.size() == 5)
            cout << "   ";
        cout << "value: " << map_it->second << endl;
        ++map_it;
    }
    cout << "\n\n";

    {  // this block just produces the vector so that we can print it
       // for the book
    cout << "Here is our original string input:\n\n";
    // read some text to transform
    ifstream input;
    if (!open_file(input, argv[2]))
        throw runtime_error("no input file");
    string word;
    while (getline(input, word))
         cout << word << endl;
    cout << "\n\n\n";
    input.close(); input.clear();
    }
}

    // ok, now we're ready to do the transformations
    // open the input file and check that the open succeeded
    ifstream input;
    if (!open_file(input, argv[2]))
        throw runtime_error("no input file");

    string line;   // hold each line from the input

    // read the text to transform it a line at a time
    while (getline(input, line)) {
        istringstream stream(line);  // read the line a word at a time
        string word;
        bool firstword = true;  // controls whether a space is printed
        while (stream >> word) {
           // ok: the actual mapwork, this part is the heart of the program
           map<string, string>::const_iterator map_it =
                               trans_map.find(word);

           // if this word is in the transformation map
           if (map_it != trans_map.end())
               // replace it by the transformation value in the map
               word = map_it->second;
           if (firstword)
               firstword = false;
           else
               cout << " ";  // print space between words
           cout << word;
        }
        cout << endl;        // done with this line of input
    }
    return 0;
}

ifstream& open_file(ifstream &in, const string &file)
{
    in.close();     // close in case it was already open
    in.clear();     // clear any existing errors
    // if the open fails, the stream will be in an invalid state
    in.open(file.c_str()); // open the file we were given
    return in; // condition state is good if open succeeded
}
