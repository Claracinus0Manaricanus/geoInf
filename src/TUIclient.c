#include <stdio.h>
#include <stdlib.h>
#include "include/utility.h"
#include "database/dataController.h"

int main(int argc, char** argv){

    char input[255]={0};
    printf("Enter a climate name:\n>");
    scanf("%s",&input);

    struct geoObj ret;
    if(getFromTable("geoObj\0",input,&ret)==0){
        printf("LOG: query succesfull printing results:\n");
        printf(
            "ID: %i\n"
            "name: %s\n"
            "soilType: %s\n"
            "flora: %s\n"
            "image is work in progress\n",
            ret.ID,ret.name,ret.soilType,ret.flora
        );
    }else{
        printf("ERR: query failed!\n");
    }

    //free memory
    freeGeoObj(&ret);

    //terminate
    return 0;
}

/*
Text User Interface for geoInf project.
This file uses dataController to acces the database.
*/