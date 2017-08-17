#ifndef AW_T_H
#define AW_T_H

#include<iostream>
#include <vector>
#include <stdio.h>

#include "vertex.h"
#include "face.h"

class aw_t{
  
  public:
  
  aw_t() :  rotx(0.0), roty(0.0), rotz(0.0)  
	{	for(int i =0; i <3; i++){  oc.push_back(0.0);	}	 }

  friend std::istream& operator>>( std::istream& s, aw_t& rhs);
  friend std::ostream& operator<<(std::ostream& s,const aw_t& rhs);
  friend  std::istream& operator>>(std::istream& s, aw_t* rhs)
  {     return ( s>> * rhs);  }
  friend  std::ostream& operator<<(std::ostream& s, const aw_t* rhs)
   {     return ( s << * rhs);  }
 
  void rotate(float rx, float ry, float rz)
  { 
    rotx +=rx; 
    roty += ry;
    rotz += rz;
  }
  void center()
  { 
    for(int i=0; i< 3; i++)
    {	std::cout<< std::endl << oc[i]<< std::endl;  }
  }
  friend void display(); 
  friend class face_t;

  private:
	std::vector<vertex_t *> verts; 
	std::vector<face_t *> faces;
	std::string group;
	float rotx, roty, rotz;
	std::vector<float>  oc;

};

#endif
