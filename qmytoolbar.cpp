#include "qmytoolbar.h"
#include "qmycanvas.h"

QMyToolBar::QMyToolBar(QWidget *parent) :
    QWidget(parent)
{
    btn1 = new QToolButton(this);
    btn1->setIcon(QIcon(":/btn1_off.png"));
    btn1->setGeometry ( 0, 0, 80, 80 );
    btn1->setIconSize(QSize(80,80));

    btn2 = new QToolButton(this);
    btn2->setIcon(QIcon(":/btn2_on.png"));
    btn2->setGeometry ( 0, 80, 80, 80 );
    btn2->setIconSize(QSize(60,60));

    btn3 = new QToolButton(this);
    btn3->setIcon(QIcon(":/btn3_on.png"));
    btn3->setGeometry ( 0, 160, 80, 80 );
    btn3->setIconSize(QSize(80,80));

    btn4 = new QToolButton(this);
    btn4->setIcon(QIcon(":/btn4_on.png"));
    btn4->setGeometry ( 0, 240, 80, 80 );
    btn4->setIconSize(QSize(80,80));

    btn5 = new QToolButton(this);
    btn5->setIcon(QIcon(":/btn5_on.png"));
    btn5->setGeometry ( 0, 320, 80, 80 );
    btn5->setIconSize(QSize(80,80));

    btn6 = new QToolButton(this);
    btn6->setIcon(QIcon(":/btn6_on.png"));
    btn6->setGeometry ( 0, 400, 80, 80 );
    btn6->setIconSize(QSize(80,80));

    btn7 = new QToolButton(this);
    btn7->setIcon(QIcon(":/btn7_on.png"));
    btn7->setGeometry ( 0, 480, 80, 80 );
    btn7->setIconSize(QSize(80,80));

    this->setMinimumWidth(80);
    this->setMaximumWidth(80);

    nBtnNo=1;
    btn = btn1;

    connect(btn1,SIGNAL(clicked()), this, SLOT(ChangeBtnPng1()));
    connect(btn2,SIGNAL(clicked()), this, SLOT(ChangeBtnPng2()));
    connect(btn3,SIGNAL(clicked()), this, SLOT(ChangeBtnPng3()));
    connect(btn4,SIGNAL(clicked()), this, SLOT(ChangeBtnPng4()));
    connect(btn5,SIGNAL(clicked()), this, SLOT(ChangeBtnPng5()));
    connect(btn6,SIGNAL(clicked()), this, SLOT(ChangeBtnPng6()));
    connect(btn7,SIGNAL(clicked()), this, SLOT(ChangeBtnPng7()));


}

void QMyToolBar::ChangeBtnPng1()
{
    if(nBtnNo == 1 )
        return;
    QString str;
    str.sprintf(":/btn%d_on.png",nBtnNo);

    btn->setIcon(QIcon(str));
    btn->setGeometry ( 0, 80*(nBtnNo-1), 80, 80 );
    btn->setIconSize(QSize(80,80));


    btn1->setIcon(QIcon(":/btn1_off.png"));
    btn1->setGeometry ( 0, 0, 80, 80 );
    btn1->setIconSize(QSize(80,80));

    nBtnNo=1;
    btn=btn1;
}

void QMyToolBar::ChangeBtnPng2()
{
    if(nBtnNo == 2 )
        return;
    QString str;
    str.sprintf(":/btn%d_on.png",nBtnNo);

    btn->setIcon(QIcon(str));
    btn->setGeometry ( 0, 80*(nBtnNo-1), 80, 80 );
    btn->setIconSize(QSize(80,80));

    btn2->setIcon(QIcon(":/btn2_off.png"));
    btn2->setGeometry ( 0, 80, 80, 80 );
    btn2->setIconSize(QSize(80,80));

    nBtnNo=2;
    btn=btn2;
}

void QMyToolBar::ChangeBtnPng3()
{
    if(nBtnNo == 3 )
        return;
    QString str;
    str.sprintf(":/btn%d_on.png",nBtnNo);

    btn->setIcon(QIcon(str));
    btn->setGeometry ( 0, 80*(nBtnNo-1), 80, 80 );
    btn->setIconSize(QSize(80,80));

    btn3->setIcon(QIcon(":/btn3_off.png"));
    btn3->setGeometry ( 0, 160, 80, 80 );
    btn3->setIconSize(QSize(80,80));

    nBtnNo=3;
    btn=btn3;
}

void QMyToolBar::ChangeBtnPng4()
{
    if(nBtnNo == 4 )
        return;
    QString str;
    str.sprintf(":/btn%d_on.png",nBtnNo);

    btn->setIcon(QIcon(str));
    btn->setGeometry ( 0, 80*(nBtnNo-1), 80, 80 );
    btn->setIconSize(QSize(80,80));

    btn4->setIcon(QIcon(":/btn4_off.png"));
    btn4->setGeometry ( 0, 240, 80, 80 );
    btn4->setIconSize(QSize(80,80));

    nBtnNo=4;
    btn=btn4;
}

void QMyToolBar::ChangeBtnPng5()
{
    if(nBtnNo == 5 )
        return;
    QString str;
    str.sprintf(":/btn%d_on.png",nBtnNo);

    btn->setIcon(QIcon(str));
    btn->setGeometry ( 0, 80*(nBtnNo-1), 80, 80 );
    btn->setIconSize(QSize(80,80));

    btn5->setIcon(QIcon(":/btn5_off.png"));
    btn5->setGeometry ( 0, 320, 80, 80 );
    btn5->setIconSize(QSize(80,80));

    nBtnNo=5;
    btn=btn5;
}

void QMyToolBar::ChangeBtnPng6()
{
    if(nBtnNo == 6 )
        return;
    QString str;
    str.sprintf(":/btn%d_on.png",nBtnNo);

    btn->setIcon(QIcon(str));
    btn->setGeometry ( 0, 80*(nBtnNo-1), 80, 80 );
    btn->setIconSize(QSize(80,80));

    btn6->setIcon(QIcon(":/btn6_off.png"));
    btn6->setGeometry ( 0, 400, 80, 80 );
    btn6->setIconSize(QSize(80,80));

    nBtnNo=6;
    btn=btn6;
}

void QMyToolBar::ChangeBtnPng7()
{
    if(nBtnNo == 7 )
        return;
    QString str;
    str.sprintf(":/btn%d_on.png",nBtnNo);

    btn->setIcon(QIcon(str));
    btn->setGeometry ( 0, 80*(nBtnNo-1), 80, 80 );
    btn->setIconSize(QSize(80,80));

    btn7->setIcon(QIcon(":/btn7_off.png"));
    btn7->setGeometry ( 0, 480, 80, 80 );
    btn7->setIconSize(QSize(80,80));

    nBtnNo=7;
    btn=btn7;
}

