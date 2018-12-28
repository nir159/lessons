#ifndef BSNode_H
#define BSNode_H
#define LEAF_HEIGHT 1

#include <string>

using namespace std;

class BSNode
{
public:
	BSNode(string data);
	BSNode(const BSNode& other);

	~BSNode();
	
	void insert(string value);
	BSNode& operator=(const BSNode& other);

	bool isLeaf() const;
	string getData() const;
	BSNode* getLeft() const;
	BSNode* getRight() const;

	bool search(string val) const;

	int getHeight() const;
	int getDepth(const BSNode& root) const;

	void printNodes() const; //for question 1 part C

private:
	string _data;
	BSNode* _left;
	BSNode* _right;

	int _count; 
	int BSNode::getCurrNodeDistFromInputNode(const BSNode* node) const; //auxiliary function for getDepth

};

#endif