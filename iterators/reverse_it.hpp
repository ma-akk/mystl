#ifndef REVERSE_IT_HPP
#define REVERSE_IT_HPP

#include <iostream>
#include <string>

#include "iterator.hpp"

namespace ft {

template <class T>
class reverse_it {
 public:
  typedef typename ft::iterator_traits<T*>::iterator_category iterator_category;
  typedef typename ft::iterator_traits<T*>::value_type value_type;
  typedef typename ft::iterator_traits<T*>::difference_type difference_type;
  typedef T* pointer;
  typedef T& reference;
  typedef pointer iterator_type;

	reverse_it() : current(NULL) {}

	explicit reverse_it(iterator_type x) : current(x) {}

	template <class V>
	reverse_it(const reverse_it<V> &value) : current(&(*value)) {}

	template<class V>
	reverse_it &operator=(const reverse_it<V> &value) {
		if (this != &value) {
			current = value.base();
		}
		return *this;
	}

	pointer base() const { return current; }

	reference operator*() const {
		return (*current);
	}

	pointer operator->() const { return &(this->operator*()); }

	reference operator[](difference_type n) const { return *(*this + n); }

	reverse_it &operator++() {
		--current;
		return *this;
	}

	reverse_it &operator--() {
		++current;
		return *this;
	}

	reverse_it operator++(int) {
		reverse_it tmp = *this;
		--current;
		return tmp;
	}

	reverse_it operator--(int) {
		reverse_it tmp = *this;
		++current;
		return tmp;
	}
	reverse_it operator+(difference_type n) const { return reverse_it(current - n); }

	reverse_it operator-(difference_type n) const { return reverse_it(current + n); }

	reverse_it &operator+=(difference_type n) {
		current -= n;
		return *this;
	}
	reverse_it &operator-=(difference_type n) {
		current += n;
		return *this;
	}

   protected:
	pointer current;
};

// non-member function
template <class Iterator1, class Iterator2>
bool operator==(const reverse_it<Iterator1> &lhs,
				const reverse_it<Iterator2> &rhs) {
	return lhs.base() == rhs.base();
};

template <class Iterator1, class Iterator2>
bool operator!=(const reverse_it<Iterator1> &lhs,
				const reverse_it<Iterator2> &rhs) {
	return !(lhs == rhs);
};

// check and compare with std
template <class Iterator1, class Iterator2>
bool operator<(const reverse_it<Iterator1> &lhs,
			   const reverse_it<Iterator2> &rhs) {
	return lhs.base() < rhs.base();
};

template <class Iterator1, class Iterator2>
bool operator<=(const reverse_it<Iterator1> &lhs,
				const reverse_it<Iterator2> &rhs) {
	return lhs < rhs || lhs == rhs;
};

template <class Iterator1, class Iterator2>
bool operator>(const reverse_it<Iterator1> &lhs,
			   const reverse_it<Iterator2> &rhs) {
	return !(lhs < rhs);
};

template <class Iterator1, class Iterator2>
bool operator>=(const reverse_it<Iterator1> &lhs,
				const reverse_it<Iterator2> &rhs) {
	return !(lhs < rhs) || lhs == rhs;
};

template <class Iter>
reverse_it<Iter> operator+(typename reverse_it<Iter>::difference_type n,
						   const reverse_it<Iter> &it) {
	return it + n;
};

template <class Iter>
reverse_it<Iter> operator-(typename reverse_it<Iter>::difference_type n,
						   const reverse_it<Iter> &it) {
	return it - n;
};
};	// namespace ft

#endif	// REVERSE_IT_HPP
