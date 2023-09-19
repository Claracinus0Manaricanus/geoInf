#include "dataController.h"
#include "../include/cm_string.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//query request functions

//functions need error checking
int getFromTable(char* tableName, char* objectName, struct tableElement* ret){
    //opening database
    sqlite3* database;
    if(sqlite3_open("src/database/geoInf.db",&database)!=SQLITE_OK)
        return 1;//exit if opening database failed

    //constructing SQL command
    char* codeToAdd[5]={"select * from \0",tableName," where name='\0",objectName,"';\0"};
    char* code=cm_concat(codeToAdd,5);
    //using that command
    sqlite3_stmt* STMT_Select;
    sqlite3_prepare(database,code,-1,&STMT_Select,0);
    free(code);//we are done with the code string

    //checking if element was found
    unsigned char isFound=(sqlite3_step(STMT_Select)==SQLITE_ROW);

    //returning data
        //expressing failure (changes if results found)
        //it is set beforehand for safety and optimization purposes
        ret->ID=-1;
        ret->name=NULL;
        ret->explanation=NULL;
        ret->soilType=NULL;
        ret->flora=NULL;
        ret->image=NULL;
    if(isFound){
        if(strcmp(tableName,"climates\0")==0){
            //ID
            ret->ID=sqlite3_column_int(STMT_Select,0);
            //name
            ret->name=calloc(1,sqlite3_column_bytes(STMT_Select,1));
            memcpy(ret->name,sqlite3_column_text(STMT_Select,1),sqlite3_column_bytes(STMT_Select,1));
            //explanation (4 because of reasons)
            ret->explanation=calloc(1,sqlite3_column_bytes(STMT_Select,4));
            memcpy(ret->explanation,sqlite3_column_text(STMT_Select,4),sqlite3_column_bytes(STMT_Select,4));
            //soilType
            ret->soilType=calloc(1,sqlite3_column_bytes(STMT_Select,2));
            memcpy(ret->soilType,sqlite3_column_text(STMT_Select,2),sqlite3_column_bytes(STMT_Select,2));
            //flora
            ret->flora=calloc(1,sqlite3_column_bytes(STMT_Select,3));
            memcpy(ret->flora,sqlite3_column_text(STMT_Select,3),sqlite3_column_bytes(STMT_Select,3));
            //image
            ret->image=calloc(1,sqlite3_column_bytes(STMT_Select,5));
            memcpy(ret->image,sqlite3_column_text(STMT_Select,5),sqlite3_column_bytes(STMT_Select,5));
        }else if(strcmp(tableName,"plants\0")==0){
            //ID
            ret->ID=sqlite3_column_int(STMT_Select,0);
            //name
            ret->name=calloc(1,sqlite3_column_bytes(STMT_Select,1));
            memcpy(ret->name,sqlite3_column_text(STMT_Select,1),sqlite3_column_bytes(STMT_Select,1));
            //explanation (4 because of reasons)
            ret->explanation=calloc(1,sqlite3_column_bytes(STMT_Select,2));
            memcpy(ret->explanation,sqlite3_column_text(STMT_Select,2),sqlite3_column_bytes(STMT_Select,2));
            //image
            ret->image=calloc(1,sqlite3_column_bytes(STMT_Select,3));
            memcpy(ret->image,sqlite3_column_text(STMT_Select,3),sqlite3_column_bytes(STMT_Select,3));
        }
    }

    //cleaning
    sqlite3_finalize(STMT_Select);
    sqlite3_close(database);
    return !isFound;//if isFound is true will return 0
}


//database input functions


//needs error checking
int addToTable(char* tableName, struct tableElement* vals){
    //opening database

    //constructing SQL command
    //insert into <tableName>(<values>) values(<ret>);

    //preparing sqlite3 statement

    //cleaning
    return 0;
}