#include "./classes_def.h"

Basic_Class::Basic_Class()
{
    basic_class_desc = "Basic Class Empty String...";
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

    for (iter; iter != class_data.end(); ++iter)
    {
        cout << *iter << '\t';
    }

    cout.put('\n');
}

Derive_Class::Derive_Class()
{
    std::cout << "set list defult size: 12.\n";
    list_data = new std::list<int>(12, 0);
}

Derive_Class::Derive_Class(std::list<int> & dat)
{
    list_data = new std::list<int>;
    *list_data = dat;
}

bool Derive_Class::copy_data(Derive_Class & tar) const
{
    if (tar.list_data == nullptr)
    {
        return false;
    }
    
    tar.list_data->assign(list_data->begin(), list_data->end());
    
    return true;
}

void Derive_Class::show_data()
{
    std::list<int>::iterator l_iter = list_data->begin();

    std::cout << "List contence: \n";
    for (l_iter; l_iter != list_data->end(); ++l_iter)
    {
        std::cout << *l_iter << '\t';
    }
    std::cout.put('\n');
}

Derive_Class::~Derive_Class()
{
    delete list_data;
}