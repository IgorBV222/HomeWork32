#include <iostream>
#include <ctime>
#include <cstdlib>
#include <cmath>
#include <string>
#include <fstream>
using namespace std;

//������ 32.3.
struct route {
	int numb_route{};  //����� ��������
	string transport{}; //��� ����������(�������, �������, ����������)
	string start_stop{}; //��������� ������ ��������
	string end_stop{};   //�������� ���������
};

//������ 32.1.
template <typename T>
void memory(T* ptr, int num1, int num2) {
	ptr = new T[num1];
	for (int i = 0; i < num1; i++){
		ptr[i] = new int [num2];
	}

}
//������ 32.2.
string replacement(string& str, char sym1, char sym2) {
	
	for (int i = 0; i < str.length(); i++)
	{
		if (str[i] == sym1)
		str[i] = sym2;
	}
	return str;
};


//������ 32.3.
//������� ������ ���������� � ����� ���������. 
void show_route(route& R) {
	cout << "����� ��������:               " << R.numb_route << '\n';
	cout << "��� ����������:               " << R.transport << '\n';
	cout << "��������� ��������� ��������: " << R.start_stop << '\n';
	cout << "�������� ��������� ��������:  " << R.end_stop << '\n';
	cout << "----------------------------------\n";
}
//������ 32.3.
//��������� ���� ���������
void fill_route(route& R) {
	cout << "������� ����� ��������: ";
	cin >> R.numb_route;
	cout << "������� ��� ����������: ";
	cin.ignore();
	getline(cin, R.transport);
	cout << "������� ��������� ��������� ��������: ";
	cin.ignore();
	getline(cin, R.start_stop);
	cout << "������� �������� ��������� ��������: ";
	cin.ignore();
	getline(cin, R.end_stop);	
}
//������ 32.3.
//��������� ��������� ������� ��� ������������ ���������� �������
void fare(route & R, int num){
	double price;
	cout << "������� ��������� �������: ";
	cin >> price;
	cout << "���� ������� ��� " << num << " ������� �� �������� � " << R.numb_route << " �� " << R.transport << " ��������: " << price * num << '\n';
}






int main() {
	setlocale(LC_ALL, "Russian");
	int n, m;

	//������ 32.1. �������� �������, ������� ��������� ��������� �� ��������� ������ ���� � ��� �����.
	//������� ���������� ���������� ��������� �� ������� ������, ���������� ��������� �������� � ���������, ������� ���������� ������.

	cout << "������ 32.1\n";
	cout << "������� ������ �����: ";
	cin >> n;
	cout << "\n������� ������ �����: ";
	cin >> m;

	int** pArr = nullptr;
	memory(pArr, n, m);
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			pArr[i][j] = rand() % 20;
		}
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cout << pArr[i][j] << '\t';
		}
		cout << '\n';
	}

	for (int i = 0; i < n; i++)
	{
		delete[] pArr[i];
	}
	delete[] pArr;
	cout << "\n\n";

	//������ 32.2.�������� �������, ������� ��������� ��������� ������ � ������� ch1 � ch2.
	//������� ���� � ���������� ������ ������� ch1 � ������ �� �� ������ ch2. ������, ��� ������ ������ ���������� �� ������.
	cout << "������ 32.2\n";
	string str;
	cout << "\n������� ������: ";
	getline(cin, str);
	
	char s1, s2;
	cout << "\n������� ������ ������: ";
	cin >> s1;
	cout << "\n������� ������ ������: ";
	cin >> s2;
	
	cout << replacement(str, s1, s2);
	cout << "\n\n";


	//������ 32.3. �������� ��������� route, ������� ��������� ������������ ������� � �������� ��������� ����:
	//����� ��������;
	//��� ����������(�������, �������, ����������);
	//��������� ������ ��������;
	//�������� ���������.
	//�������� ������� ������ ��������� � �� �� ������� ����������������� ������ ��������� �������, ������� ���������� �������� :
	// - �������, ��������� ���������� �� �������;
	// - �������, ������� ��������� ��������� ������� ��� ������������ ���������� �������, ������� ��������� � �������.
	cout << "������ 32.3\n";

	route R1, R2, R3;

	fill_route(R1);
	cout << "----------------------------------\n";
	fill_route(R2);
	cout << "----------------------------------\n";
	fill_route(R3);
	cout << "----------------------------------\n";

	show_route(R1);
	cout << "----------------------------------\n";
	show_route(R2);
	cout << "----------------------------------\n";
	show_route(R3);
	cout << "----------------------------------\n";

	fare(R1, 5);

	cout << "----------------------------------\n";

	return 0;
}