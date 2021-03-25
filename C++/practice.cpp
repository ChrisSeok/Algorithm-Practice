#include <iostream>
#include <cmath>
using namespace std;

typedef struct term
{
    int coef; //계수
    int expo; //지수
  //  struct term *next;
} Term;

int main(){
    Term *t=new Term;
    Term a = {3,4};
    t->coef=2;
    (*t).expo=3;
     a=*t;
    // cout<<(*t).coef<<endl;
    cout<<a.coef<<endl;
     cout<<t->coef<<endl;


}