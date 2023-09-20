#ifndef T0_H
#define T0_H

//math purposes
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

//data holder
struct tableElement{//can be used for multiple tables
    int ID;
    char* name;
    char* climate;
    char* soil;
    char* flora;
    unsigned char* image;
};//every table fills their corresponding values

#endif

/*
T0.h defines structs, constants and the like for other programs to use.
*/