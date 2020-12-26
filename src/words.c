#include "words.h"

//done
void addToList(Words words, String string)
{
    if (!words)
    {
        printf("Error: call initList() on object before adding any items.\n");
        return;
    }

    if (!words->value)
    {
        words->value = string;
        words->next = NULL;
        return;
    }

    Words current = words;

    while (current->next != NULL)
        current = current->next;

    current->next = (Words)malloc(sizeof(Words));

    current->next->value = string;
    current->next->next = NULL;
}

//done
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

/*
    freeing list object - if it's not empty it's clear it first
*/
void freeWords(Words words)
{
    int len = getLength(words);
    if (!len)
    {
        free(words);
        return;
    }
    removeAllElements(words);
    free(words);
    words = NULL;
}

/*
    remove all elements of the list
    this function DOES NOT list object - use deinit() instead
    list becane empty
*/
void removeAllElements(Words words)
{
    int len, i;

    len = getLength(words);

    if (!len)
        return;

    Words toRemove[len];

    toRemove[0] = words;

    for (i = 1; i < len; i++)
    {
        toRemove[i] = toRemove[i - 1]->next;
    }

    for (i = len - 1; i >= 0; i--)
    {
        if (i == 0)
        {
            toRemove[i]->value = NULL;
            toRemove[i]->next = NULL;
            break;
        }
        free(toRemove[i]);
    }
}

/*
    after freeing list memory it makes program crash
*/
void printList(Words w)
{
    if (!w->value)
    {
        printf("No items in list.\n");
        return;
    }
    int currentIndex = 0;
    Words current = w;
    do
    {
        if (current->value == NULL)
            break;
        printf("item %d: %s\n", currentIndex++, current->value);
        current = current->next;
    } while (current);
}

void removeAllBeginWith(Words words, String sentence)
{
    if (!words)
        return;

    Words *wordsArray, toRemove;
    int len;

    wordsArray = wordsToArray(words);
    len = getLength(words);

    if (len < 1)
        return;
    for (int i = 0; i < len; i++)
    {
        while (!strncmp(wordsArray[i]->value, sentence, strlen(sentence)))
        {
            if (i == 0)
            {
                if (len == 1)
                {

                    removeAllElements(words);
                    return;
                }

                removeFirstElement(words);
                wordsArray = wordsToArray(words);
                len--;
                continue;
            }
            if (i == len - 1)
            {
                removeLastElement(words);
                return;
            }
            toRemove = wordsArray[i];
            wordsArray[i - 1]->next = wordsArray[i + 1];
            free(toRemove);
            wordsArray = wordsToArray(words);
            len--;
        }
    }
}

void removeEqualLength(Words words, int elementLength)
{
    if (!words)
        return;

    Words *wordsArray, toRemove;
    int len;

    wordsArray = wordsToArray(words);
    len = getLength(words);

    if (len < 1)
        return;
    for (int i = 0; i < len; i++)
    {
        while (strlen(wordsArray[i]->value) == elementLength)
        {
            if (i == 0)
            {
                if (len == 1)
                {

                    removeAllElements(words);
                    return;
                }

                removeFirstElement(words);
                wordsArray = wordsToArray(words);
                len--;
                continue;
            }
            if (i == len - 1)
            {
                removeLastElement(words);
                return;
            }
            toRemove = wordsArray[i];
            wordsArray[i - 1]->next = wordsArray[i + 1];
            free(toRemove);
            wordsArray = wordsToArray(words);
            len--;
        }
    }
}
void removeLongerThan(Words words, int elementLength)
{
    if (!words)
        return;

    Words *wordsArray, toRemove;
    int len;

    wordsArray = wordsToArray(words);
    len = getLength(words);

    if (len < 1)
        return;
    for (int i = 0; i < len; i++)
    {
        while (strlen(wordsArray[i]->value) > elementLength)
        {
            if (i == 0)
            {
                if (len == 1)
                {
                    removeAllElements(words);
                    return;
                }
                removeFirstElement(words);
                wordsArray = wordsToArray(words);
                len--;
                continue;
            }
            if (i == len - 1)
            {
                removeLastElement(words);
                return;
            }
            toRemove = wordsArray[i];
            wordsArray[i - 1]->next = wordsArray[i + 1];
            free(toRemove);
            wordsArray = wordsToArray(words);
            len--;
        }
    }
}

/*
    (next - previous - 1) elements will be deleted
    example: 

    insertBetween(["1","2","3","4","5"], "0", 0, 3) => ["1","0","4","5"]

    ----
*/
void insertBetween(Words words, String element, int previous, int next)
{
    int len;
    Words *wordsArray, newWord;

    len = getLength(words);
    if (previous < 0 || next < 0 || previous > next || previous == next || next > len - 1)
        return;

    newWord = (Words)malloc(sizeof(Words));
    newWord->value = element;
    wordsArray = wordsToArray(words);
    wordsArray[previous]->next = newWord;
    newWord->next = wordsArray[next];
}
/*
    ala
    ben

*/
int cmpalpha(const void *a, const void *b)
{
    String first = (*(Words *)a)->value;
    String second = (*(Words *)b)->value;
    for (int i = 0; i < strlen(first); i++)
    {
        if (first[i] >= 'a' && first[i] <= 'z')
        {
            if (first[i] == second[i])
            {
                continue;
            }
            if (second[i] >= 'a' && second[i] <= 'z')
            {
                if (first[i] < second[i])
                    return 1;
                else
                    return -1;
            }
            if (second[i] >= 'A' && second[i] <= 'Z')
                return 1;
            //if its sign then its lower
            else
                return -1;
        }
        else if (first[i] >= 'Z' && first[i] <= 'Z')
        {
            if (first[i] == second[i])
            {
                continue;
            }
            if (second[i] >= 'A' && second[i] <= 'Z')
            {
                if (first[i] < second[i])
                    return 1;
                else
                    return -1;
            }
            // if (second[i] >= 'a' && second[i] <= 'z')
            //     return -1;
            // else
            //     return -1
            return -1;
        }
        else
        {
            if (first[i] == second[i])
            {
                continue;
            }
            if (first[i] > second[i])
                return -1;
            return 1;
        }
    }
    return 0;
}

int cmpLength(const void *a, const void *b)
{
    return strcmp((*(Words *)a)->value, (*(Words *)b)->value);
}
/*
    sorting by alphabetical order
*/
void sort(Words words)
{
    Words *wordsArray = wordsToArray(words);
    int len = getLength(words);
    Words current;
    qsort(wordsArray, len, sizeof(Words), cmpalpha);
    current = words;
    for (int i = 0; i < len; i++)
    {
        current->value = wordsArray[i]->value;
    }
    free(wordsArray);
}

void sortByLength(Words words)
{
    Words *wordsArray = wordsToArray(words);
    int len = getLength(words);
    Words current;
    qsort(wordsArray, len, sizeof(Words), cmpLength);
    current = words;
    for (int i = 0; i < len; i++)
    {
        current->value = wordsArray[i]->value;
    }
    free(wordsArray);
}

void replaceAll(Words words, String oldWord, String newWord)
{
    if (!words)
        return;

    Words *wordsArray, toRemove;
    int len;

    wordsArray = wordsToArray(words);
    len = getLength(words);

    if (len < 1)
        return;
    for (int i = 0; i < len; i++)
    {
        if (!strcmp(wordsArray[i]->value, oldWord))
        {
            wordsArray[i]->value = newWord;
        }
    }
}

//done
int getLength(Words words)
{
    if (!words->value)
        return 0;
    int length = 1;
    Words w = words->next;
    while (w)
    {
        w = w->next;
        length++;
    }
    return length;
}

void removeByIndex(Words words, int index)
{
    Words *array;
    int len;

    len = getLength(words);
    if (index > len - 1)
        return;
    array = wordsToArray(words);
    if (index = len - 1)

        array[index - 1]->next = NULL;
    else
        array[index - 1]->next = array[index + 1];
    free(array[index]);
}

/*
    copy first into second
    delete second
    now first is poiting to third and have value of second so,
    value of first is gone and flow is kept
*/
void removeFirstElement(Words words)
{
    int len = getLength(words);
    Words toDelete;
    if (len < 2)
        return;
    toDelete = words->next;
    words->value = words->next->value;
    words->next = words->next->next;
    free(toDelete);
}

//done
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

void connect(Words a, Words b)
{
    if (!a || !b)
        return;
    Words last = a;
    while (last->next)
        last = last->next;
    last->next = b;
}

Words *wordsToArray(Words words)
{
    int len;
    Words currentWord, *wordsArray;

    len = getLength(words);
    wordsArray = (Words *)malloc(len * sizeof(Words));

    currentWord = words;
    for (int i = 0; i < len; i++)
    {
        wordsArray[i] = currentWord;
        currentWord = currentWord->next;
    }
    return wordsArray;
}