#include<iostream>
#include<vector>
#include<cmath> 
#include "camera.h"

camera_t::camera_t()
{
  pos.push_back(0.0);
  pos.push_back(0.0); 
  pos.push_back(-10.0); 

  ref.push_back(0.0);
  ref.push_back(0.0);
  ref.push_back(1000.0);

  vup.push_back(0.0);
  vup.push_back(1.0); 
  vup.push_back(0.0);
}

void camera_t::truck(float h)
{
  pos[0]=pos[0] + h;
  ref[0]= ref[0] + h;
}

void camera_t:: pedestal(float h)
{
  pos[1]=pos[1] + h;
  ref[1]= ref[1] + h;
}

void camera_t:: dolly(float h)
{
  pos[2]=pos[2] + h;
  ref[2]= ref[2] + h;
}

void camera_t:: pitch(float angle)
{
  	angle= angle*M_PI/180;
	float newy, newz;
  newy= ref[1]*cos(angle) - ref[2]*sin(angle);
  newz= ref[1]*sin(angle) + ref[2]*cos(angle);
  
  ref[1]=newy;
  ref[2]=newz;
}

void camera_t:: pan(float angle)
{
	angle= angle *M_PI/180;
	float newx, newz; 
  newx=ref[0]*cos(angle) + ref[2]*sin(angle);
  newz=-ref[0]*sin(angle) + ref[2]*cos(angle);

  ref[0]= newx;  ref[2]= newz; 

}
void camera_t::tilt(float angle) //rotates the camera around the z axis
{
        float newx, newy;
        float rangle = angle/180.0;

  newx = vup[0] * cos(rangle) - vup[1] * sin(rangle);
  newy = vup[0] * sin(rangle) + vup[1] * cos(rangle);

  vup[0] = newx - pos[0];
  vup[1] = newy - pos[1];
  std::cout<<"vup[0], and vup[1]"<< vup[0] <<" , "<< vup[1]<< std::endl; 
}
