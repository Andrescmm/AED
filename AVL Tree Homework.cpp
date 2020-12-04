#include<iostream>

using namespace std;
  

class Node
{
    public:
    int key;
    Node *left;
    Node *right;
    int height;
};
  
class AVL_Tree{
    
private:
    Node* root;
public:
   
    AVL_Tree(){
        root=nullptr;
    }
    
    int max(int a, int b); // Regresa el maximo de dos valores
    int height(Node* N); // Regresa la altura de un arbol
    Node* newNode (int key);
    Node* rightRotate(Node*y);
    Node* leftRotate(Node *x);
    int getBalance(Node *N);
    Node* insert(Node* root,int key);
    void InsertF(int num);
    Node* minValueNode(Node* node);
    Node* deleteNode(Node* root, int key);
    void remove(int num);
 
    
    void Inorden(Node *x);
    void Postorden(Node *x);
    void Reverse(Node *x);
    void Levels(Node *x);
    void Preorder(Node *x);

    
    void PrintPreorden();
    void PrintInorden();
    void PrintPostorden();
    void PrintReverse();
    void PrintLevels();
};

  
// height
int AVL_Tree::height(Node *N)
{
    if (N == NULL)
        return 0;
    return N->height;
}
  
// max
int AVL_Tree::max(int a, int b)
{
    return (a > b)? a : b;
}

// New Node
Node* AVL_Tree::newNode(int key)
{
    Node* node = new Node();
    node->key = key;
    node->left = NULL;
    node->right = NULL;
    node->height = 1;
    return(node);
}
  
// Rigth Rotate
Node *AVL_Tree::rightRotate(Node *y)
{
    Node *x = y->left;
    Node *T2 = x->right;
  

    x->right = y;
    y->left = T2;
  
  
    y->height = max(height(y->left),
                    height(y->right)) + 1;
    x->height = max(height(x->left),
                    height(x->right)) + 1;

    return x;
}
  
// Left rotate
Node *AVL_Tree::leftRotate(Node *x)
{
    Node *y = x->right;
    Node *T2 = y->left;
  

    y->left = x;
    x->right = T2;
  
  
    x->height = max(height(x->left),
                    height(x->right)) + 1;
    y->height = max(height(y->left),
                    height(y->right)) + 1;
  
  
    return y;
}
// Get balance
int AVL_Tree::getBalance(Node *N)
{
    if (N == NULL)
        return 0;
    return height(N->left) - height(N->right);
}
  
// Insert
Node* AVL_Tree::insert(Node* node, int key)
{
    
    if (node == NULL)
        return(newNode(key));
  
    if (key < node->key)
        node->left = insert(node->left, key);
    else if (key > node->key)
        node->right = insert(node->right, key);
    else
        return node;
  

    node->height = 1 + max(height(node->left),
                        height(node->right));
  
    
    int balance = getBalance(node);
  

    // Left Left Case
    if (balance > 1 && key < node->left->key)
        return rightRotate(node);
  
    // Right Right Case
    if (balance < -1 && key > node->right->key)
        return leftRotate(node);
  
    // Left Right Case
    if (balance > 1 && key > node->left->key)
    {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }
  
    // Right Left Case
    if (balance < -1 && key < node->right->key)
    {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }

    return node;
}
  
// Insert Function
void AVL_Tree::InsertF(int num){
    root=insert(root, num);
}

// minvaluenode

Node* AVL_Tree:: minValueNode(Node *node){
    Node* temp = node;
    
        while (temp->left != NULL)
            temp = temp->left;
      
        return temp;
}

// Delete Node

Node* AVL_Tree::deleteNode(Node* root, int key){
       if (root == NULL)
           return root;
     
       if ( key < root->key )
           root->left = deleteNode(root->left, key);
   
       else if( key > root->key )
           root->right = deleteNode(root->right, key);
     
       else{
           if( (root->left == NULL) ||
               (root->right == NULL) ){
               Node *temp = root->left ?root->left :root->right;
               if (temp == NULL){
                   temp = root;
                   root = NULL;
               }
               else
               *root = *temp;
               free(temp);
           }
           else{
               Node* temp = minValueNode(root->right);
               root->key = temp->key;
               root->right = deleteNode(root->right,temp->key);
           }
       }
       if (root == NULL)
       return root;

       root->height = 1 + max(height(root->left),height(root->right));
       int balance = getBalance(root);
     
     
       // Left Left Case
       if (balance > 1 &&
           getBalance(root->left) >= 0)
           return rightRotate(root);
     
       // Left Right Case
       if (balance > 1 &&
           getBalance(root->left) < 0)
       {
           root->left = leftRotate(root->left);
           return rightRotate(root);
       }
     
       // Right Right Case
       if (balance < -1 &&
           getBalance(root->right) <= 0)
           return leftRotate(root);
     
       // Right Left Case
       if (balance < -1 &&
           getBalance(root->right) > 0)
       {
           root->right = rightRotate(root->right);
           return leftRotate(root);
       }
     
    return root;
    
}

void AVL_Tree:: remove(int num){
    root= deleteNode(root, num);
}
    

//Preorden
//template<class T>
void AVL_Tree::Preorder(Node* x){
    if(!x){
        return;
    }
    else{
        cout<<x->key<<" - ";
        Preorder(x->left);
        Preorder(x->right);
    }
}

//Inorden
//template<class T>
void AVL_Tree::Inorden(Node *x){
    if(!x){
        return;
    }
    else{
        Inorden(x->left);
        cout<<x->key<<" - ";
        Inorden(x->right);
    }
}

//Postorden
//template<class T>
void AVL_Tree::Postorden(Node *x){
    if(!x){
        return;
    }
    else{
        Postorden(x->left);
        Postorden(x->right);
        cout<<x->key<<" - ";
    }
}

//Reverse
//template<class T>
void AVL_Tree::Reverse(Node *x){
    if(!x){
        return;
    }
    else{
        Reverse(x->right);
        cout<<x->key<<" - ";
        Reverse(x->left);
    }
}

//Print
void AVL_Tree::PrintPreorden(){
    cout<<"Preorden"<<endl;
    Preorder(root);
    cout<<endl;
}

void AVL_Tree::PrintInorden(){
    cout<<"Inorden"<<endl;
    Inorden(root);
    cout<<endl;
}

void AVL_Tree::PrintPostorden(){
    cout<<"Postorden"<<endl;
    Postorden(root);
    cout<<endl;
}

void AVL_Tree::PrintReverse(){
   cout<<"Reverse"<<endl;
    Reverse(root);
    cout<<endl;
}







int main()
{

    AVL_Tree b;
    
    
    cout<< "------ AVL TREE -------"<<endl;
    cout << "  1 = Insert" << endl;
    cout << "  2 = Remove" << endl;
    cout << "  3 = Preorden" << endl;
    cout << "  4 = Inorden" << endl;
    cout << "  5 = Postorden" << endl;
    cout << "  6 = Reverse" << endl;
    cout << "  7 = Niveles" << endl;
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
                     int numero;
                     cout << "Insertar un Numero: ";
                     cin>>numero;
                     b.InsertF(numero);
                     break;
          
                    case '2':
                     int numero2;
                     cout << "Numero a Remover: ";
                     cin>>numero2;
                     b.remove(numero2);
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
                     // b.PrintLevels();
                      break;
                         
                    case '8':
                     code=false;
                     break;
          }
     }
}
