#include "cm_string.h"
#include <string.h>
#include <stdlib.h>

char* cm_concat(char** addArray, unsigned int addArraySize){
    unsigned int lengths[addArraySize],total=0;
    for(int i=0;i<addArraySize;i++){
        lengths[i]=strlen(addArray[i]);
        total+=lengths[i];
    }
    char* finalString=calloc(sizeof(char),total+1);
    total=0;
    for(int i=0;i<addArraySize;i++){
        memcpy(&finalString[total],addArray[i],lengths[i]);
        total+=lengths[i];
    }
    
    return finalString;
}