class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        
    //    deque<int> dq;

    //    vector<int> result;

    //    int n = nums.size();

    //    for(int i=0;i<n;i++){

    //     while(!dq.empty() && dq.front() <= i-k){  // window size cant be greater than k  
    //         dq.pop_front();
    //     }

    //     while(!dq.empty() && nums[i] > nums[dq.back()]){
    //         dq.pop_back();
    //     }

    //     dq.push_back(i);

    //     if(i>=(k-1)){
    //         result.push_back(nums[dq.front()]);
    //     }

    //    }


    //    return result;


    deque<int> d;

    vector<int> ans;

    int n = nums.size();

    for(int i=0;i<k-1;i++){

        if(d.empty()){
            d.push_back(i);
        }
        else{

            while(!d.empty() && nums[i] > nums[d.back()]){

                d.pop_back();

            }
            d.push_back(i);
        }
    }


    for(int i = k-1; i<n; i++){

        while(!d.empty() && nums[i] > nums[d.back()]){
            d.pop_back();
        }

        d.push_back(i);

        while(d.front() <= i-k){  // check if element is in window size . if not then remove the element from start 
            d.pop_front();
        }

        ans.push_back(nums[d.front()]);
    }
        
        return ans;
    }
};