#include <stdio.h>
#include <stdlib.h>

#include "comics.h"
#include "library.h"

void show_menu(){
	printf("\n\t MENU\n");
	printf("\t======\n\n");
	printf("1 - show : Show the library\n");
	printf("2 - details : Show one comic book\n");
	printf("3 - add : Add one book to the library\n");
	printf("4 - remove : Remove one book to the library\n");
	printf("5 - modify : Modify one comic book\n");
	printf("9 - menu : show the menu\n");
	printf("0 - quit : Exit the program\n\n");
}

int main(int argc, char **argv){

	printf("\t\t|======================|\n");
	printf("\t\t|= MY COMICS' LIBRARY =|\n");
	printf("\t\t|======================|\n");
	printf("\t\t\t\t\tby Alexandre Turrel\n");

    Library *L = create_library(); //creation of an empty Library

	int choice = 9; //choice is initialized to 9 to show the menu first.
	int id_choice; //used to choose a specific comics in the Library.

	while(choice){
		switch(choice){
			case 0:
				printf("\nBye.\n");
            break;

			case 1:
				if(L->nbBooks != 0){
					show_library(L);
				}
				else{
                    printf("The library is empty.\n");
				}
            break;

			case 2:
                if(L && (L->nbBooks != 0)){
                    printf("\nComics' Id :");
                        if(scanf("%d",&id_choice)!=1){
                            printf("Invalid choice : Wrong format.\n");
                        	exit(1);
                        }
                    	if(id_choice<L->counter)
                        	show_comics(L, (L->Tab_comics[id_choice]->id));
                        else
                            printf("This ID is incorrect.\n");
                }
                else{
                    printf("The library is empty.\n");
                }
            break;

			case 3:
                if(L){
                    L = add_comics_to_library(L);
                }
            break;

            case 4: //remove a comics from the library
                if(L && (L->nbBooks != 0)){
                    printf("\nComics' Id :");
                        if(scanf("%d",&id_choice)!=1){
                            printf("Invalid choice : Wrong format.");
                        	exit(1);
                        }
                    L = remove_comics_from_library(L, (L->Tab_comics[id_choice]->id));
                }
            break;

            case 5:
            break;

            case 9:
                show_menu();
            break;

            default:
                printf("\nThis option does not exist. Please try again. \"9\" shows the menu.\n");
			}
        //the variable choice is changed in this block.
        printf("\nWhat do you want to do ? ");
        if((scanf("%d",&choice))!=1){
            printf("\nInvalid choice : Wrong format.\n");
            exit(1);
        }
	}

	return 0;
}
