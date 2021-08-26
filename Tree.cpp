#include <iostream>
using namespace std;
struct TreeNode*{
    int val;
    TreeNode* left=NULL;
    TreeNode* right=NULL;
}
//left view
vector<int> solve(TreeNode* root)
{
    //level order first element
}


//right view
vector<int> solve(TreeNode *root)
{
    //level order ka rightmost element
}
//top view
void topview(TreeNode* root,unordered_map<int,pair<int,int>>mp,int height,int level)
{
    if(root==NULL)
    return;
    
    if(mp.find(level)==mp.end())
    mp[level]={root->val,height};
    else if{
        if(mp[level].second>height)
        {
            mp[level]={root->val,height};
        }
    }
    
    topview(root->left,mp,height+1,level-1);
    topview(root->right,mp,height+1,level+1);
    
    
}

//bottom view
void bottomview(TreeNode* root,unordered_map<int,pair<int,int>>mp,int height,int level)
{
    if(root==NULL)
    return;
    
    if(mp.find(level)==mp.end())
    mp[level]={root->val,height};
    else if{
        if(mp[level].second<=height)
        {
            mp[level]={root->val,height};
        }
    }
    
    bottomview(root->left,mp,height+1,level-1);
    bottomview(root->right,mp,height+1,level+1);
}

//Zigzag view
vector<vector<int>> Zigzag(TreeNode *root)
{
    //nornal level order
}
//reverse level order
vector<int> reverselevel(TreeNode *root)
{
    
    vector<int>ans;
    queue<TreeNode*>q;
        q.push(root);
    while(true)
    {
        TreeNode* cur=q.front();
        q.pop();
        
        if(cur==NULL)
        {
            q.push(NULL);
            if(q.front()==NULL)
            break;
        }
        else {
            ans.push_back(cur->val);
            if(cur->right)
            q.push(cur->right);
            if(cur->left)
            q.push(cur->left);
        }
    }
    reverse(ans.begin(),ans.end());
    return ans;
}

//preorder traversal
vector<int> preorder(TreeNode* root)
{
    stack<TreeNode*>s;
    while(root)
    {
        v.push_back(root);
        root=root->left;
    }
    
    
    while(!s.empty())
    {
        TreeNode *cur=s.top();
        s.pop();
        cur=cur->right;
        
        while(cur)
        {
            v.push_back(cur->val);
            s.push(cur);
            cur=cur->left;
        }
    }
    return v;
}
 //inorder traversal
 vector<int> inorder(TreeNode *root)
 {
     stack<TreeNode*>s;
     vector<int>ans;
     
     while(root)
     {
         s.push(root);
         root=root->left;
     }
     while(!s.empty())
     {
         TreeNode* cur=s.top();
         s.pop();
         ans.push(cur);
         cur=cur->right;
         while(cur)
         {
             s.push(cur);
             cur=cur->left;
         }
     }
     return ans;
 }
//postorder
vector<int>postorder(TreeNode *root)
{
    stack<TreeNode*>s;
    vector<int>ans;
    
    while(root)
    {
        ans.push_back(root->val);
        s.push(root);
        root=root->right;
    }
    
    while(!s.empty())
    {
        TreeNode *cur=s.top();
        s.pop();
        
        cur=cur->left;
        while(cur)
        {
            ans.push_back(cur->val);
            s.push(cur);
            cur=cur->right;
        }
    }
    reverse(ans.begin(),ans.end());
    return ans;
}
//diagonal 

vector<int> diagonal(TreeNode *root)
{
    queue<TreeNode*>q;
    q.push(root);
    
    while(!q.empty())
    {
        TreeNode* cur=q.front();
        
        while(cur)
        {
            ans.push_back(cur->val);
            if(cur->left)
            q.push(cur->left);
            cur=cur->right;
        }
    }
    return ans;
}

//merge two BT

TreeNode* merge(TreeNode* A,TreeNode* B)
{
   if(A==NULL && B==NULL)
   return NULL;
   
   if(A && B)
   A->val+=B->val;
   
   
   if(A && !B)
   return A;
   
   if(!A && B )
   return B;
    
    if(A && B)
    {
    A->left=merge(A->left,B->left);
    A->right=merge(A->right,B->right);
    }
    
    return A;
    
}
//Remove halfnode
TreeNode* halfnode (TreeNode *root)
{
    if(root==NULL)
    return NULL;
   
    
    root->left=halfnode(root->left);
    root->right=halfnode(root->right);
    
   
    
    if(root->left!=NULL && root->right)
    return root->left;
    
    if(root->right && root->left==NULL)
    return root->right;
   
    return root;
    
}
//path to a given node 
void path(TreeNode* root,int k ,vector<int>&ans,vector<int>&fans)
{
    if(root==NULL)
    return ;
    
    ans.push(root->val);
    if(root->val==k)
    fans=ans;
    
    path(root->left,k,ans,fans);
    path(root->right,k,ans,fans);
    
    ans.pop();
}

//Recover Binary Tree   //VIMP
void inorder(TreeNode* A,TreeNode* &f,TreeNode* &s,TreeNode* &t,TreeNode* &prev)
{
    if(A==NULL)
    return ;
    
    inorder(A->left,f,s,t,prev);

    if(prev!=NULL && prev->val>A->val)
    {
        if(s==NULL)
        {
            f=prev;
            s=A;
        }
        else t=A;
    }
    prev=A;
    inorder(A->right,f,s,t,prev);

}

int main() {
    
	return 0;
}
