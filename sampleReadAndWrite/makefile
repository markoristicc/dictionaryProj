all: write.out read.out

write.out: test.cpp testWrite.cpp 
	g++ -std=c++11 $^ -o $@

read.out: test.cpp testRead.cpp 
	g++ -std=c++11 $^ -o $@

clean:
	rm -f *.out