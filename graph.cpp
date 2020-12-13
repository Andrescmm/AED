#include <iostream>

using namespace std;

// Node
struct Node{
    int value;
    Node *next;
};

// Edge
struct Edge{
    int start;
    int end;
    
};

// Graph
class Graph{
  private:
    int N; // Number of nodes
    
    Node *getAdjListNode(int dest, Node *head){
        Node* newNode = new Node;
                newNode->value = dest;
                newNode->next = head;
         
                return newNode;
    }
    
  public:
    
    Node **head;
    Graph(int N){
        head = new Node*[N]();
               this->N = N;
        

        for (int i = 0; i < N; i++)
                    head[i] = nullptr;
    }
    
};







int main(){
    int n;
 
       cout<< "------ Graph -------"<<endl;
       cout << "How may nodes do you want?" << endl;
       cout<<">> ";
       cin>>n;
    
       (Graph(n));
          
          
          bool code=true;
          char tecla;
          while(code){
             cout<<endl;
             cout << "- Chose an a option: ";
             cin >> tecla;
             cout<<endl;
             
                    switch(tecla){
                       case '1':
                        int numero;
                        cout << "Insertar un Numero: ";
                        cin>>numero;
                        break;
             
                       case '2':
                        int numero2;
                        cout << "Numero a Remover: ";
                      
             }
        }
}
