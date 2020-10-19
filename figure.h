#ifndef FIGURE_H
#define FIGURE_H

#include <QWidget>

#include <QEvent>

class Figure : public QWidget
{
    Q_OBJECT

    bool flag_paint;
    bool flag_resize;


public:
	// QEvent event;

    explicit Figure(QWidget *parent = 0);
    
protected:
    void paintEvent(QPaintEvent *event);
    void resizeEvent(QResizeEvent *event);
    void mousePressEvent(QMouseEvent *event);

signals:
    void Clicked();
public slots:
    void IsClicked();
};

#endif // FIGURE_H
