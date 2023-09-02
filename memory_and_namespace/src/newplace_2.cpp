#include "./head_file/defs.h"

namespace Jack
{
    void show_spacename()
    {
        std:: cout << id << ' ' << intro << '\n';
    }
}

namespace Jill
{
    void show_spacename()
    {
        std:: cout << id << ' ' << intro << '\n';
    }

    void puts_s(const char *_str_)
    {
        size_t str_len = strlen(_str_);

        for (size_t str_index = 0; str_index < str_len; ++str_index)
        {
            putc(*(_str_++), stdout);
        }
        putchar('\n');
    }
}

int main(int argc, char const *argv[])
{
    using namespace Jack;

    show_spacename();
    Jill::show_spacename();
    Jill::puts_s("aaaaaa");

    return 0;
}
