// Nombre: Rogelio Eduardo Benavides De La Rosa
// Clase: Estructura de Datos
// C¢digo de Honor: Doy mi palabra de que he realizado esta actividad con integidad acad‚mica

#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <sstream>
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
    ifstream archivo;
    archivo.open("red_puertos.txt");
    //Declaring the variables
    string input;
    string line;
    vector<string> lineArray;
    vector<vector<string>> relationships;
    int nPorts;
    vector<string> ports;
    //Reading the number of relationships
    getline(archivo, input);
    //Converting the string to an integer
    int nRelationships = stoi(input);
    //Reading the relationships
    for (int i = 0; i < nRelationships; i++)
    {
        getline(archivo, line);
        lineArray = split(line, ' ');
        relationships.push_back(lineArray);
    }
    //Reading the number of ports
    getline(archivo, input);
    //Converting the string to an integer
    nPorts = stoi(input);
    //Reading the ports
    for(int i = 0; i < nPorts; i++)
    {
        getline(archivo, line);
        ports.push_back(line);
    }
    archivo.close();
    return 0;
}
