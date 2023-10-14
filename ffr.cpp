#include <iostream>
#include <string>

using namespace std;

const int ROWS = 6; // size of maze
const int COLS = 6;

class Maze {
private:
    int** maze;          // maze (pointer to pointer)
    bool** visited;      // check if maze was visited (pointer to pointer)

public:
    Maze() {
        maze = new int*[ROWS];           // allocate memory for maze rows
        visited = new bool*[ROWS];       // allocate memory for visited rows

        for (int i = 0; i < ROWS; i++) {
            maze[i] = new int[COLS];     // allocate memory for maze columns
            visited[i] = new bool[COLS]; // allocate memory for visited columns

            for (int j = 0; j < COLS; j++) {
                maze[i][j] = 0;           // initialize maze cell to 0
                visited[i][j] = false;    // initialize visited cell to false
            }
        }

        // Set default maze
        int tempMaze[ROWS][COLS] = {
            { 0, 1, 1, 1, 1, 1 },
            { 0, 0, 1, 0, 0, 0 },
            { 1, 0, 0, 0, 1, 0 },
            { 1, 1, 1, 0, 1, 0 },
            { 1, 0, 0, 0, 1, 0 },
            { 1, 1, 1, 1, 1, 3 }
        };

        for (int i = 0; i < ROWS; i++) {
            for (int j = 0; j < COLS; j++) {
                maze[i][j] = tempMaze[i][j];
            }
        }
    }

    ~Maze() {
        // Deallocate memory for maze rows
        for (int i = 0; i < ROWS; i++) {
            delete[] maze[i];
        }
        delete[] maze;

        // Deallocate memory for visited rows
        for (int i = 0; i < ROWS; i++) {
            delete[] visited[i];
        }
        delete[] visited;
    }

        void printMaze(){ //prints the maze
            cout << "********************************" << endl;
            cout << "        THE MAZE GAME           " << endl;
            cout << "********************************" << endl;
            for(int i=0;i<ROWS;i++){
                
                for(int j=0;j<COLS;j++){
                    if(maze[i][j] == 0){
                        cout << "-";    //represents openings
                    }
                    else if(maze[i][j] == 1){
                        cout << "x";    //represents walls
                    }
                }
                cout << endl;                
            }   
        }
        void changeMaze(){      //allows user to enter they're own maze
            string condition;
            cout << "Would you like to make your own Maze?(yes/no) ";
            cin >> condition;
            if(condition == "yes"){ //istructions on how to enter the maze
                cout << "Please enter a 6x6 maze, separate each number with space. " << endl;
                cout << "Use 0 as opening and 1 as walls." << endl;
                cout << "The first number should be 0 and last should be 3 for exit." << endl;
                for(int i=0;i<ROWS;i++){
                    for(int j=0;j<COLS;j++){
                        cin >> maze[i][j];
                    }
                }
            }
            else{
                cout << "We will use default maze" << endl;
            }
        }
        bool mazeAlgo(int x,int y){
            cout << "(" << x << "," << y << ")" << endl; 
            if(x < 0 || x >= ROWS || y < 0 || y >= COLS){ //check for out of bounds
                return false;
            }

            if(maze[x][y] == 3){ //if we reach the last cell than return true
                
                return true;
            }

            if(maze[x][y] == 0 && !visited[x][y]){
                visited[x][y] = true; //marks it as visited               
                if(mazeAlgo(x+1,y)){return true;} //down 
                if(mazeAlgo(x,y+1)){return true;} //right
                if(mazeAlgo(x,y-1)){return true;} //left
                if(mazeAlgo(x-1,y)){return true;} //up
                visited[x][y] = false;
            }
            
            return false; //if no path return false
            
        }
            
                  
            
        
                   
};



int main(){
    Maze maze;
    maze.changeMaze();     
    maze.printMaze();
     //starting postion for maze (0,0)
    if(maze.mazeAlgo(0,0) == true){
        cout << "found path in this maze" << endl;
    }else{
        cout << "No path" << endl;
    }
    


    return 0;
}
