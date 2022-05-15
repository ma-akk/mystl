#include <iostream>
#include <vector>
#include <stack>
#include "vector.hpp"
#include "iterators/iterator.hpp"
#include "stack.hpp"
#include "utils.hpp"

using std::cout;
using std::endl;

int main() {
	std::vector<int> v;
	ft::vector<int> v1;
	std::vector<int> v01;
	for(int i = 0; i < 15; i++) {
		v01.push_back(100 + i);
	}

	ft::vector<int> v1_copy(v1);	
	// ft::iterator_traits<char * > it;
	
	// cout << endl << "std: size/cap = " << v.size() << " / " << v.capacity() << endl;
	// cout << "ft:  size/cap = " << v1.size() << " / " << v1.capacity() << endl;
	// cout << "std: empty = " << v.empty() << endl << "ft:  empty = " << v1.empty() << endl;
	// cout << "std: max_size = " << v.max_size() << endl << "ft:  max_size = " << v1.max_size() << endl;
	// // cout << "std: data = " << *(v.data()) << endl << "ft:  data = " << *(v1.data()) << endl;

	//ASSIGN with empty vector
	// v.assign(10, 15);
	// v1.assign(10, 15);
	// for(int i = 0; i < 10; i++) {
	// 	cout << v[i] << " " << v1[i] << endl;
	// }
	// cout << endl << "std: size/cap = " << v.size() << " / " << v.capacity() << endl;
	// cout << endl << "std: size/cap = " << v1.size() << " / " << v1.capacity() << endl;
	std::vector<int>::iterator it = v.begin();
	ft::vector<int>::iterator it1 = v1.begin();
	std::vector<int>::iterator it_end = v.end();
	ft::vector<int>::iterator it_end1 = v1.end();
	
	//INSERT with empty vector
	// v.insert(it, 10);
	// v1.insert(it1, 10);
	// cout << v[0] << " std: size/cap = " << v.size() << " / " << v.capacity() << endl;
	// cout << v1[0]  << " std: size/cap = " << v1.size() << " / " << v1.capacity() << endl;

	// v.insert(it, 3, 10);
	// v1.insert(it1, 3, 10);
	// cout << v[0] << " std: size/cap = " << v.size() << " / " << v.capacity() << endl;
	// cout << v1[0]  << " ft : size/cap = " << v1.size() << " / " << v1.capacity() << endl;

	std::vector<int>::iterator it2 = v01.begin() + 2;
	std::vector<int>::iterator it3 = v01.begin() + 5;

	// v.insert(it, it2, it3);
	// v1.insert(it1, it2, it3);
	// cout << v[0] << " std: size/cap = " << v.size() << " / " << v.capacity() << endl;
	// cout << v1[0]  << " ft : size/cap = " << v1.size() << " / " << v1.capacity() << endl;

	//ERASE with empty vector  - SEG_FAULT
	// v.erase(it);
	// v1.erase(it1);
	cout << " std: size/cap = " << v.size() << " / " << v.capacity() << endl;
	cout << " ft : size/cap = " << v1.size() << " / " << v1.capacity() << endl;
	
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

	// cout << endl << "std: size/cap = " << v.size() << " / " << v.capacity() << endl;
	// cout << "ft:  size/cap = " << v1.size() << " / " << v1.capacity() << endl;
	// cout << "std: empty = " << v.empty() << endl << "ft:  empty = " << v1.empty() << endl;
	// cout << "std: front = " << v.front() << endl << "ft:  front = " << v1.front() << endl;
	// cout << "std: back = " << v.back() << endl << "ft:  back = " << v1.back() << endl;
	// cout << "std: data = " << *(v.data()) << endl << "ft:  data = " << *(v1.data()) << endl;
	
	// cout << endl << " =====   MODIFY VECTOR   ===== " << endl;
	// int rs = 7;
	// v.resize(rs);
	// v1.resize(rs);
	// cout << "RESIZE" << endl << "std: size/cap = " << v.size() << " / " << v.capacity() << endl;
	// cout << "ft:  size/cap = " << v1.size() << " / " << v1.capacity() << endl;
	// for(int i = 0; i < rs; i++) {
	// 	cout << v[i] << " " << v1[i] << endl;
	// }

	// rs = 11;
	// v.resize(rs, 10);
	// v1.resize(rs, 10);
	// cout << "RESIZE" << endl << "std: size/cap = " << v.size() << " / " << v.capacity() << endl;
	// cout << "ft:  size/cap = " << v1.size() << " / " << v1.capacity() << endl;
	// // for(int i = 0; i < rs; i++) {
	// // 	cout << v[i] << " " << v1[i] << endl;
	// // }

	// rs = 15;
	// v.resize(rs);
	// v1.resize(rs);
	// cout << "RESIZE" << endl << "std: size/cap = " << v.size() << " / " << v.capacity() << endl;
	// cout << "ft:  size/cap = " << v1.size() << " / " << v1.capacity() << endl;
	// // for(int i = 0; i < rs; i++) {
	// // 	cout << v[i] << " " << v1[i] << endl;
	// // }

	// rs = 18;
	// v.resize(rs, -90);
	// v1.resize(rs, -90);
	// cout << "RESIZE" << endl << "std: size/cap = " << v.size() << " / " << v.capacity() << endl;
	// cout << "ft:  size/cap = " << v1.size() << " / " << v1.capacity() << endl;
	// // for(int i = 0; i < rs; i++) {
	// // 	cout << v[i] << " " << v1[i] << endl;
	// // }

	// v.pop_back();
	// v1.pop_back();
	// cout << "POP_BACK" << endl << "std: size/cap = " << v.size() << " / " << v.capacity() << endl;
	// cout << "ft:  size/cap = " << v1.size() << " / " << v1.capacity() << endl;

	// v.clear();
	// v1.clear();
	// cout << "CLEAR" << endl << "std: size/cap = " << v.size() << " / " << v.capacity() << endl;
	// cout << "ft:  size/cap = " << v1.size() << " / " << v1.capacity() << endl;

	// cout << endl << " =====   CONSTRUCTORS  ===== " << endl;
	// std::vector<int> v2(10);
	// ft::vector<int> v3(10);
	// for(int i = 0; i < 10; i++) {
	// 	cout << v2[i] << " " << v3[i] << endl;
	// }
	// cout << "VECTOR(COUNT)" << endl << "std: size/cap = " << v2.size() << " / " << v2.capacity() << endl;
	// cout << "ft:  size/cap = " << v3.size() << " / " << v3.capacity() << endl;


	// std::vector<int> v4;
	// std::vector<int> v5;
	// ft::vector<int> v6;
	// ft::vector<int> v7;

	// std::vector<int>::iterator it;
	// ft::vector<int>::iterator it1;

	// cout << (v4 == v5 ? "true" : "false") << endl;
	// cout << (v6 == v7 ? "true" : "false") << endl;


	// cout << endl << " ============= STACK ================  " << endl;
	// ft::stack<int> s1;
	// cout << "empty = " << s1.empty() << endl;
	// cout << "size = " << s1.size() << endl;
	// s1.push(1);
	// s1.push(4);
	// s1.push(5);
	// s1.push(7);
	// s1.push(10);

	// cout << "top = " << s1.top() << endl;
	// cout << "empty = " << s1.empty() << endl;
	// cout << "size = " << s1.size() << endl;
	// for(int i = 0; i < 5; i++) {
	// 	cout << s1.top() << " ";
	// 	s1.pop();
	// }
	// cout << endl << "empty = " << s1.empty() << endl;
	// cout << "size = " << s1.size() << endl;


	/*cout << endl << " ============= ASSIGN ================  " << endl;
	v.assign(3, 15);
	v1.assign(3, 15);
	for(int i = 0; i < 20; i++) {
		cout << v[i] << " " << v1[i] << endl;
	}
	cout << endl << "std: size/cap = " << v.size() << " / " << v.capacity() << endl;
	cout << endl << "ft : size/cap = " << v1.size() << " / " << v1.capacity() << endl;
	v.assign(10, 100);
	v1.assign(10, 100);
	for(int i = 0; i < 20; i++) {
		cout << v[i] << " " << v1[i] << endl;
	}
	cout << endl << "std: size/cap = " << v.size() << " / " << v.capacity() << endl;
	cout << endl << "ft : size/cap = " << v1.size() << " / " << v1.capacity() << endl;

	std::vector<int> v3;
	for(int i = 0; i < 15; i++) {
		v3.push_back(100 + i);
	}*/

	// std::vector<int>::iterator it_3 = v3.begin();

	// for(int i = 0; i < 15; i++) {
	// 	cout << v[i] << "         " << v1[i] << endl;
	// }
	// cout << endl << "std: size/cap = " << v.size() << " / " << v.capacity() << endl;
	// cout << "ft : size/cap = " << v1.size() << " / " << v1.capacity() << endl;
	// v.assign(it + 2, it + 3);
	// v1.assign(it + 2, it + 3);
	// cout << endl;
	// for(int i = 0; i < 15; i++) {
	// 	cout << v[i] << "         " << v1[i] << endl;
	// }
	// cout << endl << "std: size/cap = " << v.size() << " / " << v.capacity() << endl;
	// cout << endl << "ft : size/cap = " << v1.size() << " / " << v1.capacity() << endl;
	// v.assign(it, it + 10);
	// v1.assign(it, it + 10);
	// cout << endl;
	// for(int i = 0; i < 15; i++) {
	// 	cout << v[i] << "         " << v1[i] << endl;
	// }
	// cout << endl << "std: size/cap = " << v.size() << " / " << v.capacity() << endl;
	// cout << endl << "ft : size/cap = " << v1.size() << " / " << v1.capacity() << endl;
	

	// cout << endl << " ============= INSERT ================  " << endl;
	// it = v.begin() + 2;
	// it1 = v1.begin() + 2;
	// v.insert(it, 500);
	// v1.insert(it1, 500);
	// cout << v[0] << " std: size/cap = " << v.size() << " / " << v.capacity() << endl;
	// cout << v1[0]  << " ft : size/cap = " << v1.size() << " / " << v1.capacity() << endl;
	// it = v.end();
	// it1 = v1.end();
	// v.insert(it, 1111);
	// v1.insert(it1, 1111);
	// cout << v[0] << " " << "std: size/cap = " << v.size() << " / " << v.capacity() << endl;
	// cout << v1[0] << " " << "ft : size/cap = " << v1.size() << " / " << v1.capacity() << endl;
	// for(int i = 0; i < 10; i++) {
	// 	cout << v[i] << " " << v1[i] << endl;
	// }

	// it = v.begin() + 2;
	// it1 = v1.begin() + 2;
	// v.insert(it, 5, 500);
	// v1.insert(it1, 5, 500);
	// cout << v[0] << " std: size/cap = " << v.size() << " / " << v.capacity() << endl;
	// cout << v1[0]  << " ft : size/cap = " << v1.size() << " / " << v1.capacity() << endl;
	// it = v.end();
	// it1 = v1.end();
	// v.insert(it, 3, 1111);
	// v1.insert(it1, 3, 1111);
	// cout << v[0] << " " << "std: size/cap = " << v.size() << " / " << v.capacity() << endl;
	// cout << v1[0] << " " << "ft : size/cap = " << v1.size() << " / " << v1.capacity() << endl;
	// for(int i = 0; i < 20; i++) {
	// 	cout << v[i] << " " << v1[i] << endl;
	// }

	// it2 = v01.begin() + 1;
	// it3 = v01.begin() + 7;
	// it = v.begin() + 3;
	// it1 = v1.begin() + 3;
	// v.insert(it, it2, it3);
	// v1.insert(it1, it2, it3);
	// cout << v[0] << " std: size/cap = " << v.size() << " / " << v.capacity() << endl;
	// cout << v1[0]  << " ft : size/cap = " << v1.size() << " / " << v1.capacity() << endl;
	// it = v.end();
	// it1 = v1.end();
	// v.insert(it, it2, it3);
	// v1.insert(it1, it2, it3);
	// cout << v[0] << " " << "std: size/cap = " << v.size() << " / " << v.capacity() << endl;
	// cout << v1[0] << " " << "ft : size/cap = " << v1.size() << " / " << v1.capacity() << endl;
	// for(int i = 0; i < 20; i++) {
	// 	cout << v[i] << " " << v1[i] << endl;
	// }

	// cout << endl << " =============   ERASE  ================  " << endl;
	// it = v.begin() + 2;
	// it1 = v1.begin() + 2;
	// v.erase(it);
	// v1.erase(it1);
	// for(int i = 0; i < 5; i++) {
	// 	cout << v[i] << " " << v1[i] << endl;
	// }
	// cout << "==============" << endl;
	// it = v.begin() + 2;
	// it1 = v1.begin() + 2;
	// v.erase(it);
	// v1.erase(it1);
	// for(int i = 0; i < 5; i++) {
	// 	cout << v[i] << " " << v1[i] << endl;
	// }
	// cout << "==============" << endl;
	// it = v.begin() + 1;
	// it1 = v1.begin() + 1;
	// v.erase(it);
	// v1.erase(it1);
	// for(int i = 0; i < 5; i++) {
	// 	cout << v[i] << " " << v1[i] << endl;
	// }

	// it = v.begin() + 2;
	// it1 = v1.begin() + 2;
	// it_end = v.begin() + 4;
	// it_end1 = v1.begin() + 4;
	// v.erase(it, it_end);
	// v1.erase(it1, it_end1);
	// for(int i = 0; i < 5; i++) {
	// 	cout << v[i] << " " << v1[i] << endl;
	// }
	// cout << "std: size/cap = " << v.size() << " / " << v.capacity() << endl;
	// cout << "ft : size/cap = " << v1.size() << " / " << v1.capacity() << endl;
	// it = v.begin();
	// it1 = v1.begin();
	// it_end = v.begin() + 3;
	// it_end1 = v1.begin() + 3;
	// v.erase(it, it_end);
	// v1.erase(it1, it_end1);
	// for(int i = 0; i < 5; i++) {
	// 	cout << v[i] << " " << v1[i] << endl;
	// }
	// cout << "std: size/cap = " << v.size() << " / " << v.capacity() << endl;
	// cout << "ft : size/cap = " << v1.size() << " / " << v1.capacity() << endl;

	// cout << endl << " =============   SWAP  ================  " << endl;
	// ft::vector<int> v0;
	// for(int i = 0; i < 15; i++) {
	// 	v0.push_back(100 + i);
	// }
	// cout << "1: size/cap = " << v1.size() << " / " << v1.capacity() << ", arr = " ;
	// for(int i = 0; i < v1.size(); i++) {
	// 	cout << v1[i] << " ";
	// }
	// cout << endl << "2: size/cap = " << v0.size() << " / " << v0.capacity() << ", arr = " ;
	// for(int i = 0; i < v0.size(); i++) {
	// 	cout << v0[i] << " ";
	// }
	// v1.swap(v0);
	// cout << endl << "after swap: " << endl;
	// cout << "1: size/cap = " << v1.size() << " / " << v1.capacity() << ", arr = ";
	// for(int i = 0; i < v1.size(); i++) {
	// 	cout << v1[i] << " ";
	// }
	// cout << endl << "2: size/cap = " << v0.size() << " / " << v0.capacity() << ", arr = " ;
	// for(int i = 0; i < v0.size(); i++) {
	// 	cout << v0[i] << " ";
	// }
	// cout << endl;


}