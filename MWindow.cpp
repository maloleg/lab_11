#include "MWindow.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent){
    setWindowTitle(("Lab 11"));

    createFormInterior();
}

MainWindow::~MainWindow(){   
}

void MainWindow::createFormInterior()
{
    QWidget * wgt = new QWidget(this);
    setCentralWidget(wgt);

    
}