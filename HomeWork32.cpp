#include <iostream>
#include <ctime>
#include <cstdlib>
#include <cmath>
#include <string>
#include <fstream>
using namespace std;

//Задача 32.3.
struct route {
	int numb_route{};  //номер маршрута
	string transport{}; //тип транспорта(автобус, трамвай, троллейбус)
	string start_stop{}; //остановка начала маршрута
	string end_stop{};   //конечная остановка
};

//Задача 32.1.
template <typename T>
void memory(T* ptr, int num1, int num2) {
	ptr = new T[num1];
	for (int i = 0; i < num1; i++){
		ptr[i] = new int [num2];
	}

}
//Задача 32.2.
string replacement(string& str, char sym1, char sym2) {
	
	for (int i = 0; i < str.length(); i++)
	{
		if (str[i] == sym1)
		str[i] = sym2;
	}
	return str;
};


//Задача 32.3.
//Выводит полную информацию о полях структуры. 
void show_route(route& R) {
	cout << "Номер маршрута:               " << R.numb_route << '\n';
	cout << "Тип транспорта:               " << R.transport << '\n';
	cout << "Начальная остановка маршрута: " << R.start_stop << '\n';
	cout << "Конечная остановка маршрута:  " << R.end_stop << '\n';
	cout << "----------------------------------\n";
}
//Задача 32.3.
//Заполняет поля структуры
void fill_route(route& R) {
	cout << "Введите номер маршрута: ";
	cin >> R.numb_route;
	cout << "Введите тип транспорта: ";
	cin.ignore();
	getline(cin, R.transport);
	cout << "Введите начальную остановку маршрута: ";
	cin.ignore();
	getline(cin, R.start_stop);
	cout << "Введите конечную остановку маршрута: ";
	cin.ignore();
	getline(cin, R.end_stop);	
}
//Задача 32.3.
//Вычисляет стоимость проезда для определённого количества человек
void fare(route & R, int num){
	double price;
	cout << "Введите стоимость проезда: ";
	cin >> price;
	cout << "Цена проезда для " << num << " человек по маршруту № " << R.numb_route << " на " << R.transport << " составит: " << price * num << '\n';
}






int main() {
	setlocale(LC_ALL, "Russian");
	int n, m;

	//Задача 32.1. Создайте функцию, которая принимает указатель на указатель любого типа и два числа.
	//Функция направляет переданный указатель на область памяти, являющуюся двумерным массивом с размерами, равными переданным числам.

	cout << "Задача 32.1\n";
	cout << "Введите первое число: ";
	cin >> n;
	cout << "\nВведите первое число: ";
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

	//Задача 32.2.Напишите функцию, которая принимает строковый объект и символы ch1 и ch2.
	//Функция ищет в переданной строке символы ch1 и меняет их на символ ch2. Учтите, что строка должна передавать по ссылке.
	cout << "Задача 32.2\n";
	string str;
	cout << "\nВведите строку: ";
	getline(cin, str);
	
	char s1, s2;
	cout << "\nВведите первый символ: ";
	cin >> s1;
	cout << "\nВведите второй символ: ";
	cin >> s2;
	
	cout << replacement(str, s1, s2);
	cout << "\n\n";


	//Задача 32.3. Создайте структуру route, которая описывает транспортный маршрут и содержит следующие поля:
	//номер маршрута;
	//тип транспорта(автобус, трамвай, троллейбус);
	//остановка начала маршрута;
	//конечная остановка.
	//Создайте объекты данной структуры и на их примере продемонстрируйте работу следующих функций, которые необходимо написать :
	// - функция, выводящая информацию об объекте;
	// - функция, которая вычисляет стоимость проезда для определённого количества человек, которое передаётся в функцию.
	cout << "Задача 32.3\n";

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