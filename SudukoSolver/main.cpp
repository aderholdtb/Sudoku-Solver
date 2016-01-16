#include<iostream>
#include"solver.h"
using namespace std;


int main(){
	Solver solver;
	
		int correctPuzzle[rows][cols] = {{3, 0, 7, 0, 4, 0, 0, 0, 0},
										 {0, 6, 2, 0, 0, 3, 0, 0, 0},
										 {0, 4, 0, 6, 0, 2, 0, 0, 0},
										 {8, 5, 0, 0, 0, 1, 0, 0, 6},
										 {0, 0, 0, 4, 0, 0, 0, 0, 1},
										 {0, 0, 3, 0, 0, 0, 0, 9, 0},
										 {0, 0, 1, 0, 9, 7, 0, 2, 0},
										 {0, 0, 0, 8, 0, 0, 0, 0, 0},
										 {2, 0, 0, 5, 0, 0, 7, 0, 0}};

	cout<<"Thinking..."<<endl;
	
	if(solver.backtrack(correctPuzzle))
		solver.displayAll(correctPuzzle);
	else
		cout<<"No solution Found"<<endl;


	return 0;
}