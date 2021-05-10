//
// Created by mauro on 4/24/21.
//

#ifndef C_TEXT_EDITOR_MEMORYMANAGER_CPP_H
#define C_TEXT_EDITOR_MEMORYMANAGER_CPP_H

#include "ui_mainwindow.h"

class memoryManager {

private:

    //Aqui creamos el array de memoria
    char *memoria;
    //Aqui creamos una variables que nos ayudaran a mantener referencia de ls posicones del array
    int indice;
    int indiceMemoria;
    //Aqui creamos las listas para la demas informacion
    std::vector<std::string> vectorTipos;
    std::vector<std::string> vectorEtiquetas;
    std::vector<std::string> vectorValores;

public:

    memoryManager(int bytes);

    virtual ~memoryManager();

    void insertarTipo(std::string tipo);

    void insertarEtiqueta(std::string nombre);

    void insertarValor(std::string valor);

    void insertarMemoria(std::string tipo);

    void recibirInstrucciones(std::string tipo, std::string nombre, std::string valor);

    int obtenerPosicion(int ind, std::string tipo);

    void imprimirEstado(Ui::MainWindow *ui);

    void clearVector();
};

#endif //C_TEXT_EDITOR_MEMORYMANAGER_CPP_H
