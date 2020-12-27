#include <stdio.h>
#include <stdlib.h>

#include "words.h"

#define MAXLINE 100
#define MAXFILEWORDS 10000

int main(void)
{
    FILE *fp;
    char nazwaPliku[MAXLINE];
    char *words[MAXFILEWORDS];
    int len;
    /*
    do
    {
        printf("Podaj nazwe pliku do wczytania: ");
        if (scanf("%s", nazwaPliku) != 1)
        {
            printf("Niepoprawny format nazwy pliku!\n");
            continue;
        }
        break;
    } while (1);
    */
    fp = fopen(nazwaPliku, "w");
    fputs("hehe", fp);
    fputs("oooo", fp);
    fputs("eeeeee", fp);
    fclose(fp);
    fp = fopen(nazwaPliku, "r");
    if (!fp)
    {
        printf("Nie udalo sie otworzyc pliku %s.\n", nazwaPliku);
        return 1;
    }
    rewind(fp);
    len = 0;
    while (fscanf(fp, "%s", words[len++]) > 0)
        ;
    if (len == 1)
        printf("rerere");
    for (int i = 0; i < len - 1; i++)
    {
        printf("%s\n", words[i]);
    }
    fclose(fp);

    return 0;
}
/*
prototype?
List strings;
String strings[0];
int length = strings.length;

*/