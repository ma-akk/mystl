#ifndef REVERSE_ITERATOR_HPP
#define REVERSE_ITERATOR_HPP

#include <iostream>
#include <string>
#include "iterator.hpp"

namespace ft {

	template < class RanIt >
	class reverse_iterator : public iterator <
							typename iterator_traits<RanIt>::iterator_category,
							typename iterator_traits<RanIt>::value_type,
							typename iterator_traits<RanIt>::difference_type,
							typename iterator_traits<RanIt>::pointer,
							typename iterator_traits<RanIt>::reference > {
	 public:
		typedef reverse_iterator<RanIt> rev_it;
		typedef iterator_traits<RanIt>::difference_type D;
		typedef iterator_traits<RanIt>::pointer Ptr;
		typedef iterator_traits<RanIt>::reference Ref;
		typedef RanIt iterator_type;

		reverse_iterator() { }

		explicit reverse_iterator( iterator_type x )
				: current(x) { }

		template< class U >
		reverse_iterator( const reverse_iterator<U>& value ) {
				: current(value.base());
		}

		template< class U >
		reverse_iterator& operator=( const reverse_iterator<U>& value ) {
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
	 	RanIt current;

	};

	//non-member function
	template< class Iterator1, class Iterator2 >
	bool operator==( const reverse_iterator<Iterator1>& lhs,
					const reverse_iterator<Iterator2>& rhs ) {
		return lhs.base() == rhs.base();
	};
		
	template< class Iterator1, class Iterator2 >
	bool operator!=( const reverse_iterator<Iterator1>& lhs,
					const reverse_iterator<Iterator2>& rhs ) {
		return !(lhs == rhs);
	};

	//check and compare with std
	template< class Iterator1, class Iterator2 >
	bool operator<( const reverse_iterator<Iterator1>& lhs,
					const reverse_iterator<Iterator2>& rhs ) {
		return lhs.base() < rhs.base();
	};

	template< class Iterator1, class Iterator2 >
	bool operator<=( const reverse_iterator<Iterator1>& lhs,
					const reverse_iterator<Iterator2>& rhs ) {
		return lhs < rhs || lhs == rhs;
	};

	template< class Iterator1, class Iterator2 >
	bool operator>( const reverse_iterator<Iterator1>& lhs,
					const reverse_iterator<Iterator2>& rhs ) {
		return !(lhs < rhs);
	};

	template< class Iterator1, class Iterator2 >
	bool operator>=( const reverse_iterator<Iterator1>& lhs,
					const reverse_iterator<Iterator2>& rhs ) {
		return !(lhs < rhs) || lhs == rhs;
	};

	template< class Iter >
	reverse_iterator<Iter>
    operator+( typename reverse_iterator<Iter>::difference_type n,
               const reverse_iterator<Iter>& it ) {
		return it + n;
	};

	template< class Iterator >
	typename reverse_iterator<Iterator>::difference_type
    operator-( const reverse_iterator<Iterator>& lhs,
               const reverse_iterator<Iterator>& rhs ) {
		return it - n;
	};
};

#endif	//REVERSE_ITERATOR_HPP
