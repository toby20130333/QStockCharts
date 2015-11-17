#ifndef QMYDATA_H
#define QMYDATA_H
#include <QFile>
#include <QString>
#include <stdlib.h>
#include <QTextStream>

typedef struct
{
    int  Date;
    int  Time;
    char SecID[16];
    char SecName[32];
    long Deal;
    long Vol;
    long Amt;
}FSJL;

typedef struct
{
    long Start;
    long Max;
    long Min;
    int  MaxLevel;
    int  MinLevel;
    int  PerValue;
}INFO;

class QMyData
{
public:
    QMyData();
    QMyData( char* SecID, char* Date );
    ~QMyData();

    bool ReadFSJL();
    void GetFSJLINFO();

    FSJL fsjl[241];
    INFO info;
private:
    QFile*    file;
    char szSecID[16];
    char szDate[20];
};

#endif // QMYDATA_H
