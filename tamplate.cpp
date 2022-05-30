#include <iostream>
#include <stdlib.h>
#include <string>
#include <fstream>

using namespace std;
int print_int()
{
	int res;
	do
	{
		try
		{
			string numstr;
			cout << "введите число ";
			getline(cin, numstr);
			res = stoi(numstr);
			return res;
			
		}
		catch (const exception& ex)
		{
			cout << "ошибка " << ex.what() << "\n";
		}
	} while (true);
}

double division(double A, double B);
template <typename T>
void showArr(T arr[], int length);
template <typename T> 
void fillArr(T arr[]int length, int min, int max);
int main() {
	setlocale(LC_ALL, "Russian");
		int n, m;


	//выход за числовой диапазон
		/*try
		{
			cout << "введите число от 1 до 10";
			cin >> n;
			if (n < 1)
				throw 0;
			if (n > 10)
				throw "введеное число больше";
			cout << "все ок";
		}
		catch (const int ex)
		{
			if (ex == 0)
				cout << "ошибка введеное число меньше";
			

		}
		catch (const char ex[])
		{
			cout << "ошибка " << ex << endl;

		}*/
		//защита от нуба
		/*bool check = false;
		do
		{
			try
			{
				string numstr;
				cout << "введите число ";
				getline(cin, numstr);
				n = stoi(numstr);
				cout << "введено число " << n << endl;
				check = true;
			}
			catch (const exception& ex)
			{
				cout << "ошибка " << ex.what() << "\n";
			}
		} while (!check);*/
		//защита от нуба через функцию
		/*n = print_int();
		cout << "введено " << n << endl;*/

		/*try
		{
			cout << "введите 2 числа " << endl;
			cin >> n >> m;
			cout << n << "/" << m << " = " << division(n, m) << endl;

		}
		catch (const logic_error& ex)
		{
			cout << "ошибка " << ex.what() << endl;
		}*/


	

		string path = "file.txt";
		//проверка открытия файла
		/*ofstream out;
		out.exceptions(ios::badbit| ios:: failbit| ios::eofbit);//разрешает броски исключения
		try
		{
			out.open(path);
			string str;
			cout << "введите строку " << endl;
			getline(cin, str);
			out << str + "\n";
			cout << "запись помещена в файл \n";


			out.close();

		}
		catch (const ios::failure& ex)
		{
			cout << "Ошибка: " << ex.what() << endl;
			cout << "Код ошибки: " << ex.code() << endl;//ex.code показывает код ошибки!!!
		}*/




		cout << "введите длину массива ";
		cin >> n;
		try
		{
			int* arr = new int[n] {};//заполняет массив нулями
			cout << "изначальный массив ";
			showArr(arr, n);
			fillArr(arr, n, 10, 31);
			cout << "итоговый массив ";
			showArr(arr, n);
		}
		catch (const underflow_error& ex)
		{
			cout << "Ошибка: " << ex.what() << endl;
		}
		catch (const bad_array_new_length& ex)
		{
			cout << "Ошибка создания массива: " << ex.what() << endl;
		}
		catch (const invalid_argument& ex)
		{
			cout << "Ошибка диапазона : " << ex.what() << endl;
		}

	return 0;
}
double division(double A, double B)
{
	if (B == 0)
		throw logic_error("division by zero");
	return A / B;
}

template <typename T>
void showArr(T arr[], int length)
{
	if (length <= 0)
		throw underflow_error("длина массива должна быть +");
	cout << "[";
	for (int i = 0; i < length; i++)
		cout << arr[i] << ", ";
	cout << "\b\b]\n";
}

template <typename T>
void fillArr(T arr[], int length, int min, int max)
{
	if (length <= 0)
		throw underflow_error("длина массива должна быть +");
	if (max <= min)
		throw invalid_argument(
			"конец диапазона должен быть больше чем начало"
		);
	srand(time(NULL))
		for (int i = 0; i < length; i++)
			arr[i] = rand() % (max - min) + min;
}

