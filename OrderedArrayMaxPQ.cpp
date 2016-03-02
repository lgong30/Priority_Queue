#include <iostream>
#include <string>
#include <functional>   // std::less

using namespace std;
// class template
template <class KEY, class Compare = less<KEY> >
class OrderedArrayMaxPQ{
	KEY *pq;	// elements
	int N; 		// number of elements
	Compare Less; // less function
public:
	OrderedArrayMaxPQ(int capacity,Compare uLess = Compare()){
		pq = new KEY[capacity];
		N = 0;
		Less = uLess;
	}
	bool isEmpty(){ return N == 0; }
	int size() { return N; }
	KEY delMax() { return pq[--N]; }

	void insert(KEY key){
		int i = N - 1;

		while (i >= 0 && Less(key,pq[i])){
			pq[i + 1] = pq[i];
			-- i;
		}
		pq[i + 1] = key;
		++ N;
	}

};

int main()
{
	OrderedArrayMaxPQ<string> pq(10);
	pq.insert("this");
	pq.insert("is");
	pq.insert("a");
	pq.insert("test");

	while (!pq.isEmpty())
	{
		cout << pq.delMax() << endl;
	}
	return 0;
}