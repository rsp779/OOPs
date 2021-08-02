#include <bits/stdc++.h>
using namespace std;

//0 1 2  sorting of 3 numbers

void sortingof3no(vector<int>&v)
{
    int i=0,j=v.size()-1;
    
    int k=0;
    
    while(k<j)
    {
        if(v[k]==0)
        {
            swap(v[i],v[k]);
            
            if(i==k)
            k++;
            
            i++;
            
        }
        else if (v[k]==2)
        {
            swap(v[k],v[j]);
            
            if(k==j)
            k++;
            
            j--;
        }
        else k++;
    }
}

//Largest Continuous Sequence sum 0
vector<int> sumzero(vector<int>v)
{
    unordered_map<int,int>mp;
    mp[0]=-1;
    int maxlen=0;
    int sum=0;
    int x=-1;
    int y=-1;
    for(int i=0;i<v.size();i++)
    {
        sum+=v[i];
        
        int len=0;
        if(mp.find(sum)!=mp.end())
        {
            len=i-mp[sum];
        }
        else mp[sum]=i;
        
        
        if(len>maxlen)
        {
            maxlen=len;
            x=mp[sum];
            y=i;
        }
    }
        vector<int>ans;
        for(int i=x+1;i<=y;i++)
        ans.push_back(v[i]);
        
        return ans;
 }
 //You need to find the length of the longest subarray having count of 1’s one more than count of 0’s.
 
 int onemorethanzero (vector<int>v)
 {
     unordered_map<int,int>mp;
     int sum=0;
     int len=0;
     int maxlen=0;
     for(int i=0;i<v.size();i++)
     {
         sum+=(v[i]==1)?1:-1;
         
         if(mp.find(sum-1)!=mp.end())
         
         maxlen=max(maxlen,i-mp[sum-1]);
         
         else mp[sum]=i;
        
     }
     return maxlen;
 }
//2 sum
bool 2sum (vector<int>v,int sum)
{
    unordered_map<int,int>mp;
    for(int i=0;i<v.size();i++)
    {
        if(mp.find(sum-v[i])!=mp.end())
        return true;
        
        mp[v[i]]++;
    }
    return false;
}
//3 sum
bool 3sum(vector<int>v,int target)
{
    sort(v.begin(),v.end());
    
    for(int i=0;i<v.size();i++)
    {
        int x=i+1;
        int y=v.size()-1;
        
        while(x<y)
        {
            int sum=v[i]+v[x]+v[y];
            
            if(sum==target)
            return true;
            
            else if(sum>target)
            {
                y--;
            }
            else x++;
        }
    }
}
//4 sum

vector<vector<int>> 4sum(vector<int>v,int target)
{
    unordered_map<int,vector<pair<int,int>>>mp;
    
    for(int i=0;i<v.size();i++)
    {
        for(int j=i+1;j<v.size();j++)
        {
            mp[v[i]+v[j]].push_back({i,j});
        }
    }
    
    set<vector<int>>ans;
    
    for(int x : mp)
    {
        if(mp.find(target-x)!=mp.end())
        {
            vector<pair<int,int>>x=mp[x];
            vector<pair<int,int>>y=mp[target-x];
            
            for(int i=0;i<x.size();i++)
            {
                for(int j=0;j<y.size();j++)
                {
                    set<int>s;
                    vector<int>z;
                    s.insert(x[i].first);
                    s.insert(x[i].second);
                    s.insert(y[j].first);
                    s.insert(y[j].second);
                    z.push_back(v[x[i].first]);
                    z.push_back(v[x[i].second]);
                    z.push_back(v[y[j].first]);
                    z.push_back(v[y[j].second]);
                    if(s.size()==4)
                    {
                       sort(z.begin(),z.end());
                       ans.insert(z);
                        
                    }
                }
            }
            
        }
    }
    vector<vector<int>>fans;
    for(auto x : ans)
    {
        fans.push_back(*x);
    }
    return fans;
}
//valid sudoku

int Solution::isValidSudoku(const vector<string> &A) {
    
    for(int i=0;i<A.size();i++)
    {
    unordered_map<int,int>mp;
    for(int j=0;j<A.size();j++)
    {
        if(A[i][j]!='.')
        {
            int p=A[i][j]-'0';
            if(mp.find(p)!=mp.end())
            return 0;
            
            mp[p]++;
        }
    }
    }
    
     for(int i=0;i<A.size();i++)
    {
    unordered_map<int,int>mp;
    for(int j=0;j<A.size();j++)
    {
        if(A[j][i]!='.')
        {
            int p=A[j][i]-'0';
            if(mp.find(p)!=mp.end())
            return 0;
            
            mp[p]++;
        }
    }
    }
    
    for(int i=0;i<9;i=i+3)
    {
        for(int j=0;j<9;j=j+3)
        {
            unordered_map<char,int>mp;
            for(l=i;l<i+3;l++)
            {
            for(int k=j;k<j+3;k++)
            {
                if(A[l][k]!='.')
                {
                    if(mp.find(A[l][k])!=mp.end())
                    return 0;
                    
                    mp[A[l][k]]++;
                }
            }
            }
        }
    }
    return 1;
}

//A[i]-A[j]=diff  i!=j
bool ispos(vector<int>v,int diff)
{
    unordered_map<int,int>mp;
    
    for(int i=0;i<v.size();i++)
    {
        if(mp.find(v[i]-diff)!=mp.end())return true;
        if(mp.find(v[i]+diff)!=mp.end())return true;
        
        mp[v[i]]++;
    }
    return false;
}
 //pair with a given xor_eqconst_cast
 int Solution::solve(vector<int> &A, int B) {
    unordered_map<int,int>mp;
    int ans=0;
    for(int i=0;i<A.size();i++)
    {
        int x=B^A[i];
        if(mp.find(x)!=mp.end())ans=ans+mp[x];
        
        mp[A[i]]++;
    }
    return ans;
}

//Anagrams
vector<vector<string>> anagram(vector<string>v)
{
    unordered_map<string,vector<string>>mp;
    for(int i=0;i<v.size();i++)
    {
        string str=v[i];
        sort(str.begin(),str.end());
        
        mp[str].push_back(v[i]);
    }
    vector<vector<string>>ans;
    for(string x : mp)
    ans.push_back(x);
    
    return ans;
}

//Equals
vector<int> equals(vector<int>v)
{
    int n=v.size();
    for(int i=0;i<n-3;i++)  //A
    {
        for(int j=i+1;j<n;j++)
        {
            vector<int>ans;
            unordered_map<int,int>mp;
            
            
            for(int k=i+1;k<n;k++)
            {
                if(k==j)
                continue;
                
                int search=v[i]+v[j]-v[k];
                
                if(mp.find(search)!=mp.end() && mp[search]!=j)
                {
                   if(ans.empty()    || ans[0]>mp[search])
                   {
                       ans={mp[search],k};
                   }
                }
                if(mp.find(search)==mp.end())
                mp[search]=k;
            }
            if(ans.size()==2)
            {
                return {i,j,ans[0],ans[1]};
            }
        }
    }
    return {};
}

//Average of K elements equal p
int solve(vector<int>v,int p)
{
    int sum=0;
    int ans=0;
    unordered_map<int,int>mp;
    mp[0]=1;
    for(int i=0;i<v.size();i++)
    {
        sum+=v[i]-p;
        
        if(mp.find(sum)!=mp.end())ans+=mp[sum];
        
        mp[sum]++;
    }
    return ans;
}
//Copy list
ListNode* solve(ListNode *head)
{
    if(head==NULL)
    return head;
    
    ListNode* cur=head;
    
    while(cur)
    {
        ListNode* copy=new ListNode(cur->val);
        copy->next=cur->next;
        cur->next=copy;
        cur=copy->next;
    }
    cur=head;
    
    while(cur)
    {
        if(cur->random)
        {
            cur->next->random=cur->random->next;
        }
        cur=cur->next->next;
    }
    cur=head;
    ListNode* ans=head->next;
    
    while(cur)
    {
        ListNode* temp=cur->next->next;
        ListNode* copy=cur->next;
        cur->next=NULL;
        cur=temp;
        copy->next=temp->next;
    }
    return ans;
}

//Fractions
string Fractions(int a,int b)
{
   
    if(b==0)
    {
        if(a>0)
        return to_string(INT_MAX);
        else return to_string(INT_MIN);
    }
    int sign=1;
    if(a<0)
    sign*=-1;
    
    if(b<0)
    sign*=-1;

    if(a%b==0)
    {
        return to_string(a/b);
    }
    
    string ans="";
    if(sign<0)
    ans.push_back("-");
    
    ans=to_string(a/b);
    ans.push_back('.');
    
    int r=a%b;
    int pos=str.size();
    unordered_map<int,int>mp;
    
    while(r!=0 && mp.find(r)!=mp.end())
    {
        int d=(r*10)/b;
        str.push_back(to_string(d));
        r=(r*10)%b;
        mp[r]=pos;
        pos++;
    }
    
    if(r==0)
    {
        return ans;
    }
    else {
        string str=ans.substr(0,mp[r]);
        str+='(';
        str+=ans.substr(mp[r],ans.length()-mp[r]);
        str+=')';
        return str;
    }
    
}

//Longest Substring Without Repeat
int solve(string str)
{
    int i=0,j=0,ans=1;
    unordered_map<char,int>mp;
    for(int i=0;i<str.size();i++)
    {
        mp[str[i]]++;
        
        while(mp[str[i]]>1)
        {
            mp[str[j]]--;
            j++;
        }
        ans=max(ans,i-j+1);
    }
    return ans;
}

//Given a string S and a string T, find the minimum window in S which will contain all the characters in T in linear time complexity.

int windowstring(string str,string check)
{
    int i=0,j=0;
    map<char,int>mp;
    for(int i=0;i<check.size();i++)
    mp[check[i]]++;
    
    int count=mp.size();
    int ans=1e9;
    unordered_map<char,int>xp;
    int cur=0;
    for(int j=0;j<str.size();)
    {
        
       while(j<str.size() && count!=cur)
       {
          xp[str[j]]++;
          
          if((mp.find(str[j])!=mp.end()) && xp[str[j]]==mp[str[j]])
          cur++;
          
          j++;
       }
        
        if(cur==count)
        {
        ans=min(ans,j-i);
        str=str.substr(i,j-i);
        }
        
        while(i<j && count==cur)
        {
            xp[str[i]]--;
            
            if(mp.find(str[i])!=mp.end() &&  xp[str[i]]<mp[str[i]] )
            cur=cur-1;
            i++;
        }
    }
    return (ans==1e9?-1:ans);  // return str;
}

//Subarray with B odd number
int solve(vector<int>v,int B)
{
    int count=0;
    int i=0,j=0;
    int ans=0;
    for(int j=0;j<v.size();)
    {
        count+=(v[i]%2!=0)1:0;
        
        while(i<=j && count>B)
        {
            count-=(v[i]%2!=0):1:0;
            i++;
        }
        ans+=j-i+1;
    }
    return ans;
}
int BoddNumber(vector<int>v,int B)
{
    return solve(v,B)-solve(v,B-1);
}

//XOR of Subarray
int count(vector<int>v,int B)
{
    int x=0;
    int ans=0;
    unordered_map<int,int>mp;
    for(int i=0;i<v.size();i++)
    {
       x=x xor v[i];
       int y=B xor x;
       
       if(x==B)
       ans++;
       
       if(mp.find(y)!=mp.end())
       ans+=mp[y];
       
       mp[x]++;
    }
    return ans;
}

//An Increment Problem    //deque used
vector<int> solve(vector<int>v)
{
    unordered_map<int,deque<int>> ;int>mp;
    vector<int>ans=v;
    for(int i=0;i<v.size();i++)
    {
        if(mp.find(v[i])!=mp.end())
        {
            int x=mp[v[i]].front();
            int y=v[x];
            mp[v[i]].pop_front();
            v[x]++;
            mp[v[x]].push_front(y);
            
        }
        mp[v[i]].push_back(i);
    }
    return v;
}

int main() {

	return 0;
}
