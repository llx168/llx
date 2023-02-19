#ifndef LASERDATAPROCESS2D_H
#define LASERDATAPROCESS2D_H

#include <string>
#include <vector>
#include <math.h>
#include <set>
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

class LaserDataProcess2D
{
public:
    LaserDataProcess2D();

    //滤除在设定距离范围之外的数据
    bool rangeFilter(vector<Point>* pointCloud,float lower,float lowerReplace,float upper,float upperReplace);

    //滤除在设定扫描范围之外的数据
    bool angularBoundsFilter(vector<Point>* pointCloudIn,vector<Point>* pointCloudOut,float lower,float upper);

    //滤除在设定扫描范围之内的数据
    bool angularBoundsFilterInPlace(vector<Point>* pointCloudIn,vector<Point>* pointCloudOut,float lower,float upper);

    //在可信任的扫描点之间插值
    bool interpolationFilter(vector<Point>* pointCloudIn);

    //拖尾现象处理
    bool scanShadowsFilter(vector<Point>* pointCloudIn);

    //滤除在设定强度阈值之外的数据
    bool intensityFilter(vector<Point>* pointCloudIn,float lower_threshold_,float upper_threshold_);

    //滤除随机噪点噪声
    bool speckleFilter(vector<Point>* pointCloudIn,int filterType);
    //配合去除随机噪声
    bool checkWindowValidFromDist(vector<Point>* pointCloudIn, size_t idx, size_t window, double max_range_difference);
    //配合去除随机噪声
    bool checkWindowValidFromRadiusOutlier(vector<Point>* pointCloudIn, size_t idx, size_t window, double max_distance);

    //滤除设定区域的数据
    bool boxFilter(vector<Point>* pointCloudIn,float minX,float maxX,float minY,float maxY,float minZ,float maxZ);

    
    

    //求r1这条边与r1、r2两端点连线的夹角
    inline double getAngleWithViewpoint(float r1, float r2, float included_angle)
    {
      return atan2(r2 * sin(included_angle), r1 - r2 * cos(included_angle));
    }








//private:
//    //rangeFilter
//    float lowerThreshold;//距离下限
//    float lowerReplacementValue;
//    float upperThreshold;//距离上限
//    float upperReplacementValue;

//    //angularBoundsFilter
//    float lowerAzimuth;
//    float upperAzimuth;



};

#endif // LASERDATAPROCESS2D_H
