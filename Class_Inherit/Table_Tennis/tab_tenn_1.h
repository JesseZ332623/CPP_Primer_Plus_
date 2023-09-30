#ifndef _TAB_TENN_1_H_
#define _TAB_TENN_1_H_

#include <string>

using std::string;

class Table_Tennis_Player
{
    private:
        string first_name;
        string last_name;
        bool has_table;
    
    public:
        Table_Tennis_Player(const string & fn = "none", 
                            const string & ln = "none", bool ht = false);

        void Name() const;

        bool Has_Table() const { return has_table; }

        void Reset_Table(bool has) { has_table = has; }
};

class Rated_Player : public Table_Tennis_Player
{
    private:
        unsigned int rating;

    public:
        Rated_Player(unsigned int rate = 0, const string & fn = "none",
                     const string & ln = "none", bool ht = false);
        
        Rated_Player(unsigned int rate, const Table_Tennis_Player & tp);

        const unsigned int Get_Rating() { return rating; }

        void Reset_Rating(unsigned int rate) { rating = rate; }
};

#endif