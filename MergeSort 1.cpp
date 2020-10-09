#include <iostream>
#include <ctime>
using namespace std;



// Print
void Print(int *a, int tam ){
    cout<<"{ ";
    for(int *b=a;b<a+tam;b++)
        if(b<(a+tam)-1){
            cout<<*b<<" , ";
        }
        else{
            cout<<*b<<" }";
        }
    cout<<endl;
}


// Merge
void Merge(int*a, int *left, int *rigth, int sl, int sr){
    
    int i=0, j=0;
    
     while(i<sl && j<sr){
            if(*left<=*rigth){
                *a=*left;
                left++;
                i++;
            }
            else{
                *a=*rigth;
                rigth++;
                j++;
            }
            a++;
       }

        while(i<sl){
            *a=*left;
            left++;
            i++;
            a++;
        }
        while (j<sr){
            *a=*rigth;
            rigth++;
            j++;
            a++;
        }
    }


// MergeSort
void MergeSort (int *a, int tam){
    
    // Calculate half of the size
    int n = tam/2;
    // If the array has one element is sorted
    if(tam<2){
        return;
    }
    
    // Create 2 arrays
    int *left = new int[n];
    int *right = new int[tam-n];
    
    // Fill the arrays
    for(int*i=a,*j=left ;i<a+n ;i++,j++){
        *j=*i;
    }
    for(int*i=(a+n),*j=right ;i<a+(tam+n) ;i++,j++){
          *j=*i;
      }
    
    
    // Recall
    MergeSort(left, n);
    MergeSort(right,(tam-n));
    Merge(a, left, right, n, (tam-n));
}




// Main
int main(){
    int tam= 6;
    int array[6] ={5,2,1,3,6,4};
    
    double t0, t1;
    t0=clock();
    cout<<"Initial Array"<<endl;
    Print(array, tam);
    cout<<"Final Array"<<endl;
    MergeSort(array,tam);
    Print(array, tam);
    
    // Time
    t1=clock();
    double time = (double(t1-t0)/CLOCKS_PER_SEC);
    cout << "Execution Time: " << time << endl;
    
}
