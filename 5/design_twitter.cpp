/*
Design a simplified version of Twitter where users can post tweets, follow/unfollow another user and is able to see the 10 most recent tweets in the user's news feed. Your design should support the following methods:

postTweet(userId, tweetId): Compose a new tweet.
getNewsFeed(userId): Retrieve the 10 most recent tweet ids in the user's news feed. Each item in the news feed must be posted by users who the user followed or by the user herself. Tweets must be ordered from most recent to least recent.
follow(followerId, followeeId): Follower follows a followee.
unfollow(followerId, followeeId): Follower unfollows a followee.
Example:
Twitter twitter = new Twitter();

// User 1 posts a new tweet (id = 5).
twitter.postTweet(1, 5);

// User 1's news feed should return a list with 1 tweet id -> [5].
twitter.getNewsFeed(1);

// User 1 follows user 2.
twitter.follow(1, 2);

// User 2 posts a new tweet (id = 6).
twitter.postTweet(2, 6);

// User 1's news feed should return a list with 2 tweet ids -> [6, 5].
// Tweet id 6 should precede tweet id 5 because it is posted after tweet id 5.
twitter.getNewsFeed(1);

// User 1 unfollows user 2.
twitter.unfollow(1, 2);

// User 1's news feed should return a list with 1 tweet id -> [5],
// since user 1 is no longer following user 2.
twitter.getNewsFeed(1);
*/

#include "header.h"

class comp{
    public:
        bool operator() (pair<int,int> a, pair<int,int> b){
            return b.second<a.second;
        }
};

class Twitter {
    unordered_map<int, unordered_set<int> > followers;
    unordered_map<int, unordered_set<int> > following;
    unordered_map<int, vector<pair<int,int> > > posts;
    int time;
public:
    /** Initialize your data structure here. */
    Twitter() {
        this->time = 0;
    }
    
    /** Compose a new tweet. */
    void postTweet(int userId, int tweetId) {
        this->posts[userId].push_back(make_pair(tweetId, this->time++));    
    }

    /** Retrieve the 10 most recent tweet ids in the user's news feed. Each item in the news feed must be posted by users who the user followed or by the user herself. Tweets must be ordered from most recent to least recent. */
    vector<int> getNewsFeed(int userId) {
        vector<int> res;
        priority_queue<pair<int,int>, vector<pair<int,int> >, comp> pq;
        for(int i=(this->posts[userId].size())-1; i>=0 && pq.size()<10; i--){
            pq.push(this->posts[userId][i]);
        }
        for(int followee : this->following[userId]){
            vector<pair<int,int> > temp_posts = this->posts[followee];
            int p = temp_posts.size()-1;
            while(p>=0 && (pq.size()<10 || temp_posts[p].second>pq.top().second)){
                if(pq.size()>=10) pq.pop();
                pq.push(temp_posts[p--]);
            }
        } 
        while(!pq.empty()){
            res.push_back(pq.top().first);
            pq.pop();
        }
        reverse(res.begin(), res.end());
        return res;
    }
    
    /** Follower follows a followee. If the operation is invalid, it should be a no-op. */
    void follow(int followerId, int followeeId) {
        if(followerId == followeeId) return;
        this->followers[followeeId].insert(followerId);
        this->following[followerId].insert(followeeId);
    }
    
    /** Follower unfollows a followee. If the operation is invalid, it should be a no-op. */
    void unfollow(int followerId, int followeeId) {
        if(this->followers[followeeId].find(followerId) != this->followers[followeeId].end()){
            this->followers[followeeId].erase(this->followers[followeeId].find(followerId)); 
            this->following[followerId].erase(this->following[followerId].find(followeeId));
        }
    }
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter obj = new Twitter();
 * obj.postTweet(userId,tweetId);
 * vector<int> param_2 = obj.getNewsFeed(userId);
 * obj.follow(followerId,followeeId);
 * obj.unfollow(followerId,followeeId);
 */

int main(){
    Twitter* twitter = new Twitter();
    twitter->postTweet(1, 5);
    twitter->follow(1, 2);
    twitter->follow(2, 1);
    print_vector<int>(twitter->getNewsFeed(2));
    twitter->postTweet(2, 6);
    print_vector<int>(twitter->getNewsFeed(1));
    print_vector<int>(twitter->getNewsFeed(2));
    return 0;
}
