//key idea: hash_map and hash_set 

class Twitter {
 public:
  /** Initialize your data structure here. */
  Twitter() : users(), posts() {

  }

  /** Compose a new tweet. */
  void postTweet(int userId, int tweetId) {
    users[userId].insert(userId);
    posts.push_back(make_pair(userId, tweetId));
  }

  /** Retrieve the 10 most recent tweet ids in the user's news feed. Each item in the news feed must be posted by users who the user followed or by the user herself. Tweets must be ordered from most recent to least recent. */
  vector<int> getNewsFeed(int userId) {
    users[userId].insert(userId);
    vector<int> results;
    auto following = users[userId];
    int count = 0;
    for (auto it = posts.rbegin(); it != posts.rend() && count < 10; ++it) {
      auto pair = *it;
      if (following.count(pair.first)) {
        results.push_back(pair.second);
        ++count;
      }
    }
    return results;
  }

  /** Follower follows a followee. If the operation is invalid, it should be a no-op. */
  void follow(int followerId, int followeeId) {
    users[followerId].insert(followeeId);
  }

  /** Follower unfollows a followee. If the operation is invalid, it should be a no-op. */
  void unfollow(int followerId, int followeeId) {
    users[followerId].erase(followeeId);
  }
 private:
  unordered_map<int, unordered_set<int>> users;
  vector<pair<int, int>> posts;
};