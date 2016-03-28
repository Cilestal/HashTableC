#ifndef LinkedList_h
#define LinkedList_h

#include <iostream>
#include <string>
using namespace std;

//элементы для связного списка
template <class  K, class  V>
struct Entry {
	K key;
	V value;
	Entry<K,V> *next;
};

template <class  K, class  V> class LinkedList{
private:
    Entry<K,V> *head;					//голова списка
    int length;						//длина списка
public:
    LinkedList<K, V>();					
    void insert(Entry<K,V> *newItem);	//вставка нового элемента в список
    bool remove(K itemKey);    //удаление элемента из списка
    Entry<K,V> *get(K itemKey);	    //получение элемента из списка
    void print();					//печать связного списка

    int getLength();				//получение длины списка
	void clear();					//удаление элементов из списка
    ~LinkedList();
};

template<class K, class V>
LinkedList<K, V>::LinkedList() {
	//инициализируем пустой список
	head = new Entry<K,V>;
	head->next = NULL;
	length = 0;
}

template<class K, class V>
void LinkedList<K, V>::insert(Entry<K, V> *newItem) {
	if (!head->next) {			//если список пуст
		head->next = newItem;	//начало списка указывает на новый элемент
		length++;
		return;
	}

	//ищем последний эдемент
	Entry<K,V> *prev = head, *q = head;
	while (q) {
		prev = q;
		q = prev->next;
	}
	//добавляем ссылку на новый элемент
	prev->next = newItem;
	newItem->next = NULL;
	length++;
}

template<class K, class V>
bool LinkedList<K, V>::remove(K itemKey) {
	//если список пуст, уходим
	if (!head->next)
		return false;

	//ищем нужный элемент
	Entry<K,V> *prev = head, *el = head;
	while (el) {
		if (el->key == itemKey) {
			//удаляем его
			prev->next = el->next;
			delete el;
			length--;
			return true;
		}
		prev = el;
		el = prev->next;
	}
	return false;
}

template<class K, class V>
Entry<K,V> *LinkedList<K, V>::get(K itemKey) {
	Entry<K,V> *p = head, *q = head;
	while (q) {
		p = q;
		if ((p != head) && (p->key == itemKey))
			return p;
		q = p->next;
	}
	return NULL;
}

template<class K, class V>
void LinkedList<K, V>::print() {
	//если пуст
	if (length == 0) {
		cout << "\n{ }\n";
		return;
	}
	Entry<K,V> *p = head, *q = head;
	cout << "\n{ ";
	while (q) {
		p = q;
		if (p != head) {
			cout << p->key;
			if (p->next) cout << ", ";
			else cout << " ";
		}
		q = p->next;
	}
	cout << "}\n";
}

template<class K, class V>
int LinkedList<K, V>::getLength() {
	return length;
}

template<class K, class V>
void LinkedList<K, V>::clear() {
	//очистка списка
	Entry<K,V> *tmp;
	while (head->next) {
		tmp = head->next;
		head->next = tmp->next;
		delete tmp;
	}

	this->head->next = NULL;
	this->length = 0;
}

template<class K, class V>
LinkedList<K, V>::~LinkedList() {
	Entry<K,V>  *p = head, *q = head;
	clear();
	delete head;
}

#endif
 
