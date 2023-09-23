#include "./thread.h"

std::mutex mtx;

int global_value = 0;

void thread_01()
{
    for (int i = 0; i < 10000000; i++)
    {
        mtx.lock();
        ++global_value;
        mtx.unlock();
    }
}

int main(int argc, char const *argv[])
{
#if true
    
    std::thread th_1(thread_01);
    std::thread th_2(thread_01);
    std::thread th_3(thread_01);

    th_1.join();
    //std::cout << global_value << '\n';

    th_2.join();

    th_3.join();

    std::cout << global_value << '\n';

#endif

    return EXIT_SUCCESS;
}