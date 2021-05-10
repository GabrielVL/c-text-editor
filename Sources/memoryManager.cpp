//
// Created by mauro on 4/22/21.
//

#include <iostream>
#include <vector>
#include <string>
#include <typeinfo>
#include <cstring>
#include <ctype.h>
#include <list>

using namespace std;

//string* tipos = malloc(100 * sizeof(string*));
char memoria [100];
string valores [100];
string tipos [100];
string nombres[100];
int indice=0;
int indiceMemoria=0;


/*Esta funcion lo que realiza es insertar el valor del tipo en el  vector que guarda todos los tipos*/
void insertarTipo(vector<string>& tipos,string tipo){
    tipos.push_back(tipo);

}
/*Esta funcion lo que realiza es insertar el valor del nombre en el  vector que guarda todos los nombres*/
void insertarNombre(vector<string>& nombres,string nombre){
    nombres.push_back(nombre);
}
/*Esta funcion lo que realiza es insertar el valor del valor en el  vector que guarda todos los valores*/
void insertarValor(vector<string>& valores,string valor){
    valores.push_back(valor);
}

//tipos[char][int][char][int]
//nombres[numero][pi][kk][raiz]
//valores[4][3][c][25]
//indiceMem 6
//indice 3
//[0][1][1][1][1][2][3][3][3][3]

/*Esta funcion se encarga de  insertar en la memoria RAM reservada  dependiendo si es un int o es un char*/
void  insertarMemoria( char *memoria,int *indice,int *indiceMemoria,string tipo){
    string entero=("int");
    string caracter=("char");
    if(tipo==entero){
        int i = *indiceMemoria;
        for(i = *indiceMemoria ; i < *indiceMemoria+4 ; i++){
            memoria[i]=*indice+'0';

        }
        *indiceMemoria=*indiceMemoria+4;
    }

    else if (tipo==caracter){
        memoria[*indiceMemoria]=*indice+'0';
        *indiceMemoria=*indiceMemoria+1;
    }
    *indice=*indice+1;

}
/*Esta funcion se encarga de manejar la logica dependiento  de un tipo un nombre y un valor*/
void recibirInstrucciones(string tipo,string nombre,string valor,vector<string>& tipos,vector<string>& nombres,vector<string>& valores,char memoria[], int *indice,int *indiceMemoria ){
    insertarTipo(tipos,tipo);
    insertarNombre(nombres,nombre);
    insertarValor(valores,valor);
    insertarMemoria(memoria,indice,indiceMemoria,tipo);
    indice++;
}

/*Esta funcion se encarga de obtener la posicicion de la memoria resevarda dependiento del tipo */

int obtenerPosicion(int indice,string tipo){
    string entero=("int");
    string caracter=("char");
    // cout<<"TIPO INGRESADO "<<tipo<<endl;
    if(tipo==entero){
        return indice+3;
    }
    else if (tipo==caracter){
        return indice;
    }
}
/*Esta funcion es la encargada de imprimir el estado de la memoria */
void imprimirEstado(char *memoria,int indice,int indiceMemoria,vector<string>& tipos,vector<string>& nombres,vector<string>& valores){
    string entero=("int");
    string caracter=("char");
    char **memo=&memoria;
    //char **posicion=&memoria;
    int indMemoria=0;
    for (int i=0; i<indice; i++ ){
        string tipo=tipos[i];
        string nombre=nombres[i];
        string valor=valores[i];
        indMemoria=obtenerPosicion(indMemoria,tipo);
        cout<<"MEMORY POSITION: "<<(void*)&memoria[indMemoria] <<"...........TIPO: "<<tipo<< "...........NOMBRE: "<<nombre<<"...........VALOR: "<<valor<<endl;
        indMemoria=indMemoria+1;
    }
}




int main() {
    //Aqui creamos el array de memoria
    char *memoria= (char*) malloc(100);
    //Aqui creamos una variables que nos ayudaran a mantener referencia de ls posicones del array
    int indice=0;
    int indiceMemoria=0;
    //Aqui creamos las listas para la demas informacion
    vector<string> tipos;
    vector<string> nombres;
    vector<string> valores;
    /*Aqui estamos  simulando el ingreso de otra variable */
    string tipo=string("char");
    string nombre=string("letra1");
    string valor=string("4");
    recibirInstrucciones( tipo, nombre, valor,tipos,nombres,valores, memoria,  &indice, &indiceMemoria );
    imprimirEstado(memoria,indice,indiceMemoria,tipos,nombres,valores);
    cout<<"*******************************************"<<endl;
    /*Aqui estamos  simulando el ingreso de otra variable */
    tipo=string("int");
    nombre=string("numero1");
    valor=string("8");
    recibirInstrucciones( tipo, nombre, valor,tipos,nombres,valores, memoria,  &indice, &indiceMemoria );
    imprimirEstado(memoria,indice,indiceMemoria,tipos,nombres,valores);
    cout<<"*******************************************"<<endl;

    /*Aqui estamos  simulando el ingreso de otra variable */
    tipo=string("int");
    nombre=string("numero2");
    valor=string("10");
    recibirInstrucciones( tipo, nombre, valor,tipos,nombres,valores, memoria,  &indice, &indiceMemoria );
    imprimirEstado(memoria,indice,indiceMemoria,tipos,nombres,valores);
    cout<<"*******************************************"<<endl;

    /*Aqui estamos  simulando el ingreso de otra variable */
    tipo=string("char");
    nombre=string("letra2");
    valor=string("4");
    recibirInstrucciones( tipo, nombre, valor,tipos,nombres,valores, memoria,  &indice, &indiceMemoria );
    imprimirEstado(memoria,indice,indiceMemoria,tipos,nombres,valores);
    cout<<"*******************************************"<<endl;

    //imprimirEstado(memoria,indice,indiceMemoria,tipos,nombres,valores);




    return 0;

}