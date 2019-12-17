#include "ArrList.h"
#include <assert.h>

template <class T>
ArrList<T>::ArrList(void)
{
	size = 5;
	count = 0;
	arr = new T[size];
}

template <class T>
int ArrList<T>::Length()
{
	return count;
}

template <class T>
void ArrList<T>::Append(T val)
{
	if (count == size)
		Expand();
	arr[count] = val;
	count++;
}

template <class T>
void ArrList<T>::insertAt(int pos, T val)
{
	assert(pos < count);
	if (count == size)
		Expand();
	for (int i = count; i > pos; i--)
		arr[i] = arr[i - 1];
	arr[pos] = val;
	count++;
}

template <class T>
void ArrList<T>::deleteAt(int pos)
{
	assert(pos < count);
	for (int i = pos; i < count - 1; i++)
		arr[i] = arr[i + 1];
	count--;
}

template <class T>
T ArrList<T>::At(int pos)
{
	assert(pos < count);
	return arr[pos];
}

template <class T>
void ArrList<T>::Expand()
{

	T* a = new T[size * 2];
	for (int i = 0; i < size; i++)
		a[i] = arr[i];
	delete[] arr;
	size *= 2;
	arr = a;
}

template <class T>
void ArrList<T>::Clear()
{
	delete[] arr;
	size = 5;
	arr = new T[size];
	count = 0;

}
template <class T>
ArrList<T>::~ArrList(void)
{
	delete[] arr;
}
