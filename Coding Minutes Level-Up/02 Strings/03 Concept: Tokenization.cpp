//Tokenization means to create tokens based on a delimiter

//1. Using stringstream

#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

/*******************************************************/

vector<string> tokenizeString(string& input) {

    vector<string> tokenArr;
  
    stringstream ss(input);

    string token;
    char delimiter = ' ';
  
    while(getline(ss, token, delimiter))
    {
        tokenArr.push_back(token);
    } 
    
    return tokenArr;
}

/*******************************************************/

int main() {
  
    string inputString = "Hello World C++ Tokenization";
    
    vector<string> tokens = tokenizeString(inputString);
  
    for (auto token : tokens) {
        cout << token << endl;
    }

    return 0;
}

//2. strtok()
//returns the pointer to the next token if there is any

#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

/*******************************************************/

vector<string> tokenizeString(char input[]) {

    vector<string> tokenArr;
    
    const char* delimiter = " "; //important
    
    char* token = strtok(input, delimiter);

    while (token != NULL) {
        tokenArr.push_back(token);
        token = strtok(NULL, delimiter);
    }
    
    return tokenArr;
}

/*******************************************************/

int main() {
    
    char inputString[] = "Hello World C++ Tokenization";
    
    vector<string> tokens = tokenizeString(inputString);

    for (auto token : tokens) {
        cout << token << endl;
    }

    return 0;
}
