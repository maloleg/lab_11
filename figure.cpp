#include "figure.h"

#include <QPainter>
#include <iostream>
#include <QMouseEvent>
#include <QLabel>
#include <QDialog>
#include <QDebug>

Figure::Figure(QWidget *parent, std::string Fname) : QWidget(parent), flag_paint(false), flag_resize(false), name(Fname)
{
  pen.setColor(Qt::black);
  selected = false;
}


void Figure::paintEvent(QPaintEvent *event)
{
   const int mult = 4;

   auto w = width()  -1;
   auto h = height() -1;

   if( !flag_paint ) flag_paint = true;
   if( flag_paint && !flag_resize ) this->resize(mult*w+mult,mult*h+mult);

   QPainter painter(this);
   painter.setPen(pen);

   painter.scale(1.0/mult,1.0/mult);
   painter.translate(50,0);

   painter.rotate(25);

   painter.drawLine(0+mult*15,0,w,0);	// top
   painter.drawLine(w,0,w,h);	// rigth
   painter.drawLine(w,h,0,h); 	// botton
   painter.drawLine(0,h,0,0+mult*15);	// left
   painter.drawLine(0,0+mult*15,0+mult*15,0);	// diag
}

void Figure::resizeEvent(QResizeEvent *event)
{
   if( flag_paint && !flag_resize ) flag_resize = true;
}

void Figure::IsClicked(){
  std::cout << "yeah\n" << std::flush;
}

void Figure::mousePressEvent(QMouseEvent *event)
{
  // std::cout << "lol\n" << std::flush;
  if (event->button() == Qt::LeftButton){
    coords = event->pos();
    if (pen.color() == Qt::blue) {
      pen.setColor(Qt::black);
      selected = false;
    }
    else {
      pen.setColor(Qt::blue);
      selected = true;
    }
    std::cout << event->globalX() <<  "  " << event->globalY() << std::endl;
    // x = event->globalX();
    // x = event->globalY();
    // this->move(mapToParent(event-pos() - coords ));
    this->repaint();
    emit Clicked();
  }
}

void Figure::mouseMoveEvent(QMouseEvent *event){
  // if (event->button() == Qt::LeftButton){
  //   this->setCursor(QCursor(Qt::ArrowCursor));
  //   pen.setCursor(Qt::black);
  //   pressed = false;
  // }
  QRect r = geometry();
  std::cout << "x = " << r.x() << ", y = " << r.y() << ", width = " << r.width() << ", height = " << r.height() << std::endl;


  if ((event->buttons() & Qt::LeftButton) && mapToParent(event->pos() - coords).x() > 0 && mapToParent(event->pos() - coords).y() > 0 &&
                                             mapToParent(event->pos() - coords).x() < 900 && mapToParent(event->pos() - coords).y() < 930){
    this->move(mapToParent(event->pos() - coords));
    std::cout << "Global x: " << mapToParent(event->pos() - coords).x() << std::endl;
  }
}

void Figure::FigureClicked(){
  std::cout << "figure " + name + " was clicked\n" << std::flush;
}

void Figure::contextMenuEvent(QContextMenuEvent *event){
  //menuFigure->exec(event->globalPos());
    QDialog *qd = new QDialog(this);
    qd->setModal(true);
    qd->resize(1000,1000);
    QLabel *l = new QLabel("Helloooo...",qd);
    l->show();
    qd->exec();
    delete qd;
}
