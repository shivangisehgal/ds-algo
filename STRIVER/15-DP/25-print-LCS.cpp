string findLCS(int n1, int n2, string &text1, string &text2){

  /*--------------------DP ARRAY FOR LCS-------------------*/
    vector<vector<int>> dp(n1 + 1, vector<int>(n2 + 1, -1));
        
        for(int i = 0; i <= n1; i++)
            dp[i][0] = 0;
        
        for(int j = 0; j <= n2; j++)
            dp[0][j] = 0;
        
        
        for(int i = 1; i <= n1; i++)
        {
            for(int j = 1; j <= n2; j++)
            {

                
                if(text1[i - 1] == text2[j - 1])
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                
                else
                    dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
            }
        }
    /*--------------------DP ARRAY FOR LCS-------------------*/
  
		int i = n1;
		int j = n2;
		string ans = "";

		while(i > 0 && j > 0)
		{
			if(text1[i - 1] == text2[j - 1])
			{
				//move diagonally up
				ans = text1[i - 1] + ans;
				i = i - 1;
				j = j - 1;
			}

			else if(dp[i - 1][j] >= dp[i][j - 1])
				i = i - 1;
			else
				j = j - 1;
		}
		
		//cout << ans;
        return ans;
    }
