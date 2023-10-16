#ifndef UTILITY_H
#define UTILITY_H

//command constants
#define COMMAND_HELP 0
#define COMMAND_GET  1
#define COMMAND_SET  2
#define COMMAND_DEL  3
#define COMMAND_SCAN 4

#include "T0.h"
#include <stdint.h>
#include <stdlib.h>
#include <string.h>

//memory safety features
int setZeroGeoObj(struct tableElement *toSet);

//memory freeing
int freeGeoObj(struct tableElement* toFree);//frees given geoObj struct

//argument parsing
int parseArguments(int argc, char** argv);

#endif

/*
utility.h supplies utilities such as window and opengl context creation.
Its usage is meant to tidy up the code thats repetitive or constant.
It also supplies functions for interface programs to use.
*/