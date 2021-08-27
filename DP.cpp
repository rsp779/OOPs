last seen => 27/8/2021
#include <bits/stdc++.h>
using namespace std;

int solve(int eggs,int floors) //egg dropping
{
    
     if(eggs==1)
     return floors;
    
    if(floors==0 || floors==1)
    return floors;
    
  
    if(dp[eggs][floors]!=-1)
    return dp[eggs][floors];
    
    int ans=1e9;
    for(int k=1;k<floors;k++)
    {
        int temp=1+max(solve(eggs-1,k-1),solve(eggs,floors-k));
        ans=min(ans,temp);
    }
    return dp[eggs][floors]=ans;
}
 //MCM ~ Matrix chain multiplication
 
 int solve(int arr[],int i,int j)
 {
     if(i>=j)
     return 0;
     
     if(dp[i][j]!=-1)
     return dp[i][j];
     int ans=0;
     for(int k=i+1;k<j;k++)
     {
         int temp=solve(arr,i,k)+solve(arr,k+1,j)+(arr[i]*arr[k]*arr[j]);
         ans=max(ans,temp);
     }
     return dp[i][j]=ans;
     
 }
 
 //palidrome Partioning
 bool ispalindrome(string str)
 {
     int n=str.size();
     for(int i=0;i<n/2;i++)
     if(str[i]!=str[n-i-1])
     return false;
     
     return true;
 }
 int solve(string str,int i,int j)
 {
     if(i==j)
     return 1;
     if(i>j)
     return 0;
     
     
     if(ispalindrome(str.substr(i,j-i)))
     return 0;
     
     if(dp[i][j]!=-1)
     return dp[i][j];
     
     int ans=1e9;
     for(int k=i+1;k<j;k++)
     {
    
         int temp=1+solve(str,i,k)+solve(str,k+1,j);
         ans=min(ans,temp);
         
     }
     return dp[i][j]=ans;
     
 }
 
// largest rectangle in a 2D Matrix

int solve(vector<int>v)
{
    //find the largest rectangle in histogram
    int n=v.size();
    vector<int>left(n,-1);
    stack<int>s;
    
    for(int i=0;i<n;i++)
    {
        if(s.empty())
        lef[i]=-1;
        else {
            while(!s.empty() && v[s.top()]<v[i]) 
            s.pop();
            
            if(s.empty())
            lef[i]=-1;
            else lef[i]=s.top();
        }
        s.push(i);
    }
    
    int temp=0;
    
    for(int i=n-1;i>=0;i--)
    {
        int right=n;
        if(s.empty())
        right=n;
        else {
            while(!s.empty() && v[s.top()]<v[i])
            s.pop();
            
            if(s.empty())
            right=n;
            else right=s.top();
        }
        temp=max(temp,v[i]*(right-left[i]+1));
        s.push(i);
    }
    return temp;
}

int check(vector<vector<int>>v)
{
    vector<vector<int>>dp(n,vector<int>(m,0));
    
    for(int j=0;j<m;j++)dp[0][j]=v[0][j];
    
    for(int i=1;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(v[i][j]==0)
            continue;
            
            dp[i][j]+=dp[i-1][j];
        }
    }
    
    int ans=0;
    
    for(int i=0;i<n;i++)
    {
        ans=max(ans,solve(dp[i]));
    }
    
    return ans;
    
}

//maximum sum sub Matrix
int kadane(vector<int>sum)
{
    int n=sum.size();
    int temp=sum[0];
    int ans=temp;
    for(int i=1;i<n;i++)
    {
        temp+=sum[i];
        ans=max(ans,temp);
        if(temp<0)
        temp=0;
    }
    return ans;
}
int solve(vector<vector<int>>v)
{
    int ans=-1e9;
    int n=v.size();
    int m=v[0].size();
   
    for(int j=0;j<m;j++) //column
    {
         vector<int>sum(n,0);
        for(int lef=j;lef<m;lef++)
        {
            for(int i=0;i<n;i++)
            sum[i]+=v[i][lef];
            
            ans=max(ans,kadane(sum));
        }
    }
    return ans;
}

//rainwater problem
int solve(vector<int>height)
{
    
         if(height.size()<3)
             return 0;
        int i=1,j=height.size()-2;
        int lmax=height[0],rmax=height[j+1];
           int ans=0;
        while(i<=j)
        {
            if(lmax<=rmax)
            {
                ans+=max(0,lmax-height[i]);
                lmax=max(lmax,height[i]);
                i++;
            }
            else {
                ans+=max(0,rmax-height[j]);
                rmax=max(rmax,height[j]);
                j--;
            }
        }
        return ans;
}

//largest submatrix with equal zero and 1
int sum0(vector<int>v)
{
    unordered_map<int ,vector<int>>mp;
    mp[0].push_back(-1);
    int sum=0;
    for(int i=0;i<n;i++)
    {
        sum+=v[i];
        mp[sum].push_back(i);
    }
    int temp=0;
    for(auto itr : mp)
    {
        vector<int>x=itr.second;
        if(x.size()>1)
        {
            temp=max(temp,x[x.size()-1]-x[0]);
        }
    }
    return temp;
}
int solve(vector<vector<int>>mat)
{
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(mat[i][j]==0)
            mat[i][j]=-1;
        }
    }
    
    int ans=0;
    for(int j=0;j<m;j++)
    {
        vector<int>sum(n,0);
        for(int lef=j;lef<m;lef++)
        {
            for(int i=0;i<n;i++)
            sum[i]+=mat[i][lef];
            
            ans=max(ans,(lef-j+1)*max0(sum));
        }
    }
  return ans;
}
// largest square of 1 in 0-1 matrix

int solve(vector<vector<int>>v)
{
    int n=v.size();
    int m=v[0].size();
    int ans=0;
    
    for(int i=n-1;i>=0;i--)ans=max(ans,v[i][m-1]);
    for(int j=m-1;j>=0;j--)ans=max(ans,b[n-1][j]);
    
    for(int i=n-2;i>=0;i--)
    {
        for(int j=m-2;j>=0;j--)
        {
            if(v[i][j]==0)
            continue;
            
            v[i][j]=min(v[i+1][j],min(v[i][j+1],v[i+1][j+1]))+1;
            ans=max(ans,v[i][j]);
        }
    }
    return ans;
}

//optimal Stratergy game

int solve(vector<int>v)
{
    int n=v.size();
    vector<vector<int>>dp(n,vector<int>(n,0));
    
    for(int i=0;i<n;i++)dp[i][i]=v[i]; //when u have only one coin
    
    
    int oj=1;
    while(oj<n)
    {
        int i=0,j=oj;
        oj++;
        while(j<n)
        {
            dp[i][j]=max(v[i]+min(dp[i+1][j-1],dp[i+2][j]),v[j]+min(dp[i+1][j-1],dp[i][j-2]));
            i++;
            j++;
        }
    }
    return dp[0][n-1];
}

//buy sell stock atmax 1 transaction

int solve(vector<int>v)
{
    int ans=0;
    int cur=v[0];
    for(int i=1;i<n;i++)
    {
        
        ans=max(ans,v[i]-cur);
        
        cur=min(cur,v[i]);
    }
    return ans;
}

//buy and sell stock with infinite transaction

int solve(vector<int>v)
{
    int ans=0;
    int buy=v[0];
    int sell=v[0];
    for(int i=1;i<n;i++)
    {
        sell=max(sell,v[i]);
        if(v[i]<sell)
        {
            ans+=sell-buy;
            sell=v[i];
            buy=v[i];
        }
    }
    return ans;
}

//buy sell stock atmost 2 transaction

int solve(vector<int>v)
{
    int n=v.size();
    vector<int>dp(n,0);
    int mn=v[0];
    for(int i=1;i<n;i++)
    {
        dp[i]=max(0,v[i]-mn);
        mn=min(mn,v[i]);
    }
    int ans=dp[n-1];
    int mx=v[n-1];
    for(int i=n-2;i>=0;i--)
    {
         mx=max(mx,v[i]);
        ans=max(ans,dp[i]+mx-v[i]));
       
    }
    return ans;
}


//buy and sell at most B transaction

int solve(vector<int>v,int k)    //brute force
{
    int n=v.size();
    vector<vector<int>>dp(k+1,vector<int>(n,0));
    
    
    for(int i=1;i<=k;i++)          
    {
        for(int j=0;j<n;j++)
        {
            if(j==0)
            continue;
            
            int val=dp[i][j-1];
            for(int k=0;k<j;k++)
            {
                val=max(val,dp[i-1][k]+v[j]-v[k]);    dp[i-1][k]-v[k]  + v[j]
            }
            dp[i][j]=val;
        }
    }
    
    return dp[k][n-1];
    
    
}
//optimize

int solve(vector<int>v,int k)    //brute force
{
    
    if(k>v.size()/2)
    {
        //infinte transaction
    }
    int n=v.size();
    vector<vector<int>>dp(k+1,vector<int>(n,0));
    
    
    for(int i=1;i<=k;i++)          
    {
        int val=dp[i-1][0];
        for(int j=0;j<n;j++)
        {
            if(j==0)
            continue;
            
            val=max(val,dp[i-1][j-1]-v[j-1]);
            dp[i][j]=max(dp[i][j-1],val+v[j]);
        }
    }
    return dp[k][n-1];
}

//stocks with transaction fee


int main() {
	
	
	  
	
		return 0;
}
