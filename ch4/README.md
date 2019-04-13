gdb
need to be compiled with -g3

1) gdb  dispatcher_demo
2) break main.cpp:44
3) run
4) info threads
5) bt


memcheck
valgrind --log-file=dispatcher.log --read-var-info=yes --leak-check=full ./dispatcher_demo
valgrind --tool=drd --log-file=dispatcher_drd.log --read-var-info=yes ./dispatcher_demo
valgrind --tool=helgrind --read-var-info=yes --log-file=dispatcher_helgrind.log ./dispatcher_demo