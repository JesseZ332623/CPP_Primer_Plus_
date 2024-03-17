#ifndef _TERMINAL_COLOR_H_
#define _TERMINAL_COLOR_H_

#include <ostream>

enum ColorMenu { RED = 1, GREEN, YELLO, BLUE = 6, WHITE };

class TerminalTextColor
{
    private:
        int colorCode {0};

    public:
        TerminalTextColor(const int __colorSign) : colorCode(__colorSign) {}

        friend std::ostream & operator<<(std::ostream & __os, const TerminalTextColor & __colorSign)
        {
            std::string asciiColorSign;

            asciiColorSign += "\033[38;5;" + std::to_string(__colorSign.colorCode) + "m";

            __os << asciiColorSign; 

            return __os;
        }
};

typedef struct LogLevel
{
    public:
        TerminalTextColor Original{WHITE};
        TerminalTextColor Notify{BLUE};
        TerminalTextColor Warning{YELLO};
        TerminalTextColor Correct{GREEN};
        TerminalTextColor Error{RED};
} MyLog;

/*一个简单的日志库，用于不同类型消息的输出*/
const MyLog myLog;

#define ORIGINAL    myLog.Original
#define NOTIFY      myLog.Notify
#define WARNING     myLog.Warning
#define CORRECT     myLog.Correct
#define ERROR       myLog.Error

#endif  // _TERMINAL_COLOR_H_