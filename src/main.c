#include "print.h"
#include "words.h"

int main(void)
{
    Words words = initList();
    addToList(words, "12345");
    addToList(words, "hehe");
    addToList(words, "12345");
    addToList(words, "12345");

    // addToList(words, "12345");
    // addToList(words, "Item0 sdaf");
    // addToList(words, "12345");
    // addToList(words, "Item1 sdaf");
    // addToList(words, "12345");
    // addToList(words, "12345");
    // addToList(words, "Item2 sdaf");
    // addToList(words, "12345");
    // addToList(words, "12345");
    printList(words);
    removeAllBeginWith(words, "he");

    printList(words);

    return 0;
}
/*
prototype?
List strings;
String strings[0];
int length = strings.length;

*/