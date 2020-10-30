#include "dialog.h"
#include <QLabel>
#include<QPushButton>
#include <QGridLayout>
#include <QDialog>
figureDialog::figureDialog(QWidget* pwgt):QDialog(pwgt, Qt::WindowTitleHint | Qt::WindowSystemMenuHint){

    QLineEdit *InputLine_PointA = new QLineEdit;
    QLineEdit *InputLine_PointB = new QLineEdit;
    QLineEdit *InputLine_PointC = new QLineEdit;
    QLineEdit *InputLine_PointD = new QLineEdit;
    QLineEdit *InputLine_PointE = new QLineEdit;
    QLineEdit *InputLine_PointF = new QLineEdit;
    QLineEdit *InputLine_Degree = new QLineEdit;
    QLabel* line_PointA = new QLabel("&PointA");
    QLabel* line_PointB = new QLabel("&PointB");
    QLabel* line_PointC = new QLabel("&PointC");
    QLabel* line_PointD = new QLabel("&PointD");
    QLabel* line_PointE = new QLabel("&PointE");
    QLabel* line_PointF = new QLabel("&PointF");
    QLabel* line_Degree = new QLabel("&Angle");
    line_PointA->setBuddy(InputLine_PointA);
    line_PointB->setBuddy(InputLine_PointB);
    line_PointC->setBuddy(InputLine_PointC);
    line_PointD->setBuddy(InputLine_PointD);
    line_PointE->setBuddy(InputLine_PointE);
    line_PointF->setBuddy(InputLine_PointF);
    line_Degree->setBuddy(InputLine_Degree);
    QPushButton* Ok = new QPushButton("&Ok");
    QPushButton* Cancel = new QPushButton("&Cancel");


    


    QGridLayout* Layout = new QGridLayout;
    Layout->addWidget(line_PointA, 0, 0);
    Layout->addWidget(InputLine_PointA, 0, 1);
    Layout->addWidget(line_PointB, 1, 0);
    Layout->addWidget(InputLine_PointB, 1, 1);
    Layout->addWidget(line_PointC, 2, 0);
    Layout->addWidget(InputLine_PointC, 2, 1);
 
    Layout->addWidget(line_PointD, 3, 0);
    Layout->addWidget(InputLine_PointD, 3, 1);
 
    Layout->addWidget(line_PointE, 4, 0);
    Layout->addWidget(InputLine_PointE, 4, 1);
    Layout->addWidget(line_PointF, 5, 0);
    Layout->addWidget(InputLine_PointF, 5, 1);
    Layout->addWidget(line_Degree, 6, 0);
    Layout->addWidget(InputLine_Degree, 6, 1);
    Layout->addWidget(Ok, 7,0);
    Layout->addWidget(Cancel, 7, 1);
    setLayout(Layout);

    connect(Ok, SIGNAL(clicked()), this, SLOT(accept()));
    connect(Cancel, SIGNAL(clicked()), this, SLOT(reject()));
}
QString figureDialog::PointA() const{
    return InputLine_PointA->text();
}
QString figureDialog::PointB() const{
    return InputLine_PointB->text();
}
QString figureDialog::PointC() const{
    return InputLine_PointC->text();
}
QString figureDialog::PointD() const{
    return InputLine_PointD->text();
}
QString figureDialog::PointE() const{
    return InputLine_PointE->text();
}
QString figureDialog::PointF() const{
    return InputLine_PointF->text();
}
QString figureDialog::PointDegree() const{
    return InputLine_PointDegree->text();
}