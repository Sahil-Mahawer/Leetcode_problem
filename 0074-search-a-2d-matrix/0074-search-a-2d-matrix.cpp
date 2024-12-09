class Solution {
public:
    bool searchMatrix(vector<vector<int>>& arr, int target) {
        int row = arr.size();
        int col = arr[0].size();

        int start = 0;
        int end = (row*col)-1;
        int mid;
        // int mid = start +(end-start)/2;

        while(start<=end){

             mid = start+(end-start)/2;

             int element = arr[mid/col][mid%col];

             if(element == target)
             return 1;

             else if(element>target)
             end = mid-1;

             else
             start = mid+1;
        }
        return 0;
    }
};