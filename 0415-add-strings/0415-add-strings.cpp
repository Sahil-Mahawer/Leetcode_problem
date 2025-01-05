class Solution {
public:

    string add(string nums1, string nums2){
        
        int index1 = nums1.size()-1, index2 = nums2.size()-1;  // assuming nums1 size is greater than the nums2 size
        int carry=0, sum=0;
        string ans;

        while(index2>=0){  // means nums2 will get finish first 

        sum = (nums1[index1] - '0') + (nums2[index2] - '0')+ carry;
        carry = sum/10;
        char c = '0'+ sum%10;
        ans = ans + c;

        index1--, index2--;

        }

         while(index1>=0){  // means nums2 will get finish first 

        sum = (nums1[index1] - '0') + carry;
        carry = sum/10;
        char c = '0'+ sum%10;
        ans = ans + c;
        
        index1--, index2--;

        }
        if(carry){
            ans+='1';
        }

        reverse(ans.begin(), ans.end());
        return ans;

    }


    string addStrings(string nums1, string nums2) {

        if(nums1.size()>nums2.size()){
            return add(nums1, nums2);
        }
        else
        {
            return add(nums2, nums1);
        }
        
    }
};