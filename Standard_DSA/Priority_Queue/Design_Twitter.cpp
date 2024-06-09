class Tweet {

public:
    int id,time;
    Tweet* next;
    Tweet(int i,int t):id(i),time(t),next(NULL){}

};

class User {
   public:
   int id;
   unordered_set<int>follows;
   Tweet* tweets;

   User(){}

    User(int i){
        id=i;
        tweets=NULL;
        follow(i);
    }

    void follow(int userId){
        follows.insert(userId);
    }

    void unfollow(int userId){
        follows.erase(userId);
    }

    void post(int tweetId,int time) {
         Tweet* cur=tweets;
         tweets=new Tweet(tweetId,time);
         tweets->next=cur;

    }

};

class Twitter{

public:
    Twitter() {
    }
    /** Compose a new tweet. **/
    void postTweet(int userId, int tweetId) {
        if(users.find(userId)==users.end()){
            users[userId] = User(userId);
        }
        users[userId].post(tweetId,time++);
    }

    vector<int> getNewsFeed(int userId) {

        vector<int>feed;

        if(users.find(userId)==users.end())
        return feed;

        unordered_set<int>userIds=users[userId].follows;

        priority_queue<Tweet*,vector<Tweet*>,compare>pq;

        for(int userId:userIds){

            Tweet* tweets=users[userId].tweets;
            if(tweets){
                pq.push(tweets);
            }
        }

        int i=0;

        while(!pq.empty() && i++<10) {

          Tweet* tweets=pq.top();
          pq.pop();

          feed.push_back(tweets->id);

          if(tweets->next)
          {
            pq.push(tweets->next);
          }

        }

        return feed;

    }

    void follow(int followerId, int followeeId) {

        if(users.find(followerId)==users.end()){
            users[followerId]=User(followerId);
        }
        if(users.find(followeeId)==users.end())
        {
            users[followeeId]=User(followeeId);
        }

        users[followerId].follow(followeeId);
    }

    //
    void unfollow(int followerId, int followeeId) {

      if(users.find(followerId)!=users.end() && followerId!=followeeId)
      {
        users[followerId].unfollow(followeeId);
      }

    }
private:
    unordered_map<int,User>users;
    int time=0;
    struct compare{
        bool operator()(const Tweet* l,const Tweet* r){
            return l->time<r->time;
        }
    };
};