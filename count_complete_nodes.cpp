//思路：如果当前子树的极左节点与极右节点的高度相同，则当前子树为满二叉树，记下此时树的高度h，则树的节点数目应为pow(2,h)-1,否则递归调用该函数，得到左右子树的节点数目，加上1就是原来二叉树的节点数目。
class Solution{
    public:
	int countNodes(TreeNode *root){
	    if(!root)
		return 0;
	    TreeNode *l = root, *r =root;
	    int left_height=0,right_height=0;
	    while(l){
		left_height++;
		l=l->left;
	    }
	    while(r){
		right_height++;
		r=r->right;
	    }
	    if(left_height==right_height)
		return pow(2,left_height)-1;
	    return countNodes(root->left)+countNodes(root->right)+1;
	}
};
