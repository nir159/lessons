#include "BSNode.h"

BSNode::~BSNode() {
	if (_left) {
		_left->~BSNode();
	}
	if (_right) {
		_right->~BSNode();
	}
}

BSNode::BSNode(string data) : _count(1), _data(data), _left(NULL), _right(NULL){}

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
	if (_data.compare(value) == NULL) {
		_count++;
	}
	if (_data.compare(value) > NULL) {
		if (_left) {
			_left->insert(value);
		}
		else if (!_left) {
			_left = new BSNode(value);
		}
		
	}
	else if (_data.compare(value) < NULL) {
		if (_right) {
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

// Function will return the level of how deep the current node is compared to parameter root
int BSNode::getDepth(const BSNode& root) const {
	return root.getCurrNodeDistFromInputNode(this);
}

// Function will return the level of how deep the current node is from parameter root
int BSNode::getCurrNodeDistFromInputNode(const BSNode* node) const {
	if (!search(node->getData())) {
		return -1;
	}
	if (_data.compare(node->getData()) == NULL) {
		return NULL;
	}
	else if (_data.compare(node->getData()) > NULL) {
		return _left->getCurrNodeDistFromInputNode(node) + LEAF_HEIGHT;
	}
	return _right->getCurrNodeDistFromInputNode(node) + LEAF_HEIGHT;
}

// Function will print the tree tree travel method: inorder
void BSNode::printNodes() const {
	if (_left) {
		_left->printNodes();
	}
	std::cout << _data << " " << _count << std::endl;
	if (_right) {
		_right->printNodes();
	}
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