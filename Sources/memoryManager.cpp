//
// Created by mauro on 4/22/21.
//

#include <iostream>
#include <vector>
#include <string>

#include "../Headers/memoryManager.h"


//string* vectorTipos = malloc(100 * sizeof(string*));

memoryManager::memoryManager(int bytes) {
    memoria = (char*) malloc(bytes);
    indice = 0;
    indiceMemoria = 0;
}

memoryManager::~memoryManager() {

}


/*Esta funcion lo que realiza es insertar el valor del tipo en el  vectorEtiquetas que guarda todos los vectorTipos*/
void memoryManager::insertarTipo(std::string tipo){
    vectorTipos.push_back(tipo);

}
/*Esta funcion lo que realiza es insertar el valor del nombre en el  vectorEtiquetas que guarda todos los vectorEtiquetas*/
void memoryManager::insertarEtiqueta(std::string nombre){
    vectorEtiquetas.push_back(nombre);
}
/*Esta funcion lo que realiza es insertar el valor del valor en el  vectorEtiquetas que guarda todos los vectorValores*/
void memoryManager::insertarValor(std::string valor){
    vectorValores.push_back(valor);
}

//vectorTipos[char][int][char][int]
//vectorEtiquetas[numero][pi][kk][raiz]
//vectorValores[4][3][c][25]
//indiceMem 6
//indice 3
//[0][1][1][1][1][2][3][3][3][3]

/*Esta funcion se encarga de  insertar en la memoria RAM reservada  dependiendo si es un int o es un char*/
void  memoryManager::insertarMemoria(std::string tipo){
    std::string entero = "int";
    std::string caracter = "char";
    if(tipo == entero){
        for(int i = indiceMemoria ; i < indiceMemoria+4 ; i++){
            memoria[i] = indice+'0';

        }
        indiceMemoria = indiceMemoria+4;
    }

    else if (tipo==caracter){
        memoria[indiceMemoria] = indice+'0';
        indiceMemoria++;
    }

}
/*Esta funcion se encarga de manejar la logica dependiento  de un tipo un nombre y un valor*/
void memoryManager::recibirInstrucciones(std::string tipo, std::string nombre, std::string valor){
    insertarTipo(tipo);
    insertarEtiqueta(nombre);
    insertarValor(valor);
    insertarMemoria(tipo);
    indice++;
}

/*Esta funcion se encarga de obtener la posicicion de la memoria resevarda dependiento del tipo */

int memoryManager::obtenerPosicion(int indice, std::string tipo){
    std::string entero=("int");
    std::string caracter=("char");
    // cout<<"TIPO INGRESADO "<<tipo<<endl;
    if(tipo==entero){
        return indice+3;
    }
    else if (tipo==caracter){
        return indice;
    }
}
/*Esta funcion es la encargada de imprimir el estado de la memoria */
void memoryManager::imprimirEstado(){
    std::string entero=("int");
    std::string caracter=("char");
    int indMemoria=0;
    for (int i = 0; i < indice; i++ ){
        std::string tipo = vectorTipos[i];
        std::string nombre = vectorEtiquetas[i];
        std::string valor = vectorValores[i];
        indMemoria=obtenerPosicion(indMemoria,tipo);
        std::cout<<"MEMORY POSITION: "<<(void*)&memoria[indMemoria] <<"...........TIPO: "<<tipo<< "...........NOMBRE: "<<nombre<<"...........VALOR: "<<valor<<std::endl;
        indMemoria++;
    }
}

