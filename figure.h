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


public:
	bool selected;
	// QEvent event;

    explicit Figure(QWidget *parent = 0, std::string Fname = "");
    
protected:
    void paintEvent(QPaintEvent *event);
    void resizeEvent(QResizeEvent *event);
    void mousePressEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
    void contextMenuEvent(QContextMenuEvent *event);

signals:
    void Clicked();
public slots:
    void IsClicked();
    void FigureClicked();
};

#endif // FIGURE_H
