#ifndef _TV_H_
#define _TV_H_

#include <iostream>

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
        /*
            将 遥控器 Remote 设为自己的友元类，
            因此 Remote 可以改变 TV 的状态。
        */
        friend class Remote;

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

        ~Television() {}
};

/**/
class Remote
{
    private:
        int mode;       /*操控 TV 或 DVD*/

    public:
        Remote(int _mode = Television::TV) : mode(_mode) {}

        bool volume_up(Television & _tv) { return _tv.volume_up(); }

        bool volume_down(Television & _tv) { return _tv.volume_down(); }

        void On_Off(Television & _tv) { return _tv.On_Off(); }

        void channal_up(Television & _tv) { return _tv.channal_up(); }

        void channal_down(Television & _tv) { return _tv.channal_down(); }

        bool set_channal(Television & _tv, int _channal);

        void set_mode(Television & _tv) { return _tv.set_mode(); }

        void set_input(Television & _tv) { return _tv.set_input(); }

        ~Remote() {}
};

#endif