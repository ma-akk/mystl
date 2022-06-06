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

		void left_rotate(Node *root, Node *nil) {
			Node *child = this->rigth;
			this->rigth = child->left;
			if(child->left != nil)
				child->left->parent = this;
			if(this->parent == nil)
				root = child;
			else if (this == this->parent->left)
				this->parent->left = child;
			else
				this->parent->rigth = child;
			child->left = this;
			this->parent = child;
		}

		void right_rotate(Node *root, Node *nil) {
			Node *child = this->left;
			this->left = child->rigth;
			if(child->rigth != nil)
				child->rigth->parent = this;
			if(this->parent == nil)
				root = child;
			else if (this == this->parent->left)
				this->parent->left = child;
			else
				this->parent->rigth = child;
			child->rigth = this;
			this->parent = child;
		}

		// void swap() {
		// 	this->left->color = BLACK;
		// 	this->rigth->color = BLACK;
		// 	this->color = this->is_root ? BLACK : RED;
		// }

		// void balance(Node &Node) {
		// 	if (rigth->color == RED && left->color == BLACK)
		// 		left_rotate();
		// 	if (left->color == RED && left->left->color == RED)
		// 		right_rotate();
		// 	if (left->color == RED && rigth->color == RED)
		// 		this->swap();
		// }
	};
}


#endif	//NODE_HPP