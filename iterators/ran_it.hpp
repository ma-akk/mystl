#ifndef RAN_IT_HPP
#define RAN_IT_HPP

#include <iostream>
#include <string>

#include "iterator.hpp"

class iterator_traits;

namespace ft {

template <class T>
class ran_it : public ft::iterator_traits<T*> {
   public:
	typedef typename iterator_traits<T*>::iterator_category iterator_category;
	typedef typename iterator_traits<T*>::value_type value_type;
	typedef typename iterator_traits<T*>::difference_type difference_type;
	typedef T* pointer;
	typedef T& reference;

	ran_it() : _element(NULL) {}

	ran_it(T* elem) : _element(elem) {}

	ran_it(const ran_it& value) { *this = value; }

	~ran_it() {}

	ran_it& operator=(const ran_it& value) {
		if (this != &value) {
			_element = value._element;
		}
		return *this;
	}

	pointer get_pointer() const { return this->_element; }

	reference operator*() const { return *_element; }

	pointer operator->() const { return &(this->operator*()); }

	reference operator[](ptrdiff_t n) const { return *(*this + n); }

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

	ran_it operator+(ptrdiff_t n) const { return ran_it(_element + n); }

	ran_it operator-(ptrdiff_t n) const { return ran_it(_element - n); }

	ran_it& operator+=(ptrdiff_t n) {
		_element += n;
		return *this;
	}

	ran_it& operator-=(ptrdiff_t n) {
		_element -= n;
		return *this;
	}

   protected:
	pointer _element;
};

template <typename T>
bool operator==(const ran_it<T> lhs, const ran_it<T> rhs) {
	return (lhs.get_pointer() == rhs.get_pointer());
}

template <typename T>
bool operator!=(const ran_it<T> lhs, const ran_it<T> rhs) {
	return (lhs.get_pointer() != rhs.get_pointer());
}

template <typename T>
typename ran_it<T>::difference_type operator-(const ran_it<T> lhs,
											  const ran_it<T> rhs) {
	return (lhs.get_pointer() - rhs.get_pointer());
}

template <typename T>
typename ran_it<T>::difference_type operator+(const ran_it<T> lhs,
											  const ran_it<T> rhs) {
	return (lhs.get_pointer() + rhs.get_pointer());
}

};	// namespace ft

#endif	// RAN_IT_HPP
