#include <fstream>
#include <list>
#include <stdexcept>
#include <stdlib.h>
#include "bintree.h" 
#include "dictionary.h" 
#include "spellcheck.h" 

using namespace std;

int main(int argc, char *argv[])
{
   try
   {
      if(argc != 3)
      {
         throw invalid_argument("Syntax : spellcheck dictionary filename");
      }
   
      // create an instance of spellcheck
      spellcheck check;
      // load the dictionary file
      check.loadDictionary(argv[1]);
      // compare the dictionary's stored words with the provided file's words.
      check.checkSpelling(argv[2]); 
      // print all the unkown words and summary.
      check.PrintWords(); 
   }
   catch(invalid_argument &ex)
   {
      cout << "ERROR - Incorrect number of arguments\n" << ex.what(); 
   }
   catch(runtime_error &ex)
   {
      cout << "Program failed with the following error\n" << ex.what(); 
   }
   catch(...)
   {
      cout << "unexpected error,plsease check the program!"; 
   }

   return 0;
}
