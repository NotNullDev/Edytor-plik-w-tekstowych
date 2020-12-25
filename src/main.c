#include "print.h"
#include "words.h"

int main(void)
{
    Words words = initList();
    addToList(words, "Item0 sdaf");
    addToList(words, "Item1 sdaf");
    printList(words);
    removeFirstElement(words);

    printList(words);

    return 0;
}
/*
prototype?
List strings;
String strings[0];
int length = strings.length;

*/