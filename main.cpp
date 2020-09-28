#include <iostream>
#include <QtWidgets/QApplication>
// #include <QWidget>
// #include "Lab11.h"
#include "MWindow.h"

int main(int argc, char** argv){
    QApplication app(argc, argv);

    // QWidget w;
    // w.setWindowTitle(("Heeello"));
    // w.show();
    MainWindow window;
    window.show();
    // std::cout << "Heelllo" << std::endl;
    return app.exec();
} 
