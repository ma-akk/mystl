#ifndef REVERSE_IT_HPP
#define REVERSE_IT_HPP

#include <iostream>
#include <string>

#include "iterator.hpp"

namespace ft {

template <class ran_it>
class reverse_it
	: public std::iterator<typename iterator_traits<ran_it>::iterator_category,
						   typename iterator_traits<ran_it>::value_type,
						   typename iterator_traits<ran_it>::difference_type,
						   typename iterator_traits<ran_it>::pointer,
						   typename iterator_traits<ran_it>::reference> {
   public:
	typedef reverse_it<ran_it> rev_it;
	typedef typename iterator_traits<ran_it>::difference_type D;
	typedef typename iterator_traits<ran_it>::pointer Ptr;
	typedef typename iterator_traits<ran_it>::reference Ref;
	typedef ran_it iterator_type;

	reverse_it() {}

	explicit reverse_it(iterator_type x) : current(x) {}

	template <class U>
	reverse_it(const reverse_it<U> &value) : current(value.base()) {}

	template <class U>
	reverse_it &operator=(const reverse_it<U> &value) {
		if (this != &value) {
			current = value.base();
		}
		return *this;
	}

	ran_it base() const { return current; }

	Ref operator*() const {
		ran_it tmp = current;
		return (*--tmp);
	}

	Ptr operator->() const { return (&**this); }

	Ref operator[](D n) const { return *(*this + n); }

	rev_it &operator++() {
		--current;
		return *this;
	}

	rev_it &operator--() {
		++current;
		return *this;
	}

	rev_it operator++(int) {
		rev_it tmp = *this;
		--current;
		return tmp;
	}

	rev_it operator--(int) {
		rev_it tmp = *this;
		++current;
		return tmp;
	}
	rev_it operator+(D n) const { return rev_it(current - n); }

	rev_it operator-(D n) const { return rev_it(current + n); }

	rev_it &operator+=(D n) {
		current -= n;
		return *this;
	}
	rev_it &operator-=(D n) {
		current += n;
		return *this;
	}

   protected:
	ran_it current;
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
