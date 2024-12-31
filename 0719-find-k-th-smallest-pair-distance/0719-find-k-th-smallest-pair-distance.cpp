class Solution {
public:
    int smallestDistancePair(vector<int>& nums, int k) {
        
        vector<int> distance;

        for(int i=0;i<nums.size();i++){
            for(int j=i+1;j<nums.size();j++){

                int distances = abs(nums[i]-nums[j]);

                distance.push_back(distances);
            }
        }

        sort(distance.begin(), distance.end());

        return distance[k-1];
    }
};