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

	// template< class InputIt1, class InputIt2 >
	// bool equal( InputIt1 first1, InputIt1 last1,
	// 		InputIt2 first2 );	
	// template< class InputIt1, class InputIt2,
	// 		class BinaryPredicate >
	// bool equal( InputIt1 first1,
	// 			InputIt1 last1,
	// 			InputIt2 first2,
	// 			BinaryPredicate p );

	template <bool condition, typename T>
	struct enable_if;
	
	template <typename T>
	struct enable_if<true, T> {
		typedef T	type;
	};

	template <typename T>
	struct is_integral;
	
	//testing file is in Standart p.65
	template <class T1, class T2 >
	struct pair {
		typedef T1 first_type;
		typedef T2 second_type;
		T1 first;
		T2 second;

		pair() : first(T1()), second(T2()) { }

		pair(const T1& x, const T2& y) : first(x), second(y) { }
		
		template< class U1, class U2 >
		pair(const pair<U1, U2>& p)
			: first(p.first), second(p.second) { }

		~pair() { }

		pair& operator=(const pair& value) {
			if (*this != value) {
				this->first = value.first;
				this->second = value.second;
			}
			return *this;
		}
	};

	//non-member function
	template< class T1, class T2 >
	pair<T1,T2> make_pair(T1 t1, T2 t2) {
		return pair<T1, T2>(t1, t2);
	};

	template < class T1, class T2 >
	bool operator==( const pair<T1,T2>& lhs, const pair<T1,T2>& rhs ) {
		return lhs.first == rhs.first && lhs.second == rhs.second;
	};
	
	template < class T1, class T2 >
	bool operator!=( const pair<T1,T2>& lhs, const pair<T1,T2>& rhs ) {
		return !(lhs == rhs);
	};
	
	template < class T1, class T2 >
	bool operator<( const pair<T1,T2>& lhs, const pair<T1,T2>& rhs ) {
		return lhs.first < rhs.first || !(rhs.first < lhs.first && lhs.second < rhs.second);
	};
	
	template < class T1, class T2 >
	bool operator<=( const pair<T1,T2>& lhs, const pair<T1,T2>& rhs ) {
		return lhs < rhs || lhs == rhs;
	};
	
	template < class T1, class T2 >
	bool operator>( const pair<T1,T2>& lhs, const pair<T1,T2>& rhs ) {
		return !(lhs < rhs);
	};
	
	template < class T1, class T2 >
	bool operator>=( const pair<T1,T2>& lhs, const pair<T1,T2>& rhs ) {
		return !(lhs < rhs) || lhs == rhs;
	};
	
}

#endif	//UTILS_HPP
