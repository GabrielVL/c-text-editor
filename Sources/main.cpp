#include<iostream>
#include "../Header/memoryManager.cpp.h"
#include <QApplication>



int main(int argc, char *argv[])
{
    /*QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();*/

    memoryManager *m = new memoryManager;
    int usage = m->CurrentUsage();

    std::cout << "Memory Usage: " << usage << " bytes\n";


}
