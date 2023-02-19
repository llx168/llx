#ifndef RADARIMAGE_H
#define RADARIMAGE_H

#include <QObject>
#include <QImage>


class RadarImage : public QObject
{
    Q_OBJECT
public:
    explicit RadarImage(QObject *parent = nullptr);
    //线程处理函数
    void drawRadarMap();

signals:
    void updateRadarImage(QImage temp);

};

#endif // RADARIMAGE_H
