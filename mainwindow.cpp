#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent)
{
    myCanvas = new QMyCanvas;
    myCanvas->setObjectName("myCanvas");
    myCanvas->setStyleSheet("myCanvas{qproperty-lineColor: #36404C;}");

    setCentralWidget(myCanvas);
    iniDockWidget();
    resize(800,600);

    connect(mytoolbar->btn1,SIGNAL(clicked()),myCanvas, SLOT(Draw1()));
    connect(mytoolbar->btn2,SIGNAL(clicked()),myCanvas, SLOT(Draw2()));
    connect(mytoolbar->btn3,SIGNAL(clicked()),myCanvas, SLOT(Draw3()));
    connect(mytoolbar->btn4,SIGNAL(clicked()),myCanvas,  SLOT(Draw4()));
    connect(mytoolbar->btn5,SIGNAL(clicked()),myCanvas,  SLOT(Draw5()));
    connect(mytoolbar->btn6,SIGNAL(clicked()), myCanvas, SLOT(Draw6()));
    connect(mytoolbar->btn7,SIGNAL(clicked()), myCanvas, SLOT(Draw7()));
}

MainWindow::~MainWindow()
{
}


void MainWindow::iniDockWidget()
{
        mytoolbar = new QMyToolBar;
        dockWidgetL = new QDockWidget(tr("TB"), this);
        dockWidgetL->setAllowedAreas(Qt::LeftDockWidgetArea);
        dockWidgetL->setFeatures(QDockWidget::AllDockWidgetFeatures);
        dockWidgetL->setFloating(false);
        dockWidgetL->setWidget(mytoolbar);
        dockWidgetL->setVisible(true);
        addDockWidget(Qt::LeftDockWidgetArea, dockWidgetL);
}

