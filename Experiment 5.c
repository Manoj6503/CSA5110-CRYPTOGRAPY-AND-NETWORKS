#include <stdio.h>
#include <string.h>
#include <ctype.h>
int gcd(int a, int b)
{
    while(b != 0)
    {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}
int main()
{
    char text[100];
    int a, b, i, p, c;
    printf("Enter the plaintext: ");
    scanf("%s", text);
    printf("Enter value of a: ");
    scanf("%d", &a);
    printf("Enter value of b: ");
    scanf("%d", &b);
    if(gcd(a, 26) != 1)
    {
        printf("Invalid value of a!\n");
        printf("a must be relatively prime to 26.\n");
        return 0;
    }
    for(i = 0; text[i] != '\0'; i++)
    {
        if(isalpha(text[i]))
        {
            p = toupper(text[i]) - 'A';

            c = (a * p + b) % 26;

            text[i] = c + 'A';
        }
    }
    printf("Encrypted text: %s\n", text);
    return 0;
}