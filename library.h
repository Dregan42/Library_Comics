#ifndef __LIBRARY__
#define __LIBRARY__

#include "comics.h"

typedef struct library Library;

//beginning of the implementation of a chained list
//
//typedef struct refBook
//    {
//        Comics* refComics;
//        Comics* next;
//    } RefBook;

typedef struct library
	{
        int counter; //variable used to create unique IDs
		int nbBooks;
		int nbBookMax;
		Comics** Tab_comics;
	} Library;

Library* create_library(); //create an empty library with a capacity of 1024 books max.
Library* add_comics_to_library(Library *L); // create a regular comic and add it to the current library and give to it an ID.
Library* remove_comics_from_library(Library* L,int comics_id); //remove a specific comic to the library and desallocate its memory. The comic is destroyed.
void show_library(Library *L); //show line by line the books in the library. It shows only its ID, title and author.
void show_comics(Library *L, int comics_id); // show all informations about the comic with the ID comics_id. ID, Title, Author, Editor, States and Comments.


#endif
