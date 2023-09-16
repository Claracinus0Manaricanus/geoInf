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
    char* explanation;
    char* soilType;
    char* flora;
    unsigned char* image;
};//every table fills their corresponding values
//for example while climates might fill all variables
//plant types will fill ID, name, explanation and image
//the unneeded variables must be either null or 0

#endif

/*
T0.h defines structs, constants and the like for other programs to use.
*/

/*
iklim
toprak türü
bitki örtüsü
*/