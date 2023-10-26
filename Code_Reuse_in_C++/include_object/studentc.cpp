#include "studentc.h"

using std::ostream, std::istream;
using std::endl;
using std::string;

double Student::Average() const
{
    if (scores.size() > 0)
    {
        return scores.sum() / scores.size();
    }
    else
    {
        return 0;
    }
}

const string Student::Name() const
{
    return name;
}

double & Student::operator[](int _index)
{
    return scores[_index];
}

double Student::operator[](int _index) const
{
    return scores[_index];
}

ostream & Student::array_output(ostream & _os) const
{
    int index;
    int size = scores.size();

    if (size > 0)
    {
        for (index = 0; index < size; ++index)
        {
            std::cout << scores[index] << ' ';
            if (index % 5 == 4) { _os << endl; }
        }
        if (index % 5 != 0) { _os << endl; }
    }
    else
    {
        _os << "Empty Array";
    }

    return _os;
}

std::istream & operator>>(std::istream & _is, Student & _stu)
{
    _is >> _stu.name;

    return _is;
}

std::istream & getline(std::istream & _is, Student & _stu)
{
    getline(_is, _stu.name);

    return _is;
}

std::ostream & operator<<(std::ostream & _os, Student & _stu)
{
    _os << "Scores for " << _stu.name << ":\n";
    _stu.array_output(_os);

    return _os;
}