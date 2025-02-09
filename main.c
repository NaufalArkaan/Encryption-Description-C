#include <stdio.h>
#include <string.h>
#include <process.h>

int main()
{
    int choose;
    while (1)
    {
        printf("\n==== Welcome ====\n");
        printf("Select menu: \n");
        printf("1. Encryption\n");
        printf("2. Description\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choose);
        fflush(stdin); // clears or discards all remaining characters in the standard input buffer (stdin).

        switch (choose)
        {
        case 1:
            encryption();
            break;
        case 2:
            description();
            break;
        case 3:
            exit(0);
            break;
        default:
            printf("System Invalid!.\n");
            break;
        }
    }
    return 0;
}

void encryption()
{
    int a, b, c;
    char text[100], key[100];

    printf("Enter the text you want to encrypt without space (maximum 100 letters): ");
    scanf("%[^\n]", &text);
    printf("Input key (maximum 100 letters): ");
    fflush(stdin); // clears or discards all remaining characters in the standard input buffer (stdin).
    scanf("%[^\n]", &key);
    printf("Encryption result: \n");
    for (a = 0, b = 0; a < strlen(text); a++, b++)
    {
        if (b >= strlen(key))
        {
            b = 0;
        }
        c = (((toupper(text[a])) + (toupper(key[b]))) % 26) + 65;
        printf("%c", c);
    }
    printf("\n\n");
}

void description()
{
    int a, b, c;
    char text[100], key[100];

    printf("Enter the text you want to description without space (maximum 100 letters): ");
    scanf("%[^\n]", &text);
    printf("Input key (maximum 100 letters): ");
    fflush(stdin); // clears or discards all remaining characters in the standard input buffer (stdin).
    scanf("%[^\n]", &key);
    printf("Description result: \n");
    for (a = 0, b = 0; a < strlen(text); a++, b++)
    {
        if (b >= strlen(key))
        {
            b = 0;
        }
        c = (toupper(text[a]) - 64) - (toupper(key[b]) - 64);
        if (c < 0)
        {
            c = 26 + c;
        }
        printf("%c", 65 + (c % 26));
    }
    printf("\n\n");
}