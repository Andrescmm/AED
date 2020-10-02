#include <iostream>
using namespace std;

void f1(int a)  {    cout<<"f1:"<<a<<endl;  }
void f2(int a)  {    cout<<"f2:"<<a<<endl;  }
////////////////////////////////////////////////////////////
class C1
{ public:
    void m1(int a)  {   cout<<"m1:"<<a<<endl;   }
    void m2(int a)  {   cout<<"m2:"<<a<<endl;   }
};
////////////////////////////////////////////////////////////
void ff( void (*pf)(int) )
{   (*pf)(7);   }
////////////////////////////////////////////////////////////

int main(int argc, const char * argv[])
{
    //-------------
        void (*pf)(int);
        pf = &f1;
        (*pf)(4);
    //-------------
    
    C1 obj;
    C1* pobj;
    pobj = &obj;
    
    void (C1::*pm)(int);
    pm = &C1::m2;
    
    (obj.*pm)(7);
    (pobj->*pm)(8);

    cout<<"kjdfhkjsdf";

    //-------------
        ff(pf);
    //-------------
    int ar[3]={3,6,1};
    int *p;
    p = ar;
    p = &ar[0];
    p[2]=7;
    return 0;
}
