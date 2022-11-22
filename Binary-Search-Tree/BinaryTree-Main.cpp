#include <iostream>
#include <initializer_list>
#include "BinaryTree.h"
//#include "TreeNode.h"


int main()
{
	BinaryTree<int> x({5,4,9,15,8});
	BinaryTree<int> y;
	BinaryTree<int> z;
	x.erase(5);
	y.insert(1);
	z = x + y;
	std::cout << z;
	std::cout << std::endl;
	BinaryTree<char>g({ 's', 'g', 'e' });
	g.inorder();
	g.clear();
	std::cout << g;


	return 0;
}
