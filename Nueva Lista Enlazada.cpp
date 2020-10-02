#include <iostream>

using namespace std;


//Clase Nodo
class Cnode{
public:
    int v;// Valor del nodo
    Cnode *next;// Puntero al siguiente nodo
    
    Cnode (int _v){ // Constructor
        v=_v; // Inicializa el valor
        next=nullptr; // Apunta a null
    }
    
};


class cList{
private:
    Cnode * head; // Crea la cabeza
    
public:
    cList(){
        head=nullptr; // Inicia la cabeza apuntando a nullptr
    }
    bool Find(int x, Cnode**&p); // Declaracion de Find, con una variable y con un Nodo puntero doble
    bool Insert(int x); // Declaracion de Insert con la variable a insertar
    bool Remove(int x);// Delclaracion de Remove con la variable a borrar
    void Print();// Funcion para Imprimir
    
};


// Find
bool cList::Find(int x, Cnode **&p){
    
    p=&head; // Ponemos la direccion de memoria de la cabeza de la lista en otra variable
    while(*p&&(*p)->v<x){ // Mientras el puntero p tenga contenido y si *p es menor que el numero que se esta buscando
        p=&((*p)->next); // Mueve el puntero p al siguiente nodo
    }
    return *p && (*p)->v==x; // Si es *p verifica que tiene contenido
    // verifica si el valor de p es el valor de de lo que se busca y devuelve 1
}


bool cList::Insert(int x){
    
    Cnode **p=nullptr; // Puntero TIPO NODO P doble
    
    if(Find(x,p))// Se busca si esta en la lista
        return 0;// Si se encuentra termina y se manda 0
    
    Cnode *n= new Cnode(x);// Se crea un nuevo nodo y se le da memoria
    
    n->next = *p; // *p es el nodo donde debe estar y apunta al siguiente
    
    *p=n; //p se le one al nuevo nodo n
    
    return 1;
    
}



bool cList::Remove(int x){
    
    Cnode**p; // Puntero TIPO NODO P doble
    
    if(!Find(x,p)) // Si no lo encuentra
        return 0; // Termina porque si no lo enceuntra no lo remueve
       
    Cnode *T =*p; // Se crea un nodo temporal al cual se da el valor de p
    
    *p = T->next; // el contenido de p es igualado al siguiente
    
    delete(T); // borra
    
    return 1;
}


void cList::Print(){
    
    for(Cnode *i=head ; i ; i=i->next){ // Recorrido de la lista desde head hasta el final
            cout<<i->v<<" -> ";}
     cout<<"NULL"<<endl;
}


int main(){
    
    cout<<"Lista 1: "<<endl;
    
    cList l;
    
    l.Insert(5);
    l.Insert(7);
    l.Insert(9);
    l.Print();
    l.Remove(7);
    l.Print();
    l.Remove(9);
    l.Print();
    l.Insert(1);
    l.Print();
    

}
