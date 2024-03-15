#ifndef __DEFS__H_
#define __DEFS__H_

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <cctype>
#include <stdexcept>

#include <vector>

using std::string;

#define __DEBUG false
#define PLAY_AGAIN true

#define REMOVE_NEWLINE_IN_STDIN while(std::getchar() != '\n') { continue; }

const char  LIST_FILEPATH[] = \
"F:\\CPP_Primer_Plus_\\Chapter_16\\STL_String\\Hangman\\src\\data\\wordList.txt";
const int GUESS_TIMES = 6;

/**
 * @brief 打开指定文件读取字符串到 WORDS_LIST 中
 * 
 * @param __filePath 文件路径
 * 
 * @return 文件内的单词总数
*/
std::size_t loadFileInList(const char * __filePath);

/**
 * @brief 通过提示确定玩家是否开始游戏
 * 
 * @param __ifPlay  是否开始游戏的提示符（y 是 n 否）
 * @param __ifAgain 是否重新开始游戏的提示符    
 * 
 * @return non-return
*/
void userPlay(char & __ifPlay, bool __ifAgain = false);

#if __DEBUG

/**
 * @brief 往指定流输出 `WORDS_LIST` 的内容，这在调试时使用。
 * 
 * @param __os 用户指定的输出流
 * 
 * @return non-return
*/
void displayWordList(std::ostream & __os);

#endif // __DEBUG


#endif // __DEFS__H_