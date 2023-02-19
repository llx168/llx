#include "laserdataprocess2d.h"



LaserDataProcess2D::LaserDataProcess2D()
{

}

//滤除在设定距离范围之外的数据
bool LaserDataProcess2D::rangeFilter(vector<Point>* pointCloud,float lower,float lowerReplace,float upper,float upperReplace)
{
    for (size_t i=0;i < pointCloud->size();i++){
        if (pointCloud->at(i).dist <= lower)
        {
          pointCloud->at(i).dist = lowerReplace;
        }
        else if (pointCloud->at(i).dist >= upper)
        {
          pointCloud->at(i).dist = upperReplace;
        }
    }
    return true;

}

//滤除在设定扫描范围之外的数据
bool LaserDataProcess2D::angularBoundsFilter(vector<Point> *pointCloudIn, vector<Point> *pointCloudOut,float lower,float upper)
{
    pointCloudOut->resize(pointCloudIn->size());

    for (size_t i=0;i < pointCloudIn->size();i++){

        if(pointCloudIn->at(i).azimuth>lower&&pointCloudIn->at(i).azimuth<upper){

            pointCloudOut->push_back(pointCloudIn->at(i));
        }
    }
    return true;

}

//滤除在设定扫描范围之内的数据
bool LaserDataProcess2D::angularBoundsFilterInPlace(vector<Point> *pointCloudIn, vector<Point> *pointCloudOut, float lower, float upper)
{
    pointCloudOut->resize(pointCloudIn->size());

    for (size_t i=0;i < pointCloudIn->size();i++){

        if(pointCloudIn->at(i).azimuth<lower||pointCloudIn->at(i).azimuth>upper){

            pointCloudOut->push_back(pointCloudIn->at(i));
        }
    }
    return true;
}

//拖尾现象处理
bool LaserDataProcess2D::scanShadowsFilter(vector<Point> *pointCloudIn)
{

        int window_=2;
        double min_angle_ = 5.0;
        double max_angle_ = 175.0;
        int neighbors_ = 3;
        double angle_increment =0.36/180*M_PI;

        std::set<int> indices_to_delete;
        // 遍历每个点
        for (unsigned int i = 0; i < pointCloudIn->size(); i++)
        {
          for (int y = -window_; y < window_ + 1; y++)
          {
            int j = i + y;
            if ( j < 0 || j >= (int)pointCloudIn->size() || (int)i == j ){ // Out of scan bounds or itself
              continue;
        }

            //角度为度
            double angle = abs(getAngleWithViewpoint (pointCloudIn->at(i).dist,pointCloudIn->at(j).dist, y * angle_increment)/M_PI*180);
            if (angle < min_angle_ || angle > max_angle_)
            {

              for (int index = std::max<int>(i - neighbors_, 0); index <= std::min<int>(i+neighbors_, (int)pointCloudIn->size()-1); index++)
                {
                  if (pointCloudIn->at(i).dist < pointCloudIn->at(index).dist) // delete neighbor if they are farther away (note not self)
                  {
                      indices_to_delete.insert(index);
                  }
                }
            }

          }
        }

        for ( std::set<int>::iterator it = indices_to_delete.begin(); it != indices_to_delete.end(); ++it)
          {
              pointCloudIn->at(*it).dist = 0.001;  // 给无效点赋值
          }
        return true;

}

//滤除在设定强度阈值之外的数据
bool LaserDataProcess2D::intensityFilter(vector<Point> *pointCloudIn,float lower_threshold_,float upper_threshold_)
{

    // 遍历所有点
    for (unsigned int i=0;i < pointCloudIn->size();i++)
    {

      // 是否在阈值范围外
      if (pointCloudIn->at(i).intensity <= lower_threshold_ || pointCloudIn->at(i).intensity >= upper_threshold_)
      {
        // 在阈值外，则将距离值赋为无效值
        pointCloudIn->at(i).dist = 0.001;
      }
    }


    return true;

}

//在可信任的扫描点之间插值
bool LaserDataProcess2D::interpolationFilter(vector<Point> *pointCloudIn)
{
    float previousValidDist =10.0;//前一个有效距离
    float nextValidDist =10.0;//后一个有效距离
    float distMin = 0.5;//有效距离的最小值
    float distMax = 25.0;//有效距离的最大值
    unsigned int i = 0;
    while(i < pointCloudIn->size()) // 遍历一帧数据的每一个点
        {
          //检查距离值是否在有效范围之外
          if (pointCloudIn->at(i).dist <= distMin || pointCloudIn->at(i).dist >= distMax){

            //寻找下一个有效的距离点
            unsigned int j = i + 1;
            unsigned int start_index = i;
            unsigned int end_index = i;
            while(j < pointCloudIn->size()){
              if (pointCloudIn->at(j).dist <= distMin ||
                  pointCloudIn->at(j).dist >= distMax){
                end_index = j;
              }
              else{
                nextValidDist = pointCloudIn->at(j).dist;
                break;
              }
              ++j;
            }

            //用无效点两边的有效距离做一个平均值的插值
            double average_range = (previousValidDist + nextValidDist) / 2.0;

            for(unsigned int k = start_index; k <= end_index; k++){
              pointCloudIn->at(k).dist = average_range;
            }

            //插值之后，更新上一个有效距离点
            previousValidDist = nextValidDist;
            i = j + 1;
          }
          else{
            previousValidDist = pointCloudIn->at(i).dist;
            ++i;
          }

        }
    return true;
}

//滤除随机噪点噪声
//filterType为0则选择按距离滤除，为1则为按半径范围搜索滤除
bool LaserDataProcess2D::speckleFilter(vector<Point> *pointCloudIn,int filterType)
{
    //参数
    int filter_window = 2;
    float max_range_difference = 0.1;
    float max_range = 2.0;
    bool window_valid;

    std::vector<bool> valid_ranges(pointCloudIn->size(), false);
    for (size_t idx = 0; idx < pointCloudIn->size() - filter_window + 1; ++idx)
    {
        if(filterType==0){
            window_valid = checkWindowValidFromDist(pointCloudIn, idx, filter_window, max_range_difference);
        }else{
            window_valid = checkWindowValidFromRadiusOutlier(pointCloudIn, idx, filter_window, max_range_difference);
        }

      // Actually set the valid ranges (do not set to false if it was already valid or out of range)
      for (size_t neighbor_idx_or_self_nr = 0; neighbor_idx_or_self_nr < filter_window; ++neighbor_idx_or_self_nr)
      {
        size_t neighbor_idx_or_self = idx + neighbor_idx_or_self_nr;
        if (neighbor_idx_or_self < pointCloudIn->size())  // Out of bound check
        {
          bool out_of_range = pointCloudIn->at(neighbor_idx_or_self).dist > max_range;
          valid_ranges[neighbor_idx_or_self] = valid_ranges[neighbor_idx_or_self] || window_valid || out_of_range;
        }
      }
    }

    for (size_t idx = 0; idx < valid_ranges.size(); ++idx)
    {
      if (!valid_ranges[idx])
      {
        pointCloudIn->at(idx).dist = 0.001;
      }
    }

    return true;
}

bool LaserDataProcess2D::checkWindowValidFromRadiusOutlier(vector<Point> *pointCloudIn, size_t idx, size_t window, double max_distance)
{
    int num_neighbors = 0;
    const float& r1 = pointCloudIn->at(idx).dist;
    float r2 = 0.;
    float angle_increment = 0.36;

    // Look around the current point until either the window is exceeded
    // or the number of neighbors was found.
    for (int y = -(int)window; y < (int)window + 1 && num_neighbors < (int)window; y++)
    {
      int j = idx + y;
      r2 = pointCloudIn->at(j).dist;

      if (j < 0 || j >= static_cast<int>(pointCloudIn->size()) || idx == j || std::isnan(r2))
      {  // Out of scan bounds or itself or infinity
        continue;
      }

      const float d = sqrt(pow(r1,2) + pow(r2,2) -(2 * r1 * r2 * cosf(y * angle_increment)));

      if (d <= max_distance)
      {
        num_neighbors++;
      }
    }

    // consider the window to be the number of neighbors we need
    if (num_neighbors < window)
    {
      return false;
    }
    else
    {
      return true;
    }
}

//滤除设定区域的数据
bool LaserDataProcess2D::boxFilter(vector<Point> *pointCloudIn, float minX, float maxX, float minY, float maxY, float minZ, float maxZ)
{
    // 遍历所有点
    for (unsigned int i=0;i < pointCloudIn->size();i++)
    {

      // 是否在区域范围内
      if (pointCloudIn->at(i).x > minX && pointCloudIn->at(i).x < maxX && pointCloudIn->at(i).y > minY
              && pointCloudIn->at(i).y < maxY && pointCloudIn->at(i).z >minZ && pointCloudIn->at(i).z < maxZ)
      {
        // 将距离值赋为无效值
        pointCloudIn->at(i).dist = 0.001;
      }
    }


    return true;
}

bool LaserDataProcess2D::checkWindowValidFromDist(vector<Point> *pointCloudIn, size_t idx, size_t window, double max_range_difference)
{
    const float& range = pointCloudIn->at(idx).dist;
    if (range != range) {
      return false;
    }

    for (size_t neighbor_idx_nr = 1; neighbor_idx_nr < window; ++neighbor_idx_nr)
    {
      size_t neighbor_idx = idx + neighbor_idx_nr;
      if (neighbor_idx < pointCloudIn->size())  // Out of bound check
      {
        const float& neighbor_range = pointCloudIn->at(neighbor_idx).dist;
        if (neighbor_range != neighbor_range || fabs(neighbor_range - range) > max_range_difference)
        {
          return false;
        }
      }
    }
    return true;
}





