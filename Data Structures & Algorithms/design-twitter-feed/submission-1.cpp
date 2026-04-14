class Twitter {
    int time; 

    struct User {
        vector<pair<int, int>> tweets; // {timestamp, tweetId}
        unordered_set<int> following;
    };
    unordered_map<int, User> users;

public:
    Twitter() {
        time = 0;
    }
    
    void postTweet(int userId, int tweetId) {
        users[userId].tweets.push_back({time, tweetId}); 
        time++; 
    }
    
    vector<int> getNewsFeed(int userId) {
        priority_queue<pair<int, int>> h;   // timestamp, tweetId

        User u = users[userId];
        // try to push 10 most recent user tweets 
        int pos = u.tweets.size() - 1; 
        for (int i = 0; i < 10 && pos >= 0; i++, pos--) {
            h.push({u.tweets[pos].first, u.tweets[pos].second});
        }

        // for each follower, push 10 most recent tweets 
        for (int f:u.following) {
            vector<pair<int, int>> t = users[f].tweets;
            int pos = t.size() - 1; 
            for (int i = 0; i < 10 && pos >= 0; i++, pos--) {
                h.push({t[pos].first, t[pos].second});
            }
        }

        vector<int> output = {};
        for (int i = 0; i < 10 && h.size() > 0; i++) {
            output.push_back(h.top().second); 
            h.pop();
        }
        return output;
    }
    
    void follow(int followerId, int followeeId) {
        if (followerId == followeeId) return;
        users[followerId].following.insert(followeeId); 
    }
    
    void unfollow(int followerId, int followeeId) {
        users[followerId].following.erase(followeeId); 
    }
};
