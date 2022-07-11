#ifndef MODIFIERS_H
#define MODIFIERS_H


class modifiers
{
public:
    int move_x, move_y, time_x1, time_x2, time_y1, time_y2;
    static modifiers* static_modifiers();
    modifiers();
    ~modifiers();
};

#endif // MODIFIERS_H
