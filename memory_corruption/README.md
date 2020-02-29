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
* option -Wunitialized prevents unitialized memory from being used
