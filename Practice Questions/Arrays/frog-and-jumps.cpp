class Solution {
  public:
    int unvisitedLeaves(int N, int leaves, int frogs[]) {
        // Code here
        
        vector<bool> leafMap(leaves, false);
        
        for(int i = 0; i < N; i++)
        {
           if(frogs[i] <= leaves && leafMap[frogs[i] - 1] == false)
           {
               for(int j = 1; j * frogs[i] <= leaves; j++)
                {
                    int leaf = j * frogs[i];
                    leafMap[leaf - 1] = true;
                }
           }
        }
        
        int count = 0;
        
        for(int i = 0; i < leaves; i++)
        {
            if(leafMap[i] == false)
                count++;
        }
        
        return count;
    }
};
