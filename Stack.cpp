#include <iostream>

using namespace std;

//Node
template<class T>
struct Node{
    T v;
    Node *next;
    
    Node(T V,Node *nextNode){
        v=V;
        next=nextNode;
    }
};

//List
template <class T>
struct Stack{
    
    Node<T> *top;
    
    Stack():top(nullptr){};
    
    ~Stack(){
        while(!IsEmpty()){
            pop();
        }
    }
    
    bool IsEmpty();
    
    void push(T x);
    
    void pop();
    
    void Print();
};




// Is Empty
template <class T>
bool Stack<T>::IsEmpty(){
    
    if(!top){
        return true;
    }
    else{
        return false;
    }
}


// Push
template <class T>
void Stack<T>::push(T x){
    
    top = new Node<T>(x,top);
    
}
// Pop
template <class T>
void Stack<T>::pop(){
    
    T value=0;
    Node<T>*tmp;
    
    if(!IsEmpty()){
        
    value= top->v;
    tmp=top;
    top=top->next;
    delete tmp;// Delete
    }
    
    else{
        cout<< "The Stack is Empty"<<endl;
    }
}


// Print
template <class T>
void Stack<T>::Print(){
    for(Node<T>* i=top; i ; i=i->next){
        cout<<i->v<<"->";
    }
    cout<<"NULL";
    cout<<endl;
}


int main (){
    
    Stack<int> l;

    
    cout<< "------ STACK -------"<<endl;
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
                  l.push(numero);
                  break;
       
                 case '2':
                  l.pop();
                  break;

                 case '3':
                  l.Print();
                  break;
       
                 case '4':
                  l.~Stack();
                  code=false;
                  break;
       }
    }
}
