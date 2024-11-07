#include "Max_heap.h"
#include <algorithm>
#include <iostream>

Max_heap::Max_heap(std::map<std::pair<int, int>, MyPair> map_frequency, const int size)
{
	MyPair_heap extra;
	MyPair_heap extra2;
	heap = new std::vector<MyPair_heap>();
	heap->push_back(extra2);
	//SE A�ADE CADA PAR AL HEAP.
	for (std::map<std::pair<int, int>, MyPair>::iterator iterator_map = map_frequency.begin(); iterator_map != map_frequency.end(); iterator_map++) {
		extra.first = iterator_map->second.first;
		extra.second = iterator_map->first;
		insert(extra);
	}
}

int Max_heap::size()
{
	return heap->size()-1;
}

Max_heap::~Max_heap(){
	delete heap;
}

void Max_heap::insert(MyPair_heap values)
{
	int i = size();
	heap->push_back(values);
	i++;
	while (i != 1 && heap->at(parent(i)).first < heap->at(i).first){
		upheap(&heap->at(i), &heap->at(parent(i)), &i);
	}
}

void Max_heap::removeMax(){
	if(size() < 1) return;
	if (size() == 1) {
		heap->erase(heap->begin() + size());
		return;
	}else {
			heap->at(1) = heap->back();
			heap->erase(heap->begin()+size());
			downheap(1);
	}

}
MyPair_heap Max_heap::top(){
		MyPair_heap extra;
		if (size() < 1) return extra;
		extra = heap->at(1);
		return extra;
}

void Max_heap::upheap(MyPair_heap* hijo, MyPair_heap* padre, int* i)
{
	swap(hijo,padre);
	*i = parent(*i);
}

void Max_heap::downheap(int i)
{
	int left = 2 * i;
	int right = left + 1;
	int extra = i;

	if (left <= size() && heap->at(left).first > heap->at(i).first) {
		extra = left;
	}
	if (right <= size() && heap->at(right).first > heap->at(extra).first) {
		extra = right;
	}
	if (extra != i) {
		swap(&heap->at(i), &heap->at(extra));
		downheap(extra);
	}
}

void Max_heap::swap(MyPair_heap* x, MyPair_heap* y)
{
	MyPair_heap extra = *y;
	*y = *x;
	*x = extra;
}

void Max_heap::printHeap()
{
	std::cout << "-----------------------------------------------" << std::endl;
	std::cout << "HEAP" << std::endl;
	for (std::vector<MyPair_heap>::iterator iter = heap->begin()+1; iter != heap->end(); iter++) {
			std::cout << "Clave(Freq): " << iter->first << " " << "Par: (" << iter->second.first << "," << iter->second.second << ")" << std::endl;

	}
}

void Max_heap::mod_key(int new_key,std::pair<int,int> values){
	for (size_t i = 1; i < heap->size(); i++) {
		if (heap->at(i).second == values) {
			int j = i;
			heap->at(i).first = heap->at(i).first + new_key;
			downheap(i);
			while (j != 1 && heap->at(parent(j)) < heap->at(j)) {
				upheap(&heap->at(j), &heap->at(parent(j)), &j);
			}
			break;
		}
	}
}
