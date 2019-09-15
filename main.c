#include <stdio.h>
#include <stdlib.h>
#include <string.h>

FILE *given;
FILE *crypt;

void Encrypt(int key, char *name, char text[2048])
{
    int counter = 0;
    given = fopen(name, "r");
    if (given != NULL)
    {
        while (1)
        {
            fscanf(given, "%c", &text[counter]);
            counter++;
            if (feof(given))
            {
                break;
            }
        }
        fclose(given);

        char *extension = ".enc";  //This adds to out file a postfix so we know it's enccrypted
        strncat(name, extension, sizeof(name) + sizeof(extension)); //Concatenates the extension to our name
        crypt = fopen(name, "w");
        for (int i = 0; i < counter; i++)
        {
            text[i] += key;
            fprintf(crypt, "%c", text[i]);
        }
        printf("*****ENCRYPTED*****\n");
    }
    else
    {
        printf("Doesn't exist!\n");
        return -1;
    }
}

void Decrpyt(int key, char *name, char text[2048])
{
    int counter = 0;
    given = fopen(name, "r");
    if (given != NULL)
    {
        while (1)
        {
            fscanf(given, "%c", &text[counter]);
            counter++;
            if (feof(given))
            {
                break;
            }
        }
        fclose(given);

        char *extension = ".dec";
        strncat(name, extension, sizeof(name) + sizeof(extension));
        crypt = fopen(name, "w");
        for (int i = 0; i < counter; i++)
        {
            text[i] -= key;
            fprintf(crypt, "%c", text[i]);
        }
        printf("*****DEENCRYPTED*****\n");
    }
    else
    {
        printf("Doesn't exist!\n");
        return -1;
    }
}

int main()
{
    int x, key;
    char *name = malloc(sizeof(char) * 128);
    char text[2048];

    printf("1.Encrypt\n2.Decrypt\n:");
    scanf("%d", &x);
    printf("Enter the key you want to use: ");
    scanf("%d", &key);
    printf("Enter the name of the file:");
    scanf("%s", name);

    realloc(name, sizeof(char) * strlen(name));

    if (x == 1) { Encrypt(key, name, text); }
    else if (x == 2) { Decrpyt(key, name, text); }
    else { printf("Bad input!\n"); return -1; }

    return 0;
}