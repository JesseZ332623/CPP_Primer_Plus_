#include "./include./Classic.h"

Classic::Classic() : CD()
{
    lead_music = new char[LEAD_LENGTH];
}

Classic::Classic(const char *_lead, const char *perfor, const char *lab, 
                int select, double p_time) : CD(perfor, lab, select, p_time)
{
    lead_music = new char[LEAD_LENGTH];
    std::strcpy(lead_music, _lead);
}

Classic::Classic(const char *_lead, CD & cd) : CD(cd)
{
    lead_music = new char[LEAD_LENGTH];
    std::strcpy(lead_music, _lead);
}

void Classic::Report() const
{
    CD::Report();
    std::cout << "Lead Music: " << lead_music << std::endl;
}

Classic & Classic::operator=(const Classic & classic)
{
    if (this == &classic) { return *this; }
    delete[] lead_music;
    lead_music = new char[LEAD_LENGTH];
    CD::operator=(classic);
    std::strcpy(lead_music, classic.lead_music);

    return *this;
}

Classic::~Classic()
{
    CD::~CD();
    delete[] lead_music;
}