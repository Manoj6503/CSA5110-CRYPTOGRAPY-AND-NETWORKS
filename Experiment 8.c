#include <stdio.h>
#include <string.h>
#include <ctype.h>
int main()
{
    char keyword[50];
    char plaintext[100];
    char cipher[27];
    int used[26] = {0};
    int i, j = 0;
    char ch;
    printf("Enter the keyword: ");
    scanf("%s", keyword);
    for(i = 0; keyword[i] != '\0'; i++)
    {
        ch = toupper(keyword[i]);

        if(ch >= 'A' && ch <= 'Z' && used[ch - 'A'] == 0)
        {
            cipher[j] = ch;
            used[ch - 'A'] = 1;
            j++;
        }
    }
    for(ch = 'A'; ch <= 'Z'; ch++)
    {
        if(used[ch - 'A'] == 0)
        {
            cipher[j] = ch;
            used[ch - 'A'] = 1;
            j++;
        }
    }
    cipher[j] = '\0';
    printf("\nPlain : ABCDEFGHIJKLMNOPQRSTUVWXYZ\n");
    printf("Cipher: %s\n", cipher);

    printf("\nEnter the plaintext: ");
    scanf("%s", plaintext);

    /* Encryption */
    for(i = 0; plaintext[i] != '\0'; i++)
    {
        if(plaintext[i] >= 'a' && plaintext[i] <= 'z')
            plaintext[i] = plaintext[i] - 'a' + 'A';

        if(plaintext[i] >= 'A' && plaintext[i] <= 'Z')
            plaintext[i] = cipher[plaintext[i] - 'A'];
    }
    printf("Ciphertext: %s\n", plaintext);
    return 0;
}