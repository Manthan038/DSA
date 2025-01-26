
#include <bits/stdc++.h>
using namespace std;

///Longest increasing sequence

int GetLongestSequence(vector<int> &a){
    int n = a.size();
    vector<int > dp(n,1);
    int cnt = 1;
    for(int i = 0; i < n ; i++) {
        /// If question is just to retunr count 
        // then here is scope of improving the complexity 
        /// no need to store the sequence
        // just add in list and check the lower bound 
        /// add that place
        ///Then Time complexity will O(N log(N))
        // improve that below loop with lower bound
        for(int j = 0; j < i; j++){
            if(a[i] > a[j] && dp[i] < dp[j] +1) {
                dp[i] = dp[j]+1;
                cnt = max(cnt, dp[i]);
            }
        }
    }
    
    return cnt;
    
    
    ///Time complexity is O(n^2)
}


int main()
{
    vector<int> ar = {2,1,5,4,22,3,4,6,9};
    
    cout<<"Longest increasing sequence is "<<GetLongestSequence(ar);
}