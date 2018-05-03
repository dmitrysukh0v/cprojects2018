// 010318_cpp_course.cpp: главный файл проекта.

#include "stdafx.h"
#include <iostream>
#include <clocale>
#include <ctime>
#include <stdlib.h>

using namespace std;

void wait(int ms){
	int end=clock()+ms;
	while(clock()<end){};
}

class Part{
private:
	Part *last;
	Part *next;
public:
	int x;
	int y;

	Part(){
		last=NULL;
		next=NULL;
	}
	Part(Part *ls){
		last=ls;
		next=NULL;
	}

	Part* GetLast(){
		return last;
	}
	Part* GetNext(){
		return next;
	}
};

class Snake{
private:
	Part *head;
public:
	Snake(){};
	Snake(int x,int y){
		head=new Part();
		head->x=x;
		head->y=y;
	}
	Part* GetHead(){
		return head;
	}
	Part* Eat(Part *part){
		if(part->next!=NULL){
			Eat(head->next);
		}
		else{
			part->next=new Part(part);
		}
		return part->next;
	}
};

class World{
private:
	int **cells;
	int max_x;
	int max_y;
	Snake *snake;
public:
	World(int x,int y){
		cells=(int**)calloc(x+1,sizeof(int*));
		for(int i=0;i<x;i++){
			cells[i]=(int*)calloc(y+1,sizeof(int));
		}
		for(int xi=0;xi<x;xi++){
			for(int yi=0;yi<y;yi++){
				if(xi==0 || xi==(x-1) || yi==0 || yi==(y-1)){
					cells[xi][yi]=1;
				}
				else
					cells[xi][yi]=0;
			}
		}
		max_x=x;
		max_y=y;
		srand(clock());
		int xhead=rand()%x;
		int yhead=rand()%y;
		snake=new Snake(xhead,yhead);
		cells[xhead][yhead]=2;
		for(int i=0;i<50;){
			int xfeed=rand()%x;
			int yfeed=rand()%y;
			if(cells[xfeed][yfeed]==0){
				cells[xfeed][yfeed]=3;
				i++;
			}
		}
	}
	void PrintWorld(){
		system("cls");
		for(int xi=0;xi<max_x;xi++){
			for(int yi=0;yi<max_y;yi++){
				switch(cells[xi][yi]){
					case 1:{
						cout<<'#';
						break;
						   }
					case 2:{
						cout<<'@';
						break;
						   }
					case 3:{
						cout<<'*';
						break;
						   }
					case 4:{
						cout<<'%';
						break;
						   }
					default:{
						cout<<' ';
							}
				}
				cout<<' ';
			}
			cout<<endl;
		}
	}
	void Step(){
		while(true){
			int xv=-1+rand()%3;
			int yv=-1+rand()%3;
			if(cells[snake->GetHead()->x+xv][snake->GetHead()->y+yv]==0 && (xv==0 || yv==0)){
				cells[snake->GetHead()->x][snake->GetHead()->y]=0;
				cells[snake->GetHead()->x+xv][snake->GetHead()->y+yv]=2;
				snake->GetHead()->x=snake->GetHead()->x+xv;
				snake->GetHead()->y=snake->GetHead()->y+yv;
				break;
			}
			if(cells[snake->GetHead()->x+xv][snake->GetHead()->y+yv]==3 && (xv==0 || yv==0)){
				cells[snake->GetHead()->x+xv][snake->GetHead()->y+yv]=0;
				Part *newp=snake->Eat(snake->head);
				int xvp=-1+rand()%3;
				int yvp=-1+rand()%3;
				while(true){
					if(cells[newp->last->x+xvp][newp->last->y+yvp]==0 && (xvp==0 || yvp==0)){
						cells[newp->last->x+xvp][newp->last->y+yvp]==4;
						newp->x=newp->last->x+xvp;
						newp->y=newp->last->y+yvp;
						break;
					}
				}
			}
		}
		PrintWorld();
	}
};

int main()
{
	setlocale(LC_ALL,"Russian");

	World w(30,30);
	
	for(int i=0;i<30;i++){
		w.Step();
		wait(3000);
	}

	int end;
	cin>>end;

    return 0;
}
