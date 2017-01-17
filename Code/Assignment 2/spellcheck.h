using namespace std;

class spellcheck
{
   private:

      dictionary dict;
      int totalWord;
      int unknownSpelling;
      /*use a list to store unknown words which can be printed out later
      Note: words from dict.txt are still stored in a binary tree!*/
      list<string> unknownwordList;

      // check if a character is a seperator
      bool isSeparator(char c) const
      {
         if(isspace(c)||ispunct(c))
         {
            if(c==39||c=='-'||c=='&'||c=='$'||c=='_'||c=='@')
            {
               return false;
            }
            return true;
         }
         return false;
      } 
      // check if a character is a specific character
      bool isSpecChar(char c) const
      {
         if(isdigit(c)||c=='+'||c=='-'||c=='\t'||c=='\n'||c==' ') 
         {
            return true;
         }
         return false;
      }

      bool isNumber(string searchWord) const
      {
         const char* c=searchWord.c_str();
         /* use strrod function to determine if a string is a number,
         if the string contains characters then 
         pEnd is set to print to the first non-number character*/
         char* pEnd=NULL;  
         strtod(c, &pEnd);
         if(*pEnd==0)
         {
            return true;
         }
         return false;
      }
      // set all the character in the string to be lowercase
      const string& toLowerCase(string &searchWord)
      {
         string::iterator itr;
         for (itr = searchWord.begin(); itr != searchWord.end(); itr++) 
         {
            *itr = tolower(*itr);
         }
         return searchWord;
      }

   public:
      // constructor
      spellcheck() 
      {
      }

      void checkSpelling(const char* textFile)
      {
         totalWord=0;
         unknownSpelling=0;
         ifstream fin;
         string searchWord; 
         /* set up three characters to be used in determining whether
         "." should not be considered as a seperator*/
         char previous=' ', current, next; 
         fin.open(textFile);
         if(!fin)
         {
            throw runtime_error("Unable to access the file");
         }
         while (!fin.eof())
         {
            if(fin.good()) 
            {
               // read the file character by character
               current=fin.get();
               // read the next character
               next=fin.peek();
               
               /* append '.' to the searchWord's text 
               if it should not be considered as a seperator*/
               if(isSpecChar(previous) && current=='.' && isdigit(next))
               {
                  searchWord.push_back(current);
                  previous=current;
               }
               else if(isSeparator(current))
               {
                  if(!isSeparator(previous))
                  {
                     /* if the word is a number , then it is initialized to "",
                     and it will not be counted in the totalword.*/
                     if(isNumber(searchWord))
                     {
                        searchWord="";
                        previous=current;
                     }
                     else
                     {
                        if(!dict.findWord(toLowerCase(searchWord)))
                        {
                           unknownwordList.push_back(searchWord);
                           unknownSpelling++;
                        }
                        /*if the word is not in the dictionary, 
                        then searchWord is initialized to ""*/
                        searchWord=""; 
                        previous=current;
                        totalWord++;
                     }
                  }
               }
               else 
               {
                  searchWord.push_back(current);
                  previous=current;
                  /* if the current character is in the end of the file,
                  then check the searchWord immediately*/
                  if(fin.eof())
                  {
                     // if searchWord is a number then exit immediately.
                     if(isNumber(searchWord))
                     {
                        break;
                     }
                     //check whether the last word can be found in dict
                     if(!dict.findWord(toLowerCase(searchWord)))
                     {
                        unknownwordList.push_back(searchWord);
                        unknownSpelling++;
                     }
                     totalWord++;
                  }
               }
            }
         }
         fin.close();    
      }

      void loadDictionary(const char* dictionaryFile)
      {
         //load all the words from the provided file to dict.
         dict.loadDictionary(dictionaryFile);
      }

      void PrintWords() const
      {
         list<string>::const_iterator itr;
         for (itr = unknownwordList.begin(); itr != unknownwordList.end(); itr++) 
         {
            cout<<*itr<<endl;
         }
         cout<<"A total of "<<totalWord<<" words were found in the file\n";
         cout<<unknownSpelling<<" had unknown spelling"<<endl;
      }
};