#ifndef DRAWPOINTCLOUD_H
#define DRAWPOINTCLOUD_H

#include <QObject>
#include <vtkRenderWindow.h>
#include <pcl/io/pcd_io.h>
#include <pcl/point_types.h>
#include <pcl/visualization/pcl_visualizer.h>

class DrawPointCloud : public QObject
{
    Q_OBJECT
public:
    explicit DrawPointCloud(QObject *parent = nullptr);
    void drawPointCloud();
signals:
    void updatePointCloud(pcl::PointCloud<pcl::PointXYZ>::Ptr cloud);

public slots:

private:
    pcl::PointCloud<pcl::PointXYZ>::Ptr cloud;
};

#endif // DRAWPOINTCLOUD_H
