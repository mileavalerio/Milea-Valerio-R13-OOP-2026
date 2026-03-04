#include "Math.h"
#include <cstdarg>
#include <string.h>

int Math::Add(int x, int y)
{
	return x + y;
}

int Math::Add(int x, int y, int z)
{
	return x + y + z;
}

int Math::Add(double x, double y)
{
	return x + y;
}

int Math::Add(double x, double y, double z)
{
	return x + y + z;
}

int Math::Mul(int x, int y)
{
	return x * y;
}

int Math::Mul(int x, int y, int z)
{
	return x * y * z;
}

int Math::Mul(double x, double y)
{
	return x * y;
}

int Math::Mul(double x, double y, double z)
{
	return x * y * z;
}

int Math::Add(int count, ...)
{
	int sum = 0;
	va_list param;
	va_start(param, count);

	for (int i = 0; i < count; i++)
	{
		sum += va_arg(param, int);
	}
	va_end(param);
	return sum;
}

char* Math::Add(const char* s, const char* t)
{
	if (s == nullptr || t == nullptr)
		return nullptr;
	int buffer_size = strlen(s) + strlen(t) + 1;
	char* rez = new char[buffer_size];
	strcpy_s(rez, buffer_size, s);
	strcat_s(rez, buffer_size, t);

	return rez;
}