#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <queue>

using namespace std;

class Twitter {
private:
    int time;
    unordered_map<int, unordered_set<int>> follows;
    unordered_map<int, vector<pair<int, int>>> tweets; // userId -> list of {timestamp, tweetId}

public:
    Twitter() {
        time = 0;
    }
    
    void postTweet(int userId, int tweetId) {
        tweets[userId].push_back({time++, tweetId});
    }
    
    vector<int> getNewsFeed(int userId) {
        // Priority queue storing {timestamp, tweetId, userId, index_in_user_tweets}
        priority_queue<vector<int>> maxHeap;
        
        // Include self in the set of accounts to check
        unordered_set<int> userList = follows[userId];
        userList.insert(userId);
        
        for (int followeeId : userList) {
            if (tweets.count(followeeId) && !tweets[followeeId].empty()) {
                int idx = tweets[followeeId].size() - 1;
                auto& tweet = tweets[followeeId][idx];
                maxHeap.push({tweet.first, tweet.second, followeeId, idx});
            }
        }
        
        vector<int> res;
        while (!maxHeap.empty() && res.size() < 10) {
            auto curr = maxHeap.top();
            maxHeap.pop();
            
            int tweetId = curr[1];
            int followeeId = curr[2];
            int idx = curr[3];
            
            res.push_back(tweetId);
            
            // Push the previous tweet from the same followee into the heap
            if (idx - 1 >= 0) {
                auto& prevTweet = tweets[followeeId][idx - 1];
                maxHeap.push({prevTweet.first, prevTweet.second, followeeId, idx - 1});
            }
        }
        
        return res;
    }
    
    void follow(int followerId, int followeeId) {
        if (followerId != followeeId) {
            follows[followerId].insert(followeeId);
        }
    }
    
    void unfollow(int followerId, int followeeId) {
        if (follows.count(followerId)) {
            follows[followerId].erase(followeeId);
        }
    }
};