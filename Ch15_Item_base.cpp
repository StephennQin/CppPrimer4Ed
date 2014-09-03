#include "Ch15_Item_base.h"

Item_base::~Item_base()
{
    //dtor
    std::cout << "~Item_base() -- destructor" << std::endl;
}

Item_base::Item_base( const Item_base& other ) : isbn(other.isbn), price(other.price)
{
    //copy ctor
    std::cout << "Item_base(const Item_base&) -- copy constructor" << std::endl;
}

Item_base& Item_base::operator=(const Item_base& rhs)
{
    if (this == &rhs) return *this; // handle self assignment
    //assignment operator
    isbn = rhs.isbn;
    price = rhs.price;
    std::cout << "Item_base::operator=() -- assignment operator" << std::endl;
    return *this;
}

///////////////////////////////////////////////////////////////////////////////////

Bulk_item::~Bulk_item()
{
    //dtor
    std::cout << "~Bulk_item() -- destructor" << std::endl;
}

Bulk_item::Bulk_item(const Bulk_item& other) :
                        Item_base(other), quantity(other.quantity), discount(other.discount)
{
    //copy ctor
    std::cout << "Bulk_item(const Bulk_item&) -- copy constructor" << std::endl;
}

Bulk_item& Bulk_item::operator=(const Bulk_item& rhs)
{
    if (this == &rhs) return *this; // handle self assignment
    //assignment operator
    Item_base::operator=(rhs);
    quantity = rhs.quantity;
    discount = rhs.discount;
    std::cout << "Bulk_item::operator=() -- assignment operator" << std::endl;
    return *this;
}

double Bulk_item::net_price( std::size_t cnt) const
{
    if ( cnt >= quantity )
        return cnt * ( 1 - discount ) * price;
    else
        return cnt * price;
}
