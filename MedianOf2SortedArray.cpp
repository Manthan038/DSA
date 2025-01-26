

#include<bits/stdc++.h>
using namespace std;


double getMedian(vector<int> &a, vector<int>& b){
    int n1 = a.size();
    int n2 = b.size();
    
    int high = n1;
    int low = 0;
    int total = (n1 + n2 + 1 )/2;
    while(low <= high){
        int mid1 = (high + low)/2;
        int mid2 = total - mid1;
        int l1 = INT_MIN, l2 = INT_MIN;
        int r1 = INT_MAX, r2 = INT_MAX;
        
        if (mid1 > 0 ) l1 = a[mid1-1];
        if(mid2 > 0 ) l2 = b[mid2-1];
        if(mid1 < n1) r1 = a[mid1];
        if(mid2 < n2) r2 = b[mid2];
        
        if(l1 <= r2 && l2 <= r1) {
            //case for even and odd
            if((n1+n2)%2 == 0) {
               
                return (double)(max(l1,l2) + min(r1,r2) )/2.0;
            } else {
                return max(l1,l2);
            }
        }
        
        if(l1 > r2) high = mid1-1;
        else low = mid1+1;
        
    }
    
    return 0.0;
}

int main() {
    vector<int> a = {2,4,5,9};
    vector<int> b = { 1,3,7,8,10};
    
   
    // 1 2 3 4 5 --- 6. ---- 7 8 9 10 11
     double med = getMedian(a, b);
    
     cout<<"median of data is "<<med<<"\n";
}