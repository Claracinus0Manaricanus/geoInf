#ifndef DATACONTROLLER_H
#define DATACONTROLLER_H

#include <sqlite3.h>
#include <stdint.h>
#include "../include/T0.h"

//query get functions
int getFromTable(char* tableName, char* objectName, struct tableElement* ret);//gets an object from a table using their names

//query input functions
int addFromTable(char* tableName, char* objectName, struct tableElement* ret);//sets an object to a table using their names

#endif

/*
Header for controlling databases with sqlite3 library.
Its main purpose is to create an interface for other user interfaces.
It has set function names and parameters for abstraction purposes so
that functions can be updated without changing user interface programs.
*/