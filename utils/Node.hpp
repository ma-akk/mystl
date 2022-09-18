#ifndef NODE_HPP
#define NODE_HPP

#include <cmath>
#include <exception>
#include <iostream>
#include <limits>
#include <string>

#include "utils.hpp"

#define RED 1
#define BLACK 0

using std::cout;
using std::endl;

namespace ft {
template <typename value_type>
struct Node {
	bool color;
	Node *parent;
	Node *left;
	Node *right;
	value_type value;

	Node(value_type value = value_type())
		: color(BLACK), parent(NULL), left(NULL), right(NULL), value(value) {}

	Node(const Node &node) :  value(node.value) {
		if (this != &node) {
			color = node.color;
			parent = node.parent;
			left = node.left;
			right = node.right;
		}
	}

	Node &operator=(const Node &node) {
		if (this != &node) {
			color = node.color;
			parent = node.parent;
			left = node.left;
			right = node.right;
			value = node.value;
		}
		return *this;
	}

	virtual ~Node() {
		// cout << "destructor node" << endl;
	}

	bool is_leaf() const {
		if (this->left == NULL && this->right == NULL) {
			return 1;
		}
		return 0;
	}
};
}  // namespace ft

#endif	// NODE_HPP