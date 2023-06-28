#include <stdlib.h>

#include <curses.h>

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

	for(int i = c.y; i < (r+c.y); i++){
		int di = i;
		int dj = (c.x-r) + i;
		move(i, ( (c.x-r) + i ) );
		insch('*');
		di = i*(-1);
		dj = (c.x+r) - i;
		move(i*(-1), ( (c.x+r) - i ) );
		insch('*');
		refresh();
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
	insch('X');

	Circle* circle = newCircle(*point, 5);

	drawCircle(*circle);
	refresh();

	for(;;){
		if(getch()=='q') break;
	}
	
	return 0;
}
