//Create your own strtok()
//we will have a token string and input string
//strok return the pointer to a token and internally changes and manages the state of input
//Hence, input must be global (not possible), hence, static in the function

//input: "Hello World C++ Tokenization"
//after 1: token = "Hello"  input = "World C++ Tokenization"
//after 2: token = "World" input = "C++ Tokenization"
//after 3: token = "C++" input = "Tokenization"
//after 4: token = "Tokenization" input = NULL

#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

/*******************************************************/

char* mystrtok(char* str, char delim)
{
    static char* input = NULL;
    
    if(str != NULL)
        input = str;
    
    if(input == NULL)
        return NULL;
        
    char* token = new char[strlen(input) + 1]; //for null character
    
    int i = 0;
    
    
    while(input[i] != '\0')
    {
        if(input[i] != delim)
            token[i] = input[i];
        else
        {
            token[i] = '\0';
            input += i + 1;
            return token;
        }
        
        i++;
    }
    
    //last word
    token[i] = '\0';
    input = NULL;
    
    return token;
}



vector<string> tokenizeString(char input[]) {

    vector<string> tokenArr;
    
    char delimiter = ' '; 
    
    char* token = mystrtok(input, delimiter);
    

    while (token != NULL) {
        
        tokenArr.push_back(token);
        token = mystrtok(NULL, delimiter);
    }
    
    return tokenArr;
}

/*******************************************************/

int main() {
    
    char inputString[] = "Hello World C++ Tokenization";
    
    vector<string> tokens = tokenizeString(inputString);

    for (const auto& token : tokens) {
        cout << token << endl;
    }

    return 0;
}
