#include "./include/customer.h"
#include <cstdlib>

void Customer::set(long int when)
{
    process_time = std::rand() % 3 + 1;
    arrive = when;
}