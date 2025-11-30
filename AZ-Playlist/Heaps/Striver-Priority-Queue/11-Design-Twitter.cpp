// APPROACH: PQ FOR GET TWEET: TOP K ELEMENTS
// Each tweet has a global increasing timestamp.
// For any user, news feed = top 10 most recent tweets from:
//     - the user
//     - all followees

// Use a min-heap of size 10 storing {timestamp, tweetId}.
// Push both types of tweets; if size > 10, pop smallest.

// Stores the tweets of each user as a vector of (timestamp, tweetId)
// Stores the set of followees for each user
// Global time counter to sort tweets

//
// TC: getNewsFeed ≈ O(T log 10) where T = total tweets from user + followees.

class Twitter {
    unordered_map<int, unordered_set<int>> following;
    unordered_map<int, vector<pair<int, int>>> tweets;
    int timeOffset;

public:
    Twitter() { timeOffset = 0; }

    void postTweet(int userId, int tweetId) {
        tweets[userId].push_back({timeOffset++, tweetId});
    }

    vector<int> getNewsFeed(int userId) {
        // top 10 max timeOffset elements

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>>
            minHeap;

        // push both - user’s own tweets and tweets of followees
        for (auto& t : tweets[userId]) {
            minHeap.push(t);
            if (minHeap.size() > 10)
                minHeap.pop();
        }

        for (int f : following[userId]) {
            for (auto& t : tweets[f]) {
                minHeap.push(t);
                if (minHeap.size() > 10)
                    minHeap.pop();
            }
        }

        vector<int> ans(minHeap.size());
        int idx = ans.size();
        while (!minHeap.empty()) {
            ans[--idx] = minHeap.top().second;
            minHeap.pop();
        }
        return ans;
    }

    void follow(int followerId, int followeeId) {
        following[followerId].insert(followeeId);
    }

    void unfollow(int followerId, int followeeId) {
        following[followerId].erase(followeeId);
    }
};
