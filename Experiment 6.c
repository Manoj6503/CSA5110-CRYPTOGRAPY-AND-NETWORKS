#include <stdio.h>
#include <ctype.h>
int main()
{
    char cipher[100];
    char plain[100];
    int i, c, p;
    int a = 3, b = 15;
    int inverse_a = 9;
    printf("Enter the ciphertext: ");
    scanf("%s", cipher);
    for(i = 0; cipher[i] != '\0'; i++)
    {
        c = toupper(cipher[i]) - 'A';

        /* Decryption: p = a^-1 (c - b) mod 26 */
        p = (inverse_a * (c - b)) % 26;

        if(p < 0)
            p = p + 26;

        plain[i] = p + 'A';
    }
    plain[i] = '\0';
    printf("Decrypted text: %s\n", plain);
    return 0;
}