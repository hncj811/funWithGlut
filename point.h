#ifndef POINT_T_H

#define POINT_T_H

#include<vector>

class point_t
{
	public:
	// Constructors
	point_t(void) {}
	point_t(double x, double y, double z)
	{
		coord.push_back(x);
		coord.push_back(y);
		coord.push_back(z);
	}
	
	point_t(std::vector<double> c)
        {
                coord.push_back(c[0]);
                coord.push_back(c[1]);
	        coord.push_back(c[2]);
		
        }
	
	// destructor (default ok)
	// ~point_t();
	
	//copy constructor
	point_t(const point_t& rhs);

	//assignment operator
	point_t operator=(const point_t& rhs);
	
	// operators (accessor)
	const double& operator[] (int i) const
	{ return coord[i];  }

	// operator (mutator)
	double& operator[] (int i)
	{ return coord[i];  }


	// friend functions
	// friend input operator
	friend std::istream& operator>>(std::istream& s, point_t& rhs);

	friend std::istream& operator>>(std::istream& s, point_t* rhs)
	{	return (s >> *rhs); }



	// friend output operator
	friend std::ostream& operator<<(std::ostream& s, const point_t& rhs);
	friend std::ostream& operator<<(std::ostream& s, point_t* rhs)
	{	return (s<< *rhs);	}


	double distance(point_t& rhs);
	double distance(point_t* rhs)  {  return distance(*rhs);  }
	int dim() const	{   return coord.size();   }
	private:

	std::vector<double> coord;

};

#endif
