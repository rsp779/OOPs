#include <bits/stdc++.h>
using namespace std;

//longest alternating subsequence

int solve(vector<int>v)
{
    if(v.size()==0)
    return 0;
    int n=v.size();
    vector<int>idp(n,1);
    vector<int>ddp(n,1);
    int ans=1;
    for(int i=1;i<n;i++) //1
    {
        for(int j=0;j<i;j++)
        {
            if(v[j]>v[i])  //our cur element is last elementof decreasing subsequence
            {
                ddp[i]=max(ddp[i],idp[j]+1);
            }
            else {
                idp[i]=max(idp[i],ddp[j]+1); //my current element is the last ele of an increasing subsequence
            }
            
        }
        ans=max(ans,max(idp[i],ddp[i])); //to find the max
    }
    return ans;
}
// Simple code 
int idp=1,ddp=1;
for(int i=1;i<n;i++
    {
	    if(v[i]>v[i-1])
		    idp=ddp+1;
	    else ddp=idp+1;
}
// given height of tree how many balanced bst can be formed
int solve(int n)
{
    vector<int>dp(n+1,0);
    dp[0]=0; 
    dp[1]=1;
    dp[2]=3;
    
    for(int i=3;i<=n;i++)
    {
        dp[i]=dp[i-1]*(2*dp[i-2]+dp[i-1]);
    }
    return dp[n];
}

//no of ways by which we can give coulours to n fences k coulours such that no 3 have same colour
int solve(int fences,int colour)
{
    if(fences==0)
    return 0;
    if(fences==1)
    return colour;
    
    
    int same=colour;
    int diff=same*(colour-1);
    int total=same+diff;
    
    for(int i=3;i<=fences;i++)
    {
        same=diff*1;
        diff=total*(colour-1);
        total=same+diff;
    }
    return total;
}
//Assembly line scheduling 

int solve()
{
    int x[]={} //time to 1st row 
    int y[]={} //time to 2nd row
    int u[]={} //time to travel across upward
    int d[]={} //time to travel across down
    
    int xdp[]={};
    int ydp[]={};
    xdp[0]=0;
    ydp[0]=0;
    for(int i=1;i<n;i++)
    {
        xdp[i]=min(ydp[i-1]+u[i],xdp[i-1])+x[i];
        ydp[i]=min(ydp[i-1],xdp[i-1]+d[i])+y[i];
    }
    return min(xdp[n-1]+d[n],ydp[n-1]+u[n]);
}

//minimum removals such that max-min<=k 
struct ele{
    int co;
    int val;
};
int solve(vector<int>v,int k)
{
    int n=v.size();
    priority_queue<ele,vector<ele>>pq1;  //max heap
    priority_queue<<ele,vector<ele>,greater<ele>>pq2;  //min heap
    
    unordered_map<int,int>mp;
    for(int i=0;i<n;i++)
    {
        mp[v[i]]++;
    }
    for(auto itr : mp)
    {
        ele.co=itr.second;
        ele.val=itr.first;
        pq1.push(ele);
        pq2.push(ele);
    }
    int ans=0;
    while(!pq1.empty() && !pq2.empty())
    {
        int c1=pq1.top().co;
        int c2=pq2.top().co;
        
        if(pq1.top().val-pq2.top().val<=k)
        break;
        
        if(c1>c2)
        {
            ans+=c2;
            pq2.pop();
        }
        else {
            ans+=c1;
            pq1.pop();
        }
    }
    return ans;
}

//maximum sum of pairs with specific difference 

int solve(vector<int>v)
{
    sort(v.begin(),v.end());
    int n=v.size();
    int ans=0;
    for(int i=n-1;i>0;i--)
    {
        if(v[i]-v[i-1]<k)
        {
            ans+=v[i];
            ans+=v[i-1];
            i--;
        }
    }
    return ans;
}
 // maximum subsequencesum such that no 3 are consequtive

int solve (vector<int>v)   // v[i]>0
{  
    int n=v.size();
    vector<int>dp(n,0);
    dp[0]=v[0];
    dp[1]=v[0]+v[1];
    
    dp[2]=max(dp[0]+v[2],dp[1]);
    for(int i=3;i<n;i++)
    {
        dp[i]=max(v[i]+v[i-1]+dp[i-3],max(dp[i-2]+v[i],dp[i-1]));
    }
    return dp[n-1];
}
//Interleafing string

bool solve(int i,int j,int k)
{
    if(i<0 || j<0 || k<0)
    return false;
    
    if(i==0 && j==0 && k==0)
    return true;
    
    
    
    string key=to_string(i);
    key.push("_");
    key.append(to_string(j));
    key.append("_");
    key.append(to_string(k));
    
    if(mp.find(key)!=mp.end())
    return mp[key];
    
    
    
    bool flag=false;
    if(str1[i]==str2[j] && str1[i]==str[i] )
    flag=solve(i-1,j,k-1) || solve(i,j-1,k-1);
    else if (str1[i]==str[k])
    flag=solve(i-1,j,k-1);
    else if (str2[j]==str[k])
    flag=solve(i,j-1,k-1);
    
    return mp[key]=flag;
}

bool solve(string a,string b,string c)
{
    int n1=a.size();
    int n2=b.size();
    int n3=c.size();
    if(n1+n2!=n3)
    return false;
    
    vector<vector<bool>>dp(n1+1,vector<bool>(n2+1,false));
   
    for(int i=0;i<=n1;i++)
    {
        for(int j=0;j<=n2 ; j++)
        {
            if(i==0 && j==0)
            dp[i][j]=true;
            
            else if(i==0 && b[j-1]==c[i+j-1])
            dp[i][j]=dp[i][j-1];
            
            else if(j==0 && a[i-1]==c[i+j-1])
            dp[i][j]=dp[i-1][j];
            
            else if(a[i-1]==c[i+j-1] & b[j-1]==c[i+j-1])
            dp[i][j]=(dp[i-1][j]) || (dp[i][j-1]);
            
            else if(a[i-1]==c[i+j-1])
            dp[i][j]=dp[i-1][j];
            
            else if(b[j-1]==c[i+j-1])
            dp[i][j]=(dp[i][j-1]);
            
            else dp[i][j]=false;
            
            
        }
    }
    return dp[n1][n2];
}

//No of sequence such that product is less than k
int solve(vector<int>v,int k)
{
    int n=v.size();
    vector<vector<int>>dp(n+1,vector<int>(k+1,0));
    
    dp[0][0]=1;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=k;j++)
        {
            dp[i][j]=dp[i-1][j];
            
            if(v[i-1]==j)
            dp[i][j]+=1;
            
            if( v[i-1] !=0 && j%v[i-1]==0 && dp[i-1][j/v[i-1]])
            dp[i][j]+=dp[i-1][j/v[i-1]];
            
        }
    }
    int ans=0;
    for(int i=1;i<=k;i++)
    ans+=(dp[n][i]);
    return ans;
    
}




int main() {
	// your code goes here
	return 0;
}
