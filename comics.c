#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "comics.h"

Comics *create_comics(char* author, char* title, char* editor){
	Comics *comics = (Comics*)malloc(sizeof(Comics));
	if(comics==NULL){
		printf("Erreur lors de la création du comics\n");
        	return NULL;
	}
	comics->author = strdup(author);
	comics->title = strdup(title);
	comics->editor = strdup(editor);
	comics->read = IDK;
	comics->rate = NR;
	return comics;
}

Comics *modify_title(Comics *comics, char* title){
	free(comics->title);
	comics->title = (char*)malloc(sizeof(char));
	strcpy(comics->title, title);
	return comics;
}

Comics *modify_author(Comics *comics, char* author){
	free(comics->author);
	comics->author = (char*)malloc(sizeof(char));
	strcpy(comics->author, author);
	return comics;
}

Comics *modify_editor(Comics *comics, char* editor){
	free(comics->editor);
	comics->editor = (char*)malloc(sizeof(char));
	strcpy(comics->editor, editor);
	return comics;
}

Comics *change_state_read(Comics *comics, Read read){
	if(read > -1 || read < 5){
		comics->read = read;
	}
	else{
		printf("Erreur de statut : lecture\n");
	}
	return comics;
}

Comics *change_state_rate(Comics *comics, Rate rate){
	if(rate < 0 || rate > 5){
		comics->rate = rate;
	}
	else{
		printf("Erreur de statut : rate\n");
	}
	return comics;
}

Comics *modify_comment(Comics *comics, char* comment){
	if(comics->comment){
		delete_comment(comics);
		comics->comment = (char*)malloc(sizeof(char));
		strcpy(comics->comment, comment);
	}
	else{
		comics->comment = (char*)malloc(sizeof(char));
		strcpy(comics->comment, comment);
	}
	return comics;
}

Comics *delete_comment(Comics *comics){
	if(comics->comment){
		free(comics->comment);
	}
	else{
		printf("Erreur suppression : aucun comment existant\n");
	}
	return comics;
}

void delete_comics(Comics *comics){
    free(comics->author);
    free(comics->title);
    free(comics->editor);
    if(comics->comment){
        free(comics->comment);
    }
    free(comics);
}
