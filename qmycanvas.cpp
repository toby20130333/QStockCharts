/*********************************************************************************
  *Copyright(C),2014-2015,www.heilqt.com
  *FileName(文件名):  example stock charts
  *Author  (作者):    TobyYi(tanboy@heilqt.com)
  *Version (版本):    2.0.0
  *CreateDate(创建日期):
  *FinishDate(完成日期):
  *Description(描述):
     1.用于主要说明此程序文件完成的主要功能
     2.与其他模块或函数的接口、输出值、取值范围、含义及参数间的控制、顺序、独立及依赖关系

  *Others(其他内容说明):
       others
  *Function List(函数列表):
     1.主要函数列表，每条记录应包含函数名及功能简要说明

     2.
  *History(历史修订记录):
     1.Date: 修改日期
       Author:修改者
       Modification:修改内容简介

     2.

**********************************************************************************/

#include "qmycanvas.h"
#include <QMessageBox>
#include <QApplication>

QMyCanvas::QMyCanvas(QWidget *parent):
    QWidget(parent)
{
    m_Color = QColor("#F29E08");
    mousePoint =QPoint(0,0);
    yLinjieMin=0.0;
    yLinjieMax=0.0;
    rightAligned = false;
    this->setAutoFillBackground(true);
    QPalette palette;
    palette.setColor(QPalette::Window, QColor("#313233"));
    this->setPalette(palette);
    setMouseTracking(true);
    //最小屏幕宽度
    this->setMinimumWidth(BORDER_SIZE*2+COORDINATE_X1+COORDINATE_X2+MINCONTENTWIDTH);
    this->setMinimumHeight(BORDER_SIZE*2+COORDINATE_Y1+COORDINATE_Y2+MINCONTENTHEIGHT);
    doDraw = 1;
}

QColor QMyCanvas::lineColor()
{
    return m_Color;
}

void QMyCanvas::setLineColor(QColor color)
{
    m_Color = color;
    emit lineColorChanged();
    update();
}

void QMyCanvas::setLSpace( QString& str, int n )
{
    for( int i=0 ;i<n; i++ )
    {
        str.push_front(" ");
    }
}


void QMyCanvas::paintEvent(QPaintEvent* event)
{
    if( doDraw == 1 )
        DrawFSJL("000001K","20100310");
    else    if( doDraw == 2 )
        DrawFSJL("000002J","20100311");
    else    if( doDraw == 3 )
        DrawFSJL("000012J","20100311");
    else        if( doDraw == 4 )
        DrawFSJL("000001K","20100310");
    else            if( doDraw == 5 )
        DrawFSJL("000002J","20100311");
    else               if( doDraw == 6 )
        DrawFSJL("000012J","20100311");
    else                    if( doDraw == 7 )
        DrawBK();
        DrawLines();
        //drawShape();
            DrawBK();
}

void QMyCanvas::resizeEvent(QResizeEvent * event)
{
    m_x = this->width();
    m_y = this->height();
}

void QMyCanvas::DrawBK()
{
    QPainter painter(this);
    QPen     pen;
    pen.setColor(QColor("#836033"));
    painter.setPen(pen);

    //边框
    painter.drawLine(0+BORDER_SIZE,0+BORDER_SIZE,0+BORDER_SIZE,m_y-BORDER_SIZE);//左|
    painter.drawLine(0+BORDER_SIZE,0+BORDER_SIZE,m_x-BORDER_SIZE,0+BORDER_SIZE);//上-
    painter.drawLine(m_x-BORDER_SIZE,0+BORDER_SIZE,m_x-BORDER_SIZE,m_y-BORDER_SIZE);//右|
    painter.drawLine(0+BORDER_SIZE,m_y-BORDER_SIZE,m_x-BORDER_SIZE,m_y-BORDER_SIZE);//下-

    painter.drawLine(0+BORDER_SIZE+COORDINATE_X1,0+BORDER_SIZE+COORDINATE_Y1,
                     0+BORDER_SIZE+COORDINATE_X1,m_y-BORDER_SIZE-COORDINATE_Y2);//左|
    painter.drawLine(0+BORDER_SIZE+COORDINATE_X1,0+BORDER_SIZE+COORDINATE_Y1,
                     m_x-BORDER_SIZE-COORDINATE_X2,0+BORDER_SIZE+COORDINATE_Y1);//上-
    painter.drawLine(m_x-BORDER_SIZE-COORDINATE_X2,0+BORDER_SIZE+COORDINATE_Y1,
                     m_x-BORDER_SIZE-COORDINATE_X2,m_y-BORDER_SIZE-COORDINATE_Y2);//右|
    painter.drawLine(0+BORDER_SIZE+COORDINATE_X1,m_y-BORDER_SIZE-COORDINATE_Y2,
                     m_x-BORDER_SIZE-COORDINATE_X2,m_y-BORDER_SIZE-COORDINATE_Y2);//下-

    int Interval = (double)( (m_y-BORDER_SIZE-COORDINATE_Y2)- (0+BORDER_SIZE+COORDINATE_Y1) ) / 15 + 0.5;
    pen.setColor(QColor("#836033"));
    for( int i=1,j=Interval; i < 15; i++,j+=Interval)
    {
        if( i % 5 != 0 )
        {
            pen.setStyle(Qt::DashLine);
            painter.setPen(pen);
        }
        else
        {
            pen.setStyle(Qt::SolidLine);
            painter.setPen(pen);
        }
        painter.drawLine(0+BORDER_SIZE+COORDINATE_X1,0+BORDER_SIZE+COORDINATE_Y1+j,
                         m_x-BORDER_SIZE-COORDINATE_X2,0+BORDER_SIZE+COORDINATE_Y1+j);//上-
    }

    Interval = (double)( (m_x-BORDER_SIZE-COORDINATE_X2)- (0+BORDER_SIZE+COORDINATE_X1) ) / 8 + 0.5;
    for( int x=1,y=Interval; x < 8; x++,y+=Interval)
    {

        pen.setStyle(Qt::DashLine);
        painter.setPen(pen);
        painter.drawLine(0+BORDER_SIZE+COORDINATE_X1+y,0+BORDER_SIZE+COORDINATE_Y1,
                         0+BORDER_SIZE+COORDINATE_X1+y,m_y-BORDER_SIZE-COORDINATE_Y2);//左|
    }
}

void QMyCanvas::DrawFSJL(char* SecID,char* szDate)
{
    QMyData fsjl(SecID,szDate);
    if( !fsjl.ReadFSJL() )
        return;
    fsjl.GetFSJLINFO();

    QPainter painter(this);
    QPen     pen;
    pen.setColor(Qt::white);
    painter.setPen(pen);

    int Interval = (double)( (m_y-BORDER_SIZE-COORDINATE_Y2)- (0+BORDER_SIZE+COORDINATE_Y1) ) / 15 + 0.5;
    QString str;
    float Proportional;
    pen.setColor(Qt::white);
    painter.setPen(pen);
    painter.drawText(QPoint(m_x-BORDER_SIZE-COORDINATE_X2+10,
                            0+BORDER_SIZE+COORDINATE_Y1+Interval*5),
                     QString("0.00%"));     //右边百分比

    str.sprintf("%.2f",(float)fsjl.info.Start / 1000 );
    setLSpace( str, 11 - str.size() );
    painter.drawText(QPoint(0+BORDER_SIZE+5,
                            0+BORDER_SIZE+COORDINATE_Y1+Interval*5),
                     str);     //左边数值

    pen.setColor(Qt::red);
    painter.setPen(pen);
    for(int i=5 ; i > 0 ; i-- )
    {
        Proportional = (float)fsjl.info.PerValue / 100 * i;
        str.sprintf( "%.2f%%", Proportional );
        painter.drawText(QPoint(m_x-BORDER_SIZE-COORDINATE_X2+10,
                                0+BORDER_SIZE+COORDINATE_Y1+Interval*(5-i)),
                         str);
        //qDebug()<<"right: "<<Proportional;
        str.sprintf("%.2f",(float)fsjl.info.Start / 1000 * (1+Proportional/100));
        setLSpace( str, 11 - str.size() );
        painter.drawText(QPoint(0+BORDER_SIZE+5,
                                0+BORDER_SIZE+COORDINATE_Y1+Interval*(5-i)),
                         str);     //左边数值

        //最最大值
         if(i == 5){
             m_MaxY = str.toFloat();
             //qDebug()<<"left5: "<<m_MaxY;
         }
    }

    pen.setColor(Qt::green);
    painter.setPen(pen);
    for(int i=1 ; i <= 5 ; i++ )
    {
        Proportional = (float)fsjl.info.PerValue / 100 * i;
        str.sprintf( "%.2f%%", Proportional);
        painter.drawText(QPoint(m_x-BORDER_SIZE-COORDINATE_X2+10,
                                0+BORDER_SIZE+COORDINATE_Y1+Interval*(5+i)),
                         str);

        str.sprintf("%.2f",(float)fsjl.info.Start / 1000 * (1-Proportional/100));
        setLSpace( str, 11 - str.size() );
        painter.drawText(QPoint(0+BORDER_SIZE+5,
                                0+BORDER_SIZE+COORDINATE_Y1+Interval*(5+i)),
                         str);     //左边数值
        //取最小值
        if( i == 5){
            m_MinY = str.toFloat();
            //qDebug()<<"left1: "<<m_MinY;
        }
    }

    //画时刻表
    for(int i=0 ; i < 9 ; i++)
    {
        double rateI =  (double)( (m_x-BORDER_SIZE-COORDINATE_X2)- (0+BORDER_SIZE+COORDINATE_X1) ) / 8 + 0.5;
        QPoint ft(BORDER_SIZE+COORDINATE_X2-10+i*(rateI),m_y-BORDER_SIZE-COORDINATE_Y2+12);
        QDateTime time = QDateTime::fromString("09:30","HH:mm");
        QDateTime newTime;
        if(i >=4){
           newTime = time.addSecs(1800*(i+3));
        }else if(i<4){
           newTime = time.addSecs(1800*i);
        }
        QString str = newTime.toString("HH:mm");
        painter.drawText(ft,
                         str);
    }
    //画线
    //0点坐标
    int ZeroX = 0+BORDER_SIZE+COORDINATE_X1;
    int ZeroY = 0+BORDER_SIZE+COORDINATE_Y1+Interval*5;
    float XInter = float(m_x - 2 * BORDER_SIZE - COORDINATE_X1 -COORDINATE_X2)/241;
    float YInter = (float)Interval / fsjl.info.PerValue * 100  ; // Point/增长率
    int PointX1=ZeroX,PointX2=ZeroX,PointY1=ZeroY,PointY2=ZeroY;


    pen.setColor(QColor("#E1923A"));
    pen.setWidth(1);
    painter.setPen(pen);

    QLinearGradient fade(0, 0, 0, height());
    fade.setColorAt(0, QColor("#4D4D4D"));
    fade.setColorAt(0.5, QColor("#4D4D4D"));
    fade.setColorAt(0.6, QColor("#443A2F"));
    fade.setColorAt(0.7, QColor("#443A2F"));
    QColor color("#443A2F");
    color.setAlpha(0.5);
    painter.setBrush(fade);
    QVector<QPointF> lstPoints;
    lstPoints.append(QPointF(ZeroX,BORDER_SIZE+COORDINATE_Y1+Interval*10));
    for( int i=0; i < 241; i++ )
    {

        if(i == 240){
            PointX2 = this->width()-(90);
        }else{
           PointX2 = ZeroX + i* XInter;
        }

        PointY2 = ZeroY - (  float(fsjl.fsjl[i].Deal - fsjl.info.Start)/ fsjl.info.Start )* YInter*100;

        //painter.drawLine(PointX1,PointY1,PointX2,PointY2);
        lstPoints.append(QPointF(PointX1,PointY1));
        lstPoints.append(QPointF(PointX2,PointY2));
        PointX1 = PointX2;
        PointY1 = PointY2;
    }
    lstPoints.append(QPointF(PointX1,BORDER_SIZE+COORDINATE_Y1+Interval*10));
    painter.drawConvexPolygon(lstPoints);
}

void QMyCanvas::DrawLines()
{
    QLineF line(0+BORDER_SIZE+COORDINATE_X1,mousePoint.y(),this->width()-(BORDER_SIZE+COORDINATE_X1),mousePoint.y());
    QLineF line2(mousePoint.x(),BORDER_SIZE+COORDINATE_Y1,mousePoint.x(),this->height()-(BORDER_SIZE+COORDINATE_Y2));
    QPainter painter(this);
    QPen     pen;
    pen.setColor(m_Color);
    pen.setWidth(1);
    painter.setPen(pen);
    painter.drawLine(line);
    painter.drawLine(line2);
    DrawTips();
}

void QMyCanvas::DrawTips()
{
    //画竖坐标提示框
    double rangY = yLinjieMax-yLinjieMin;
    //qDebug()<<QString::fromUtf8("取出临界值 ")<<yLinjieMax<<" Interval "<<Interval;
    float rate = (mousePoint.y()-50)/rangY;
    float rangShu = m_MaxY-m_MinY;
    float yPos = (1.0-rate)*rangShu;
    //qDebug()<<" rate "<<rate<<" yPos "<<yPos<<" rangShu"<<rangShu;
    float readPosY = m_MinY+yPos;
    //qDebug()<<"readPosY "<<readPosY;
    if(readPosY< m_MinY || readPosY>m_MaxY){
        return;
    }
    QRect rect(0+BORDER_SIZE*4,mousePoint.y()-10,42,18);
    QPainter painter(this);
    QPen     pen;
    pen.setColor(Qt::white);
    QBrush brush(Qt::blue);
    painter.setBrush(brush);
    pen.setWidth(1);
    painter.setPen(pen);
    painter.drawRect(rect);
    QString text;
    text.sprintf("%.2f",readPosY);
    painter.drawText(rect,Qt::AlignCenter,text);

    QFontMetrics fm(QApplication::font());
    int pixelsWide = fm.width(text);

    QRect rect2(mousePoint+QPoint(10,-40),QSize(pixelsWide+20,30));
    drawShape(rect2,text);
}

void QMyCanvas::Draw1()
{
    if(doDraw != 1 )
    {
        doDraw = 1;
        update();}
}
void QMyCanvas::Draw2()
{
    setStyleSheet("QWidget{qproperty-lineColor: #00C853;}");
    if(doDraw != 2 )
    {
        doDraw = 2;
        update();
    }
}
void QMyCanvas::Draw3()
{
    setStyleSheet("QWidget{qproperty-lineColor: #5B7DB1;}");
    if(doDraw != 3 )
    {
        doDraw = 3;
        update();}
}
void QMyCanvas::Draw4()
{
    setStyleSheet("QWidget{qproperty-lineColor: #FF5722;}");
    if(doDraw != 4 )
    {
        doDraw = 4;
        update();
    }
}
void QMyCanvas::Draw5()
{
    if(doDraw != 5 )
    {
        doDraw = 5;
        update();
    }
}
void QMyCanvas::Draw6()
{
    if(doDraw != 6 )
    {
        doDraw = 6;
        update();
    }
}
void QMyCanvas::Draw7()
{
    if(doDraw != 7 )
    {
        doDraw = 7;
        update();
    }
}

void QMyCanvas::mouseMoveEvent(QMouseEvent *event)
{
    //qDebug()<<"----------mouseMoveEvent-----------"<<event->pos();
    mousePoint = QPoint(event->pos());

    //取出临界值
    xLinjieMin = BORDER_SIZE+COORDINATE_X1;
    xLinjieMax = m_x -(BORDER_SIZE+COORDINATE_X1);

    yLinjieMin =BORDER_SIZE+COORDINATE_Y1;
    Interval  = (double)( (m_y-BORDER_SIZE-COORDINATE_Y2)- (0+BORDER_SIZE+COORDINATE_Y1) ) / 15 + 0.5;
    yLinjieMax =m_y-BORDER_SIZE-COORDINATE_Y2-5*(Interval);

    if(mousePoint.y() < yLinjieMin || mousePoint.y() > yLinjieMax){
        return;
    }
    if(mousePoint.x() < xLinjieMin || mousePoint.x() > xLinjieMax){
        return;
    }
    update();
}

void QMyCanvas::enterEvent(QEvent *e)
{
    qDebug("----------enterEvent-----------");
}
void QMyCanvas::drawShape(const QRect& myRect,const QString& text)
{
    QPainter painter(this);
    QBrush brush(m_Color);

    painter.setBrush(brush);
    painter.setPen(Qt::NoPen);
    painter.setRenderHint(QPainter::Antialiasing);
    if (rightAligned)
    {
        painter.drawRoundedRect(myRect, 10, 10);
        const QPointF points[3] = {
            QPointF(rect().width() - 10.0, 10.0),
            QPointF(rect().width() ,20 ),
            QPointF(rect().width() - 10.0,30 ),
        };
        painter.drawConvexPolygon(points, 3);
    }
    else
    {
        painter.drawRoundedRect(myRect, 5, 5);
        const QPointF points[3] = {
            QPointF(myRect.x(), myRect.y()+20.0),
            QPointF(myRect.x()-6.0, myRect.y()+myRect.height()+6),
            QPointF(myRect.x()+10.0, myRect.y()+myRect.height()),
        };
        painter.drawConvexPolygon(points, 3);
    }
    QPen pen;
    pen.setColor(Qt::white);
    painter.setPen(pen);
    painter.drawText(myRect,Qt::AlignCenter,text);
}
