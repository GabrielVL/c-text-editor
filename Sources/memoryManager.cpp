//
// Created by mauro on 4/22/21.
//

#include <QTextStream>
#include <iomanip>

#include "../Headers/memoryManager.h"

class MainWindow;

memoryManager::memoryManager(int bytes) {
    memoria = (char*) malloc(bytes);
    indice = 0;
    indiceMemoria = 0;
}

memoryManager::~memoryManager() = default;

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
void memoryManager::recibirInstrucciones(std::string tipo, std::string etiqueta, std::string valor){
    vectorTipos.push_back(tipo);
    vectorEtiquetas.push_back(etiqueta);
    vectorValores.push_back(valor);
    insertarMemoria(tipo);
    indice++;
}

int memoryManager::obtenerPosicion(int ind, std::string tipo){
    if (tipo == "int" || tipo == "float"){
        ind += 3;
    } else if (tipo == "long" || tipo == "double") {
        ind += 7;
    }
    return ind;
}

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

QString memoryManager::pointerToQString(void *ptr)
{
    std::ostringstream oss;
    oss << "0x" << std::uppercase << std::hex << uintptr_t(ptr);
    return QString(oss.str().c_str());
}

void memoryManager::clearVector() {
    vectorTipos.clear();
    vectorEtiquetas.clear();
    vectorValores.clear();
    indice = 0;
}

