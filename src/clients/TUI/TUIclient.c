#include <stdio.h>
#include <stdlib.h>
#include "../../include/utility.h"
#include "../../database/dataController.h"

//constants
const char* MESSAGE_HELP=
"-a <action> : selects an action such as get or set. see actions.\n"
"-help       : displays help message.\n"
"actions list:\n"
"get = gets an element from a table\n"
"set = inserts an element to a table\n"
"del = deletes an element from a table\n"
"list = list name column values of a table\n"
"\0";

int main(int argc, char** argv){
    if(argc<2){
        printf("too few arguments.\ntry to use:\n%s",MESSAGE_HELP);
        return 1;
    }

    //vars
    char tabName[255]={0};//tableName
    char input[255]={0};
    struct tableElement element;
    char** elementNames=NULL;
    int namesLength=0;

    switch(parseArguments(argc,argv)){
        case COMMAND_GET:
            //input
            printf("table name > ");
            scanf("%s",&tabName);
            printf("element name > ");
            scanf("%s",&input);
            //accessing database
            getFromTable(tabName,input,&element);
            //output
            printf(
                "ID: %i\n"
                "name: %s\n"
                "climate: %s\n"
                "soil: %s\n"
                "flora: %s\n"
                "image: %s\n",
                element.ID,element.name,element.climate,element.soil,element.flora,element.image
            );
            //cleaning
            freeGeoObj(&element);
        break;

        case COMMAND_SET:
            //input
            //table name
            printf("table to insert > ");
            scanf("%s",&tabName);
            //element name
            printf("element name > ");
            scanf("%s",&input);
            element.name=calloc(sizeof(char),strlen(input));
            memcpy(element.name,input,strlen(input));
            //climate
            printf("element climate > ");
            fgets((char*)&input,255,stdin);//workaround to unknown bug
            fgets((char*)&input,255,stdin);
            element.climate=calloc(sizeof(char),strlen(input)-1);
            memcpy(element.climate,input,strlen(input)-1);
            //soil
            printf("element soil > ");
            fgets((char*)&input,255,stdin);
            element.soil=calloc(sizeof(char),strlen(input)-1);
            memcpy(element.soil,input,strlen(input)-1);
            //flora
            printf("element flora > ");
            fgets((char*)&input,255,stdin);
            element.flora=calloc(sizeof(char),strlen(input)-1);
            memcpy(element.flora,input,strlen(input)-1);
            //image
            printf("element image > ");
            fgets((char*)&input,255,stdin);
            element.image=calloc(sizeof(char),strlen(input)-1);
            memcpy(element.image,input,strlen(input)-1);

            //inserting to table
            addToTable(tabName,&element);
            freeGeoObj(&element);
        break;

        case COMMAND_DEL:
            //input
            printf("table to delete from > ");
            scanf("%s",&tabName);
            printf("element to delete > ");
            scanf("%s",&input);
            //deleting
            deleteFromTable(tabName,input);
        break;

        case COMMAND_SCAN:
            //input
            printf("table to scan > ");
            scanf("%s",&tabName);
        break;
        
        case COMMAND_HELP:
            printf("%s",MESSAGE_HELP);
        break;

        default:
            printf("wrong arguments for -a.\ntry to use:\n%s",MESSAGE_HELP);
        break;
    }

    //terminate
    return 0;
}

/*
Text User Interface for geoInf project.
This file uses dataController to acces the database.
*/