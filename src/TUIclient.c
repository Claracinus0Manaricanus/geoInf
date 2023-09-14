#include <stdio.h>
#include "include/utility.h"
#include "database/dataController.h"

int main(int argc, char** argv){

    struct geoObj ret;
    if(getFromTable("geoObj\0","trial\0",&ret)==0){
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

    return 0;
}

/*
Text User Interface for geoInf project.
This file uses dataController to acces the database.
*/