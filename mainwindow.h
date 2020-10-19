#ifndef MAINWINDOW_H
#define MAINWINDOW_H

/*
 * Toolbar:
 *
 * doc.qt.io/archives/qt-4.8/qt-demos-mainwindow-example.html
 *
 */

#include <QMainWindow>
#include <vector>
#include "figure.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
private:
    QMenu    *menuFigure;
    QAction  *actionFigure1;
    bool Figure1_selected = 0;
    bool Figure2_selected = 0;
    std::vector<Figure*> FirstType_figures;
    std::vector<Figure*> SecondType_figures;
    Figure *f;

protected:
    void contextMenuEvent(QContextMenuEvent *event);

public:
    MainWindow(QWidget *parent = 0);
    QToolBar* createToolBar();
    ~MainWindow();

public slots:
	void Figure1(bool checked);
	void Figure2(bool checked);
	void AddFigures();	
	void DeleteFigures();
	void FigureClicked();
};

#endif // MAINWINDOW_H
