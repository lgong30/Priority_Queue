#include <iostream>
#include <string>
#include <functional>   // std::less

using namespace std;
// class template
template <class KEY, typename Compare = less<KEY> >
class UnorderedArrayMaxPQ{
	KEY *pq; // elements
	int N; // number of elements
	Compare Less;// less function for type KEY
    void exch(int i,int j)
    {
    	KEY tmp = pq[i];
    	pq[i] = pq[j];
    	pq[j] = tmp;
    }
public:
	UnorderedArrayMaxPQ(int capacity,Compare uLess = Compare()){
		pq = new KEY[capacity];
		N = 0;
		Less = uLess;
	}
	bool isEmpty(){return N == 0;}
	int size(){ return N; }
	void insert(KEY x){pq[N++] = x;}

	KEY delMax(){
		int maxElem = 0;
		for (int i = 1;i < N;++ i)
		{
			if (Less(pq[maxElem],pq[i])) maxElem = i;
		}
		exch(maxElem,N - 1);

		return pq[--N];

	}
};



int main()
{
	UnorderedArrayMaxPQ<string> pq(10);
	pq.insert("this");
	pq.insert("is");
	pq.insert("a");
	pq.insert("test");
	while (!pq.isEmpty())
		cout << pq.delMax() << endl;

	return 0;
}