#ifndef NODE_HPP
#define NODE_HPP

#include <iostream>
#include <string>
#include <exception>
#include <cmath>
#include <limits>
#include "utils.hpp"

using std::cout;
using std::endl;

//leaf - "нулевая" нода

namespace ft {
	template < class Key, class T >
	class Node {
	 public:

		Node(Key key, T value, Node *parent) {
			_parent = parent;
			_pair = make_pair<const Key, T>(const_cast<Key>(key), value);
			_left; //leaf
			_rigth; //leaf

		}
		Node(const Node &node);
		Node &operator=(const Node &node);
		~Node();

		void left_rotate(Node &node);
		void right_rotate(Node &node);
		void swap(Node &node);
		void balance(Node &node);

	 private:
		Node() { }
		bool _red;
		Node *_parent;
		Node *_left;
		Node *_rigth;
		pair<const Key, T > _pair;
	};
}


#endif	//NODE_HPP