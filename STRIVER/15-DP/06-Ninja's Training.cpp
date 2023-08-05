//for each day find the activity that has max points, provided it was not done on last day.
//so, we need to keep track of the activity that we did.
//Greedy won't work.

//last (activity) can be 0, 1, 2 OR any specific number (like 3) for unidefined/no activity.

//return sum of points gained by perform one activity each day.

int rec(int day, int last, vector<vector<int>> &points)
{
    //base case, day = 0.
    int maxi = 0;

    if(day == 0)
    {
        for(int i = 0; i < 3; i++)
        {
            if(i != last)
                maxi = max(maxi, points[0][i]);
        }

        return maxi;
    }

    maxi = 0;

    for(int i = 0; i < 3; i++)
    {
        if(i != last)
        {
            //points of this day on activity + points till the last day, if this activity was performed today
            maxi = max(maxi, points[day][i] + rec(day - 1, i, points));
        }
    }

    return maxi;
}


int ninjaTraining(int n, vector<vector<int>> &points)
{
    return rec(n - 1, 3, points);
}

//memo
//for each day find the activity that has max points, provided it was not done on last day.
//so, we need to keep track of the activity that we did.
//Greedy won't work.

//last (activity) can be 0, 1, 2 OR any specific number (like 3) for unidefined/no activity.

//return sum of points gained by perform one activity each day.

int rec(int day, int last, vector<vector<int>> &dp, vector<vector<int>> &points)
{
    //base case, day = 0.
    int maxi = 0;

    if(day == 0)
    {
        for(int i = 0; i < 3; i++)
        {
            if(i != last)
                maxi = max(maxi, points[0][i]);
        }

        return maxi;
    }

    //if exists
    if(dp[day][last] != -1)
        return dp[day][last];

    maxi = 0;

    for(int i = 0; i < 3; i++)
    {
        if(i != last)
        {
            //points of this day on activity + points till the last day, if this activity was performed today
            maxi = max(maxi, points[day][i] + rec(day - 1, i, dp, points));
        }
    }

    return dp[day][last] = maxi;
}


int ninjaTraining(int n, vector<vector<int>> &points)
{
    //dp[n][4]
    vector<vector<int>> dp(n,vector<int>(4,-1));
    
    return rec(n - 1, 3, dp, points);
}

//tab
int ninjaTraining(int n, vector<vector<int>> &points)
{
    //dp[n][4]
    vector<vector<int>> dp(n,vector<int>(4,-1));
    
    dp[0][0] = max(points[0][1], points[0][2]);
    dp[0][1] = max(points[0][0], points[0][2]);
    dp[0][2] = max(points[0][0], points[0][1]);
    dp[0][3] = max(points[0][0], max(points[0][1], points[0][2]));

    

    for(int day = 1; day < n; day++)
    {
        for(int last = 0; last < 4; last++)
        {
            int maxi = 0;

            for(int i = 0; i < 3; i++)
            {
                if(i != last)
                    maxi = max(maxi, points[day][i] + dp[day - 1][i]);
            }

            dp[day][last] = maxi;
        }
    }

    return dp[n - 1][3];
}

//space opt
int ninjaTraining(int n, vector<vector<int>> &points)
{
    //dp[n][4]
    vector<int> prevDay(4, -1);
    
    prevDay[0] = max(points[0][1], points[0][2]);
    prevDay[1] = max(points[0][0], points[0][2]);
    prevDay[2] = max(points[0][0], points[0][1]);
    prevDay[3] = max(points[0][0], max(points[0][1], points[0][2]));

    

    for(int day = 1; day < n; day++)
    {
        vector<int> currDay(4, -1);

        for(int last = 0; last < 4; last++)
        {
            int maxi = 0;

            for(int i = 0; i < 3; i++)
            {
                if(i != last)
                    maxi = max(maxi, points[day][i] + prevDay[i]);
            }

            currDay[last] = maxi;
        }

        prevDay = currDay;
    }

    return prevDay[3];
}
