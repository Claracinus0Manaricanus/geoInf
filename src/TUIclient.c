#include <stdio.h>
#include <stdlib.h>
#include "include/utility.h"
#include "database/dataController.h"

int main(int argc, char** argv){

    char objName[255]={0};//object name
    char tabName[255]={0};//table name
    printf("Enter the table to search:\n>");
    scanf("%s",&tabName);
    printf("Enter object to get:\n>");
    scanf("%s",&objName);

    struct tableElement ret;
    if(getFromTable(tabName,objName,&ret)==0){
        printf("LOG: query succesfull printing results:\n");
        printf(
            "ID: %i\n"
            "name: %s\n"
            "climate: %s\n"
            "soil: %s\n"
            "flora: %s\n"
            "image: %s\n",
            ret.ID,ret.name,ret.climate,ret.soil,ret.flora,ret.image
        );
    }else{
        printf("ERR: query failed!\n");
    }
    addToTable("soils\0",&ret);

    //free memory
    freeGeoObj(&ret);

    //terminate
    return 0;
}

/*
Text User Interface for geoInf project.
This file uses dataController to acces the database.
*/