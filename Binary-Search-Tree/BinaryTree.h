#pragma once
#include "TreeNode.h"
#include <iostream>
#include <queue>
#include <initializer_list>


template<class data_type>
class BinaryTree
{
private:
	int getHeight(TreeNode<data_type>* node);
	void clearTree(TreeNode<data_type>*& node);
	void inorder(TreeNode<data_type>* node);
	void preorder(TreeNode<data_type>* node);
	void levelorder(TreeNode<data_type>* node);
	void postorder(TreeNode<data_type>* node);
	TreeNode<data_type>* copy(TreeNode<data_type>* node);
	void print(std::ostream& ost, TreeNode<data_type>* curr) const;
	void Print_Tree(TreeNode<data_type>* node);
	void Print();
public:
	//Root node
	TreeNode<data_type>* root;
	//Node Counts
	int nodeCount;
	//Default Constructor
	BinaryTree();
	//Single Argument Constructor
	BinaryTree(data_type data);
	//Parameterized Constructor (std::initializer_list)
	BinaryTree(std::initializer_list<data_type> list);
	//Copy Constructor
	BinaryTree(BinaryTree<data_type>& Tree);
	//Destructor
	~BinaryTree();
	//Insert using key
	void insert(data_type data);
	//Get Node's count
	int get_number_of_nodes();
	//Get root data
	int get_root_data();
	//Get tree height
	int get_height();
	//Contains using key(true/false)
	bool contains(data_type data);
	//Delete Node using key
	void erase(data_type data);
	//Delete all Node's except root
	void clear();
	//Find using key (Node address)
	TreeNode<data_type>* find(data_type data);
	//Inorder traversal
	void inorder();
	//Preorder traversal
	void preorder();
	//Postorder traversal
	void postorder();
	//Levelorder
	void levelorder();
	//Operator copy assignment (=)
	BinaryTree<data_type>& operator=( BinaryTree<data_type>& rhs);
	//Operator stream out(<<)
	template<class data_type>
	friend std::ostream& operator<<(std::ostream& out, const BinaryTree<data_type>& tmp);
	
};


//Default Constructor
template<class data_type>
BinaryTree<data_type>::BinaryTree()
{
	nodeCount = 0;
	root = nullptr;
}
//Single Argument Constructor
template<class data_type>
BinaryTree<data_type>::BinaryTree(data_type data)
{
	nodeCount = 0;
	insert(data);
}
//Parameterized Constructor (std::initializer_list)
template<class data_type>
BinaryTree<data_type>::BinaryTree(std::initializer_list<data_type> list)
{
	root = nullptr;
	nodeCount = 0;
	for (const auto& e : list)
	{
		insert(e);
	}
}
//Copy Constructor {
template<class data_type>
BinaryTree<data_type>::BinaryTree(BinaryTree<data_type>& Tree)
{
	nodeCount = Tree.nodeCount;
	root = copy(Tree.root);
}
template<class data_type>
TreeNode<data_type>* BinaryTree<data_type>::copy(TreeNode<data_type>* node)
{
	if (node)
	{
		TreeNode<data_type>* newNode = new TreeNode<data_type>();
		newNode->key = node->key;
		newNode->left = copy(node->left);
		newNode->right = copy(node->right);
		return newNode;
	}
	else
	{
		return nullptr;
	}
}
//Copy Constructor }
//Destructor
template<class data_type>
BinaryTree<data_type>::~BinaryTree()
{
	clear();
	delete root;
}
template<class data_type>
//Insert using key
void BinaryTree<data_type>::insert(data_type data)
{
	if (root == nullptr) {
		root = new TreeNode<data_type>(data);
		++nodeCount;
	}
	TreeNode<data_type>* current = root;
	while (current && current->key != data)
	{
		if (current->key > data && current->left == nullptr)
		{
			current->left = new TreeNode<data_type>(data);
			++nodeCount;
			return;
		}
		if (current->key < data && current->right == nullptr)
		{
			current->right = new TreeNode<data_type>(data);
			++nodeCount;
			return;
		}
		if (current->key > data)
		{
			current = current->left;
		}
		else
		{
			current = current->right;
		}
	}
}
template<class data_type>
//Get Node's count
int BinaryTree<data_type>::get_number_of_nodes()
{
	return nodeCount;
}
template<class data_type>
//Get root data
int BinaryTree<data_type>::get_root_data()
{
	return root->key;
}
template<class data_type>
int BinaryTree<data_type>::getHeight(TreeNode<data_type>* node)
{
	if (!node)
	{
		return 0;
	}
	else
	{
		int left_height = getHeight(node->left);
		int right_height = getHeight(node->right);
		if (left_height >= right_height)
		{
			return left_height + 1;
		}
		else
		{
			return right_height + 1;
		}

	}

}
//Get tree height
template<class data_type>
int BinaryTree<data_type>::get_height()
{
	return getHeight(root);
}
//Contains using key(true/false)
template<class data_type>
bool BinaryTree<data_type>::contains(data_type data)
{
	TreeNode<data_type>* current = root;
	while (current && current->key != data)
	{
		if (current->key > data)
			current = current->left;
		else
			current = current->right;
	}
	return current != nullptr;
}
//Delete Node using key
template<class data_type>
void BinaryTree<data_type>::erase(data_type data)
{
	TreeNode<data_type>* current = root;
	TreeNode<data_type>* parent = nullptr;
	while (current && current->key != data)
	{
		parent = current;
		if (current->key > data)
		{
			current = current->left;
		}
		else
		{
			current = current->right;
		}
	}
	if (!current)
		return;
	if (current->left == nullptr)
	{
		if (parent && parent->left == current)
			parent->left = current->right;
		if (parent && parent->right == current)
			parent->right = current->right;
		--nodeCount;
		delete current;
		return;
	}
	if (current->right == nullptr)
	{
		if (parent && parent->left == current)
			parent->left = current->left;
		if (parent && parent->right == current)
			parent->right = current->left;
		--nodeCount;
		delete current;
		return;
	}
	TreeNode<data_type>* replace = current->right;
	while (replace->left)
		replace = replace->left;
	int replace_value = replace->key;
	erase(replace_value);
	current->key = replace_value;
}
//Delete all Node's except root
template<class data_type>
void BinaryTree<data_type>::clear()
{
	clearTree(root);
}
template<class data_type>
void BinaryTree<data_type>::clearTree(TreeNode<data_type>*& node)
{
	if (node == nullptr)
	{
		return;
	}
	clearTree(node->left);
	clearTree(node->right);
	delete node;
	node = nullptr;

}
//Find using key (Node address)
template<class data_type>
TreeNode<data_type>* BinaryTree<data_type>::find(data_type data)
{
	TreeNode<data_type>* current = root;
	while (current && current->key != data)
	{
		if (current->key > data)
		{
			current = current->left;
		}

		else
		{
			current = current->right;
		}

	}
	return current;
}
//Inorder traversal {
template<class data_type>
void BinaryTree<data_type>::inorder(TreeNode<data_type>* node)
{
	if (node != nullptr) {
		inorder(node->left);
		std::cout << node->key << ',';
		inorder(node->right);
	}
}
template<class data_type>
void BinaryTree<data_type>::inorder()
{
	inorder(root);
	std::cout << std::endl;
}
//Inorder traversal }
//Preorder traversal {
template<class data_type>
void BinaryTree<data_type>::preorder(TreeNode<data_type>* node)
{
	if (node != nullptr) {
		std::cout << node->key << ',';
		preorder(node->left);
		preorder(node->right);
	}
}
template<class data_type>
void BinaryTree<data_type>::preorder()
{
	preorder(root);
	std::cout << std::endl;
}
//Preorder traversal }
//Levelorder traversal {
template<class data_type>
void BinaryTree<data_type>::levelorder()
{
	levelorder(root);
	std::cout << " ";
}
template<class data_type>
void BinaryTree<data_type>::levelorder(TreeNode<data_type>* node)
{
	if (node == nullptr)
	{
		return;
	}
	std::queue<TreeNode<data_type>*> list;
	list.push(node);
	while (!list.empty())
	{
		TreeNode* current = list.front();
		std::cout << current->key << "  ";
		if (current->left != nullptr)
			list.push(current->left);
		if (current->right != nullptr)
			list.push(current->right);

		list.pop();
	}
}
//Levelorder traversal }
//PostOrder traversal {
template<class data_type>
void BinaryTree<data_type>::postorder()
{
	postorder(root);
	std::cout << std::endl;
}
template<class data_type>
void BinaryTree<data_type>::postorder(TreeNode<data_type>* node)
{
	if (node != nullptr) {
		postorder(node->left);
		postorder(node->right);
		std::cout << node->key << ',';
	}
}
//Postorder traversal }
//Print tree (private) {
template<class data_type>
void BinaryTree<data_type>::Print()
{
	Print_Tree(this->root);
	std::cout << std::endl;
}
template<class data_type>
void BinaryTree<data_type>::Print_Tree(TreeNode<data_type>* current)
{
	if (current)
	{
		Print_Tree(current->left);
		std::cout << current->key << "  ";
		Print_Tree(current->right);
	}
}
//Print tree (private) }
//Copy Operator assignment
template<class data_type>
BinaryTree<data_type>& BinaryTree<data_type>::operator=(BinaryTree<data_type>& other)
{
	BinaryTree<data_type>* ptr = &other;

	if (this != &other)
	{
		clear();
		root = ptr->root;
		ptr->root = nullptr;
	}
	return *this;
}
//Operator stream out { 
//Print for ostream
template<class data_type>
void BinaryTree<data_type>::print(std::ostream& out, TreeNode<data_type>* curr) const
{
	if (curr)
	{
		print(out, curr->right);
		out << curr->key << " ";
		print(out, curr->left);
	}
}
template<class data_type>
std::ostream& operator<<(std::ostream& out, const BinaryTree<data_type>& tmp)
{
	tmp.print(out, tmp.root);
	return out;
}
//Operator stream out } 