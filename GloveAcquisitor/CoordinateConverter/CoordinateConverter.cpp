#include "CoordinateConverter.h"

CoordinateConverter::CoordinateConverter()
{
    l0_thumb = 9.0;
    l0_index = 10.0;
    l0_middle = 10.0;
    l0_ring = 9.0;
    l0_pinky = 9.0;

    l1_thumb = 4.0;
    l1_index = 5.0;
    l1_middle = 5.0;
    l1_ring = 5.0;
    l1_pinky = 4.0;

    l2_thumb = 3.0;
    l2_index = 5.0;
    l2_middle = 6.0;
    l2_ring = 5.0;
    l2_pinky = 4.0;
}

CoordinateConverter::CoordinateConverter(vector<double> l0_list, vector<double> l1_list, vector<double> l2_list)
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

    switch(finger)
    {
        case 0:
        {
            l0 = l0_thumb;
            l1 = l1_thumb;
            l2 = l2_thumb;
            break;
        }
        case 1:
        {
            l0 = l0_index;
            l1 = l1_index;
            l2 = l2_index;
            break;
        }
        case 2:
        {
            l0 = l0_middle;
            l1 = l1_middle;
            l2 = l2_middle;
            break;
        }
        case 3:
        {
            l0 = l0_ring;
            l1 = l1_ring;
            l2 = l2_ring;
            break;
        }
        case 4:
        {
            l0 = l0_pinky;
            l1 = l1_pinky;
            l2 = l2_pinky;
            break;
        }
        default:
        {
            l0 = l1 = l2 = 0.0;
            break;
        }
    }

    // Middle point

    if (finger == 0) // THUMB special case
    {
        x = l0 + ( l1 * cos(degToRad(angles.at(1))) );
        y = l1 * sin(degToRad(angles.at(1)));
        z = 0.0;
    } else { // other fingers
        x = l0 + ( l1 * cos(degToRad(angles.at(0))) );
        y = l1 * sin(degToRad(angles.at(0)));
        z = 0.0;
    }

    buff1.push_back(x);
    buff1.push_back(y);
    buff1.push_back(z);

    // End point

    if (finger == 0)
    {
        x = l0 + x + ( l2 * cos(degToRad(angles.at(1) + angles.at(2))) );
        y = y + ( l2 * sin(degToRad(angles.at(1) + angles.at(2))) );
        z = 0;
    } else {
        x = l0 + x + ( l2 * cos(degToRad(angles.at(0) + angles.at(2))) );
        y = y + ( l2 * sin(degToRad(angles.at(0) + angles.at(2))) );
        z = 0.0;
    }

    buff2.push_back(x);
    buff2.push_back(y);
    buff2.push_back(z);

    pair_buff.first = buff1;
    pair_buff.second = buff2;

    return pair_buff;
}



