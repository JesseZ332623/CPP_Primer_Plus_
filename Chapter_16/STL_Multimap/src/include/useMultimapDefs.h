#ifndef _USE_MULTIMAPDEFS_H_
#define _USE_MULTIMAPDEFS_H_

#include <iostream>
#include <fstream>
#include <algorithm>
#include <utility>
#include <map>
#include <string>

#include <MyLib/myLogDef.h>
#include <MyLib/myDelay.h>

const long int DEFAULT_DELAY_TIME = 35;

/**
 * @brief 将从文件中读取的字符串按一定格式分割并交给 std::pair 去构造并返回
 * 
 * @tparam KeyType              键值对中键的类型
 * @tparam ValueType            键值对中值的类型
 * 
 * @param __fileLineString      从文件中读取的一行字符串
 * 
 * @return 构造好的一个键值对（`std::pair`），其中键是不可修改的
*/
template <typename KeyType, typename ValueType>
std::pair<const KeyType, ValueType> makeStringToPair(const std::string & __fileLineString);

/**
 * @brief 从文件中逐行读取字符串，
 *        然后通过指定格式分割转换后插入一个 std::multimap 中
 * 
 * @tparam KeyType              键值对中键的类型
 * @tparam ValueType            键值对中值的类型
 * 
 * @param __filePath            文件路径
 * @param __cityInfoTable       一张多重映射表（`std::multimap`）的引用
 * 
 * @return non-return
*/
template <typename KeyType, typename ValueType>
void readConvertAndInsert(const std::string __filePath, std::multimap<KeyType, ValueType> & __cityInfoTable);

/**
 * @brief 按照用户指定的格式（DataFormatRule）输出多重映射表的信息
 * 
 * @tparam KeyType              键值对中键的类型
 * @tparam ValueType            键值对中值的类型
 * @tparam DataFormatRule       用户定义的函数指针，Lamba 表达式 或 functor
 * 
 * @param __cityInfoTable       一张多重映射表（`std::multimap`）的只读引用
 * @param __datformat           对数据的说明，用户自行定义
 * 
 * @return non-return
*/
template <typename KeyType, typename ValueType, typename DataFormatRule>
void showMultimap(const std::multimap<KeyType, ValueType> & __cityInfoTable, DataFormatRule __datformat);

#endif // _USE_MULTIMAPDEFS_H_