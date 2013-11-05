#include <vector>
#include <algorithm>
#include <iostream>

bool greater10(int value)
{
    return value >10;
}

int main()
{
    using namespace std;
    vector<int> v1;
    vector<int>::iterator Iter;

    v1.push_back(10);
    v1.push_back(20);
    v1.push_back(10);
    v1.push_back(40);
    v1.push_back(10);
    cout << "The first element:"<<v1.front()<<endl;
    cout << "The last element:"<<v1.back()<<endl;

    vector<int>::const_iterator Itera = v1.begin();
    ++Itera;++Itera;++Itera;++Itera;--Itera;
    cout<< *Itera <<endl;

    vector<int>::iterator::difference_type result1;
    result1 = count_if(v1.begin(), v1.end(), greater10);
    cout << "The number of elements in v1 greater than 10 is: "
         << result1 << "." << endl;
    v1.clear();

    return 0;
}
