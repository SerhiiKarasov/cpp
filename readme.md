```
clang-tidy -checks=*,-fuchsia-overloaded-operator,-llvm-header-guard,-llvm-include-order,-google-readability-braces-around-statements,-readability-avoid-const-params-in-decls,-fuchsia-default-arguments -header-filter=.*  *pp >/tmp/log_clang.txt 2>&1
python3 -m cpplint --filter=-whitespace,-readability,-legal *pp > /tmp/log_cpplint.txt  2>&1
cppcheck --force --include=/usr/include --suppress=missingIncludeSystem --enable=all  *pp > /tmp/log_cppcheck.txt 2>&1
geany /tmp/log_*.txt
```
