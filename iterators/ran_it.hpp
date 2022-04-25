#ifndef RAN_IT_HPP
#define RAN_IT_HPP

#include <iostream>
#include <string>
#include "iterator.hpp"

class iterator_traits;

namespace ft {

	template < class T >
	class ran_it : public iterator<random_access_iterator_tag, T> {
	 public:
	 	typedef typename iterator<random_access_iterator_tag, T>::iterator_category	iterator_category ;
		typedef typename iterator<random_access_iterator_tag, T>::value_type		value_type;
		typedef typename iterator<random_access_iterator_tag, T>::difference_type	difference_type;
		typedef T*		pointer;
		typedef T&		reference;

		ran_it() : _element(NULL) { }

		ran_it(T* elem) : _element(elem) { }

		ran_it(const ran_it& value) {
			*this = value;
		}

		~ran_it() { }

		ran_it& operator=( const ran_it& value ) {
			if(this != &value) {
				_element = value._element;
			}
			return *this;
		}

		T& operator*() const {
			return *_element;
		}

		T* operator->() const {
			return &(this->operator*()); //(&**this);
		}

		T& operator[](ptrdiff_t n) const {
			return *(*this + n);
		}

		ran_it& operator++() {
			++_element;
			return *this;
		}

		ran_it& operator--() {
			--_element;
			return *this;
		}

		ran_it operator++( int ) {
			ran_it tmp = *this; 
			++_element;
			return tmp;
		}

		ran_it operator--( int ) {
			ran_it tmp = *this; 
			--_element;
			return tmp;
		}
		ran_it operator+(ptrdiff_t n) const {
			return ran_it(_element + n);
		}

		ran_it operator-(ptrdiff_t n) const {
			return ran_it(_element - n);
		}

		ran_it& operator+=(ptrdiff_t n) {
			_element += n;
			return *this;
		}
		ran_it& operator-=(ptrdiff_t n) {
			_element -= n;
			return *this;
		}

	 protected:
		T* _element;

	};

};

#endif	//RAN_IT_HPP
