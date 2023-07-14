//task_1
#include <iostream>
#include "tree_node.hpp"

Tree_node::Tree_node(std::string data) : data("null"), left(nullptr), right(nullptr), count(1)
{
	this->data = data;
}

std::string Tree_node::getData() const { return this->data; }
int Tree_node::getCount() const { return this->count; }
Tree_node* Tree_node::getLeft() const { return this->left; }
Tree_node* Tree_node::getRight() const { return this->right; }
void Tree_node::setData(std::string data) { this->data = data; }
void Tree_node::setCount(int count) { this->count = count; }
void Tree_node::setLeft(Tree_node* left) { this->left = left; }
void Tree_node::setRight(Tree_node* right) { this->right = right; }
