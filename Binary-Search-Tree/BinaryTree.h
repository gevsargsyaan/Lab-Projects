#pragma once
#include "TreeNode.h"
#include <initializer_list>
#include <vector>
#include<iostream>
class BinaryTree
{
private:
	int getHeight(TreeNode* node);
	void clearTree(TreeNode*& node);
	void inorder(TreeNode* node);
	void preorder(TreeNode* node);
	void levelorder(TreeNode* node);
	void postorder(TreeNode* node);
	TreeNode* copy(TreeNode* node);
	void print(std::ostream& ost, TreeNode* curr) const;
	void Print_Tree(TreeNode* node);
	void Print();
public:
	//Root node
	TreeNode* root;
	//Node Counts
	int nodeCount;
	//Default Constructor
	BinaryTree();
	//Single Argument Constructor
	BinaryTree(int &data);
	//Parameterized Constructor (std::initializer_list)
	BinaryTree(std::initializer_list<int> list);
	//Copy Constructor
	BinaryTree(BinaryTree& Tree);
	//Destructor
	~BinaryTree();
	//Insert using key
	void insert(int data);
	//Get Node's count
	int get_number_of_nodes();
	//Get root data
	int get_root_data();
	//Get tree height
	int get_height();
	//Contains using key(true/false)
	bool contains(int &data);
	//Delete Node using key
	void erase(int data);
	//Delete all Node's except root
	void clear();
	//Find using key (Node address)
	TreeNode* find(int &data);
	//Inorder traversal
	void inorder();
	//Preorder traversal
	void preorder();
	//Postorder traversal
	void postorder();
	//Levelorder
	void levelorder();
	//Operator copy assignment (=)
	BinaryTree& operator=( BinaryTree& rhs);
	//Operator stream out(<<)
	friend std::ostream& operator<<(std::ostream& out, const BinaryTree& tmp);
	

};

