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
struct geoObj{
    int ID;
    char* name;
    char* soilType;
    char* flora;
    unsigned char* image;
};

#endif

/*
T0.h defines structs, constants and the like for other programs to use.
*/

/*
iklim
toprak türü
bitki örtüsü
*/