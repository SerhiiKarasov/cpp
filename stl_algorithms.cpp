#include <algorithm>
#include <vector>
#include <iostream>

int main()
{

    std::vector<int> numbers{9, 0, 1, 2, 3, 4, 5, 6, 7, 8, 10};
    //a heap is a datastructure every node is smaller then it's children
    // max heap in c++ is actually vice verse
    // it can be squashed into a range -> take first, second, third etc row
    //it is used to find a max value quickly(it is in front)
    for (auto i : numbers) std::cout << i << ' ';
    std::cout << std::endl;
    std::make_heap(begin(numbers), end(numbers));
    for (auto i : numbers) std::cout << i << ' ';
    std::cout << std::endl;
    numbers.push_back(11);
    std::push_heap(begin(numbers), end(numbers));
    for (auto i : numbers) std::cout << i << ' ';
    std::cout << std::endl;
    std::pop_heap(begin(numbers), end(numbers));//it swaps last elements with the first one, now moves elements to become a heap again
    std::sort_heap(begin(numbers), end(numbers)); //sorts heap using pop_heap

    //sort
    //partial sort makes e.g. beginning of collection sorted(everything is sorted), other part is unsorted
    //nth_element give a value of located at some index in collection, if the collection is sorted, like n-th biggest value, and on left everything is smaller, on the right not smaller
    //sort_heap
    //inplace merge , merges two sorted collections
} 