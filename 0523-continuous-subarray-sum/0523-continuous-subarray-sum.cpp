// class Solution {
// public:
//     bool checkSubarraySum(vector<int>& nums, int k) {
//         int n = nums.size();
// //         if(n<2){
// //             return 0;
// //         }
// //         for(int i=0;i<n;i++){
// //             int sum=0;
// //             for(int j=i;j<n;j++){

// //                 sum = sum+nums[j];

                
// //                 if(sum%k==0)
// //                 return 1;
                
// //             }
// //         }

// //         return 0;
// //     }
// // };

// for (int i = 0; i < n; i++) {
//     int sum = 0;
//     for (int j = i; j < n; j++) {
//         sum += nums[j];

//         // Ensure subarray length is at least 2
//         if (j - i + 1 >= 2 && sum % k == 0) {
//             return true;
//         }
//     }
// }
// return false;

//      }
//  };

class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> remainderMap; // To store (remainder, index)
        remainderMap[0] = -1; // Initialize for the case where sum is already a multiple of k

        int sum = 0;

        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];

            // Compute remainder
            int remainder = sum % k;
            if (remainder < 0) remainder += k; // Handle negative remainders

            // Check if this remainder was seen before
            if (remainderMap.find(remainder) != remainderMap.end()) {
                // Ensure subarray length is at least 2
                if (i - remainderMap[remainder] > 1) {
                    return true;
                }
            } else {
                // Store remainder and index
                remainderMap[remainder] = i;
            }
        }
        return false;
    }
};

