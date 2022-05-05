// Nombre: Rogelio Eduardo Benavides De La Rosa
// Clase: Estructura de Datos
// C¢digo de Honor: Doy mi palabra de que he realizado esta actividad con integidad acad‚mica

#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <sstream>
#define INF 0x3f3f3f3f
using namespace std;

//Split a String
vector<string> split(string str, char delimiter) {
    vector<string> internal;
    stringstream ss(str); // Turn the string into a stream.
    string tok;
    while(getline(ss, tok, delimiter)) {
        internal.push_back(tok);
    }
    return internal;
}

int main(int argc, char const *argv[])
{
    //Opening the file
    ifstream file;
    file.open("red_puertos.txt");
    //Declaring the variables
    string input;
    string line;
    vector<string> lineArray;
    vector<vector<string>> relationships;
    int nPorts;
    vector<string> ports;
    //Reading the number of relationships
    getline(file, input);
    //Converting the string to an integer
    int nRelationships = stoi(input);
    //Reading the relationships
    for (int i = 0; i < nRelationships; i++)
    {
        getline(file, line);
        lineArray = split(line, ' ');
        relationships.push_back(lineArray);
    }
    //Reading the number of ports
    getline(file, input);
    //Converting the string to an integer
    nPorts = stoi(input);
    //Reading the ports
    for(int i = 0; i < nPorts; i++)
    {
        getline(file, line);
        ports.push_back(line);
    }
    //Closing the file
    file.close();
    //Creating the adjacency matrix
    int adjMatrix[nPorts][nPorts];
    //Initializing the adjacency matrix in Infinite
    for(int i = 0; i < nPorts; i++)
    {
        for(int j = 0; j < nPorts; j++)
        {
            adjMatrix[i][j] = INF;
        }
    }
    //Auxiliary variables
    int port1;
    int port2;
    //Creating the adjacency matrix
    for(int i = 0; i < nRelationships; i++)
    {
        port1 = 0;
        port2 = 0;
        for(int j = 0; j < nPorts; j++)
        {
            if(ports[j] == relationships[i][0])
            {
                port1 = j;
            }
        }
        for(int j = 0; j < nPorts; j++)
        {
            if(ports[j] == relationships[i][1])
            {
                port2 = j;
            }
        }
        adjMatrix[port1][port2] = stoi(relationships[i][2]);
        adjMatrix[port2][port1] = stoi(relationships[i][2]); // Quitar si es un grafo no dirigido
    }
    // Printing the adjacency matrix
    // for(int i = 0; i < nPorts; i++)
    // {
    //     for(int j = 0; j < nPorts; j++)
    //     {
    //         cout << adjMatrix[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    //Port variables
    string port1String;
    string port2String;
    //Asking for the port 1
    cout << "Ingrese el puerto 1: ";
    cin >> port1String;
    //Asking for the port 2
    cout << "Ingrese el puerto 2: ";
    cin >> port2String;

    //Checking if the ports are valid
    for(int i = 0; i < nPorts; i++){
        if(ports[i] == port1String){
            port1 = i;
        }
        else if(ports[i] == port2String){
            port2 = i;
        }
    }
    
    //Dijkstra's algorithm
    //Declaration of the variables and arrays for the dijkstra's algorithm
    bool know[nPorts];
    int cost[nPorts];
    int path[nPorts];
    int known = 0;
    int actualPort = port2;
    //Initializing the variables of the arrays for the dijkstra's algorithm
    for (int i = 0; i < nPorts; i++)
    {
        cost[i] = INF;
        path[i] = -1;
        know[i] = false;
    }
    // Cost on port 2 is equal to 0 because it is the ending point
    cost[port2] = 0;
    
    do{
        know[actualPort] = true;
        known++;
        int menor = INF;
        int minimumIndex = 0;
        //Cicle to find the minimum cost
        for (int col = 0; col < nPorts; col++)
        {
            //If the cost is less than the minimum cost and the node has not been visited
            if(adjMatrix[actualPort][col] != INF && know[col] == false)
            {
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
    } while(known < nPorts);

    //Printing the path from the starting point to the ending point
    cout << "\nRuta m s corta:\n";
    int nextPort = port1;
    while(path[nextPort]!= -1){
        cout << ports[nextPort] << "->";
        nextPort = path[nextPort];
    }
    cout  << ports[port2] << "\nDistancia: " << cost[port1] << " millas na£ticas"<< endl;
    return 0;
}
