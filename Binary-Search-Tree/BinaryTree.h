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
	/*void level(TreeNode* root, int level_no);*/
	void postorder(TreeNode* node);
	TreeNode* copy(TreeNode* node);
	void print(std::ostream& ost, TreeNode* curr) const;
public:
	TreeNode* root;
	int nodeCount;
	BinaryTree();
	BinaryTree(int data);
	BinaryTree(std::initializer_list<int> list);
	BinaryTree(BinaryTree& Tree);
	~BinaryTree();
	void Insert(int data);
	void Print_Tree(TreeNode* node);
	void Print();
	int get_number_of_nodes();
	int get_root_data();
	int get_height();
	bool contains(int data);
	void erase(int data);
	void clear();
	TreeNode* find(int data);
	void inorder();
	void preorder();
	void postorder();
	void levelorder();
	BinaryTree& operator=( BinaryTree& rhs);
	friend std::ostream& operator<<(std::ostream& out, const BinaryTree& tmp);
	

};

