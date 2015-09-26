#ifndef _ex_13_28_h
#define _ex_13_28_h

#include <string>
#include <iostream>

// a double linked list accessed from root

// (a)
class TreeNode{
public:
	TreeNode();
	TreeNode(const std::string&);

	TreeNode(const TreeNode&);
	TreeNode& operator=(const TreeNode&);
	~TreeNode();
private:
	std::string value;
	int count;
	TreeNode *left;
	TreeNode *right;
};

// (b)
class BinStrTree{
public:
	BinStrTree();
	BinStrTree(const BinStrTree&) = delete;
	BinStrTree& operator=(const TreeNode&) = delete;
	~BinStrTree();
private:
	TreeNode *root;
};

#endif
