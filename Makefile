main:
	g++ main.cpp mergesort.cpp -lgflags -lglog -o main
test:
	g++ mergesort_test.cpp mergesort.cpp -lgtest_main -lgtest -lpthread -o test
benchmark:
	g++ mergesort_benchmark.cpp mergesort.cpp -lbenchmark -lpthread -o benchmark