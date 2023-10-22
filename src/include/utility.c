#include "utility.h"

//memory safety features
int setNULLGeoObj(struct tableElement *toSet){
    toSet->name=NULL;
    toSet->climate=NULL;
    toSet->soil=NULL;
    toSet->flora=NULL;
    toSet->image=NULL;
    return 0;
}

//memory freeing
int freeGeoObj(struct tableElement* toFree){
    free(toFree->name);
    free(toFree->climate);
    free(toFree->soil);
    free(toFree->flora);
    free(toFree->image);
    setNULLGeoObj(toFree);
    return 0;
}


//argument parsing
int parseArguments(int argc, char** argv){

    for(int i=1;i<argc;i++){
        if(strcmp(argv[i],"-a\0")==0){
            if(i<(argc-1)){
                i++;
                if(strcmp(argv[i],"get")==0){
                    return COMMAND_GET;
                }else if(strcmp(argv[i],"set")==0){
                    return COMMAND_SET;
                }else if(strcmp(argv[i],"del")==0){
                    return COMMAND_DEL;
                }else if(strcmp(argv[i],"list")==0){
                    return COMMAND_SCAN;
                }else{
                    return 0;
                }
            }else{
                continue;
            }
        }
    }

    return 0;
}