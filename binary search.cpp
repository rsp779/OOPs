#include <iostream>
using namespace std;

//bionic array

int Solution::solve(vector<int> &a, int B) {
    
    int peak=-1;
    int low=0;
    int high=a.size()-1;
    
    while(low<=high)
    {
        int mid=high+(low-high)/2;
        
        if(a[mid]>a[mid+1] && a[mid]>a[mid-1])
        
        {
            peak=mid;
            break;
        }
        
        if(a[mid]>a[mid+1] && a[mid]<a[mid-1])
        high=mid-1;
        else if(a[mid]<a[mid+1] && a[mid]>a[mid-1])
        low=mid+1;
        
    }
    
    if(a[peak]==B)
    return peak;
    
    
    low=0;
    high=peak-1;
    while(low<=high)
    {
        int mid=high+(low-high)/2;
        
        if(a[mid]==B)
        return mid;
        
        if(a[mid]>B)
        high=mid-1;
        else low=mid+1;
    }
    low=peak+1;
    high=a.size()-1;
    
    while(low<=high)
    {
        int mid=low+(high-low)/2;
        
        if(a[mid]==B)
        return mid;
        
        if(a[mid]>B)
        low=mid+1;
        else high=mid-1;
    }
    return -1;
}

//wood cutting
int check(vector<int>&A,int mid)
{
    int wood=0;
    for(int i=0;i<A.size();i++)
    {
        if(A[i]>=mid)
        wood+=A[i]-mid;
    }
    return wood;
}
int Solution::solve(vector<int> &A, int B) {
    int low=0;
    int high=1e9;
    int ans=0;
   for(int i=0;i<40;i++)// while(low<=high)
    {
        int mid=high+(low-high)/2;
        
        int quan=check(A,mid);
        if(quan==B)
        return mid;
        
        if(quan>B)
        {
            ans=mid;
            low=mid+1;
        }
        else high=mid-1;
    }
    return ans;
}

// matrix search

bool search(vector<vector<int>>v,int B)
{
    int n=v.size();
    int m=v[0].size();
    
    long long int l=0;
    long long int int h=n*m-1;
    
    while(l<=h)
    {
        long long int mid=(l)+(h-l)/2;
        
        long long int x=mid/m;
        long long int y=mid%m;
        
        if(A[x][y]==B)
        return true;
        
        if(A[x][y]>B)
        {
            h=mid-1;
        }
        else l=mid+1;
    }
    return false;
}

//number of eleements samaler or equal to B 
int Solution::solve(vector<int> &A, int B) {
    if(A[A.size()-1]<=B)return A.size();
    int low=0;
    int high=A.size()-1;
    int ans=0;
    while(low<=high)
    {
        int mid=(low+high)/2;
        if(A[mid]>B)
        {
            ans=mid;
            high=mid-1;
        }
        else {
            low=mid+1;
        }
    }
    
    return ans;
}

//first and last occurence of element B 
vector<int> Solution::searchRange(const vector<int> &A, int B) {
    
    int first=-1;
    int low=0;
    int high=A.size()-1;
    while(low<=high)
    {
        int mid=high+(low-high)/2;
        
        if(A[mid]>=B)
        {
            first=mid;
            high=mid-1;
        }
        else low=mid+1;
    }
    vector<int>ans;
    if(A[first]!=B)
    {
        ans.push_back(-1);
        ans.push_back(-1);
        return ans;
    }
    ans.push_back(first);
    int last=first;
    
     low=0;
     high=A.size()-1;
    while(low<=high)
    {
        int mid=high+(low-high)/2;
        
        if(A[mid]<=B)
        {
            last=mid;
            low=mid+1;
        }
        else high=mid-1;
    }
    ans.push_back(last);
    return ans;
  
}
//median of 2d sorted array
int solve(vector<vector<int>>v)
{
    int l=INT_MAX;
    int h=INT_MIN;
    int n=v.size();
    int m=v[0].size();
    for(int i=0;i<v.size();i++)
    {
        l=min(l,v[i][0]);
        h=min(h,v[i][m-1]);
    }
    
    int req=(n*m+1)/2;
    int ans=-1;
    while(l<=h)
    {
        int mid=h+(l-h)/2;
        int count=0;
        
        for(int i=0;i<n;i++)
        count+=upper_bound(v[i].begin(),v[i].end(),mid)-v[i].begin();
        
        if(count>=req)
        {
            ans=mid;
            h=mid-1;
        }
        else l=mid+1;
    }
    return ans;
}

//book allocation




bool check(vector<int>v,int s,int page)
{
    int x=1;
    int p=0;
    
    for(int i=0;i<v.size();i++)
    {
        p+=v[i];
        
        if(p>page)
        {
            x++;
            p=v[i];
        }
        if(x>s)
        return false;
    }
    return true;
}

int solve(vector<int>book,int s)
{
    int l=INT_MIN;
    int h=0;
    
    for(int i=0;i<book.size();i++)
    {
        l=max(l,book[i]);    
        h+=book[i];
    }
    int ans=0;
    while(l<=h)
    {
        
        int mid=l+(h-l)/2;
        
        if(check(v,s,mid))
        {
            ans=mid;
            r=mid-1;
        }
        
        else l=mid+1;
    }
    return ans;
}

//painter partion

bool check(vector<int>v,int p,int b)
{
    int pa=1;
    int sum=0;
    
    for(int i=0;i<v.size();i++)
    {
        sum+=v[i];
        if(sum>b)
        {
            pa++;
            sum=v[i];
        }
        if(pa>p)
        return false;
    }
    return true;
}

long long int solve(int painter,int time,vector<int>v)
{
    int l=INT_MIN;
    int h=0;
    
    for(int i=0;i<v.size();i++)
    {
        l=max(l,v[i]);
        h+=v[i];
    }
    long long int ans=-1;
    
    
    while(l<=h)
    {
        long long int mid=l+(h-l)/2;
        
        if(check(v,painter,mid))
        {
            ans=mid;
            h=mid-1;
        }
        else l=mid+1;
    }
    return (ans*B);
}

//Aggresive Cows


#include <bits/stdc++.h>
using namespace std;

int main() {
    
    int t;
    cin>>t;
    
    while(t--)
    {
        int n,c;
        cin>>n>>c;
        
        int arr[n];
        
        for(int i=0;i<n;i++)
        cin>>arr[i];
        
        sort(arr,arr+n);
        
        int h=arr[n-1]-arr[0];
        int l=0;
        int dis=-1;
        while(l<=h)
        {
            int mid=l+(h-l)/2;
            
            int count=1;
            int p=arr[0];
            for(int i=1;i<n;i++)
            {
                if(arr[i]-p>=mid)
                {
                    count++;
                    p=arr[i];
                }
            }
            
            if(count>=c)
            {
                dis=mid;
                l=mid+1;
            }
            else h=mid-1;
        }
        
        cout<<dis<<endl;
    }
    
	return 0;
}


//Rotated Sorted array
int Solution::search(const vector<int> &A, int B) {
    if(B==A[0])
    return 0;
    int low=0;
    int high=A.size()-1;
    for(int i=0;i<40;i++)
    {
        int mid=low+(high-low)/2;
        
        if(A[mid]==B)
        return mid;
        
       if(B>A[0])
       {
           if(A[mid]>A[0])
           {
               if(A[mid]>B)
               high=mid-1;
               else low=mid+1;
           }
           else high=mid-1;
       }
      else {
          if(A[mid]>A[0])
          low=mid+1;
          else {
              if(A[mid]>B)
              high=mid-1;
              else low=mid+1;
          }
      }
    }
    return -1;
}

//Median of 2 sorted arrays

double solve(vector<int>A,vector<int>B)
{
    int n=A.size();
    int m=B.size();
    
    int k=(m+n+1)/2;
    
    int l=0;
    int h=n-1;
    
    while(l<=h)
    {
        int mid=l+(h-l)/2;
        int y=k-mid;
        int a=(mid==0)?INT_MIN:A[mid-1];
        int b=(mid==n)?INT_MAX:A[mid];
        int c=(y==0)?INT_MIN:B[y-1];
        int d=(y==m)?INT_MAX:B[y];
        
        if(a<d && c<b)
        {
            if((n+m)%2==0)
            {
                return (max(a,c)+min(b,d))/2.0;
            }
            else return max(a,c)*1.0;
        }
        if(a>d)
        h=mid-1;
        else l=mid+1;
    }
    return 0;
}

//Implement Power Function 
int Solution::pow(int x, int n, int d) {
    
    if(x==0)
    {
        return 1%d;
    }
    long long int a=1;
    long long int base=x;
    
    while(n>0)
    {
        if(n%2==0)
        {
            base=((base)*(base))%d;
            n=n/2;
        }
        else {
            a=((a)*(base))%d;
            n-=1;
        }
    }
    
    if(a<0)
    return (a+d)%d;

    return a;
}
int main() {
	// your code goes here
	return 0;
}
