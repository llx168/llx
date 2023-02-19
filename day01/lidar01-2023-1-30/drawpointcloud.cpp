#include "drawpointcloud.h"

DrawPointCloud::DrawPointCloud(QObject *parent) : QObject(parent)
{
    cloud.reset(new pcl::PointCloud<pcl::PointXYZ>());
}

void DrawPointCloud::drawPointCloud()
{

    cloud->clear();
    //画随机扰动的圆
    double distance = 30;
    int x,y = 0;
    double azimuth = 0;
    int ran = 0;
//    for(int k=0;k<36;k++){

        for(int i=0;i<100;i++){
            ran = qrand()%3;
            azimuth = 360.0/100.0*i/180.0*M_PI;
            x = (distance+ran)*cos(azimuth);
            y = (distance+ran)*sin(azimuth);
//            cloud->push_back(pcl::PointXYZ(x, y, 20.0/36.0*k));
            cloud->push_back(pcl::PointXYZ(x, y, 0.0));
        }
//    }

//    //花心形线
//    double azimuth = 0.0;
//    double x,y = 0.0;
//    for(int i=0;i<720;i++){
//        azimuth = 360.0/720.0*i/180.0*M_PI;
//        y=16*pow(sin(azimuth),3);
//        x=13*cos(azimuth)-5*cos(2*azimuth)-2*cos(azimuth*3)-cos(4*azimuth);
//        cloud->push_back(pcl::PointXYZ(x, y, 0));
//    }


//    x=2.*(sin(i)-sin(2*i)./2);
//    y=2.*(cos(i)-cos(i).^2);



    emit updatePointCloud(cloud);


}
