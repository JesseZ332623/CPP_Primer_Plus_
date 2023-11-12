#include "./tv.h"

bool Television::volume_up()
{
    if (volume < MAX_VOLUME) { ++volume; return true; }

    return false;
}

bool Television::volume_down()
{
    if (volume > MIN_VOLUME) { --volume; return true; }

    return false;
}

void Television::channal_up()
{
    if (channel < max_channel) { ++channel; }

    else { channel = 1; }
}

void Television::channal_down()
{
    if (channel > 1) { --channel; }

    else { channel = max_channel; }
}

void Television::display_settings() const
{
    using std::cout, std::cin;

    cout << "Television is: " << ((state == ON) ? "ON" : "OFF") << '\n';

    if (state == ON)
    {
        cout << "Volume: " << volume << '\n';
        cout << "Channel: " << channel << '\n';

        cout << "Mode: " << ((mode == ANTENNA) ? "ANTENNA" : "CABLE") << '\n';
        cout << "Input: " << ((input == TV) ? "TV" : "DVD") << '\n';
    }
}