#ifndef T0_H
#define T0_H

struct Vec2{
    float x,y;
};

struct Hitbox{
    struct Vec2 LDC;//left down
    struct Vec2 RUC;//right up
};

struct Vec3{
    float x,y,z;
};

#endif

/*
T0.h defines structs, constants and the like for other programs to use.
*/