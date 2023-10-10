#ifndef _CD_H_
#define _CD_H_

#include <cstring>
#include <iostream>

const int PERFORMERS_LENGTH = 50;
const int LABLE_LENGTH = 20;

/*
    基类 CD 的私有成员为：
    演出者
    唱片公司
    选择的数量
    播放时间
*/
class CD
{
    private:
        char *performers;   /*默认长度 50*/
        char *label;        /*默认长度 20*/
        int selections;
        double play_times;  /*传入分钟数 如 2.66 分钟*/
    
    public:
        CD();
        CD(const CD & cd); 
        CD(const char *perfor, const char *lab, int select, double p_time);

        virtual void Report() const;

        virtual CD & operator=(const CD & cd);

        virtual ~CD();
};
#endif