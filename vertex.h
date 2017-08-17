#ifndef VERTEX_T_H
#define VERTEX_T_H

#include <iostream>
#include <vector>
#include <stdio.h>

class vertex_t
{
  public:

  friend std::istream& operator>>(std::istream& s, vertex_t& rhs);  
  friend std::ostream& operator<<(std::ostream& s, const vertex_t& rhs);  
  friend std::istream& operator>>(std::istream& s, vertex_t* rhs)
   {     return ( s>> * rhs);  }
  friend std::ostream& operator<<(std::ostream& s, const vertex_t* rhs)
   {     return ( s << * rhs);  }
  
  float& operator[] (int i)
       { return coord[i];  }
 
  private:
	std::vector<float> coord;

}; 

#endif
