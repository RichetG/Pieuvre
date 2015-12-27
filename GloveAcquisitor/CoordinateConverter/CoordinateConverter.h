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
 * The Cyberglove system give three angles per finger. This class converts these angles into
 * the cartesian system. In output each finger has two points (first and third by default, but you can change 
 * that in PolarToCartesian function) with (x,y) coordinates.
 * Distances from the hand's root to each articulation can be passed to the constructor :
 * For each finger : 
 * [hand_root ----l0---- metacarpal_angle ----l1---- proximal_angle ----l2---- distal_angle ----l3---- finger_end]
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
   * @param l1_list met. to proximal lengths (th. --> p.)
   * @param l2_list proximal to distal lengths (th. --> p.)
   * @param l3_list distal to finger end lengths (th. --> p.)
   */
  CoordinateConverter(vector<double> l0_list, vector<double> l1_list, vector<double> l2_list, vector<double> l3_list);

  /**
   * @brief PolarToCartesian
   * @param finger Finger identifier (enum)
   * @param angles Cyberglove datas (met. -- prox. -- dist.)
   * @return A vector pair. Two (x,y) coordinates couples.
   *
   * Converts "metacarpal" and "distal" angles into finger points positions.
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


  vector<double> buff1, buff2, buff3;
  pair< vector<double>,vector<double> > pair_buff;
  double x, y;
  //double r, phi, theta;
  double l0, l1, l2, l3;

  // Hand dimensions
  double l0_thumb, l0_index, l0_middle, l0_ring, l0_pinky;
  double l1_thumb, l1_index, l1_middle, l1_ring, l1_pinky;
  double l2_thumb, l2_index, l2_middle, l2_ring, l2_pinky;
  double l3_thumb, l3_index, l3_middle, l3_ring, l3_pinky;
};
