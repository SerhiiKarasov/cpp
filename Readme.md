# based on the book "Cpp smart pointers"

# Main pointer types

## std::unique_ptr
* a sole owner of the memory
* is a preferred type to be returned from the factory class
* no guarantee that the wrapped pointer is not used by smdb else, better to wrap a const pointer
* how to move it
  ``` c++
  std::unique_ptr<int> p1 = std::make_unique<int>(42);
  std::unique_ptr<int> p2 = move(p1);
  ```

## raw pointer 
* raw pointers and references represent access to an object, but not ownership
* it is a default way to pass objects to functions/methods
``` c++
  std::unique_ptr<House> house = buildAHouse();
  renderHouse(*house);
```
## std::shared_ptr 
* A single memory resource can be held by several std::shared_ptr at the same time.
* problem 1: Having several simultaneous holders of a resource makes a system more complex than with one unique holder, like with std::unique_ptr.
* problem 2: Having several simultaneous holders of a resource makes thread-safety harder.
* problem 3: performance cost, both in time and memory, because of the bookkeeping on reference counting.
## std::weak_ptr (present in boost as well)
* std::weak_ptr can hold a reference to a shared object along with other std::shared_ptr, but they don't increment the reference count.
* resource can be deleted even if some weak_ptr is pointing to it, hence need to add a check if object is still existing before manupulating/reading it. 
``` c++
void useMyWeakPointer(std::weak_ptr<int> wp)
{
  if (std::shared_ptr<int> sp = wp.lock())
  {
    // the resource is still here and can be used
  }
  else
  {
    // the resource is no longer here
  }
}
```
* typically is used to break circular dependency

``` c++
struct House
{
    std::shared_ptr<House> neighbour;
};
```
vs

``` c++
struct House
{
    std::weak_ptr<House> neighbour;
};
```
``` c++
std::shared_ptr<House> house1 = std::make_shared<House>();
std::shared_ptr<House> house2 = std::make_shared<House>();;
house1->neighbour = house2;
house2->neighbour = house1;
```
* may be used to maintain a cache
## boost::scoped_ptr
* scoped_ptr is present in Boost but was not included in the standard (at least as of C++17).
* It simply disables the copy and even the move construction. So it is the sole owner of a resource, and its ownership cannot be transferred
* lives only inside of a scope
## std::auto_ptr
* present in C++98, deprecated in C++11, removed in C++17
* older version of unique_ptr, without move semantics

# How to transfer unique_ptr from a set to another set
* transfer unique ptr to another one is easy:
``` c++
std::unique_ptr<int> p1 = std::make_unique<int>(42);
std::unique_ptr<int> p2 = std::move(p1); // the contents of p1 have been transferred to p2
```
* transfer unique ptr from set to set is hard, still in c++17 it is easier
