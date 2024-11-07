#pragma once
#include <map>
#include <vector>

struct Node;
typedef std::pair<int, std::pair<Node*, Node*>> MyPair;
typedef std::pair<int, std::pair<int, int>> MyPair_heap;

class Max_heap
{
private:
	std::vector<MyPair_heap> *heap;
	void upheap(MyPair_heap* hijo, MyPair_heap* padre, int* i);
	void downheap(int i);
	int parent(int i) { return (i) / 2; }
	void swap(MyPair_heap* x, MyPair_heap* y);
public:
	Max_heap(std::map<std::pair<int, int>, MyPair> map_frequency,const int size);
	Max_heap(const int);
	~Max_heap();
	void insert(MyPair_heap values);
	void removeMax();
	MyPair_heap top();
	void printHeap();
	int size();
	void mod_key(int new_key, std::pair<int,int> values);

};
