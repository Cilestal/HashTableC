#include "HashTable.h"

int main()
{
	setlocale(LC_ALL, "RUSSIAN");
	//создание таблицы размером 16
    HashTable<string, string> table;				
	
	//добавляем элементы - E A S Y Q U E S T I O N
	table.put("E", "Value E");
    table.put("A", "Value A");
    table.put("S", "Value S");
	table.put("Y", "Value Y");
	table.put("Q", "Value Q");
	table.put("U", "Value U");
	table.put("E", "Value E");
	table.put("S", "Value S");
	table.put("T", "Value T");
	table.put("I", "Value I");
	table.put("O", "Value O");
	table.put("N", "Value N");
	
    table.printTable();
    table.printHistogram();
    
	system("pause");
    
    return 0;
}

