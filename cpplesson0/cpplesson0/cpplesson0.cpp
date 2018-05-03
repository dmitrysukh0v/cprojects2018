// cpplesson0.cpp: главный файл проекта.

#include "stdafx.h"
#include <iostream>
#include <cstdlib>

using namespace std;

class Game{
public:
	Game(int x,int y){
		cells=(int**)malloc((x*y)+1);
		for(int i=0;i<x;i++){
			cells[i]=(int*)malloc(y+1);
		}
	}
private:
	int **cells;
};

int main()
{
	Game g(10,10);
    return 0;
}
