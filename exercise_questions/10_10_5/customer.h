#ifndef _CUSTOMER_H_
#define _CUSTOMER_H_

#include <iostream>
#include <string>
#include <stack>
#include <vector>
#include <windows.system.h>

const int TOTAL_CUSTOMER = 3;

typedef struct _Customer_
{
    std::string full_name;
    double payment;

} Customer;

class Customer_t
{
    private:
        Customer client[TOTAL_CUSTOMER];
        std::stack<Customer> customer;
        double total_payment;

    public:
        /*默认构建函数 引导用户输入数据*/
        Customer_t(); 

        Customer_t(std::vector<std::string>::iterator full_name_iter, double *payment);

        void show_stack_data() const;      

        void customer_push();

        void customer_pop();

        const double get_payment_total() const { return total_payment; };

        ~Customer_t() {};
};

void set_digital(size_t digital);

#endif
