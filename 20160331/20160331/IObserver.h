//#pragma once // C11 에서 공식 표준으로 채택
#ifndef IOBSERVER_H
#define IOBSERVER_H

struct IObserver
{
	virtual void onUpdate(void* data) = 0;
	virtual ~IObserver() {}
};

#endif