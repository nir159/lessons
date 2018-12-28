#include "BSNode.h"

BSNode::~BSNode() {
	if (_left) {
		_left->~BSNode();
	}
	if (_right) {
		_right->~BSNode();
	}
}

BSNode::BSNode(string data) : _data(data), _left(NULL), _right(NULL){}

BSNode::BSNode(const BSNode& other) : _data(other.getData()){
	if (other.getLeft()) {
		_left = new BSNode(*other.getLeft());
	}
	if (other.getRight()) {
		_right = new BSNode(*other.getRight());
	}
}

// operator = override 
BSNode& BSNode::operator=(const BSNode& other) {
	_data = other.getData();
	if (other.getLeft()) {
		_left = new BSNode(*other.getLeft());
	}
	if (other.getRight()) {
		_right = new BSNode(*other.getRight());
	}
	return *this;
}

// Function returns true if node has no child
bool BSNode::isLeaf() const {
	return !(_right || _left);
}

// Function will insert a value to the binary tree
void BSNode::insert(string value) {
	if (_data.compare(value) > NULL) {
		if (_left && _left->getData().compare(value) != NULL) {
			_left->insert(value);
		}
		else if (!_left) {
			_left = new BSNode(value);
		}
		
	}
	else if (_data.compare(value) < NULL) {
		if (_right && _right->getData().compare(value) != NULL) {
			_right->insert(value);
		}
		else if (!_right) {
			_right = new BSNode(value);
		}
	}
}

// Function will return true if val exists in the tree or subtree
bool BSNode::search(string val) const {
	if (_data.compare(val) == NULL) {
		return true;
	}
	else if (_right && _right->search(val)) {
		return true;
	}
	else if (_left && _left->search(val)) {
		return true;
	}
	return false;
}

// Function returns the height of the tree or subtree
int BSNode::getHeight() const {
	if (!(_right || _left)) {
		return LEAF_HEIGHT;
	}
	if (_right && _left)
	{
		if (_right->getHeight() > _left->getHeight()) {
			return _right->getHeight() + LEAF_HEIGHT;
		}
		return _left->getHeight() + LEAF_HEIGHT;
	}
	else if (_left) {
		return _left->getHeight() + LEAF_HEIGHT;
	}
	return _right->getHeight() + LEAF_HEIGHT;
}

// Getters
string BSNode::getData() const {
	return _data;
}

BSNode* BSNode::getLeft() const {
	return _left;
}

BSNode* BSNode::getRight() const {
	return _right;
}