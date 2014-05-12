// C++ Primer 4th Edition Chapter 13 Section 13.5
#ifndef CH13_HASPTR
#define CH13_HASPTR

#include <iostream>

// Section 13.5.1 & Exercise Section 13.5.1 Exercise 13.24
class U_Ptr {
    // default: private member
    friend class HasPtr_UC;
    int *ip;
    size_t use;

    U_Ptr( int *p ): ip(p), use(1) {}
    ~U_Ptr() { delete ip;}
};

/*
 * smart pointer class: takes ownership of the dynamically allocated
 *          object to which it is bound
 * User code must dynamically allocate an object to initialize a HasPtr
 * and must not delete that object; the HasPtr class will delete it
 */
class HasPtr_UC {
public:
    // HasPtr owns the pointer; p must have been dynamically allocated
    HasPtr_UC ( int *p, int i ): ptr(new U_Ptr(p)), val(i) {}
    // copy members and increment the use count
    HasPtr_UC ( const HasPtr_UC &orig ):
        ptr(orig.ptr), val(orig.val) { ++ptr->use; }
    HasPtr_UC& operator= ( const HasPtr_UC& );
    // if use count goes to zero, delete the U_Ptr object
    ~HasPtr_UC() { if (--ptr->use == 0 ) delete ptr; }

    //accessors must change to fetch value from U_Ptr object
    int *get_ptr() const { return ptr->ip; }
    int get_int() const { return val; }
    // change the appropriate data member
    void set_ptr( int *p ) { ptr->ip = p; }
    void set_int( int i ) { val = i; }
    // return or change the value pointed to, so ok for const objects Note: *ptr->ip is equivalant to *(ptr->ip)
    int get_ptr_val() const { return *ptr->ip; }
    void set_ptr_val( int i ) { *ptr->ip = i; }
private:
    U_Ptr *ptr;
    int val;
};

// Section 13.5.2 & Exercise Section 13.5.2 Exercise 13.26
HasPtr_UC& HasPtr_UC::operator= ( const HasPtr_UC &rhs )
{
    ++rhs.ptr->use;
    if( --ptr->use == 0 )
        delete ptr;
    ptr = rhs.ptr;
    val = rhs.val;
    return *this;
}

/*
 * Valuelike behavior even though HasPtr has a pointer member:
 * Each time we copy a HasPtr object, we make a new copy of the
 * underlying int object to which ptr points.
 */
class HasPtr_VL {
public:
    // no point to passing a pointer if we're going to copy it anyway
    // store pointer to a copy of the object we're given
    HasPtr_VL( const int &p, int i ): ptr(new int(p)), val(i) {}
    // copy members and increment the use count
    HasPtr_VL( const HasPtr_VL &orig ):
        ptr(new int (*orig.ptr)), val(orig.val) {}
    HasPtr_VL& operator=( const HasPtr_VL& );
    ~HasPtr_VL() { delete ptr; }

    //accessors must change to fetch value from Ptr object
    int *get_ptr() const { return ptr; }
    int get_int() const { return val; }
    // change the appropriate data member
    void set_ptr( int *p ) { ptr = p; }
    void set_int( int i ) { val = i; }
    // return or change the value pointed to, so ok for const objects
    int get_ptr_val() const { return *ptr; }
    void set_ptr_val( int i ) { *ptr = i; }
private:
    int *ptr;   // points to an int
    int val;
};

HasPtr_VL& HasPtr_VL::operator=( const HasPtr_VL &rhs )
{
    // Note: Every HasPtr is guaranteed to point at an actual int;
    //       We know thar ptr cannot be a zero pointer
    *ptr = *rhs.ptr; //copy the value pointed to
    val = rhs.val;   //copy the int
    return *this;
}

#endif // CH13_HASPTR
