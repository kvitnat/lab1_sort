all: generateData

generateData: generateData.cpp
	g++ -std=c++17 generateData.cpp -o generateData
	./generateData

clean: 
	rm -rf Data/*
	rm -f generateData





