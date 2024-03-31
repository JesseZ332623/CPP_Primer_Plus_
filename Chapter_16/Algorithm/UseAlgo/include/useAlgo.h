#ifndef _USE_ALGO_H_
#define _USE_ALGO_H_

#include <MyLib/myLib.h>

#include <iterator>
#include <vector>
#include <map>
#include <set>
#include <cctype>

/**
 * 编写一程序，让用户输入单词。希望最后得到：
 * 
 * - 一个按输入顺序排列的单词列表               使用 std::vector<std::string>
 * - 一个按字母顺序排列的单词列表 (忽略大小写)   使用 std::set<std::string>
 * - 记录每个单词输入次数的列表                 使用 std::map<std::string, int>
*/

/**
 * @brief 用于判断用户输入的字符串是否为单词。
 * 
 * @brief - 对单词的定义：由英文字母组成的，两边无空格或其他非字母字符的一串字符。
 * 
 * @param __string 字符串只读引用
 * 
 * @return 一个 bool 类型，表明是否为单词
*/
bool isWord(const std::string & __string);

/**
 * @brief 将一个单词字符串转化成小写，作为 std::transform() 算法的操作。
 * 
 * @param __string 字符串引用
 * 
 * @return 字符串引用（std::transform 算法要求的）
*/
std::string & getLowerString(std::string & __string);

/**
 * @brief 用户输入单词，然后存入一个 vector 中，就能得到一个按输入顺序排列的单词列表。
 * 
 * @param __wordsArray 按输入顺序排列的单词列表的引用
 * 
 * @return non-return
*/
void wordsUserInput(std::vector<std::string> & __wordsArray);

/**
 * @brief 将 __wordsArray 中的数据按字母表顺序插入集合中，忽略大小写。
 * 
 * @param __wordsArray  按输入顺序排列的单词列表的只读引用
 * @param __wordsSet    一个按字母顺序排列的单词集合的引用 (忽略大小写)
 * 
 * @return non-return
*/
void getAlphabeticalOrderSet(const std::vector<std::string> & __wordsArray, std::set<std::string> & __wordsSet);

/**
 * @brief 获取用户输入单词的出现次数（活用 STL 容器）
 * @brief - 可以使用 map，以 __wordsSet 内的元素为键使用 count() 算法在 __wordsArray 内计算出现的次数，
 * @brief - 最后把结果存入 __wordsMap 之中
 * 
 * @param __wordsArray  按输入顺序排列的单词列表的只读引用
 * @param __wordsSet    一个按字母顺序排列的单词集合的只读引用 (忽略大小写)
 * @param __wordsMap    存储用户输入单词出现次数的映射表引用  
 * 
 * @return non-return
*/  
void getAppearTimesOfEveryWords(const std::vector<std::string> & __wordsArray, const std::set<std::string> & __wordsSet, 
                                std::map<std::string, int> & __wordsMap);

/**
 * @brief 重载 << 运算符，让他可以输出 std::map<std::string, int> 内的每一个键值对。
 * 
 * @param __os      标准输出流的引用
 * @param __pair    std::map<std::string, int> 内的每一个键值对的只读引用
 * 
 * @return 标准输出流的引用（用于链式调用）
*/
std::ostream & operator<<(std::ostream & __os, const std::pair<std::string, int> & __pair);

#endif // Z_USE_ALGO_H_
