#include "customer.h"

int main(int argc, char const *argv[])
{
    std::vector<std::string> full_name_set = 
    {
        "Jesse", "Rose", "Jack"
    };

    double payment_set[TOTAL_CUSTOMER] = {10.00, 10.00, 10.00}; 

    Customer_t customer_t(full_name_set.begin(), payment_set);

    customer_t.customer_push();
    customer_t.customer_pop();
    
    set_digital(2);
    std::cout.precision(2);
    std:: cout << "Customer count: ("
               << TOTAL_CUSTOMER
               << ") Total Payment: $"
               << customer_t.get_payment_total()
               << std::endl;
    
    return EXIT_SUCCESS;
}
