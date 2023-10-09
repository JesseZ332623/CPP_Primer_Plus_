#include "./include./Classic.h"

Classic::Classic() : CD()
{
    std::memset(lead_music, 0, std::strlen(lead_music) + 1);
    lead_music[std::strlen(lead_music) + 1] = '\0';
}

Classic::Classic(const char *_lead, const char *perfor, const char *lab, 
                int select, double p_time) : CD(perfor, lab, select, p_time)
{
    std::strcpy(lead_music, _lead);
}

Classic::Classic(const char *_lead, CD & cd) : CD(cd)
{
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

    CD::operator=(classic);
    std::strcpy(lead_music, classic.lead_music);

    return *this;
}