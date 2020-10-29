#pragma once

#include <QDialog>
#include <QLineEdit>
class figureDialog : public QDialog
{
    Q_OBJECT
private:
    QLineEdit* InputLine_PointA;
    QLineEdit* InputLine_PointB;
    QLineEdit* InputLine_PointC;
    QLineEdit* InputLine_PointD;
    QLineEdit* InputLine_PointE;
    QLineEdit* InputLine_PointF;
    QLineEdit* InputLine_PointDegree;
 
public:
    figureDialog(QWidget* pwgt = 0);
    QString PointA() const;
    QString PointB() const;
    QString PointC() const;
    QString PointD() const;
    QString PointE() const;
    QString PointF() const;
    QString PointDegree() const;
};
