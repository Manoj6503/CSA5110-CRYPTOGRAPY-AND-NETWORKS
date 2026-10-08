#include <stdio.h>
#include <string.h>
#include <ctype.h>
int main()
{
    char text[100], key[100];
    int i, j = 0;
    int shift;
    printf("Enter the plaintext: ");
    scanf("%s", text);
    printf("Enter the key: ");
    scanf("%s", key);
    for(i = 0; text[i] != '\0'; i++)
    {
        if(isalpha(text[i]))
        {
            shift = toupper(key[j]) - 'A';

            text[i] = ((toupper(text[i]) - 'A' + shift) % 26) + 'A';

            j++;

            if(key[j] == '\0')
                j = 0;
        }
    }
    printf("Encrypted text: %s\n", text);
    return 0;
}