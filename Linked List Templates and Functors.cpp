#include <iostream>

using namespace std;

template<class T>
struct Cless{
    inline bool operator()(T a, T b){
      return a<b;
    }
};

template<class T>
struct CGreater{
    inline bool operator()(T a, T b){
      return a>b;
    }
};

//Clase Nodo
template<class T>
class Cnode{
public:
    T v;// Valor del nodo
    Cnode<T> *next;// Puntero al siguiente nodo
    
    Cnode (T _v){ // Constructor
        v=_v; // Inicializa el valor
        next=nullptr; // Apunta a null
    }
    
};

template <class T, class C>
class cList{
private:
    Cnode<T> * head; // Crea la cabeza
    C co;
public:
    cList(){
        head=nullptr; // Inicia la cabeza apuntando a nullptr
    }
    bool Find(T x, Cnode<T>**&p); // Declaracion de Find, con una variable y con un Nodo puntero doble
    bool Insert(T x); // Declaracion de Insert con la variable a insertar
    bool Remove(T x);// Delclaracion de Remove con la variable a borrar
    void Print();// Funcion para Imprimir
    
};


// Find
template <class T, class C>
bool cList<T,C>::Find(T x, Cnode<T> **&p){
    
    p=&head; // Ponemos la direccion de memoria de la cabeza de la lista en otra variable
      while(*p&& co((*p)->v,x)){ // Mientras el puntero p tenga contenido y si *p es menor que el numero que se esta buscando
        //for(;*p && (*p)->v<x ; ){
        p=&((*p)->next); // Mueve el puntero p al siguiente nodo
    }
    return *p && (*p)->v==x; // Si es *p verifica que tiene contenido
    // verifica si el valor de p es el valor de de lo que se busca y devuelve 1
}

template <class T, class C>
bool cList<T,C>::Insert(T x){
    
    Cnode<T> **p=nullptr; // Puntero TIPO NODO P doble
    
    if(Find(x,p)){// Se busca si esta en la lista
        cout<<"El numero "<<x<< " ya esta en la Lista"<<endl;
        return 0;}// Si se encuentra termina y se manda 0
    
    Cnode<T>*n= new Cnode<T>(x);// Se crea un nuevo nodo y se le da memoria
    
    n->next = *p; // *p es el nodo donde debe estar y apunta al siguiente
    
    * p=n; //p se le one al nuevo nodo n
    
    return 1;
    
}


template <class T, class C>
bool cList<T,C>::Remove(T x){
    
    Cnode<T>**p; // Puntero TIPO NODO P doble
    
    if(!Find(x,p)) // Si no lo encuentra
        return 0; // Termina porque si no lo enceuntra no lo remueve
       
    Cnode<T> *t =*p; // Se crea un nodo temporal al cual se da el valor de p
    
    *p = t->next; // el contenido de p es igualado al siguiente
    
    delete(t); // borra
    
    return 1;
}

template <class T, class C>
void cList<T,C>::Print(){
    
    for(Cnode <T>*i=head ; i ; i=i->next){ // Recorrido de la lista desde head hasta el final
            cout<<i->v<<" -> ";}
     cout<<"NULL"<<endl;
}


int main(){
    
    cout<<"Lista 1: "<<endl;
    
    cList<int,Cless<int>> l;
    
    l.Insert(9);
    l.Insert(10);
    l.Insert(5);
    l.Print();
    l.Remove(7);
    l.Print();
    l.Remove(9);
    l.Print();
    l.Insert(1);
    l.Print();
    l.Insert(1);
    l.Print();
    

}
  
