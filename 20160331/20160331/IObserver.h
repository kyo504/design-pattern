//#pragma once // C11 ���� ���� ǥ������ ä��
#ifndef IOBSERVER_H
#define IOBSERVER_H

struct IObserver
{
	virtual void onUpdate(void* data) = 0;
	virtual ~IObserver() {}
};

#endif