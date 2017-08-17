#include <iostream>
#include <vector>
#include<cmath>
#include "face.h"
#include "aw.h"
 
std::istream& operator>>(std::istream& s, face_t& rhs)
{
        int     i=0;    //counter for coords read in
        char    c, n;   // temporary characters to look at input
        int	f;

        do{
                s>>f;
                rhs.vin.push_back(f);  i++;
        }while(s.get(c) && (c!= '\n') && ((n =s.peek()) != '\n'));

//      for(int i= 0; i< (int) rhs.coord.size(); i++)
//              s>> rhs.coord[i];
        return s;
};

std::ostream& operator<<(std::ostream& s, const face_t& rhs)
{
      //  s.setf(std::ios::fixed, std::ios::floatfield);
       // s.precision(2);
        for(int i= 0;i < (int) rhs.vin.size(); i++)
                if(i == (int) rhs.vin.size() -1)
                        s<< rhs.vin[i];
                else
                        s<< rhs.vin[i] <<", ";
        return s;
}

void face_t::calc_norm(const aw_t& obj)
{
	std::vector<float> A(3, 0.0), B(3, 0.0), C(3, 0.0);
  
  //set A to first vertex B to last vertex
 //  vin.size()<< std::endl;
  std::cout<< (*obj.verts[vin[0]-1])<<" A\n";
  std::cout<< (*obj.verts[vin[3]-1])<<" B\n";
  for(int i=0; i < 3; i++)
  {  A[i]= ( *obj.verts[ (vin[0])-1 ] )[i];  }
  int size= (int) vin.size()-1; 
  for(int i=0; i < 3; i++)
  {  B[i]= (*obj.verts[ (vin[size])-1 ])[i];  }
  int h=0;
  std::cout<< "vin "; 
  while(h< (int) vin.size())
  {  std::cout<<vin[h]<< ", "; h++; }
  //cross product
  for(int j=0; j<3; j++)
  {   C[j] =\
      B[((3+j-1)%3)] * A[((3+j+1)%3)] -\
      A[((3+j-1)%3)] * B[((3+j+1)%3)]; 
  }
  // compute magnitude of C
  float sum= 0.0; 
  for(int j=0; j<3; j++)
  {  sum += (C[j] * C[j]); }
  sum = sqrt(sum);

  // set norm
  for(int i=0; i< 3; i++)
  {  norm.push_back(C[i]/sum);
     std::cout<<"C[" <<i << "] ="<< C[i]<< ", ";
  }
  std::cout<<std::endl;
}

