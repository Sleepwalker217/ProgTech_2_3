#pragma once
#include "Disciplines.h"
class Student { //класс студент
	string surname; //Фамилия
	string initials; //Инициалы
	string group; //Номер группы
	Disciplines* head_disciplines; //Дисциплины и их оценки
	int number_of_disciplines; //Количество дисциплин
	double average_mark; //Средний балл
	Student* next_student; //Указатель на следующий элемент студента
public:
	Student(); // конструктор
	Student(string, string, string, Disciplines*); //констурктор с параметрами
	~Student();// деструктор
	void set_next_student(Student* next_student) { this->next_student = next_student; } //установка указателя на след элемент
	Student* get_next_student() { return next_student; } //получить указатель на следующего студента
	string get_surname() { return surname; } //получить фамилию
	string get_initials() { return initials; }//поулчить инициалы
	string get_group() { return group; } //получить группу
	Disciplines* get_head_disciplines() { return head_disciplines; }//получить укзаатель на голову
	double get_average_mark() { return average_mark; } //получить  среднюю оценку
	void push_disciplines(); //ввести дисциплину
	void delete_disciplines(string); //удалить дисциплину
	void show_data(); //просмортреть данные
	void change_data(); //изменить данные 
	void average_score(); //средний бал
	bool find_mark_two();//найти оценку
};