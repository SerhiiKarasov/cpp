# based on the book "Cpp smart pointers"

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
## std::weak_ptr 
## boost::scoped_ptr
## std::auto_ptr
