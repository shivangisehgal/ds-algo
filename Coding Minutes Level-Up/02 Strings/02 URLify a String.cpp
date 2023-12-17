//1. Brute
//Replace all spaces by %20, assume sufficient additional spaces are given at the end of the true string

#include <iostream>
using namespace std;

/****************************************************************/

void replaceSpaces(char str[], int trueLength)
{
    int spaceCount = 0;

    for(int i = 0; i < trueLength; i++)
    {
          if(str[i] == ' ')
              spaceCount++;
    }

    int j = trueLength + 2 * spaceCount;
    
    str[j] = '\0';
    j--;

    int i = trueLength - 1;

    while(i >= 0)
    {
        if(str[i] != ' ')
        {
            str[j] = str[i];
            
            j--;
            i--;
        }

        else
        {
            str[j - 2] = '%';
            str[j - 1] = '2';
            str[j] = '0';

            j = j - 3;
            i--;
        }
    }

    cout << str << endl;
    
}

/****************************************************************/

int main() {
    
    // Test Case 1
    char str1[100] = "Mr John Smith    ";
    int trueLength1 = 13; 
    replaceSpaces(str1, trueLength1);
    

    // Test Case 2
    char str2[100] = "Hello World, how are you?";
    int trueLength2 = 25; 
    replaceSpaces(str2, trueLength2);
    

    // Test Case 3
    char str3[100] = "   ";
    int trueLength3 = 0; 
    replaceSpaces(str3, trueLength3);

    return 0;
}
