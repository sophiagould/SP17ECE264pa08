#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#include "solver.h"
#include "path.h"

char * solveMaze(Maze * m) {
	char * retval = malloc(sizeof(char) * ((m->width * m->height) + 1));

	MazePos mp = {.xpos = m->start.xpos, .ypos = m->start.ypos};
	if (!depthFirstSolve(m, mp, retval, 0)) {
		fprintf(stderr, "No solution found!\n");
	} else {
		printf("Solution found: %s\n", retval);
	}
	
	return retval;
}

bool depthFirstSolve(Maze * m, MazePos curpos, char * path, int step) {

	//FILL IN
	if(curpos.ypos < 0 || curpos.xpos < 0 || curpos.xpos >= m -> width || curpos.ypos >= m -> height){
		return false;
	}
	if(m -> maze[curpos.ypos][curpos.xpos].type == WALL){
		return false;
	}
	if(m -> maze[curpos.ypos][curpos.xpos].type == END){
		path[step] = '\0';
		return true;
	}
	if(m -> maze[curpos.ypos][curpos.xpos].visited == true){
		return false;
	}

	m -> maze[curpos.ypos][curpos.xpos].visited = true;
	curpos.xpos--;
	if(depthFirstSolve(m,curpos,path,step +1) == true){
		path[step] = WEST;
		return true;
	}
	curpos.xpos++;
	curpos.xpos++;
	
	if(depthFirstSolve(m,curpos,path,step +1) == true){
		path[step] = EAST;
		return true;
	}
	curpos.xpos--;
	curpos.ypos--;

	if(depthFirstSolve(m,curpos,path,step +1) == true){
		path[step] = NORTH;
		return true;
	}
	curpos.ypos++;
	curpos.ypos++;
	
	if(depthFirstSolve(m,curpos,path,step +1) == true){
		path[step] = SOUTH;
		return true;
	}
	curpos.ypos--;
	return false;
}
