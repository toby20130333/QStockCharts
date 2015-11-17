#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QToolButton>
#include <QtGui>
#include <QDockWidget>
#include "qmytoolbar.h"
#include "qmycanvas.h"
class MainWindow : public QMainWindow {
    Q_OBJECT
public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void iniDockWidget();

private:
    QDockWidget*	dockWidgetL;
    QMyCanvas*          myCanvas;
    QMyToolBar*         mytoolbar;
};

#endif // MAINWINDOW_H
