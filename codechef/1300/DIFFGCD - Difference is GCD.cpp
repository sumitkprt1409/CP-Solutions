#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
	
	int t;
	cin>>t;
	while(t--){
	    long long n;
    	cin>>n;
    	
    	long long ans = 0;
    	
    	long long left = 1;
    	
    	while(left <= n){
    	    long long q = n/left;
    	    long long right = n/q;
    	    
    	    ans += q*(right - left + 1);
    	    
    	    left = right + 1;
    	    
    	}
    	
    	cout<<ans - n<<endl;
	}

}
