//
// Created by MykolaV on 14.03.2019.
//

class LinkedHashEntry {

 private:
	int key;
	int value;
	LinkedHashEntry *next;

 public:
	LinkedHashEntry(int key, int value) : key(key), value(value) {
		this->next = nullptr;
	}

	int getKey() {
		return key;
	}

	int getValue() {
		return value;
	}

	void setValue(int value) {
		this->value = value;
	}

	LinkedHashEntry *getNext() {
		return next;
	}

	void setNext(LinkedHashEntry *next) {
		this->next = next;
	}
};


