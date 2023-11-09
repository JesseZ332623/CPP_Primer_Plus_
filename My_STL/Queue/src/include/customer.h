/**
 * customer.h
 * @author Jesse_EC
 * @date 2023.9.23
*/

/*
    设计一个 Customer 类，这个类非常简单，只需要操作两个数据：
    1）客户何时到达 ATM 机前        long int arrive;  
    2）客户在 ATM 机前花了多少时间（1 ~ 3 的随机数）  int process_time;
*/

#ifndef _CUSTOMER_H_
#define _CUSTOMER_H_

class Customer
{
    private:
        long int arrive;        /*客户何时到达 ATM 机前*/
        int process_time;       /*客户在 ATM 机前花了多少时间（1 ~ 3 的随机数）*/
    
    public:
        Customer() { arrive = process_time = 0; }

        void set(long int when);    /*设置 arrive 的值*/

        long int when() const { return arrive; }
        int p_time() const { return process_time; }

        ~Customer() {}
};

#endif