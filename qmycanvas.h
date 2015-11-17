#ifndef QMYCANVAS_H
#define QMYCANVAS_H

#include <QWidget>
#include <QPaintEvent>
#include <QPainter>
#include <QMouseEvent>
#include <QDebug>
#include <QDateTime>

#include <QString>
#include "qmydata.h"
#define BORDER_SIZE         10              //边框
#define COORDINATE_X1       80              //坐标(相对边框)
#define COORDINATE_Y1       40
#define COORDINATE_X2       80
#define COORDINATE_Y2       20

#define MINCONTENTWIDTH     240             //一个屏幕最少展示240点宽度的数据
#define MINCONTENTHEIGHT    180             //一个屏幕最少展示180点高度点的数据

class QMyCanvas : public QWidget
{
    Q_OBJECT
    Q_PROPERTY(QColor lineColor READ lineColor WRITE setLineColor NOTIFY lineColorChanged)
public:
    explicit QMyCanvas(QWidget *parent = 0);
    QColor lineColor();
    void setLineColor(QColor color);
signals:
    void lineColorChanged();
private:
    void DrawBK();
    void resizeEvent(QResizeEvent * event);
    void paintEvent(QPaintEvent* event);
    void DrawFSJL(char* SecID,char* szDate);

    void DrawLines();
    void DrawTips();

    void setLSpace( QString& str, int n );
    int  m_x,m_y;
    int  doDraw;
    float m_MaxY;
    float m_MinY;
    double yLinjieMin;
    double yLinjieMax;
    double xLinjieMin;
    double xLinjieMax;

    double Interval;
    QColor m_Color;
    bool rightAligned;
    QPoint mousePoint;
public slots:
    void Draw1();
    void Draw2();
    void Draw3();
    void Draw4();
    void Draw5();
    void Draw6();
    void Draw7();
    void drawShape(const QRect& myRect,const QString& text);
protected:
    void mouseMoveEvent(QMouseEvent* event);
    void enterEvent(QEvent *);
};

#endif // QMYCANVAS_H
