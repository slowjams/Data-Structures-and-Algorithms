#ifndef SEQUENCE_H
#define SEQUENCE_H

#include <string>

using namespace std;

class sequence
{
   
   private:
      int id;
	   string text;
   public:
      
      friend class message;

         sequence() 
    {
        
    }

      sequence(int a, string t) 
	  {
         id=a;
         text=t;
    }
      
       //overloaded '>' operator
     bool operator > (const sequence &other)
    {
         return id > other.id;
    }
};
#endif