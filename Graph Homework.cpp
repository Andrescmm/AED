#include <iostream>
#include <string>
#include <list>
#include <algorithm>

using namespace std;

// Graph
template< class N , class E>
struct  Graph {
    struct Node;
    //Edge
    struct Edge {
        E edge_value;
        bool dir;
        Node* nodes[2];

        Edge(Node* a, Node* b, E value, bool d) {
            edge_value = value;
            nodes[0] = a;
            nodes[1] = b;
            dir = d;
        }

        ~Edge() {
        }
    };
     
    // Node
    struct  Node {
        N node_value;
        list<Edge*> edges;
        bool colored;
        string color;

        Node(N value) {
            node_value = value;
        }

        ~Node() {

        }
    };
    
    int GraphSize;
    list<Node*> nodes;
    
    
   // Insert Node
    bool InsertNode(N value) {
        Node* a= new Node(value);
        nodes.push_back(a);
        return 1;
    }

    
    // InsertEdge
    bool InsertEdge(N a, N b, E  value, bool d) {

        auto nodeA = find_if(nodes.begin(), nodes.end(),
            [&a](Node*& i_nodeA) {
                return i_nodeA->node_value == a;
            }
        );

        auto nodeB = find_if(nodes.begin(), nodes.end(),
            [&b](Node*& i_nodeB) {
                return i_nodeB->node_value == b;
            }
        );
        Edge* e= new Edge((*nodeA), (*nodeB), value, d);
        (*nodeA)->edges.push_back(e);
        (*nodeB)->edges.push_back(e);
        return 1;
    }

    
    // Coloring
    void coloring(){
        

        int i=0;
        for (typename list<Node*>::iterator it=nodes.begin();it != nodes.end();++it){
            cout<<"Nodo "<<i+1<<" -> Color "<<i<<endl;
            i++;
        }
    }
};



// Main
int main() {
    int n;
    Graph<char, int> g;
    cout<< "------ Graph -------"<<endl;
          cout << "Cuantos nodos desea?" << endl;
          cout<<">> ";
          cin>>n;
          for(int i=0; i<n;i++){
              char  valor;
              cout<<"Nodo "<<i+1<<",  Que letra desea que tenga el nodo = "
              ;
              cin>>valor;
              g.InsertNode(valor);
           }
    
    cout<<endl;
    cout << "  1 = Agregar Vertices" << endl;
    cout << "  2 = Imprimir Coloreo" << endl;
    cout << "  3 = Terminar"<<endl;
    
    
    bool code=true;
          char tecla;
          while(code){
             cout<<endl;
             cout << "- Chose an a option: ";
             cin >> tecla;
             cout<<endl;
             
                    switch(tecla){
                       case '1':
                            char nodo1, nodo2;
                            int peso;
                            cout << "Ingrese los dos nodos que quiere conectar:"<<endl;
                            cout<<"Primero Nodo >> ";
                            cin>>nodo1;
                            cout<<"Segundo Nodo >> ";
                            cin>>nodo2;
                            cout<<"Peso >> ";
                            cin>>peso;
                            g.InsertEdge(nodo1, nodo2, peso, true);
                            break;
             
                       case '2':
                        cout << "Coloreo: ";
                            g.coloring();
                        break;
                            
                       case '3':
                        code=false;
                        break;
             }
        }
}
