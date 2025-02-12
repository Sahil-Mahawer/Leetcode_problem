class Solution {
public:

void parenth(int n, int left , int right, vector<string> &ans, string &temp)
{
    // base condition 
    if(left ==n && right == n){
        ans.push_back(temp);
        return;
    }
    // include left
    if(left<n){
        temp.push_back('(');
        parenth(n , left+1, right,ans, temp);
        temp.pop_back();
    
    }

    // include right
    if(right < left){  // right parenthesis left se bda hua toh add nhi krenge .. kyuki tbb shii format mai parethesis genreate nhi honge
        temp.push_back(')');
        parenth(n , left, right+1,ans, temp);
        temp.pop_back();
    }

}

    vector<string> generateParenthesis(int n) {
        
        vector<string> ans;
        string temp;
        parenth(n, 0 ,0, ans , temp);

        return ans;
    }
};