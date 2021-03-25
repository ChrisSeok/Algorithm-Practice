#include <iostream>
#include <cmath>
using namespace std;
#define MAX_POLYS 100

typedef struct term
{
    int coef; //계수
    int expo; //지수
    struct term *next;
} Term;
typedef struct polynomial
{
    char name;
    Term *first;
    int size = 0;
} Polynomial;
Polynomial *polys[MAX_POLYS]; //다항식들에 대한 포인터 배열
int n = 0;                    //number of 다항식 saved

Term *create_term()
{
    Term *t = new Term;
    t->coef = 0;
    t->expo = 0;
    return t;
}

Polynomial *creat_poly(char name)
{
    Polynomial *p = new Polynomial;
    p->name = name;
    p->size = 0; //항의 개수
    p->first = NULL;
    return p;
}
void addterm(int c, int e, Polynomial *poly)
{
    if (c == 0)
        return;
    Term *p = poly->first, *q = NULL;
    while (p != NULL && p->expo > e)
    {
        q = p;
        p = p->next;
    }
    if (p != NULL && p->expo == e)
    {
        p->coef += c;
        if (p->coef == 0)
        {
            if (q == NULL)
                poly->first = p->next;
            else
                q->next = p->next;
        }
        (poly->size)--;
        free(p);
    }
    else
    {
        Term *term = create_term();
        term->coef = c;
        term->expo = e;
        if (q == NULL)
        {
            term->next = p; //term->next=poly->first;
            poly->first = term;
        }
        else
        {
            q->next = term;
            term->next = p;
        }
        poly->size++;
    }
}
int eval(Polynomial *poly, int x)
{ //다항식 값을 계산하는 함수
    int result = 0;
    Term *t = poly->first;
    while (t != NULL)
    {
        result += eval(t, x);
        t = t->next;
    }
    return result;
}
int eval(Term *trm, int x){ //각 항 계산
    int ex = pow(x, trm->expo);
    int result = (trm->coef) * ex;
    return result;
}
void print_poly(Polynomial *poly)
{
    cout << poly->name << ":";
    Term *t = poly->first;
    while (t != NULL)
    {
        if (t->expo > 1)
        {
            cout << t->coef << "x^" << t->expo;
            if (t->next != NULL)
                cout << "+";
        }
        else if (t->expo == 1)
        {
            cout << t->coef << "x";
            if (t->next != NULL)
                cout << "+";
        }
        else{
            cout << t->coef;
            if (t->next != NULL)
                cout << "+";
        }
        t = (*t).next;
    }
    // void handle_definition(char *expression);{
    //     erase_blanks(expression);
    //     char *fname=strtok(expression,"=");
    //     if(fname==NULL||strlen(fname)!=1){
    //         cout<<"Unsupported command";
    //         return;
    //     }
    //     char *expbody=strtok(NULL,"=");
    //     if(fname==NULL||strlen(fname)!=1){
    //         cout<<"Unsupported command";
    //         return;
    //     }
    // }
