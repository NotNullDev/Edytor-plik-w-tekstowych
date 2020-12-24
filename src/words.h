#ifndef WORDS_H
#define WORDS_H 1

#define WORDS_ERROR -1
#include <stdlib.h>
#include <stdio.h>
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

void removeAllElements(Words words);

int removeAllBeginWith(Words words, String sentence);

int removeEqualLength(Words words, int elementLength);

int removeLongerThan(Words words, int elementLength);

/*
    (next - previous - 1) elements will be deleted
    example: 

    insertBetween(["1","2","3","4","5"], "0", 0, 3) => ["1","0","4","5"]

    ----
*/
int insertBetween(Words words, String element, int previous, int next);

/*
    sorting by alphabetical order
*/
int sort(Words words);

int sortByLength(Words Words);

int replaceAll(Words words, String oldWord, String newWord);

int getLength(Words words);

int removeByIndex(Words words, int index);

void addToList(Words words, String string);

void removeFirstElement(Words words);

void removeLastElement(Words words);

void connect(Words a, Words b);

#endif