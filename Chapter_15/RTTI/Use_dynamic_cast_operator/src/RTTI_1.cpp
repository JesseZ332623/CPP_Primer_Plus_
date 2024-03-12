#include "./include/RTTI_1.h"

Grand * getOne()
{
    Grand * ptr = nullptr;

    switch (std::rand() % 3)
    {
        case 0:
            ptr = new Grand(std::rand() % 100);
            break;

        case 1:
            ptr = new Superb(std::rand() % 100);
            break;

        case 2:
            ptr = new Magnificent(std::rand() % 100, 'A' + std::rand() % 26);
            break;

        default:
            break;
    }

    return ptr;
}

int main(int argc, char const *argv[])
{
    std::srand(time(nullptr));

    Grand * pg;
    Superb * ps;

    for (int index = 0; index < 5; ++index)
    {
        /*
            从 getOne() 函数中随机获得 Grand Superb 或 Magnificent 类对象
        */
        pg = getOne();      

        // 输出这个对象的类型
        pg->Speak();

        /*
            试图将 Grand Superb 或 Magnificent 类对象 转换为（Superb *）类型

            若指向的对象（Type *）的类型为 Type 或者是从 Type 直接或间接派生下来的类型，
            则下面的表达式将指针 pt 转为 Type 类型的指针。

            若不满足上述条件，比如将两个毫不相干的类型进行转换，
            或者出现 父 -> 子 / 孙 的情况，dynamic_cast 运算符就会返回 nullptr，
            输出转换失败的信息。
        */
        if ((ps = dynamic_cast<Superb *>(pg)))
        {
            ps->Say();
        }
        else
        {
            fprintf(stdout, "Failed Conversion.....\n");
        }

        delete pg;
    }

    ps = nullptr;
    pg = nullptr;

    return EXIT_SUCCESS;
}
