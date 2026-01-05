class Twitter {
public:
    unordered_map<int, unordered_set<int>>followList;
    unordered_map<int, vector<pair<int,int>>>tweet;
    int timestamp = 0;
    Twitter() {
    
    }
    
    void postTweet(int userId, int tweetId) {
        tweet[userId].push_back({timestamp, tweetId});
        timestamp++;
    }
    
    vector<int> getNewsFeed(int userId) {
        vector<int>ans;
        priority_queue<tuple<int,int,int,int>>pq;
        followList[userId].insert(userId);
        for(auto followeeId : followList[userId]){
            if(tweet.count(followeeId)){
                int index = tweet[followeeId].size()-1;
                auto [count, tweetId] = tweet[followeeId][index];
                pq.push(make_tuple(count, tweetId, followeeId, index-1));
            }
        }

        while(pq.size() && ans.size()<10){
            auto [count, tweetId, followeeId, index] = pq.top();
            pq.pop();
            ans.push_back(tweetId);
            if(index>=0){
                auto [count, tweetId] = tweet[followeeId][index];
                pq.push(make_tuple(count, tweetId, followeeId, index-1));
            }
        }
        return ans;
    }
    
    void follow(int followerId, int followeeId) {
        followList[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        if(followList.count(followerId) && followList[followerId].count(followeeId)){
            followList[followerId].erase(followeeId);
        }
    }
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter* obj = new Twitter();
 * obj->postTweet(userId,tweetId);
 * vector<int> param_2 = obj->getNewsFeed(userId);
 * obj->follow(followerId,followeeId);
 * obj->unfollow(followerId,followeeId);
 */