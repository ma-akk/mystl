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
	template < class Key, class T >
	class Node {
	 public:

		/* using for only null-node */
	 	Node() {
			 _parent = NULL;
			 _left = NULL;
			 _rigth =NULL;
			 _color = BLACK;
		}

		Node(Key key, T value, Node *parent, Node *leaf) 
			: _parent(parent), _left(leaf), _rigth(leaf) {
			_pair = make_pair<const Key, T>(const_cast<Key>(key), value);
			_color = RED;
		}

		Node(Key key, T value, Node *parent, Node *left, Node *right) 
			: _parent(parent), _left(left), _rigth(right) {
			_pair = make_pair<const Key, T>(const_cast<Key>(key), value);
			_color = RED;
		}

		Node(const Node &node) {
			cout << "copy constructor " << endl;
			if (this != &node) {
				_color = node._color;
				_parent = node._parent;
				_left = node._left;
				_rigth = node._rigth;
				_pair = pair(node._pair);
			}
		}

		Node &operator=(const Node &node) {
			cout << "operator = " << endl;
			if (this != &node) {
				_color = node._color;
				_parent = node._parent;
				_left = node._left;
				_rigth = node._rigth;
				_pair = pair(node._pair);
			}
			return *this;
		}

		~Node();


		bool is_root() const {
			if (this->_parent->parent == NULL)
				return 1;
			return 0;
		}

		bool is_leaf() const {
			if (this->_parent == NULL)
				return 1;
			return 0;
		}

		//rotate without color
		void left_rotate(Node *root, Node *nil) {
			Node *child = this->_rigth;
			this->_rigth = child->_left;
			if(child->_left != nil)
				child->_left->_parent = this;
			if(this->_parent == nil)
				root = child;
			else if (this == this->_parent->_left)
				this->_parent->_left = child;
			else
				this->_parent->_rigth = child;
			child->_left = this;
			this->_parent = child;
		}

		//rotate without color
		void right_rotate(Node *root, Node *nil) {
			Node *child = this->_left;
			this->_left = child->_rigth;
			if(child->_rigth != nil)
				child->_rigth->_parent = this;
			if(this->_parent == nil)
				root = child;
			else if (this == this->_parent->_left)
				this->_parent->_left = child;
			else
				this->_parent->_rigth = child;
			child->_rigth = this;
			this->_parent = child;
		}

		void swap() {
			this->_left->_color = BLACK;
			this->_rigth->_color = BLACK;
			this->_color = this->is_root ? BLACK : RED;
		}

		void balance(Node &node) {
			if (_rigth->_color == RED && _left->_color == BLACK)
				left_rotate();
			if (_left->_color == RED && _left->_left->_color == RED)
				right_rotate();
			if (_left->_color == RED && _rigth->_color == RED)
				swap();
		}

	 private:
		bool _color;
		Node *_parent;
		Node *_left;
		Node *_rigth;
		pair<const Key, T > _pair;
	};
}


#endif	//NODE_HPP