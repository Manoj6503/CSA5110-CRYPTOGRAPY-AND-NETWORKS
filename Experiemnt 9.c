#include <stdio.h>
#include <string.h>
#include <ctype.h>
char matrix[5][5];
void createMatrix(char key[])
{
    int used[26] = {0};
    int i, j, k = 0;
    char ch;
    used['J' - 'A'] = 1;

    for(i = 0; key[i] != '\0'; i++)
    {
        ch = toupper(key[i]);

        if(ch == 'J')
            ch = 'I';

        if(ch >= 'A' && ch <= 'Z' && used[ch - 'A'] == 0)
        {
            matrix[k / 5][k % 5] = ch;
            used[ch - 'A'] = 1;
            k++;
        }
    }
    for(ch = 'A'; ch <= 'Z'; ch++)
    {
        if(used[ch - 'A'] == 0)
        {
            matrix[k / 5][k % 5] = ch;
            used[ch - 'A'] = 1;
            k++;
        }
    }
}
void findPosition(char ch, int *row, int *col)
{
    int i, j;
    if(ch == 'J')
        ch = 'I';

    for(i = 0; i < 5; i++)
    {
        for(j = 0; j < 5; j++)
        {
            if(matrix[i][j] == ch)
            {
                *row = i;
                *col = j;
                return;
            }
        }
    }
}
void decrypt(char text[])
{
    int i;
    int r1, c1, r2, c2;
    for(i = 0; text[i] != '\0'; i += 2)
    {
        findPosition(text[i], &r1, &c1);
        findPosition(text[i + 1], &r2, &c2);
        if(r1 == r2)
        {
            text[i] = matrix[r1][(c1 + 4) % 5];
            text[i + 1] = matrix[r2][(c2 + 4) % 5];
        }
        else if(c1 == c2)
        {
            text[i] = matrix[(r1 + 4) % 5][c1];
            text[i + 1] = matrix[(r2 + 4) % 5][c2];
        }
        else
        {
            text[i] = matrix[r1][c2];
            text[i + 1] = matrix[r2][c1];
        }
    }
}
int main()
{
    char key[100];
    char cipher[200];
    int i, j;
    printf("Enter the key: ");
    fgets(key, sizeof(key), stdin);
    printf("Enter the ciphertext:\n");
    fgets(cipher, sizeof(cipher), stdin);
    j = 0;
    for(i = 0; cipher[i] != '\0'; i++)
    {
        if(isalpha(cipher[i]))
        {
            cipher[j++] = toupper(cipher[i]);
        }
    }
    cipher[j] = '\0';
    createMatrix(key);
    printf("\nPlayfair Matrix:\n");
    for(i = 0; i < 5; i++)
    {
        for(j = 0; j < 5; j++)
        {
            printf("%c ", matrix[i][j]);
        }
        printf("\n");
    }
    decrypt(cipher);
    printf("\nDecrypted text:\n%s\n", cipher);
    return 0;
}