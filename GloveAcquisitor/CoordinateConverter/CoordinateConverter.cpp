#include "CoordinateConverter.h"

CoordinateConverter::CoordinateConverter()
{
    l0_thumb = 5.0;
    l0_index = 10.0;
    l0_middle = 10.0;
    l0_ring = 9.0;
    l0_pinky = 9.0;

    l1_thumb = 5.0;
    l1_index = 6.0;
    l1_middle = 6.0;
    l1_ring = 5.0;
    l1_pinky = 4.5;

    l2_thumb = 4.0;
    l2_index = 3.0;
    l2_middle = 3.5;
    l2_ring = 3.0;
    l2_pinky = 2.5;

    l3_thumb = 3.0;
    l3_index = 2.5;
    l3_middle = 2.5;
    l3_ring = 2.5;
    l3_pinky = 2.0;
}

CoordinateConverter::CoordinateConverter(vector<double> l0_list, vector<double> l1_list, vector<double> l2_list, vector<double> l3_list)
{
    l0_thumb = l0_list.at(0);
    l0_index = l0_list.at(1);
    l0_middle = l0_list.at(2);
    l0_ring = l0_list.at(3);
    l0_pinky = l0_list.at(4);

    l1_thumb = l1_list.at(0);
    l1_index = l1_list.at(1);
    l1_middle = l1_list.at(2);
    l1_ring = l1_list.at(3);
    l1_pinky = l1_list.at(4);

    l2_thumb = l2_list.at(0);
    l2_index = l2_list.at(1);
    l2_middle = l2_list.at(2);
    l2_ring = l2_list.at(3);
    l2_pinky = l2_list.at(4);

    l3_thumb = l3_list.at(0);
    l3_index = l3_list.at(1);
    l3_middle = l3_list.at(2);
    l3_ring = l3_list.at(3);
    l3_pinky = l3_list.at(4);
}

double CoordinateConverter::degToRad(double d)
{
    return d / 180.0 * M_PI;
}

double CoordinateConverter::radToDeg(double r)
{
    return r / M_PI * 180.0;
}

pair< vector<double>,vector<double> > CoordinateConverter::PolarToCartesian(Finger finger, vector<double> angles)
{
    buff1.clear();
    buff2.clear();
    buff3.clear();

    switch(finger)
    {
        case 0:
        {
            l0 = l0_thumb;
            l1 = l1_thumb;
            l2 = l2_thumb;
            l3 = l3_thumb;
            break;
        }
        case 1:
        {
            l0 = l0_index;
            l1 = l1_index;
            l2 = l2_index;
            l3 = l3_index;
            break;
        }
        case 2:
        {
            l0 = l0_middle;
            l1 = l1_middle;
            l2 = l2_middle;
            l3 = l3_middle;
            break;
        }
        case 3:
        {
            l0 = l0_ring;
            l1 = l1_ring;
            l2 = l2_ring;
            l3 = l3_ring;
            break;
        }
        case 4:
        {
            l0 = l0_pinky;
            l1 = l1_pinky;
            l2 = l2_pinky;
            l3 = l3_pinky;
            break;
        }
        default:
        {
            l0 = l1 = l2 = l3 = 0.0;
            break;
        }
    }

    // Metacarpal point

    // x1 = l0 + l1.cos(am)
    // y1 = l1.sin(am)
    x = l0 + ( l1 * cos(degToRad(angles.at(0))) );
    y = l1 * sin(degToRad(angles.at(0)));

    buff1.push_back(x);
    buff1.push_back(y);

    // Proximal point

    // x2 = x1 + l2.cos(am + ap)
    // y2 = y1 + l2.sin(am + ap)
    x = x + ( l2 * cos(degToRad(angles.at(0) + angles.at(1))) );
    y = y + ( l2 * sin(degToRad(angles.at(0) + angles.at(1))) );

    buff2.push_back(x);
    buff2.push_back(y);

    // Distal point

    // x3 = x2 + l3.cos(am + ap + ad)
    // y3 = y2 + l3.sin(am + ap + ad)
    x = x + ( l3 * cos(degToRad(angles.at(0) + angles.at(1) + angles.at(2))) );
    y = y + ( l3 * sin(degToRad(angles.at(0) + angles.at(1) + angles.at(2))) );

    buff3.push_back(x);
    buff3.push_back(y);

    // ********************
    // CHANGE HERE TO CHOOSE BETWEEN METACARPAL / PROXIMAL / DISTAL POINTS
    // Default : met + dist
    pair_buff.first = buff1;
    pair_buff.second = buff3;

    return pair_buff;
}



