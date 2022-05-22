#include <iostream>
#include <conio.h>
#include <string>
#include <fstream>
#include "Kniga.h"

int main() {
	setlocale(0, "rus");
	char choice;
	char exit;
	Note a;
	Book b;
	do {
		do {
			system("cls");
			main_page();
			cout << "Выберите действие: ";
				choice = _getch();

		} while (choice != '1' && choice != '2' && choice != '3' && choice != '4' && choice != '5' && choice != '6' && choice != '7');

		switch (choice) {
		case '1': {
			system("cls");
			b.add_event();
			cout << "Запись добавлена! " << endl;
		}
				break;
		case '2': {
			system("cls");
			string event_to_find;
			cout << "Найти событие: ";
			getline(cin, event_to_find);
			int n_found = 0;
			string* found_events = b.find_event(event_to_find, n_found);

			if (found_events) {
				cout << "Найдены события: \n";
				for (int i = 0; i < n_found; i++)
					cout << found_events[i] << endl;
				delete[] found_events;
			}
			else {
				cout << "Ничего не найдено" << endl;
			}
		}
				break;
		case '3': {
			system("cls");
			int count = 0;
			string* all_events_arr = b.all_events(count);
			cout << "Все события: ";
			for (int i = 0; i < count; i++)
				cout << "[" << i + 1 << "]" << all_events_arr[i] << endl;
			cout << "Какое событие хотите отредактировать? (номер): ";
			int choice = 0;
			cin >> choice;
			cout << "Редактирование: " << endl;
			b.delete_event(all_events_arr, count, choice);
			b.add_event();
			cout << "Изменения внесены! " << endl;
			delete[] all_events_arr;
		}
				break;

		case '4': {
			system("cls");
			int count = 0;
			string* all_events_arr = b.all_events(count);
			cout << "Все события: ";
			for (int i = 0; i < count; i++)
				cout << "[" << i + 1 << "]" << all_events_arr[i] << endl;
			cout << "Какое событие хотите удалить? (номер): ";
			int choice = 0;
			cin >> choice;
			b.delete_event(all_events_arr, count, choice);
			cout << "Событие удалено! " << endl;
			delete[] all_events_arr;
		}
				break;
		case '5': {
			system("cls");
			b.see_all_list();
		}
				break;
		case '6': {
			system("cls");
			b.clean_list();
			cout << "Все события удалены! " << endl;
		}
				break;
		}

		cout << endl << " Хотите продолжить работу? (1 - да, 0 - нет)" << endl;
		fflush(stdin);
		exit = _getch();

		

	} while (exit != '0');
}
