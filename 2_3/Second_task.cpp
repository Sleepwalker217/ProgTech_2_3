#include "Second_task.h"
using namespace std;
int second_task() {
	string buffer;
	bool flag_sentence = false; //Флаг наличия нужной строки в файле
	char prev;
	try {
		ifstream fin("Text.txt", ios::in);
		if (!fin)
			throw exception("Файл не был открыт!");
		while (!fin.eof()) { //Пока файл не закончился
			getline(fin, buffer); //Считываем строку
			if (buffer.length() == 0) //Если строка пуста, топереходим на следующую
				continue;
			/* Дополняем строку символом \0, так как при считывании строки в
			string в конец ничего не добавляется */
			/* Это помогает определять двузначное число, если оно стоит в конце
			строки */
			buffer.resize(buffer.length() + 1); //Вторым параметром  ничего не передано, значит по умолчанию строка дополнится символом \0
			prev = ' ';
			//Предыдущий символ строки
			for (int i = 0; i < buffer.length() - 2; ++i) {
				if (prev == ' ' && buffer[i] > '0' && buffer[i] <= '9' && buffer[i +
					1] >= '0' && buffer[i + 1] <= '9' && (buffer[i + 2] == ' ' || buffer[i + 2] == '\0' || buffer[i + 2] ==
						'.' || buffer[i + 2] == ',')) {
					flag_sentence = true;
					cout << buffer << endl << endl;
					break;
				}
				prev = buffer[i];
			}
		}
		if (!flag_sentence)
			cout << "Подходящий строк нет!" << endl << endl;
	}
	catch (exception& ex) {
		cout << ex.what() << endl << endl;
	}
	system("pause");
	return 0;
}