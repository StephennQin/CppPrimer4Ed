#ifndef CH15_ITEM_BASE_H
#define CH15_ITEM_BASE_H

#include <iostream>
#include <string>

class Item_base
{
    public:
        Item_base( const std::string &book = "",
                   double sales_price = 0.0) :
                   isbn(book), price(sales_price)
        {
            std::cout << "Item_base() -- constructor" << std::endl;
        };
        virtual ~Item_base();
        Item_base( const Item_base& );
        Item_base& operator=( const Item_base& );
        std::string book() const
        {
            return isbn;
        }
        virtual double net_price( std::size_t n ) const
        {
            return price * n;
        }
    protected:
        double price;
    private:
        std::string isbn;
};

class Bulk_item : public Item_base
{
    public:
        Bulk_item( const std::string& book = "",
                              double sales_price = 0.0,
                              std::size_t qty = 0,
                              double disc_rate = 0.0) :
                                  Item_base(book, sales_price),
                                  quantity(qty), discount(disc_rate)
        {
            //ctor
            std::cout << "Bulk_item() -- constructor" << std::endl;
        }
        virtual ~Bulk_item();
        Bulk_item( const Bulk_item& );
        Bulk_item& operator=( const Bulk_item& );
        double net_price( std::size_t ) const;
    protected:
    private:
        std::size_t quantity;
        double discount;
};
#endif // CH15_ITEM_BASE_H
