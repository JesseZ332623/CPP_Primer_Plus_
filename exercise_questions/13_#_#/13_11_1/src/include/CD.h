#ifndef _CD_H_
#define _CD_H_

#include <cstring>
#include <iostream>

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
        char performers[50];
        char label[20];
        int selections;
        double play_times;/*传入分钟数 如 2.66*/
    
    public:
        CD(const char *perfor, const char *lab, int select, double p_time);
        CD(const CD & cd);
        CD();

        virtual void Report() const;

        virtual CD & operator=(const CD & cd);

        ~CD() {};
};



#endif