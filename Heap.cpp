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


int main() {
	// your code goes here
	return 0;
}
