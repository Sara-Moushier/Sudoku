#pragma once
#include <iostream>
#include <utility>
#include <fstream>
#include <queue>
constexpr auto NIL = -1;
typedef std::pair<int, int> cell;

class SudokuSolver
{
	class Adress
	{
	public:
		cell here;
		cell prev;
		int val;
		Adress(cell u, cell v, int x) {
			here = u;
			prev = v;
			val = x;
		}
	};

	int** grid;
	int size;
	bool isDiagonal;
	bool solveSudoku();
	cell findNextCellToFill();
	bool checkDiagonals();
	bool solveIterative();
	bool giveOutAll();
	void saveToFile(std::ofstream&);
	void outputAll(bool&, std::ofstream&);
	bool isValid(int x, int y);
	void display();
public:
	SudokuSolver();
	SudokuSolver(int**, int);
	SudokuSolver(int**, int, bool);
	void getAll();
	void solve();
	~SudokuSolver();
};

