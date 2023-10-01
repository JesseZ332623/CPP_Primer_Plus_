#include "./tab_tenn_1.h"

Table_Tennis_Player::Table_Tennis_Player(const string &fn,
                                         const string &ln, bool ht) : first_name(fn),
                                                                      last_name(ln), has_table(ht) {}

void Table_Tennis_Player::Name() const
{
    std::cout << last_name << '_' << first_name;
}

Rated_Player::Rated_Player(unsigned int rate, const string &fn,
                           const string &ln, bool ht) : Table_Tennis_Player(fn, ln, ht)
{
    rating = rate;
}

Rated_Player::Rated_Player(unsigned int rate,
                           const Table_Tennis_Player &tp)
    : Table_Tennis_Player(tp), rating(rate) {}