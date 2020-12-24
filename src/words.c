#include "words.h"

void addToList(Words words, String string)
{
    if (!words)
    {
        printf("Error: call initList() on list before adding any items.\n");
        return;
    }

    if (!words->value)
    {
        words->value = string;
        return;
    }

    Words current = words;

    while (current->next != NULL)
        current = current->next;

    current->next = (Words)malloc(sizeof(Words));

    current->next->value = string;
    current->next->next = NULL;
}

/*
    return empty linked list
*/
Words initList()
{
    Words w;
    w = (Words)malloc(sizeof(Words));
    w->next = NULL;
    w->value = NULL;
    return w;
}

void removeAllElements(Words words)
{

    while (words->next != NULL)
    {
        removeAllElements(words + 1);
    }
    free(words);
}

void printList(Words w)
{
    if (!w)
    {
        printf("No items in list.\n");
        return;
    }
    int currentIndex = 0;
    Words current = w;
    do
    {
        printf("item %d: %s\n", currentIndex++, current->value);
        current = current->next;
    } while (current);
}

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

void removeFirstElement(Words words);

void removeLastElement(Words words)
{
    if (!words)
        return;
    Words current = words;
    Words previous = NULL;
    while (current->next != NULL)
    {
        previous = current;
        current = current->next;
    }
    free(current);
    if (previous)
    {
        previous->next = NULL;
    }
}

void connect(Words a, Words b);