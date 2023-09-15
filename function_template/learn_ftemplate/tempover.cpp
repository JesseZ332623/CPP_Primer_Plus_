#include <iostream>
using namespace std;

struct debts
{
    char name[50];
    double amount;
};

template <typename Type>            /*模板 A*/
void show_array(Type arr[], int n);

template <typename Type>            /*模板 B*/
void show_array(Type *arr[], int n);

template <typename Type>            /*模板 A*/
void show_array(Type arr[], int n)
{
    cout << "template A \n";
    for (int i = 0; i < n; ++i)
    {
        cout << arr[i] << ' ';
    }
    cout.put('\n');
}

template <typename Type>            /*模板 B*/
void show_array(Type *arr[], int n)
{
    cout << "template B \n";
    for (int i = 0; i < n; ++i)
    {
        cout << *arr[i] << ' ';
    }
    cout.put('\n');
}

int main(int argc, char const *argv[])
{
    cout << argc << ' ' << argv[0] << endl;
    int things[6] = {13, 31, 103, 301, 310, 130};
    double *pd[3];
    debts mr_E[3] = 
    {
        {"Ima Wolfe", 2400.00},
        {"Ura Foxe", 1300.00},
        {"Iby Stout", 1800.00}
    };
    for (int i = 0; i < 3; ++i)
    {
        pd[i] = &mr_E[i].amount;
    }

    cout << "模板 A\n";
    show_array(things, 6);

    cout << "模板 B\n";
    show_array(pd, 3);
    
    return EXIT_SUCCESS;
}
