#include<iostream>
#include<vector>
#include<cmath>
#include"point.h"

//copy constructer 
point_t::point_t(const point_t &rhs)
{

	for(int i=0; i< (int) rhs.coord.size(); i++)
	{	coord.push_back(rhs.coord[i]); }
}


// assignment operator
point_t point_t::operator= (const point_t &rhs)
{
//coord[i]=rhs.coord[i]
	coord.clear();
	for(int i=0; i< (int) rhs.coord.size(); i++)
	{	coord.push_back(rhs.coord[i]); }
	return *this;
}


//input output streams	
	
std::istream& operator>>(std::istream& s, point_t& rhs)
{
	int 	i=0;	//counter for coords read in
	char	c, n;	// temporary characters to look at input
	double	f;

	do{
		s>>f;
		rhs.coord.push_back(f);  i++;
	}while(s.get(c) && (c!= '\n') && ((n =s.peek()) != '\n'));

//	for(int i= 0; i< (int) rhs.coord.size(); i++)
//		s>> rhs.coord[i];
	return s;
}

std::ostream& operator<<(std::ostream& s, const point_t& rhs) 
{
	s.setf(std::ios::fixed, std::ios::floatfield);
	s.precision(2);
	for(int i= 0;i < (int) rhs.coord.size(); i++)
		if(i == (int) rhs.coord.size() -1)
			s<< rhs.coord[i];
		else			
			s<< rhs.coord[i] <<", ";
	return s; 
}

// distance function

double point_t::distance(point_t & rhs)
{
	double sum =0.0;
	double dif= 0.0;
	//double xy=pow((rhs.coord[0] - coord[0]), 2) + pow((rhs.coord[1] - coord[1]),2 );
	for(int i=0;  i< (int) rhs.coord.size(); i++)
	{
		dif= coord[i]- rhs.coord[i];
		sum+=(dif*dif);
	}

	return sqrt(sum);
}
