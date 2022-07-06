#ifndef NODE_HPP
#define NODE_HPP

#include <iostream>
#include <string>
#include <exception>
#include <cmath>
#include <limits>
#include "../utils.hpp"

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
		Node *right;
		value_type value;

	 	Node(value_type value = value_type()) : parent(NULL), left(NULL), right(NULL), color(BLACK) { }

		Node(const Node &node) {
			cout << "copy constructor " << endl;
			if (this != &node) {
				color = node.color;
				parent = node.parent;
				left = node.left;
				right = node.right;
				value = node.value;
			}
		}

		Node &operator=(const Node &node) {
			cout << "operator = " << endl;
			if (this != &node) {
				color = node.color;
				parent = node.parent;
				left = node.left;
				right = node.right;
				value = node.value;
			}
			return *this;
		}

		virtual ~Node() { }

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

    //???????
    template < typename value_type>
    bool operator<( const Node<value_type>& lhs, const Node<value_type>& rhs ) {
        return lhs.value < rhs.value;
    };
}

#endif	//NODE_HPP