#include "dataController.h"
#include "../include/cm_string.h"
#include "../include/utility.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//database request functions

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
        setNULLGeoObj(ret);
    if(isFound){//same for all geography tables
        //ID
        ret->ID=sqlite3_column_int(STMT_Select,0);
        //name
        ret->name=calloc(1,sqlite3_column_bytes(STMT_Select,1));
        memcpy(ret->name,sqlite3_column_text(STMT_Select,1),sqlite3_column_bytes(STMT_Select,1));
        //climate
        ret->climate=calloc(1,sqlite3_column_bytes(STMT_Select,2));
        memcpy(ret->climate,sqlite3_column_text(STMT_Select,2),sqlite3_column_bytes(STMT_Select,2));
        //soilType
        ret->soil=calloc(1,sqlite3_column_bytes(STMT_Select,3));
        memcpy(ret->soil,sqlite3_column_text(STMT_Select,3),sqlite3_column_bytes(STMT_Select,3));
        //flora
        ret->flora=calloc(1,sqlite3_column_bytes(STMT_Select,4));
        memcpy(ret->flora,sqlite3_column_text(STMT_Select,4),sqlite3_column_bytes(STMT_Select,4));
        //image
        ret->image=calloc(1,sqlite3_column_bytes(STMT_Select,5));
        memcpy(ret->image,sqlite3_column_text(STMT_Select,5),sqlite3_column_bytes(STMT_Select,5));
    }

    //cleaning
    sqlite3_finalize(STMT_Select);
    sqlite3_close(database);
    return !isFound;//if isFound is true will return 0
}



int getTableElementNames(char* tableName, char*** elementNames, int* size){//fills elementNames with tables name column values
    //opening database
    sqlite3* db;
    if(sqlite3_open("src/database/geoInf.db",&db)!=SQLITE_OK)
        return -1;

    //code assembling
    char* codeToAdd[3]={"select name from \0",tableName,";"};
    char* code=cm_concat(codeToAdd,3);

    //statement
    sqlite3_stmt* STMT_Select;
    sqlite3_prepare(db,code,-1,&STMT_Select,0);
    free(code);//we are done with the code string

    //reading data
    int length=0,textSize=0;
    char** results=NULL;
    while(sqlite3_step(STMT_Select)==SQLITE_ROW){
        length++;
        textSize=sqlite3_column_bytes(STMT_Select, 0);
        results=realloc(results,sizeof(char*)*length);
        results[length-1]=calloc(textSize+1,sizeof(char));
        memcpy(results[length-1],sqlite3_column_text(STMT_Select,0),textSize);
    }

    //cleanup
    sqlite3_finalize(STMT_Select);
    sqlite3_close(db);

    //returns
    if(length==0)return -1;
    (*size)=length;
    (*elementNames)=results;
    return 0;
}


//database input functions

//needs error checking
int addToTable(char* tableName, struct tableElement* vals){
    //opening database
    sqlite3* database;
    if(sqlite3_open("src/database/geoInf.db",&database)!=SQLITE_OK)
        return 1;

    //constructing SQL command
    //insert into <tableName>(<values>) values(<ret>);
    char* commands[13]={
        "insert into \0",
        tableName,
        "(name,climate,soil,flora,image) values('\0",
        vals->name,"','\0",
        vals->climate,"','\0",
        vals->soil,"','\0",
        vals->flora,"','\0",
        vals->image,"');\0"
    };
    char* code=cm_concat(commands,13);

    //preparing sqlite3 statement
    sqlite3_stmt* STMT_insert;
    sqlite3_prepare(database,code,-1,&STMT_insert,0);
    free(code);
    sqlite3_step(STMT_insert);

    //cleaning
    sqlite3_finalize(STMT_insert);
    sqlite3_close(database);
    return 0;
}

int deleteFromTable(char* tableName, char* elementName){
    //opening database
    sqlite3* database;
    if(sqlite3_open("src/database/geoInf.db",&database)!=SQLITE_OK)
        return 1;

    //constructing SQL command
    char* commands[5]={
        "delete from \0",
        tableName,
        " where name='\0",
        elementName,"';\0"
    };
    char* code=cm_concat(commands,5);

    //preparing command
    sqlite3_stmt* STMT_Delete;
    sqlite3_prepare(database,code,-1,&STMT_Delete,0);
    sqlite3_step(STMT_Delete);

    //cleaning
    sqlite3_finalize(STMT_Delete);
    sqlite3_close(database);
    return 0;
}