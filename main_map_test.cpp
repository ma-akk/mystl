#include <iostream>
#include <vector>
#include <stack>
// #include "vector.hpp"
// #include "iterators/iterator.hpp"
// #include "stack.hpp"
// #include "utils.hpp"
#include <map>
#include "map.hpp"

using std::cout;
using std::endl;


int main() {
	std::map<int, int> m0;
	m0[0] = 100;
	for(std::map<int, int>::iterator it = m0.begin(); it != m0.end(); ++it) {
		cout << it->first << " " << it->second << endl;
	}
	cout << "size/count : " << m0.size() << " " << endl; 
	m0[1] = 101;
	cout << "size/count : " << m0.size() << " " << endl; 
	m0[2] = 102;
	cout << "size/count : " << m0.size() << " " << endl; 
	m0[3] = 103;
	cout << "size/count : " << m0.size() << " " << endl; 
	m0[4] = 14;
	cout << "size/count : " << m0.size() << " " << endl; 
	m0[5] = 105;
	m0[10] = 110;

	m0.insert(std::make_pair(7, 107));

	std::map<int, int>::iterator it = m0.begin();
	for( ; it != m0.end(); ++it) {
		cout << it->first << " " << it->second << endl;
	}
	// cout << it->first << " " << it->second << endl;
	// cout << it->first << " " << it->second << endl;
	// cout << it->first << " " << it->second << endl;
	// cout << it->first << " " << it->second << endl;

	std::map<int, int> mEmp;
	cout << "size/count : " << mEmp.size() << " map = "  << mEmp[0] << endl;
	ft::map<int, int> m5;
	cout << "size/count : " << mEmp.size() << " map = "  << mEmp[0] << endl;



}