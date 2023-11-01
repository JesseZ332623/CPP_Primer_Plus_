#include "./specialization.h"
#include <vector>

int main(int argc, char const *argv[])
{
    using std::cout, std::endl;
    Normal_Data n_data_1(3.1415926);
    Normal_Data n_data_2(2.00);

    Normal_Data<std::string> s_data_1("This is a specialization class.");
    Normal_Data<std::string> s_data_2("This is a specialization class.");

    cout << n_data_1.Get_Data() << endl;
    cout << s_data_1;
    cout << (n_data_1 + n_data_2) << endl;
    (s_data_1 == s_data_2) ? cout << "true" : cout << "false";
    
    return EXIT_SUCCESS;
}
