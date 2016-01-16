#ifndef SOLVER_H
#define SOLVER_H

const int rows = 9;
const int cols = 9;

class Solver {
public:

	Solver();
	~Solver();

	void displayAll(int [rows][cols]);
	void enterData();
	//bool checkPuzzle(int [rows][cols]);
	bool checkRow(int R, int [rows][cols], int value);
	bool checkCol(int C, int [rows][cols], int value);
	bool checkBox(int R, int C, int [rows][cols], int value);

	//bool UsedInRow(int [rows][cols], int, int);
	//bool UsedInCol(int [rows][cols], int, int);
	//bool UsedInBox(int, int, int [rows][cols], int);
	//bool isSafe(int, int, int [rows][cols], int);

	void resetPuzzle();
	bool backtrack(int [rows][cols]);
	bool checkForCell(int&, int&, int [rows][cols]);
	bool checkCell(int R, int C, int [rows][cols], int value);
};

#endif