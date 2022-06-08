#ifndef RB_TREE_HPP
#define RB_TREE_HPP

#include <iostream>
#include <string>
#include <exception>
#include <cmath>
#include <memory>
#include "utils.hpp"
#include "Node.hpp"

#define RED 1
#define BLACK 0

using std::cout;
using std::endl;

namespace ft {
	template < typename value_type, class Compare = std::less<value_type>, class Allocator = std::allocator<value_type> >
	class rb_tree {
	 public:
		typedef size_t							size_type;
		typedef std::ptrdiff_t					difference_type;
		typedef Compare							key_compare;
		typedef Allocator::pointer				pointer;
		typedef value_type&						reference;
	 	typedef const Allocator::pointer		const_pointer;
		typedef const value_type&				const_reference;
	 	typedef ran_it< T >						iterator;
		typedef ran_it< const T >				const_iterator;
		typedef reverse_it< iterator >			reverse_iterator;
		typedef reverse_it< const iterator >	const_reverse_iterator;
		

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

		//!!!!обращение к ключу в таком виде возможно, заменить на итераторы!!!
		// С++ - псевдокод
		void rb_insert_node(Node *node) {
			Node <const Key, T> *tmp1 = _root;
			Node <const Key, T> *tmp2 = _nil
			while (tmp1 != _nil) {
				tmp2 = tmp1;
				if (node->key < tmp1->key)
					tmp1 = tmp1->left;
				else
					tmp1 = tmp1->rigth;
			}
			node->parent = tmp2;
			if (tmp2 == _nil)
				_root = node;
			else if (node->key < tmp2->key)
				tmp2->left = node;
			else
				tmp2->rigth = node;
			node->left = _nil;
			node->rigth = _nil;
			node->color = RED;
			rb_insert_balance(node);
		}

		//проверить, как работает else {}
		//возможно стоит перенести все в класс Node
		void rb_insert_balance(Node *node) {
			Node <const Key, T> *tmp = _root;
			while (node->parent->color == RED) {
				if (node->parent == node->parent->parent->left) {
					tmp = node->parent->parent->rigth;
					if (tmp->color == RED) {
						node->parent->color = BLACK;
						tmp->color = BLACK;
						node->parent->parent->color = RED;
						node = node->parent->parent;
					} else {
						if (node == node->parent->rigth) {
							node = node->parent;
							node->left_rotate(_root, _nil);
						}
						node->parent->color = BLACK;
						node->parent->parent->color = RED;
						node->parent->parent->rigth_rotate(_root, _nil);
					}
				}
				else {
					tmp = node->parent->parent->left;
					if (tmp->color == RED) {
						node->parent->color = BLACK;
						tmp->color = BLACK;
						node->parent->parent->color = RED;
						node = node->parent->parent;
					} else {
						if (node == node->parent->left) {
							node = node->parent;
							node->rigth_rotate(_root, _nil);
						}
						node->parent->color = BLACK;
						node->parent->parent->color = RED;
						node->parent->parent->left_rotate(_root, _nil);
					}
				}
			}
			_root->color = BLACK;
		}

		Node *rb_min(Node *node) {
			Node *tmp = node;
			while (tmp->left != _nil)
				tmp = tmp->left;
			return tmp;
		}

		void rb_transplant(Node *u, Node *v) {
			if (u->parent == _nil)
				_root = v;
			else if(u == u->parent->left)
				u->parent->left = v;
			else
				u->parent->rigth = v;
			v->parent = u->parent;
		}

		void rb_delete(Node *node) {
			Node *x; 
			Node *tmp = node;
			bool tmp_orig_color = tmp->color;

			if (node->left == _nil) {
				x = node->rigth;
				rb_transplant(node, node->rigth);
			} else if (node->rigth == _nil) {
				x = node->left;
				rb_transplant(node, node->left);
			} else {
				tmp = rb_min(node->rigth);
				tmp_orig_color = tmp->color;
				x = tmp->rigth;
				if (tmp->parent == node) {
					x->parent = tmp;
				} else {
					rb_transplant(tmp, tmp->rigth);
					tmp->rigth = node->rigth;
					tmp->rigth->parent = tmp;
				}
				rb_transplant(node, tmp);
				tmp->left = node->left;
				tmp->left->parent = tmp;
				tmp->color = node->color;
			}
			if (tmp_orig_color == BLACK)
				rb_delete_balance(x);
		}

		void rb_delete_balance(Node *node) {
			Node *tmp;
			while (node != _root && node->color == BLACK) {
				if (node == node->parent->left) {
					tmp = node->parent->rigth;
					if (tmp->color == RED) {
						tmp->color = BLACK;
						node->parent->color = RED;
						node->parent->left_rotate(_root, _nil);
						tmp = node->parent->rigth;
					}
					if (tmp->left->color == BLACK && tmp->rigth->color == BLACK) {
						tmp->color = RED;
						node = node->parent;
					} else {
						if (tmp->rigth->color == BLACK) {
							tmp->left->color = BLACK;
							tmp->color = RED;
							tmp->rigth_rotate(_root, _nil);
							tmp = node->parent->rigth;
						}
						tmp->color = node->parent->color;
						node->parent->color = BLACK;
						tmp->rigth->color = BLACK;
						node->parent->left_rotate(_root, _nil);
						node = _root;
					}
				} else {
					tmp = node->parent->left;
					if (tmp->color == RED) {
						tmp->color = BLACK;
						node->parent->color = RED;
						node->parent->rigth_rotate(_root, _nil);
						tmp = node->parent->left;
					}
					if (tmp->rigth->color == BLACK && tmp->left->color == BLACK) {
						tmp->color = RED;
						node = node->parent;
					} else {
						if (tmp->left->color == BLACK) {
							tmp->rigth->color = BLACK;
							tmp->color = RED;
							tmp->left_rotate(_root, _nil);
							tmp = node->parent->left;
						}
						tmp->color = node->parent->color;
						node->parent->color = BLACK;
						tmp->left->color = BLACK;
						node->parent->rigth_rotate(_root, _nil);
						node = _root;
					}
				}
			}
			node->color = BLACK;
		}

	 private:
		Node <value_type> *_root;
		Node <value_type> *_nil;
	};
}


#endif	//RB_TREE_HPP