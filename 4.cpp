// List.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"

#include <iostream>
#include <cstring>

using namespace std;

struct element {
	int a;
	element *next;
};

int vyvodlist(element *first) {

	element *curr = first;

	if (first != nullptr) {
		do {
			cout << curr->a;
			if (curr->next != nullptr)cout << " -> ";
			curr = curr->next;
		} while (curr != nullptr);
	}
	else {
		cout << "Список пуст " << endl;
	}
	return 0;
}

int dobavitlist(element **first) {
	element *prev = *first;
	int e=0;
	
	if (*first != nullptr) {
		while (prev->next != nullptr) {
			prev = prev->next;
		}
	}
	cout << "Введите элементы :" << endl;

	while (cin >> e) {
		element *curr = new element{ e, nullptr };
		if (prev != nullptr) {
			prev->next = curr;
		}
		else {
			(*first) = curr;
		}
		prev = curr;
		if (cin.get() == '\n') break;
	}
	
	return 0;
}

int udalitelement(element **first) {
	element *curr = *first;
	element *prev = nullptr;
	int e = 0;
	int flag = 0;

	if (first != nullptr) {
		cout << "Введите значение элемента: ";
		cin >> e;

		 do{
			if (curr->a == e) {
				flag = 1;
				break;
			}
			prev = curr;
			curr = curr->next;
		 } while (curr != nullptr);
		
		if (flag == 1) {
			if (prev != nullptr) {
				prev->next = curr->next;
			}
			if (curr == (*first)) {
				(*first) = nullptr;
			}
			delete curr;
		}else{
			cout << "Элемент " << e << " отсутствует" << endl;
		}
	}
	else {
		cout << "Список пуст " << endl;
	}

	return 0;
}

int poiskelement(element *first) {
	element *curr = first;
	int e = 0;
	int flag = 0;
	int i=1;

	if (first != nullptr) {
		cout << "Введите значение элемента: ";
		cin >> e;

		do {
			if (curr->a == e) {
				flag = 1;
				cout << i << " ";
			}
			curr = curr->next;
			i++;
		} while (curr != nullptr);

		if (flag == 0) {
			cout << "Элемент не найден" << endl;
		}
		else {
			cout << endl;
		}
	}
	else {
		cout << "Список пуст " << endl;
	}

	return 0;
}

int zamenitelement(element *first) {
	element *curr = first;
	int e = 0;
	int flag = 0;
	int z = 0;
	int i = 1;

	if (first != nullptr) {
		cout << "Введите позицию и новое значение: ";
		cin >> z;
		cin >> e;
		
		do {
			if (i == z) {
				flag = 1;
				break;
			}
			curr = curr->next;
			i++;
		} while (curr != nullptr);

		if (flag == 0) {
			cout << "Элемент с позицией " << z << " не существует" << endl;
		}
		else {
			curr->a=e;
		}
	}
	else {
		cout << "Список пуст " << endl;
	}

	return 0;
}

int classiksortirovka1(int elementov, int **m) {
	int i;
	int j;

	for (i = 0; i < elementov; i++)
		for (j = 0; j < elementov; j++) {
			if ((*m)[j] >(*m)[i]) swap((*m)[j], (*m)[i]);
		}

	return 0;
}

int sortlist(element *first) {
	element *curr = first;
	int elementov = 0;

	if (first != nullptr) {

		do {
			curr = curr->next;
			elementov++;
		} while (curr != nullptr);
		cout << "Элементов " << elementov << endl;
		
		int *m1 = new int[elementov];

		curr = first;
		elementov = 0;
		do {
			m1[elementov] = curr->a;
			curr = curr->next;
			elementov++;
		} while (curr != nullptr);

		classiksortirovka1(elementov, &m1);

		curr = first;
		elementov = 0;
		do {
			curr->a = m1[elementov];
			curr = curr->next;
			elementov++;
		} while (curr != nullptr);

		delete[] m1;
	}
	else {
		cout << "Список пуст " << endl;
	}

	return 0;
}

int main(int argc, char*argv[]) {  // argv - массив указателей на строки параметров командной строки, argc - кол-во параметров + 1
	char operation = 'c';

	int elementov = 0;
	element *first = nullptr;
    element *prev = nullptr; 

	setlocale(LC_ALL, "Russian");

	if (argc != 1) {  // проверка на наличие параметров входной строки
		elementov = (argc - 1);

		for (int i = 0; i<elementov; i++) {
			element *curr = new element{ atoi(argv[i + 1]), nullptr };
			if (i == 0) {
				first = curr;
				prev = curr;
			}
			else {
				prev->next = curr;
				prev = curr;
			}
		}

	}

	while (operation != '7') {
		cout << endl;
		cout << "Выберите одну из операций:" << endl;
		cout << "1. Распечатать список" << endl;
		cout << "2. Добавить элементы в список" << endl;
		cout << "3. Удалить элемент" << endl;
		cout << "4. Найти позиции элементов" << endl;
		cout << "5. Заменить элемент на другой" << endl;
		cout << "6. Отсортировать элементы списка" << endl;
		cout << "7. Завершить работу программы" << endl;

		cin >> operation;

		switch (operation) {
		case '1':
			vyvodlist(first);
			break;

		case '2':
			dobavitlist(&first);
			break;

		case '3':
			udalitelement(&first);
			break;
			
		case '4':
			poiskelement(first);
			break;
			
		case '5':
			zamenitelement(first);
			break;

		case '6':
			sortlist(first);
			break;

		case '7':
			char s[4];

			operation = 0;

			cout << "Вы хотите выйти из программы ? (y, N) : ";
			cin >> s;

			if ((strcmp("y", s) == 0) || (strcmp("Y", s) == 0) || (strcmp("yes", s) == 0) || (strcmp("Yes", s) == 0) || (strcmp("YES", s) == 0)) {
				operation = '7';
				cout << "До свидания !" << endl;
			}
			break;
		default:
			cerr << "Vveden nevernij parametr" << endl;
			break;
		}
	}

	return 0;
}
