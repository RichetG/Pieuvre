#include <cmath>
#include <iostream>
#include <vector>
#include <utility>

using namespace std;

/**
 * @brief Finger identification enum
 */
enum Finger {

    THUMB = 0,
    INDEX = 1,
    MIDDLE = 2,
    RING = 3,
    PINKY = 4
};

/**
 * @brief Polar to cartesian converter class
 *
 * The Cyberglove system give two angles per finger. This class converts these angles into
 * the cartesian system. In output each finger has two points (middle and extremity) with (x,y)
 * coordinates.
 * Distances from the hand's root to each articulation can be passed to the constructor :
 * For each finger : [hand_root ----l0---- metacarpal_angle ----l1---- distal_angle ----l2---- finger_end]
 * You can also use the default constructor which uses standard values.
 */
class CoordinateConverter
{
public:
  /**
   * @brief CoordinateConverter
   * Default constructor
   */
  CoordinateConverter();

  /**
   * @brief CoordinateConverter
   * @param l0_list root to metacarpal lengths (thumb --> pinky)
   * @param l1_list met. to distal lengths (th. --> p.)
   * @param l2_list distal to finger end lengths (th. --> p.)
   */
  CoordinateConverter(vector<double> l0_list, vector<double> l1_list, vector<double> l2_list);

  /**
   * @brief PolarToCartesian
   * @param finger Finger identifier (enum)
   * @param angles Cyberglove datas (met. -- prox. -- dist.)
   * @return A vector pair. The first vector contains x,y coordinates for the middle point of the finger. The second contains x,y coordinates for the end point.
   *
   * Converts "metacarpal" and "distal" angles into finger points positions.
   *
   * Special cases :
   * ** THUMB : "metacarpal" datas are displayed on "proximal". Probably a glove driver bug.
   * This case is treated in the implementation so you can forget about it. Just consider that THUMB is fully functional.
   * ** PINKY : datas from "metacarpal" are wrong, because the glove sensor is broken.
   * You'll have to handle it, maybe with random loop values.
   *
   * The glove also provide indications on the distance between fingers. This implementation ignore it.
   * So the "proximal" category is never used, except for the thumb's special case.
   */
  pair< vector<double>,vector<double> > PolarToCartesian(Finger finger, vector<double> angles);

private:
  /**
   * @brief degToRad
   * @param d value in degrees
   * @return result in radians
   * Simple conversion method
   */
  double degToRad(double d);
  /**
   * @brief radToDeg
   * @param r value in radians
   * @return result in degrees
   * Simple conversion method
   */
  double radToDeg(double r);


  vector<double> buff1, buff2;
  pair< vector<double>,vector<double> > pair_buff;
  double x, y, z;
  //double r, phi, theta;
  double l0, l1, l2;

  // Hand dimensions
  double l0_thumb, l0_index, l0_middle, l0_ring, l0_pinky;
  double l1_thumb, l1_index, l1_middle, l1_ring, l1_pinky;
  double l2_thumb, l2_index, l2_middle, l2_ring, l2_pinky;
};
