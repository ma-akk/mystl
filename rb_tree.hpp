#ifndef RB_TREE_HPP
#define RB_TREE_HPP

#include <iostream>
#include <string>
#include <exception>
#include <cmath>
#include <limits>
#include "utils.hpp"
#include "Node.hpp"

#define RED 1
#define BLACK 0

using std::cout;
using std::endl;

namespace ft {
	template < typename value_type >
	class rb_tree {
		bool color;
		Node <value_type> *_root;
		Node <value_type> *_nil;

	 	rb_tree(value_type value = value_type()) : parent(NULL), left(NULL), rigth(NULL), color = BLACK { }

		rb_tree(const rb_tree &rb_tree) {
			cout << "copy constructor " << endl;
			if (this != &rb_tree) {
				color = rb_tree.color;
				parent = rb_tree.parent;
				left = rb_tree.left;
				rigth = rb_tree.rigth;
				value = rb_tree.value;
			}
		}

		rb_tree &operator=(const rb_tree &rb_tree) {
			cout << "operator = " << endl;
			if (this != &rb_tree) {
				color = rb_tree.color;
				parent = rb_tree.parent;
				left = rb_tree.left;
				rigth = rb_tree.rigth;
				value = rb_tree.value;
			}
			return *this;
		}

		//why is virtual destructor??
		virtual ~rb_tree();

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

		void left_rotate(rb_tree *root, rb_tree *nil) {
			rb_tree *child = this->rigth;
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

		void right_rotate(rb_tree *root, rb_tree *nil) {
			rb_tree *child = this->left;
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

		// void balance(rb_tree &rb_tree) {
		// 	if (rigth->color == RED && left->color == BLACK)
		// 		left_rotate();
		// 	if (left->color == RED && left->left->color == RED)
		// 		right_rotate();
		// 	if (left->color == RED && rigth->color == RED)
		// 		this->swap();
		// }
	};
}


#endif	//RB_TREE_HPP