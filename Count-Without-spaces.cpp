#include <stdio.h>
#include <conio.h>

int main()
{
    int nc=0,i;
    char c[90];
    clrscr();
    gets(c);

    for (i=0; c[i]!='\0'; ++i) {
        if(c[i]!=' ')
            ++nc;
    }
    printf ( "%d\n" ,nc);

    getch();
    return 0;
}
