#include <iostream>
#include <set>
#include "set.hpp"

using std::cout;
using std::endl;

void	testInsert()
{
	cout << "================= INSERT =========================" << endl;
	ft::set<char> myset;

	// first insert function version (single parameter):
	myset.insert('a');
	myset.insert('z');

	ft::pair<ft::set<char, int>::iterator, bool> ret;
	ret = myset.insert('z');
	if (ret.second == false)
	{
		std::cout << "element 'z' already existed";
		std::cout << " with a value of " << *(ret.first) << '\n';
	}

	// second insert function version (with hint position):
	ft::set<char>::iterator it = myset.begin();
	myset.insert(it, 'b'); // max efficiency inserting
	myset.insert(it, 'c'); // no max efficiency inserting

	// third insert function version (range insertion):
	ft::set<char> anotherset;
	anotherset.insert(myset.begin(), myset.find('c'));

	// showing contents:
	// myset.clear();
	myset.insert(it, 'b'); // max efficiency inserting
	myset.insert(it, 'c'); // no max efficiency inserting
	std::cout << "myset contains:\n";
	for (it = myset.begin(); it != myset.end(); ++it)
		std::cout << *it <<  " ";

	std::cout << "anotherset contains:\n";
	for (it = anotherset.begin(); it != anotherset.end(); ++it)
		std::cout <<  *it <<  " ";
}

void	clear()
{
	cout << "================= CLEAR =========================" << endl;
	ft::set<int> myset;
	for (int i = 0; i < 5; i++) {
		myset.insert(100);
	}
	
	std::cout << "myset size: " << myset.size() << std::endl;
	std::cout << "myset contains:\n";
	for (ft::set<int>::iterator it = myset.begin(); it != myset.end(); ++it)
		std::cout <<  *it <<  " ";

	myset.clear();
	myset.insert(555);
	myset.insert(555);
	std::cout << "myset size: " << myset.size() << std::endl;
	std::cout << "myset contains:\n";
	for (ft::set<int>::iterator it = myset.begin(); it != myset.end(); ++it)
		std::cout <<  *it <<  " ";
}

void	count()
{
	cout << "================= COUNT =========================" << endl;
	ft::set<char> myset;
	char c;
	myset.insert('a');
	myset.insert('b');
	myset.insert('c');

	for (c = 'a'; c < 'h'; c++)
	{
		std::cout << c;
		if (myset.count(c) > 0)
			std::cout << " is an element of myset.\n";
		else
			std::cout << " is not an element of myset.\n";
	}
}

void	empty()
{
	cout << "================= EMPTY =========================" << endl;
	ft::set<char> myset;

	myset.insert('a');
	myset.insert('b');
	myset.insert('c');

	while (!myset.empty())
	{
		std::cout << *myset.begin() << '\n';
		myset.erase(myset.begin());
	}
}

void	erase()
{
	cout << "================= ERASE =========================" << endl;
	ft::set<char> myset;
	ft::set<char>::iterator it;

	// insert some values:
	myset.insert('a');
	myset.insert('b');
	myset.insert('c');
	myset.insert('x');
	myset.insert('y');
	myset.insert('z');

	it = myset.find('b');
	myset.erase(it); // erasing by iterator
	cout << "After erase myset['b'] : " << endl;
	for (it = myset.begin(); it != myset.end(); ++it)
		std::cout <<  *it <<  " ";
	
	myset.erase('c'); // erasing by key
	cout << "After erase myset['c'] : " << endl;
	for (it = myset.begin(); it != myset.end(); ++it)
		std::cout <<  *it <<  " ";
	
	it = myset.find('x');
	myset.erase(it, myset.end()); // erasing by range

	// show content:
	cout << "After erase myset['x']-['z'] : " << endl;
	for (it = myset.begin(); it != myset.end(); ++it)
		std::cout <<  *it <<  " ";
}

void	find()
{
	cout << "================= FIND =========================" << endl;
	ft::set<char> myset;
	ft::set<char>::iterator it;

	myset.insert('a');
	myset.insert('b');
	myset.insert('c');
	myset.insert('x');
	myset.insert('y');
	myset.insert('z');

	it = myset.find('b');
	if (it != myset.end())
		myset.erase(it);

	// print content:
	std::cout << "elements in myset:" << '\n';
	std::cout << *myset.find('a')<< " ";
	std::cout << *myset.find('c') << " ";
	std::cout << *myset.find('x') << " ";
}

void	equal_range()
{
	cout << "================= EQUAL_RANGE =========================" << endl;
	ft::set<int> myset;

	myset.insert(10);
	myset.insert(20);
	myset.insert(30);
	myset.insert(40);
	myset.insert(50);
	myset.insert(60);

	ft::pair<ft::set<int>::iterator, ft::set<int>::iterator> ret;
	ret = myset.equal_range('c');

	std::cout << "lower bound points to: ";
	std::cout << *(ret.first) << " " << *(ret.second) << '\n';

	std::cout << "upper bound points to: ";
	std::cout << *(ret.first) << " " << *(ret.second) << '\n';
}

void	get_allocator()
{
	cout << "================= GET ALLOCATOR =========================" << endl;
	int psize;
	ft::set<int> myset;
	int *p;

	// allocate an array of 5 elements using myset's allocator:
	p = myset.get_allocator().allocate(5);

	// assign some values to array
	psize = sizeof(ft::set<int>::value_type) * 5;

	std::cout << "The allocated array has a size of " << psize << " bytes.\n";

	myset.get_allocator().deallocate(p, 5);
}

// void	key_comp()
// {
// 	cout << "================= KEY_COMPARE =========================" << endl;
// 	ft::set<int> myset;

// 	ft::set<int>::key_compare mycomp = myset.key_comp();

// 	myset.insert(200);
// 	myset.insert(300);
// 	myset.insert(400);
// 	myset.insert(500);
// 	myset.insert(600);

// 	std::cout << "myset contains:\n";

// 	char highest = 400; // key value of last element

// 	ft::set<int>::iterator it = myset.begin();
// 	do
// 	{
// 		std::cout << *it << '\n';
// 	} while (mycomp((*it++).first, highest));

// 	std::cout << '\n';
// }

void	lower_bound()
{
	cout << "================= LOWER_UPPER_BOUND =========================" << endl;
	ft::set<char> myset;
	ft::set<char>::iterator itlow, itup;

	myset.insert('a');
	myset.insert('b');
	myset.insert('c');
	myset.insert('x');
	myset.insert('y');
	myset.insert('z');

	cout << "Start with : " << endl;
	for (ft::set<char>::iterator it = myset.begin(); it != myset.end(); ++it)
		std::cout <<  *it <<  " ";

	itlow=myset.lower_bound ('b');  // itlow points to b
	itup=myset.upper_bound ('d');   // itup points to e (not d!)

	myset.erase(itlow, itup); // erases [itlow,itup)

	// print content:
	for (ft::set<char>::iterator it = myset.begin(); it != myset.end(); ++it)
		std::cout <<  *it <<  " ";
}

void	max_size()
{
	cout << "================= MAX_SIZE =========================" << endl;
	int i;
	ft::set<int> myset;

	if (myset.max_size() > 1000)
	{
		for (i = 0; i < 1000; i++)
			myset.insert(i);
		std::cout << "The set contains 1000 elements.\n";
	}
	else
		std::cout << "The set could not hold 1000 elements.\n";
}

void	operatorEqual()
{
	cout << "================= operator = =========================" << endl;
	ft::set<int> first;
	ft::set<int> second;

	first.insert(200);
	first.insert(300);
	first.insert(400);
	first.insert(500);
	first.insert(600);

	second = first;				   // second now contains 3 ints
	first = ft::set<int>(); 		// and first is now empty

	std::cout << "Size of first: " << first.size() << '\n';
	std::cout << "Size of second: " << second.size() << '\n';
}

void	size()
{
	cout << "================= SIZE =========================" << endl;
	ft::set<char> myset;
	myset.insert('a');
	myset.insert('b');
	myset.insert('c');
	myset.insert('x');
	myset.insert('y');
	myset.insert('z');

	std::cout << "myset.size() is " << myset.size() << '\n';
}

void	swap()
{
	cout << "================= SWAP =========================" << endl;
	ft::set<int> foo, bar;

	foo.insert(20);
	foo.insert(30);

	bar.insert(22);
	bar.insert(55);
	bar.insert(66);

	foo.swap(bar);

	std::cout << "foo contains:\n";
	for (ft::set<int>::iterator it = foo.begin(); it != foo.end(); ++it)
		std::cout <<  *it <<  " ";

	std::cout << "bar contains:\n";
	for (ft::set<int>::iterator it = bar.begin(); it != bar.end(); ++it)
		std::cout <<  *it <<  " ";
}

// void	value_comp()
// {
// 	cout << "================= VALUE_COMPARE =========================" << endl;
// 	ft::set<char, int> myset;

// 	myset.insert(22);
// 	myset.insert(55);
// 	myset.insert(66);

// 	std::cout << "myset contains:\n";

// 	ft::pair<char, int> highest = *--myset.end(); // last element

// 	ft::set<char, int>::iterator it = myset.begin();
// 	do
// 	{
// 		std::cout << it->first << " => " << it->second << '\n';
// 	} while (myset.value_comp()(*it++, highest));
// }

bool fncomp(char lhs, char rhs) { return lhs < rhs; }

struct classcomp
{
	bool operator()(const char &lhs, const char &rhs) const
	{
		return lhs > rhs;
	}
};

void	construct()
{
	cout << "================= CONSTRUCTOR =========================" << endl;
	ft::set<int> first;

	first.insert(22);
	first.insert(55);
	first.insert(66);

	ft::set<int> second(first.begin(), first.end());

	ft::set<int> third(second);

	ft::set<int, classcomp> fourth; // class as Compare
	fourth.insert(10);
	fourth.insert(10);
	fourth.insert(10);
	fourth.insert(10);
	fourth.insert(10);
	fourth.insert(10);
	bool (*fn_pt)(char, char) = fncomp;
	ft::set<int, bool (*)(char, char)> fifth(fn_pt); // function pointer as Compare
	fifth.insert(90);
	fifth.insert(90);
	fifth.insert(90);
	fifth.insert(90);
	fifth.insert(90);
	fifth.insert(90);
	std::cout << "first contains: \n";
	for (ft::set<int>::iterator it = first.begin(); it != first.end(); ++it)
		std::cout << *it <<  " ";
	std::cout << "second contains: \n";
	for (ft::set<int>::iterator it = second.begin(); it != second.end(); ++it)
		std::cout << *it <<  " ";
	std::cout << "third contains: \n";
	for (ft::set<int>::iterator it = third.begin(); it != third.end(); ++it)
		std::cout  << *it <<  " ";
	std::cout << "fourth contains: \n";
	for (ft::set<int, classcomp>::iterator it = fourth.begin(); it != fourth.end(); ++it)
		std::cout  << *it <<  " ";
	std::cout << "fifth contains: \n";
	for (ft::set<int, bool (*)(char, char)>::iterator it = fifth.begin(); it != fifth.end(); ++it)
		std::cout  << *it <<  " ";
	std::cout << "asd\n";
}

void	reverse_iterator()
{
	cout << "================= REVERS_ITERATOR =========================" << endl;
	ft::set<int> myset;

	myset.insert(22);
	myset.insert(55);
	myset.insert(66);

	// show content:
	ft::set<int>::reverse_iterator rit = myset.rbegin();
	for (rit = myset.rbegin(); rit != myset.rend(); ++rit)
		std::cout << *rit << " ";
}

void	bool_check()
{
	cout << "================= BOOL OPERATIONS =========================" << endl;
	ft::set<char> foo, bar, moo;
	foo.insert('a');
	foo.insert('b');
	bar.insert('c');
	bar.insert('x');
	moo.insert('y');
	moo.insert('z');

	if (foo == bar)
		std::cout << "foo and bar are equal\n";
	if (foo != bar)
		std::cout << "foo and bar are not equal\n";
	if (foo == moo)
		std::cout << "foo and moo are equal\n";
	if (foo != moo)
		std::cout << "foo and moo are not equal\n";
	if (foo < bar)
		std::cout << "foo is less than bar\n";
	if (foo < moo)
		std::cout << "foo is less than moo\n";
	if (foo > bar)
		std::cout << "foo is greater than bar\n";
	if (foo <= bar)
		std::cout << "foo is less than or equal to bar\n";
	if (foo >= bar)
		std::cout << "foo is greater than or equal to bar\n";
	if (foo > moo)
		std::cout << "foo is greater than moo\n";
	if (foo <= moo)
		std::cout << "foo is less than or equal to moo\n";
	if (foo >= moo)
		std::cout << "foo is greater than or equal to moo\n";
}

void	non_member_swap()
{
	cout << "================= SWAP_II =========================" << endl;
	ft::set<char> foo, bar;

	foo.insert('a');
	foo.insert('b');
	bar.insert('y');
	bar.insert('x');

	ft::swap(foo, bar);

	std::cout << "foo contains:\n";
	for (ft::set<char, int>::iterator it = foo.begin(); it != foo.end(); ++it)
		std::cout << *it << " ";

	std::cout << "bar contains:\n";
	for (ft::set<char, int>::iterator it = bar.begin(); it != bar.end(); ++it)
		std::cout << *it << " ";
}

int		main()
{
	testInsert();
	// clear();
	// count();
	// empty();
	// erase();
	// find();
	// equal_range();
	// get_allocator();
	// lower_bound(); // it uses erase()
	// // stress_test();
	// max_size();
	// operatorEqual();
	// size();
	// swap();
	// construct();
	// reverse_iterator();
	// bool_check();
	// non_member_swap();
	// std::cout << "TEST IS FINISHED\n";
	// while (1);
	return 0;
}