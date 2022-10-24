#include <iostream>
#include <ctime>
#include <string>
using namespace std;

int f = 1;

void verify(const string const& a, int& ca);

void FillArray(int* const arr, int const size)
{
	srand(time(0));
	for (int i = 0; i < size; i++)
	{
		arr[i] = rand() % 20;
	}
}

void ShowArray(const int const* arr, int const size)
{
	cout << "\nмассив: ";
	for (int i = 0; i < size; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
}

void App(int*& arr, int& size)
{
	string cindex, ccount, cnumeric;
	int index, count, numeric;
	cout << "\nКол-во добавляемых эл-ов(>=0): ";
	cin >> ccount;
	verify(ccount, count);
	if (f != 0 and count >= 0)
	{
		for (int i = 0; i < count; i++)
		{
			cout << "Выберите куда добавить " << i + 1 << " эл-т" << " (0 - " << size << ") : ";
			cin >> cindex;
			verify(cindex, index);
			if (f != 0 and (index <= size) and (index >= 0))
			{
				size++;
				int* SecondArray = new int[size];
				cout << "Введите " << i + 1 << " число (0 - 20)" << ": ";
				cin >> cnumeric;
				verify(cnumeric, numeric);
				if (f != 0 and (numeric >= 0 and numeric <= 20))
				{
					int i;
					for (i = 0; i < index; i++)
					{
						SecondArray[i] = arr[i];
					}
					SecondArray[index] = numeric;
					i++;
					for (i; i < size; i++)
					{
						SecondArray[i] = arr[i - 1];
					}
					delete[] arr;
					arr = SecondArray;
					ShowArray(arr, size);
					cout << endl;
				}
				else
				{
					if (f == 0)
					{
						break;
					}
					else
					{
						f = 0;
						cout << "\nПовторите попытку\n";
						break;
					}
				}
			}
			else
			{
				if (f == 0)
				{
					break;
				}
				else
				{
					f = 0;
					cout << "\nПовторите попытку\n";
					break;
				}
			}
		}
	}
}

void verify(const string const& a, int& ca)
{
	for (int i = 0; i < a.length(); i++)
	{
		if (isdigit(a[i]) == 0)
		{
			cout << "\nПовторите попытку\n";
			f = 0;
			break;
		}
		else
		{
			f = 1;
		}
	}
	if (f == 1)
	{
		ca = atoi(a.c_str());
	}
}

void Del(int*& arr, int& size)
{
	cout << "\nКолличество удаляемых эл-ов (0-" << size << "): ";

	string ccount, cindex;
	int count, index;
	cin >> ccount;
	verify(ccount, count);
	if (f != 0 and count >= 0 and count <= size)
	{
		for (int i = 0; i < count; i++)
		{
			cout << "Выберите индекс " << i + 1 << "-ого удаляемого эл-та (0-" << size - 1 << "): ";
			cin >> cindex;
			verify(cindex, index);
			if (f != 0 and index >= 0 and index <= size - 1)
			{
				size--;
				int* Third = new int[size];
				int i;
				for (i = 0; i < index; i++)
				{
					Third[i] = arr[i];
				}
				for (i; i < size; i++)
				{
					Third[i] = arr[i + 1];
				}
				delete[] arr;
				arr = Third;
				ShowArray(arr, size);
				cout << endl;
			}
			else
			{
				if (f == 0)
				{
					break;
				}
				else
				{
					f = 0;
					cout << "\nПовторите попытку\n";
					break;
				}
			}
		}
	}
	else
	{
		if (f != 0 and (count < 0 or count > size - 1))
		{
			cout << "\nПовторите попытку\n";
			f = 0;
		}
	}
}

int main()
{
	setlocale(LC_ALL, "ru");
	int size;
	string csize;

	cout << "Введите размерность массива (>0): ";
	cin >> csize;
	verify(csize, size);
	if (f != 0 and size > 0)
	{
		int* FirstArray = new int[size];

		FillArray(FirstArray, size);
		ShowArray(FirstArray, size);

		cout << "\n1)Добавить эл-т(ы)\n2)Удалить эл-т(ы)\n";
		int c;
		cin >> c;

		switch (c)
		{
		case 1:
			App(FirstArray, size);
			break;
		case 2:
			Del(FirstArray, size);
			break;
		default:
			cout << "\nПовторите попытку\n";
			break;
		}
		delete[] FirstArray;
	}
	else
	{
		if (f != 0 and size <= 0)
		{
			cout << "\nПовторите попытку\n";
		}
	}
	return 0;
}