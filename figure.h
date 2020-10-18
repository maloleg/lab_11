#ifndef FIGURE_H
#define FIGURE_H

#include <QWidget>

class Figure : public QWidget
{
    Q_OBJECT

    bool flag_paint;
    bool flag_resize;

public:
    explicit Figure(QWidget *parent = 0);
    
protected:
    void paintEvent(QPaintEvent *event);
    void resizeEvent(QResizeEvent *event);

signals:
    
public slots:
    
};

#endif // FIGURE_H
