#include <stdlib.h>
#include <stdio.h>

#include "library.h"

Library* create_library(){
    Library* L = (Library*)malloc(sizeof(Library));
    if(!L) return NULL;

    L->nbBookMax = 1024;
    L->nbBooks = 0;
    L->Tab_comics = (Comics**)malloc(sizeof(Comics*));
    if(!L->Tab_comics) return NULL;

    return L;
}

Library* add_comics_to_library(){

    return NULL;
}

Library* remove_comics_from_library(int comics_id){

    return NULL;
}

void show_library(Library *L){
    if(L){
        int i;
        for(i=0;i<L->nbBooks;i++){
            printf("%d\t%s\t%s",L->Tab_comics[i]->id,L->Tab_comics[i]->title,L->Tab_comics[i]->author);
        }
    }
}

void show_comics(int comics_id){

}