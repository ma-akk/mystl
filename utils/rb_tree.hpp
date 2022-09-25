#ifndef RB_TREE_HPP
#define RB_TREE_HPP

#include <memory>

#include "../iterators/reverse_tree_it.hpp"
#include "../iterators/tree_it.hpp"
#include "utils.hpp"

#define RED 1
#define BLACK 0

using std::cout;
using std::endl;
using std::cerr;

namespace ft {
template <typename value_type, class Compare = std::less<value_type>,
		  class Allocator = std::allocator<value_type> >
class rb_tree {

 public:
	typedef size_t size_type;
	typedef std::ptrdiff_t difference_type;
	typedef Compare key_compare;
	typedef Allocator allocator_type;
	typedef typename Allocator::template rebind<Node<value_type> >::other
		node_allocator;
	typedef typename node_allocator::pointer node_pointer;
	typedef typename allocator_type::pointer pointer;
	typedef typename allocator_type::reference reference;
	typedef typename allocator_type::const_pointer const_pointer;
	typedef typename allocator_type::const_reference const_reference;
	typedef tree_it<value_type> iterator;
	typedef tree_it<const value_type> const_iterator;
	typedef reverse_tree_it<value_type> reverse_iterator;
	typedef reverse_tree_it<const value_type> const_reverse_iterator;

 private:
	node_pointer _nil;
	node_pointer _root;
	allocator_type _value_alloc;
	node_allocator _node_alloc;
  	key_compare _compare;
	size_type _size;

 public:
	node_pointer init_node(value_type v = value_type()) {
		node_pointer node = NULL;
		try {
			node = _node_alloc.allocate(1);
		} catch (std::bad_alloc const&) {
			cerr << "Bad allocate exception" << endl;
		}
		_node_alloc.construct(node, Node<value_type>(v));
		return node;
	}

	void free_node(node_pointer node) {
		if (node != NULL) {
			_node_alloc.destroy(node);
			_node_alloc.deallocate(node, 1);
			node = NULL;
		}
	}

	void init_tree() {
		_nil = init_node();
		_root = _nil;
		_root->parent = _nil;
	}

	/* consructors */
	rb_tree() : _size(0) {
        init_tree();
    }

	explicit rb_tree(const Compare& comp, const Allocator& alloc = Allocator())
		: _node_alloc(alloc), _compare(comp), _size(0) {
        init_tree();
	}

	template <class InputIt>
	rb_tree(InputIt first, InputIt last, const Compare& comp = Compare(),
			const Allocator& alloc = Allocator())
		: _node_alloc(alloc), _compare(comp), _size(0) {
		init_tree();
		InputIt it = first;
		for (; it != last; ++it) insert(*it);
	}

    rb_tree(const rb_tree& value) : _node_alloc(value._node_alloc),
            _compare(value._compare), _size(value._size) {
        *this = value;
    }

	rb_tree& operator=(const rb_tree& value) {
		if (this != &value) {
			clear();
            _value_alloc = value._value_alloc;
            _node_alloc = value._node_alloc;
            _compare = value._compare;
			for(const_iterator it = value.begin(); it != value.end(); ++it) {
				insert(*it);
			}
		}
		return *this;
	}

	/* destructor */
	~rb_tree() {
		clear_tree(_root);
		free_node(_nil);
	}

	/* methods of rotate around node */
	void left_rotate(node_pointer node) {
		node_pointer child = node->right;
		node->right = child->left;
		if (child->left != _nil) child->left->parent = node;
		child->parent = node->parent;
		if (node->parent == _nil)
			_root = child;
		else if (node == node->parent->left)
			node->parent->left = child;
		else
			node->parent->right = child;
		child->left = node;
		node->parent = child;
	}

	void right_rotate(node_pointer node) {
		node_pointer child = node->left;
		node->left = child->right;
		if (child->right != _nil) child->right->parent = node;
		child->parent = node->parent;
		if (node->parent == _nil)
			_root = child;
		else if (node == node->parent->left)
			node->parent->left = child;
		else
			node->parent->right = child;
		child->right = node;
		node->parent = child;
	}

	/* methods of transformation of tree */
	void rb_insert_node(node_pointer node) {
		node_pointer tmp1 = _root;
		node_pointer tmp2 = _nil;
		while (tmp1 != _nil) {
			tmp2 = tmp1;
			if (_compare(node->value, tmp1->value))
				tmp1 = tmp1->left;
			else
				tmp1 = tmp1->right;
		}
		node->parent = tmp2;
		if (tmp2 == _nil)
			_root = node;
		else if (_compare(node->value, tmp2->value))
			tmp2->left = node;
		else
			tmp2->right = node;
		node->left = _nil;
		node->right = _nil;
		node->color = RED;
		++_size;
		rb_insert_balance(node);
	}

	void rb_insert_balance(node_pointer node) {
		node_pointer tmp = _root;
		while (node->parent->color == RED) {
			if (node->parent == node->parent->parent->left) {
				tmp = node->parent->parent->right;
				if (tmp->color == RED) {
					node->parent->color = BLACK;
					tmp->color = BLACK;
					node->parent->parent->color = RED;
					node = node->parent->parent;
				} else {
					if (node == node->parent->right) {
						node = node->parent;
						left_rotate(node);
					}
					node->parent->color = BLACK;
					node->parent->parent->color = RED;
					right_rotate(node->parent->parent);
				}
			} else {
				tmp = node->parent->parent->left;
				if (tmp->color == RED) {
					node->parent->color = BLACK;
					tmp->color = BLACK;
					node->parent->parent->color = RED;
					node = node->parent->parent;
				} else {
					if (node == node->parent->left) {
						node = node->parent;
						right_rotate(node);
					}
					node->parent->color = BLACK;
					node->parent->parent->color = RED;
					left_rotate(node->parent->parent);
				}
			}
		}
		_root->color = BLACK;
	}

	void rb_transplant(node_pointer u, node_pointer v) {
		if (u->parent == _nil)
			_root = v;
		else if (u == u->parent->left)
			u->parent->left = v;
		else
			u->parent->right = v;
		v->parent = u->parent;
	}

	void rb_delete(node_pointer node) {
		node_pointer x;
		node_pointer tmp = node;
		bool tmp_orig_color = tmp->color;
		if (node->left == _nil) {
			x = node->right;
			rb_transplant(node, node->right);
		} else if (node->right == _nil) {
			x = node->left;
			rb_transplant(node, node->left);
		} else {
			tmp = rb_min(node->right);
			tmp_orig_color = tmp->color;
			x = tmp->right;
			if (tmp->parent == node) {
				x->parent = tmp;
			} else {
				rb_transplant(tmp, tmp->right);
				tmp->right = node->right;
				tmp->right->parent = tmp;
			}
			rb_transplant(node, tmp);
			tmp->left = node->left;
			tmp->left->parent = tmp;
			tmp->color = node->color;
		}
		--_size;
		if (tmp_orig_color == BLACK) rb_delete_balance(x);
	}

	void rb_delete_balance(node_pointer node) {
		node_pointer tmp;
		while (node != _root && node->color == BLACK) {
			if (node == node->parent->left) {
				tmp = node->parent->right;
				if (tmp->color == RED) {
					tmp->color = BLACK;
					node->parent->color = RED;
					left_rotate(node->parent);
					tmp = node->parent->right;
				}
				if (tmp->left->color == BLACK && tmp->right->color == BLACK) {
					tmp->color = RED;
					node = node->parent;
				} else {
					if (tmp->right->color == BLACK) {
						tmp->left->color = BLACK;
						tmp->color = RED;
						right_rotate(tmp);
						tmp = node->parent->right;
					}
					tmp->color = node->parent->color;
					node->parent->color = BLACK;
					tmp->right->color = BLACK;
					left_rotate(node->parent);
					node = _root;
				}
			} else {
				tmp = node->parent->left;
				if (tmp->color == RED) {
					tmp->color = BLACK;
					node->parent->color = RED;
					right_rotate(node->parent);
					tmp = node->parent->left;
				}
				if (tmp->right->color == BLACK && tmp->left->color == BLACK) {
					tmp->color = RED;
					node = node->parent;
				} else {
					if (tmp->left->color == BLACK) {
						tmp->right->color = BLACK;
						tmp->color = RED;
						left_rotate(tmp);
						tmp = node->parent->left;
					}
					tmp->color = node->parent->color;
					node->parent->color = BLACK;
					tmp->left->color = BLACK;
					right_rotate(node->parent);
					node = _root;
				}
			}
		}
		node->color = BLACK;
	}

	allocator_type get_allocator() const { return _value_alloc; }

	size_t max_size() const { return _value_alloc.max_size(); }

	bool empty() const { return _size == 0 ? 1 : 0; }

	size_t size() const { return _size; }

	node_pointer rb_min(node_pointer node) const {
		node_pointer tmp = node;
		while (tmp != _nil && tmp->left != _nil) tmp = tmp->left;
		return tmp;
	}

	node_pointer rb_max(node_pointer node) const {
		node_pointer tmp = node;
		while (tmp != _nil && tmp->right != _nil) tmp = tmp->right;
		return tmp;
	}

	/* methods of print tree from @lelle */
	void printBT(const std::string& prefix, const node_pointer nodeV,
				 bool isLeft) const {
		std::cout << prefix;
		std::cout << (isLeft ? "├──" : "└──");
		if (nodeV == _nil) {
			std::cout << "\033[0;36m"
					  << "nil"
					  << "\033[0m" << endl;
			return;
		}
		// print the value of the node
		if (nodeV->color == 0)
			cout << "\033[0;36m" << nodeV->value.first << "\033[0m" << endl;
		else
			cout << "\033[0;31m" << nodeV->value.first << "\033[0m" << endl;
		printBT(prefix + (isLeft ? "│   " : "    "), nodeV->left, true);
		printBT(prefix + (isLeft ? "│   " : "    "), nodeV->right, false);
	}

	void printTree() { printBT("", _root, false); }

	void clear_tree(node_pointer node) {
		if (_nil != NULL && node != _nil) {
			clear_tree(node->left);
			clear_tree(node->right);
			free_node(node);
            node = NULL;
		}
	}

	void clear() {
		clear_tree(_root);
        _root = _nil;
        _root->parent = _nil;
		_size = 0;
	}

	node_pointer tree_search(node_pointer root, value_type key) const {
		if (root == _nil ||
			(!_compare(key, root->value) && !_compare(root->value, key))) {
			return root;
		}
		if (_compare(key, root->value))
			return tree_search(root->left, key);
		else
			return tree_search(root->right, key);
	}

	iterator begin() { return iterator(rb_min(_root)); }

	const_iterator begin() const { return const_iterator(rb_min(_root)); }

	iterator end() { return iterator(_nil); }

	const_iterator end() const { return const_iterator(_nil); }

	reverse_iterator rbegin() { return reverse_iterator(rb_max(_root)); }

	const_reverse_iterator rbegin() const {
		return const_reverse_iterator(rb_max(_root));
	}

	reverse_iterator rend() { return reverse_iterator(_nil); }

	const_reverse_iterator rend() const {
		return const_reverse_iterator(_nil);
	}

	/*modify*/
	ft::pair<iterator, bool> insert(const value_type& value) {
		iterator res = find(value);
		if (res.get_node() != _nil)
			return ft::make_pair<iterator, bool>(res, false);
		else {
			node_pointer node = init_node(value);
			rb_insert_node(node);
			return ft::make_pair<iterator, bool>(iterator(node), true);
		}
	}

	template <class InputIt>
	void insert(InputIt first, InputIt last) {
		for (InputIt it = first; it != last; ++it) {
			insert(*it);
		}
	}

	iterator insert(iterator hint, const value_type& value) {
		(void)hint;
		node_pointer node = tree_search(_root, value);
		if (node != _nil)
			return iterator(node);
		else {
			node = init_node(value);
			rb_insert_node(node);
			return iterator(node);
		}
	}

	size_t erase_node(node_pointer node) {
		if (node == _nil) return 0;
		rb_delete(node);
		free_node(node);
		return 1;
	}

	size_t erase(iterator pos) {
		node_pointer node = pos.get_node();
		return erase_node(node);
	}

	void erase(iterator first, iterator last) {
		for (iterator it = first; it != last; ) {
			erase((it++));
		}
	}

	void swap(rb_tree& other) {
		std::swap(this->_root, other._root);
		std::swap(this->_nil, other._nil);
		std::swap(this->_size, other._size);
		std::swap(this->_node_alloc, other._node_alloc);
		std::swap(this->_value_alloc, other._value_alloc);
		std::swap(this->_compare, other._compare);
	}

	/* lookup */
	size_type count(const value_type& key) const {
		return tree_search(_root, key) != _nil ? 1 : 0;
	}

	iterator find(const value_type& key) {
		return iterator(tree_search(_root, key));
	}

	const_iterator find(const value_type& key) const {
		return const_iterator(tree_search(_root, key));
	}

	ft::pair<iterator, iterator> equal_range(const value_type& key) {
		return ft::pair<iterator, iterator>(lower_bound(key), upper_bound(key));
	}

	ft::pair<const_iterator, const_iterator> equal_range(
		const value_type& key) const {
		return ft::pair<iterator, iterator>(lower_bound(key), upper_bound(key));
	}

	iterator lower_bound(const value_type& key) {
		iterator it = begin();
		while (it != end() && _compare(*it, key))
			++it;
		return it;
	}

	const_iterator lower_bound(const value_type& key) const {
		const_iterator it = begin();
		while (it != end() &&
			   _compare(*it, key))
			++it;
		return it;
	}

	iterator upper_bound(const value_type& key) {
		iterator it = begin();
		while (it != end() &&
			   _compare(*it, key))
			++it;
		if (!(_compare(it.get_node()->value, key) ||
			  _compare(key, it.get_node()->value)))
			++it;
		return it;
	}

	const_iterator upper_bound(const value_type& key) const {
		const_iterator it = begin();
		while (it != end() &&
			   (_compare(it.get_node()->value, key) ||
				_compare(key, *it)))
			++it;
		return it;
	}

  	key_compare value_comp() const { return _compare; }

	friend bool operator<(const rb_tree<value_type, Compare, Allocator>& lhs,
			   const rb_tree<value_type, Compare, Allocator>& rhs) {
		return (ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(),
									rhs.end()));
	}

	friend bool operator==(const rb_tree<value_type, Compare, Allocator>& lhs,
				const rb_tree<value_type, Compare, Allocator>& rhs) {
		return (lhs.size() == rhs.size() &&
			ft::equal(lhs.begin(), lhs.end(), rhs.begin()));
	}
};

template <typename value_type, class Compare, class Alloc>
void swap(rb_tree<value_type, Compare, Alloc>& lhs,
		  rb_tree<value_type, Compare, Alloc>& rhs) {
	lhs.swap(rhs);
}

}  // namespace ft

#endif	// RB_TREE_HPP