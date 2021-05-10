//
// Created by mauro on 4/22/21.
//

#include <QTextStream>
#include <iomanip>

#include "../Headers/memoryManager.h"


//string* vectorTipos = malloc(100 * sizeof(string*));

class MainWindow;

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
    if(tipo == "char"){
        memoria[indiceMemoria] = indice+'0';
        indiceMemoria++;
    } else if (tipo == "int" || tipo == "float"){
        indiceMemoria += 4;
        for(int i = indiceMemoria; i < indiceMemoria; i++){
            memoria[i] = indice+'0';

        }
    } else if (tipo == "long" || tipo == "double") {
        indiceMemoria += 8;
        for(int i = indiceMemoria; i < indiceMemoria; i++){
            memoria[i] = indice+'0';

        }
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

int memoryManager::obtenerPosicion(int ind, std::string tipo){
    if (tipo == "int" || tipo == "float"){
        ind += 3;
    } else if (tipo == "long" || tipo == "double") {
        ind += 7;
    }
    return ind;
}

QString pointerToQString(void *ptr)
{
    std::ostringstream oss;
    oss << "0x" << std::uppercase << std::hex << uintptr_t(ptr);
    return QString(oss.str().c_str());
}

/*Esta funcion es la encargada de imprimir el estado de la memoria */
void memoryManager::imprimirEstado(Ui::MainWindow *ui){
    int indMemoria = 0;
    QString tipo;
    QString etiqueta;
    QString valor;
    indice -= 1;
    for (int i = 0; i < indice; i++ ){
        tipo = QString::fromStdString(vectorTipos[i]);
        etiqueta = QString::fromStdString(vectorEtiquetas[i]);
        valor = QString::fromStdString(vectorValores[i]);
        QString referencia = pointerToQString((void *) &memoria[indMemoria]);
        indMemoria = obtenerPosicion(indMemoria,tipo.toUtf8().constData());
        ui->RamList->addItem("Tipo: " + tipo);
        ui->RamList->addItem("Etiqueta: " + etiqueta);
        ui->RamList->addItem("Valor: " + valor);
        ui->RamList->addItem("Posición en memoria: " + referencia);
        ui->RamList->addItem(" ");
        indMemoria++;
    }
    clearVector();
}

void memoryManager::clearVector() {
    vectorTipos.clear();
    vectorEtiquetas.clear();
    vectorValores.clear();
    indice = 0;
}

