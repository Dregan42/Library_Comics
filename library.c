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

//create an unique ID for a comics in the library L
Library* add_comics_to_library(Library *L){
    L->nbBooks ++;
    char author[40];
    char title[200];
    char editor[40];
    printf("\nNew Comics :\n");
    printf("\nAuthor : ");
    scanf("%s", author);
    printf("\nTitle : ");
    scanf("%s",title);
    printf("\nEditor :");
    scanf("%s",editor);
    L->Tab_comics[L->nbBooks-1] = create_comics(author,title, editor);
    L->Tab_comics[L->nbBooks-1]->id = L->nbBooks-1;
    return L;
}

Library* remove_comics_from_library(int comics_id){

    return NULL;
}

void show_library(Library *L){
    int i;
    printf("\nId\tTitle\tAuthor\tEditor\n");
    printf("---\t------\t-------\t-------\n");
    for(i=0;i<L->nbBooks;i++){
        printf(" %d\t %s\t %s \t%s\n",L->Tab_comics[i]->id,L->Tab_comics[i]->title,L->Tab_comics[i]->author,L->Tab_comics[i]->editor);
    }
}

void show_comics(Library *L, int comics_id){
    printf("\nTitle : %s", L->Tab_comics[comics_id]->title);
    printf("\nAuthor : %s", L->Tab_comics[comics_id]->author);
    printf("\nEditor : %s", L->Tab_comics[comics_id]->editor);
    printf("\nRate : %d", L->Tab_comics[comics_id]->rate);
    printf("\nRead ? %d", L->Tab_comics[comics_id]->read);
    printf("\nComments : %s", L->Tab_comics[comics_id]->comment);
    printf("\n");
}
