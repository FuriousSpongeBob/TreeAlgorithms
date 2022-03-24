#include<iostream>
#include<vector>
#define TREENODESIZE 15
#define BRANCHNODESIZE 7
using namespace std;

typedef struct TreeNode
{
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
}TreeNode;

void InOrder(TreeNode *root){
	if(root==nullptr){
		return;
	}
	InOrder(root->left);
	cout<<root->val<<endl;
	InOrder(root->right);
}

void buildTree(TreeNode *root,vector<int> v,int i){
	if(i<TREENODESIZE&&(2*i+1)<TREENODESIZE&&v[i]!=0){
		root->val=v[i];
		//cout<<root->val;
		TreeNode *_tl=new TreeNode();
		_tl->val=v[2*i+1];
		TreeNode *tl=(v[2*i+1]!=0)?_tl:nullptr;
		TreeNode *_tr=new TreeNode();
		_tr->val=v[2*i+2];
		TreeNode *tr=(v[2*i+2]!=0)?_tr:nullptr;
		root->left=tl;
		root->right=tr;
		buildTree(tl,v,2*i+1);
		buildTree(tr,v,2*i+2);
	}else if(i<TREENODESIZE&&(2*i+1)>TREENODESIZE&&v[i]!=0){
		root->val=v[i];
		//cout<<root->val;
		root->left=nullptr;
		root->right=nullptr;
	}
}

int main(){
	vector<int> v={2,7,5,2,6,0,9,0,0,5,11,0,0,4,0};
	TreeNode *root=new TreeNode();
	buildTree(root,v,0);
	InOrder(root);
}