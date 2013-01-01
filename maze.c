#include <stdio.h>
#include <stdlib.h>

typedef struct square {
	char borderN;
	char borderE;
} square;

typedef struct maze {
	int width;
	int height;
	/*
 	 * squares[0] is top left
 	 * squares[1] is 2nd left on the top
 	 * ...
 	 * squares[width*height-2] is 2nd right on the bottom
 	 * squares[width*height-1] is bottom right
	 */
	square* squares;
} maze;

maze *new_maze(width, height) {
	maze* maze = malloc(sizeof(maze));
	maze->width = width;
	maze->height = height;
	maze->squares = malloc(width*height*sizeof(square));
	return maze;
}

void free_maze(maze *maze) {
	free(maze->squares);
	free(maze);
}

void print_maze(maze *maze) {
	for (int y=0; y < maze->height; y++) {
		// top border
		for (int x=0; x < maze->width; x++) {
			printf("*");
			if (maze->squares[maze->width*y +x].borderN) {
				printf("*");
			} else {
				printf(" ");
			}
		}
		printf("*\n");
		// East border and blank for square
		for (int x=0; x < maze->width; x++) {
			if (maze->squares[maze->width*y +x].borderE) {
				printf("*");
			} else {
				printf(" ");
			}
			printf(" ");
		}
		printf("*\n");
	}
	// Very bottom border
	for (int x=0; x < maze->width-1; x++) {
		printf("**");
	}
	printf("* *\n");
}

int main(int argc, char **argv) {
	maze *m = new_maze(3, 3);
	
	// Generate a simple maze
	m->squares[0].borderN=0;
	m->squares[0].borderE=1;
	m->squares[1].borderN=1;
	m->squares[1].borderE=0;
	m->squares[2].borderN=1;
	m->squares[2].borderE=0;

	m->squares[3].borderN=1;
	m->squares[3].borderE=1;
	m->squares[4].borderN=0;
	m->squares[4].borderE=0;
	m->squares[5].borderN=1;
	m->squares[5].borderE=0;

	m->squares[6].borderN=0;
	m->squares[6].borderE=1;
	m->squares[7].borderN=1;
	m->squares[7].borderE=0;
	m->squares[8].borderN=1;
	m->squares[8].borderE=0;
	print_maze(m);
	free_maze(m);
	return 0;
}

