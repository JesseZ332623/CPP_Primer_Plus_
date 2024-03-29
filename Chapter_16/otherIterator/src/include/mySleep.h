#ifndef _MY_SLEEP_H_
#define _MY_SLEEP_H_

/**
 * @brief 自制延时函数，用于代替 windows 库中的 Sleep()
 * 
 * @param __millisSeconds 延时时间（毫秒）
 * 
 * @return non-return
*/
extern void delayMilliseconds(long int __millisSeconds);

#endif // _MY_SLEEP_H_