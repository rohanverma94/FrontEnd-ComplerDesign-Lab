#include <string.h>
#include <stdio.h>
#include <conio.h>
int main()
{
    char str[80];
    const char s[2] = "-";
    char *token;
    clrscr();
    printf("Enter String for tokenization:  ");
    gets(str);
    token = strtok(str, s);


    while( token != NULL )
    {
        printf( " %s\n", token );

        token = strtok(NULL, s);
    }
    getch();
    return(0);
}


