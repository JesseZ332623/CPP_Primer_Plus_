#include "./include/_String.h"

/*将字符串类的数量初始化为 0*/
int _String::str_count = 0;

/*默认构建函数*/
_String::_String()
{
    _length = 4;

    str = new char[1];

    str[0] = '\0';

    ++str_count;
}

/*传入字符串的构建函数*/
_String::_String(const char *_str)
{
    _length = std::strlen(_str);

    str = new char[_length + 1];

    std::strcpy(str, _str);

    ++str_count;
}

/*传入字符串类的构建函数*/
_String::_String(_String & str_object)
{
    _length = str_object._length;

    str = new char[_length + 1];

    std::strcpy(str, str_object.str);

    ++str_count;
}

/*将字符串全部转换成小写*/
void _String::string_low()
{
    for (size_t index = 0; index < _length; ++index)
    {
        str[index] = std::tolower(str[index]);
    }
}

/*将字符串全部转换成大写*/
void _String::string_upper()
{
    for (size_t index = 0; index < _length; ++index)
    {
        str[index] = std::toupper(str[index]);
    }
}

const size_t _String::appear_times(const char _ch) const
{
    if (!_ch)
    {
        throw "Enter ERROR.....\n";
    }

    size_t appears = 0;

    for (size_t index = 0; index < _length; ++index)
    {
        if (this->str[index] == _ch)
        {
            ++appears;
        }
    }

    return appears;
}

/*字符串的赋值操作 字符串类 赋值给 字符串类*/
_String & _String::operator=(const _String & str_object)
{
    /*如果传入的就是该对象本身，直接返回就行。*/
    if (this == &str_object)
    {
        return *this;
    }

    delete[] str;       /*删除旧字符串*/

    /*获取传入的字符串类的字符串长度*/
    _length = str_object._length;   

    /*重新给字符串类分配内存*/
    str = new char[_length + 1];

    /*将传入的字符串类中的字符串拷贝*/
    std::strcpy(str, str_object.str);

    /*返回调用此方法的类的引用*/
    return *this;
}

/*字符串的赋值操作 字符串 赋值给 字符串类*/
_String & _String::operator=(const char *_str)
{
    delete[] str;

    _length = std::strlen(_str);

    str = new char[_length + 1];

    std::strcpy(str, _str);

    return *this;
}

char & _String::operator[](int index)
{
    return str[index];
}

const char & _String::operator[](int index) const
{
    return str[index];
}

/*合并字符串 传入一个 _String 对象*/
_String _String::operator+(const _String & _str) const
{
    _String cat_string;

    cat_string._length = this->_length + _str._length;

    cat_string.str = new char[cat_string._length + 1];

    std::strcpy(cat_string.str, this->str);
    std::strcat(cat_string.str, _str.str);

    return cat_string; 
}

/*合并字符串 传入一个 C 风格的字符串*/
_String _String::operator+(const char * c_str) const
{
    _String cat_string;

    cat_string._length = this->_length + std::strlen(c_str);

    cat_string.str = new char[cat_string._length + 1];

    std::strcpy(cat_string.str, this->str);
    std::strcat(cat_string.str, c_str);

    return cat_string;
}

_String operator+(const char *c_str, const _String _str)
{
    _String cat_string;

    cat_string._length = _str._length + std::strlen(c_str);

    cat_string.str = new char[cat_string._length + 1];

    std::strcpy(cat_string.str, c_str);
    std::strcat(cat_string.str, _str.str);

    return cat_string;
}

/*
    这里有必要复习一下 strcmp 函数，
    它逐个比较两个字符串 a b中的每一个字符，返回一个 int 类型，有如下三种情况：
    返回值为 0 两个字符串完全相等
    返回值为 > 0 字符串 a 的 ASCII 码值比 字符串 b 大
    返回值为 < 0 字符串 b 的 ASCII 码值比 字符串 a 大
*/
bool operator>(const _String & _str_1, const _String & _str_2)
{
    return _str_2 < _str_1;
}

bool operator<(const _String & _str_1, const _String & _str_2)
{
   return (std::strcmp(_str_1.str, _str_2.str) < 0);
}

bool operator==(const _String & _str_1, const _String & _str_2)
{
    return (std::strcmp(_str_1.str, _str_2.str) == 0);
}

ostream & operator<<(ostream & _os, const _String & _str)
{
    _os << _str.str;

    return _os;
}

istream & operator>>(istream & _is, const _String & _str)
{
    char temp_str[_String::CIN_LIMIT];

    _is.get(temp_str, _String::CIN_LIMIT);

    if (_is)
    {
        std::strcpy(_str.str, temp_str);
    }

    while (_is && _is.get() != '\n')
    {
        continue;
    }

    return _is;   
}

_String::~_String()
{
    --str_count;
    delete[] str;
    //str = nullptr;
}

const size_t _String::String_Count()
{
    return str_count;
}