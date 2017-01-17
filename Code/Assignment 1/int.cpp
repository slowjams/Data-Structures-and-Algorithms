#include <iostream>
#include <iomanip>
#include <string>
#include <stdlib.h>
#include <fstream> 
#include <list>
#include "message.h"
#include "sequence.h"

using namespace std;

void printMessage(const list<message> &mylist);

void saveMessage(list<message> &mylist, message &m); 

void printMessage(const list<message> &mylist)
{
	list<message>::const_iterator itr;   
		for(itr=mylist.begin(); itr!=mylist.end(); itr++)
		{
			(*itr).printSequence();
			
			cout << endl;
		}
}

void saveMessage(list<message> &mylist, message &m) 
{
	if(mylist.empty())          
	{
		m.addSequence();
		mylist.push_back(m);
	}
	else
	{
		list<message>::iterator itr; 
		for(itr=mylist.begin(); itr!=mylist.end(); itr++)
		{
				if(m == *itr)  
			{	
				(*itr).addSequence(m);
				return;
			}
		}
		for(itr=mylist.begin(); itr!=mylist.end(); itr++)
		{
			if(*itr>m)
			{
				m.addSequence();
				mylist.insert(itr,m);
				return;
			}	
		}
		m.addSequence();
		mylist.push_back(m);
	}
}

int main(int arg, char *argv[])
{
	
	int d;
	int e;
	list<message> myList;
    string line;
	string a,b,c;
	ifstream fin;
	
	fin.open(argv[1]);
	 if (!fin) 
   {
      cout << "Unable to read\n";
      exit(0);
   }
   
   while (getline(fin,line))   
   { a=line.substr(0,3);
     
     if(a=="END")
     {
     	break;
     }
     b=line.substr(4,3);
     c=line.substr(8);
     d=atoi(a.c_str());  
     e=atoi(b.c_str());
     sequence s(e,c);
     message m(d,s);
 	saveMessage(myList,m);
   }
	
	fin.close(); 
	printMessage(myList);
	
	return 0;
}