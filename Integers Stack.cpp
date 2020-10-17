#include <iostream>

using namespace std;

//Node
struct Node{
    int v; // value
    Node *next; // Node point to the next Node
    
    Node(int V,Node *nextNode){ // Constructor
        v=V; // Give value
        next=nextNode; // next points to a another next
    }
};

//List

struct Stack{
    
    Node *top;//Making the top of the stack
    
    Stack():top(nullptr){}; // Constructor and making top point to NULL
    
    void push(int x);// Push
    
    void pop();// Pop
    
    void Print(); // Print
};


// Push
void Stack::push(int x){
    
    top = new Node(x,top);// Create a new Node in top place and make it points to the next node

}
// Pop
void Stack::pop(){
    
    int value=0;
    Node *tmp; // temporal Node
    
    value= top->v; //Make it 0 Top values
    tmp=top; // temporal equals top
    top=top->next; // Make the next to top the new top
    delete tmp; // Delete
}


// Print
void Stack::Print(){
    for(Node* i=top; i ; i=i->next){
        cout<<i->v<<"->";
    }
    cout<<"NULL";
    cout<<endl;
}


int main (){
    
    Stack a;
    a.push(5);
    a.Print();
    a.push(8);
    a.Print();
    a.pop();
    a.Print();
    a.push(2);
    a.push(1);
    a.push(4);
    a.Print();
    a.pop();
    a.Print();
    
}
