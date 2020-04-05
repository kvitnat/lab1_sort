all: generateData

generateData: generateData.cpp
	g++ -std=c++17 generateData.cpp -o generateData
	./generateData

check: check.cpp
	g++ check.cpp -o check
	./check

display: displaySort.cpp sort.h sort.cpp
	g++ displaySort.cpp sort.cpp -o display
	

clean: 
	rm -rf Data/*.txt
	rm -f generateData
	rm -f check





