#ifndef RAN_IT_HPP
#define RAN_IT_HPP

#include <iostream>
#include <string>
#include <cstddef>

#include "iterator.hpp"

class iterator_traits;

namespace ft {

template <class T>
class ran_it {
   public:
	typedef typename std::random_access_iterator_tag iterator_category;
	typedef typename ft::iterator_traits<T*>::value_type value_type;
	typedef typename ft::iterator_traits<T*>::difference_type difference_type;
	typedef typename ft::iterator_traits<T*>::pointer pointer;
	typedef typename ft::iterator_traits<T*>::reference reference;
	typedef pointer iterator_type;

	ran_it() : _element(NULL) {
		_element = 0;
	}

	ran_it(pointer elem) : _element(elem) {}

	ran_it(const ran_it<typename ft::remove_const<value_type>::type > & value) : _element(&(*value)) {}

	virtual ~ran_it() {}

	ran_it& operator=(const ran_it<typename ft::remove_const<value_type>::type >& value) {
		if (this != &value) {
			_element = value._element;
		}
		return *this;
	}

	pointer get_pointer() const { return this->_element; }

	reference operator*() const { return *_element; }

	pointer operator->() const { return &(this->operator*()); }

	reference operator[](difference_type n) const { return *(_element + n); }

	ran_it& operator++() {
		++_element;
		return *this;
	}

	ran_it& operator--() {
		--_element;
		return *this;
	}

	ran_it operator++(int) {
		ran_it tmp = *this;
		++_element;
		return tmp;
	}

	ran_it operator--(int) {
		ran_it tmp = *this;
		--_element;
		return tmp;
	}

	ran_it operator+(const difference_type n) const { return _element + n; }

	ran_it operator-(const difference_type n) const { return _element - n; }

	ran_it& operator+=(difference_type n) {
		_element += n;
		return *this;
	}

	ran_it& operator-=(difference_type n) {
		_element -= n;
		return *this;
	}

	friend bool operator==(const ran_it<T>& lhs, const ran_it<T>& rhs) {
		return (lhs._element == rhs._element);
	}

	friend bool operator!=(const ran_it<T>& lhs, const ran_it<T>& rhs) {
		return (lhs._element != rhs._element);
	}

	bool operator>(const ran_it<T>& value) const {
		return _element > value._element;
	};

	bool operator>=(const ran_it<T>& value) const {
		return _element >= value._element;
	};

	difference_type operator-(const ran_it<T> value) const {
		return (_element - value._element);
	};

	difference_type operator+(const ran_it<T> value) const {
		return (_element + value._element);
	};

	bool operator<(const ran_it<T>& value) const {
		return _element < value._element;
	};

	bool operator<=(const ran_it<T>& value) const {
		return _element <= value._element;
	};

   protected:
	pointer _element;
};

template <typename T>
ran_it<T> operator-(int n, const ran_it<T> &value)
{
	ran_it<T> tmp(value._element - n);
	return (tmp);
}

template <typename T>
ran_it<T> operator+(int n, const ran_it<T> &value)
{
	ran_it<T> tmp(value._element + n);
	return (tmp);
}


};	// namespace ft

#endif	// RAN_IT_HPP
