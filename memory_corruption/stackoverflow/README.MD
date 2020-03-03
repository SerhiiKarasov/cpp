```
cppcheck --force --include=/usr/include --suppress=missingIncludeSystem --enable=all stackoverflow.cpp 
Checking stackoverflow.cpp ...
[stackoverflow.cpp:7]: (error) Buffer is accessed out of bounds: target
```

```
computer@computer:~/Coding/cpp/memory_corruption/stackoverflow/build$ clang-tidy -p build/-header-filter=.* -checks=*,-fuchsia-overloaded-operator,-llvm-header-guard,-llvm-include-order,-google-readability-braces-around-statements,-readability-avoid-const-params-in-decls,-fuchsia-default-arguments  ../stackoverflow.cpp 

/home/computer/Coding/cpp/memory_corruption/stackoverflow/build/../stackoverflow.cpp:7:12: warning: do not implicitly decay an array into a pointer; consider using gsl::array_view or an explicit cast instead [cppcoreguidelines-pro-bounds-array-to-pointer-decay]
    memcpy(target, source, 101);
           ^
/home/computer/Coding/cpp/memory_corruption/stackoverflow/build/../stackoverflow.cpp:7:20: warning: do not implicitly decay an array into a pointer; consider using gsl::array_view or an explicit cast instead [cppcoreguidelines-pro-bounds-array-to-pointer-decay]
    memcpy(target, source, 101);
                ^
```