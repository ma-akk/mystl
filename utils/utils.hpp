#ifndef UTILS_HPP
#define UTILS_HPP

#include <stdint.h>

namespace ft {
// template <class Iterator>
// class iterator_traits {
//    public:
// 	typedef typename Iterator::iterator_category iterator_category;
// 	typedef typename Iterator::value_type value_type;
// 	typedef typename Iterator::difference_type difference_type;
// 	typedef typename Iterator::pointer pointer;
// 	typedef typename Iterator::reference reference;
// };

// template <class T>
// class iterator_traits<T*> {
//    public:
// 	typedef std::random_access_iterator_tag iterator_category;
// 	typedef T value_type;
// 	typedef std::ptrdiff_t difference_type;
// 	typedef T* pointer;
// 	typedef T& reference;
// };

// template <class T>
// class iterator_traits<const T*> {
//    public:
// 	typedef std::random_access_iterator_tag iterator_category;
// 	typedef const T value_type;
// 	typedef std::ptrdiff_t difference_type;
// 	typedef const T* pointer;
// 	typedef const T& reference;
// };

template <class InputIt1, class InputIt2>
bool lexicographical_compare(InputIt1 first1, InputIt1 last1, InputIt2 first2,
							 InputIt2 last2) {
	for (; (first1 != last1) && (first2 != last2); ++first1, (void)++first2) {
		if (*first1 < *first2) return true;
		if (*first2 < *first1) return false;
	}
	return (first1 == last1) && (first2 != last2);
}

template <class InputIt1, class InputIt2, class Compare>
bool lexicographical_compare(InputIt1 first1, InputIt1 last1, InputIt2 first2,
							 InputIt2 last2, Compare comp) {
	for (; (first1 != last1) && (first2 != last2); ++first1, (void)++first2) {
		if (comp(*first1, *first2)) return true;
		if (comp(*first2, *first1)) return false;
	}
	return (first1 == last1) && (first2 != last2);
}

template <class InputIt1, class InputIt2>
bool equal(InputIt1 first1, InputIt1 last1, InputIt2 first2) {
	for (; first1 != last1; ++first1, ++first2) {
		if (!(*first1 == *first2)) {
			return false;
		}
	}
	return true;
}

template <class InputIt1, class InputIt2, class BinaryPredicate>
bool equal(InputIt1 first1, InputIt1 last1, InputIt2 first2,
		   BinaryPredicate p) {
	for (; first1 != last1; ++first1, ++first2) {
		if (!p(*first1, *first2)) {
			return false;
		}
	}
	return true;
}

template <class T, bool v>
struct integral_constant {
	static const bool value = v;
	typedef T value_type;
	typedef integral_constant type;

	operator value_type() const { return value; }
};

template <class T>
struct is_integral : public ft::integral_constant<T, false> {};
template <>
struct is_integral<bool> : public ft::integral_constant<bool, true> {};
template <>
struct is_integral<char> : public ft::integral_constant<bool, true> {};
template <>
struct is_integral<signed char> : public ft::integral_constant<bool, true> {};
template <>
struct is_integral<unsigned char> : public ft::integral_constant<bool, true> {};
template <>
struct is_integral<wchar_t> : public ft::integral_constant<bool, true> {};
// template <>
// struct is_integral<char16_t>: public ft::integral_constant<bool, true> {};
template <>
struct is_integral<short> : public ft::integral_constant<bool, true> {};
template <>
struct is_integral<unsigned short> : public ft::integral_constant<bool, true> {};
template <>
struct is_integral<int> : public ft::integral_constant<bool, true> {};
template <>
struct is_integral<unsigned int> : public ft::integral_constant<bool, true> {};
template <>
struct is_integral<long> : public ft::integral_constant<bool, true> {};
template <>
struct is_integral<unsigned long> : public ft::integral_constant<bool, true> {};
template <>
struct is_integral<long long> : public ft::integral_constant<bool, true> {};
template <>
struct is_integral<unsigned long long> : public ft::integral_constant<bool, true> {};

// template <bool condition, class T, class F>
// struct conditional {
// 	typedef F type;
// };

// template <class T, class F>
// struct conditional<true, T, F> {
// 	typedef T type;
// };

template <bool condition, typename T = void>
struct enable_if {};

template <typename T>
struct enable_if<true, T> {
  typedef T type;
};

// testing file is in Standart p.65
template <class T1, class T2>
struct pair {
	typedef T1 first_type;
	typedef T2 second_type;
	T1 first;
	T2 second;

	pair() : first(T1()), second(T2()) {}

	pair(const T1& x, const T2& y) : first(x), second(y) {}

	template <class U1, class U2>
	pair(const pair<U1, U2>& p) : first(p.first), second(p.second) {}

	pair(const pair& p) : first(p.first), second(p.second) {}

	virtual ~pair() {}

	pair& operator=(const pair& value) {
		if (*this != value) {
			this->first = value.first;
			this->second = value.second;
		}
		return *this;
	}
};

// non-member function
template <class T1, class T2>
pair<T1, T2> make_pair(T1 t1, T2 t2) {
	return pair<T1, T2>(t1, t2);
};

template <class T1, class T2>
bool operator==(const ft::pair<T1, T2>& lhs, const ft::pair<T1, T2>& rhs) {
	return lhs.first == rhs.first && lhs.second == rhs.second;
};

template <class T1, class T2>
bool operator!=(const ft::pair<T1, T2>& lhs, const ft::pair<T1, T2>& rhs) {
	return !(lhs == rhs);
};

template <class T1, class T2>
bool operator<(const ft::pair<T1, T2>& lhs, const ft::pair<T1, T2>& rhs) {
	return lhs.first < rhs.first; //|| !(rhs.first < lhs.first && lhs.second < rhs.second);
};

template <class T1, class T2>
bool operator<=(const ft::pair<T1, T2>& lhs, const ft::pair<T1, T2>& rhs) {
	return lhs < rhs || lhs == rhs;
};

template <class T1, class T2>
bool operator>(const ft::pair<T1, T2>& lhs, const ft::pair<T1, T2>& rhs) {
	return !(lhs < rhs);
};

template <class T1, class T2>
bool operator>=(const ft::pair<T1, T2>& lhs, const ft::pair<T1, T2>& rhs) {
	return !(lhs < rhs) || lhs == rhs;
};

}  // namespace ft

#endif	// UTILS_HPP
