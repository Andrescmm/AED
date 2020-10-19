#include <iostream>

using namespace std;

template <class T>
struct Node{
    
    T v;
    Node *next;
    Node *prev;
    
    Node(T V, Node *n=nullptr, Node *p=nullptr){
     v=V;
     next=n;
     prev=p;
    }
};


template <class T>
struct Queue{
    
    Node <T>*Head;
    Node <T>*Tail;
    
    Queue(Node<T>*h=nullptr, Node<T>*t=nullptr){
        Head=h;
        Tail=t;
    }
    
    ~Queue(){
        while(Head){
            pop();
        }
    }
    
    void push(T x);
    void pop ();
    void Print();
};


// Push
template <class T>
void Queue<T>::push(T x){
    
    if(!Head){
        Head= new Node<T>(x,Head);
        Tail=Head;
    }
    else{
        Tail->next=new Node<T>(x,Tail->next);
        Tail=Tail->next;
    }
}


// Pop
template <class T>
void Queue<T>::pop(){
    if(!Head){
        cout<<"The Queue Empty"<<endl;
    }
    else{
        T value=0;
        Node<int> *tmp;
        
        value= Head->v;
        tmp=Head;
        Head=Head->next;
        delete tmp;
    }
}


// Print
template <class T>
void Queue<T>::Print(){
 
    for(Node<T>* i=Head; i ; i=i->next){
        cout<<i->v<<"->";
    }
    cout<<"NULL";
    cout<<endl;
}

    
    
int main(){
    
    Queue<int> q;
    
    cout<< "------ QUEUE -------"<<endl;
    cout << "  1 = Push" << endl;
    cout << "  2 = Pop" << endl;
    cout << "  3 = Imprimir" << endl;
    cout << "  4 = Terminar" << endl;;
    
    
    bool code=true;
    char tecla;
    while(code){
       cout << "- Chose an a option: ";
              cin >> tecla;
       
              switch(tecla){
                 case '1':
                  int numero;
                  cout << "Number to make Push: ";
                  cin>>numero;
                  q.push(numero);
                  break;
       
                 case '2':
                  q.pop();
                  break;

                 case '3':
                  q.Print();
                  break;
       
                 case '4':
                  q.~Queue();
                  code=false;
                  break;
       }
    }
    
}
