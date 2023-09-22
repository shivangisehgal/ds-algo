//Refer handwritten notes
//TC: N * K * 26 * logN //where K is the length of max word | logN is for hashset

class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        
        unordered_set<string> wordSet(wordList.begin(), wordList.end());
        queue<pair<string, int>> q;
        
        q.push({beginWord, 1});
        wordSet.erase(beginWord);
        
        while(!q.empty())
        {
            auto p = q.front();
            q.pop();
            
            string word = p.first;
            int level = p.second;
            
            if(word == endWord)
                return level;
            
            for(int i = 0; i < word.size(); i++)
            {
                char original_char = word[i];
                
                for(char ch = 'a'; ch <= 'z'; ch++)
                {
                    word[i] = ch;
                    
                    if(wordSet.find(word) != wordSet.end())
                    {
                        q.push({word, level + 1});
                        wordSet.erase(word);
                    }
                }
                
                word[i] = original_char;
            }
        }
        
        return 0;
    }
};
