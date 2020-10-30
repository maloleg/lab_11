#ifndef FIGURE_H
#define FIGURE_H

#include <QWidget>

#include <QEvent>

#include <QPainter>




class Figure : public QWidget
{
    Q_OBJECT

    bool flag_paint;
    bool flag_resize;
    
    std::string name;
    int x = 0;
    int y = 0;
    QPen pen;
    QPoint coords;
    double Angle;
    uint64_t start = 0;
    int direction;
    int type;
    double A;
    double B;
    double C;
    double D;
    double E;
    double F;

    double A_temp;
    double B_temp;
    double C_temp;
    double D_temp;
    double E_temp;
    double F_temp;

    // figureDialog *D;
    // QPainter painter;


public:
	bool selected;
	// QEvent event;

    explicit Figure(QWidget *parent = 0, std::string Fname = "", int t = 1);
    
protected:
    void paintEvent(QPaintEvent *event);
    void resizeEvent(QResizeEvent *event);
    void mousePressEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
    // void contextMenuEvent(QContextMenuEvent *event);
    
    double fRand(double fMin, double fMax){
	    double f = (double)rand() / RAND_MAX;
	    return fMin + f * (fMax - fMin);
	}

signals:
    void Clicked();
public slots:
    void IsClicked();
    void FigureClicked();
    void Rotation();
    void RotationDir();
};

#endif // FIGURE_H
