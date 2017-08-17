#ifndef FACE_T_H
#define FACE_T_H

#include<vector>
#include<iostream>

class aw_t;

class face_t
{
  public:

  friend  std::istream& operator>>(std::istream& s, face_t& rhs);  
  friend  std::ostream& operator<<(std::ostream& s, const face_t& rhs);
  friend  std::istream& operator>>(std::istream& s, face_t* rhs)
  {	return ( s>>*rhs);  }     
  friend  std::ostream& operator<<(std::ostream& s, const face_t* rhs)
  {	return ( s <<*rhs);  }

  friend void display();
  
  void calc_norm(const aw_t& obj); 

  private:
    std::vector<int> vin;
    std::vector<float> norm;
};

#endif
