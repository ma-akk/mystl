#ifndef UTILS_HPP
#define UTILS_HPP

#include "vector.hpp"

using std::allocator;
using std::cout;
using std::endl;

namespace ft {
	// template< class InputIt1, class InputIt2 >
	// bool lexicographical_compare( InputIt1 first1, InputIt1 last1,
    //                           InputIt2 first2, InputIt2 last2 );

	// template< class InputIt1, class InputIt2, class Compare >
	// bool lexicographical_compare( InputIt1 first1, InputIt1 last1,
    //                           InputIt2 first2, InputIt2 last2,
    //                           Compare comp );

	//non-member function
	template< class T, class Alloc >
	bool operator==( const vector<T,Alloc>& lhs,
					const vector<T,Alloc>& rhs ) {
		if (lhs.size() == rhs.size()) {
			for(int i = 0; i < rhs.size(); i++) {
				if(lhs[i] != rhs[i])
					return false;
			}
			return true;
		}
		return false;
	}

	template< class T, class Alloc >
	bool operator!=(const vector<T,Alloc>& lhs,
					const vector<T,Alloc>& rhs) {
		return !(lhs == rhs);
	}

	// template< class T, class Alloc >
	// bool operator<( const vector<T,Alloc>& lhs,
	// 				const vector<T,Alloc>& rhs ) {
		
	// }

	// template< class T, class Alloc >
	// bool operator<=( const vector<T,Alloc>& lhs,
	// 				const vector<T,Alloc>& rhs );

	// template< class T, class Alloc >
	// bool operator>( const vector<T,Alloc>& lhs,
	// 				const vector<T,Alloc>& rhs );

	// template< class T, class Alloc >
	// bool operator>=( const vector<T,Alloc>& lhs,
	// 				const vector<T,Alloc>& rhs );
}

#endif	//UTILS_HPP
