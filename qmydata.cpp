#include "qmydata.h"
QMyData::QMyData()
{    
    memset(fsjl,0,sizeof(FSJL)*241);
}

QMyData::QMyData( char* SecID, char* Date )
{
    strcpy(szSecID , SecID );
    strcpy( szDate , Date) ;
    memset(fsjl,0,sizeof(FSJL)*241);
}

QMyData::~QMyData()
{
    file->close();
}


void QMyData::GetFSJLINFO()
{
    int UpRate = 0,DnRate=0;
    info.Start = fsjl[0].Deal;

    info.Max = fsjl[0].Deal;
    for( int i=1; i<241; i++ )
    {
        if( info.Max < fsjl[i].Deal )
            info.Max = fsjl[i].Deal;
    }

    info.Min = fsjl[0].Date;
    for( int i=1; i<241; i++ )
    {
        if( info.Min > fsjl[i].Deal )
            info.Min = fsjl[i].Deal;
    }

    if( info.Max > info.Start )
    {
        UpRate = (double)( info.Max - info.Start ) / info.Start * 10000;
    }

    if( info.Min < info.Start )
    {
        DnRate = (double)( info.Start - info.Min ) / info.Start * 10000;
    }

    if( UpRate > DnRate )
        info.PerValue = ( UpRate / 40 / 5 + 1 ) * 40;
    else
        info.PerValue = ( DnRate / 40 / 5 + 1 ) * 40;
}



bool QMyData::ReadFSJL()
{
    QString str;
    char    line[1024];
    char    *token;
    str.sprintf("./FSJL.%s.%s",szSecID,szDate);
    file = new QFile(str);
    if( !file->open(QFile::ReadOnly) )
        return false;

    for( int i=0; i < 241; i++ )
    {
        if( file->readLine(line,1024)  > 0 )
        {
            token = strtok( line, "|" );
            if( token != NULL )
                fsjl[i].Date = atoi(token);

            token = strtok( NULL, "|" );
            if( token != NULL )
                fsjl[i].Time = atoi(token);

            token = strtok( NULL, "|" );
            if( token != NULL )
                strcpy(fsjl[i].SecID,token);

            token = strtok( NULL, "|" );
            if( token != NULL )
                strcpy(fsjl[i].SecName,token);

            token = strtok( NULL, "|" );
            if( token != NULL )
                fsjl[i].Deal = atoi(token);

            token = strtok( NULL, "|" );
            if( token != NULL )
                fsjl[i].Vol = atoi(token);

            token = strtok( NULL, "|" );
            if( token != NULL )
                fsjl[i].Amt = atoi(token);
        }
    }
    return true;
}

