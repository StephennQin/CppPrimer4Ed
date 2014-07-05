// C++ Primer 4th Edition Chapter 14 Section 14.7
#include "Ch14_CheckedPtr.h"
#include <iostream>
using std::cerr;
#include <stdexcept>
using std::out_of_range;
using std::logic_error;

// dereference operator
int& CheckedPtr::operator*()
{
    if (curr == end)
        throw out_of_range("dereference past the end");
    return *curr;
}

const int& CheckedPtr::operator*() const
{
    if (curr == end)
        throw out_of_range("dereference past the end");
     return *curr;
}

// subscript operator
int& CheckedPtr::operator[]( const size_t index )
{
    if( (index+beg)<beg || (index+beg)>=end ){
        throw out_of_range("subscript wrong range");
    }
    return *(beg+index);
}

const int& CheckedPtr::operator[]( const size_t index ) const
{
    if( (index+beg)<beg || (index+beg)>=end ){
        throw out_of_range("subscript wrong range");
    }
    return *(beg+index);
}

// postfix: increment/decrement object but return unchanged value
CheckedPtr CheckedPtr::operator++(int)
{
    // no check needed here, the call to prefix increment will do the check
    CheckedPtr ret(*this);   // save current value
    ++*this;                 // advance one element, checking the increment
    return ret;              // return saved state
}

CheckedPtr CheckedPtr::operator--(int)
{
    // no check needed here, the call to prefix decrement will do the check
    CheckedPtr ret(*this);  // save current value
    --*this;                // move backward one element and check
    return ret;             // return saved state
}

// prefix: return reference to incremented/decremented object
CheckedPtr& CheckedPtr::operator++()
{
    if (curr == end)
        throw out_of_range
              ("increment past the end of CheckedPtr");

    ++curr;                // advance current state
    return *this;
}

CheckedPtr& CheckedPtr::operator--()
{
    if (curr == beg)
        throw out_of_range
          ("decrement past the beginning of CheckedPtr");

    --curr;              // move current state back one element
    return *this;
}

//
inline bool operator==( const CheckedPtr& lhs, const CheckedPtr& rhs )
{
    return lhs.beg==rhs.beg && lhs.end==rhs.end && lhs.curr==rhs.curr;
}

inline bool operator!=( const CheckedPtr& lhs, const CheckedPtr& rhs )
{
    return !( lhs==rhs );
}

inline bool operator>( const CheckedPtr& lhs, const CheckedPtr& rhs )
{
    return lhs.beg==rhs.beg && lhs.end==rhs.end && lhs.curr>rhs.curr;
}

inline bool operator<( const CheckedPtr& lhs, const CheckedPtr& rhs )
{
    return rhs>lhs;
}
inline bool operator>=( const CheckedPtr& lhs, const CheckedPtr& rhs )
{
    return !( lhs<rhs );
}
inline bool operator<=( const CheckedPtr& lhs, const CheckedPtr& rhs )
{
    return !( lhs>rhs );
}

//
CheckedPtr operator+( const CheckedPtr& lhs, const ptrdiff_t index )
{
    if( lhs.curr+index >= lhs.end || lhs.curr+index < lhs.beg ){
        throw out_of_range("pointer out of range!");
    }
    CheckedPtr ret(lhs);
    ret.curr += index;
    return ret;
}

CheckedPtr operator-( const CheckedPtr& lhs, const ptrdiff_t index )
{
    return lhs+(-index);
}

ptrdiff_t operator-( const CheckedPtr& lhs, const CheckedPtr& rhs )
{
    if( lhs.beg!=rhs.beg || lhs.end!= rhs.end ){
        throw logic_error("Different pointers!");
    }
    return lhs.curr - rhs.curr;
}
