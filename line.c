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
	move(c.x+r, c.y);
	insch('*');
	move(c.x-r, c.y);
	insch('*');
	move(c.x, c.y+r*2);
	insch('*');
	move(c.x, c.y-r*2);
	insch('*');

	refresh();
}

int main(){
	WINDOW* window;
	
	window = initscr();
	
	cbreak();
	noecho();
	
	clear();
	refresh();

	Point* point = newPoint(15, 30);

	Circle* circle = newCircle(*point, 5);

	drawCircle(*circle);

	for(;;){
		if(getch()=='q') break;
	}
	
	return 0;
}
