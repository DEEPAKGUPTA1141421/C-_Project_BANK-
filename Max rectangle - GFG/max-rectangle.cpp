//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
#define MAX 1000


// } Driver Code Ends
/*You are required to complete this method*/

// class Solution{
//   public:
//     vector<int> nextSmallerElement(vector<int> &heights, int n){
//         vector<int> next(n);
//         stack<int> st;
//         st.push(-1);
//         for(int i = n-1; i>=0; i--){
//             while(st.top() != -1 && heights[st.top()] >= heights[i])
//             {
//                 st.pop();
//             }
//             next[i] = st.top();
//             st.push(i);
//         }
//         return next;
//     }

//     vector<int> prevSmallerElement(vector<int> &heights, int n){
//         vector<int> prev(n);
//         stack<int> st;
//         st.push(-1);
//         for(int i = 0; i < n; i++){
//             while(st.top() != -1 && heights[st.top()] >= heights[i]){
//                 st.pop();
//             }
//             prev[i] = st.top();
//             st.push(i);
//         }
//         return prev;
//     }

//     int largestRectangleArea(vector<int>& heights) {
//         int n = heights.size();
//         vector<int> next(n);
//         vector<int> prev(n);
//         next = nextSmallerElement(heights, n);
//         prev = prevSmallerElement(heights, n);
//         int area = INT_MIN;
//         for(int i = 0; i < n; i++){
//             int l = heights[i];
//             if(next[i] == -1)
//             next[i] = n;
//             int b = next[i] - prev[i] - 1;
//             int newarea = l*b;
//             area = max(area, newarea);
//         }
//         return area;
//     }
//     int maxArea(int M[MAX][MAX], int n, int m) {
//         // Your code here
//         vector<int>heights(n,0);
//         int ans=INT_MIN;
//         for(int i=0;i<n;i++){
//             for(int j=0;j<m;j++){
//                 if(M[i][j]==1){
//                  heights[j]+=1;
//               }
//               else{
//                   heights[j]=0;
//               }
//             }
//             ans=max(ans,largestRectangleArea(heights));
//         }
//         return ans;
//     }
// };
class Solution{
    
    private:
    vector<int> prevsmelement(vector<int> &ans ,int n){
        stack<int> s;
        s.push(-1);
        vector<int> arr(n);
        
        for(int i = 0 ;i<n ;i++){
            int curr = ans[i];
            while(s.top()!= -1 && ans[s.top()]>= curr){
                s.pop();
            }
            
            arr[i] = s.top();
            s.push(i);
        }
        return arr;
    }
    
    
    vector<int> nextsmelement(vector<int> &ans ,int n){
        stack<int> s;
        s.push(-1);
        vector<int> arr(n);

        
        for(int i = n-1 ; i>= 0 ; i--){
            int curr = ans[i];
            while(s.top()!= -1 && ans[s.top()]>= curr){
                s.pop();
            }
            
            arr[i] = s.top();
            s.push(i);
        }
        return arr;
    }
    
    
    
    int histogram(vector<int> &ans , int n ){
        vector<int> next = nextsmelement(ans , n);
        vector<int> prev = prevsmelement(ans , n);
        int area = INT_MIN;
        
        for(int i = 0; i<n ; i++){
            int l = ans[i];
            
            if(next[i] == -1)
            next[i] = n;
            
            int b = next[i] - prev[i] - 1;
            
            int newarea = l*b;
            area = max(newarea , area);
            
        }
        
        return area;
    }
    
  public:
    int maxArea(int M[MAX][MAX], int n, int m) {
        // Your code here
        vector<int> ans(m , 0);
        int maxi = INT_MIN;
        
        for(int i = 0 ; i<n ; i++){
        for(int j = 0 ; j<m ; j++)
            if(M[i][j] == 1)
            ans[j]++;
            else ans[j] = 0;
            
            maxi = max(maxi , histogram(ans , m));
            
        }
        
        return maxi;
    }
};


//{ Driver Code Starts.
int main() {
    int T;
    cin >> T;

    int M[MAX][MAX];

    while (T--) {
        int n, m;
        cin >> n >> m;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> M[i][j];
            }
        }
        Solution obj;
        cout << obj.maxArea(M, n, m) << endl;
    }
}

// } Driver Code Ends