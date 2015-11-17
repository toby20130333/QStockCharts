#ifndef QMYTOOLBAR_H
#define QMYTOOLBAR_H

#include <QWidget>
#include <QToolButton>
#include <QMessageBox>
#include <QString>
class QMyToolBar : public QWidget
{
Q_OBJECT
public:
    explicit QMyToolBar(QWidget *parent = 0);
    QToolButton* btn1;
    QToolButton* btn2;
    QToolButton* btn3;
    QToolButton* btn4;
    QToolButton* btn5;
    QToolButton* btn6;
    QToolButton* btn7;
private:

    QToolButton* btn;
    int nBtnNo;
public slots:
    void ChangeBtnPng1();
    void ChangeBtnPng2();
    void ChangeBtnPng3();
    void ChangeBtnPng4();
    void ChangeBtnPng5();
    void ChangeBtnPng6();
    void ChangeBtnPng7();
};

#endif // QMYTOOLBAR_H
