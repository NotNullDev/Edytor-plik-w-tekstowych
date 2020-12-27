#ifndef WORDS_H
#define WORDS_H 1

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef const char *String;

typedef struct Element
{
    String value;
    struct Element *next;
} Element;

/*
    linked list of strings
*/
typedef Element *Words;

void printList(Words w);

Words initList();

void freeWords(Words words);

void removeAllElements(Words words);

void removeAllBeginWith(Words words, String sentence);

void removeEqualLength(Words words, int elementLength);

void removeLongerThan(Words words, int elementLength);

/*
    (next - previous - 1) elements will be deleted
    example: 

    insertBetween(["1","2","3","4","5"], "0", 0, 3) => ["1","0","4","5"]

    ----
*/
void insertBetween(Words words, String element, int previous, int next);

/*
    sorting by alphabetical order
*/
void sort(Words words);

void sortByLength(Words words);

void replaceAll(Words words, String oldWord, String newWord);

int getLength(Words words);

void removeByIndex(Words words, int index);

void addToList(Words words, String string);

void removeFirstElement(Words words);

void removeLastElement(Words words);

void connect(Words a, Words b);

/*
    remember to free list after it's not important anymore
*/
Words *wordsToArray(Words words);

String *wordsToStringsArray(Words words);

#endif