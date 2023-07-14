//task_1
#pragma once
#include <string>

class Tree_node
{
	std::string data;
	int count;
	Tree_node* left;
	Tree_node* right;

public:
	Tree_node(std::string);
	std::string getData() const;
	int getCount() const;
	Tree_node* getLeft() const;
	Tree_node* getRight() const;
	void setData(std::string);
	void setCount(int);
	void setLeft(Tree_node*);
	void setRight(Tree_node*);
};