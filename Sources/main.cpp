#include "../Headers/mainwindow.h"
#include "../Headers/memoryManager.h"

#include <QApplication>
#include <iostream>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return QApplication::exec();
}
