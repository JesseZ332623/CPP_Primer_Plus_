#include <iterator>
#include <iostream>

/**
*   @date 2023.10.10
    迭代器暂时没有掌握，以后再来
*/

template<typename Number>
class My_Data 
{
    private:
        Number *dat;
        const size_t MAX_SIZE = 15;
        const size_t DEFULT_SZIE = 5;
        size_t current_size;
    public:      
        class iterator : public std::iterator<std::forward_iterator_tag, Number>
        {
            private:
                Number *data;

            public:
                iterator(Number *ptr) : data(ptr) {}

                Number & operator*() { return *data; }
                iterator & operator++() 
                {
                    ++data; 
                    return *this;
                }
        };

        My_Data();
        My_Data(size_t size);

        void write_dat(Number *dat, size_t round);

        //typedef iterator::iterator Iter;

        Number *start_ptr = dat;
        Number *end_ptr = (dat + current_size);

        iterator begin() { return iterator(start_ptr); }
        iterator end() { return iterator(end_ptr); }

        ~My_Data();
};

template<typename Number>
My_Data<Number>::My_Data()
{
    current_size = DEFULT_SZIE;
    dat = new Number[DEFULT_SZIE];
}

template<typename Number>
My_Data<Number>::My_Data(size_t size)
{
    if (size > MAX_SIZE)
    {
        current_size = DEFULT_SZIE;
        dat = new Number[MAX_SIZE];
    }
    else
    {
        current_size = size;
        dat = new Number[size];
    }
}

template<typename Number>
My_Data<Number>::~My_Data()
{
    delete[] dat;
}

template<typename Number>
void My_Data<Number>::write_dat(Number *dat, size_t round)
{
    if (round > current_size)
    {
        return;
    }

    for (size_t index = 0; index < round; ++index)
    {
        this->dat[index] = dat[index];
    }
}

int main(int argc, char const *argv[])
{
    My_Data<int> my_dat(5);
    My_Data<int>::iterator iter = my_dat.begin();

    int out_dat[5] = {1, 2, 3, 4, 5};

    my_dat.write_dat(out_dat, 5);

    for (auto &index : out_dat)
    {
        std::cout << index << ' ';
    }
    
    return 0;
}
