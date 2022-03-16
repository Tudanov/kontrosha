#include "Header.h"


int _stateMenu;

void Menu()
{

	cout << "Выберите действие:" << endl
		<< "(0) Выход из программы." << endl
		<< "(1) Ввод данных." << endl
		<< "(2) Вывод данных." << endl
		<< "(3) Изменение данных." << endl
		<< "(4) Удаление данных." << endl
		<< "(5) Добавление данных." << endl
		<< "(6) Сохранение данных." << endl
		<< "Ваш выбор: ";
	cin >> _stateMenu;
}

void main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	DataInitialization();

	Menu();

	int _actions;
	string fileName;

	while (_stateMenu != 0)
	{
		switch (_stateMenu)
		{
		case 1:
			system("cls");

			cout << "Ввод вручную или из файла?: ";
			cin >> _actions;

			system("cls");

			if (_actions == 1)
			{
				DataEntry();
			}
			else
			{
				cout << "Введите название файла: ";
				cin >> fileName;

				DataReading(fileName);
			}
			system("pause");
			system("cls");
			Menu();
			break;
		case 2:
			system("cls");
			Print();
			system("pause");
			system("cls");
			Menu();
			break;
		case 3:
			system("cls");
			DataChange();
			system("pause");
			system("cls");
			Menu();
			break;
		case 4:
			system("cls");
			DeleteData();
			system("pause");
			Menu();
			break;
		case 5:
			system("cls");
			AddData();
			system("pause");
			system("cls");
			Menu();
			break;
		case 6:
			system("cls");
			cout << "Введите название файла: ";
			cin >> fileName;
			system("cls");
			SaveData(fileName);
			system("pause");
			system("cls");
			Menu();
			break;
		default:
			cout << "Неправильно выбран пункт меню!" << endl;
			break;
		}
	}
	system("cls");
	if (DataCleaning())
		cout << "Данные очищены!" << endl;
	else
		cout << "Данные НЕ очищены!" << endl;
	cout << "Работа завершена." << endl;
	system("pause");
}