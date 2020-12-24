#include "print.h"
#include "words.h"

int main(void)
{
    Words words = initList();
    addToList(words, "Item1 sdaf");
    addToList(words, "Item2 sdaf");
    addToList(words, "Item3 sdaf");
    addToList(words, "Item4 sdaf");

    printList(words);
    addToList(words, "Item5 sdaf");
    printList(words);
    removeAllElements(words);
    printList(words);
    return 0;
}
/*
prototype?
List strings;
String strings[0];
int length = strings.length;

*/