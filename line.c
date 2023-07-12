#include <stdlib.h>

#include <curses.h>



int abs(int x){
	if(x < 0) return x*=-1;
	
	return x;
}

int pow2(int x){
	return x*x;
}


typedef struct Point {
	int x;
	int y;
} Point;

Point* newPoint(int nx, int ny){
	Point* p = malloc(sizeof(Point));
	p->x = nx;
	p->y = ny;
	return p;
}


typedef struct Line {
	Point p1;
	Point p2;
} Line;


typedef struct Circle {
	Point center;
	int radius;
} Circle;

Circle* newCircle(Point p, int r){
	Circle* c = malloc(sizeof(Circle));
	c->center = p;
	c->radius = r;
	return c;
}

void drawCircle(Circle circle){
	Point c = circle.center;
	int r = circle.radius;
	
	/*int xx = c.x-r;
	int yy = 0;

<<<<<<< HEAD
	while(xx <= c.x+r){
		if( (abs(xx-c.x) + abs(yy-c.y)) > r ){
			
		}	//abs(xx-c.x) && abs(yy-c.y)
	}*/

	int xx = c.x-r;
	int yy = c.y-r;

	for(int x = xx; x <= (c.x+r); x++){
		for(int y = yy; y <= (c.y+r); y++){
			if(pow2(abs(x-c.x))+pow2(abs(y-c.y))<=pow2(r) && x != c.x && y != c.y){
				move(y,x);
				insch('*');
			}
		}
	}
}

int main(){
	WINDOW* window;
	
	window = initscr();
	
	cbreak();
	noecho();
	
	clear();
	refresh();

	Point* point = newPoint(30, 15);
	move(point->y, point->x);
	insch('*');

	Circle* circle = newCircle(*point, 6);

	drawCircle(*circle);
	refresh();

	for(;;){
		if(getch()=='q') break;
	}
	
	return 0;
}
