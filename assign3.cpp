#include <iostream>
#include <fstream>
#include <string>
#include "GenStack.h"

using namespace std;

//This program in main because it takes command line argument.
int main(int argc, char **argv) {

  string k = "";

  if (argc > 1){
    cout <<"\nYour file name is " <<argv[1] <<"\n"<<endl;
  }
  else{
    cout <<"No file name entered. ";
    return -1;
  }

	string u = "yes";
	string file;

	file = argv[1];

	while(u == "yes") {
    ifstream file(argv[1]);// opens the file that was passed through the command line
    if (file.is_open() && file.good()) {//Checks if the file is open and is good. Else it will state that file is not found
      GenStack s;
      GenStack line;
      int count = 1;
      char x;

      while(getline(file, k)){
//This for loop goes throguh the inputed file and goes through each character.
//It will then insert the oppennignt prenthasis into a stack called s.
//finaaly, it will check if the the prethasis are equal or not or if there is a prethasis missing.
    for (int i=0; i<k.length(); i++)
    {
            switch(k[i]) {
    					case '{':
    						s.push('{');
    						line.push(count);
    						break;
    					case '[':
    						s.push('[');
    						line.push(count);
    						break;
    					case '(':
    						s.push('(');
    						line.push(count);
    						break;


          //------------------- Check if { does not have a }
         case '}':

         if(s.empty()) {
           cout << "Line " << count << ": Unaccompanied }." << endl;
           exit(0);
         }
         else if (s.peak() != '{') {

           if (line.peak() != count) {
             if (s.peak() == '(') {
               cout << "Expected ) at line " << line.peak() << endl;
               exit(0);
             }
             else if (s.peak() == '[') {
               cout << "Expected ] at line " << line.peak() << endl;
               exit(0);
             }
           }
           else {
             if (s.peak() == '[') {
               cout << "Line " << count << ": Found } where ] Expected." << endl;
               exit(0);
             }
             else if (s.peak() == '(') {
               cout << "Line " << count << ": Found } where ) Expected." << endl;
               exit(0);
             }
           }
         }
         else if (s.peak() == '{') {
           try {
             s.pop();
             line.pop();
           } catch (exception &e) {
           cout << e.what() << endl;
           }
         }
         break;
         //------------------- Check if [ does not have a ]
       case ']':
         if(s.empty()) {
           cout << "Line " << count << ": Unaccompanied ]." << endl;
           exit(0);
         }

         if (s.peak() != '[') {
           if (line.peak() != count) {
             if (s.peak() == '{') {
               cout << "Line " << count << ": Found ] where } Expected." << endl;
               exit(0);
             }
             else if (s.peak() == '(') {
               cout << "Expected ) at line " << line.peak() << endl;
               exit(0);
             }
           }
           else {
             if (s.peak() == '{') {
               cout << "Line " << count << ": Found ] where } Expected." << endl;
               exit(0);
             }
             else if (s.peak() == '(') {
               cout << "Line " << count << ": Found ] where ) Expected." << endl;
              exit(0);
             }
           }
         }
         else {
           try {
             s.pop();
             line.pop();
           } catch (exception &e) {
           cout << e.what() << endl;
           }
         }
         break;
         //------------------- Check if ( does not have a )
       case ')':
         if (s.empty()) {
           cout << "Line " << count << ": Unaccompanied }." << endl;
           exit(0);
         }
         else if (s.peak() != '(') {
           if (line.peak() != count) {
             cout << "Expected ( at line " << count << endl;
             exit(0);
           }
           else {
             if (s.peak() == '{') {
               cout << "Line " << count << ": Found ) where } Expected." << endl;
               exit(0);
             }
             else if (s.peak() == '[') {
               cout << "Line " << count << ": Found ) where ] Expected." << endl;
               exit(0);
             }
           }
         }
         else if (s.peak() == '(') {
           try {
             s.pop();
             line.pop();
           } catch (exception &e) {
           cout << e.what() << endl;
           }
         }
         break;
     }
   }
 ++count;
}
    if(!s.empty()) {
       if (s.peak() == '{') {
         cout << "Reached end of file. Expected a }" << endl;
       }
       else if(s.peak() == '(') {
         cout << "Reached end of file. Expected a )" << line.peak() << endl;
       }
       else if(s.peak() == '[') {
         cout << "Reached end of file. Expected a ]" << line.peak() << endl;
       }
       exit(0);
     }
  }
  file.close();
  cout << "Your file is balanced.\nWould you like to analyze another file? type yes or no please " << endl;

  string u;
  getline(cin, u);
  for (char& l : u){
    l = tolower(l);
  }

  while(!(u== "yes" || u == "no")) {
    cout << "Please type yes or no." << endl;
    getline(cin, u);
  }

  if(u == "yes") {
    cout << "Type new file name: " << endl;
    cin>>argv[1];
    cout <<"\nYour file name is " <<argv[1] <<"\n"<<endl;
    continue;
  }

  else if(u == "no") {
    cout << "\nThank you.\n" << endl;
    exit(0);
      }
    }
  }
