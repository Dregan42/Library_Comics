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
    L->counter ++;
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
    L->Tab_comics[L->nbBooks-1]->id = L->counter-1;
    return L;
}


//so much bug here !!!
Library* remove_comics_from_library(Library* L,int comics_id){
    if (L){
        if(comics_id < L->nbBooks){
            if(L->Tab_comics[comics_id]!=NULL){
                int i;
                for (i = comics_id;i<L->nbBooks-2;i++){
                    L->Tab_comics[comics_id]->id = L->Tab_comics[comics_id+1]->id;
                    modify_title(L->Tab_comics[comics_id], L->Tab_comics[comics_id+1]->title);
                    modify_author(L->Tab_comics[comics_id], L->Tab_comics[comics_id+1]->author);
                    modify_editor(L->Tab_comics[comics_id], L->Tab_comics[comics_id+1]->editor);
                    change_state_rate(L->Tab_comics[comics_id], L->Tab_comics[comics_id+1]->rate);
                    change_state_read(L->Tab_comics[comics_id], L->Tab_comics[comics_id+1]->read);
                    modify_comment(L->Tab_comics[comics_id], L->Tab_comics[comics_id+1]->comment);
                }
                delete_comics(L->Tab_comics[L->nbBooks-1]);
            }
            else{
                printf("\nThis comics is set to NULL.\n");
            }
        }
        else{
            printf("\nThis ID is not valid !!!\n");
        }
    }
    else{
        printf("\nThe Library does not exist or it is empty.\n");
    }
    return L;
}


//comment in there
void show_library(Library *L){
    int i;
    printf("\nId\t\tTitle\t\tAuthor\t\tEditor\n");
    printf("---\t\t------\t\t-------\t\t-------\n");

    //have to change this to implement refBook correctly
    for(i=0;i<L->nbBooks;i++){
        printf(" %d\t\t%s  \t%s \t%s\n",L->Tab_comics[i]->id,L->Tab_comics[i]->title,L->Tab_comics[i]->author,L->Tab_comics[i]->editor);
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
