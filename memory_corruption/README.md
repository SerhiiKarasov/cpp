# Memory layout
* https://manybutfinite.com/post/anatomy-of-a-program-in-memory/
* Sample linux memory layout
    * text segment (read only, executable instructions, string literals)
    * data segment (initialized static variables)
    * bss segment (uninitialized variables)
    * heap (dynamic allocation), on pop platforms grows towards higher addr.
    * memory mapping segment (dynamic libs, mappings)
    * stack (local variables and function parameters, program stack)
    
* sample code
```
const char* hello_string = "hello"; //data and text
int nums[] = {1, 2};//data
char g_buf[1024];// bss
int main()
{
    char l_buf[1024]; //stack
    char* h_buf = malloc(1024); //heap
    return 0;
}
```
# Memory corruption
* option -Wunitialized prevents unitialized memory from being used (https://gcc.gnu.org/wiki/Better_Uninitialized_Warnings)
* out-of-bounds memory corruption errors fall in two categories:
      * object-based, i.e. when a pointer is used to access target memory;
      * pointer-based, i.e. when the target address is out-of-bounds.
* tools
      * valgrind memcheck
      * kmemcheck uses shadow memory to monitor allocated memory, supports only heap
      * MemorySanitizer is a detector of unitialized read. Consists of compiler and run-time lib. If an error occurs -> prints error message. 
      * AddressSanitizer check for usage of freed or out-of-bounds memory  
      * DieHard, DieHarder allow for avoiding memory reuse by use of special allocators
      * DangNull uses pointer nullification to eliminate pointer dangling.
      * FreeSentry  doesn't change ptr repr., 
      
# Classification of memory corruptions
* buffer overflow - data can be overwritten, hacker cannot control on destination address, hacker can control input data(size and source address)
* arbitrary write - hacker has full control on destination address and input data(size and source address)
* of-by-one - data can be overwritten(usually limited by one element of array), hacker cannot control on destination address, hacker can control input data(only source address)
