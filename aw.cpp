#include<iostream>
#include<vector>
#include<cmath>

#include "aw.h"
//#include "vertex.h"
//#include "face.h"

std::istream& operator >>(std::istream& s, aw_t& rhs)
{
	vertex_t* vertexp=NULL;
	face_t* facep=NULL;
	char c;
	

  while(s.get(c) && !s.eof())
  {

    switch(c){
      case 'v':
        s >> (vertexp = new vertex_t() ) >> std::ws;
        rhs.verts.push_back(vertexp);
        std::cout<< vertexp <<std::endl;
	for(int i=0; i < 3; i++)
	{	rhs.oc[i]+= (*vertexp)[i];  }
	
        break;
      case 'g':
        std::cin >> rhs.group;
        break;
      case 'f':
//      int i=0;
        s>>(facep= new face_t())>> std::ws;
        rhs.faces.push_back(facep);
//	(*facep).calc_norm(rhs);
//        rhs.faces[i++]->calc_norm(rhs);
        break;
    }

  }

  for(int i=0; i < (int) rhs.faces.size(); i++)
  {
    rhs.faces[i]->calc_norm(rhs);
  }

  for(int i=0; i< 3; i++)
  {  rhs.oc[i]/= (float) rhs.verts.size(); }
  return s;
}

std::ostream& operator<<(std::ostream& s, const aw_t& rhs)
{

  for(int i=0; i< (int) rhs.verts.size(); i++)
  {  s<<'v' << rhs.verts[i] <<std::endl;  }
  
  std::cout<<"group"<< rhs.group<< std::endl;

  for(int i=0; i< (int) rhs.faces.size(); i++)
  {  s<<'v' << rhs.faces[i] <<std::endl;  }

  return s;

}

/*void aw_t::rotate(float rx, float ry, float rz)
{
  rotx +=rx; 
  roty += ry;
  rotz += rz;
}
*/

/*
aw_t aw_t::operator= (const aw_t &rhs)
{
//coord[i]=rhs.coord[i]
	coord.clear();
	for(int i=0; i< (int) rhs.coord.size(); i++)
	{	coord.push_back(rhs.coord[i]); }
	return *this;

}*/

