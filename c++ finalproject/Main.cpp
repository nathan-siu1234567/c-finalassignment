#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
using namespace std;

char square[10] = { 'o','1','2','3','4','5','6','7','8','9' };

int checkwin();
void board();
void readFromFile();
void writeToFile(int, int);
string p1, p2;
int userInput;
int main()
{
	int player = 1, i, choice;
	int score = 0;
	cout << "Hello and welcome to tic-tac-toe" << endl;
	cout << "Press 1 to view winners list" << endl;
	cout << "Press 2 to play" << endl;
	cin >> userInput;
	if (userInput == 1)
	{
		readFromFile();
		cin.ignore();
		cin.get();
	}
	if (userInput == 2)
	{
		cout << "Enter player 1 name :";
		cin >> p1;
		cout << "Enter player 2 name:";
		cin >> p2;

		char mark;
		do
		{
			board();
			player = (player % 2) ? 1 : 2;

			cout << "Player " << player << ", enter a number:  ";
			cin >> choice;

			mark = (player == 1) ? 'X' : 'O';

			if (choice == 1 && square[1] == '1')

				square[1] = mark;
			else if (choice == 2 && square[2] == '2')

				square[2] = mark;
			else if (choice == 3 && square[3] == '3')

				square[3] = mark;
			else if (choice == 4 && square[4] == '4')

				square[4] = mark;
			else if (choice == 5 && square[5] == '5')

				square[5] = mark;
			else if (choice == 6 && square[6] == '6')

				square[6] = mark;
			else if (choice == 7 && square[7] == '7')

				square[7] = mark;
			else if (choice == 8 && square[8] == '8')

				square[8] = mark;
			else if (choice == 9 && square[9] == '9')

				square[9] = mark;
			else
			{
				cout << "Invalid move ";

				player--;
				cin.ignore();
				cin.get();
			}
			i = checkwin();

			player++;
		} while (i == -1);
		board();
		if (i == 1)
		{
			score++;
			writeToFile(-player, score);
			cout << "==>\aPlayer " << -player << " win ";
			cin.ignore();
			cin.get();
			return 0;
		}

		else
		{
			cout << "==>\aGame draw";

			cin.ignore();
			cin.get();
			return 0;
		}


	}
}

int checkwin()
{
	if (square[1] == square[2] && square[2] == square[3])
	{
		return 1;
	}


	else if (square[4] == square[5] && square[5] == square[6])
	{
		return 1;
	}


	else if (square[7] == square[8] && square[8] == square[9])
	{
		return 1;
	}

	else if (square[1] == square[4] && square[4] == square[7])

		return 1;
	else if (square[2] == square[5] && square[5] == square[8])
	{
		return 1;
	}

	else if (square[3] == square[6] && square[6] == square[9])
	{
		return 1;
	}

	else if (square[1] == square[5] && square[5] == square[9])
	{
		return 1;
	}

	else if (square[3] == square[5] && square[5] == square[7])
	{
		return 1;
	}


	else if (square[1] != '1' && square[2] != '2' && square[3] != '3'
		&& square[4] != '4' && square[5] != '5' && square[6] != '6'
		&& square[7] != '7' && square[8] != '8' && square[9] != '9')
	{
		return 0;
	}


	else
		return -1;
}





void board()
{
	system("cls");
	cout << setw(90) << "\n\n\t\t\t\tTic Tac Toe\n\n";

	cout << setw(53) << "Player 1 (X)  -  Player 2 (O)" << endl << endl;
	cout << endl;

	cout << setw(45) << "     |     |     " << endl;
	cout << setw(30) << "  " << square[1] << "  |  " << square[2] << "  |  " << square[3] << endl;

	cout << setw(45) << "_____|_____|_____" << endl;
	cout << setw(45) << "     |     |     " << endl;

	cout << setw(30) << "  " << square[4] << "  |  " << square[5] << "  |  " << square[6] << endl;

	cout << setw(45) << "_____|_____|_____" << endl;
	cout << setw(45) << "     |     |     " << endl;

	cout << setw(30) << "  " << square[7] << "  |  " << square[8] << "  |  " << square[9] << endl;

	cout << setw(45) << "     |     |     " << endl << endl;
}

void writeToFile(int player, int score)
{


	if (player == 1)
	{
		ofstream scoreFile;
		scoreFile.open("score.txt",std::ios_base::app);
		scoreFile << p1 << " " << "score:" << " " << score << endl;;
	}
	else if (player == 2)
	{
		ofstream scoreFile;
		scoreFile.open("score.txt", std::ios_base::app);
		scoreFile << p2 << " " << "score:" << " " << score << endl;
	}


}
void readFromFile()
{
	string line;
	ifstream readFile("score.txt");
	if (readFile.is_open())
	{
		cout << "The Winners List For Tic-Tac-Toe" << endl;
		while (getline(readFile, line))
		{
			
			cout << line << '\n';
		}
		readFile.close();
	}
	else
	{
		cout << "unable to open file";
	}
}
	

	
	