#include "BinaryTree.h"
#include "TreeNode.h"
#include<iostream>
#include<queue>

//Default Constructor
BinaryTree::BinaryTree()
{
	nodeCount = 0;
	root = nullptr;
}
//Single Argument Constructor
BinaryTree::BinaryTree(int &data)
{
	nodeCount = 0;
	insert(data);
}
//Parameterized Constructor (std::initializer_list)
BinaryTree::BinaryTree(std::initializer_list<int> list)
{
	root = nullptr;
	nodeCount = 0;
	for (const auto &e : list)
	{
		insert(e);
	}
}
//Copy Constructor {
BinaryTree::BinaryTree(BinaryTree& Tree)
{
	nodeCount = Tree.nodeCount;
	root = copy(Tree.root);
}
TreeNode* BinaryTree::copy(TreeNode* node)
{
	if (node)
	{
		TreeNode* newNode = new TreeNode();
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
BinaryTree::~BinaryTree() 
{
	clear();
	delete root;
}
//Insert using key
void BinaryTree::insert(int data)
{
	if (root == nullptr) {
		root = new TreeNode(data);
		++nodeCount;
	}
	TreeNode* current = root;
	while (current &&  current->key != data)
	{
		if (current->key > data && current->left == nullptr)
		{
			current->left = new TreeNode(data);
			++nodeCount;
			return;
		}
		if (current->key < data && current->right == nullptr)
		{
			current->right = new TreeNode(data);
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
//Get Node's count
int BinaryTree::get_number_of_nodes()
{
	return nodeCount;
}
//Get root data
int BinaryTree::get_root_data()
{
	return root->key;
}
int BinaryTree::getHeight(TreeNode* node)
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
int BinaryTree::get_height()
{
	return getHeight(root);
}
//Contains using key(true/false)
bool BinaryTree::contains(int &data)
{
	TreeNode* current = root;
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
void BinaryTree::erase(int data)
{
	TreeNode* current = root;
	TreeNode* parent = nullptr;
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
	TreeNode* replace = current->right;
	while (replace->left)
		replace = replace->left;
	int replace_value = replace->key;
	erase(replace_value);
	current->key = replace_value;
}
//Delete all Node's except root
void BinaryTree::clear()
{
	clearTree(root);
}
void BinaryTree::clearTree(TreeNode* &node)
{
	if (node == nullptr) {
		return;
	}
	clearTree(node->left);
	clearTree(node->right);
	delete node;
	node = nullptr;

}
//Find using key (Node address)
TreeNode* BinaryTree::find(int &data)
{
	TreeNode* current = root;
	while (current && current->key != data)
	{
		if (current->key > data)
			current = current->left;
		else
			current = current->right;
	}
	return current;
}
//Inorder traversal {
void BinaryTree::inorder(TreeNode* node)
{
	if (node != nullptr) {
		inorder(node->left);
		std::cout << node->key << ',';
		inorder(node->right);
	}
}
void BinaryTree::inorder()
{
	inorder(root);
	std::cout << std::endl;
}
//Inorder traversal }
//Preorder traversal {
void BinaryTree::preorder(TreeNode* node)
{
	if (node != nullptr) {
		std::cout << node->key << ',';
		preorder(node->left);
		preorder(node->right);
	}
}
void BinaryTree::preorder()
{
	preorder(root);
	std::cout << std::endl;
}
//Preorder traversal }
//Levelorder traversal {
void BinaryTree::levelorder()
{
	levelorder(root);
	std::cout << " ";
}

void BinaryTree::levelorder(TreeNode* node)
{
	if (node == nullptr)
	{
		return;
	}
	std::queue<TreeNode*> list;
	list.push(node);
	while (!list.empty())
	{
		TreeNode* current = list.front();
		std::cout << current->key << "  ";
		if (current->left != nullptr)
		{
			list.push(current->left);
		}
		if (current->right != nullptr)
		{
			list.push (current->right);
		}
		list.pop();
	}
}
//Levelorder traversal }
//PostOrder traversal {
void BinaryTree::postorder()
{
	postorder(root);
	std::cout << std::endl;
}

void BinaryTree::postorder(TreeNode* node)
{
	if (node != nullptr) {
		postorder(node->left);
		postorder(node->right);
		std::cout << node->key << ',';
	}
}
//Postorder traversal }
//Print tree (private) {
void BinaryTree::Print()
{
	Print_Tree(this->root);
	std::cout << std::endl;
}
void BinaryTree::Print_Tree(TreeNode* current)
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
BinaryTree& BinaryTree::operator=(BinaryTree& other)
{
	BinaryTree* ptr = &other;

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
void BinaryTree::print(std::ostream& out, TreeNode* curr) const
{
	if (curr)
	{
		print(out, curr->right);
		out << curr->key << " ";
		print(out, curr->left);
	}
}
std::ostream& operator<<(std::ostream& out, const BinaryTree& tmp)
{
	tmp.print(out, tmp.root);
	return out;
}
//Operator stream out } 