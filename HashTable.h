#ifndef HashTable_h
#define HashTable_h

#include "LinkedList.h"

const int DEFAULT_INITIAL_CAPACITY = 16;

template<class K, class V>
class HashTable{
private:
    LinkedList<K, V> *table;						//связные списки - "корзины"
    int length;												//длина таблицы
    int hash(K itemKey);								//функция получения hashcode 
	Entry<K, V> *getEntry(K key);			//ф-ция получения записи
public:
    HashTable<K, V>(int tableLength = DEFAULT_INITIAL_CAPACITY);
    void put(K key, V value);		//добавить элемент в таблицу
    bool remove(K key);				//удалить элемент из таблицы
	V getValue(K key);			//получить значение элемента по ключу
	bool contains(K key);				//проверка на содержание таблицей ключа

	void clear();							//очистка таблицы
    void printTable();						//печать таблицы
    void printHistogram();					//печать гистограммы
    int getLength();						//длинна таблицы
    int size();								//кол-во элементов в таблице
    ~HashTable();
};

template<class K, class V>
HashTable<K, V>::HashTable<K, V>(int tableLength) {
	//инициализируем таблицу
	if (tableLength <= 0)
		tableLength = DEFAULT_INITIAL_CAPACITY;

	table = new LinkedList<K, V>[tableLength];
	length = tableLength;
}

//функция получения hashcode
template<class K, class V>
int HashTable<K, V>::hash(K key) {
	return (std::hash<K>()(key) & 2147483647) % this->length;
}

//добавление элемента в таблицу
template<class K, class V>
void HashTable<K, V>::put(K key, V value) {
	//создаем запись с ключем и значением
	Entry<K, V> *entry = new Entry<K, V>{ key, value, NULL };

	//определяем индекс "корзины"
	int index = hash(entry->key);

	//добавляем элемент в нужную "корзину"
	table[index].insert(entry);
}

template<class K, class V>
bool HashTable<K, V>::remove(K key) {
	int index = hash(key);
	return table[index].remove(key);
}

template<class K, class V>
Entry<K, V> *HashTable<K, V>::getEntry(K key) {
	int index = hash(key);
	return table[index].get(key);
}

template<class K, class V>
V HashTable<K, V>::getValue(K key) {
	//ищем запись и возвращаем её значение
	return this->getEntry(key)->value;
}

template<class K, class V>
bool HashTable<K, V>::contains(K key) {
	//ищем запись, если она найдена, то таблица содержит такой элемент
	return this->getEntry(key) != NULL;
}

template<class K, class V>
void HashTable<K, V>::clear() {
	//чистим каждую "корзину"
	for (int i = 0; i < length; i++) {
		table[i].clear();
	}
}

template<class K, class V>
void HashTable<K, V>::printTable() {
	cout << "\nHash Table:\n";
	for (int i = 0; i < length; i++) {
		cout << "Bucket " << i + 1 << ": ";
		table[i].print();
	}
}

template<class K, class V>
void HashTable<K, V>::printHistogram() {
	cout << "\n\nHash Table Contains ";
	cout << size() << " Items total\n";
	for (int i = 0; i < length; i++) {
		cout << i + 1 << ":\t";
		//печатаем столько иксов, сколько элементов в "корзине"
		for (int j = 0; j < table[i].getLength(); j++) cout << " X";
		cout << "\n";
	}
}

template<class K, class V>
int HashTable<K, V>::getLength() {
	return length;
}

template<class K, class V>
int HashTable<K, V>::size() {
	//суммируем кол-во элементов в каждой из корзин
	int itemCount = 0;
	for (int i = 0; i < length; i++)
		itemCount += table[i].getLength();
	return itemCount;
}

template<class K, class V>
HashTable<K, V>::~HashTable() {
	delete[] table;
}
#endif


