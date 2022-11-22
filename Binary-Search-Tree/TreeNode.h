#pragma once
template<class data_type>
class TreeNode
{
public:
	data_type key;
	TreeNode<data_type>* left;
	TreeNode<data_type>* right;
	TreeNode();
	TreeNode(data_type data);
};

template<class data_type>
TreeNode<data_type>::TreeNode()
{
	key = 0;
	left = nullptr;
	right = nullptr;
}
template<class data_type>
TreeNode<data_type>::TreeNode(data_type data)
{
	key = data;
	left = nullptr;
	right = nullptr;
}



	