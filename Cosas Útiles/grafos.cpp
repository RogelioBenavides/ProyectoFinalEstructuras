// Realizado por: Rogelio Eduardo Benavides De La Rosa

#include <iostream>
using namespace std;
#include "GraphMP.h"
// aplicación que utiliza matriz de adyacencias sin ponderación

int main()
{
    GraphMP<char> grafo;

    char vertices[10];
    vertices[0] = 'a';
    vertices[1] = 'b';
    vertices[2] = 'c';
    vertices[3] = 'd';
    vertices[4] = 'e';
    vertices[5] = 'f';
    vertices[6] = 'g';
    vertices[7] = 'h';

    grafo.insertVertices(vertices,8);

    grafo.insert('a','e', 4);
    grafo.insert('b','c', 7);
    grafo.insert('b','d', 23);
    grafo.insert('b','g', 5);
    grafo.insert('c','e', 1);
    grafo.insert('d','h', 16);
    grafo.insert('f','d', 39);
    grafo.insert('g','e', 2);

    grafo.print();  

    grafo.remove('g','e');

    grafo.print();  
    
    return 0;
}
