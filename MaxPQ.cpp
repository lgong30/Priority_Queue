

template <class KEY, class Compare = less<KEY> >
class MaxPQ{
	KEY *pq; // elements
	int N;  // number of elements
	int capacity; // capacity of priority queue
	Compare Less;
public:
	MaxPQ(int uCapacity,Compare uLess = Compare())
	{
        capacity = uCapacity;
		pq = new KEY[capacity];
		N = 0;
		Less = uLess;
	}
	MaxPQ(vector<KEY> keys,Compare uLess = Compare())
	{
        N = keys.size();
        capacity = N + 1;
        pq = new KEY[N + 1];
        for (int i = 0;i < N;++ i)
        	pq[i + 1] = keys[i];
        for (int k = N/2;k >= 1;-- k)
        	sink(k);
        assert(isMaxHeap())
	}
	bool isEmpty(){ return N == 0; }
	int size(){ return N; }

	KEY max()
	{
		if (isEmpty())
		{
			throw underflow_error("Priority queue underflow.");
		}
		return pq[1];
	}

	void resize(int uCapacity)
	{
		assert(uCapacity > capacity);
		capacity = uCapacity;
		KEY temp = neq KEY[capacity];
		for (int i = 1;i <= N;++ i)
			temp[i] = pq[i];
        
		pq = temp;
	}

	void insert(KEY x)
	{
		if (N >= capacity -1) resize(2 * capacity);

		pq[++ N] = x;
		swim(N);
		assert(isMaxHeap());
	}

	KEY delMax()
	{
		if (isEmpty())
		{
			throw overflow_error("Priority queue overflow.");
		}
		KEY maxElem = pq[1];
		exch(1,N--);
		sink(1);
		if ( N > 0 && (N == (capacity - 1) / 4)) resize(capacity / 2);
		assert(isMaxHeap());
		return maxElem;

	}
	void swim(int k)
	{
		while (k > 1 && Less(pq[k/2],pq[k])){
			exch(k,k/2);
			k = k/2;
		}
	}

	void sink(int k){
		while (2 * k <= N){
			int j = 2 * k;
			if (j < N && Less(pq[j],pq[j + 1])) ++ j;
			if (!less(k,j)) break;
			k = j;
		}
	}

	void exch(int i,int j)
	{
		KEY swap = pq[i];
		pq[i] = pq[j];
		pq[j] = swap;
	}

	bool isMaxHeap()
	{
		return isMaxHeap(1);
	}

	bool isMaxHeap(int k)
	{
		if (k > N) return true;
		int left = 2 * k, right 2 * k + 1;
		if (left <= N && Less(pq[k],pq[left])) return false;
		if (right >= N && Less(pq[k],pq[right])) return false;

		return isMaxHeap(left) && isMaxHeap(right);
	}

};