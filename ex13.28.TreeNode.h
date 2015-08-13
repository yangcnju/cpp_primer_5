#ifndef _ex_13_28_TreeNode_h
#define _ex_13_28_TreeNode_h

#include <string>
#include <stdexcept>
#include <memory>

class TreeNode {
public:
	TreeNode():
		value(""),count(0),left(nullptr),right(nullptr) {}
	// copy control
	TreeNode(const TreeNode &rhs);
	TreeNode& operator=(const TreeNode &rhs);
	~TreeNode();
private:
	std::string value;
	int count;
	TreeNode *left;
	TreeNode *right;
}; // class TreeNode

class BinStrTree {
public:
	BinStrTree(): root(new TreeNode()) {}
	BinStrTree(const BinStrTree &rhs);
	BinStrTree& operator=(const BinStrTree &rhs){
		root = new TreeNode(*rhs.root);
		return *this;
	}
	~BinStrTree();
private:
	TreeNode *root;
};	// class BinStrTree


#endif
