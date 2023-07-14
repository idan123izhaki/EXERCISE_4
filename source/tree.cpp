//task_1
#include "tree_node.hpp"
#include "tree.hpp"
#include <iostream>

Tree::Tree() : root(nullptr) {}

Tree_node* Tree::getRoot() const { return this->root; }
void Tree::setRoot(Tree_node* root) { this->root = root; }


void Tree::addValue(std::string val)
{
	this->root = insertIntoBST(this->root, val);
}

Tree_node* Tree::insertIntoBST(Tree_node* root, std::string value)
{
	if (root == nullptr) 
		return new Tree_node(value);
	if (value == root->getData())
		root->setCount(root->getCount() + 1);
	else if (value < root->getData())
		root->setLeft(insertIntoBST(root->getLeft(), value));
	else
		root->setRight(insertIntoBST(root->getRight(), value));
	return root;
}



void Tree::printInOrder(Tree_node* root) {
	printInOrder(root, std::cout);
}

void Tree::printInOrder(Tree_node* node, std::ostream& output)
{
	if (node == nullptr)
		return;
	printInOrder(node->getLeft(), output);
	output << node->getData() << "    " << node->getCount() << std::endl;
	printInOrder(node->getRight(), output);
}
