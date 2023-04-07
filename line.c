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
	/*move(c.y+r, c.x);
	insch('*');
	move(c.y-r, c.x);
	insch('*');
	move(c.y, c.x+r*2);
	insch('*');
	move(c.y, c.x-r*2);
	insch('*');*/

	for(int i = 1; i < 3; i++){
		move((c.y+r)-c.y/i, (c.x-r*2)+c.x/i);
		insch('*');
		move((c.y-r)+c.y/i, (c.x+r*2)-c.x/i);
		insch('*');
		move((c.y+r)-c.y/i, (c.x+r*2)-c.x/i);
		insch('*');
		move((c.y-r)+c.y/i, (c.x-r*2)+c.x/i);
		insch('*');
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

	Circle* circle = newCircle(*point, 5);

	drawCircle(*circle);
	refresh();

	for(;;){
		if(getch()=='q') break;
	}
	
	return 0;
}
