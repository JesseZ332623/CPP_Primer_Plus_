#include "./classes_def.h"

int main(int argc, char const *argv[])
{
    using std::cout, std::endl, std::list, std::vector;

    list<int> ls = {12, 67, 98};

  
    Derive_Class *derive_set = new Derive_Class[2]
    {
        Derive_Class(),
        Derive_Class(ls)
    };

    derive_set[0].show_data();
    derive_set[1].show_data();

    derive_set[1].copy_data(derive_set[0]);
    
    derive_set[0].show_data();
    derive_set[1].show_data();

    delete[] derive_set;
    
    return EXIT_SUCCESS;
}
