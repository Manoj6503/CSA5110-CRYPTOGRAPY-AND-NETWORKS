#include <stdio.h>
#include <string.h>
#include <ctype.h>
char matrix[5][5] =
{
    {'M', 'F', 'H', 'I', 'K'},
    {'U', 'N', 'O', 'P', 'Q'},
    {'Z', 'V', 'W', 'X', 'Y'},
    {'E', 'L', 'A', 'R', 'G'},
    {'D', 'S', 'T', 'B', 'C'}
};
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
void prepareText(char input[], char output[])
{
    int i, j = 0;
    char ch;

    for(i = 0; input[i] != '\0'; i++)
    {
        if(isalpha(input[i]))
        {
            ch = toupper(input[i]);

            if(ch == 'J')
                ch = 'I';

            output[j++] = ch;
        }
    }
    output[j] = '\0';
}
void encrypt(char text[], char result[])
{
    int i, j = 0;
    int r1, c1, r2, c2;
    char a, b;
    for(i = 0; text[i] != '\0'; i += 2)
    {
        a = text[i];
        if(text[i + 1] == '\0')
            b = 'X';
        else
            b = text[i + 1];
        if(a == b)
        {
            b = 'X';
            i--;
        }
        findPosition(a, &r1, &c1);
        findPosition(b, &r2, &c2);
        if(r1 == r2)
        {
            result[j++] = matrix[r1][(c1 + 1) % 5];
            result[j++] = matrix[r2][(c2 + 1) % 5];
        }
        else if(c1 == c2)
        {
            result[j++] = matrix[(r1 + 1) % 5][c1];
            result[j++] = matrix[(r2 + 1) % 5][c2];
        }
        else
        {
            result[j++] = matrix[r1][c2];
            result[j++] = matrix[r2][c1];
        }
    }
    result[j] = '\0';
}
int main()
{
    char input[200];
    char text[200];
    char encrypted[200];
    printf("Enter the message:\n");
    fgets(input, sizeof(input), stdin);
    prepareText(input, text);
    encrypt(text, encrypted);
    printf("\nPrepared text: %s\n", text);
    printf("Encrypted text: %s\n", encrypted);
    return 0;
}