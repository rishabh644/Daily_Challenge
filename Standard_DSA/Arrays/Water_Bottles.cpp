// There are numBottles water bottles
// that are initially full of water.
// You can exchange numExchange
// empty water bottles from the market with one full water bottle.

// The operation of drinking a full water bottle
// turns it into an empty bottle.

// Given the two integers numBottles and numExchange, return the maximum number of water
// bottles you can drink.

int numWaterBottles(int numBottles, int numExchange) {

       int ans=0;
       int emptybtl=0;
        while(numBottles>0)
        {
           ans+=(numBottles);

           emptybtl+=numBottles;

           numBottles=emptybtl/numExchange;

           emptybtl=emptybtl%numExchange;


        }

        return ans;

    }

//////////////////------------------/////////////

    int numWaterBottles(int numBottles, int numExchange) {



        int ans=numBottles+(numBottles-1)/(numExchange-1);

        return ans;

    }