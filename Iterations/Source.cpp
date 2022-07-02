#include <iostream>

#include <thread>

#include <chrono>

using namespace std;
void DoWork()
{
	for (size_t i = 0; i < 10; i++)
	{
		cout << "ID потока =" << this_thread::get_id() << "\tDoWork \t" << i << endl;
		this_thread::sleep_for(chrono::milliseconds(1000));
	}
}

int main()
{
	setlocale(LC_ALL, "rus");

	thread th(DoWork); // указатель на функцию

	thread th2(DoWork);

	DoWork();

	for (size_t i = 0; i < 10; i++)
	{
		cout << "ID потока =" << this_thread::get_id() << "\tmain" << endl;
		this_thread::sleep_for(chrono::milliseconds(500));
	}

	th.join(); // дожидаемся метода 
	th2.join();
	return 0;
}

