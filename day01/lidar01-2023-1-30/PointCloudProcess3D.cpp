#include "PointCloudProcess3D.h"


PointCloudProcess3D::PointCloudProcess3D()
{

}

pcl::PointCloud<pcl::PointXYZ>::Ptr PointCloudProcess3D::statisticalRemovalFilter(pcl::PointCloud<pcl::PointXYZ>::Ptr cloud)
{
    //过滤后的结果
    pcl::PointCloud<pcl::PointXYZ>::Ptr cloud_filtered (new pcl::PointCloud<pcl::PointXYZ>);
    // 创建滤波器，对每个点分析的临近点的个数设置为50 ，并将标准差的倍数设置为1  这意味着如果一
     //个点的距离超出了平均距离一个标准差以上，则该点被标记为离群点，并将它移除，存储起来
    pcl::StatisticalOutlierRemoval<pcl::PointXYZ> sor;   //创建滤波器对象
    sor.setInputCloud (cloud);                           //设置待滤波的点云
    sor.setMeanK (50);                               //设置在进行统计时考虑查询点临近点数
    sor.setStddevMulThresh (1.0);                      //设置判断是否为离群点的阀值
    sor.filter (*cloud_filtered);                    //存储
    return cloud_filtered;

}

//点云分割
void PointCloudProcess3D::regionGrowingSegmentation(pcl::PointCloud<pcl::PointXYZ>::Ptr cloud)
{
    pcl::search::Search<pcl::PointXYZ>::Ptr tree (new pcl::search::KdTree<pcl::PointXYZ>);
    pcl::PointCloud <pcl::Normal>::Ptr normals (new pcl::PointCloud <pcl::Normal>);

    pcl::NormalEstimation<pcl::PointXYZ, pcl::Normal> normal_estimator;
    normal_estimator.setSearchMethod (tree);
    normal_estimator.setInputCloud (cloud);
    normal_estimator.setKSearch (50);
    normal_estimator.compute (*normals);

    pcl::IndicesPtr indices (new std::vector <int>);
    pcl::PassThrough<pcl::PointXYZ> pass;
    pass.setInputCloud (cloud);
    pass.setFilterFieldName ("z");
    pass.setFilterLimits (0.0, 1.0);
    pass.filter (*indices);

    pcl::RegionGrowing<pcl::PointXYZ, pcl::Normal> reg;
    reg.setMinClusterSize (50);
    reg.setMaxClusterSize (1000000);
    reg.setSearchMethod (tree);
    reg.setNumberOfNeighbours (30);
    reg.setInputCloud (cloud);
    //reg.setIndices (indices);
    reg.setInputNormals (normals);
    reg.setSmoothnessThreshold (3.0 / 180.0 * M_PI);
    reg.setCurvatureThreshold (1.0);

    std::vector <pcl::PointIndices> clusters;//存放分割之后的索引数组
    reg.extract (clusters);//得到分割之后的索引
    pcl::PointCloud <pcl::PointXYZRGB>::Ptr colored_cloud = reg.getColoredCloud ();//将分割的结果用不用颜色表示

}
