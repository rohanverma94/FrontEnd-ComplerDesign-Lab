#define SIZE 400            /* Size of Stack */
#include<string.h>
#include<iostream.h>
#include<conio.h>
#include<ctype.h>
char s[SIZE];
int top = -1;

void push(char elem) {
    s[++top] = elem;
}

char pop() {
    return(s[top--]);
}

int pr(char elem) {
    switch (elem) {
    case '#':
        return 0;
    case '(':
        return 1;
    case '+':
    case '-':
        return 2;
    case '*':
    case '/':
        return 3;
    }
    return 0;
}







int main()
{

    char infx[400], pofx[400], ch;
    int i = 0, k = 0;
    cout << "\n\nEnter the Infix Expression ?";
    cin >> infx;
    push('#');
    while ((ch = infx[i++]) != '\0') {
        if (ch == '(')
            push(ch);
        else if (isalnum(ch))
            pofx[k++] = ch;
        else if (ch == ')') {
            while (s[top] != '(')
                pofx[k++] = pop();
            top--;

        } else {
            while (pr(s[top]) >= pr(ch))
                pofx[k++] = pop();
            push(ch);
        }
    }
    while (s[top] != '#')
        pofx[k++] = pop();
    pofx[k] = '\0';
    cout<< "Postfix Expression is:"<< pofx<<endl;


    getch();
    return 0;
}

