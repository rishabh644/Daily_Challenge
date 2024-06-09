class Twitter:
    def __init__(self):
        self.user_tweets = {}  # Maps userId to a list of (timestamp, tweetId)
        self.following = {}  # Maps userId to a set of followeeIds
        self.timestamp = 0  # Global timestamp to order tweets

    def postTweet(self, userId, tweetId):
        # Initialize user_tweets for user if it does not exist
        if userId not in self.user_tweets:
            self.user_tweets[userId] = []
        # Append the new tweet with a timestamp
        self.user_tweets[userId].append((self.timestamp, tweetId))
        # Increment the timestamp for the next tweet
        self.timestamp += 1

    def getNewsFeed(self, userId):
        # Get the user's own tweets
        tweets = self.user_tweets.get(userId, []).copy()

        # Get tweets from each followee
        if userId in self.following:
            for followeeId in self.following[userId]:
                if followeeId in self.user_tweets:
                    tweets.extend(self.user_tweets[followeeId])

        # Sort tweets by timestamp in descending order
        tweets.sort(key=lambda x: x[0], reverse=True)

        # Return the tweetIds of the top 10 tweets
        return [tweetId for _, tweetId in tweets[:10]]

    def follow(self, followerId, followeeId):
        # Initialize following set for the follower if it does not exist
        if followerId not in self.following:
            self.following[followerId] = set()
        # Add the followeeId to the follower's following set
        self.following[followerId].add(followeeId)

    def unfollow(self, followerId, followeeId):
        # Check if the follower is following anyone
        if followerId in self.following:
            # Remove the followeeId from the follower's following set
            self.following[followerId].discard(followeeId)