#include <iostream>

#include <queue>
using namespace std;

// Node
template <class T>
struct TNode{
    T v;
    TNode<T> *nodes[2];
    
    TNode(T V){
        v=V;
        nodes[0]=nullptr;
        nodes[1]=nullptr;
    }
};


// Binary Tree
template <class T>
class BinaryTree{
    
   private:
    TNode<T> *root;
   public:

    BinaryTree(){
        root=nullptr;
    }
  
    bool Find(T x, TNode<T>**&p);
    bool Insert(T x);
    bool Remove(T x);
    
    void Preorden(TNode<T> *x);
    void Inorden(TNode<T> *x);
    void Postorden(TNode<T> *x);
    void Reverse(TNode<T> *x);
    void Levels(TNode<T> *x);
    
    void PrintPreorden();
    void PrintInorden();
    void PrintPostorden();
    void PrintReverse();
    void PrintLevels();
    
    TNode<T>** LN(TNode<T>**p);
  
};


// Left Node
template <class T>
TNode<T>** BinaryTree<T>::LN(TNode<T>**q){
    
    bool b = rand()%2;
    for( q = &(*q)->nodes[b]; (*q)->nodes[!b]; q =  &((*q)->nodes[!b]));
    return q;
}


// Find
template <class T>
bool BinaryTree<T>::Find(T x, TNode<T>**&p){
 
    p=&root;
    
    while ( (*p) && (*p)->v!= x){
        p=&((*p)->nodes[(*p)->v<x]);
    }
    return (*p)!=0 && (*p)->v==x;
}

// Insert
template <class T>
bool BinaryTree<T>::Insert(T x){
 
    TNode<T> **p = nullptr;
    if(Find(x,p)){
        return 0;
    }
    
    *p = new TNode<T>(x); // Se conecta con el Puntero al cual P esta apuntando
    
    return 1;
}


// Remove
template <class T>
bool BinaryTree<T>::Remove(T x){
    
    TNode<T> **p = nullptr;
    
    if(!Find(x,p)){
        return 0;
    }
    
    if(((*p)->nodes[0])and((*p)->nodes[1])){ // En caso esten los dos nodos
        
        TNode<T> **q = LN(p);
        (*p)->v = (*q)->v;
        p = q;
    }
    
    TNode<T> *n = *p;
    
    *p= (*p)-> nodes[ (*p)->nodes[1] != 0 ];
    
    delete (n);
    
    return 1;
}


//Preorden
template<class T>
void BinaryTree<T>::Preorden(TNode<T> *x){
    if(!x){
        return;
    }
    else{
        cout<<x->v<<" - ";
        Preorden(x->nodes[0]);
        Preorden(x->nodes[1]);
    }
}

//Inorden
template<class T>
void BinaryTree<T>::Inorden(TNode<T> *x){
    if(!x){
        return;
    }
    else{
        Inorden(x->nodes[0]);
        cout<<x->v<<" - ";
        Inorden(x->nodes[1]);
    }
}

//Postorden
template<class T>
void BinaryTree<T>::Postorden(TNode<T> *x){
    if(!x){
        return;
    }
    else{
        Postorden(x->nodes[0]);
        Postorden(x->nodes[1]);
        cout<<x->v<<" - ";
    }
}

//Reverse
template<class T>
void BinaryTree<T>::Reverse(TNode<T> *x){
    if(!x){
        return;
    }
    else{
        Reverse(x->nodes[1]);
        cout<<x->v<<" - ";
        Reverse(x->nodes[0]);
    }
}

//Levels
template<class T>
void BinaryTree<T>::Levels(TNode<T> *x){
    if(!x){
        return;
    }
    
    queue<TNode<T>*> q;
    
    q.push(x);
    
    while(!q.empty()){
        
        int nodecount= q.size();
        
        while(nodecount>0){
            
            TNode<T> *node = q.front();
            cout << node->v << " ";
            q.pop();
            if (node->nodes[0] != NULL)
              q.push(node->nodes[0]);
            if (node->nodes[1] != NULL)
              q.push(node->nodes[1]);
            nodecount--;
        }
        cout<<endl;
    }
    
    
}

//Print
template<class T>
void BinaryTree<T>::PrintPreorden(){
    cout<<"Preorden"<<endl;
    Preorden(root);
    cout<<endl;
}
template<class T>
void BinaryTree<T>::PrintInorden(){
    cout<<"Inorden"<<endl;
    Inorden(root);
    cout<<endl;
}
template<class T>
void BinaryTree<T>::PrintPostorden(){
    cout<<"Postorden"<<endl;
    Postorden(root);
    cout<<endl;
}
template<class T>
void BinaryTree<T>::PrintReverse(){
   cout<<"Reverse"<<endl;
    Reverse(root);
    cout<<endl;
}
template<class T>
void BinaryTree<T>::PrintLevels(){
    cout<<endl;
    Levels(root);
    cout<<endl;
}





int main(){
    BinaryTree<int> a;
    BinaryTree<char> b;
    
    ///*
    b.Insert('f');
    b.Insert('b');
    b.Insert('g');
    b.Insert('a');
    b.Insert('i');
    b.Insert('d');
    b.Insert('h');
    b.Insert('c');
    b.Insert('e');
    //*/
    
    
    cout<< "------ BINARY TREE -------"<<endl;
    cout << "  1 = Insert" << endl;
    cout << "  2 = Remove" << endl;
    cout << "  3 = Preorden" << endl;
    cout << "  4 = Inorden" << endl;
    cout << "  5 = Postorden" << endl;
    cout << "  6 = Reverse" << endl;
    cout << "  7 = Niveles" << endl;
    // Contar hojas
    // Contar Ramas
    // Contar hojas + Contar Ramas + 1 = nodos arbol 
    cout << "  8 = Terminar" << endl;
    cout<<endl;
       
       
       bool code=true;
       char tecla;
       while(code){
          cout<<endl;
          cout << "- Chose an a option: ";
          cin >> tecla;
          cout<<endl;
          
                 switch(tecla){
                    case '1':
                     char numero;
                     cout << "Insert: ";
                     cin>>numero;
                     b.Insert(numero);
                     break;
          
                    case '2':
                     char numero2;
                     cout << "Remove: ";
                     cin>>numero2;
                     b.Remove(numero2);
                     break;

                     case '3':
                      b.PrintPreorden();
                      break;
                        
                     case '4':
                      b.PrintInorden();
                      break;
                         
                     case '5':
                      b.PrintPostorden();
                      break;
                        
                     case '6':
                      b.PrintReverse();
                      break;
          
                     case '7':
                      b.PrintLevels();
                      break;
                         
                    case '8':
                     code=false;
                     break;
          }
     }
}

