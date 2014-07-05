// C++ Primer 4th Edition Chapter 14 Section 14.7
/*
 * smart pointer: Checks access to elements throws an out_of_range
 *                exception if attempt to access a nonexistent element
 * users allocate and free the array

*/
#include <cstddef>

class CheckedPtr {
    friend inline bool operator==( const CheckedPtr&, const CheckedPtr& );
    friend inline bool operator>( const CheckedPtr&, const CheckedPtr& );
    friend CheckedPtr operator+( const CheckedPtr&, const ptrdiff_t );
    friend ptrdiff_t operator-( const CheckedPtr&, const CheckedPtr& );
public:
    // no default constructor; CheckedPtrs must be bound to an object
    CheckedPtr(int *b, int *e): beg(b), end(e), curr(b) { }
    CheckedPtr( const CheckedPtr& orig ): beg(orig.beg), end(orig.end), curr(orig.curr) { }

    // dereference operator
    int& operator*();
    const int& operator*() const;

    // subscript operator
    int& operator[]( const size_t index  );
    const int& operator[]( const size_t index  ) const;

    // increment and decrement
    CheckedPtr operator++(int);     // postfix operators
    CheckedPtr operator--(int);

    CheckedPtr& operator++();       // prefix operators
    CheckedPtr& operator--();

    // other members as before
private:
    int* beg;    // pointer to beginning of the array
    int* end;    // one past the end of the array
    int* curr;   // current position within the array
};
