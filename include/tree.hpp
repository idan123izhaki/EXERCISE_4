//task_1
#pragma once
#include <fstream>
#include "tree_node.hpp"
class Tree
{
	Tree_node* root;

public:
	Tree();
	Tree_node* getRoot() const;
	void setRoot(Tree_node*);
	void addValue(std::string);
	Tree_node* insertIntoBST(Tree_node*, std::string);
	void printInOrder(Tree_node*);
	void printInOrder(Tree_node*, std::ostream&);
};