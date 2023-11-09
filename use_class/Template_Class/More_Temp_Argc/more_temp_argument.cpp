#include "./more_temp_argument.h"

int main(int argc, char const *argv[])
{
    using std::cout, std::endl, std::string;

    /*
        要声明一个模板类，就必须明确声明类型。

        如下所示：rantings 是一个拥有 4 个元素，且每一个元素都是 Pair<string, int> 类型的对象数组，
        声明的类型会在编译的时候替换到模板类之中，也就是说，这个类型的类长这样：

        template<typename string, typename int>
        class Pair
        {
            private:
                string a;
                int b;

            public:
            .......
        };

    */
    Pair<string, int> ratings[4] = 
    {
        Pair<string, int>("The Purpled Duck", 5),
        Pair<string, int>("Jaquie's Frisco Al Fresco", 4),
        Pair<string, int>("Cafe Souffle", 5),
        Pair<string, int>("Beriter Eats", 3)
    };

    /*求对象数组每一个元素的字节数，当前类型下是 40 Bytes*/
    size_t joins = sizeof(ratings) / sizeof(Pair<string, int>);

    /*循环变量 rating 中的数据*/
    cout << "Rating:\t Eatery\n";
    for (int index = 0; index < joins; ++index)
    {
        cout << ratings[index].second() << "\t ";
        cout << ratings[index].first() << endl;
    }

    cout << "---------------------------------------------------" << endl;

    /**
     * 这里有个语法点需要注意：
     * 
     *      ratings[3].first() = "Bertie's Fab Eats";
     *      ratings[3].second() = 6;
     * 
     * 这个语法看似有些怪异，其实很好理解，
     * first(), second() 函数有一个重载版本是返回 a 和 b 的引用，
     * 所以上面的两条语句会被转化成：
     * 
     *      a = "Bertie's Fab Eats";
     *      b = 6;
     * 
     * 即调用 operator=() 将一些数据赋值给 a 和 b。
    */
    cout << "Oops! Revised Rating: \n";
    ratings[3].first() = "Bertie's Fab Eats";
    ratings[3].second() = 6;

    cout << "---------------------------------------------------" << endl;

    /*修订（Revised）之后，重新遍历输出*/
    cout << "Rating:\t Eatery\n";
    for (int index = 0; index < joins; ++index)
    {
        cout << ratings[index].second() << "\t ";
        cout << ratings[index].first() << endl;
    }

    cout << "Done." << endl;

    return EXIT_SUCCESS;
}

