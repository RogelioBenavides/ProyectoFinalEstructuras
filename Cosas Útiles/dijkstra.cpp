//Rogelio Eduardo Benavides De La Rosa
//Doy mi palabra de que he realizado este programa con integridad academica
//Programa que calcula el camino mas corto entre dos puntos
#include <iostream>
#define INF 0x3f3f3f3f
using namespace std;

//M‚todo main
int main()
{
    //Declaraci¢n de arreglos
    bool know[8];
    int cost[8];
    int path[8];
    int adjMat[8][8];
    int start = 5;
    //Inicializaci¢n de arreglos
    for (int i = 0; i < 8; i++)
    {
        cost[i] = INF;
        path[i] = -1;
        know[i] = false;
        for (int j = 0; j < 8; j++)
        {
            adjMat[i][j] = INF;
        }
    }
    //Asignaci¢n de valores
    adjMat[0][2]=8;
    adjMat[2][0]=8;
    adjMat[0][3]=2;
    adjMat[3][0]=2;
    adjMat[1][5]=6;
    adjMat[5][1]=6;
    adjMat[1][6]=8;
    adjMat[6][1]=8;
    adjMat[2][4]=6;
    adjMat[4][2]=6;
    adjMat[2][5]=6;
    adjMat[5][2]=6;
    adjMat[3][7]=8;
    adjMat[7][3]=8;
    adjMat[4][6]=3;
    adjMat[6][4]=3;
    adjMat[5][6]=6;
    adjMat[6][5]=6;
    adjMat[5][7]=3;
    adjMat[7][5]=3;
    adjMat[6][7]=1;
    adjMat[7][6]=1;

    //Inicializaci¢n de variables
    cost[start] = 0;
    int verdaderos = 0;
    int vactual = start;

    //Ciclo que calcula el camino mas corto
    do{
        know[vactual] = true;
        verdaderos++;
        int menor = INF;
        int idxMenor = 0;
        //Ciclo que busca el menor costo
        for (int col = 0; col < 8; col++)
        {
            //Si el costo es menor que el menor costo y el nodo no ha sido visitado
            if(adjMat[vactual][col] != INF && know[col] == false)
                if(cost[col] > cost[vactual] + adjMat[vactual][col]){
                    cost[col] = cost[vactual] + adjMat[vactual][col];
                    path[col] = vactual;
            }
            //Si el costo es menor que el menor costo y el nodo ha sido visitado
            if(cost[col] < menor && know[col] == false){
                menor = cost[col];
                idxMenor = col;
            }
        }
        //Se asigna el valor por el que va a empezar el ciclo
        vactual = idxMenor;
    } while(verdaderos < 8);

    //Impresi¢n de resultados
    for (int i = 0; i < 8; i++)
    {
        int sig = i;
        while(path[sig]!= -1){
            cout << sig << "<-";
            sig = path[sig];
        }
        cout << start << " costo: " << cost[i] << endl;
    }
    
    return 0;
}
