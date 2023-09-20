#ifndef DATACONTROLLER_H
#define DATACONTROLLER_H

#include <sqlite3.h>
#include <stdint.h>
#include "../include/T0.h"

//database get functions
int getFromTable(char* tableName, char* objectName, struct tableElement* ret);//gets an object from a table using their names
int getTableElementNames(char* tableName, char*** elementNames, int &size);//fills elementNames with tables name column values

//database input functions
int addToTable(char* tableName, struct tableElement* vals);//sets an object to a table using their names
int deleteFromTable(char* tableName, char* elementName);//deletes the element with the given name from <tableName>

#endif

/*
Header for controlling databases with sqlite3 library.
Its main purpose is to create an interface for other user interfaces.
It has set function names and parameters for abstraction purposes so
that functions can be updated without changing user interface programs.
*/