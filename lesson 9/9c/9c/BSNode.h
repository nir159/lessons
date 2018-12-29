#ifndef BSNode_H
#define BSNode_H
#define LEAF_HEIGHT 1

#include <iostream>
#include <string>

using namespace std;

template <class T>
class BSNode
{
public:
	BSNode<T>::BSNode(T data);
	BSNode<T>(const BSNode<T>& other);

	BSNode<T>::~BSNode();

	void BSNode<T>::insert(T value);
	T& BSNode<T>::operator=(const T& other);

	bool BSNode<T>::isLeaf() const;
	string BSNode<T>::getData() const;
	BSNode* BSNode<T>::getLeft() const;
	BSNode* BSNode<T>::getRight() const;

	bool BSNode<T>::search(string val) const;

	int BSNode<T>::getHeight() const;
	int BSNode<T>::getDepth(const BSNode<T>& root) const;

	void BSNode<T>::printNodes() const; //for question 1 part C

private:
	T _data;
	BSNode* _left;
	BSNode* _right;

	int _count;
	int BSNode<T>::getCurrNodeDistFromInputNode(const T* node) const; //auxiliary function for getDepth

};

#endif

template <class T>
BSNode<T>::~BSNode() {
	if (_left) {
		_left->~BSNode();
	}
	if (_right) {
		_right->~BSNode();
	}
}

template <class T>
BSNode<T>::BSNode(T data) : _count(1), _data(data), _left(NULL), _right(NULL) {}

template <class T>
BSNode<T>::BSNode(const BSNode<T>& other) : _data(other.getData()) {
	if (other.getLeft()) {
		_left = new BSNode<T>(*other.getLeft());
	}
	if (other.getRight()) {
		_right = new BSNode<T>(*other.getRight());
	}
}

// operator = override 
template <class T>
T& BSNode<T>::operator=(const T& other) {
	_data = other.getData();
	if (other.getLeft()) {
		_left = new BSNode<T>(*other.getLeft());
	}
	if (other.getRight()) {
		_right = new BSNode<T>(*other.getRight());
	}
	return *this;
}

// Function returns true if node has no child
template <class T>
bool BSNode<T>::isLeaf() const {
	return !(_right || _left);
}

// Function will insert a value to the binary tree
template <class T>
void BSNode<T>::insert(T value) {
	if (_data == value) {
		_count++;
	}
	if (_data > value) {
		if (_left) {
			_left->insert(value);
		}
		else if (!_left) {
			_left = new BSNode<T>(value);
		}

	}
	else if (_data < value) {
		if (_right) {
			_right->insert(value);
		}
		else if (!_right) {
			_right = new BSNode<T>(value);
		}
	}
}

// Function will return true if val exists in the tree or subtree
template <class T>
bool BSNode<T>::search(string val) const {
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
template <class T>
int BSNode<T>::getHeight() const {
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
template <class T>
int BSNode<T>::getDepth(const BSNode<T>& root) const {
	return root.getCurrNodeDistFromInputNode(this);
}

// Function will return the level of how deep the current node is from parameter root
template <class T>
int BSNode<T>::getCurrNodeDistFromInputNode(const T* node) const {
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
template <class T>
void BSNode<T>::printNodes() const {
	if (_left) {
		_left->printNodes();
	}
	std::cout << _data << " " << _count << std::endl;
	if (_right) {
		_right->printNodes();
	}
}

// Getters
template <class T>
string BSNode<T>::getData() const {
	return _data;
}

template <class T>
BSNode<T>* BSNode<T>::getLeft() const {
	return _left;
}

template <class T>
BSNode<T>* BSNode<T>::getRight() const {
	return _right;
}