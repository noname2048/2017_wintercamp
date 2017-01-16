#include"common.hpp"
#include"2017_winter\√÷º∫øÌ\√÷º∫øÌ.h"
#include"2017_winter\±Ë¿Á»Ò\±Ë¿Á»Ò.h"
Timer test;
int main() {
	test.tick();
	freopen("txt/robot.txt", "r", stdin);
	√÷º∫øÌ::robot();
	test.toc();
}