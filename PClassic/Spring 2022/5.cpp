// curteosy to frank

#include <iostream>
#include <vector>
#include <sstream>
using namespace std;

void printBoardDebug(vector<vector<int>> board){
	cout << "Board: " << endl;
	for(int trow = 0; trow < 4; trow++){
		for(int tcol = 0; tcol < 4; tcol++){
			cout << board[trow][tcol] << " ";
		}
		cout << endl;
	}
	cout << endl;
}

vector<vector<int>> shiftingSands(vector<vector<int>> board, vector<string> moves)
{
	for(auto it = moves.begin(); it != moves.end(); it++){
		string move = *it;
		//cout << "move: " << move << endl;
		if(move == "N"){
			for(int col = 0; col < 4; col++){
				int zerocount = 0;
				for(int i = 3; i >= 0; i--){
					if(board[i][col] == 0){
						zerocount++;
					}
				}
				int nonzeroupto = 4 - zerocount;
				while(true){
					//cout << "Looping: zerocheck" << endl;
					bool modchange = false;
					for(int i = 0; i < nonzeroupto; i++){
						if(board[i][col] == 0){
							for(int temprow = i; temprow < 3; temprow++){
								board[temprow][col] = board[temprow+1][col];
							}
							board[3][col] = 0;
							modchange = true;
							break;
						}
					}
					if(!modchange){
						break;
					}
				}
				//printBoardDebug(board);
				for(int row = 0; row < (nonzeroupto - 1); row++){
					if(board[row][col] == board[row+1][col]){
						board[row][col] *= 2;
						for(int temprow = row + 1; temprow < (nonzeroupto - 1); temprow++){
							board[temprow][col] = board[temprow+1][col];
						}
						board[nonzeroupto - 1][col] = 0;
						nonzeroupto--;
						zerocount++;
					}
					//printBoardDebug(board);
				}
				//printBoardDebug(board);
			}
		} else if (move == "S") {
			for(int col = 0; col < 4; col++){
				int zerocount = 0;
				for(int i = 3; i >= 0; i--){
					if(board[i][col] == 0){
						zerocount++;
					}
				}
				int nonzeroupto = zerocount;
				while(true){
					//cout << "Looping: zerocheck" << endl;
					bool modchange = false;
					for(int i = 3; i >= nonzeroupto; i--){
						if(board[i][col] == 0){
							for(int temprow = i; temprow > 0; temprow--){
								board[temprow][col] = board[temprow-1][col];
							}
							board[0][col] = 0;
							modchange = true;
							break;
						}
					}
					if(!modchange){
						break;
					}
				}
				//printBoardDebug(board);
				for(int row = 3; row > nonzeroupto; row--){
					//cout << "Testing for row: " << row << ", col: " << col << endl;
					if(board[row][col] == board[row-1][col]){
						board[row][col] *= 2;
						for(int temprow = row - 1; temprow > nonzeroupto; temprow--){
							board[temprow][col] = board[temprow-1][col];
						}
						board[nonzeroupto][col] = 0;
						nonzeroupto++;
						zerocount++;
					}
					//printBoardDebug(board);
				}
				//printBoardDebug(board);
			}
		} else if (move == "W"){
			for(int newrow = 0; newrow < 4; newrow++){
				int zerocount = 0;
				for(int i = 3; i >= 0; i--){
					if(board[newrow][i] == 0){
						zerocount++;
					}
				}
				int nonzeroupto = 4 - zerocount;
				while(true){
					//cout << "Looping: zerocheck" << endl;
					bool modchange = false;
					for(int i = 0; i < nonzeroupto; i++){
						if(board[newrow][i] == 0){
							for(int tempcol = i; tempcol < 3; tempcol++){
								board[newrow][tempcol] = board[newrow][tempcol+1];
							}
							board[newrow][3] = 0;
							modchange = true;
							break;
						}
					}
					if(!modchange){
						break;
					}
				}
				//printBoardDebug(board);
				for(int newcol = 0; newcol < (nonzeroupto - 1); newcol++){
					if(board[newrow][newcol] == board[newrow][newcol+1]){
						board[newrow][newcol] *= 2;
						for(int tempcol = newcol + 1; tempcol < (nonzeroupto - 1); tempcol++){
							board[newrow][tempcol] = board[newrow][tempcol];
						}
						board[newrow][nonzeroupto - 1] = 0;
						nonzeroupto--;
						zerocount++;
					}
					//printBoardDebug(board);
				}
				//printBoardDebug(board);
			}
		} else if (move == "E") {
			for(int newrow = 0; newrow < 4; newrow++){
				int zerocount = 0;
				for(int i = 3; i >= 0; i--){
					if(board[newrow][i] == 0){
						zerocount++;
					}
				}
				int nonzeroupto = zerocount;
				while(true){
					//cout << "Looping: zerocheck" << endl;
					bool modchange = false;
					for(int i = 3; i >= nonzeroupto; i--){
						if(board[newrow][i] == 0){
							for(int tempcol = i; tempcol > 0; tempcol--){
								board[newrow][tempcol] = board[newrow][tempcol-1];
							}
							board[newrow][0] = 0;
							modchange = true;
							break;
						}
					}
					if(!modchange){
						break;
					}
				}
				//printBoardDebug(board);
				for(int newcol = 3; newcol > nonzeroupto; newcol--){
					//cout << "Testing for row: " << newrow << ", col: " << newcol << endl;
					if(board[newrow][newcol] == board[newrow][newcol-1]){
						board[newrow][newcol] *= 2;
						for(int tempcol = newcol - 1; tempcol > nonzeroupto; tempcol--){
							board[newrow][tempcol] = board[newrow][tempcol-1];
						}
						board[newrow][nonzeroupto] = 0;
						nonzeroupto++;
						zerocount++;
					}
					//printBoardDebug(board);
				}
				//printBoardDebug(board);
			}
		}
	}
	return board;
}

// Do not modify below this line
vector<string> tokenize(string s)
{
    vector<string> tokens;
    stringstream ss(s);
    string word;

    while (ss >> word)
        tokens.push_back(word);

    return tokens;
}

int main()
{
    string s;
    int t;

    getline(cin, s);
    t = stoi(s);

    for (int i = 0; i < t; i++)
    {
        vector<vector<int>> board;

        for (int j = 0; j < 4; j++)
        {
            vector<int> vector_row;
            getline(cin, s);
            vector<string> vector_row_str = tokenize(s);
            for (int k = 0; k < 4; k++)
                vector_row.push_back(stoi(vector_row_str[k]));

            board.push_back(vector_row);
        }

        vector<string> moves;
        getline(cin, s);
        moves = tokenize(s);
        vector<vector<int>> output = shiftingSands(board, moves);

        for (int j = 0; j < 4; j++)
        {
            for (int k = 0; k < 4; k++)
            {
                cout << output[j][k] << " ";
            }
            cout << endl;
        }
    }
}
