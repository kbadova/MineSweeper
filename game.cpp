#include <iostream>
#include <cstdlib>
using namespace std;

const int max_X_coordinate = 100;
const int max_Y_coordinate = 100;

const int maxNumberOfHiddenMines = 30;


//Дали клетката е свободна. Тук вече допускаме, че x_coordinate и y_coordinate са валидни координати.
bool isCellFree(char playerBoard[max_X_coordinate][max_Y_coordinate], int x_coordinate, int y_coordinate)
{
    return playerBoard[x_coordinate][y_coordinate] == '*';
}

bool isCellOpened(char playerBoard[max_X_coordinate][max_Y_coordinate], int x_coordinate, int y_coordinate) {
    return playerBoard[x_coordinate][y_coordinate] != '*';
}

void print(char playerBoard[max_X_coordinate][max_Y_coordinate], int matrix_dimension)
{
    for (int i = 0; i < matrix_dimension; i++)
    {
        for (int j = 0; j < matrix_dimension; j++)
        {
            cout << " " << playerBoard[i][j];
        }
        cout << endl;
    }
    cout << endl;
}


void addMinesToBoard(char playerBoard[max_X_coordinate][max_Y_coordinate], int enteredMineCount, int matrix_dimension)
{
    for (int j = 0; j < enteredMineCount; j++)
    {

        int randomRow = (rand() % matrix_dimension) + 1;
        int randomColumn = (rand() % matrix_dimension) + 1;

        bool isCellFreeResult = isCellFree(playerBoard, randomRow, randomColumn);

        while (isCellFreeResult == false) {
            randomRow = (rand() % matrix_dimension) + 1;
            randomColumn = (rand() % matrix_dimension) + 1;

            isCellFreeResult = isCellFree(playerBoard, randomRow, randomColumn);
        }

        playerBoard[randomRow][randomColumn] = '@';
    }
}

bool hasMinesNeighbour(char helpingBoard[max_X_coordinate][max_Y_coordinate], int x_coordinate, int  y_coordinate, int matrix_dimension)
{
    if (y_coordinate + 1 >= 0 && y_coordinate + 1 < matrix_dimension)
    {
        if (helpingBoard[x_coordinate][y_coordinate + 1] != '*')
        {
            return true;

        }
    }
    if (y_coordinate + 1 >= 0 && y_coordinate + 1 < matrix_dimension && x_coordinate + 1 >= 0 && x_coordinate + 1 < matrix_dimension)
    {
        if (helpingBoard[x_coordinate + 1][y_coordinate + 1] != '*')
        {
            return true;

        }
    }
    if (x_coordinate + 1 >= 0 && x_coordinate + 1 < matrix_dimension)
    {
        if (helpingBoard[x_coordinate + 1][y_coordinate] != '*')
        {
            return true;
        }
    }
    if (x_coordinate + 1 >= 0 && x_coordinate + 1 < matrix_dimension && y_coordinate - 1 >= 0 && y_coordinate - 1 < matrix_dimension)
    {
        if (helpingBoard[x_coordinate + 1][y_coordinate - 1] != '*')
        {
            return true;

        }
    }
    if (y_coordinate - 1 >= 0 && y_coordinate - 1 < matrix_dimension)
    {
        if (helpingBoard[x_coordinate][y_coordinate - 1] != '*')
        {
            return true;

        }
    }
    if (x_coordinate - 1 >= 0 && x_coordinate - 1 < matrix_dimension && y_coordinate - 1 >= 0 && y_coordinate - 1 < matrix_dimension)
    {
        if (helpingBoard[x_coordinate - 1][y_coordinate - 1] != '*')
        {
            return true;
        }
    }
    if (x_coordinate - 1 >= 0 && x_coordinate - 1 < matrix_dimension)
    {
        if (helpingBoard[x_coordinate - 1][y_coordinate] != '*')
        {
            return true;

        }
    }
    if (x_coordinate - 1 >= 0 && x_coordinate - 1 < matrix_dimension && y_coordinate + 1 >= 0 && y_coordinate + 1 < matrix_dimension)
    {
        if (helpingBoard[x_coordinate - 1][y_coordinate + 1] != '*')
        {
            return true;
        }
    }
    return false;
}

int countTheNumberOfMines(char playerBoard[max_X_coordinate][max_Y_coordinate], int x_coordinate, int y_coordinate, int matrix_dimension)
{
    int countOfMines = 0;

    if (y_coordinate + 1 >= 0 && y_coordinate + 1 < matrix_dimension) {
        if (playerBoard[x_coordinate][y_coordinate + 1] == '@')
        {
            countOfMines += 1;

        }
    }
    if (y_coordinate + 1 >= 0 && y_coordinate + 1 < matrix_dimension && x_coordinate + 1 >= 0 && x_coordinate + 1 < matrix_dimension) {
        if (playerBoard[x_coordinate + 1][y_coordinate + 1] == '@')
        {
            countOfMines += 1;
        }
    }
    if (x_coordinate + 1 >= 0 && x_coordinate + 1 < matrix_dimension)
    {
        if (playerBoard[x_coordinate + 1][y_coordinate] == '@')
        {
            countOfMines += 1;
        }
    }
    if (x_coordinate + 1 >= 0 && x_coordinate + 1 < matrix_dimension && y_coordinate - 1 >= 0 && y_coordinate - 1 < matrix_dimension)
    {
        if (playerBoard[x_coordinate + 1][y_coordinate - 1] == '@')
        {
            countOfMines += 1;

        }
    }
    if (y_coordinate - 1 >= 0 && y_coordinate - 1 < matrix_dimension)
    {
        if (playerBoard[x_coordinate][y_coordinate - 1] == '@')
        {
            countOfMines += 1;

        }
    }
    if (x_coordinate - 1 >= 0 && x_coordinate - 1 < matrix_dimension && y_coordinate - 1 >= 0 && y_coordinate - 1 < matrix_dimension)
    {
        if (playerBoard[x_coordinate - 1][y_coordinate - 1] == '@')
        {
            countOfMines += 1;
        }
    }
    if (x_coordinate - 1 >= 0 && x_coordinate - 1 < matrix_dimension)
    {
        if (playerBoard[x_coordinate - 1][y_coordinate] == '@')
        {
            countOfMines += 1;

        }
    }
    if (x_coordinate - 1 >= 0 && x_coordinate - 1 < matrix_dimension && y_coordinate + 1 >= 0 && y_coordinate + 1 < matrix_dimension)
    {
        if (playerBoard[x_coordinate - 1][y_coordinate + 1] == '@')
        {
            countOfMines += 1;
        }
    }

    return countOfMines;
}


void addNumberToBoard(char board[max_X_coordinate][max_Y_coordinate], char helpingBoard[max_X_coordinate][max_Y_coordinate], int x_coordinate, int y_coordinate, int matrix_dimension)
{
    int resultCountTheNumberOfMines = countTheNumberOfMines(helpingBoard, x_coordinate, y_coordinate, matrix_dimension);
    
    // TODO; DROP the cin
    cout << "resultCountTheNumberOfMines " << resultCountTheNumberOfMines;

    board[x_coordinate][y_coordinate] = (char)resultCountTheNumberOfMines;
}

void makeSquareOpened(char board[max_X_coordinate][max_Y_coordinate], int x_coordinate, int y_coordinate)
{
    board[x_coordinate][y_coordinate] = 'O';
}

bool isNeighbour(char helpingBoard[max_X_coordinate][max_Y_coordinate], int initialElementX, int initialElementY, int possibleNeighbourX, int possibleNeighbourY)
{
    if (initialElementX - 1 == possibleNeighbourX && initialElementY == possibleNeighbourY) {
        return true;
    }

    if (initialElementX - 1 == possibleNeighbourX && initialElementY + 1 == possibleNeighbourY)
    {
        return true;
    }

    if (initialElementX == possibleNeighbourX && initialElementY + 1 == possibleNeighbourY)
    {
        return true;
    }

    if (initialElementX + 1 == possibleNeighbourX && initialElementY + 1 == possibleNeighbourY){
        return true;
    }

    if (initialElementX + 1 == possibleNeighbourX && initialElementY == possibleNeighbourY)
    {
        return true;
    }

    if (initialElementX + 1 == possibleNeighbourX && initialElementY - 1 == possibleNeighbourY) {
        return true;
    }

    if (initialElementX - 1 == possibleNeighbourX && initialElementY + 1 == possibleNeighbourY)
    {
        return true;
    }

    if (initialElementX - 1 == possibleNeighbourX && initialElementY - 1 == possibleNeighbourY) {
        return true;
    }

    return false;
}

bool openSquare(char playerBoard[max_X_coordinate][max_Y_coordinate], char helpingBoard[max_X_coordinate][max_Y_coordinate], int x_coordinate, int y_coordinate, int matrix_dimension)
{
    if (helpingBoard[x_coordinate][y_coordinate] == '@')
    {
        cout << "End of game. This is a mine!" << endl;
        return false;
    }
 
    bool resultHasMinesNeighbour = hasMinesNeighbour(helpingBoard, x_coordinate, y_coordinate, matrix_dimension);

    if (resultHasMinesNeighbour == true)
    {
        addNumberToBoard(playerBoard, helpingBoard, x_coordinate, y_coordinate, matrix_dimension);

        addNumberToBoard(helpingBoard, helpingBoard, x_coordinate, y_coordinate, matrix_dimension);

        return true;
    }

    else
    {
        makeSquareOpened(playerBoard, x_coordinate, y_coordinate);
        makeSquareOpened(helpingBoard, x_coordinate, y_coordinate);

        cout << "Player board visualization:" << endl;
        print(playerBoard, matrix_dimension);

        cout << "Helping board visualization:"  << endl;
        print(helpingBoard, matrix_dimension);

        // Call openSquare for all possible neighbours that are not mines
        for (int i = 0; i < matrix_dimension; i++)
            {
                for (int j = 0; j < matrix_dimension; j++)
                {
                    if (helpingBoard[i][j] == '*' && isNeighbour(helpingBoard, x_coordinate, y_coordinate, i, j)) {
                        openSquare(playerBoard, helpingBoard, i, j, matrix_dimension);
                    }

                }
            } 
    }
}


//Дали не сме извън рамките на масива
bool areValidCoordinates(int x_coordinate, int y_coordinate, int matrix_dimension)
{
    return x_coordinate >= 0 && x_coordinate <= matrix_dimension && y_coordinate >= 0 && y_coordinate <= matrix_dimension;  //3 ili 1 ili 0
}

void markSquresAsMines(char playerBoard[max_X_coordinate][max_Y_coordinate], int x_coordinate, int y_coordinate)
{
    playerBoard[x_coordinate][y_coordinate] = '!';
}
void unmarkSquresAsMines(char playerBoard[max_X_coordinate][max_Y_coordinate], int x_coordinate, int y_coordinate)
{
    playerBoard[x_coordinate][y_coordinate] = '*';
}


bool validateMatrixDimension(int matrix_dimension)
{
    if (matrix_dimension >= 3 && matrix_dimension <= 10)
        return true;
    else
    {
        return false;
    }
}

bool validateMineCount(int enteredMineCount, int matrix_dimension)
{
    if (enteredMineCount >= 1 && enteredMineCount <= (3 * matrix_dimension))
    {
        return true;
    }
    else
    {
        return false;
    }
}


bool validateCommand(string command)
{
    if (command != "open" && command != "mark" && command != "unmark" && command != "print")
    {
        return false;
    }
    else
    {
        return true;
    }
}

void createPlayerBoard(int matrix_dimension, char playerBoard[max_X_coordinate][max_Y_coordinate])
{
    for (int i = 0; i < matrix_dimension; i++)
    {
        for (int j = 0; j < matrix_dimension; j++)
        {
            playerBoard[i][j] = '*';

        }
    }
}
bool validateCellIsMark(char playerBoard[max_X_coordinate][max_Y_coordinate], int x_coordinate, int y_coordinate)
{
    return playerBoard[x_coordinate][y_coordinate] == '!';
}

int main()
{
    char playerBoard[max_X_coordinate][max_Y_coordinate] = {};

    char helpingBoard[max_X_coordinate][max_Y_coordinate] = {};

    int matrix_dimension;
    int enteredMineCount;
    string command;
    int minesCount;
    bool playing = true;
    int x_coordinate, y_coordinate;

    cout << "Hey there, enter a valid dimension!";
    cin >> matrix_dimension;


    bool result = validateMatrixDimension(matrix_dimension);
    while (result == false)
    {
        cout << "Enter again!";
        cin >> matrix_dimension;
        result = validateMatrixDimension(matrix_dimension);

    }

    cout << "Hey there, enter a valid mine count!";
    cin >> enteredMineCount;
    bool resultValidateMineCount = validateMineCount(enteredMineCount, matrix_dimension);
    while (resultValidateMineCount == false)
    {
        cout << "Enter again";
        cin >> enteredMineCount;
        resultValidateMineCount = validateMineCount(enteredMineCount, matrix_dimension);
    }

    createPlayerBoard(matrix_dimension, playerBoard);
    
    createPlayerBoard(matrix_dimension, helpingBoard);

    addMinesToBoard(helpingBoard, enteredMineCount, matrix_dimension);

    cout << "Player board visualization:" << endl;
    print(playerBoard, matrix_dimension);

    cout << "Helping board visualization:"  << endl;
    print(helpingBoard, matrix_dimension);

    while (playing)
    {
        cout << "Hey there, enter a valid command!";
        cin >> command;

        bool resultValidateCommand = validateCommand(command);
        while (resultValidateCommand == false)
        {
            cout << "Enter a valid command again! ";
            cin >> command;
            resultValidateCommand = validateCommand(command);
        }
        cout << "Enter valid coordinates: ";

        cin >> x_coordinate >> y_coordinate;
        bool resultAreValidCoordinates = areValidCoordinates(x_coordinate, y_coordinate, matrix_dimension);
        while (resultAreValidCoordinates == false)
        {
            cout << "Enter again valid coordinates";
            cin >> x_coordinate >> y_coordinate;
            resultAreValidCoordinates = areValidCoordinates(x_coordinate, y_coordinate, matrix_dimension);
        }

        if (command == "open")
        {
            bool resultIsCellOpened = isCellOpened(playerBoard, x_coordinate, y_coordinate);
            while (resultIsCellOpened == true)
            {
                cout << "Cell is not free! Enter another coordinates!";
                cin >> x_coordinate >> y_coordinate;
                resultIsCellOpened = isCellOpened(playerBoard, x_coordinate, y_coordinate);
            }

            // TODO: Check whether the cell is marked 

            result = openSquare(playerBoard, helpingBoard, x_coordinate, y_coordinate, matrix_dimension);

            if (result == false)
            {
                playing = false;
                return 0;
            }
            
            cout << "Player board visualization:" << endl;
            print(playerBoard, matrix_dimension);

            cout << "Helping board visualization:"  << endl;
            print(helpingBoard, matrix_dimension);
        }

        else if (command == "mark")
        {
            bool resultIsCellFreeForMark = isCellFree(playerBoard, x_coordinate, y_coordinate);
            while (resultIsCellFreeForMark == false)
            {
                cout << "Cell is not free! Enter another coordinates!";
                cin >> x_coordinate >> y_coordinate;
                resultIsCellFreeForMark = isCellFree(playerBoard, x_coordinate, y_coordinate);
            }
            markSquresAsMines(playerBoard, x_coordinate, y_coordinate);

            print(playerBoard, matrix_dimension);

        }
        else if (command == "unmark")
        {
            bool resultValidateCelIsMark = validateCellIsMark(playerBoard, x_coordinate, y_coordinate);
            while (resultValidateCelIsMark == false)
            {
                cout << "Cell is not marked! Enter another cooedinates!";
                cin >> x_coordinate >> y_coordinate;
                resultValidateCelIsMark = validateCellIsMark(playerBoard, x_coordinate, y_coordinate);
            }

            unmarkSquresAsMines(playerBoard, x_coordinate, y_coordinate);
            print(playerBoard, matrix_dimension);
        }

        if (command == "print") {
            print(playerBoard, matrix_dimension);
        }
    }
}
