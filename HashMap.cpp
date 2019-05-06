
#include "iostream"
#include "string.h"
#include "cstdlib"
#include "LinkedList.h"

using namespace std;

struct Data {
 public:
	int weight;
	bool gender;
	Data(){}
};

inline ostream & operator << (ostream &out, const Data &data){
	out << data.weight << " ";
	if (data.gender)
		out << "Female";
	else
		out << "Male";
	out << "\n";
	return out;
}

class HashMap {

 private:
	LinkedList<string,Data> **table;
	int size;


 public:

	explicit HashMap(int sizeReceived) {
		this->size = sizeReceived;
		table = new LinkedList<string,Data> *[size];
		for (int i = 0; i < size; i++)
			table[i] = nullptr;
	}

	Data get(string key) {
		int hash = hashFunc(key);
		if (table[hash] == nullptr){
			return *new Data;
		}
		else {
			LinkedList<string,Data> *entry = table[hash];
			return entry->find(key)->value;

		}
	}

	void put(string key, int _weight, bool _gender) {
		Data value;
		value.weight = _weight;
		value.gender = _gender;
		int hash = hashFunc(key);
		if (table[hash] == nullptr) {
			table[hash] = new LinkedList<string,Data>();
			table[hash]->addToEnd(key, value);
		} else {
			LinkedList<string,Data> *entry = table[hash];
			entry->addToEnd(key, value);
		}
	}

	void remove(string key) {
		int hash = hashFunc(key);
		if (table[hash] != nullptr) {
			LinkedList<string,Data> *entry = table[hash];
			entry->deleteNode(entry->find(key));
		}
	}

	int hashFunc(string key) {
		int hash = 0;
		for(char c: key){
			hash += c*c;
		}
		return abs(hash % size);
	}

	~HashMap() {
		for (int i = 0; i < size; i++)
			if (table[i] != nullptr) {
				LinkedList<string,Data> *entry = table[i];
				while (entry->head != nullptr) {
					entry->deleteNode(entry->head);
				}
			}
		delete[] table;
	}
};


