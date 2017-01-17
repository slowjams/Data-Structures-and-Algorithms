#ifndef MESSAGE_H
#define MESSAGE_H

#include <string>
#include <iostream>
#include <list>
#include "sequence.h"

using namespace std;

class message
{
   
   private:
      int mainid;
	     sequence seq;
      list<sequence> messageList;
  
   public:
      message(int x, sequence y)
	  {
        mainid=x;
        seq=y;           
    }
    
      void addSequence()
      {
      	
      	messageList.push_back(seq);
      }

      
       void addSequence(const message &other) 
      {
      	list<sequence>::iterator itr;
		for(itr=messageList.begin(); itr!=messageList.end(); itr++)
        {
        	if(*itr>(other.seq))  
        	{
        		messageList.insert(itr,other.seq);
        		return;
        	}
        }
        messageList.push_back(other.seq); 
      }

       void printSequence() const
      {
      	cout << "Message " << setfill('0') << setw(3) << mainid <<endl;
      	list<sequence>::const_iterator itr;

		    for(itr=messageList.begin(); itr!=messageList.end(); itr++)
        {
        	cout << (*itr).text<<endl<<"?";
        }
      }

       //overloaded equality operator
       bool operator == (const message &other) const
	  {
         return mainid == other.mainid;
    }

       //overloaded ">" operator
       bool operator > (const message &other) 
	  {
         return mainid > other.mainid;
    }    
};
#endif