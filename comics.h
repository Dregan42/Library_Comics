#ifndef __COMICS__
#define __COMICS__

typedef enum read {NO=0, YES, IDK} Read;
typedef enum rate {NR = -1, CRAP, VERY_BAD, BORING, GOOD_ENOUGH, GOOD, EXCELLENT} Rate;

typedef struct comics Comics;

typedef struct comics
	{
		int id;
		char* author;
		char* title;
		char* editor;
		Read read;
		Rate rate;
		char* comment;
	} Comics;

Comics *create_comics(char* author, char* title, char* editor); // Create a comic with an Author, a Title and an Editor. It initialize its States. Comments aren't initialized.

Comics *modify_title(Comics *comics, char* title); //change the current title.
Comics *modify_author(Comics *comics, char* author); //change the current author.
Comics *modify_editor(Comics *comics, char* editor); //change the current editor.

/*change states of read and rate*/
Comics *change_state_read(Comics *comics, Read read);
Comics *change_state_rate(Comics *comics, Rate rate);

/*create a comment if it does not exist or erase the current comment and change it by the comment passed by argument*/
Comics *modify_comment(Comics *comics, char* comment);
Comics *delete_comment(Comics *comics); // delete a comment and free the memory.

void delete_comics(Comics *comics); //free the memory space allocated for the deleted comic.
#endif
