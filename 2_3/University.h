#pragma once
#include "Student.h"
class University {
	Student* head_student; //указатель на головного студента
	int number_of_student; //количество студентов
public:
	University();
	University(const University&);
	~University();
	int get_number_of_student() { return number_of_student; } //возврат значения количества студентов
	void delete_student(); //укадление студента
	void show_student_two(); //просмотр студентов с 2
	void sort_student(); //соортировка студентов по ср баллу
	Student* find_student(string, string); //поиск студента 
	friend istream& operator >> (istream&, University&); //перегрузка ввода и вывода
	friend ostream& operator <<(ostream&, University&);
};