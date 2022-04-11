#ifndef RANIT_HPP
#define RANIT_HPP

#include <iostream>
#include <string>
#include "iterator.hpp"


namespace ft {

	template < class T, class D, class Ptr, class Ref >
	class RanIt : public iterator< random_access_iterator_tag
									T, D, Ptr, Ref > {
	 public:
		RanIt();
		RanIt(const RanIt& value);
		~RanIt();

		RanIt& operator=( const RanIt& value ) {
			if(this != &value) {
				current = value.base();
			}
			return *this;
		}

		RanIt base() const {
			return current;
		}

		Ref operator*() const {
			RanIt tmp = current;
			return (*--tmp);
		}

		Ptr operator->() const {
			return (&**this);
		}

		Ref operator[](D n) const {
			return *(*this + n);
		}

		rev_it& operator++() {
			--current;
			return *this;
		}

		rev_it& operator--() {
			++current;
			return *this;
		}

		rev_it operator++( int ) {
			rev_it tmp = *this; 
			--current;
			return tmp;
		}

		rev_it operator--( int ) {
			rev_it tmp = *this; 
			++current;
			return tmp;
		}
		rev_it operator+(D n) const {
			return rev_it(current - n);
		}

		rev_it operator-(D n) const {
			return rev_it(current + n);
		}

		rev_it& operator+=(D n) {
			current -= n;
			return *this;
		}
		rev_it& operator-=(D n) {
			current += n;
			return *this;
		}


	 protected:
		T _element;


	};

};

#endif	//RANIT_HPP
