#ifndef CAMERA_T_H
#define CAMERA_T_H

#include <vector>

class camera_t
{
  public:
    camera_t();

    // to move [translate the camera]
    void truck(float); 
    void pedestal(float);
    void dolly(float);

    //to rotate the camera
    void pan(float); 
    void pitch(float);
    void tilt(float);

  friend void display(); 
  
  private:
	std::vector<float> pos;
	std::vector<float> ref;
	std::vector<float> vup;
};

#endif
