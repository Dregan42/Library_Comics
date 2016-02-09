#include <stdio.h>
#include <stdlib.h>

#include "comics.h"
#include "library.h"

void show_menu(int* val){
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
	do{
            scanf("%d",&rep);
            if(scanf("%d",&rep) != 1){
                printf("Entry Error. Please try again.");
            }
	}while(scanf("%d",&rep) != 1);
	*val = rep;
}

int main(int argc, char **argv){

	printf("\t\t|====================|\n");
	printf("\t\t|= COMICS INVENTORY =|\n");
	printf("\t\t|====================|\n");
	printf("\t\t\t\t\tby Alexandre Turrel\n");

    Library *L = create_library();

	int choice;

	do{

		show_menu(&choice);
		switch(choice){
			case 0:
				printf("\nBye.\n");
				break;
			case 1:
				if(1){
					show_library(L);
				}
				break;
			case 2:
                break;
			case 3:
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
