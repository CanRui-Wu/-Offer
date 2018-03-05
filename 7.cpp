#include <iostream>
#include <vector>
using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	TreeNode *construct(vector<int> &pre,vector<int> &vin,int pre_start,int pre_end,int vin_start,int vin_end) {
		if(pre_start > pre_end || vin_start > vin_end)
			return NULL;
		TreeNode *root = new TreeNode(pre[pre_start]);
		int vin_split;
		for(int i = vin_start;i <= vin_end;i++) {
			if(vin[i] == pre[pre_start]) {
				vin_split = i;
				break;
			}
		}
		int left_length = vin_split-vin_start;
		int right_length = vin_end-vin_split;
		root->left = construct(pre,vin,pre_start+1,pre_start+left_length,vin_start,vin_split-1);
		root->right = construct(pre,vin,pre_start+left_length+1,pre_end,vin_split+1,vin_end);
		return root;
	}
    TreeNode* reConstructBinaryTree(vector<int> pre,vector<int> vin) {
    	return construct(pre,vin,0,pre.size()-1,0,vin.size()-1);
    }
};

void print(TreeNode *root) {
	if(root == NULL)
		return;
	cout << root->val << endl;
	print(root->left);
	print(root->right);
}

int main() {
	vector<int> pre = {1,2,4,7,3,5,6,8};
	vector<int> vin = {4,7,2,1,5,3,8,6};
	Solution solution;
	TreeNode *root = solution.reConstructBinaryTree(pre,vin);
	print(root);
}