/*
Author: Rohan Verma
Compiler Construction
Code :LEX parser/Token Recognizer/Scanner

Usage : scanner <InputTextFile>

*/

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <conio.h>

enum {Ident_max = 16};
typedef char Ident[Ident_max+1];

typedef enum {
    null, times, plus, rparen, lparen, number, identifier, eofsym,sstring,
    keyword,delimeter,assign
} Symbol;
int m=0;
class Scanner {
public:
    int init(const char fn[]);
    Symbol getsym();
    int getval() {
        return val;
    }
    int l[Ident_max];
    enum {KW=25};
    char *keyTab[KW+1];
    int p;
private:
    void read_ch();
    Symbol get_token();
    Symbol get_number();
    void TableEntry(Symbol sym, Ident name);



    int val;
    Ident id;
    int ch;
    int new_keyword;

    Symbol keySym[KW+1];
    FILE *f;
};

void Scanner::read_ch() {
    ch = fgetc(f);
    if (ch != EOF)
        putchar((char)ch);
}

Symbol Scanner::get_token() {
    int i;
    p++;
    i = 0;
    do {
        if (i < Ident_max) {
            id[i] = (char)ch;
            i++;
        }
        read_ch();
    } while (ch != EOF && isalnum(ch));
    id[i] = '\0';
    for (i = 0; i < new_keyword && strcmp(id, keyTab[i]) != 0; i++)
        ;
    l[p]=i;
    if(strcmp(id,keyTab[i])!=0 && m==0)
        return identifier;
    else
        return keySym[i];


}

Symbol Scanner::get_number() {
    val = 0;
    do {
        val = 10 * val + (ch - '0');
        read_ch();
    } while (ch != EOF && isdigit(ch));
    return number;
}

Symbol Scanner::getsym() {
    while (ch != EOF && ch <= ' ')
        read_ch();
    switch (ch) {
    case EOF:
        return eofsym;
    case ';':
        return delimeter;
    case '+':
        read_ch();
        return plus;
    case '=':
        read_ch();
        return assign;
    case '*':
        read_ch();
        return times;
    case '(':
        read_ch();
        return lparen;
    case ')':
        read_ch();
        return rparen;
    case '"':
        read_ch();
        if(m==1) {
            m=0;
            return sstring;
        }
        else {
            m=1;
            return null;
        }
    default:
        if (isalpha(ch))
            return get_token();
        if (isdigit(ch))
            return get_number();
        read_ch();
        return null;
    }
}


void Scanner::TableEntry(Symbol sym, Ident name) {
    keyTab[new_keyword] = name;
    keySym[new_keyword] = sym;
    new_keyword++;
}

int Scanner::init(const char fn[]) {
    //Library Functions can be added here



    if ((f = fopen(fn, "r")) == NULL)
        return 0;
    ch = ' ';
    read_ch();
    new_keyword = 0;
    TableEntry(identifier,  "printf");
    TableEntry(identifier,  "puts");



    TableEntry(keyword,  "int");
    TableEntry(keyword,  "char");
    TableEntry(keyword,  "long");
    TableEntry(keyword,  "double");
    TableEntry(keyword,  "float");
    TableEntry(keyword,  "signed");
    TableEntry(keyword,  "unsigned");

    TableEntry(identifier,  "a");
    TableEntry(identifier,  "b");
    return 1;
}

int main(int argc, char *argv[]) {
    Scanner s;
    Symbol sym=null;

    int array[20],b=0;

    memset(array,0,sizeof(array));
    if (argc < 2) {
        printf("Need a filename\n");
        return 2;
    }
    if (s.init(argv[1])==0) {
        printf("Can't open %s\n", argv[1]);
        return 2;
    }
    do {
        sym = s.getsym();
        array[b] = sym;
        b++;

    } while (sym != delimeter);
    printf("\n");
    for (int i = 0; i < 20; ++i)
    {
        if(array[i]==11)
            printf("Assignment\n");
        if(array[i]==1)
            printf("times\t*\n");
        if(array[i]==2)
            printf("plus\t+\n");
        if(array[i]==3)
            printf("Rparen\t)\n");
        if(array[i]==4)
            printf("Lparen\t(\n");
        if(array[i]==5)
            printf("number\t%d\n",s.getval());
        if(array[i]==6) {
            printf("identifier\t\n");
        }
        if(array[i]==7)
            printf("eof\n");
        if(array[i]==8)
            printf("string\n");
        if(array[i]==9)
            printf("keyword\n");
        if(array[i]==10)
            printf("end\n");

    }
    getch();
    return 0;
}
