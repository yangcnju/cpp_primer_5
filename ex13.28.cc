#include "ex13.28.h"
#include <iostream>
#include <string>

TreeNode::TreeNode():
	value(std::string()), count(0), left(nullptr), right(nullptr) {}


// class BinStrTree
BinStrTree::BinStrTree():
	root(new TreeNode()) {}


