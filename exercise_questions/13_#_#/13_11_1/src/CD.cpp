#include "./include/CD.h"
#include <cmath>

CD::CD(const char *perfor, const char *lab, int select, double p_time)
{
    std::strcpy(performers, perfor);
    std::strcpy(label, lab);
    selections = select;
    play_times = p_time;
}

CD::CD(const CD & cd)
{
    std::strcpy(performers, cd.performers);
    std::strcpy(label, cd.label);
    selections = cd.selections;
    play_times = cd.play_times;
}

CD::CD()
{
    std::memset(performers, 0, std::strlen(performers) + 1);
    std::memset(label, 0, std::strlen(label) + 1);
    selections = 0;
    play_times = 0.0000;

    performers[std::strlen(performers) + 1] = '\0';
    label[std::strlen(label) + 1] = '\0';
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

    std::strcpy(performers, cd.performers);
    std::strcpy(label, cd.label);
    selections = cd.selections;
    play_times = cd.play_times;

    return *this;
}

