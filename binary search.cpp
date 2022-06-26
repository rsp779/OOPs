#include <iostream>
using namespace std;

// bitonic array => first increasing and then decreasing 
// => find the peak and break the array in two halves first part is increasing and other part is decreasing
// => then separately find the element in both the halves

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
// if if we get more than the required amount of wood we have to increase the height of blade so we move low to mid+1 and view verse
int wood_quantity(vector<int>&A,int mid)
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
    int low=0,high=A[0];
	
    for(int i=0;i<A.size();i++)
	    high=max(high,A[i]);
	
    int ans=0;
    while(low<=high)  //for(int i=0;i<40;i++)
    {
        int mid=high+(low-high)/2;
        
        int quan=wood_quantity(A,mid);
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

// matrix search => elements of the matrix is sorted row wise and the last element of the each row is greater than first element 
// in the next row . so we can basically have one binary search to fina out the possible row and do another binary search in that row to find out 
// that whether or not element is present in that particular row

// solution 2  : think of the sorted matrix as a single sorted array and "cell" reperesenting the element number in that array 
// => cell = (row * number of element in one row) + (pth element of the column) 
// cell/(number of element in one row) = row number
// cell%(number of element in one row) = column number

bool search(vector<vector<int>>v,int B)
{
    int n=v.size();
    int m=v[0].size();
    
    long long int l=0;
    long long int int h=n*m-1;  // total number of elemnets
    
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

//number of eleements smaller or equal to B 

// we have to find the first number that is greater than B and return that index
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
// for first occurence if we get a number that is greater or equal to B then we will store that index and move leftward by low=mid-1;
// for last occurence of element if we get the smaller or equal number we will store in ans and move rightwards


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
// traverse between lowest element = A[0][0] and highest element = A[n-1][m-1] 
// and find the count of elements that are smaller than or equal to that element and if this count >= req we can store it
// here req = (n*m + 1)/2
int count calculate(vector<int>&arr , int ele){
	int n=arr.size();
	int low=0,high=n-1;
	int ans=arr.size();
	while(low<=high){
		int mid =low + (high-low)/2;
		
		if(A[mid]<=ele){
			ans=mid;
			low=mid+1;
		}
		else high=mid-1;
	}	
	return ans;
}	

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
        count+=calculate_smaller_elements(v[i],mid);
        
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
            int sum=0;
            for(int i=1;i<n;i++)
            {
		    sum+=arr[i];
                if(sum>=mid)
                {
                    count++;
                    sum=arr[i];
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
// Solution 1 : linear search 
// Solution 2 : find the index or pivot point from and form two sorted array and separately do binary search of elements in the two array
// solution 3 : Ultra pro max solution is to divide the array initially into two sections based on value of B and arr[0] 
//              then locate mid with the help of arr[0] and arr[mid]
// 		then compare arr[mid] with B

//		if(B>arr[0]){
// 			if(arr[0]<arr[mid]{
// 				if(B>arr[mid])
// 					low=mid+1;
// 			else high=mid-1;
//  			}
// 			   else {				   
// 				high=mid-1;   
//  			   }	   
// 		}
			   
// 		else {
			
//  			if(arr[0]>arr[mid]){
// 				if(B>arr[mid])
// 					low=mid+1;
// 				else high=mid-1;			
//  			}			
//  			else {				
// 				low=mid+1;				
//  			}		
// 		}		
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
// Solutions 1 : make an array and push all the elements and find the median 
// this is ultra pro max tarika

// 2 sorted arrays 
// 1 3 5      7 9
//     a      b
// 2 4 6      8 10
//     c      d 

// I can imagine the resultant sorted array to be devided into two parts .
// first part of are having mid_first number of elemets therefor req-mid_first number of elements are 
// coming from the second array 

// there can be one of the test case that all the elements are coming from first array so from the second array we will take zero elements
// the array is divided into two sections with first half as (a,c) and for right half we call it as (b,d)
// => assigning the variable as INT_MIN for left half half and if all the elements are used up we will initialize INT_MAX for right half .

// we do this because we take out the max element of left part whereas min element from right half.

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
//  3^7 = 3 * (3^6) =  3
//  3 * ((3^2)^3) =  9
//  3 * 9 * (9^2)  = 9 
//  3 * 9 * (81^1) = 81
//  3 * 9 * 81* (81 ^ 0) 

//  1 + 2 + 4

int Solution::pow(int x, int n, int d) {
    
    if(x==0)
    {
        return 1%d;
    }
    long long int ans=1;
    long long int base=x;
    
    while(n>0)
    {
        if(n%2!=0){
		ans=ans*base;
		n=n-1;
	}
	    else {
		    base=base*base;
		    n=n/2;
		    
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
