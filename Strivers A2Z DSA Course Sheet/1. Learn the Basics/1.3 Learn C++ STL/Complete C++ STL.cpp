// Complete C++ STL is divided into 4 parts:-
// 	1. Algorithms	2. Containers
//  3. Functions 	4. Iterators


#include <bits/stdc++.h>
using namespace std;



// PAIR
// it is a part of utility library

void explainPair() {

	pair<int, int> p = {1, 3};
	cout << p.first " " << p.second;

	pair<int, pair<int, int>> p = {1, {3, 4}};
	cout << p.first << " " << p.second.first << " " << p. second.second;

	pair<int, int> arr[] = {{1, 2}, {2, 5}, {5, 1}};
	cout << arr[1].first << " " << arr[1].second;

}



// VECTOR
// it is a container that's dynamic in nature
// vector functions are similar in
//	other DSs like queue, list, map, set
// the internal operation is kinda like a singly linked list

void explainVector() {

	vector<int> v; // creates an empty container

	v.push_back(1); // {1}
	v.emplace_back(2); // similar to push-back and
	//	faster {1, 2}

	vector<pair<int, int>> vec;

	v.push_back({1, 2});
	v.emplace_back(1, 2);

	vector<int> v(5, 100) // (size,element) {100, 100, 100, 100, 100}

	vector<int> v(5); //{0, 0, 0, 0, 0}

	vector<int> v1(5, 20);
	vector<int> v2(v1); // copy one vector to another

	//accessing elements the easy way
	vector<int> v{20, 10, 15, 6, 7};
	cout << v[0] << " " << v.at(1); // 20 10


	//accessing using iterator
	vector<int> v{20, 10, 15, 6, 7};
	vector<int>::iterator it = v.begin();
	// here 'it' iterator points to the memory location where the first elements is stored
	// so we use pointers to point to the memory locations

	it++;
	cout << *(it) << " "; // 10

	it = it + 2;
	cout << *(it) << " "; // 6

	//other iterators
	vector<int>:: iterator it1 = v.end();
	// end points to a memory location after the last element

	vector<int>:: iterator it2 = v.rend();
	// rend points to a memory location before the first element
	vector<int>:: iterator it3 = v.rbegin();
	// rbegin points to the memory location of the last element
	// if we do it++ here, then it moves to the 2nd last element and so on.

	cout << v.back() << " "; // points to the last element

	// printing the elements
	// simplest way using for loop from 0 to n
	// another way is to use iterator

	for (vector<int>::iterator it = v.begin(); it != v.end(); it++) {
		cout << *(it) << " ";
	}

	// shorter way to do the same
	// auto automatically assigns the vector to an iterator
	for (auto it = v.begin(); it != v.end(); it++) {
		cout << *(it) << " ";
	}

	// another way to write it
	for (auto it : v) {
		cout << *(it) << " ";
	}

	// Deletion in vector
	// {10, 20, 12, 23}
	v.erase(v.begin() + 1); // 20 is deleted

	// { 10, 20, 30, 40, 50}
	v.erase(v.begin() + 1, v.begin() + 3); // erase(start, end)
	// deletes 20, 30
	// {10, 20, 12, 23, 35}
	v.erase(v.begin() + 2, v.begin() + 4); // {10, 20, 35} {start, end}


	// Insert function -
	// insert in a vector is costly
	vector<int> v(2, 100); // {100, 100}
	v.insert(v.begin(), 300); // {300, 100, 100}
	v.insert(v.begin() + 1, 2, 10); // {300, 10, 10, 100, 100}

	vector<int> copy(2, 50); //{50, 50}
	v.insert(v.begin(), copy.begin(), copy.end()); // {50, 50, 300, 10, 10, 100, 100}

	// {10, 20}
	cout << v.size(); // 2

	// {10, 20}
	v.pop_back(); // 10; removes 20, the last element

	// v1 -> {10, 20}
	// v2 -> {30, 40}
	v1.swap(v2); // v1 -> {30, 40}, v2 -> {10, 20}

	v.clear(); // erases the entire vector

	v.empty(); // returns true or false accordingly

}



// LIST
// it is a container similar to vector
// but it gives you front operations too
// the internal operation is kinda like a doubly linked list
// that's why push_front is very cheap in case of list

void explainList() {

	list<int> ls;

	ls.push_back(2); //{2}
	ls.emplace_back(4); // {2, 4}

	ls.push_front(5); // {5, 2, 4}
	ls.emplace_front(6); // {6, 5, 2, 4}

	// the rest of the functions are same as vector
	// begin(), end(), rbegin(), rend(), clear(), insert(), swap()

}



// DEQUE
// it is a container too,
//		exactly similar to list and almost to vector
// it gives you front operations too
// STL deque is a sequential container
// 		that provides the functionality of a
// 		double-ended queue data structure

void explainDeque() {

	deque<int> dq;
	dq.push_back(1); // {1}
	dq.emplace_back(2); // {1, 2}
	dq.push_front(4); // {4, 1, 2}
	dq.emplace_front(3) // {3, 4, 1, 2}

	dq.pop_back() // {3, 4, 1}
	dq.pop_front(); // {4, 1}

	dq.back(); // points to the last element
	dq.front() // points to the first element

	// the rest of the functions are same as vector
	// begin(), end(), rbegin(), rend(), clear(), insert(), swap()

}


// STACK
// it is a container in LIFO manner
// all operations in stack are in O(1) time

void explainStack() {

	stack<int> st;
	//functions - push, pop, top, swap
	st.push(1); // {1}
	st.push(2); // {2, 1}
	st.push(3); // {3, 2, 1}
	st.push(4); // {4, 3, 2, 1}
	st.emplace(5); // {5, 4, 3, 2, 1}

	cout << st.top(); // prints 5
	// here indexed access is not allowed
	// for ex. st[2] is a invalid use

	st.pop(); // {4, 3, 2, 1}

	cout << st.top(); // prints 4
	cout << st.size(); // 4
	cout << st.empty(); // false

	stack<int> st1, st2;
	st1.swap(st2);

}



// QUEUE
// it is a container in FIFO manner

void explainQueue() {

	queue<int> q;
	q.push(1); // {1}
	q.push(2); // {1, 2}
	q.emplace(4); // {1, 2, 4}

	q.back() += 5; // 4 + 5 = 9; {1, 2, 9}

	cout << q.back(); // prints 9

	// {1, 2, 9}
	cout << q.front(); // prints 1

	q.pop(); // {2, 9}

	cout << q.front(); // prints 2

	// size, swap, empty are same as stack

}



// PRIORTY QUEUE
// it is a container too, almost similar to queue
// element with the largest value stays at the top
// here values are not stored in a linear fashion
// instead, a tree is maintained inside
// push happens in O(log n)
// top happens in O(1)
// pop happens in O(log n)

void explainPriortyQueue() {

	// Max Heap
	priorty_queue<int> pq;

	pq.push(5); // {5}
	pq.push(2); // {5 , 2}
	pq.push(8); // {8, 5, 2}
	pq.emplace(10); // {10, 8, 5, 2}

	cout << pq.top(); // prints 10

	pq.pop(); // {8, 5, 2}

	cout << pq.top(); // prints 8

	// size, swap, empty functions same as others

	// if I want a priorty queue that stores
	// 	minimum element at the top, then

	// Minimum Heap / minimum priorty queue
	priorty_queue<int, vector<int>, greater<int>> pq;
	pq.push(5); // {5}
	pq.push(2); // {2, 5}
	pq.push(8); // {2, 5, 8}
	pq.push(10); // {2, 5, 8, 10}

	cout << pq.top(); // prints 2

}



// SET
// it is a container too
// it stores everything in sorted order and are unique
// here values are not stored in a linear fashion
// instead, a tree is maintained inside
// In Set, everything happens in O(log n) time

void explainSet() {

	set<int> st;
	st.insert(1); // {1}
	st.emplace(2); // {1 ,2}
	st.insert(2); // {1, 2}
	st.insert(4); // {1, 2, 4}
	st.insert(3); // {1, 2, 3, 4}

	//	Functionality of insert in vector can be also used
	// that only increases efficiency

	// begin(), end(), rbegin(), rend(), size()
	// empty() and swap() are same as those of above

	// {1, 2, 3, 4, 5}
	auto it = st.find(3);
	// returns an iterator which points to 3

	auto it = st.find(6);
	// returns st.end() if the element is not present
	// so here it returns an iterator which points to
	//	 the location after the last element

	st.erase(5); // erases or deletes 5
	// takes logarithmic time

	int count = st.count(1);
	// return 1 or 0 since the elements are unique

	auto it = st.find(3);
	st.erase(it); // it takes constant time

	// {1, 2, 3, 4, 5}
	auto it1 = st.find(2);
	auto it2 = st.find(4);
	st.erase(it1, it2); // {1, 4, 5}
	// it deletes {2, 3}

	// lower_bound() and upper_bound() works
	// 	in the same way as vector does

	// this is the syntax
	auto it = st.lower_bound(2);

	auto it = st.upper_bound(3);

}



// MULTISET
// Everything is same as set,
// it stores everything in sorted manner but not unique
// i.e. it also stores duplicate elements

void explainMultiSet() {

	multiset<int> ms;
	ms.insert(1); // {1}
	ms.insert(1); // {1, 1}
	ms.insert(1); // {1, 1, 1}

	ms.erase(1); // {}; all 1's are erased

	int count = ms.count(1);

	multiset<int> ms {1, 1, 1};
	ms.erase(ms.find(1)); // {1, 1}
	ms.erase(ms.find(1), ms.find(1) + 2);
	// {1}

}



//UNORDERED SET
// Everything is similar to set
// it stores everything uniquely
// but it is not in sorted manner
// it has randomized order

void explainUnorderedSet() {

	unordered_set<int> st;
	// lower_bound and upper_bound function does not work
	// but all the rest of the functions are same as that of set
	// in almost all cases, it works in O(1) time
	// in worst cases (happens rarely), TC would be O(N)

}



// MAP
// it is a container which stores everything
// 	in {key, value}
// (key, value)
// keys are unique; key can use any datatype
// but the values can be duplicate; value can also use any datatype
// it works in O(log n) time

void explainMap() {

	map <int, int> mp;
	map<int, pair<int, int>> mp1;
	map<pair<int, int>, int> mp2;

	mp[1] = 2; // {{1, 2}}

	mp.emplace({3, 1}); // {{1, 2}, {3, 1}}
	mp.insert({2, 4}); // {{1, 2}, {2, 4}, {3, 1}}
	// map stores unique keys in sorted order

	mp[ {2, 3}] = 10; // { {{2,3}, 10} }

	// traversing or iterating over the map
	for (auto it : mp) {
		cout << it.first << " " << it.second;
	}

	cout << mp[1]; // prints the value 2

	cout << mp[5]; // prints 0 or null

	auto it = mp.find(3);
	cout << *(it).second;

	auto it = mp.find(5);
	cout << *(it).second; // points to mp.end()
	// if the key is not present

	auto it = mp.lower_bound(2);

	auto it = mp.upper_bound(3);

	// erase, swap, size and empty are same as above

}



// MULTIMAP

void explainMultiMap() {

	// Everything is same as map
	// except for the fact that we can store duplicate keys
	// here, only map[key] cannot be used

}



// UNORDERED MAP
// in almost  all cases, it works in O(1) time
// in worst cases (happens rarely), TC would be O(N)

void explainUnorderedMap() {

	// Similar to set
	// it has unique keys
	// but it is not in sorted manner
	// it has randomized order

}


// By this, Containers and Iterators are complete


// Important Algorithms that are mandatory

bool comp(pair<int, int> p1[], pair<int, int> p2[]) {
	// now while writing comparator,
	//think of having two pairs

	if (p1.second < p2.second) {
		return true;
	}
	if (p1.second > p2.second) {
		return false;
	}
	// when it's false,
	// the comparator internally swaps the values

	// if they are same
	if (p1.first > p2.first) {
		return true;
	}
	return false;


}



void explainExtra() {
// 1. Sorting Algorithm
	// Given
	int arr[];
	int n = sizeof(arr) / sizeof(arr[0]);
	sort(arr, arr + n); // in ascending order
	// we can use this for almost any container
	// except for map
	sort(arr, arr + n, greater<int>); // in descending order

	// but if I want to sort it my way? Then

	pair<int, int> arr[] = {{1, 2}, {2, 1}, {4, 1}};

	// sort it in ascending order according to second element
	// if second element is same, then sort it
	// according to first element but in descending order

	// so if we sort it in ascending order
	// {{2, 1}, {4, 1}, {1, 2}}
	// but here the 2nd element are same
	// then we have to sort those element having the same 2nd element
	// in descending order of 1st element
	// {{4, 1}, {2, 1}, {1, 2}}

	sort(arr, arr + n, comp);
	// this comp is nothing but a self-written comparator
	// and this comparator is a boolean function

	int num = 7;
	int count = __builtin_popcount();
	// returns the binary of 7, i.e. 111
	// if num was 6, then count = 110
	// it only returns the number of
	// said bits of the 32bit binary number


	long long num = 22232432323;
	int count = __builtin_popcountll();

	// Next Permutation
	string s = "123";
	// if s = " 231", then it would only 3 permutations
	// so we need to start at the sorted string
	sort(s.begin(), s.end());

	do {
		cout << s << endl;
	} while (next_permutation(s.begin(), s.end()));
	// prints all the permutation of 123
	// 123 132 213 231 312 321 and exits at null

	// Max element and Min element
	int maxElement = *max_element(arr, arr + n);
	int minElement = *min_element(arr, arr + n);


}

int main() {

	return 0;
}