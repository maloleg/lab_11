#pragma once
#include <QMainWindow>
#include <QWidget>

class MainWindow : public QMainWindow
{
    Q_OBJECT    
public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    void createFormInterior();
};