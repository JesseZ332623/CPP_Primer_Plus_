#ifndef _TAB_TENN_1_H_
#define _TAB_TENN_1_H_

#include <string>
#include <iostream>

using std::string;

/*基类 Table_Tennis_Player*/
class Table_Tennis_Player
{
    private:
        string first_name;
        string last_name;
        bool has_table;
    
    public:
        /*初始化类私有数据*/
        Table_Tennis_Player(const string & fn = "none", 
                            const string & ln = "none", bool ht = false);

        /*输出 顾客姓名 last_name · first_name*/
        void Name() const;

        /*返回 顾客是否拥有球桌*/
        bool Has_Table() const { return has_table; }

        /*重设 顾客是否拥有球桌*/
        void Reset_Table(bool has) { has_table = has; }
};

/*Table_Tennis_Player 类的派生类 Rated_Player*/
class Rated_Player : public Table_Tennis_Player
{
    private:
        unsigned int rating;

    public:
        /*初始化类私有数据*/
        Rated_Player(unsigned int rate = 0, const string & fn = "none",
                     const string & ln = "none", bool ht = false);
        
        Rated_Player(unsigned int rate, const Table_Tennis_Player & tp);

        /*获取这位顾客的排名*/
        const unsigned int Get_Rating() { return rating; }

        /*重设 顾客排名*/
        void Reset_Rating(unsigned int rate) { rating = rate; }


};

#endif