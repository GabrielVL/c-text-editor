#include "../Headers/mainwindow.h"
#include "../Headers/memoryManager.h"

#include <QApplication>
#include <iostream>


int main(int argc, char *argv[])
{
    memoryManager *mem = new memoryManager(100);
    /*Aqui estamos  simulando el ingreso de otra variable */
    std::string tipo = std::string("char");
    std::string nombre = std::string("letra1");
    std::string valor = std::string("4");
    mem->recibirInstrucciones( tipo, nombre, valor);
    mem->imprimirEstado();
    std::cout<<"*******************************************"<<std::endl;
    /*Aqui estamos  simulando el ingreso de otra variable */
    tipo = std::string("int");
    nombre = std::string("numero1");
    valor = std::string("8");
    mem->recibirInstrucciones( tipo, nombre, valor);
    mem->imprimirEstado();
    std::cout<<"*******************************************"<<std::endl;

    /*Aqui estamos  simulando el ingreso de otra variable */
    tipo = std::string("int");
    nombre = std::string("numero2");
    valor = std::string("10");
    mem->recibirInstrucciones( tipo, nombre, valor);
    mem->imprimirEstado();
    std::cout<<"*******************************************"<<std::endl;

    /*Aqui estamos  simulando el ingreso de otra variable */
    tipo = std::string("char");
    nombre = std::string("letra2");
    valor = std::string("4");
    mem->recibirInstrucciones( tipo, nombre, valor);
    mem->imprimirEstado();
    std::cout<<"*******************************************"<<std::endl;

    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return QApplication::exec();
}
