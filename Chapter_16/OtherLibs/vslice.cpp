#include <iostream>
#include <valarray>
#include <cstdlib>
#include <ctime>

#include <MyLib/myDelay.h>
#include <MyLib/myLogerDef.h>

/**
 * 在 <valarray> 头文件中，有一个用作数组索引以辅助 valarray 容器的类 std::slice
 * 他不表示一个值而是一组值，初始化该类对象需要 3  个参数，分别是：
 * 
 * 				std::slice(起始索引，索引数，跨距)
 * 
 * 假设 std::valarray<int> numberList = {一共 10 个元素}
 * 
 * 那么语句 
 * 
 * 				numberList[std::slice(1, 3, 3)] = 10; 
 * 
 * 就会把 numberList 容器下标为 1，4，7 所对应的值全部设成 10。
 * 
 * 有了这个类，甚至可以使用一个一维的 std::valarray<type> 类表示一个二维数组
*/

const int DEFAULT_SIZE = 16;
using intValArray = std::valarray<int>;
using MyLib::MyDelay::delay;
using namespace MyLib::MyLoger;

/**
 * @brief 往 `std::valarray<int>` 容器内随机写入数据
 * 
 * @param __vint `std::valarray<int>` 类容器
 * @param __size 容器长度（默认为 12）
 * 
 * @return  non-return
*/
void getRandomValue(intValArray & __vint, int __size = DEFAULT_SIZE);

/**
 * @brief 按指定列数的形式输出 `std::valarray<int>` 容器内部数据
 * 
 * @param __vint `std::valarray<int>` 类容器
 * @param __cols 列数
 * 
 * @return  non-return
*/
void display(intValArray & __vint, std::size_t __cols);

int main(int argc, char const *argv[])
{    
	using std::cout, std::slice;
	std::srand(std::time(nullptr));

	std::system("cls");

	intValArray valInt(DEFAULT_SIZE);
	getRandomValue(valInt, DEFAULT_SIZE);

	/*将 valInt 容器中下标为 1，5，9，13（即第二列的数据）拷贝给 secondValue 容器*/
	intValArray secondValue(valInt[std::slice(1, 4, 4)]);

	/*将 valInt 容器中下标为 3，4，5（即第二行的数据）拷贝给 secondRow 容器*/
	intValArray secondRow(valInt[std::slice(4, 4, 1)]);

	loger(std::cout, NOTIFY, "Original valInt: \n");
	display(valInt, 4);

	loger(std::cout, NOTIFY, "Second Column of valInt: \n");
	display(secondValue, 1);

	loger(std::cout, NOTIFY, "Second Row of valInt: \n");
	display(secondRow, 4);

	valInt[std::slice(2, 4, 4)] = -1;

	loger(std::cout, NOTIFY, "Modifty Third Column to -1: \n");
	display(valInt, 4);

	loger(std::cout, CORRECT, "Done.");

    return EXIT_SUCCESS;
}

void getRandomValue(intValArray & __vint, int __size)
{
	for (int index = 0; index < __size; ++index)
	{
		__vint[index] = std::rand() % 10;
	}
}
void display(intValArray & __vint, std::size_t __cols)
{
	using std::cout, std::endl;

	std::size_t limit = __vint.size();
	
	for (std::size_t index = 0; index < limit; ++index)
	{
		cout.width(3);
		cout << __vint[index];

		if (index % __cols == __cols - 1) { cout << endl; }
		else { cout << ' '; }

		delay(40);
	}

	if (limit % __cols != 0) { cout << endl; }	
}