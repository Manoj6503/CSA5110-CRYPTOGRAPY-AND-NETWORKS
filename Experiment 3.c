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
void encrypt(char text[])
{
    int i;
    int r1, c1, r2, c2;
    char a, b;
    for(i = 0; text[i] != '\0'; i += 2)
    {
        a = text[i];
        b = text[i + 1];

        findPosition(a, &r1, &c1);
        findPosition(b, &r2, &c2);
        if(r1 == r2)
        {
            text[i]     = matrix[r1][(c1 + 1) % 5];
            text[i + 1] = matrix[r2][(c2 + 1) % 5];
        }
        else if(c1 == c2)
        {
            text[i]     = matrix[(r1 + 1) % 5][c1];
            text[i + 1] = matrix[(r2 + 1) % 5][c2];
        }
        else
        {
            text[i]     = matrix[r1][c2];
            text[i + 1] = matrix[r2][c1];
        }
    }
}
int main()
{
    char key[50], text[100];
    int i, len;
    printf("Enter the keyword: ");
    scanf("%s", key);
    createMatrix(key);
    printf("\nPlayfair Matrix:\n");
    for(i = 0; i < 5; i++)
    {
        for(int j = 0; j < 5; j++)
        {
            printf("%c ", matrix[i][j]);
        }
        printf("\n");
    }
    printf("\nEnter plaintext (even number of letters): ");
    scanf("%s", text);

    len = strlen(text);
    for(i = 0; i < len; i++)
    {
        text[i] = toupper(text[i]);

        if(text[i] == 'J')
            text[i] = 'I';
    }
    if(len % 2 != 0)
    {
        text[len] = 'X';
        text[len + 1] = '\0';
    }
    encrypt(text);
    printf("\nEncrypted text: %s\n", text);

    return 0;
}