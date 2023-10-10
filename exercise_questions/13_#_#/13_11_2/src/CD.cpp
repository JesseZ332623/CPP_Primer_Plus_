#include "./include/CD.h"
#include <cmath>

CD::CD()
{
    performers = new char[PERFORMERS_LENGTH];
    label = new char[LABLE_LENGTH];
    selections = 0;
    play_times = 0.0000;

    std::strcpy(performers, "No performers");
    std::strcpy(label, "No label");
}

CD::CD(const CD & cd)
{
    performers = new char[PERFORMERS_LENGTH];
    label = new char[LABLE_LENGTH];

    std::strcpy(performers, cd.performers);
    std::strcpy(label, cd.label);
    selections = cd.selections;
    play_times = cd.play_times;
}

CD::CD(const char *perfor, const char *lab, int select, double p_time)
{
    performers = new char[PERFORMERS_LENGTH];
    label = new char[LABLE_LENGTH];
    
    std::strcpy(performers, perfor);
    std::strcpy(label, lab);
    selections = select;
    play_times = p_time;
}

void CD::Report() const
{
    double sec = (play_times - (int)play_times) * 60;

    std::cout << "Performers: " << performers << std::endl;
    std::cout << "Label: " << label << std::endl;
    std::cout << "Selections: " << selections << std::endl;
    std::cout << "Play Time: " 
              << (int)play_times << " miniuts " << std::round(sec) << " seconds." << std::endl; 
}

CD & CD::operator=(const CD & cd)
{
    if (this == &cd) { return *this; }

    delete[] performers;
    delete[] label;
    
    performers = new char[PERFORMERS_LENGTH];
    label = new char[LABLE_LENGTH];

    std::strcpy(performers, cd.performers);
    std::strcpy(label, cd.label);
    selections = cd.selections;
    play_times = cd.play_times;

    return *this;
}

CD::~CD()
{
    delete[] performers;
    delete[] label;
}