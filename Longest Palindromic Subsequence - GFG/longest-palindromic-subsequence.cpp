//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
  public:
  int helper(string text1,string text2){
        int n1=text1.size();
        int n2=text2.size();
        int**ans=new int*[n1+1];
        for(int i=0;i<=n1;i++){
            ans[i]=new int[n2+1];
            for(int j=0;j<=n2;j++){
                ans[i][j]=-1;
            }
        }
        for(int i=0;i<=n2;i++){
            ans[0][i]=0;
        }
        for(int i=0;i<=n1;i++){
            ans[i][0]=0;
        }
        for(int i=1;i<=n1;i++){
            for(int j=1;j<=n2;j++){
                if(text1[n1-i]==text2[n2-j]){
                    ans[i][j]=1+ans[i-1][j-1];
                }
                else{
                    ans[i][j]=max(ans[i-1][j-1],max(ans[i-1][j],ans[i][j-1]));
                }
            }
        }
        return ans[n1][n2];
   }
    int longestPalinSubseq(string s) {
        //code here
         string s2=s;
        reverse(s2.begin(), s2.end());
        return helper(s,s2);
    }
};

//{ Driver Code Starts.

int32_t main()
{
    int t; cin >> t;
    while (t--)
    {
        string s; cin >> s;
        Solution ob;
        cout << ob.longestPalinSubseq(s) << endl;
    }
}
// Contributed By: Pranay Bansal

// } Driver Code Ends