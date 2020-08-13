#include "stdafx.h"
#include <iostream>

#ifdef EXPORTS_API
#define MY_API_EXPORT __declspec (dllexport)
#else
#define MY_API_EXPORT __declspec (dllimport)
#endif

extern "C" {
	void MY_API_EXPORT my_print();
}

void my_print()
{
	std::cout << std::endl << "From dll: Hello 7erom!" << std::endl;
}