
#include <iostream>

using namespace std;


template <class T>
struct CSNode

{

typedef unsigned int UInt;
  CSNode(UInt x, UInt y, T v);
  UInt m_X, m_Y;
  T m_value;
  CSNode<T> *m_pRight, *m_pDown;
};

template <class T>
CSNode<T>::CSNode(UInt x, UInt y, T v)
{
  m_X = x; m_Y = y; m_value = v;
  m_pRight = m_pDown = 0;
}

template <class T, T NullElem>
class CSparseMatrix
{
public:
  typedef unsigned int UInt;
  typedef T TType;

  CSparseMatrix(UInt xdim = 0, UInt ydim = 0);
  ~CSparseMatrix();
    //mis funciones
   bool findInX(T x,T y, CSNode<T> **&ptr);
   bool findInY(T x, T y, CSNode<T> **&ptr);
    // fin de mis funciones
  bool Set(UInt x, UInt y, T v);
  TType Get(UInt x, UInt y);
  void Print();
  
  UInt m_XDim, m_YDim;
  CSNode<T> **m_XVector, **m_YVector;
};

template <class T, T NullElem>
CSparseMatrix<T,NullElem>::CSparseMatrix(UInt xdim, UInt ydim)
{
  m_XDim = xdim; m_YDim = ydim;
  m_XVector = new CSNode<T>*[m_XDim];
  m_YVector = new CSNode<T>*[m_YDim];
  for (int x = 0; x < xdim; x++)   m_XVector[x] = 0;
  for (int y = 0; y < ydim; y++)   m_YVector[y] = 0;

}

template <class T, T NullElem>
CSparseMatrix<T,NullElem>::~CSparseMatrix()
{
  delete [] m_XVector;
  delete [] m_YVector;
}


template <typename T, T NullElem>
inline bool CSparseMatrix<T, NullElem>::findInX(T x, T y, CSNode<T> **&ptr) {
    ptr  = &(m_XVector[x]);
    if(*ptr) { // Si el primer elemento de la lista de xs no apunta a nulo
    while(*ptr and (*ptr)->m_Y < y )
        ptr = &((*ptr)->m_pDown);
    if(*ptr and (*ptr)->m_Y == y)
        return true;
    }
    return false;
}

template <typename T, T NullElem>
inline bool CSparseMatrix<T, NullElem>::findInY(T x, T y, CSNode<T> **&ptr) {
    ptr  = &(m_YVector[y]);
    if(*ptr) { // Si el primer elemento de la lista de ys no apunta a nulo
    while(*ptr and (*ptr)->m_X < x )
        ptr = &((*ptr)->m_pRight);
    if(*ptr and (*ptr)->m_X == x)
        return true;
    }
    return false;
}


// Set
template <class T, T NullElem>
bool CSparseMatrix<T,NullElem>::Set(UInt x, UInt y, T v)
{
    CSNode<T> **ptr;
    if(v==NullElem){
        cout<< "valor nulo "<<endl;
        return 0;
    }
        if(x < 0 or y < 0 )
        return false;
        if(findInX(x,y,ptr)) { //si lo encuentra, ya existe, entonces cambio su valor
        (*ptr)->m_value = v;
        return false;
        }
        else {
            CSNode<T> *tmp = new CSNode<T>(x, y, v);
        tmp->m_pRight= *ptr;
        *ptr = tmp;

        findInY(x,y,ptr);
        tmp->m_pDown=*ptr;
        *ptr = tmp;
        return true;
        }
}
   

//Get
template <class T, T NullElem>
typename CSparseMatrix<T,NullElem>::TType CSparseMatrix<T,NullElem>::Get(UInt x, UInt y)
{
    CSNode<T>** ptr;
    //CSNode<T>** ptr1;
    
    if(findInY(x, y, ptr)==true){
        //cout<<ptr->m_value<<endl;
        return 1;
    }
    else{

    }
    return 0;
}

template <class T, T NullElem>
void CSparseMatrix<T,NullElem>::Print()
{
  cout<<"\n--------------------\n";
  for (int y = 0; y < m_YDim; y++)
  {
      UInt xLast = 0, xDiff;
      for (CSNode<T>* xPtr = m_YVector[y]; xPtr; xPtr = xPtr->m_pRight )
      {
          xDiff = xPtr->m_X - xLast;
          for ( int i = 0; i < xDiff; i++ ) cout<<"-\t";
          cout<<xPtr->m_value<<"\t";
          xLast = xPtr->m_X;
      }
      cout<<"\n";
  }
}

template <class T, T NullElem>
void SumMatrix(CSparseMatrix<T,NullElem>& a, CSparseMatrix<T,NullElem>& b, CSparseMatrix<T,NullElem>& MResult)
{
  // Implementar aqui una función para sumar las matrices a y b, y poner el resultado en la matriz mResult
  //...
  
}

int main(int argc, const char * argv[])
{
  CSparseMatrix<int,0> m1(8,8);
 // int v;
  
  m1.Set(2,1, 5);
  m1.Set(2,3, 2);
  m1.Set(2,5, 7);
  m1.Set(5,3, 9);
  m1.Set(7,3, 12);
  m1.Set(1,4, 3);
  m1.Set(2,4, 0);
  m1.Set(5,5, 8);
  m1.Set(3,6, 1);
  m1.Print();
  m1.Set(1,4, 0);
  m1.Set(2,3, 0);
  m1.Set(4,3, 0);
  m1.Set(0,1, 0);
  m1.Print();
  cout<<"\n 0,0 => "<<m1.Get(0,0);
  cout<<"\n 3,5 => "<<m1.Get(3,5);
  cout<<"\n 7,3 => "<<m1.Get(7,3);

  CSparseMatrix<int,0> m2(8,8);
  m2.Set(2,1, -5);
  m2.Set(2,3, -2);
  m2.Set(5,3, -10);
  m2.Set(7,3, 12);
  m2.Set(3,4, 7);
  m2.Set(0,5, 8);
  m2.Set(6,5, 1);
  m2.Set(3,6, -3);
  m2.Set(2,7, 14);
  m2.Print();

  CSparseMatrix<int,0> m3(8,8);
  SumMatrix(m1,m2,m3);
  m3.Print();
  
  return 0;
};
