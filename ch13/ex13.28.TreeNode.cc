#include "ex13.28.TreeNode.h"
#include <string>
#include <stdexcept>
#include <memory>

TreeNode::TreeNode(const TreeNode &rhs):
	value(rhs.value), count(rhs.count)
{
	if(rhs.left!=nullptr)
		left = new TreeNode(*rhs.left);
	else
		left = nullptr;
	if(rhs.right!=nullptr)
		right = new TreeNode(*rhs.right);
	else
		right = nullptr;
}

TreeNode& TreeNode::operator=(const TreeNode &rhs){
	value = rhs.value;
	count = rhs.count;
	if(rhs.left!=nullptr)
		left = new TreeNode(*rhs.left);
	else
		left = nullptr;
	if(rhs.right!=nullptr)
		right = new TreeNode(*rhs.right);
	else
		right = nullptr;
	return *this;
}

TreeNode::~TreeNode()
{
	if(left!=nullptr){
		delete left->left;
	}
	if(right!=nullptr){
		delete right->right;
	}
	delete left;
	delete right;
}

BinStrTree::BinStrTree(const BinStrTree &rhs):
	root(new TreeNode(*rhs.root)) {}

BinStrTree::~BinStrTree()
{
	delete root;
	root = nullptr;
}
