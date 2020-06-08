// lab5_1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <math.h>
#include <iostream>
#include <fstream>
#include <string>
#include <stdio.h>
#include <fstream>
#include <sstream>
#include <algorithm>

using namespace std;

struct spik {
	float s = 0;
	string imya = " ";
	string fam = " ";
	string otch = " ";
	string raion = " ";
	int stoimost = 0;

};

bool sor(const spik& a1, const spik& a2)
{
	return a1.fam < a2.fam;
}

int main()
{
	setlocale(LC_ALL, "rus");

	string x;
	spik s;
	ifstream vod;

	vod.open("1.txt");
	int l=0;

	if (vod.is_open()) {
		while (!vod.eof()) {
			string s;
			getline(vod, s);
			l++;
		}
	}

	spik* Arr = new spik[l];
	vod.seekg(0, ios_base::beg);//начало файла

	for (size_t i = 0; i < l; i++)
	{
		getline(vod, x);
		istringstream iss(x);//поток ввода
		iss >> s.s >> s.imya >> s.fam >> s.otch >> s.raion >> s.stoimost;
		Arr[i] = s;

	}

	cout << "Все квартиры: \n" << endl;

	for (size_t n = 0; n < l; n++)
	{
		cout << "Площадь : " << Arr[n].s << " "
			<< "Имя : " << Arr[n].imya << " "
			<< "Фамилия : " << Arr[n].fam << " "
			<< "Отчество : " << Arr[n].otch << " "
			<< "Район : " << Arr[n].raion << " "
			<< "Стоимость : " << Arr[n].stoimost << endl;
	}

	cout << "\nКвартиры находящиeся в Центральном районе :\n" << endl;

	for (size_t n = 0; n < l; n++)
	{
		if (Arr[n].raion == "central")
		{
			cout << "Площадь : " << Arr[n].s << " "
				<< "Имя : " << Arr[n].imya << " "
				<< "Фамилия : " << Arr[n].fam << " "
				<< "Отчество : " << Arr[n].otch << " "
				<< "Район : " << Arr[n].raion << " "
				<< "Стоимость : " << Arr[n].stoimost << endl;
		}
	}
	cout << "\nКвартиры стоимостью более 1000к отсортированная по алфавиту:\n" << endl;

	sort(Arr, Arr + l, sor);
	for (size_t n = 0; n < l; n++)
	{
		if (Arr[n].stoimost > 1000)
		{
			cout << "Площадь : " << Arr[n].s << " "
				<< "Имя : " << Arr[n].imya << " "
				<< "Фамилия : " << Arr[n].fam << " "
				<< "Отчество : " << Arr[n].otch << " "
				<< "Район : " << Arr[n].raion << " "
				<< "Стоимость : " << Arr[n].stoimost << endl;
		}
	}
	vod.close();
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
//https://ru.cppreference.com/w/cpp/algorithm/sort