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

int dobavitlist(element *first) {
	element *prev = first;
	int e=0;
	
	cout << "Введите элементы :" << endl;
	
	while (prev->next != nullptr) {
		prev = prev->next;
	}

	while (cin >> e) {
		element *curr = new element{ e, nullptr };
		prev->next = curr;
		prev = curr;
		if (cin.get() == '\n') break;
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
			dobavitlist(first);
			break;
/*
			case '3':
			umnogmatrix(strok, stolbchov, m);
			break;

			case '4':
			transportirovka(strok, stolbchov, m);
			break;

			case '5':
			vyvodfile(strok, stolbchov, m);
			break;

			case '6':
			vvodfile(&strok, &stolbchov, &m);
			break;
			*/

		case '7':
			char s[4];

			operation = 0;

			cout << "Вы хотите выйти из программы ? (y, N) : ";

			cout << strcmp("y", s) << endl;
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
