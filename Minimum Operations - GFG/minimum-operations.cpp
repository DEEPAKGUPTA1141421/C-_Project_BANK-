//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
  public:
    int minOperation(int n)
    {
        //code here.
        int*ans=new int[n+1];
        ans[0]=0;
        for(int i=1;i<=n;i++){
            ans[i]=ans[i-1]+1;
            if(i%2==0){
                ans[i]=min(ans[i],ans[i/2]+1);
            }
        }
        return ans[n];
    }
};

//{ Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	    {
	        int n;
	        cin>>n;
	        Solution ob;
	        cout<<ob.minOperation(n)<<endl;
	    }
}
// } Driver Code Ends