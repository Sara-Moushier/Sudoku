#pragma once
template <class T>
class ArrList
{
	int count, size;
	T* arr;
public:
	ArrList(void);
	int Length();
	T At(int);
	void Append(T);
	void insertAt(int, T);
	void deleteAt(int);
	void Expand();
	void Clear();
	~ArrList(void);
};

