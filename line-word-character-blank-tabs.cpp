/*
DOS utility or Command-line Utility
To count number of lines , words,character,blanks and tabs in the file
Usage : my_count <InputTextFile>

IN & OUT represent whether the file pointer is inside or outside of a word
*/

#include <stdio.h>
#include <conio.h>
#define IN 1
#define OUT 0


int main(int argc,char* argv[])
{

    int c, nl, nw, nc,nb,nt, state;

    state = OUT;
    nl=nw=nc=nb=nt=0;
    FILE *fp = fopen(argv[1], "r");

    while ((c = fgetc(fp)) != EOF) {
        if(c!=' ')
            ++nc;
        if(c==' ')
            ++nb;
        if(c=='\t')
            ++nt;
        if ( c == '\n' )
            ++nl;
        if (c == ' ' || c == '\n' || c == '\t')
            state = OUT;
        else if (state == OUT) {
            state = IN;
            ++nw;
        }
    }
    printf("The line count , word count ,character count,blanks, tabs respectively are\n");
    printf ( "%d %d %d %d %d\n" , nl+1, nw, nc,nb,nt) ;
    getch();
    return 0;
}

