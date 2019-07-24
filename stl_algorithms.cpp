#include <algorithm>
#include <vector>
#include <iostream>
#include <iterator>
#include <forward_list>
#include <random>
#include <numeric>
#include <functional>

template <class Iter>
void merge_sort(Iter first, Iter last)
{
    if (last - first > 1)
    {
        Iter middle = first + (last - first) / 2;
        merge_sort(first, middle);
        merge_sort(middle, last);
        std::inplace_merge(first, middle, last);
    }
}

int main()
{
    std::vector<int> numbers{9, 0, 1, 2, 3, 4, 5, 6, 7, 8, 10};

    // HEAP
    // a heap is a datastructure every node is smaller then it's children
    // max heap in c++ is actually vice verse
    // it can be squashed into a range -> take first, second, third etc row one by one
    // it is used to find a max value quickly(it is in front)
    for (auto i : numbers)
        std::cout << i << ' ';
    std::cout << std::endl;
    //https://en.cppreference.com/w/cpp/algorithm/make_heap. Constructs a max heap in the range [first, last).
    std::make_heap(begin(numbers), end(numbers));
    for (auto i : numbers)
        std::cout << i << ' ';
    std::cout << std::endl;
    numbers.push_back(11);
    //https://en.cppreference.com/w/cpp/algorithm/push_heap. Inserts the element at the position last-1 into the max heap defined by the range [first, last-1)
    std::push_heap(begin(numbers), end(numbers));
    for (auto i : numbers)
        std::cout << i << ' ';
    std::cout << std::endl;
    //https://en.cppreference.com/w/cpp/algorithm/pop_heap. Swaps the value in the position first and the value in the position last-1 and makes the subrange [first, last-1) into a max heap.
    std::pop_heap(begin(numbers), end(numbers));

    // SORT
    //https://en.cppreference.com/w/cpp/algorithm/sort_heap. Converts the max heap [first, last) into a sorted range in ascending order.
    std::sort_heap(begin(numbers), end(numbers)); //sorts heap using pop_heap
    //https://en.cppreference.com/w/cpp/algorithm/partial_sort. Rearranges elements such that the range [first, middle) contains the sorted middle - first smallest elements in the range [first, last).
    std::partial_sort(numbers.begin(), numbers.begin() + 3, numbers.end());
    for (auto i : numbers)
        std::cout << i << ' ';
    std::cout << std::endl;
    //https://en.cppreference.com/w/cpp/algorithm/nth_element. nth_element is a partial sorting algorithm that rearranges elements in [first, last) such that:  The element pointed at by nth is changed to whatever element would occur in that position if [first, last) were sorted.  All of the elements before this new nth element are less than or equal to the elements after the new nth element.
    std::nth_element(numbers.begin(), numbers.begin() + numbers.size() / 2, numbers.end());
    std::cout << "The median is " << numbers[numbers.size() / 2] << '\n';
    //https://en.cppreference.com/w/cpp/algorithm/inplace_merge.Merges two consecutive sorted ranges [first, middle) and [middle, last) into one sorted range [first, last).
    merge_sort(numbers.begin(), numbers.end());
    for (auto i : numbers)
        std::cout << i << ' ';
    std::cout << std::endl;

    //PARTITIONING
    //partitioning splits collection basing on predicates
    //https://en.cppreference.com/w/cpp/algorithm/partition. Reorders the elements in the range [first, last) in such a way that all elements for which the predicate p returns true precede the elements for which predicate p returns false. Relative order of the elements is not preserved.
    auto partitioning_result = std::partition(std::begin(numbers), std::end(numbers), [](const auto &em) { return em > 1; });
    std::cout << partitioning_result - std::begin(numbers) << " " << typeid(partitioning_result).name() << ' ';
    std::cout << std::endl;
    //https://en.cppreference.com/w/cpp/algorithm/partition_point. Examines the partitioned (as if by std::partition) range [first, last) and locates the end of the first partition, that is, the first element that does not satisfy p or last if all elements satisfy p.
    auto p = std::partition_point(numbers.begin(), numbers.end(), [](const auto &em) { return em > 1; });
    std::cout << "Before partition:\n    ";
    std::copy(numbers.begin(), p, std::ostream_iterator<int>(std::cout, " "));
    std::cout << "\nAfter partition:\n    ";
    std::copy(p, numbers.end(), std::ostream_iterator<int>(std::cout, " "));
    std::cout << std::endl;
    //PERMUTATIONS
    //https://en.cppreference.com/w/cpp/algorithm/rotate.  Performs a left rotation on a range of elements.
    for (auto i : numbers)
        std::cout << i << ' ';
    std::cout << std::endl;
    std::rotate(numbers.begin(), numbers.begin() + 1, numbers.end());
    for (auto i : numbers)
        std::cout << i << ' ';
    std::cout << std::endl;
    //https://en.cppreference.com/w/cpp/algorithm/random_shuffle. Reorders the elements in the given range [first, last) such that each possible permutation of those elements has equal probability of appearance.
    std::random_device rd;
    std::mt19937 g(rd());
    std::shuffle(numbers.begin(), numbers.end(), g);
    for (auto i : numbers)
        std::cout << i << ' ';
    std::cout << std::endl;
    //https://en.cppreference.com/w/cpp/algorithm/next_permutation. Transforms the range [first, last) into the next permutation from the set of all permutations that are lexicographically ordered with respect to operator< or comp. Returns true if such permutation exists, otherwise transforms the range into the first permutation (as if by std::sort(first, last)) and returns false.
    std::string s = "ab";
    std::sort(s.begin(), s.end());
    do
    {
        std::cout << s << '\n';
    } while (std::next_permutation(s.begin(), s.end()));
    //https://en.cppreference.com/w/cpp/algorithm/prev_permutation. Transforms the range [first, last) into the previous permutation from the set of all permutations that are lexicographically ordered with respect to operator< or comp. Returns true if such permutation exists, otherwise transforms the range into the last permutation (as if by std::sort(first, last); std::reverse(first, last);) and returns false.
    std::string a = "abc";
    std::sort(a.begin(), a.end(), std::greater<char>());
    do
    {
        std::cout << a << ' ';
    } while (std::prev_permutation(a.begin(), a.end()));
    //https://en.cppreference.com/w/cpp/algorithm/reverse. Reverses the order of the elements in the range [first, last) Behaves as if applying std::iter_swap to every pair of iterators first+i, (last-i) - 1 for each non-negative i < (last-first)/2
    std::cout << 'reverse ' << std::endl;
    for (auto i : numbers)
        std::cout << i << ' ';
    std::cout << std::endl;
    std::reverse(numbers.begin(), numbers.end());
    for (auto i : numbers)
        std::cout << i << ' ';
    std::cout << std::endl;

    //VARIANTS of algos
    //stable_* (stable_sort, stable_partitioning) -> keep the relative order
    //is_* (is_sorted, is_partitioned, is_heap)
    //is_*_until (is_sorted_until, is_partitioned_until, is_heap_until) -> returns an iterator
    //*_copy
    //*_n
    //*_if

    //QUERIES
    //https://en.cppreference.com/w/cpp/algorithm/count. Returns the number of elements in the range [first, last) satisfying specific criteria.
    auto count_numbers_eq_target = std::count(numbers.begin(), numbers.end(), 1);
    std::cout << count_numbers_eq_target << std::endl;
    auto count_numbers = std::count_if(numbers.begin(), numbers.end(), [](int i) { return i > 1; });
    std::cout << count_numbers << std::endl;
    //https://en.cppreference.com/w/cpp/algorithm/accumulate. Computes the sum of the given value init and the elements in the range [first, last). The first version uses operator+ to sum up the elements, the second version uses the given binary function op, both applying std::move to their operands on the left hand side (since C++20).
    //similar C++17 (transform_)reduce, can be run parallel
    int sum = std::accumulate(numbers.begin(), numbers.end(), 0);
    std::cout << sum << std::endl;
    int product = std::accumulate(numbers.begin(), numbers.end(), 1, std::multiplies<int>());
    std::cout << product << std::endl;
    //https://en.cppreference.com/w/cpp/algorithm/partial_sum. Computes the partial sums of the elements in the subranges of the range [first, last) and writes them to the range beginning at d_first. The first version uses operator+ to sum up the elements, the second version uses the given binary function op, both applying std::move to their operands on the left hand side (since C++20).
    std::partial_sum(numbers.begin(), numbers.end(), std::ostream_iterator<int>(std::cout, " "));
    std::cout << std::endl;
    std::partial_sum(numbers.begin(), numbers.end(), numbers.begin(), std::multiplies<int>());
    for (auto i : numbers)
        std::cout << i << ' ';
    std::cout << std::endl;
    //https://en.cppreference.com/w/cpp/algorithm/inclusive_scan. Computes an inclusive prefix sum operation using binary_op (or std::plus<>() for overloads (1-2)) for the range [first, last), using init as the initial value (if provided), and writes the results to the range beginning at d_first. "inclusive" means that the i-th input element is included in the i-th sum.
    // C++17 std::exclusive_scan(numbers.begin(), numbers.end(),std::ostream_iterator<int>(std::cout, " "), 0);
    // C++17 std::inclusive_scan(numbers.begin(), numbers.end(),std::ostream_iterator<int>(std::cout, " "));
    //https://en.cppreference.com/w/cpp/algorithm/inner_product. Computes inner product (i.e. sum of products) or performs ordered map/reduce operation on the range [first1, last1) and the range beginning at first2.
    int r1 = std::inner_product(numbers.begin(), numbers.begin() + numbers.size() / 2, numbers.begin() + numbers.size() / 2 + 1, 0);
    std::cout << r1 << std::endl;
    //https://en.cppreference.com/w/cpp/algorithm/adjacent_difference. Computes the differences between the second and the first of each adjacent pair of elements of the range [first, last) and writes them to the range beginning at d_first + 1. An unmodified copy of *first is written to *d_first.
    std::adjacent_difference(numbers.begin(), numbers.end(), numbers.begin());
    for (auto i : numbers)
        std::cout << i << ' ';
    std::cout << std::endl;
    //https://en.cppreference.com/w/cpp/algorithm/sample. Selects n elements from the sequence [first; last) such that each possible sample has equal probability of appearance, and writes those selected elements into the output iterator out. Random numbers are generated using the random number generator g.
    //std::vector<int> out;
    //C++17 std::sample(numbers.begin(), numbers.end(), std::back_inserter(out), 5, std::mt19937{std::random_device{}()});

    //QUERYING A PROPERTY
    // https://en.cppreference.com/w/cpp/algorithm/all_any_none_of.1) Checks if unary predicate p returns true for all elements in the range [first, last).
    // 3) Checks if unary predicate p returns true for at least one element in the range [first, last).
    // 5) Checks if unary predicate p returns true for no elements in the range [first, last).
    // 2,4,6) Same as (1,3,5), but executed according to policy. These overloads do not participate in overload resolution unless std::is_execution_policy_v<std::decay_t<ExecutionPolicy>> is true
    if (std::all_of(numbers.cbegin(), numbers.cend(), [](int i) { return i % 2 == 0; })) //returns true on empty collection
    {
        std::cout << "All numbers are even\n";
    }
    //QUERYING A PROPERTY ON 2 RANGES
    //https://en.cppreference.com/w/cpp/algorithm/equal. Returns true if the range [first1, last1) is equal to the range [first2, first2 + (last1 - first1)), and false otherwise
    //to do iterators from different containers
    std::cout << std::equal(numbers.begin(), numbers.begin() + numbers.size() / 2, numbers.rbegin()) << std::endl;
    // https://en.cppreference.com/w/cpp/algorithm/lexicographical_compare. Checks if the first range [first1, last1) is lexicographically less than the second range [first2, last2).
    // Lexicographical comparison is a operation with the following properties:
    // Two ranges are compared element by element.
    // The first mismatching element defines which range is lexicographically less or greater than the other.
    // If one range is a prefix of another, the shorter range is lexicographically less than the other.
    // If two ranges have equivalent elements and are of the same length, then the ranges are lexicographically equal.
    // An empty range is lexicographically less than any non-empty range.
    // Two empty ranges are lexicographically equal.
    for (auto it = numbers.begin(); it != (numbers.begin() + numbers.size() / 2); ++it)
    {
        std::cout << *it << " ";
    }
    if (!std::lexicographical_compare(numbers.begin(), numbers.begin() + numbers.size() / 2, numbers.begin() + numbers.size() / 2 + 1, numbers.end()))
    {
        std::cout << ">= ";
    }
    else
    {
        std::cout << "< ";
    }
    for (auto it = numbers.begin() + numbers.size() / 2 + 1; it != numbers.end(); ++it)
    {
        std::cout << *it << " ";
    }
    //https://en.cppreference.com/w/cpp/algorithm/mismatch. Returns the first mismatching pair of elements from two ranges: one defined by [first1, last1) and another defined by [first2,last2). If last2 is not provided (overloads (1-4)), it denotes first2 + (last1 - first1). 
    auto mism = std::mismatch(numbers.begin(), numbers.end(), numbers.rbegin());
    std::cout <<std::endl<< *mism.first << *mism.second<< std::endl;

    //SEARCHING A VALUE
    //in not sorted collection
    //https://en.cppreference.com/w/cpp/algorithm/find. Returns the first element in the range [first, last) that satisfies specific criteria: 1) find searches for an element equal to value 3) find_if searches for an element for which predicate p returns true 5) find_if_not searches for an element for which predicate q returns false }
    std::cout << *(std::find(std::begin(numbers), std::end(numbers), 1)) << std::endl;
    //https://en.cppreference.com/w/cpp/algorithm/adjacent_find.Searches the range [first, last) for two consecutive identical elements. 1) Elements are compared using operator==. 3) Elements are compared using the given binary predicate p.
    std::cout << *(std::adjacent_find(numbers.begin(), numbers.end())) << std::endl;
    //in a sorted collection
    //some algos require collection to be at least partially sorted in respect to value
    //partially ordered with respect to value, i.e. it must satisfy all of the following requirements:
    //partitioned with respect to element < value or comp(element, value) (that is, all elements for which the expression is true precedes all elements for which the expression is false)
    //partitioned with respect to !(value < element) or !comp(value, element)
    //for all elements, if element < value or comp(element, value) is true then !(value < element) or !comp(value, element) is also true 
    //A fully-sorted range meets these criteria. 
    //https://en.cppreference.com/w/cpp/algorithm/equal_range. Returns a range containing all elements equivalent to value in the range [first, last). 
    std::sort(numbers.begin(), numbers.end());
    auto per = std::equal_range(numbers.begin(), numbers.end(), 2);//actually may be implemented via lower and upper bound 
    std::cout << *(per).first << *(per).second << std::endl;
    //https://en.cppreference.com/w/cpp/algorithm/lower_bound. Returns an iterator pointing to the first element in the range [first, last) that is not less than (i.e. greater or equal to) value, or last if no such element is found. 
    auto plb = std::lower_bound(numbers.begin(), numbers.end(), 2);
    std::cout << *plb << std::endl;
    //https://en.cppreference.com/w/cpp/algorithm/upper_bound. Returns an iterator pointing to the first element in the range [first, last) that is greater than value, or last if no such element is found. 
    auto pub = std::upper_bound(numbers.begin(), numbers.end(), 2);
    std::cout << *pub << std::endl;
    //https://en.cppreference.com/w/cpp/algorithm/binary_search. Checks if an element equivalent to value appears within the range [first, last). Should be at least partially sorted. 
    std::cout <<std::binary_search(numbers.begin(), numbers.end(), 2) <<std::endl;
    
    //SEARCHING A RANGE
    //https://en.cppreference.com/w/cpp/algorithm/search.  Searches for the first occurrence of the sequence of elements [s_first, s_last) in the range [first, last).
    std::cout<< *(std::search(numbers.begin(), numbers.end(), numbers.begin(), numbers.end()))<< std::endl;
    //https://en.cppreference.com/w/cpp/algorithm/find_end. Searches for the last occurrence of the sequence [s_first, s_last) in the range [first, last). 
    std::cout<< *(std::find_end(numbers.begin(), numbers.end(), numbers.begin(), numbers.end()))<< std::endl;
    //https://en.cppreference.com/w/cpp/algorithm/find_first_of.Searches the range [first, last) for any of the elements in the range [s_first, s_last). 
    std::cout<< *(std::find_first_of(numbers.begin(), numbers.end(), numbers.begin(), numbers.end()))<< std::endl;

}