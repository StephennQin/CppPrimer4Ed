// C++ Primer 4th Edition Chapter 15 Exercises Section 15.4.4 Excercise 15.20
#include "Ch15_Item_base.h"

using namespace std;

void func_1(Item_base obj) {}
void func_2(Item_base& obj) {}
Item_base func_3(string str, double value)
{
    Item_base obj(str,value);
    return obj;
}

int main()
{
    Item_base iobj;
    func_1(iobj);
    func_2(iobj);
    iobj = func_3("9-787121-174414",108.0);
    Item_base* p = new Item_base;
    delete p;

    Bulk_item bobj;
    func_1(bobj);
    func_2(bobj);
    Bulk_item* q = new Bulk_item;
    delete q;

    return 0;
}
