#include <iostream>

using namespace std;

//Par
template <class T>
struct Par{
    
    bool operator()(T x){
        return (x%2==0);
  }
};

// Multiplo de 3
template <class T>
struct multiploTres{

    bool operator()(T a){
        return (a%3==0);
  }
};

// Multiplo de 4
template <class T>
struct multiploCinco{
    
    bool operator()(T a){
        return (a%5==0);
  }
};

// Swap
template <class T>
void swap(T *a,T *b){
    T r=*a;
    *a = *b;
    *b = r;
}

// Imprimir
void Imprimir(int tam,int *arr) {
    cout<<"{";
    for(int *i=arr; i<arr+tam; i++ ){
        if(i<((arr+tam)-1)){
        cout<<*i<<",";
        }
        else{
            cout<<*i;
        }
  }
    cout<<"}";cout<<endl;cout<<endl;
}

// Split
template <class T>
void split(int *arr, int tam ,int *&q, T comp){
    for(int *p=arr; p < arr+tam; p++){
        if(!q){ //verificamos que q no apunta a nada
            if (comp(*p)){
                q=p; // Si P es cumple se almacena dentro de Q
            }
        }
        else{
            if(!comp(*p)){// Si no es par
            // R se ubica con Q
                int *r=q;
                while(r<p){
                    swap(r,p);//intercambio
                    r++;
                }
                q++;
            }
        }
    }

}


// Main
int main() {
       int arr[10], arr1[10], arr2[10];
        int tam =10;
        //Se llena el array
        for(int *p=arr,i=1; p<arr+tam; p++, i++){
            *p=i;
        }
        //Imprimir
        cout<<"Array Base: ";
        Imprimir(tam, arr);
        
        //Pares
        Par<int>p;
        int *pares=nullptr;
        split(arr,tam,pares,p);
        cout<<"Array Pares: ";
        Imprimir(tam, arr);
        
        
        //Multiplos de 3
        // Se llena el array
        for(int *p=arr1,i=1; p<arr1+tam; p++, i++){
            *p=i;}
        
        multiploTres<int>Tres;
        int *multi3=nullptr;
        split(arr1,tam,multi3,Tres);
        cout<<"Array Multiplos de 3: ";
        Imprimir(tam, arr1);
         
        
        
        //Multiplos de 5
        // Se llena el array
        for(int *p=arr2,i=1; p<arr2+tam; p++, i++){
            *p=i;}
        
        multiploCinco<int>Cinco;
        int *multi5=nullptr;
        split(arr2,tam,multi5,Cinco);
        cout<<"Array Multiplos de 5: ";
        Imprimir(tam, arr2);
}
