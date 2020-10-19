#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
	srand(time(0));
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    w.resize(1000, 1000);
    
    return a.exec();
}
