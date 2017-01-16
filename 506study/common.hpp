#pragma once
#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<time.h>

//시간을 체크하기 위해 만든 단일 시간 체크용 클래스
class Timer {
public:
	Timer() {
		p = true;
		startTime = -1;
		finTime = -1;
	}
	void tick();
	double toc();
protected:
	//이 기능은 파생만 클래스만 사용가능
	void p_off() {
		p = false;
	};
private:
	//clock_t = long(8byte signed int)
	bool p;
	clock_t startTime;
	clock_t finTime;
};

void Timer::tick() {
	if(p) printf("Clock start\n");
	startTime = clock();
}
double Timer::toc() {
	if (startTime < 0) {
		if(p) printf("call tick first\n");
		return -1;
	}
	finTime = clock();
	double t = (double)(finTime - startTime) / CLOCKS_PER_SEC;
	if (p) printf("take time (%08.5lf)sec\n", t);
	return t;
}

//현재 테스트용 기능(사용될일이 없을듯)
class AlgoritmTimer : Timer {
public:
	AlgoritmTimer() {
		total = 0;
	}
	void check(char *txtName, void *func());
private:
	double total;
};

void AlgoritmTimer::check(char *txtName, void *func()) {
	p_off();
	for (int i = 0; i < 5; i++) {
		tick();
		freopen((const char*)txtName, "r", stdin);
		func();
		total += toc() / 5;
	}
}
