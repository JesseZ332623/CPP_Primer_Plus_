#include <iostream>

struct box
{
    char maker[40];
    float height;
    float width;
    float length;
    double volume;
};

double calculate_volume(struct box *_box);
struct box *comp_volume(struct box *_box_1, struct box *_box_2);

double calculate_volume(struct box *_box)
{
    _box->volume = _box->height * _box->width * _box->length;
    return _box->volume;
}

struct box *comp_volume(struct box *_box_1, struct box *_box_2)
{
    if (calculate_volume(_box_1) > calculate_volume(_box_2))
    {
        return _box_1;
    }
    else 
    {
        return _box_2;
    }
}

int main(int argc, char const *argv[])
{
    box *_box_1 = new box{"Box_1", 10.78, 89.45, 8.9901, 0.0000};
    box *_box_2 = new box{"Box_2", 20.21, 9.50, 18.92, 0.0000};

    box *_box_3 = comp_volume(_box_1, _box_2);

    std::cout << _box_3->maker << ' ' << _box_3->volume << '\n';

    delete _box_1;
    delete _box_2;
    
    return EXIT_SUCCESS;
}
