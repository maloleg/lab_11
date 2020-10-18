#include "figure.h"

#include <QPainter>

Figure::Figure(QWidget *parent) :
    QWidget(parent),
    flag_paint(false), flag_resize(false)
{
}


void Figure::paintEvent(QPaintEvent *event)
{
   const int mult = 4;

   auto w = width()  -1;
   auto h = height() -1;

   if( !flag_paint ) flag_paint = true;
   if( flag_paint && !flag_resize ) this->resize(mult*w+mult,mult*h+mult);

   QPainter painter(this);

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
