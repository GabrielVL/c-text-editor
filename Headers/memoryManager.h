//
// Created by mauro on 4/24/21.
//

#ifndef C_TEXT_EDITOR_MEMORYMANAGER_CPP_H
#define C_TEXT_EDITOR_MEMORYMANAGER_CPP_H

#include "ui_mainwindow.h"

/**
 * Administra una cantidad de memoria determinada al IDE
 */
class memoryManager {

private:


    /**
     * Array que almacena las posiciones de memoria de la RAM
     */
    char *memoria;

    /**
     * Ayuda a mantener las referencias de las posicones del array
     */
    int indice;

    /**
     * Ayuda a mantener las referencias de las posicones del array
     */
    int indiceMemoria;

    /**
     * Vector que almacena los tipos de los datos almacenados
     */
    std::vector<std::string> vectorTipos;

    /**
     * Vector que almacena las etiquetas de las variables almacenadas
     */
    std::vector<std::string> vectorEtiquetas;

    /**
     * Vector que almacena los valores de las variables almacenadas
     */
    std::vector<std::string> vectorValores;

public:

    /**
     * Crea el objeto que administra la memoria
     * @param bytes Memoria a administrar en bytes
     */
    memoryManager(int bytes);

    /**
     * Destructor del administrador de memoria
     */
    virtual ~memoryManager();

    /**
     * Se encarga de insertar en la memoria RAM reservada  dependiendo del tipo de dato
     * @param tipo
     */
    void insertarMemoria(std::string tipo);

    /**
     * Esta funcion se encarga de manejar la logica de un tipo un etiqueta y un valor
     * @param tipo Tipo de dato de una variable
     * @param etiqueta Nombre etiquetado a la variable
     * @param valor Valor que guarda la variable
     */
    void recibirInstrucciones(std::string tipo, std::string etiqueta, std::string valor);

    /**
     * Esta funcion se encarga de obtener la posicicion de la memoria resevarda dependiento del tipo
     * @param ind posición actual recorrida
     * @param tipo Utilizado para recorrer el array según el tamaño que necesita el tipo
     * @return posición nueva
     */
    int obtenerPosicion(int ind, std::string tipo);

    /**
     * Muestra el estado de la memoria en la sección de RAM del IDE
     * @param ui Ventana principal
     */
    void imprimirEstado(Ui::MainWindow *ui);

    /**
     * Encargada de mostrar punteros en un string
     * @param ptr Puntero a mostrar
     * @return QString para mostrar el puntero en pantalla
     */
    QString pointerToQString(void *ptr);

    /**
     * Limpia el vector y el índice del administrador de memoria
     */
    void clearVector();


};

#endif //C_TEXT_EDITOR_MEMORYMANAGER_CPP_H
