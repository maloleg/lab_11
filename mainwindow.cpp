#include "mainwindow.h"

#include "figure.h"

#include <QApplication>
#include <QAction>
#include <QMenu>
#include <QMenuBar>
#include <QToolBar>
#include <QMenu>


#include <QContextMenuEvent>

#include <QDialog>
#include <QLabel>
#include <iostream>
#include <QLabel>
MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent){


    actionFigure1 = new QAction(tr("&Act"), this);
    connect(actionFigure1,SIGNAL(triggered()),
            QApplication::instance(),SLOT(quit()));



    addToolBar(Qt::TopToolBarArea, createToolBar());

    // Figure *f = new Figure(this);
    //     f->move(10,10);
    //     f->show();


//     QMenu *fileMenu = menuBar()->addMenu(tr("&File"));
//     QMenu *menuFigure = menuBar()->addMenu(tr("&Figure 1"));
//     QToolBar *ToolBar = addToolBar(tr("Figure 1"));
//     const QIcon F1Icon = QIcon::fromTheme("document-new", QIcon());
//     QAction *Figure1_action = new QAction(F1Icon, tr("&figure 1"), this);
//     connect (Figure1_action, SIGNAL(toggled()), this, SLOT(Figure1_Slot()));
//     menuFigure->addAction(actionFigure1);
//     ToolBar->addAction(Figure1_action);




//     
 }

QToolBar* MainWindow::createToolBar(){

    


    QToolBar* tb = new QToolBar("ToolBar for figuries buttons");

    QAction* Figure1 = new QAction(QIcon::fromTheme("document-new", QIcon()), "figure 1", this);
    Figure1->setCheckable(true);
    connect(Figure1, SIGNAL(toggled(bool)), this, SLOT(Figure1(bool)));

    QAction* Figure2 = new QAction(QIcon::fromTheme("document-new", QIcon()), "figure 2", this);
    Figure2->setCheckable(true);
    connect(Figure2, SIGNAL(toggled(bool)), this, SLOT(Figure2(bool)));

    tb->addAction(Figure1); 
    tb->addAction(Figure2);
    tb->addAction(QIcon::fromTheme("document-new", QIcon()), "Add", this, SLOT(AddFigures())); 
    tb->addAction(QIcon::fromTheme("document-new", QIcon()), "Delete", this, SLOT(DeleteFigures())); 


    // std::cout << "NOT HERE\n" << std::flush;

    return tb;
}

void MainWindow::Figure1(bool checked){
    
    if (checked) {
        Figure1_selected = checked;
        std::cout << "Figure 1 selected " << checked << std::endl;
    }
    else {
        std::cout << "Figure 1 unselected " << checked << std::endl;
        Figure1_selected = checked;
    }
}
void MainWindow::Figure2(bool checked){
    if (checked) {
        Figure2_selected = checked;
        std::cout << "Figure 2 selected "<< std::endl;
    }
    else {
        std::cout << "Figure 2 unselected " << std::endl;
        Figure2_selected = checked;
    }
}
void MainWindow::AddFigures(){
    if (Figure1_selected && Figure2_selected) {
        std::cout << "Figures 1, 2 added" << std::endl;
        Figure *f = new Figure(this);
        f->move(40,40);
        f->show();
        // FirstType_figures.push_back(Figure(this));
        Figure *f2 = new Figure(this);
        f2->move(100,100);
        f2->show();
    }
    if (Figure1_selected && !Figure2_selected){
        std::cout << "Figure 1 added" << std::endl;
        Figure *f = new Figure(this);
        // f->move(10,10);
        FirstType_figures.push_back(f);
        FirstType_figures[0]->show();
        FirstType_figures[0]->move(10, 10);
    }
    if (!Figure1_selected && Figure2_selected) {
        std::cout << "Figure 2 added" << std::endl;
        Figure *f2 = new Figure(this);
        f2->move(50,50);
        f2->show();
    }
    if (!Figure1_selected && !Figure2_selected) std::cout << "Nothing added" << std::endl;


}

void MainWindow::DeleteFigures(){
    // layout()->removeAt(FirstType_figures[0]);
    FirstType_figures[0]->close();
    FirstType_figures.pop_back();
    if (Figure1_selected && Figure2_selected) std::cout << "Figures 1, 2 deleted" << std::endl;
    if (Figure1_selected && !Figure2_selected) std::cout << "Figure 1 deleted" << std::endl;
    if (!Figure1_selected && Figure2_selected) std::cout << "Figure 2 deleted" << std::endl;
    if (!Figure1_selected && !Figure2_selected) std::cout << "Nothing deleted" << std::endl;
}

MainWindow::~MainWindow()
{
    
}

void MainWindow::contextMenuEvent(QContextMenuEvent *event)
{
  //menuFigure->exec(event->globalPos());
    QDialog *qd = new QDialog(this);
    qd->setModal(true);
    qd->resize(1000,1000);
    QLabel *l = new QLabel("Helloooo...",qd);
    l->show();
    qd->exec();
    delete qd;
}
