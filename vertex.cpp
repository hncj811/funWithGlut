#include<vector>
#include<iostream>

#include"vertex.h"

std::istream& operator>>(std::istream& s, vertex_t& rhs)
{
        int     i=0;    //counter for coords read in
        char    c, n;   // temporary characters to look at input
        float f;

        do{
                s>>f;
                rhs.coord.push_back(f);  i++;
        }while(s.get(c) && (c!= '\n') && ((n =s.peek()) != '\n'));

//      for(int i= 0; i< (int) rhs.coord.size(); i++)
//              s>> rhs.coord[i];
        return s;
}

std::ostream& operator<<(std::ostream& s, const vertex_t& rhs)
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
