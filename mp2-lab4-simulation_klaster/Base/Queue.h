#ifndef __QUEUE_H__
#define __QUEUE_H__

#include <iostream>

using namespace std;

//������� ������������ �� ��������� ������.
template<typename ValType>
class TQueue
{
private:
	int QueueSize;
	ValType *pQueueArray;
	int HeadIndex;
	int TailIndex;
	int CountData;

	int GetNextIndex(int index);
	TQueue(const TQueue&) = delete;//������ �� ����������� �������.
	TQueue<ValType>& operator=(const TQueue&) = delete;// ������ �� ������������ �������.
public:
	TQueue(int _QueueSize);
	int GetSizeQueue();//�������� ������ �������
	int GetCountData();//���������� ��������� � �������
	void Push(const ValType& data); //���������� �������� � ����� �������
	void Pop(); //�������� ������� ��������
	ValType& Front();//���������� � ������� �������� ������� - ���������� � ��������
	ValType& Back(); //��������� � ���������� �������� ������� - ���������� � ��������
	bool Empty(); //�������� �� ������� �������
	bool Full(); //�������� �� ��������� �������
	void PrintQueue();//���������� ��������� �������
	~TQueue();
};

template<typename ValType>
int TQueue<ValType>::GetNextIndex(int index)
{
	return ++index % QueueSize;
}

template<typename ValType>
TQueue<ValType>::TQueue(int _QueueSize) 
{
	if (_QueueSize < 1)
		throw "ERROR! Size is negative number or 0";
	QueueSize = _QueueSize;
	pQueueArray = new ValType[QueueSize];
	HeadIndex = 0;
	TailIndex = -1;
	CountData = 0;
}

template<typename ValType>
int TQueue<ValType>::GetSizeQueue()
{
	return QueueSize;
}

template<typename ValType>
int TQueue<ValType>::GetCountData()
{
	return CountData;
}

template<typename ValType>
void TQueue<ValType>::Push(const ValType& data)
{
	if (Full())
		throw "ERROR! Unable to put an element.";
	TailIndex = GetNextIndex(TailIndex);
	pQueueArray[TailIndex] = data;
	CountData++;
}

template<typename ValType>
void TQueue<ValType>::Pop()
{
	if (Empty())
		throw "ERROR! Unable to put an element.";
	HeadIndex = GetNextIndex(HeadIndex);
	CountData--;
}

template<typename ValType>
ValType& TQueue<ValType>::Front()
{
	return pQueueArray[HeadIndex];
}

template<typename ValType>
ValType& TQueue<ValType>::Back()
{
	return pQueueArray[TailIndex];
}

template<typename ValType>
bool TQueue<ValType>::Empty()
{
	if (CountData == 0)
		return true;
	else
		return false;
}

template<typename ValType>
bool TQueue<ValType>::Full()
{
	if (CountData == QueueSize)
		return true;
	else
		return false;
}

template<typename ValType>
void TQueue<ValType>::PrintQueue()
{
	for (int i = HeadIndex, j = 0 ; j < CountData ; j++)
	{
		cout << j + 1 << ") " << pQueueArray[i] << endl;
		i = GetNextIndex(i);
	}
}

template<typename ValType>
TQueue<ValType>::~TQueue()
{
	delete[] pQueueArray;
}

#endif 