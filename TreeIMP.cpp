#include <iostream>
using namespace std;

//recover a binary tree --> two nodes swap in bst

//1 .  1 2 3 4 8 6 7 5 9      1. // 1 2 3 4 6 5 7 8 9  // 1 2 3 4 5 6 7 8 9


void recover(TreeNode* root,TreeNode* &f,TreeNode* &s,TreeNode* &t,TreeNode* &prev)
{
    if(root==NULL)
    return ;
    recover(root->left,f,s,t,prev);
    
    if(prev!=NULL && prev->val>root->val)
    {
            if(!f)
            {
                f=root;
                s=prev;
            }
            else {
                f=root;
            }
    }
    prev=root;
    recover(root->right,f,s,t,prev);
}

//2 sum BST --> two nodes whose sum is target

bool ispos(TreeNode* root)
{
    stack<TreeNode*>s1;
    stack<TreeNode*>s2;
    
    TreeNode* cur=root;
    
    while(root)
    {
        s1.push(root);
        root=root->left;
    }
    while(cur)
    {
        s2.push(cur);
        cur=cur->right;
    }
    while(!s1.empty() && !s2.empty())
    {
        if(s1.top()==s2.top())
        break;
        
        TreeNode* root=s1.top();
        TreeNode* cur=s2.top();
        
        if(root->val+cur->val==target)
        return true;
        else if (root->val+cur->val>target){
            
            s2.pop();
            cur=cur->left;
            while(cur)
            {
                 s2.push(cur);
            cur=cur->right;
            }
        }
        else {
            s1.pop();
            root=root->right;
              while(root)
          {
              s1.push(root);
             root=root->left;
             }
        }
    }
    return false;
}

//Binary tree from post order
int search(vector<int>&in,int i,int j,int ele)
{
    for(int k=i;k<=j;k++)
    if(in[k]==ele)
    return k;
    
    return -1;
}
TreeNode* posttoTree(vector<int>&post,vector<int>&in,int i,int j,int &last)
{
    if(i>=j)
    return NULL;
    
    
    int index=search(in,i,j,post[last--]);
    
    TreeNode* root=new TreeNode(in[index]);
    
    root->right=posttoTree(post,in,index+1,j,last);
    root->left=posttoTree(post,in,i,index-1);
    
    return root;
}

//Least Common Ancestor


TreeNode* LCA(TreeNode* root,TreeNode* ans ,TreeNode* A,TreeNode* B)
{
    if(root==NULL)
    return root;
    
    TreeNode* lef=LCA(root->left,ans,A,B);
    TreeNode* rig=LCA(root->right,ans,A,B);
    
    if(root==A && root==B)
    {
        ans=root;
        return root;
    }
    if(root==A || root==B)
    return root;
    
    if((lef!=NULL || rig!=NULL) && (root==A || root==B))
    {
        ans=root;
        return root;
    }
    
    if(lef!=NULL && rig!=NULL)
    {
         ans=root;
        return root;
    }
    return (lef!=NULL ?lef : rig);
}

// flatten a tree to link list 

TreeNode* flattentree(TreeNode* root)
{
    if(root==NULL)
    return NULL;
    
    TreeNode* lef=flattentree(root->left);
    
    TreeNode* temp=root->right;
    
    root-right=root->left;
    
    root->left=NULL;
    
    TreeNode* cur=root;
    while(cur->right)
    {
        cur=cur->right;
    }
    cur->right=temp;
   
    TreeNode* rig=flattentree(root->right);
    
    return root;
}

// Maximum sum path   //VIP

int maxsumpath(TreeNode *A, int &ans)
{
    if(root==NULL)
    return 0;
    
    int lef=maxsumpath(A->left,ans);
    int rig=maxsumpath(A->right,ans);
    
    int x=A->val+lef+rig;
    x=max(x,A->val);
    x=max(x,A->val+max(lef,rig));
    
    ans=max(ans,x);
    
    return max(A->val,max(lef,rig)+A->val);
}

//Diamter of a tree


int dia(TreeNode* A,int &ans)
{
    if(root==NULL)
    return 0;
    
    int lef=dia(A->left,ans);
    int rig=dia(A->rig,ans);
    
    int x=1+lef+rig;
    
    ans=max(ans,x);
    
    return 1+max(lef,rig);
}

//serialize deserialize Tree
// Maximum Sum BST in BT
//Same tree structure

int main() {
	// your code goes here
	return 0;
}
