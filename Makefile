all: generateData

generateData: generateData.cpp
	g++ -std=c++17 generateData.cpp -o generateData
	./generateData

check: check.cpp
	g++ check.cpp -o check
	./check

display: displaySort.cpp sort.h sort.cpp
	g++ sort.cpp displaySort.cpp -o display
	./display
	
ifeq ($(OS),Windows_NT)
    RM = del
else
    RM = rm
endif

clean: 
	$(RM) -rf Data/*.txt
	$(RM) -f generateData
	$(RM) -f check





