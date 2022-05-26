#include "Kniga.h"
#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

void main_page() {
	setlocale(0, "rus");
	cout << "[1] �������� �������" << endl;
	cout << "[2] ����� �������" << endl;
	cout << "[3] ������������� �������" << endl;
	cout << "[4] ������� �������" << endl;
	cout << "[5] �������� ��� �������" << endl;
	cout << "[6] ������� ��� �������" << endl;
}

void Book::add_event() {
	setlocale(0, "rus");
	Note a;
	ofstream file("list.txt", ios::app);
	if (!file.is_open()) {
		cout << "Error: File is not opened";
			exit(EXIT_FAILURE);
	}
	cout << "������� / �������: " << endl;
	a.SetEvent();
	cout << "���� �������: " << endl;
	a.SetDate();
	cout << "�����: " << endl;
	a.SetAdress();
	cout << "��������: " << endl;
	a.SetContacts();

	file << "������� / �������: " << a.GetEvent() << ' ';
	file << "���� �������: " << a.GetDate() << ' ';
	file << "�����:: " << a.GetAdress() << ' ';
	file << "��������: " << a.GetContacts() << ' ' << endl;
	file.close();
}

void Book::see_all_list() {
	setlocale(0, "rus");
	ifstream file("list.txt");
	if (!file.is_open()) {
		cout << "List is clear or file not found! " << endl;
		return;
	}
	string one_event;
	cout << "��� �������: " << endl;
	for (int i = 1; !file.eof(); i++) {
		getline(file, one_event);
		if (one_event.empty())
			continue;
		cout << "[" << i << "]" << one_event << endl;
	}
	file.close();
}

string* Book::find_event(const string& event_to_find, int& n_count) {
	setlocale(0, "rus");
	ifstream file("list.txt");
	if (!file.is_open()) {
		cout << "List is clear! Add new events! " << endl;
		return nullptr;
	}
	string one_event;
	string* found_events = nullptr;
	string* found_events_tmp = nullptr;
	int count = 0;
	while (!file.eof()) {
		getline(file, one_event);
		if (one_event.find(event_to_find) != -1) {
			count++;
			found_events_tmp = new string[count]; //�������� �� ���������
				for (int i = 0; i < count - 1; i++) 
					found_events_tmp[i] = found_events[i]; //���������� ������ �������
				found_events_tmp[count - 1] = one_event;  //�������� ������� �����������
				delete[] found_events;
				found_events = found_events_tmp; //�������� �� ����� ������
		}
	}
	file.close();
	n_count = count;
	return found_events;
}

string* Book::all_events(int& n_count) {
	setlocale(0, "rus");
	string* all_events = nullptr;
	string* all_events_ptr = nullptr;
	ifstream file("list.txt");
	if (!file.is_open()) {
		cout << "Error: File is not opened";
		exit(EXIT_FAILURE);
	}
	string one_event;
	int count = 0;
	while (!file.eof()) {
		getline(file, one_event);
		if (one_event.empty())
			continue;
		count++;
		all_events_ptr = new string[count];
		for (int i = 0; i < count - 1; i++)
			all_events_ptr[i] = all_events[i];
		all_events_ptr[count - 1] = one_event;  
		delete[] all_events;
		all_events = all_events_ptr;
		all_events_ptr = nullptr;
	}
	file.close();
	n_count = count;
	return all_events;
}

void Book::delete_event(string* all_events_arr, int count, int choice) {
	setlocale(0, "rus");
	ofstream file("list.txt");
	if (!file.is_open()) {
		cout << "Error: File is not opened";
		exit(EXIT_FAILURE);
	}
	for (int i = 0; i < count; i++) {
		if (i + 1 == choice)
			continue;
		file << all_events_arr[i] << endl;
	}
	file.close();
}
void Book::clean_list() {
	setlocale(0, "rus");
	fstream file("list.txt", ios::out | ios::trunc);
	if (!file.is_open()) {
		cout << "Error: File is not opened";
		exit(EXIT_FAILURE);
	}
	file.close();
}



