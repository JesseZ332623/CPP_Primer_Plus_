#ifndef _CORPORATION_H_
#define _CORPORATION_H_

#include <iostream>

using std::cout;

class Corporation
{
    private:
        int head_value;
    public:
        Corporation(int h_val) { head_value = h_val; }

        virtual const int head() {
            
            cout << "Corporation data" << std::endl;
            return head_value; 
        }

        ~Corporation() {}
};

class Public_Corporation : public Corporation
{
    private:
        int p_head_value;

    public:
        Public_Corporation(int p_head_val) : Corporation(p_head_value) 
        { p_head_value = p_head_val; }

        virtual const int head()  {
                cout << "Public_Corporation data" << std::endl;
             return p_head_value; 
        }

        ~Public_Corporation() {}
};

#endif