//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
		

	public:
	int helper(string s1,int n1,string s2,int n2,int**ans){
	    if(n1==0&&n2==0){
	        return 0;
	    }
	    if(n1==0&&n2!=0){
	        return n2;
	    }
	    if(n1!=0&&n2==0){
	        return n1;
	    }
	    if(ans[n1][n2]!=-1){
	        return ans[n1][n2];
	    }
	    if(s1[0]==s2[0]){
	        ans[n1][n2]= helper(s1.substr(1),n1-1,s2.substr(1),n2-1,ans);
	        return ans[n1][n2];
	    }
	    else{
	        int a=helper(s1,n1,s2.substr(1),n2-1,ans)+1;
	        int b=helper(s1.substr(1),n1-1,s2,n2,ans)+1;
	        ans[n1][n2]= min(a,b);
	        return ans[n1][n2];
	    }
	}
	int minOperations(string str1, string str2) 
	{ 
	    // Your code goes here
	    int n1=str1.length();
	    int n2=str2.length();
	    int**ans=new int*[n1+1];
        for(int i=0;i<=n1;i++){
            ans[i]=new int[n2+1];
            for(int j=0;j<=n2;j++){
                ans[i][j]=-1;
            }
        }
	    return helper(str1,n1,str2,n2,ans);
	    
	} 
};

//{ Driver Code Starts.
int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        string s1, s2;
        cin >> s1 >> s2;

	    Solution ob;
	    cout << ob.minOperations(s1, s2) << "\n";
	     
    }
    return 0;
}


// } Driver Code Ends