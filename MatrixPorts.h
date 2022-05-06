// Nombre: Rogelio Eduardo Benavides De La Rosa
// Clase: Estructura de Datos
// C¢digo de Honor: Doy mi palabra de que he realizado esta actividad con integidad acad‚mica
// Fecha de entrega: 06/05/2022

#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#define INF 0x3f3f3f3f
using namespace std;

class MatrixPorts
{
private:
    vector <string> ports;
    vector <vector <int>> adjMatrix;
public:
    MatrixPorts(vector<string> ports, vector<vector<string>> relationships);
    void dijkstra(int start, int end);
};

//Constructor Method
MatrixPorts::MatrixPorts(vector<string> ports, vector<vector<string>> relationships)
{
    //Importing the ports
    this->ports = ports;
    //Initializing the adjacency matrix in Infinite
    for(int i = 0; i < ports.size(); i++)
    {
        vector<int> aux;
        for(int j = 0; j < ports.size(); j++)
        {
            aux.push_back(INF);
        }
        adjMatrix.push_back(aux);
    }
    //Auxiliary variables
    int port1;
    int port2;
    //Creating the adjacency matrix
    for(int i = 0; i < relationships.size(); i++)
    {
        port1 = 0;
        port2 = 0;
        for(int j = 0; j < ports.size(); j++)
        {
            if(ports[j] == relationships[i][0])
            {
                port1 = j;
            }
            else if(ports[j] == relationships[i][1])
            {
                port2 = j;
            }
        }
        adjMatrix[port1][port2] = stoi(relationships[i][2]);
        adjMatrix[port2][port1] = stoi(relationships[i][2]);
    }
}

//Dijkstra Method
void MatrixPorts::dijkstra(int start, int end){
    //Declaration of the variables and arrays for the dijkstra algorithm
    bool know[adjMatrix.size()];
    int cost[adjMatrix.size()];
    int path[adjMatrix.size()];
    int known = 0;
    int actualPort = end;
    //Initializing the variables of the arrays for the dijkstra's algorithm
    for (int i = 0; i < adjMatrix.size(); i++)
    {
        cost[i] = INF;
        path[i] = -1;
        know[i] = false;
    }
    // Cost on port 2 is equal to 0 because it is the ending point
    cost[end] = 0;
    // Calculating the cost of the traveling through the ports
    do{
        know[actualPort] = true;
        known++;
        int menor = INF;
        int minimumIndex = 0;
        //Cicle to find the minimum cost
        for (int col = 0; col < adjMatrix.size(); col++)
        {
            //If the cost is less than the minimum cost and the node has not been visited
            if(adjMatrix[actualPort][col] != INF && know[col] == false)
            {
                //If the cost is less than the minimum cost
                if(cost[col] > cost[actualPort] + adjMatrix[actualPort][col]){
                    cost[col] = cost[actualPort] + adjMatrix[actualPort][col];
                    path[col] = actualPort;
                }
            }
            //If the cost is less than the minimum cost and the node has been visited
            if(cost[col] < menor && know[col] == false){
                menor = cost[col];
                minimumIndex = col;
            }
        }
        //The actual port will be the port with the minimum cost
        actualPort = minimumIndex;
    } while(known < adjMatrix.size());

    //Printing the path from the starting point to the ending point
    cout << "\nRuta m s corta:\n";
    int nextPort = start;
    while(path[nextPort]!= -1){
        cout << ports[nextPort] << "->";
        nextPort = path[nextPort];
    }
    cout  << ports[end] << "\nDistancia: " << cost[start] << " millas na£ticas"<< endl;

}