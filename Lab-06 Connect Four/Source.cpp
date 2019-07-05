#include<iostream>
using namespace std;
class Connect4Game
{
private:
	int **board;
	int turn;
	int noOfTurns;
	int colNumber;
public:
	Connect4Game()
	{
		setGameBoard();
		for (int i = 0; i < 7; i++)
		{
			for (int j = 0; j < 7; j++)
				board[i][j] = 0;
		}
	}

	void setGameBoard()
	{
		board = new int*[7];
		for (int i = 0; i < 7; i++)
		{
			board[i] = new int[7];
		}
	}
	void defaultNoOfTurn()
	{
		noOfTurns = 0;
	}
	void incNoOfTurns()
	{
		noOfTurns++;
	}
	int switchTurn()
	{
		if (noOfTurns % 2 == 0)
		{
			return 1;
		}
		else
		{
			return 2;
		}
	}
	bool isBoardFull()
	{
		for (int i = 0; i < 7; i++)
		{
			for (int j = 0; j < 7; j++)
			{
				if (board[i][j] == 0)
				{
					return false;
				}
			}
		}
		return true;
	}
	void setEntry(int c,int i)
	{
		if (switchTurn()==1)
		{
			for (int r = 6; r >= 0; r--)
			{
				if (board[r][c] == 0)
				{
					board[r][c] = 1;
					break;
				}
			}
		}
		else
		if (switchTurn()==2)
		{
			for (int r = 6; r >= 0; r--)
			{
				if (board[r][c] == 0)
				{
					board[r][c] = 2;
					break;
				}
			}
		}
	}
	void showBoard()
	{
		for (int i = 0; i < 7; i++)
		{
			for (int j = 0; j < 7; j++)
			{
				cout << board[i][j] << " ";
			}
			cout << endl;
		}
	}
	int isWon()
	{
		if (checkHorizontalWinner() == 1)
		{
			cout << "Winner. 1" << endl;
			exit(0);
		}
		else
		if (checkHorizontalWinner() == 2)
		{
			cout << "Winner. 2" << endl;
			exit(0);
		}
		else
		if (checkVerticalWinner() == 1)
		{
			cout << "Winner. 1" << endl;
			exit(0);
		}
		else
		if (checkVerticalWinner() == 2)
		{
			cout << "Winner. 2" << endl;
			exit(0);
		}
		else
		if (checkLeftDiagonalWinner() == 1)
		{
			cout << "Winner. 1" << endl;
			exit(0);
		}
		else
		if (checkLeftDiagonalWinner() == 2)
		{
			cout << "Winner. 2" << endl;
			exit(0);
		}
		else
		if (checkRightDiagonalWinner() == 1)
		{
			cout << "Winner. 1" << endl;
			exit(0);
		}
		else
		if (checkRightDiagonalWinner() == 2)
		{
			cout << "Winner. 2" << endl;
			exit(0);
		}
		else
		if (isBoardFull()==true)
		{
			cout << "Game Drawn." << endl;
			exit(0);
		}
	}
	int checkHorizontalWinner()
	{
		int x = 1, e = 0;
		for (int i = 0; i < 7; i++)
		{
			x = 1;
			for (int j = 0; j < 6; j++)
			{
				if ((board[i][j] == 1 || board[i][j]== 2) && (board[i][j] == board[i][j + 1]))
				{
					e = board[i][j];
					x++;
					if (x == 4)
					{
						return e;
					}
				}
				else
				{
					x = 1;
				}
			}
		}
	}
	int checkVerticalWinner()
	{
		int x = 1, e = 0;
		for (int j = 0; j < 7; j++)
		{
			x = 1;
			for (int i = 0; i < 6; i++)
			{
				if ((board[i][j] == 1 || board[i][j] == 2) && (board[i][j] == board[i+1][j]))
				{
					e = board[i][j];
					x++;
					if (x == 4)
					{
						return e;
					}
				}
				else
				{
					x = 1;
				}
			}
		}
	}
	int checkLeftDiagonalWinner()
	{
		int x = 1, e = 0;
		for (int i = 0; i < 7; i++)
		{
			for (int j = 7; j >= 0; j--)
			{
				x = 1;
				for (int a = i, b = j; (a + 1) < 7 && (b + 1) < 7; a++, b++)
				{
					if ((board[a][b] == 1 || board[a][b] == 2) && (board[a][b] == board[a+1][b+1]))
					{
						e = board[a][b];
						x++;
						if (x == 4)
						{
							return e;
						}
					}
					else
					{
						x = 1;
					}
				}
			}
		}
	}
	int checkRightDiagonalWinner()
	{
		int x = 1, e = 0;
		for (int i = 0; i < 7; i++)
		{
			for (int j = 0; j < 7; j++)
			{
				x = 1;
				for (int a = i, b = j; ((a + 1) < 7) && ((b - 1) >= 0); a++, b--)
				{
					if ((board[a][b] == 1 || board[a][b] == 2) && (board[a][b] == board[a + 1][b - 1]))
					{
						e = board[a][b];
						x++;
						if (x == 4)
						{
							return e;
						}
					}
					else
					{
						x = 1;
					}
				}
			}
		}
	}
	bool isColumnFilled(int col)
	{
		for (int i = 6; i >= 0; i--)
		{
			if (board[i][col] == 0)
			{
				return false;
			}
		}
		return true;
	}
	void setColumnOfGrid()
	{
		int c = 0;
		do
		{
			cout << "Player-" << switchTurn() << "'s Turn: " << "Enter Column of grid (0-6) where you want to put an entry: ";
			cin >> c;	
		} while (checkColumnEntry(c) == false);

		if (checkColumnEntry(c) == true)
		{
			colNumber = c;
		}
	}
	bool checkColumnEntry(int c)
	{
		if (c > 6)
		{
			cout << "Please Enter Valid Column grid." << endl;
			return false;
		}
		else
		if (isColumnFilled(c) == true)
		{
			cout << "Column has been filled. Try another." << endl;
			return false;
		}
		else
		{
			return true;
		}
	}
	void start()
	{
		showBoard();
		for (int i = 0; i < 7 * 7; i++)
		{
			setColumnOfGrid();
			setEntry(colNumber, i);
			showBoard();
			isWon();
			incNoOfTurns();

		}

	}
};
int main()
{
	Connect4Game game;
	game.start();
}