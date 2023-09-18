#include "dataController.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>


//change the function to use select more efficiently with:
//select * from geoObj where name=<objectName>;
//remove while loop
//add different functions for different tables
//or add a switch statement (using void* for returning data)
//functions need error checking
int getFromTable(char* tableName, char* objectName, struct tableElement* ret){
    //opening database
    sqlite3* database;
    sqlite3_open("src/database/geoInf.db",&database);

    //preparing sqlite3 statement and getting column size
    char* codeToAdd="select * from \0";
    char* code=calloc(16+strlen(tableName),sizeof(char));
    code=memcpy(code,codeToAdd,16);
    code=strcat(code, tableName);
    sqlite3_stmt* STMT_Select;
    sqlite3_prepare(database,code,-1,&STMT_Select,0);
    free(code);//we are done with code string
    int cols=sqlite3_column_count(STMT_Select);

    unsigned char check=0;

    while(sqlite3_step(STMT_Select)==SQLITE_ROW){
        if(strcmp(objectName,sqlite3_column_text(STMT_Select,1))==0){
            check=1;
            break;
        }
    }

    if(check&&strcmp(tableName,"Climates\0")){
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
        ret->image=NULL;
    }else{
        //expressing failure
        ret->ID=-1;
        ret->name=NULL;
        ret->explanation=NULL;
        ret->soilType=NULL;
        ret->flora=NULL;
        ret->image=NULL;
        //cleaning
        sqlite3_finalize(STMT_Select);
        sqlite3_close(database);
        return 1;
    }

    //cleaning
    sqlite3_finalize(STMT_Select);
    sqlite3_close(database);
    return 0;
}