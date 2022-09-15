#ifndef MAP_HPP
#define MAP_HPP

#include "iterators/tree_it.hpp"
#include "utils/rb_tree.hpp"
#include "utils/utils.hpp"

namespace ft {

template <class Key, class T, class Compare = std::less<Key>,
		  class Allocator = std::allocator<ft::pair<const Key, T> > >
class map {
   public:
	typedef Key key_type;
	typedef T mapped_type;
	typedef pair<const Key, T> value_type;
	typedef size_t size_type;
	typedef std::ptrdiff_t difference_type;
	typedef Compare key_compare;
	typedef Allocator allocator_type;
	typedef typename Allocator::pointer pointer;
	typedef value_type& reference;
	typedef typename Allocator::const_pointer const_pointer;
	typedef const value_type& const_reference;
	typedef tree_it<value_type> iterator;
	typedef tree_it<const value_type> const_iterator;
	typedef reverse_it<value_type> reverse_iterator;
	typedef reverse_it<const value_type> const_reverse_iterator;

	class value_compare {
	   public:
		Compare _comp;
		value_compare(Compare c) : _comp(c) {}

		bool operator()(const value_type& lhs, const value_type& rhs) const {
			return _comp(lhs.first, rhs.first);
		}
	};

	typedef rb_tree<value_type, value_compare, allocator_type> map_tree;

	/*constructors*/
	explicit map(const key_compare& comp = key_compare(), const Allocator& alloc = Allocator())
		: _tree(map_tree(comp, alloc)) {}

	template <class InputIt>
	map(InputIt first, InputIt last, const Compare& comp = Compare(),
		const Allocator& alloc = Allocator())
		: _tree(map_tree(first, last, comp, alloc)) {}

	map(const map& other) { this->_tree = map_tree(other._tree); }

	map& operator=(const map& other) {
		if (this != &other) {
			_tree.clear_tree();
			this->_tree = map_tree(other._tree);
		}
		return *this;
	}

	/*destructor*/
	~map() { _tree.clear_tree(_tree.get_root()); }

	/*access*/
	Allocator get_allocator() const {}

	T& at(const Key& key) {
		iterator it = _tree.find(make_pair(key, mapped_type()));
		if (it == _tree.end())
			throw std::out_of_range("range_check it >= size");
		return it->second;
	}

	const T& at(const Key& key) const {
		const_iterator it = _tree.find(make_pair(key, mapped_type()));
		if (it == _tree.end())
			throw std::out_of_range("range_check it >= size");
		return it->second;
	}

	// NEED TESTED
	T& operator[](const Key& key) {
		return insert(const ft::make_pair(key, T())).first->second;
	}

	/* iterators */
	iterator begin() { return _tree.begin(); }
	const_iterator begin() const { return _tree.begin(); }

	iterator end() { return _tree.end(); }

	const_iterator end() const { return _tree.end(); }

	reverse_iterator rbegin() { return _tree.rbegin(); }

	const_reverse_iterator rbegin() const { return _tree.rbegin(); }

	reverse_iterator rend() { return _tree.rend(); }

	const_reverse_iterator rend() const { return _tree.rend(); }

	/* capacity */
	bool empty() const { return _tree.empty(); }

	size_t size() const { return _tree.size(); }

	size_t max_size() const { return _tree.max_size(); }

	/*modify*/
	void clear() { _tree.clear(); }

	pair<iterator, bool> insert(const value_type& value) {
		return _tree.insert(value);
	}

	iterator insert(iterator hint, const value_type& value) {
		return _tree.insert(hint, value);
	}

	template <class InputIt>
	void insert(InputIt first, InputIt last) {
		_tree.insert(first, last);
	}

	void erase(iterator pos) { return _tree.erase(pos); }

	void erase(iterator first, iterator last) {
		return _tree.erase(first, last);
	}

	size_type erase(const Key& key) { return _tree.erase(key); }

	void swap(map& other) { _tree.swap(other); }

	/* lookup */
	size_type count(const Key& key) const {
		return _tree.count(make_pair(key, mapped_type()));
	}

	iterator find(const Key& key) {
		return _tree.find(make_pair(key, mapped_type()));
	}

	const_iterator find(const Key& key) const {
		return _tree.find(make_pair(key, mapped_type()));
	}

	pair<iterator, iterator> equal_range(const Key& key) {
		return _tree.equal_range(make_pair(key, mapped_type()));
	}
	pair<const_iterator, const_iterator> equal_range(const Key& key) const {
		return _tree.equal_range(make_pair(key, mapped_type()));
	}

	iterator lower_bound(const Key& key) {
		return _tree.lower_bound(make_pair(key, mapped_type()));
	}

	const_iterator lower_bound(const Key& key) const {
		return _tree.lower_bound(make_pair(key, mapped_type()));
	}

	iterator upper_bound(const Key& key) {
		return _tree.upper_bound(make_pair(key, mapped_type()));
	}

	const_iterator upper_bound(const Key& key) const {
		return _tree.upper_bound(make_pair(key, mapped_type()));
	}

	/* observers */
	key_compare key_comp() const { return _compare; }
	map::value_compare value_comp() const { return _tree.value_comp(); }

   private:
	map_tree _tree;
	Compare _compare;
};

template <class Key, class T, class Compare, class Alloc>
bool operator==(const map<Key, T, Compare, Alloc>& lhs,
				const map<Key, T, Compare, Alloc>& rhs) {
	return lhs._tree == rhs._tree;
}

template <class Key, class T, class Compare, class Alloc>
bool operator!=(const map<Key, T, Compare, Alloc>& lhs,
				const map<Key, T, Compare, Alloc>& rhs) {
	return !(lhs._tree == rhs._tree);
}

template <class Key, class T, class Compare, class Alloc>
bool operator<(const map<Key, T, Compare, Alloc>& lhs,
			   const map<Key, T, Compare, Alloc>& rhs) {
	return lhs._tree < rhs._tree;
}

template <class Key, class T, class Compare, class Alloc>
bool operator<=(const map<Key, T, Compare, Alloc>& lhs,
				const map<Key, T, Compare, Alloc>& rhs) {
	return lhs._tree < rhs._tree || lhs._tree == rhs._tree;
}

template <class Key, class T, class Compare, class Alloc>
bool operator>(const map<Key, T, Compare, Alloc>& lhs,
			   const map<Key, T, Compare, Alloc>& rhs) {
	return !(lhs._tree < rhs._tree || lhs._tree == rhs._tree);
}

template <class Key, class T, class Compare, class Alloc>
bool operator>=(const map<Key, T, Compare, Alloc>& lhs,
				const map<Key, T, Compare, Alloc>& rhs) {
	return !(lhs._tree < rhs._tree);
}

template <class Key, class T, class Compare, class Alloc>
void swap(map<Key, T, Compare, Alloc>& lhs, map<Key, T, Compare, Alloc>& rhs) {
	return lhs.swap(rhs);
}
}  // namespace ft

#endif	// MAP_HPP
