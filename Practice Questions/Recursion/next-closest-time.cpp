// TC: O(1), constant time complexity.
// As maximum, our loop will run maximum for 24*60=1440 making complexity as O(1440).


class Solution {
public:
    string incrementTime(string time) {
        int h = stoi(time.substr(0, 2));
        int m = stoi(time.substr(3, 2));
        
        if (++m == 60) {
            m = 0;
            if (++h == 24) {
                h = 0;
            }
        }
        string hstr = to_string(h);
        string mstr = to_string(m);
        
        if (h < 10) hstr = "0" + hstr;
        if (m < 10) mstr = "0" + mstr;
        
        string result = hstr + ":" + mstr;
        return result;
    }
    
    
    string nextClosestTime(string time) {
        unordered_set<char> chars;
        for (char c : time) chars.insert(c);
        string tempTime = time;
        string result = time;
        while (true) {
            string newTime = incrementTime(tempTime);
            bool allValid = true;
            for (char c : newTime) {
                if (chars.find(c) == chars.end()) {
                    allValid = false;
                    break;
                }
            }
            if (allValid) {
                return newTime;
            }
            tempTime = newTime;
        }
        return result;
    }
};

//DFS
//TC: O(4^4) = O(256)

#include <bits/stdc++.h> 

bool isValid(int hh, int mm){

    if(hh > 23 || mm > 59)
        return false;

    return true;
}
int minsDiff(int m1, int m2){

    if(m1 == m2)
        return INT_MAX;

    int t = 24 * 60;

    return (m1 - m2 + t) % t;
}

void dfs(int ind, int& ansMins, vector<int>& ans, int givenMins, vector<int>& digits){
    if(ind == 4){ //last digit filled

        int hh = ans[0] * 10 + ans[1];
        int mm = ans[2] * 10 + ans[3];

        if(!isValid(hh, mm))
            return;

        else{
            int currMins = hh * 60 + mm;
            if(minsDiff(currMins, givenMins) < minsDiff(ansMins, givenMins))
                ansMins = currMins;
            return;
        }
    }

    for(int d : digits){
        ans[ind] = d;
        dfs(ind + 1, ansMins, ans, givenMins, digits);
    }
}
string ninjaWatch(string &time)
{
    int hh = stoi(time.substr(0, 2));
    int mm = stoi(time.substr(3, 2));

    vector<int> digits;

    for (int i = 0; i <= 4; i++) {
      if (i == 2)
        continue;
      digits.push_back(time[i] - '0');
    }

    int givenMins;
    givenMins = hh * 60 + mm;

    vector<int> ans(4, 0); // 00:00
    int ansMins = givenMins;


    //generate all valid permutations and choose the best one
    dfs(0, ansMins, ans, givenMins, digits);

    string ansString = "";
    int ansHH = ansMins / 60;
    int ansMM = ansMins % 60;

    
    if(ansHH < 10){
        ansString += "0";
    }

    ansString += to_string(ansHH) + ":";

    if(ansMM < 10){
        ansString += "0";
    }

    ansString += to_string(ansMM);

    return ansString;
}
