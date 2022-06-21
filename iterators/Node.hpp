#ifndef NODE_HPP
#define NODE_HPP

#include <iostream>
#include <string>
#include <exception>
#include <cmath>
#include <limits>
#include "utils.hpp"

#define RED 1
#define BLACK 0

using std::cout;
using std::endl;

namespace ft {
	template < typename value_type >
	struct Node {
		bool color;
		Node *parent;
		Node *left;
		Node *rigth;
		value_type value;

	 	Node(value_type value = value_type()) : parent(NULL), left(NULL), rigth(NULL), color = BLACK { }

		Node(const Node &node) {
			cout << "copy constructor " << endl;
			if (this != &node) {
				color = node.color;
				parent = node.parent;
				left = node.left;
				rigth = node.rigth;
				value = node.value;
			}
		}

		Node &operator=(const Node &node) {
			cout << "operator = " << endl;
			if (this != &node) {
				color = node.color;
				parent = node.parent;
				left = node.left;
				rigth = node.rigth;
				value = node.value;
			}
			return *this;
		}

		//why is virtual destructor??
		virtual ~Node();

		bool is_root() const {
			if (this->parent->parent == NULL)
				return 1;
			return 0;
		}

		bool is_leaf() const {
			if (this->parent == NULL)
				return 1;
			return 0;
		}

	};
}


#endif	//NODE_HPP