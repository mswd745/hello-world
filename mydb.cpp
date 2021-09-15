#include "mydb.h"
#include <iostream>
using namespace std;

void MyDB::show() {
	cout << "***Displaying DB records****\n";

	int i;
	for(i=0; i <=counter; i++) {
		cout << "Author : " << data[i].author << ", ";
		cout << "Pages : " << data[i].pages << ", ";
		cout << "Publisher : " << data[i].publisher << ", ";
		cout << "Publication Year : " << data[i].year << "\n";
	}
	cout << "******END******\n";
}

void MyDB::insert(struct record r) {
	if (counter+1 >= MAX) {
		cout << "No Space in DB !!!\n";
		return;
	}

	counter++;
	data[counter].author = r.author;
	data[counter].year = r.year;
	data[counter].pages = r.pages;
	data[counter].publisher = r.publisher;
	cout << "Author : " << r.author << ", Data Inserted\n";
}

void MyDB::update(string author, struct record r) {
	int i;
	for(i=0; i<=counter; i++) {
		if (data[i].author == author)
			break;
	}

	if (i > counter) {
		cout << "Author : " << author << ", Record not found !!!\n";
		return;
	}

	data[i].author = r.author;
	data[i].year = r.year;
	data[i].pages = r.pages;
	data[i].publisher = r.publisher;

	cout << "Author : " << author << ", Data updated \n"; 
}

void MyDB::delete_r(string author) {

	int i;
	for(i=0; i<=counter; i++) {
		if (data[i].author == author)
			break;
	}
	if (i > counter) {
		cout << "Author : " << author << ", Record not found !!!\n";
		return;
	}

	while(i<=counter-1) {
		data[i].author = data[i+1].author;
		data[i].pages = data[i+1].pages;
		data[i].publisher = data[i+1].publisher;
		data[i].year = data[i+1].year;
		i++;
	}

	counter--;

	cout << "Author : " << author << ", Data Deleted\n";
}

void MyDB::query(string author) {
	int i;
	for(i=0; i<=counter; i++) {
		if (data[i].author == author)
			break;
	}

	if (i > counter) {
		cout << "Author : " << author << ", Record not found !!!\n";
		return;
	}

	cout << "***queried Author Info****\n";
	cout << "Author : " << data[i].author << ", ";
	cout << "Pages : " << data[i].pages << ", ";
	cout << "Publisher : " << data[i].publisher << ", ";
	cout << "Year : " << data[i].year << "\n";
	cout << "***END*******\n";
	return;
}

MyDB::MyDB() : MAX(10) {
	counter = -1;
}
