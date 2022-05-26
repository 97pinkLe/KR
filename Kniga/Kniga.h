#ifndef KNIGA_H
#define KNIGA_H

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Note {
private:
	string event;
	string date;
	string adress;
	string contacts;
public:
	void SetEvent() {
		string EVENT;
		getline(cin, EVENT);
		event = EVENT;
	}
	string GetEvent() {
		return event;
	}
	void SetDate() {
		string DATE;
		getline(cin, DATE);
		date = DATE;
	}
	string GetDate() {
		return date;
	}
	void SetAdress() {
		string ADRESS;
		getline(cin, ADRESS);
		adress = ADRESS;
	}
	string GetAdress() {
		return adress;
	}
	void SetContacts() {
		string CONTACTS;
		getline(cin, CONTACTS);
		contacts = CONTACTS;
	}
	string GetContacts() {
		return contacts;
	}	
};

class Book {
public:
	void add_event();
	string* find_event(const string& event_to_find, int& n_count);
	string* all_events(int& count);
	void delete_event(string* all_events_arr, int count, int choice);
	void sort();
	void see_all_list();
	void clean_list();
};

void main_page();

#endif

