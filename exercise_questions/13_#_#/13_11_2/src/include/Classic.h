#ifndef _CLASSIC_H_
#define _CLASSIC_H_

#include "./CD.h"

const int LEAD_LENGTH = 50;

class Classic : public CD
{
    private:
        char *lead_music;

    public:
        Classic();
        Classic(const char *_lead, const char *perfor, const char *lab, 
                int select, double p_time);
        Classic(const char *_lead, CD & cd);

        virtual void Report() const;
        virtual Classic & operator=(const Classic & classic);

        virtual ~Classic();
};

#endif