class Solution {
public:
typedef long long ll;
    long long repairCars(vector<int>& ranks, int cars) {

        /* time = ranks[i] * n^2;

         so n = sqrt(time/ranks[i]); */

        //  Applying Binarty search on time 

        // minimum time is 1 minute and maximum time is  maximum of ranks * cars* cars;  by applying Binary search we get the time whixh we call as mid value ;

        // now check in this calculated time we can fix all cars or not 
        
        ll left = 1;

        ll maxR = *max_element(begin(ranks), end(ranks));

        ll right = maxR * cars* cars;

        ll result = 0; 


        while(left<=right){

            ll mid = left+(right-left)/2;

            int repaired_cars = 0;

            for(int i = 0;i<ranks.size();i++){

                repaired_cars += sqrt(mid/ranks[i]);
            }

            if(repaired_cars>=cars){
                result = mid;
                right = mid-1; 
            }
            else{
                left = mid+1;
            }

        } 

        return result;
    }
};