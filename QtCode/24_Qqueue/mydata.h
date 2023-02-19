#ifndef MYDATA_H
#define MYDATA_H

#include<QQueue>
#include <string>
#include <vector>
#include <QMap>
using namespace std;
typedef struct
{
    int pointId;
    float x; //x坐标
    float y; //y坐标
    float z; //Z坐标
    float azimuth; //角度
    float dist; //距离
    float intensity; //强度
    string timeStamp; //时间戳
}Point;
class MyData
{
public:
    MyData();
    int* data_char;
    int size;
    int id;
};

extern QMap<QString,QQueue<Point>*> d_queue;

#endif // MYDATA_H
