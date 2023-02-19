#ifndef POINTCLOUDPROCESS3D_H
#define POINTCLOUDPROCESS3D_H

#include <pcl/io/pcd_io.h>
#include <pcl/point_types.h>
#include <pcl/filters/statistical_outlier_removal.h>


#include <iostream>
#include <thread>

#include <pcl/console/parse.h>
#include <pcl/filters/extract_indices.h>
#include <pcl/filters/passthrough.h>
#include <pcl/segmentation/region_growing.h>
#include <pcl/features/normal_3d.h>
#include <pcl/sample_consensus/ransac.h>
#include <pcl/sample_consensus/sac_model_plane.h>
#include <pcl/sample_consensus/sac_model_sphere.h>
#include <pcl/visualization/pcl_visualizer.h>

using namespace std::chrono_literals;

class PointCloudProcess3D
{
public:
    PointCloudProcess3D();

    //移除离群点
    pcl::PointCloud<pcl::PointXYZ>::Ptr statisticalRemovalFilter(pcl::PointCloud<pcl::PointXYZ>::Ptr cloud);
    
    //点云分割
    void regionGrowingSegmentation(pcl::PointCloud<pcl::PointXYZ>::Ptr cloud);




};

#endif // POINTCLOUDPROCESS3D_H
