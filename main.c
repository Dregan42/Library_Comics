#include <stdio.h>
#include <stdlib.h>

#include "comics.h"
#include "library.h"

int show_menu(int choice){
    int rep;
	printf("\n\t MENU\n");
	printf("\t======\n\n");
	printf("1 - show : Show the library\n");
	printf("2 - details : Show one comic book\n");
	printf("3 - add : Add one book to the library\n");
	printf("4 - remove : Remove one book to the library\n");
	printf("5 - modify : Modify one comic book\n");
	printf("0 - quit : Exit the program\n\n");
	printf("What do you want to do ? ");

    if((scanf("%d",&choice))!=1){
        printf("\nInvalid choice : Wrong format.\n");
        exit(1);
    }
    rep = choice;
    return rep;
}

int main(int argc, char **argv){

	printf("\t\t|====================|\n");
	printf("\t\t|= COMICS INVENTORY =|\n");
	printf("\t\t|====================|\n");
	printf("\t\t\t\t\tby Alexandre Turrel\n");

    Library *L = create_library();

	int choice, id_choice;

	do{

		choice = show_menu(choice);
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
                    if(scanf("%d",&id_choice)!=1){
                        printf("Invalid choice : Wrong format.");
                        exit(1);
                    }
                    if(id_choice<=L->nbBooks)
                        show_comics((L->Tab_comics[id_choice]->id));
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
            case 4:
                break;
            case 5:
                break;
            default:
                printf("\nThis option does not exist. Please try again.\n");
		}
	}while(choice);

	return 0;
}
