/*
ID: 63011293
Name: Raviphas Sananpanichkul
Final Project
OBJECT-ORIENTED CONCEPTS AND PROGRAMMING
Teacher: Sarun Intakosum
University: King Mongkut's Institute of Technology Ladkrabang
*/

#ifndef VOCABBACK_H
#define VOCABBACK_H
#include <fstream>
#include <vector>
#include <string>
#include <direct.h>
#include <QDebug>
using namespace std;

/*
 * Vocab header was created to take care of all the gameplay
 * 1.Create a word pool by random
 * 2.Check which vocab exist in the dict
 */

class Vocab{
    private:
    //Homepath easier when change project location
        string home_path;
    // Charpool or Voacb pool
        string charpool = "";
    public:
        Vocab(){
            home_path = getCurrentDir();
        }

        string getCurrentDir(){
            //the maximum length for a path is MAX_PATH, which is defined as 260
            char buff[PATH_MAX];
            _getcwd( buff, PATH_MAX ); //Get the current working directory pathname
            string current_working_dir(buff);
            return current_working_dir + "\\";
        }

        //Word pool management
        void clearPool(){
            charpool.clear();
        }
        const string getCharPool(){
            return charpool;
        }
        //Scramble method
        void scramble(){
            /*
             * Since the length of the charpool is 24
             * We just swap position in the char pool
             * so that the char is not in the same order
            */
            for(int i =0; i < 23 ; i++){
                int nIndex = rand()%23; // 0<= nIndex < 23
                if(i != nIndex) //If the random number and the current index is not the same
                    swap(i,nIndex); // swap postion of charpool[i] and charpool[nIndex]
            }

        }

        //Add new random words to the charpool
        void addRandom(){
            fstream read_file;
            string line;
            int temp = (rand()%868)+1; //Three length word
            string fileName = home_path + "threeBank.txt";
            read_file.open(fileName, ios::in);
            if(!read_file){
                qDebug() << "threeBank.txt not found\n";
            }
            // We need three vocabs that is three characters long
            for(int outer_loop = 0; outer_loop < 3; outer_loop++){
            for(int loop_file = 0; loop_file != temp; loop_file++){
                getline(read_file, line);
            }
            read_file.seekg(0, ios::beg);
            temp = (rand()%868)+1;
            //After find the word that match to the random int then insert the vocab to charpool
            charpool.insert(0,line);
            }
            read_file.close();
            fileName =  home_path +  "fiveBank.txt";
            read_file.open(fileName, ios::in);
            if(!read_file){
                qDebug() << "fiveBank.txt not found\n";
            }
            temp = (rand()%5740)+1;//Five length word
            // We need one vocab that is five characters long
            for(int loop_file = 0; loop_file != temp; loop_file++){
                getline(read_file, line);
            }
            charpool.insert(0,line);
            read_file.close();
            fileName =  home_path + "tenBank.txt";
            read_file.open(fileName, ios::in);
            if(!read_file){
                qDebug() << "tenBank.txt not found\n";
            }
            temp = (rand()%9739)+1;//Ten length word
            // We need one vocab that is ten characters long
            for(int loop_file = 0; loop_file != temp; loop_file++){
                getline(read_file, line);
            }
            charpool.insert(0,line);
            read_file.close();
        }

        //swap func
        void swap(int a,int b){
            if(a != b){ // if a and b is the same then do nothing
            char temp = charpool[a];
            charpool[a] = charpool[b];
            charpool[b] = temp;
            }
        }

        //check
        bool isVocab(string word){
            fstream read_file;
            bool out = false;
            string line;
            string fileName =  home_path + "dict.txt";
            read_file.open(fileName, ios::in);
            if(!read_file){
                qDebug() << "dict.txt not found";
            }
            else{
                while (read_file) //if not EOF
                {
                //read line
                getline(read_file, line);
                if(word.compare(line) == 0) //If it is possible to find
                    out = true; //Then it is possible to find
                }
                read_file.close(); // close file
            }
            return out;
        }

};
#endif // VOCABBACK_H
