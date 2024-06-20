class Solution {
public:
    bool canRepairAllCars(vector<int>&ranks,int cars,long long time){

         long long totalCars=0;

         for(int rank:ranks){

            long long maxCars=(long long)sqrt(time/rank); // Number of cars this mechaninc can repair

            totalCars+=maxCars;

            if(totalCars>=cars)
            {
                return true;
            }

         }

         return false;



    }


    long long repairCars(vector<int>& ranks, int cars) {

     int n=ranks.size();

     int min_rank=*min_element(ranks.begin(),ranks.end());

     long long left=0;

     long long right=(long long)min_rank*cars*cars; // Upper bound for binary search

     long long answer=right;

     while(left<=right)
     {

         long long mid=(left+right)/2;

         if(canRepairAllCars(ranks,cars,mid)){
            answer=mid;
            right=mid-1;
         }
         else
         {
            left=mid+1;
         }

     }



      return answer;

    }
};