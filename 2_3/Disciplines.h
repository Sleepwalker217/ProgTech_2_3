#pragma once
#include <iostream>
#include <string>
#include <exception>
using namespace std;
struct Disciplines { //структура "преподаваемые дисциплины"
	string name; //название дисциплины
	int mark;//оценка по дисциплине 
	Disciplines* next_disciplines;//указатель на следующиую дисциплину
	Disciplines() : name("No"), mark(0) {}; //конструктор для структуры
	Disciplines(string name, int mark) : name(name), mark(mark) {}; //коструктор структуры с параметрами
};