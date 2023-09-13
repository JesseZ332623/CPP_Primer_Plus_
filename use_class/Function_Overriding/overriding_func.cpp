#include "./classes_def.h"

Basic_Class::Basic_Class()
{
    basic_class_desc = "Empty String...";
    class_data.reserve(12);
    std::cout << "set vector default size: 12.\n";
}

Basic_Class::Basic_Class(std::string str, std::vector<double> data)
{
    basic_class_desc = str;
    class_data = data;
}

bool Basic_Class::copy_data(Basic_Class & tar, size_t copy_count) const
{
    if (copy_count < 0)
    {
        return false;
    }
    
    std::copy(class_data.begin(), class_data.begin() + copy_count, std::back_inserter(tar.class_data));
    
    return true;
}

void Basic_Class::show_data()
{
    using std::cout, std::endl;
    std::vector<double>::iterator iter = class_data.begin();

    cout << "class describe:" << basic_class_desc << endl;

    for (iter; iter < class_data.end(); ++iter)
    {
        cout << *iter << '\t';
    }

    cout.put('\n');
}