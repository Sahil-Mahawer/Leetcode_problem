class Solution {
public:


 void mergesort(vector<int>& nums , int start, int end){

    if(start==end){
        return;
    }
    int mid = start+(end-start)/2;

    //left side
    mergesort(nums, start , mid);

    // right side
    mergesort(nums, mid+1, end);

    merge(nums, start, mid , end);

 }
 void  merge(vector<int>& nums, int start, int mid, int end){

    vector<int> temp(end-start+1);

    int left = start, right = mid+1, index=0;

    while(left<=mid && right<=end){

    if(nums[left]<=nums[right]){
        temp[index] = nums[left];
        index++;
        left++;
    }

     else  //(nums[right]<=nums[left])
     {
        temp[index] = nums[right];
      
        index++;
        right++;
    }
}

    while(left<=mid){      // agrr left mai koii element bcha hai 
        temp[index] = nums[left];
        index++;
        left++;
    }

    while(right<=end){      // agrr right mai koii element bcha hai 
        temp[index] = nums[right];
        index++;
        right++;
    }

    index=0;
    while(start<=end){
        nums[start] = temp[index];
        index++;
        start++;
    }


  }

    vector<int> sortArray(vector<int>& nums) {
       
        int n = nums.size();
        int start = 0;
        int end = nums.size()-1;

        mergesort(nums,start,end);

        return nums;
    }
};