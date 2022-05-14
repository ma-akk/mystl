#include <iostream>
#include <vector>
#include <map>
#include <stack>
#include "../vector.hpp"
#include "iterator.hpp"
#include "ran_it.hpp"
// #include "stack.hpp"
// #include "utils.hpp"

using std::cout;
using std::endl;

int main() {
	std::vector<int> v;
	ft::vector<int> v1;

	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	v.push_back(5);
	v.push_back(12);

	v1.push_back(1);
	v1.push_back(2);
	v1.push_back(3);
	v1.push_back(5);
	v1.push_back(12);
	// ft::iterator_traits<std::vector<int>::iterator> it1;
	// ft::iterator_traits<std::map<int, int>::iterator> it2;
	// std::advance(it1, 0);
	// ft::advance(it2, 0);
	// ft::advance(it1, 0);// ft::itera// ft::iterator_traits<std::vector<int>::iterator> it1;
	// ft::iterator_traits<std::map<int, int>::iterator> it2;
	// std::advance(it1, 0);
	// ft::advance(it2, 0);
	// ft::advance(it1, 0);tor_traits<std::vector<int>::iterator> it1;
	// ft::iterator_traits<std::map<int, int>::iterator> it2;
	// std::advance(it1, 0);
	// ft::advance(it2, 0);
	// ft::advance(it1, 0);

	// char* ptr = "Hela";
	// cout << (*--ptr) << endl;
	// cout << (*ptr) << endl;
	
	std::vector<int>::iterator it = v.begin();
	ft::ran_it<int> ran_it1 = v1.begin();
	ft::ran_it<int> ran_it2 = (v1.begin() + 2);
	cout << *ran_it1 << " " << *ran_it2 << endl;
	bool res = ran_it1 != ran_it2;
	cout << res << endl;
	res = ran_it1 == ran_it2;
	cout << res << endl;



	
	
	// cout << endl << "std: size/cap = " << v.size() << " / " << v.capacity() << endl;
	// cout << "ft:  size/cap = " << v1.size() << " / " << v1.capacity() << endl;
	// cout << "std: empty = " << v.empty() << endl << "ft:  empty = " << v1.empty() << endl;
	// cout << "std: max_size = " << v.max_size() << endl << "ft:  max_size = " << v1.max_size() << endl;
	// // cout << "std: data = " << *(v.data()) << endl << "ft:  data = " << *(v1.data()) << endl;
	// v.push_back(1);
	// v.push_back(2);
	// v.push_back(3);
	// v.push_back(5);
	// v.push_back(12);

	// v1.push_back(1);
	// v1.push_back(2);
	// v1.push_back(3);
	// v1.push_back(5);
	// v1.push_back(12);
	// for(int i = 0; i < 5; i++) {
	// 	cout << v[i] << " " << v1[i] << endl;
	// }
}