#include "pch.h"
#include <Windows.h>
#include <iostream>
#include <thread>
#include <mutex>

std::mutex mx1;
std::mutex mx2;

void my_print(int number, int interval)
{
	{
		std::lock_guard<std::mutex> lk(mx1);
		std::cout << "Thread #" << number << " : " << std::hex << GetCurrentThreadId() << std::endl;
	}

	Sleep(interval);

	{
		std::lock_guard<std::mutex> lk(mx2);
		std::cout << "Hello from thread Thread #" << number << std::endl;
	}
}

int main(int argc, char* argv[])
{
	std::cout << "Main Thread : " << std::hex << GetCurrentThreadId() << std::endl;

	int interval = 10'000; // ms

	std::cout << "Creating 3 threads and sleep for 10 seconds..." << std::endl;

	std::thread thr1(my_print, 1, interval);
	std::thread thr2(my_print, 2, interval);
	std::thread thr3(my_print, 3, interval);


	thr1.join();
	thr2.join();
	thr3.join();

	printf("\nSet Last Error: 5 (Access Denied)\n");
	SetLastError(5);

	printf("\npress any key to exit...\n");
	getchar();
	return 0;
}

