#include "BSNode.h"
#include <iostream>
#include <fstream>
#include <string>
#include <windows.h>
#include "printTreeToFile.h"
using namespace std;


int main()
{
	BSNode* curr;
	BSNode* bs = new BSNode("6");
	bs->insert("2");
	bs->insert("8");
	bs->insert("3");
	bs->insert("5");
	bs->insert("9");
	bs->insert("6");
	bs->printNodes();


	cout << "Tree height: " << bs->getHeight() << endl;
	cout << "depth of node with 5 depth: " << bs->getLeft()->getRight()->getRight()->getDepth(*bs) << endl;
	cout << "depth of node with 3 depth: " << bs->getLeft()->getRight()->getDepth(*bs) << endl;

	string textTree = "BSTData.txt";
	printTreeToFile(bs, textTree);

	system("BinaryTree.exe");
	system("pause");
	remove(textTree.c_str());
	delete bs;
	system("PAUSE");
	return 0;
}
