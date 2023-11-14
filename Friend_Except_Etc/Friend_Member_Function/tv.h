#ifndef _TV_H_
#define _TV_H_

#include <iostream> 

/**
 * 有些时候，友元类的使用会造成一些不安全的现象，
 * 所以可以将一个成员方法声明为友元成员函数，但是这会造成一些小麻烦，因此整个头文件的声明和实现顺序都需要重新修改。
 * 
 *                      class Television;
 *                      class Remote {.....};
 *                      class Television {......};
 * 
 *                      Implement Member Function for class Remote (use inline keywords)
*/

/*先命名一个 Television 类，实现在后面。*/
class Television;

/*遥控器类，可以操控电视机，这种设计模式也叫命令模式。*/
class Remote
{
    public:
        enum {OFF, ON};
        enum {MIN_VOLUME, MAX_VOLUME = 20};
        enum {ANTENNA, CABLE};
        enum {TV, DVD};

    private:
        int mode;       /*操控 TV 或 DVD*/

    public:
        Remote(int _mode = TV) : mode(_mode) {}

        bool volume_up(Television & _tv);

        bool volume_down(Television & _tv);

        void On_Off(Television & _tv);

        void channal_up(Television & _tv);

        void channal_down(Television & _tv); 

        bool set_channal(Television & _tv, int _channal);

        void set_mode(Television & _tv);

        void set_input(Television & _tv);

        ~Remote() {}
};

/**
 * 一个电视类，有以下状态和操作。
 * 
        * 状态：
        * 开 / 关
        * 音量大小
        * 最大频道数
        * 当前频道
        * 接收模式
        * 输入模式
 * 
        * 操作：
        * 开关切换
        * 音量 +/-
        * 频道 +/-
        * 切换接收模式
        * 切换输入模式
*/
class Television
{
    private:
        int state;          /*ON or OFF*/
        int volume;         /*音量*/
        int max_channel;    /*最大频道数*/
        int channel;        /*当前频道*/
        int mode;           /*有线接收 或 UHF 广播接收*/
        int input;          /*TV or DVD*/

    public:

        enum {OFF, ON};
        enum {MIN_VOLUME, MAX_VOLUME = 20};
        enum {ANTENNA, CABLE};
        enum {TV, DVD};

        Television(int _state = OFF, int _max_channel = 125) : 
        state(_state), volume(5), max_channel(_max_channel), channel(2), mode(CABLE), input(TV) {}

        /*一个简单的状态切换功能。每次调用就可以在 ON/OFF 两种状态间进行切换*/
        void On_Off() { state = (state == ON) ? OFF : ON; }

        /*判断电视机是否开启*/
        bool is_on() { return state == ON; }
        
        /*音量 + 1*/
        bool volume_up();

        /*音量 - 1*/
        bool volume_down();

        /*频道 + 1*/
        void channal_up();

        /*频道 - 1*/
        void channal_down();

        /*一个简单的模式切换功能。每次调用就可以在 ANTENNA/CABLE 两种状态间进行切换*/
        void set_mode() { mode = (mode == ANTENNA) ? CABLE : ANTENNA; }

        /*一个简单的输入切换功能。每次调用就可以在 TV/DVD 两种状态间进行切换*/
        void set_input() { input = (input == TV) ? DVD : TV; }

        /*展示所有的设置*/
        void display_settings() const;

        friend bool Remote::set_channal(Television & _tv, int _channal);

        ~Television() {}
};

inline bool Remote::volume_up(Television & _tv) 
{
    return _tv.volume_up();
}

inline bool Remote::volume_down(Television & _tv)
{
    return _tv.volume_down();
}

/*..... 接下来的实现以此类推，就不浪费时间了。*/
#endif