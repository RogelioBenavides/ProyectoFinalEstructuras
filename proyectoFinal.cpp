// Nombre: Rogelio Eduardo Benavides De La Rosa
// Clase: Estructura de Datos
// C¢digo de Honor: Doy mi palabra de que he realizado esta actividad con integidad acad‚mica
// Fecha de entrega: 06/05/2022
// Casos de prueba:
// Balboa -> Chittagong: Balboa->Barcelona->Algeciras->Ambarli->Chittagong - Distancia: 12787 millas na£ticas
// Alexandria -> Charleston: Alexandria->Algeciras->Callao->Charleston - Distancia: 10520 millas na£ticas
// Cai_Me-> Bandar: Cai_Me->Bremen->Algeciras->Bandar Distancia: 15642 millas na£ticas
#include "MatrixPorts.h"

int main(int argc, char const *argv[])
{
    //Asking the name of the file
    cout << "Ingresa el nombre del archivo: ";
    string fileName;
    cin >> fileName;
    //Opening the file
    ifstream file;
    file.open(fileName);
    //Declaring the variables
    string input;
    string line;
    vector<string> lineArray(3);
    vector<vector<string>> relationships;
    int nPorts;
    vector<string> ports;
    //Reading the number of relationships
    int nRelationships;
    file >> nRelationships;
    //Reading the relationships
    for (int i = 0; i < nRelationships; i++)
    {
        file >> lineArray[0] >> lineArray[1] >> lineArray[2];
        relationships.push_back(lineArray);
    }
    //Reading the number of ports
    file >> nPorts;
    //Reading the ports
    for(int i = 0; i < nPorts; i++)
    {
        file >> line;
        ports.push_back(line);
    }
    //Closing the file
    file.close();
    //Creating the matrix
    MatrixPorts Matrix(ports, relationships);
    //Auxiliary variables
    int port1;
    int port2;
    //Port variables
    string port1String;
    string port2String;
    bool port1Found;
    bool port2Found;
    do{
        port1Found = false;
        port2Found = false;
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
                port1Found = true;
            }
            else if(ports[i] == port2String){
                port2 = i;
                port2Found = true;
            }
        }

        //If one of the ports is not valid
        if(!(port1Found && port2Found)){
            //If port 1 is not found
            if(!port1Found){
                cout << "Puerto 1 no encontrado" << endl;
            }
            //If port 2 is not found
            if(!port2Found){
                cout << "Puerto 2 no encontrado" << endl;
            }
            cout << "Por favor ingresar los puertos correctamente" << endl << endl;
        }
        
        //If the ports are valid
    }while(!(port1Found && port2Found));
    
    //Running the dijkstra algorithm
    Matrix.dijkstra(port1, port2);
    return 0;
}
