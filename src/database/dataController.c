#include "dataController.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>


//change the function to use select more efficiently with:
//select * from geoObj where name=<objectName>;
//remove while loop
int getFromTable(char* tableName, char* objectName, struct geoObj* ret){
    //opening database
    sqlite3* database;
    sqlite3_open("src/database/geoInf.db",&database);

    //preparing sqlite3 statement and getting column size
    const char* code="select * from geoObj;\0";
    sqlite3_stmt* STMT_Select;
    sqlite3_prepare(database,code,-1,&STMT_Select,0);
    int cols=sqlite3_column_count(STMT_Select);

    unsigned char check=0;

    while(sqlite3_step(STMT_Select)==SQLITE_ROW){
        if(strcmp(objectName,sqlite3_column_text(STMT_Select,1))==0){
            check=1;
            break;
        }
    }

    if(check){
        ret->ID=sqlite3_column_int(STMT_Select,0);
        ret->name=calloc(1,sqlite3_column_bytes(STMT_Select,1));
        memcpy(ret->name,sqlite3_column_text(STMT_Select,1),sqlite3_column_bytes(STMT_Select,1));
        ret->soilType=calloc(1,sqlite3_column_bytes(STMT_Select,2));
        memcpy(ret->soilType,sqlite3_column_text(STMT_Select,2),sqlite3_column_bytes(STMT_Select,2));
        ret->flora=calloc(1,sqlite3_column_bytes(STMT_Select,3));
        memcpy(ret->flora,sqlite3_column_text(STMT_Select,3),sqlite3_column_bytes(STMT_Select,3));
        ret->image=NULL;
        sqlite3_finalize(STMT_Select);
        sqlite3_close(database);
    }else{
        sqlite3_finalize(STMT_Select);
        sqlite3_close(database);
        return 1;
    }

    return 0;
}