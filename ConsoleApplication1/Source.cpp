#include "Header.h"


void DataInitialization()
{
	ofstream _buf("Buffer.txt");
	if (!_buf)
		cout << "Ошибка создания буферного файла!" << endl;
	_buf.close();
}

void DataEntry()
{
	int _number;
	string _surname;
	string _Name;
	string _patronymic;
	string _subject;
	string _price;
	int n;
	cout << "Введите количество данных: ";
	cin >> n;
	ofstream record("Buffer.txt", ios::app);

	if (record)
	{
		record << n << endl;

		for (int i = 0; i < n; i++)
		{
			cout << "Номер договора: ";
			cin >> _number;
			cout << "Фамилия: ";
			cin >> _surname;
			cout << "Имя: ";
			cin >> _Name;
			cout << "Отчество: ";
			cin >> _patronymic;
			cout << "Предмет договрода: ";
			cin >> _subject;
			cout << "Цена договора: ";
			cin >> _price;
			record << _surname << endl;
			record << _phoneNum << endl;
			if (i < n - 1)
				record << _city << endl;
			else
				record << _city;
			cout << "_____________" << endl;
		}
	}
	else
		cout << "Ошибка открытия файла" << endl;
	record.close();
}

void DataReading(string fileName)
{
	ifstream reading(fileName);
	ofstream record("Buffer.txt", ios::out);
	if (reading)
	{
		if (record)
		{
			string _surname;
			int _phoneNum;
			string _city;
			int n;
			reading >> n;
			record << n << endl;
			for (int i = 0; i < n; i++)
			{
				reading >> _surname;
				reading >> _phoneNum;
				reading >> _city;
				record << _surname << endl;
				record << _phoneNum << endl;
				if (i < n - 1)
					record << _city << endl;
				else
					record << _city;
			}
			cout << "Данные считаны" << endl;
		}
		else
			cout << "Ошибка открытия буфера!" << endl;
	}
	else
		cout << "Ошибка открытия файла!" << endl;
	reading.close();
	record.close();
}

void Print()
{
	ifstream reading("Buffer.txt");
	if (reading)
	{
		string _surname;
		int _phoneNum;
		string _city;
		int n;
		reading >> n;
		cout << "Количество данных: " << n << endl << endl;
		for (int i = 0; i < n; i++)
		{
			cout << "Данные об №" << i + 1 << endl;
			reading >> _surname;
			cout << "Данные №1 (Фамилия): " << _surname << endl;
			reading >> _phoneNum;
			cout << "Данные №2 (Номер телефона): " << _phoneNum << endl;
			reading >> _city;
			cout << "Данные №3 (Город): " << _city << endl;
			cout << "___________________________" << endl;
		}
	}
	else
		cout << "Ошибка открытия файла" << endl;
	reading.close();
}

bool DataCleaning()
{
	bool clear = false;
	fstream _buf("Buffer.txt", ios::out);
	if (!_buf)
		cout << "Ошибка открытия буферного файла!" << endl;
	_buf.clear();
	if (_buf.peek() == EOF)
		clear = true;
	else
		clear = false;
	_buf.close();
	return clear;
}

void DataChange()
{
	Copy();
	ifstream reading("Buffer_.txt");
	ofstream record("Buffer.txt", ios::out);
	if (reading)
	{
		if (record)
		{
			string _surname;
			int _phoneNum;
			string _city;
			int n, _n;
			reading >> n;
			cout << "Выберите номер изменяемого элемента (от 1 до " << n << "): ";
			cin >> _n;
			_n--;
			system("cls");
			record << n << endl;
			if (_n >= 0 && _n < n)
			{
				for (int i = 0; i < n; i++)
				{
					if (i != _n)
					{
						reading >> _surname;
						record << _surname << endl;
						reading >> _phoneNum;
						record << _phoneNum << endl;
						reading >> _city;
						if (i < n - 1)
							record << _city << endl;
						else
							record << _city;
					}
					else
					{
						cout << "Введите данные №1 (Фамилия): ";
						cin >> _surname;

						cout << "Введите данные №2 (Номер телефона): ";
						cin >> _phoneNum;

						cout << "Введите данные №3 (Город): ";
						cin >> _city;

						record << _surname << endl;
						record << _phoneNum << endl;
						if (i < n - 1)
							record << _city << endl;
						else
							record << _city;
						reading >> _surname;
						reading >> _phoneNum;
						reading >> _city;
					}
				}
				cout << "Данные измененны!" << endl;
			}
			else
				cout << "Номер введён не верно!" << endl;
		}
		else
			cout << "Ошибка открытия файла!" << endl;
	}
	else
		cout << "Ошибка открытия буферного файла!" << endl;

	record.close();
	reading.close();
	remove("Buffer_.txt");
}

void Copy()
{
	ifstream reading("Buffer.txt");
	ofstream record("Buffer_.txt", ios::out);
	if (reading)
	{
		if (record)
		{
			string _surname;
			int _phoneNum;
			string _city;
			int n;
			reading >> n;
			record << n << endl;
			for (int i = 0; i < n; i++)
			{
				reading >> _surname;
				record << _surname << endl;
				reading >> _phoneNum;
				record << _phoneNum << endl;
				reading >> _city;
				if (i < n - 1)
					record << _city << endl;
				else
					record << _city;
			}
		}
		else
			cout << "Ошибка открытия файла!" << endl;
	}
	else
		cout << "Ошибка открытия буферного файла!" << endl;
	record.close();
	reading.close();
}

int AmountOfData()
{
	ifstream _buf("Buffer.txt");
	int n;
	if (_buf)
	{
		_buf >> n;
	}
	else
		cout << "Ошибка открытия буферного файла!" << endl;
	_buf.close();
	return n;
}

void DeleteData()
{
	Copy();
	ifstream reading("Buffer_.txt");
	ofstream record("Buffer.txt", ios::out);
	if (reading)
	{
		if (record)
		{
			string _surname;
			int _phoneNum;
			string _city;
			int n, _n;
			reading >> n;
			int b = n - 1;
			cout << "Выберите номер изменяемого элемента (от 1 до " << n << "): ";
			cin >> _n;
			_n--;
			system("cls");
			record << b << endl;
			if (_n >= 0 && _n < n)
			{
				for (int i = 0; i < n; i++)
				{
					if (i != _n)
					{
						reading >> _surname;
						record << _surname << endl;
						reading >> _phoneNum;
						record << _phoneNum << endl;
						reading >> _city;
						if (i < n - 1)
							record << _city << endl;
						else
							record << _city;
					}
					else
					{
						reading >> _surname;
						reading >> _phoneNum;
						reading >> _city;
					}
				}
				cout << "Данные удалены!" << endl;
			}
			else
				cout << "Номер введен не верно!" << endl;
		}
		else
			cout << "Ошибка открытия файла!" << endl;
	}
	else
		cout << "Ошибка открытия буферного файла!" << endl;
	record.close();
	reading.close();
	remove("Buffer_.txt");
}

void AddData()
{
	string _surname;
	int _phoneNum;
	string _city;
	int n = AmountOfData() + 1;
	ofstream record("Buffer.txt", ios::app);
	ofstream record_("Buffer.txt", ios::out | ios::in);
	if (record_)
	{
		record_ << n << endl;
	}
	else
		cout << "Ошибка открытия буферного файла!" << endl;
	if (record)
	{
		record << endl;
		cout << "Введите данные №1 (Фамилия): ";
		cin >> _surname;
		cout << "Введите данные №2 (Номер телефона): ";
		cin >> _phoneNum;
		cout << "Введите данные №3 (Город): ";
		cin >> _city;
		record << _surname << endl;
		record << _phoneNum << endl;
		record << _city << endl;
	}
	else
		cout << "Ошибка открытия файла!" << endl;
	record.close();
	record_.close();
}

void SaveData(string fileName)
{
	ifstream reading("Buffer.txt");
	ofstream record(fileName, ios::out);
	if (reading)
	{
		if (record)
		{
			string _surname;
			int _phoneNum;
			string _city;
			int n;
			reading >> n;
			record << n << endl;
			for (int i = 0; i < n; i++)
			{
				reading >> _surname;
				record << _surname << endl;
				reading >> _phoneNum;
				record << _phoneNum << endl;
				reading >> _city;
				if (i < n - 1)
					record << _city << endl;
				else
					record << _city;
			}
			cout << "Данные сохранены в файле " << fileName << endl;
		}
		else
			cout << "Ошбика открытия буферного файла!" << endl;
	}
	else
		cout << "Ошибка отыкрытия файла!" << endl;
	record.close();
	reading.close();
}