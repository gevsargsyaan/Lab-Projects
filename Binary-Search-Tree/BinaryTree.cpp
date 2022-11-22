#include "BinaryTree.h"
#include "TreeNode.h"
#include<iostream>
#include<queue>
BinaryTree::BinaryTree()
{
	nodeCount = 0;
	root = nullptr;
}
BinaryTree::BinaryTree(int data)
{
	nodeCount = 0;
	Insert(data);
	
}
BinaryTree::BinaryTree(std::initializer_list<int> list)
{
	root = nullptr;
	nodeCount = 0;
	for (auto e : list)
	{
		Insert(e);
	}
}
BinaryTree::BinaryTree(BinaryTree& Tree)
{
	nodeCount = Tree.nodeCount;
	root = copy(Tree.root);
}
BinaryTree::~BinaryTree() 
{
	clear();
	delete root;
}
void BinaryTree::Insert(int data)
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
void BinaryTree::Print()
{
	Print_Tree(this->root);
	std::cout << std::endl;
}
int BinaryTree::get_number_of_nodes()
{
	return nodeCount;
}
int BinaryTree::get_root_data()
{
	return root->key;
}
int BinaryTree::getHeight(TreeNode* node)
{
	if (!node)
		return 0;
	else {
		
		int left_height = getHeight(node->left);
		int right_height = getHeight(node->right);
		if (left_height >= right_height)
			return left_height + 1;
		else
			return right_height + 1;
	}
}
int BinaryTree::get_height()
{
	return getHeight(root);
}
bool BinaryTree::contains(int data)
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
TreeNode* BinaryTree::find(int data)
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
void BinaryTree::preorder(TreeNode* node)
{
	if (node != nullptr) {
		std::cout << node->key << ',';
		preorder(node->left);
		preorder(node->right);
	}
}

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
void BinaryTree::preorder()
{
	preorder(root);
	std::cout << std::endl;
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
void BinaryTree::postorder()
{
	postorder(root);
	std::cout << std::endl;
}
BinaryTree& BinaryTree::operator=(BinaryTree& other)
{
	BinaryTree* ptr = &other;
    
    if (this != &other)
    {
        clear ();
        
        root = ptr->root; 

        ptr->root = nullptr;
    }
    return *this;
}
void BinaryTree::postorder(TreeNode* node)
{
	if (node != nullptr) {
		postorder(node->left);
		postorder(node->right);
		std::cout << node->key << ',';
	}
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

void BinaryTree::print(std::ostream& out, TreeNode* curr) const
{
	if (curr)
	{
		print(out, curr->right);
		out << curr->key <<"," ;
		print(out, curr->left);
	}
}

std::ostream& operator<<(std::ostream& out, const BinaryTree& tmp)
{
	tmp.print(out, tmp.root);
	return out;
}
