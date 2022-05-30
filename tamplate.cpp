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
			cout << "������� ����� ";
			getline(cin, numstr);
			res = stoi(numstr);
			return res;
			
		}
		catch (const exception& ex)
		{
			cout << "������ " << ex.what() << "\n";
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


	//����� �� �������� ��������
		/*try
		{
			cout << "������� ����� �� 1 �� 10";
			cin >> n;
			if (n < 1)
				throw 0;
			if (n > 10)
				throw "�������� ����� ������";
			cout << "��� ��";
		}
		catch (const int ex)
		{
			if (ex == 0)
				cout << "������ �������� ����� ������";
			

		}
		catch (const char ex[])
		{
			cout << "������ " << ex << endl;

		}*/
		//������ �� ����
		/*bool check = false;
		do
		{
			try
			{
				string numstr;
				cout << "������� ����� ";
				getline(cin, numstr);
				n = stoi(numstr);
				cout << "������� ����� " << n << endl;
				check = true;
			}
			catch (const exception& ex)
			{
				cout << "������ " << ex.what() << "\n";
			}
		} while (!check);*/
		//������ �� ���� ����� �������
		/*n = print_int();
		cout << "������� " << n << endl;*/

		/*try
		{
			cout << "������� 2 ����� " << endl;
			cin >> n >> m;
			cout << n << "/" << m << " = " << division(n, m) << endl;

		}
		catch (const logic_error& ex)
		{
			cout << "������ " << ex.what() << endl;
		}*/


	

		string path = "file.txt";
		//�������� �������� �����
		/*ofstream out;
		out.exceptions(ios::badbit| ios:: failbit| ios::eofbit);//��������� ������ ����������
		try
		{
			out.open(path);
			string str;
			cout << "������� ������ " << endl;
			getline(cin, str);
			out << str + "\n";
			cout << "������ �������� � ���� \n";


			out.close();

		}
		catch (const ios::failure& ex)
		{
			cout << "������: " << ex.what() << endl;
			cout << "��� ������: " << ex.code() << endl;//ex.code ���������� ��� ������!!!
		}*/




		cout << "������� ����� ������� ";
		cin >> n;
		try
		{
			int* arr = new int[n] {};//��������� ������ ������
			cout << "����������� ������ ";
			showArr(arr, n);
			fillArr(arr, n, 10, 31);
			cout << "�������� ������ ";
			showArr(arr, n);
		}
		catch (const underflow_error& ex)
		{
			cout << "������: " << ex.what() << endl;
		}
		catch (const bad_array_new_length& ex)
		{
			cout << "������ �������� �������: " << ex.what() << endl;
		}
		catch (const invalid_argument& ex)
		{
			cout << "������ ��������� : " << ex.what() << endl;
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
		throw underflow_error("����� ������� ������ ���� +");
	cout << "[";
	for (int i = 0; i < length; i++)
		cout << arr[i] << ", ";
	cout << "\b\b]\n";
}

template <typename T>
void fillArr(T arr[], int length, int min, int max)
{
	if (length <= 0)
		throw underflow_error("����� ������� ������ ���� +");
	if (max <= min)
		throw invalid_argument(
			"����� ��������� ������ ���� ������ ��� ������"
		);
	srand(time(NULL))
		for (int i = 0; i < length; i++)
			arr[i] = rand() % (max - min) + min;
}

