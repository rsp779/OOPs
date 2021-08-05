#include <bits/stdc++.h>
using namespace std;

int heap[100010];

void heapify(int i,int n)
{
      int largest=i;
      int l=2*i+1;
      int r=2*i+2;
      
      if(l<n && heap[l]>heap[largest])
      largest=l;
      
      if(r<n && heap[r]>heap[largest])
      largest=r;
      
      if(largest!=i)
      {
            swap(heap[largest],heap[i]);
            heapify(largest,n);
      }
      
}

void buildmaxheap(vector<int>heap)    //O(3N)
{
      int n=heap.size();
      for(int i=n/2;i>=0;i--)
      {
            heapify(i,n);
      }
}

void heapsort(vector<int>heap)   //max heap --> ascending sorted array 
                                  //min heap ==> desending sorted array                                          
{
      buildmaxheap(heap);
      
      int n=v.size();
      for(int i=n-1;i>=0;i--)
      {
            swap(heap[0],heap[i]);
            maxheapify(0,i);
      }
}

//priority queue

void insert(int x)
{
      int k=n;
      heap[n]=x;
      n++;
      
      heapfilterup(k);
}

void heapfilterup(int k)
{
      int p=(k-1)/2;
      
      if(p>=0 && heap[p]<heap[k])
      {
            swap(heap[p],heap[k]);
            heapfilterup(p);
      }
}
/*   while(k/2>0)
      {
            int p=(k-1)/2;
            
            if(heap[k]<heap[p])
            return ;
            else {
                  swap(heap[p],heap[k]);
                  k=p;
            }
      }  */
      
//    Sliding Window Maximum (Maximum of all subarrays of size k)
vector<int> solve(vector<int>v,int k)
{
      deque<int>dq;
      vector<int>ans;
      
      for(int i=0;i<v.size();i++)
      {
            while(!dq.empty() && dq.front()>=(i-k))   //ensure dq has only those elements which is in i to i-k range
            dq.pop_front();
            
            while(!dq.empty() && v[dq.front()]<v[i])  
            dq.pop_back();
            
            dq.push_back(i);
            
            if(i+1>=k)
            ans.push_back(v[dq.front()]);
      }
      return ans;
}
     
//K largest element in array

int solve(vector<int>v)
{
      priority_queue<int,vector<int>,greater<int>>pq;
      
      for(int i=0;i<n;i++)
      {
            if(pq.size()<k)
            {
                  pq.push(v[i]);
            }
            else {
                  if(pq.front()<v[i])
                  {
                        pq.pop();
                        pq.push(v[i]);
                  }
            }
      }
      return pq.front();
}

//Merge K sorted Arrays 

vector<int> solve(vector<vector<int>>v)
{
      priority_queue<v,vector< pair<int,pair<int,int>>>,greater< pair<int,pair<int,int>>>>pq;
      
      for(int i=0;i<v.size();i++)
      pq.push({v[i][0],{i,0}});     //element   Array number    pos
      
      vector<int>ans;
      
      while(!pq.empty())
      {
             pair<int,pair<int,int>>p=pq.top();
             pq.pop();
             
             ans.push_back(p.first);
             
             int x=p.second.first;
             int pos=p.second.second;
             
             if(v[x].size()-1>pos)
             {
                   pq.push({v[x][pos+1],{x,pos+1}});
             }
      }
     return ans;
}

// K-th Largest Sum Contiguous Subarray    //n^2log(n^2)  ===> n^2log(k)
int solve(vector<int>v,int k)
{
      int n=v.size();
      int sum[n+1]={0};
      sum[0]=0;
      sum[1]=v[0];
      for(int i=2;i<n;i++)
      sum[i]=sum[i-1]+v[i-1];
      
      priority_queue<int,vector<int>,greater<int>>pq;
      
      for(int i=1;i<=n;i++)
      {
            for(int j=i;j<=n;j++)
            {
                  int x=sum[j]-sum[i-1];
                  
                  if(pq.size()<k)
                  {
                        pq.push(x);
                  }
                  else {
                        if(pq.top()<x)
                        {
                              pq.pop();
                              pq.push(x);
                        }
                  }
            }
      }
      return pq.top();
}

//Given a string s, rearrange the characters of s so that any two adjacent characters are not the same.

string reorganize(string str)
{
      string ans="";
      int count=0;
      unordered_map<char,int>mp;
      for(int i=0;i<str.size();i++)
      {
      mp[str[i]]++;
      count=max(count,mp[str[i]]);
      }
      
      if(count>(str.size()/2))return ans;
      
      priority_queue<pair<int,char>,vector<pair<int,char>>,greater<pair<int,char>>>pq;
      
      for(auto x : mp)
      {
            pq.push({x.second,x});
      }
      while(!pq.empty())
      {
            pair<int,char>p=pq.top();
            
            ans.push_back(p.second);
            
            pq.pop();
            
            if(!pq.empty())
            {
                  pair<int,char>q=pq.top();
                  pq.pop();
                  
                  ans.push_back(q.second);
                  
                  if(q.first>1)
                  pq.push({q.first-1,q.second});
                  
            }
            
            if(p.first>1)
            {
                  pq.push({p.first-1,p.second});
            }
      }
      return ans;
}

//Merge K sorted Link list

ListNode* merge(vector<ListNode*>&v)
{
      priority_queue<pair<int,ListNode*>,vector<pair<int,ListNode*>>,greater<pair<int,ListNode*>>>pq;
      
      for(int i=0;i<v.size();i++)
      pq.push({v[i]->val,v[i]});
      
      ListNode* head=new ListNode(-1);
      ListNode* temp=head;
      while(!pq.empty())
      {
            temp->next=pq.top().second;
            pq.pop();
            
            if(pq.top()->next)
            {
                  pq.push({pq.top()->next->val,pq.top()->next});
            }
      }
      return head->next;
}

//Median of stream of integers
class Solution
{
    public:
    //Function to insert heap.
    priority_queue<int,vector<int>>xp;   //stores max of min elements
    priority_queue<int,vector<int>,greater<int>>ip; //stores min of max elements
    Solution() 
    {
        while(!xp.empty())
        xp.pop();
        
        while(!ip.empty())
        ip.pop();
        
    }
    void insertHeap(int &x)
    {
        if(xp.empty() || xp.top()>x)
        xp.push(x);
        else ip.push(x);
    }
    
    //Function to balance heaps.
    void balanceHeaps()
    {
        if(xp.size()>ip.size()+1)
        {
            ip.push(xp.top());
            xp.pop();
        }
        else if(xp.size()+1<ip.size())   //to maintain the size difference of <=1 so that we can divide the sorted array in 2 parts
        {
            xp.push(ip.top());
            ip.pop();
        }
    }
    
    //Function to return Median.
    double getMedian()
    {
        balanceHeaps();
        if( xp.size()!=0 && xp.size()==ip.size())
        {
            return((xp.top()+ip.top())/2.0);
        }
        else {
            if(xp.empty())
            return(ip.top())*1.0;
            else if(ip.empty())
            return(xp.top())*1.0;
            
            else {
              return ((xp.size()>ip.size()?xp.top():ip.top())*1.0);
            }
        }
    }
};

//Minimum cost to connect ropes

int cost(vector<int>v)
{
    priority_queue<int,vector<int>,greater<int>>pq;
    for(int i=0;i<v.size();i++)
    pq.push({v[i]});
    int ans=0;
    while(pq.size()!=1)
    {
       int a=pq.top();
       pq.pop();
       int b=pq.top();
       pq.pop();
       
       ans+=a+b;
       pq.push(a+b);
       
    }
    return pq.top();
}

//comvert Min Heap to Max Heap
// ==> simple hepify with buildmaxheap

//Minimum sum using the elements of the array

string solve(int arr[], int n) {
        sort(arr,arr+n);
        
        int i=0,j=1;
        string s1="",s2="";
        while(j<n)
        {
            s1.push_back(arr[i]+'0');
            s2.push_back(arr[j]+'0');
            
            i=i+2;
            j=j+2;
        }
        if(n%2!=0)
           s1.push_back(arr[i]+'0');
        
        
        string ans="";
        int carry=0;
        i=s1.size()-1,j=s2.size()-1;
        
        while(i>=0 || j>=0 || carry>0)
        {
            int sum=carry;
            if(i>=0)
            sum+=s1[i]-'0';
            
            if(j>=0)
            sum+=s2[j]-'0';
            
            ans.push_back((sum%10)+'0');
            carry=sum/10;
            i--;j--;
        }
        reverse(ans.begin(),ans.end());
        i=0;
        while(i<ans.size()-1 && ans[i]=='0')
        i++;
        
        return ans.substr(i);
}
//Return first k maximum sum of 2 arrays

vector<int>kmaxsum(vector<int>a,vector<int>b,int k)
{
    sort(a.begin(),a.end());
    sort(b.begin(),b.end());
    
    priority_queue<pair<int,pair<int,int>,vector<pair<int,pair<int,int>>>>pq;
    int n=a.size()-1;
    int m=b.size()-1;
    
    pq.push({a[n][m],{n,m}});
    vector<int>ans;
    
    vector<vector<int>>dp(n+1,vector<int>(m+1,-1));

    
    while(ans.size()!=k)
    {
        pair<int,pair<int,int>p=pq.top();
        pq.pop();
        ans.push_back(p.first);
        
        int x=p.second.first;
        int y=p.second.second;
        
        if(x>0 && dp[x-1][y]=-1)
        {
            pq.push({a[x-1]+b[y],{x-1,y}});
            dp[x-1][y]=1;
        }
        if(y>0 && dp[x][y-1]=-1)
        {
            pq.push({a[x]+b[y-1],{x,y-1}});
            dp[x][y-1]=1;
        }
    }
    return ans;
}

//distict numbers in window
vector<int> distictnumbers(vector<int>v,int B)
{
    vector<int>ans;
    unordered_map<int,int>mp;
    
    for(int i=0;i<v.size();i++)
    mp[v[i]]=0;
    
    int count=0;
    
    for(int i=0;i<v.size();i++)
    {
        mp[v[i]]++;
        if(mp[v[i]]==1)
        count++;
        
        if(i+1>=B)
        {
            ans.push_back(count);
            mp[v[i+1-B]]--;
            
            if(mp[v[i+1-B]]==0)
            count--;
        }
    }
    return ans;
}


int main() {
	// your code goes here
	return 0;
}
