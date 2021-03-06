using namespace std;

class dictionary
{
   private:
      // use bintree structure to store all the words from dictionary file
      bintree<string> treeRoot;

   public:
      // constructor
      dictionary() 
      {
      }

      void loadDictionary(const char* file)
      {
         ifstream fin;
         fin.open(file);
         if(!fin)
         {
            throw runtime_error("Unable to open dictionary file to read");
         }

         while(!fin.eof())
         {
            string word;
            if(fin.good()) 
            {
               fin >> word; 
               treeRoot.insert(word);
            }
         }
         fin.close();
      }
      // return true if s is a word can be found in the dictionary
      bool findWord(const string &word) const
      {
         const string* pointer=NULL; 
         pointer=treeRoot.find(word);
         if(pointer == NULL)
         {
            return false;
         }
         return true;
      }
};