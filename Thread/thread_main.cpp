#include "./thread.h"

std::mutex mtx;

int global_value = 100;

void thread_01(int _val)
{
    mtx.lock();

    global_value += _val;

    mtx.unlock();
}

void thread_02(int _val)
{
    mtx.lock();

    global_value += _val;

    mtx.unlock();
}

void thread_03(int _val)
{
    mtx.lock();

    global_value += _val;   

    mtx.unlock();
}

int main(int argc, char const *argv[])
{
    
    std::cout << global_value << '\n';

    thread_01(10);
    std::cout << global_value << '\n';

    thread_01(20);
    std::cout << global_value << '\n';

    thread_01(30);
    std::cout << global_value << '\n';

    return EXIT_SUCCESS;
}
