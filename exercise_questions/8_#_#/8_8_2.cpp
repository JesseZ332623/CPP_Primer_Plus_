#include <iostream>
#include <string>

typedef struct Candy_Bar_Set
{
    std::string bar_name;
    float bar_weight;
    int calorie;
    
} Candy_Bar;

void set_bar_value(Candy_Bar &candy_bar, std::string bar_name = "Millennium Munch", float bar_weight = 2.85, int calorie = 350);

void show_bar_data(const Candy_Bar &candy_bar);


void set_bar_value(Candy_Bar &candy_bar, std::string bar_name, float bar_weight, int calorie)
{
    candy_bar.bar_name += bar_name;
    candy_bar.bar_weight = bar_weight;
    candy_bar.calorie = calorie;
}

void show_bar_data(const Candy_Bar &candy_bar)
{
    std::cout << "Candy Bar Name: " << candy_bar.bar_name << '\n';
    std::cout << "Bar Weight: " << candy_bar.bar_weight << '\t' << "Bar Calorie: " << candy_bar.calorie << '\n';
    std::cout.put('\n');
}

int main(int argc, char const *argv[])
{
    Candy_Bar candy_bar;

    set_bar_value(candy_bar, "Jesse", 12.767, 1000);
    show_bar_data(candy_bar);

    return EXIT_SUCCESS;
}
