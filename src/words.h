#ifndef WORDS_H
#define WORDS_H 1
typedef const char *String;
typedef struct Element
{
    String element;
    Element *next;
    int length();
    /*
        return 1 on success
        return 0 on failure
    */
    int remove(int id);
    /*
        return 1 on success
        return 0 on failure
    */
    int removeLast();
    /*
        return 1 on success
        return 0 on failure
    */
    int removeFirst();
} Element;

typedef Element *Words;
#endif