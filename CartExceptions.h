#ifndef CARTEXCEPTIONS_H
#define CARTEXCEPTIONS_H
#include <stdexcept>

class EmptyCart_exception :public std::runtime_error
{
public:
    EmptyCart_exception ():std::runtime_error("Empty Cart!"){};
};

class NoAvailableQuantity:public std::runtime_error
{
public:
    NoAvailableQuantity():std::runtime_error("No Available Quantity"){};
};
#endif // CARTEXCEPTIONS_H
