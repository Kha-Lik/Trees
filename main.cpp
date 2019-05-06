#include <iostream>
#include "ctime"
#include "HashMap.cpp"

using namespace std;

int main() {
	int size = 25000;
	string key = "Key";
	time_t tStart, tEnd;
	HashMap hMap(size);
	for (int i = 0; i < size; i++){
		hMap.put(key + to_string(i), rand()%100, i%2);
	}

	tStart = clock();
	for (int i = 0; i < size; i++){
		hMap.remove(key + to_string(i));
	}
	tEnd = clock();


	cout << tEnd - tStart << "ms\n";
	return 0;
}

