#include <iostream>
#include <cstring>

class Frabjous
{
    private:
        char fab[20];

    public:
        Frabjous(const char *_s = "C++") 
        {
            std::strcpy(fab, _s);
        }
        virtual void tell() { std::cout << fab << '\n'; }

        ~Frabjous() {};
};

class Golam
{
    private:
        int glip;
        Frabjous fb;

    public:
        Golam(int g = 0, const char *_s = "C++") : glip(g)
        {
            fb = Frabjous(_s);
        }
        Golam(int g, const Frabjous & _f) : glip(g), fb(_f) {}

        void tell() 
        { 
            std::cout << glip << '\n'; 
            fb.tell();
        }
};

int main(int argc, char const *argv[])
{
    Golam _golam(10, "Fuck You!");

    _golam.tell();
    return 0;
}
