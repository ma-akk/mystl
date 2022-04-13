#ifndef REVERSE_ITERATOR_HPP
#define REVERSE_ITERATOR_HPP

#include <iostream>
#include <string>
#include "iterator.hpp"

namespace ft {

	template < class ran_it >
	class reverse_iterator : public iterator <
							typename iterator_traits<ran_it>::iterator_category,
							typename iterator_traits<ran_it>::value_type,
							typename iterator_traits<ran_it>::difference_type,
							typename iterator_traits<ran_it>::pointer,
							typename iterator_traits<ran_it>::reference > {
	 public:
		typedef reverse_iterator<ran_it> rev_it;
		typedef iterator_traits<ran_it>::difference_type D;
		typedef iterator_traits<ran_it>::pointer Ptr;
		typedef iterator_traits<ran_it>::reference Ref;
		typedef ran_it iterator_type;

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

		ran_it base() const {
			return current;
		}

		Ref operator*() const {
			ran_it tmp = current;
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
	 	ran_it current;

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
