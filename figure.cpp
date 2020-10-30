#include "figure.h"

#include <QPainter>
#include <iostream>
#include <QMouseEvent>
#include <QLabel>
#include <QDialog>
#include <QDebug>
#include <QIcon>
#include <QAction>
#include <QApplication>
#include <QAction>
#include <QMenu>
#include <QMenuBar>
#include <QToolBar>
#include <QMenu>
#include <QPushButton>


#include <QContextMenuEvent>

#include <QDialog>
#include <QLabel>
#include <iostream>
#include <QLabel>
#include <QMouseEvent>
#include <QLineEdit>
#include "dialog.h"
// #include <QDebug>
Figure::Figure(QWidget *parent, std::string Fname, int t) : QWidget(parent), flag_paint(false), flag_resize(false), name(Fname)
{
  type = t;
  pen.setColor(Qt::black);
  selected = false;
  Angle = 0;
  direction = -1;
  A = this->fRand(0, 5*(height()  -0.0)/3);
  B = this->fRand(0, 5*(height()  -0.0)/3);
  C = this->fRand(0, 5*(height()  -0.0)/3);
  D = this->fRand(0, 5*(height()  -0.0)/3);
  E = this->fRand(0, 5*(width()  -0.0)/4);
  F = this->fRand(0, 5*(width()  -0.0)/4);
  // D = new figureDialog(0);

  std::cout << A << " " << B << " " << C << " " << D << " " << E << " " << F << " " << std::endl;
   // = new QPainter(this);
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

   painter.translate(150,50);

   // painter.scale(1.0/3, 1.0/3);



   painter.rotate(Angle);


   painter.scale(1.0/mult,1.0/mult);
   

   // painter.rotate(25);
   if (type == 1){

     painter.drawLine(0, D, 0, h - C);

     painter.drawLine(C, h, w - B, h);

     painter.drawLine(w, h - B, w, A);

     painter.drawLine(D, 0, w - A, 0);


     painter.drawArc(w - A*2, 0, A*2, A*2, 0*16, 90*16);
     painter.drawLine(w, h-B, w-B, h);
     painter.drawLine(C, h, 0, h- C);
     painter.drawArc(0, 0, D*2, D*2, 90*16, 90*16);
   }
   else if (type == 2){
     painter.drawLine(0, D, 0, h - C);

     painter.drawLine(C, h, w - B, h);

     painter.drawLine(w, h - B, w, A);

     painter.drawLine(D, 0, w - A, 0);


     painter.drawArc(w - A, -A, A*2, A*2, 180*16, 90*16);
     painter.drawArc(w - B*2, h - B*2, B*2, B*2, -90*16, 90*16);
     painter.drawArc(0 - C, h - C, C*2, C*2, 90*16, -90*16);
     painter.drawArc(0 - D, 0 - D, D*2, D*2, -90*16, 90*16);

     painter.drawLine(w/2 - F/2, h, w/2 - F/2, h + F/2);
     painter.drawLine(w/2 - F/2, h + F/2, w/2 + F/2, h + F/2);
     painter.drawLine(w/2 + F/2, h + F/2, w/2 + F/2, h);


     // painter.drawLine(C*5, h, 0, h- C*5);
     // painter.drawArc(0, 0, D*10, D*10, 90*16, 90*16);
   }
   
   // painter.drawLine(start+mult*15,start,start+w,start);	// top
   // painter.drawLine(start+w,start,start+w,start+h);	// rigth
   // painter.drawLine(start+w,start+h,start+0,start+h); 	// botton
   // painter.drawLine(start+0,start+h,start+0,start+0+mult*15);	// left
   // painter.drawLine(start+0,start+0,+mult*15,start+0+mult*15,start+0);	// diag
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
  else if(event->button() == Qt::RightButton){
      figureDialog *D = new figureDialog(this);
      D->show();

      if (D->exec() == QDialog::Accepted){

        if (D->PointA().size() > 0) std::cout << D->PointA().toStdString();
    }
      // std::cout << "afaegaw" << std::endl;

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

void Figure::Rotation(){
  Angle += 10*direction;
  this->repaint();
}

void Figure::RotationDir(){
  if (direction == 1){
    direction = -1;
  }
  else direction = 1;
}

// void Figure::contextMenuEvent(QContextMenuEvent *event){
//   //menuFigure->exec(event->globalPos());
//     if (pen.color() == Qt::blue) {
//       pen.setColor(Qt::black);
//       selected = false;
//     }
//     else {
//       pen.setColor(Qt::blue);
//       selected = true;
//     }

//     this->repaint();
//     QDialog *qd = new QDialog(this);

//     qd->setModal(true);
//     qd->resize(200,300);
//     // QLabel *LAngle = new QLabel("Angle", qd);
//     // QLabel *LPointA = new QLabel("Point A", qd);
//     // QLabel *LPointB = new QLabel("Point B", qd);
//     // QLabel *LPointC = new QLabel("Point C", qd);
//     // QLabel *LPointD = new QLabel("Point D", qd);

//     // LAngle->move(0, 0);
//     // LPointA->move(0, 30);
//     // LPointB->move(0, 60);
//     // LPointC->move(0, 90);
//     // LPointD->move(0, 120);
//     // // QLabel *l = new QLabel("Helloooo...",qd);
//     // QLineEdit *Angle = new QLineEdit("", qd);
//     // Angle->move(100,0);
//     // QLineEdit *PointA = new QLineEdit("", qd);
//     // PointA->move(100,30);
//     // QLineEdit *PointB = new QLineEdit("", qd);
//     // PointB->move(100,60);
//     // QLineEdit *PointC = new QLineEdit("", qd);
//     // PointC->move(100,90);
//     // QLineEdit *PointD = new QLineEdit("", qd);
//     // PointD->move(100,120);
//     // if (type == 2){
//     //   QLabel *LPointF = new QLabel("Point F", qd);
//     //   LPointF->move(0, 150);
//     //   QLineEdit *PointF = new QLineEdit("", qd);
//     //   PointF->move(100,150);
//     // }


//     // QLabel *ltext = new QLabel("&Point A", qd);
//     // ltext->setBuddy(l2);
//     // ltext->move(0, 50);
//     // l2->move(0, 30);
//     // b1->move()
//     QPushButton *b1 = new QPushButton("Submit", qd);
//     b1->move(0, 200);
//     // connect(b, SIGNAL(clicked()), this, SLOT(RotationDir()));
//     connect(b1, SIGNAL(pressed()), this, SLOT(Submit()));
//     // b->show();
//     // qd->addAction(QIcon::fromTheme("document-new", QIcon()), "Add", this, SLOT(IsClicked())); 

//     // l->show();
//     qd->exec();
//     delete qd;
// }
