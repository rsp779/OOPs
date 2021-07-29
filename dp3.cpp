#include <bits/stdc++.h>
using namespace std;

//Mininum number of coins
int solve(vector<int>v,int k)
{
    vector<int>dp(k+1,INT_MAX);
    dp[0]=0;
    for(int i=1;i<=k;i++)
    {
        for(int j=0;j<v.size();j++)
        {
            if(i>=v[j])
            {
                dp[i]=min(dp[i],dp[i-v[j]]+1);
            }
        }
    }
    return dp[k];
}
//Maximize Cut segment

int solve(vector<int>v,int k)
{
    vector<int>dp(k+1,INT_MIN);
    dp[0]=0;
    for(int i=1;i<=k;i++)
    {
        for(int j=0;j<v.size();j++)
        {
            if(i>=v[j])
            {
                dp[i]=max(dp[i],dp[i-v[j]]+1);
            }
        }
    }
    return dp[k];
}

//edit distance
int solve(string a,string b)
{
    int n1=a.size();
    int n2=b.size();
    vector<vector<int>>dp(n1+1,vector<int>(n2+1,0));
    
    
    for(int i=0;i<=n1;i++)
    {
        for(int j=0;j<=n2;j++)
        {
            if(i==0 && j==0)
            dp[i][j]=0;
            else if(i==0)
            dp[i][j]=j;
            else if(j==0)
            dp[i][j]=i;
            
            else if(a[i-1]==b[j-1])
            dp[i][j]=dp[i-1][j-1];
            
            else dp[i][j]=min(dp[i][j-1],min(dp[i-1][j],dp[i-1][j-1]))+1;
        }
    }
    return dp[n1][n2];
}

//count palindromic subsequence   //youtube pepcoding

int solve(string str,int i,int j)
{
    if(i>j)
    return 0;
    
    if(i==j)
    return 1;
    
    if(dp[i][j]!=-1)
    return dp[i][j];
    
    if(str[i]==str[j])
    dp[i][j]=solve(str,i+1,j)+solve(str,i,j-1)+1;
    
    else dp[i][j]=solve(str,i+1,j)+solve(str,i,j-1)-solve(str,i+1,j-1);

}

//longest palindromic substring

int solve(string s)
{
    int n=s.length();
    int ans=1;
    for(int i=0;i<n;i++)
    {
        int x=i-1;
        int y=i+1;
        
        while(x>0 && y<n)
        {
            if(s[x]!=s[y])
            break;
            x--;
            y++;
        }
        
        ans=max(ans,y-x-1);
        x=i;
        y=i+1;
        while(x>0 && y<n)
        {
            if(s[x]!=s[y])
            break;
        }
        ans=max(ans,y-x-1);
    }
    return ans;
}
//Mininum jumps to end of an array
int solve(vector<int>v)
{
    
    if(v[0]==0 && v.size()==1)
    return 0;
    
    if(v[0]==0)
    return -1;
    int n=v.size();
    
     vector<int>dp(n,INT_MAX);
     dp[0]=0;
    
    for(int i=0;i<n;i++)
    {
        if(dp[i]==INT_MAX)
        return -1;
        
        for(int j=i+1;j<=min(n-1,i+v[i]);j++)
        {
            dp[j]=min(dp[j],dp[i]+1);
        }
    }
    return dp[n-1];
}

//optimized code
int solve(vector<int>v)
{
    
    if(v[0]==0 && v.size()==1)
    return 0;
    
    if(v[0]==0)
    return -1;
    int n=v.size();
    
    int jumps=0;
    int maxr=0;
    int steps=0;
    
    for(int i=0;i<n;i++)
    {
        maxr=maxr(maxr,i+v[i]);
        
        if(maxr>=n-1)
        return jumps;
        
        steps--;
        
        if(steps<=0)
        {
            jumps++;
            steps=maxr-i;
            if(steps==0)
            return -1;
        }
    }
    //print longest subsequence
    string solve(string a,string b)
    {
        int n=a.size();
        int m=b.size();
        
        vector<vector<int>>dp(n+1,vector<int>(m+1,0));
        
        
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                if(a[i-1]==b[j-1])
                dp[i][j]=dp[i-1][j-1]+1;
                else dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        }
        
        int i=n,j=m;
        string ans="";
        while(i>0 && j>0)
        {
            if(a[i-1]==b[j-1])
            {
                ans.push_back(a[i-1]);
                i--;
                j--;
            }
            else if(dp[i-1][j]>dp[i][j-1])
            {
                i--;
            }
            else j--;
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
    
//print supersequence
 string solve(string a,string b)
    {
        int n=a.size();
        int m=b.size();
        
        vector<vector<int>>dp(n+1,vector<int>(m+1,0));
        
        
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                if(a[i-1]==b[j-1])
                dp[i][j]=dp[i-1][j-1]+1;
                else dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        }
        
        int i=n,j=m;
        string ans="";
        while(i>0 && j>0)
        {
            if(a[i-1]==b[j-1])
            {
                ans.push_back(a[i-1]);
                i--;
                j--;
            }
            else if(dp[i-1][j]>dp[i][j-1])
            {
                ans.push_back(a[i-1]);
                i--;
            }
            else {
                ans.push_back(b[j-1]);
                j--;
            }
        }
        
        while(i>0)
        {
        ans.push_back(a[i-1]);
        i--;
        }
        
        while(j>0)
        ans.push_back(b[--j]);
        
        reverse(ans.begin(),ans.end());
        return ans;
    }

//LCS in 3 string
int solve(string a,string b,string c)
{
    int x=a.size();
    int y=b.size();
    int z=c.size();
    
    int dp[x+1][y+1][z+1];
           
    
    for(int i=0;i<=x;i++)
    {
        for(int j=0;j<=y;j++)
        {
            for(int k=0;k<=z;k++)
            {
                
                if(i==0 || j==0 || k==0)
                {
                    dp[i][j][k]=0;    //initialization of dp
                    continue;
                }
                if(a[i-1]==b[j-1] && a[i-1]==c[k-1])
                dp[i][j][k]=dp[i-1][j-1][k-1]+1;
                
                else dp[i][j][k]=max(dp[i-1][j][k],max(dp[i][j][k-1],dp[i][j-1][k]));
            }
        }
    }
    
    return dp[x][y][z];
}


//longest common substring
int solve(string s)
{
    int n=s.size();
    vector<vector<int>>dp(n+1,vector<int>(n+1,0));
    
    int ans=0;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(s[i-1]==s[j-1])
            dp[i][j]=dp[i-1][j-1]+1;
            
            ans=max(ans,dp[i][j]);
        }
    }
    
    return ans;
}
//minimum number of deletion to make palindrom

//ans=str.size()-LPS(longest palindromic supersequence);

//for LPS reverse the string and perform LIS;

//Maximum number of ways
int solve(vector<int>v,int k)
{
    vector<vector<int>>dp(n+1,vector<int>(k+1,0));
    
    for(int i=1;i<=n;i++)
    {
        for(int j=0;j<=k;j++)
        {
            if(j==0)
            dp[i][j]=1;
            
            dp[i][j]=dp[i-1][j];
            
            if(j>=v[i-1])
            {
                dp[i][j]+=dp[i][j-v[i-1]];
            }
        }
    }
    return dp[n][k];
}

//subset problem

int solve(vector<int>v,int k)
{
    int n=v.size();
    vector<vector<bool>>dp(n+1,vector<bool>(k+1,false));
    dp[0][0]=true;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=k;j++)
        {
            dp[i][j]=dp[i-1][j];
            
            
            if(j>=v[i-1])
            dp[i][j]=dp[i][j]||dp[i-1][j-v[i-1]];
        }
    }
    return dp[n][k];
}
//Equal sum partion
int solve(vector<int>v,int k)
{
    int sum=0;
    int n=v.size();
    for(int i=0;i<n;i++)
    sum+=v[i];
    
    sum=sum/2;
    vector<vector<int>>dp(n+1,vector<int>(sum,false));
    dp[0][0]=true;
    
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=sum;j++)
        {
            if(j==0)
            dp[i][j]=true;
            
            dp[i][j]=dp[i-1][j];
            
            if(j>=v[i-1])
            dp[i][j]=dp[i][j]||dp[i-1][j-v[i-1]];
        }
    }
    return dp[n][sum];
    
}
//Minimum Subset Diff

int main() {
	// your code goes here
	return 0;
}
