#include <iostream>

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


// Tree
template <class T>
struct BinaryTree{
  
    TNode<T> *Root;
    
    BinaryTree(){
        Root=nullptr;
    }
    //~BinaryTree();
    bool Find(T x, TNode<T>**&p);
    bool Insert(T x);
    bool Remove (T x);
    void Print();
    TNode<T>** Rep(TNode<T>**p);
    
};

// Rep
template <class T>
TNode<T>** BinaryTree<T>::Rep(TNode<T>**q){// Busca el mas izquierdo o derecho de un arbol
    
    for(q=&((*q)->nodes[0]);
          (*q)->nodes[1];
         q=&((*q)->nodes[1]));
    return q;
}


// Find
template <class T>
bool BinaryTree<T>::Find(T x, TNode<T>**&p){
    
    p=&Root; // Double Pointer to the Root
    
    //for(;(*p)&&((*p)->v != x);p=&((*p)->nodes[(*p)->v>x]));
    
    while((*p)&&((*p)->v != x)){ // Mientras que *p no sea nulo osea no termine que recorrer el arbol o el valor del nodo sea diferente al de x
        
            p=&((*p)->nodes[(*p)->v>x]); // Se recorre el arbol dependiendo de si el numero es mayor o menor por medio de los nodos array

    }
     return *p!=0  && (*p)->v==x; // Comprobamos si salio porque se acabo (*p) entonces es 0 si no sera 1 y si el valor es de *p es igual al valor
}


// Insert
template <class T>
bool BinaryTree<T>::Insert(T x){
    
    TNode<T> **p;
    if(Find(x, p)){
        return 0;
    }
    
    *p = new TNode<T>(x); // Se conecta con el Puntero al cual P esta apuntando
    
    return 1;
}


// Remove
template <class T>
bool BinaryTree<T>::Remove(T x){
    
    TNode<T> **p;
    if(!Find(x, p)){
        return 0;
    }
    
    if((*p)->nodes[0] and (*p)->nodes[1]){ // Caso 2
        
        TNode<T> **q = Rep(p);
        (*p)->v=(*q)->v; // Se intercambia el que este mas a la izquierda con el valor a borrar
        p=q;// Se devuelve p al numero intercambiado
      }
    TNode<T>*n= *p; // recojemos al puntero que se sera borrado
    
    *p= (*p)-> nodes[(*p)->nodes[1]!=0]; // apunta a p al lado del nodo el cual no es un nullptr
    
    delete(n);
    
    return 1;
}


template<class T>
void BinaryTree<T>::Print(){
    for(TNode<T> *i=Root; i; i=i->nodes[0]){
        cout<<i->v<<",";
}
    cout<<endl;
}


// Main
int main(){
    
    BinaryTree<int> t;
    t.Insert(5);
    t.Insert(7);
    t.Insert(8);
    t.Insert(9);
    t.Print();
    t.Remove(5);
    t.Print();
 
    
}
