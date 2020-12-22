#ifndef WORDS_H
#define WORDS_H 1

#define WORDS_ERROR -1

typedef const char *String;

typedef struct Element
{
    String element;
    Element *next;
} Element;

typedef Element *Words;

/*
    return amount of elements in list
    retrun WORDS_ERROR on error
*/
int removeAllElements(Words words);

int removeAllBeginWith(Words words, String sentence);

int removeEqualLength(Words words, int elementLength);

int removeLongerThan(Words words, int elementLength);

int insertBetween(Words words, String element, int previous, int next);

/*
    sorting by alphabetical order
*/
int sort(Words words);

int sortByLength(Words Words);

int replaceAll(Words words, String oldWord, String newWord);

int getLength(Words words);

int removeByIndex(Words words, int index);

int append(Words words, String string);

void removeFirstElement(Words words);

void removeLastElement(Words words);

void connect(Words a, Words b);

#endif