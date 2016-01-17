#include<iostream>
#include <stdio.h>
#include"solver.h"
using namespace std;

Solver::Solver() {
	resetPuzzle();
}

Solver::~Solver() {
	//destructor
}

void Solver::displayAll(int guessPuzzle[rows][cols]) {
	cout<<"Correct puzzle"<<endl;

	for (int r = 0; r < rows; r++) {
		cout << "\n[";
		for (int c = 0; c < cols; c++) {
			cout << guessPuzzle[r][c] << " ";
		}
		cout << "]\n" << endl;
	}
}
/*
bool Solver::checkPuzzle(int guessPuzzle[rows][cols]) {
	for (int r = 0; r < rows; r++) {
		for (int c = 0; c < cols; c++) {
			if (!checkRow(r, c, guessPuzzle) ||
				!checkCol(r, c, guessPuzzle) ||
				!checkBox(r, c, guessPuzzle))
				return false;
		}
	}

	return true;
}

*/
bool Solver::checkCell(int R, int C, int guessPuzzle[rows][cols], int value){
	return checkRow(R, guessPuzzle, value) && 
		   checkCol(C, guessPuzzle, value) && 
	       checkBox(R - R%3, C - C%3, guessPuzzle, value);
}

bool Solver::checkRow(int R, int guessPuzzle[rows][cols], int value) {
	//check row
	for (int c = 0; c < cols; c++) 
		if(guessPuzzle[R][c] == value)
			return false;
	
	return true;
}

bool Solver::checkCol(int C, int guessPuzzle[rows][cols], int value) {
	//check col
	for (int r = 0; r < rows; r++) 
		if(guessPuzzle[r][C] == value)
			return false;
	
	return true;
}

bool Solver::checkBox(int R, int C, int guessPuzzle[rows][cols], int value) {
	//check box
	for (int r = 0; r < 3; r++) 
		for (int c = 0; c < 3; c++) 
			if(guessPuzzle[R + r][C + c] == value)
				return false;

	return true;
}
/*
void Solver::resetPuzzle() {
	for (int r = 0; r < rows; r++) {
		for (int c = 0; c < cols; c++) {
			//guessPuzzle[r][c] = correctPuzzle[r][c];
		}
	}
}
*/
bool Solver::checkForCell(int &curr_row, int &curr_col, int guessPuzzle[rows][cols]){
	for(curr_row = 0; curr_row < rows; curr_row++){
		for(curr_col = 0; curr_col < cols; curr_col++){
			if(guessPuzzle[curr_row][curr_col] == 0)
				return true;
		}
	}

	return false;
}

bool Solver::backtrack(int guessPuzzle[rows][cols]){
	int curr_col, curr_row;

	if(!checkForCell(curr_row, curr_col, guessPuzzle))
		return true;

	for(int i = 1; i <= 9; i++){
		if(checkCell(curr_row, curr_col, guessPuzzle, i)){
			
			guessPuzzle[curr_row][curr_col] = i;

			if(backtrack(guessPuzzle))
				return true;

			guessPuzzle[curr_row][curr_col] = 0;
		}
	}

	return false;
}
