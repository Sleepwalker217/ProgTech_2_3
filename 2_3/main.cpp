#include "University.h"
#include "Second_task.h"
#include <iostream>
#include <fstream>
#include <string>
#include <exception>
using namespace std;
int main() {
	setlocale(LC_ALL, "");
	University Univer; //объект университет
	Student *ptr; //указатель на студента
	string surname; //для поиска
	string initials;
	int choose; //выбор пользователя
	bool flag = true;
	while (flag) {
		system("cls");
		cout << "1: Добавление нового студента (без оценок)" << endl;
		cout << "2: Удаление выбранного студента" << endl;
		cout << "3: Вывод всех студентов на экран" << endl;
		cout << "4: Вывод всех студентов с оценкой 2 на экран" << endl;
		cout << "5: Сортировка всех студентов по возрастанию среднего балла" << endl;
		cout << "6: Изменение данных студента (добавление оценок)" << endl;
		cout << "0: Переход на второе задание ->" << endl;
		cin >> choose;
		if (cin.fail()) {
			choose = -1;
			cin.clear();
			cin.ignore(10000, '\n');
		}
		switch (choose) {
		case 1:
			cin >> Univer; //ввод студента
			break;
		case 2:
			Univer.delete_student();//удаление студента
			break;
		case 3:
			system("cls");
			cout << Univer; //вывод студента
			system("pause");
			break;
		case 4:
			Univer.show_student_two();//просмотрстудента с 2
			break;
		case 5:
			system("cls");
			cout << "\t| Изначальный список |" << endl;
			cout << "\t----------------------" << endl << endl << Univer << endl << endl;
			Univer.sort_student(); //сортировка по сред баллу
			cout << "\t| Отсортированный список |" << endl;
			cout << "\t--------------------------" << endl << endl << Univer << endl << endl;
			system("pause");
			break;
		case 6:
			if (Univer.get_number_of_student() == 0) { //если нет студентов
				system("cls");
				cout << "Список студентов пуст!" << endl << endl;
				system("pause");
			}
			else {//если есть студенты
				cout << "Введите фамилию: ";
				cin >> surname;
				cout << "Введите инициалы: ";
				cin >> initials;
				ptr = Univer.find_student(surname, initials); //найти студента
				if (ptr == nullptr) {//если указатель пуст
					cout << "Такого студента нет!" << endl << endl;
					system("pause");
				}
				else {
					ptr->change_data(); //изменить данные студента по указателю 
				}
			}
			break;
		case 0:
			flag = false;
			break;
		default:
			cout << "Введена некорректная команда" << endl << endl;
			system("pause");
		}
	}
	system("cls");
	cout << "Второе задание...." << endl << endl;
	second_task();

	return 0;
}
