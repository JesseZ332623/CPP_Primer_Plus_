//#include "./thread.h"

#include <iostream>
#include <thread>
#include <string>
#include <mutex>
#include <fstream>
using namespace std;

class LogFile
{
    std::mutex _mu;
    std::mutex _mu2;
    ofstream f;

public:
    LogFile()
    {
        f.open("log.txt");
    }
    ~LogFile()
    {
        f.close();
    }
    void shared_print(string msg, int id)
    {
        std::lock(_mu, _mu2);
        std::lock_guard<std::mutex> guard(_mu, std::adopt_lock);
        std::lock_guard<std::mutex> guard2(_mu2, std::adopt_lock);
        f << msg << id << endl;
        cout << msg << id << endl;
    }
    void shared_print2(string msg, int id)
    {
        std::lock(_mu, _mu2);
        std::lock_guard<std::mutex> guard(_mu2, std::adopt_lock);
        std::lock_guard<std::mutex> guard2(_mu, std::adopt_lock);
        f << msg << id << endl;
        cout << msg << id << endl;
    }
};

void function_1(LogFile &log)
{
    for (int i = 0; i > -100; i--)
        log.shared_print2(string("From t1: "), i);
}

int main()
{
    LogFile log;
    std::thread t1(function_1, std::ref(log));

    for (int i = 0; i < 100; i++)
        log.shared_print(string("From main: "), i);

    t1.join();

    return EXIT_SUCCESS;
}
