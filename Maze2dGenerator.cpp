
#include "MyMaze2dGenerator.h"
#include "Maze2dGenerator.h"

using std::cout;
using std::uniform_int_distribution;

void Maze2dGenerator::createGrid()
{
    int size = SIZE;
    vector<Position> pos(size);
    // initiate grid
    for (uint8_t x = 0; x < SIZE; x++)
    {
        grid.push_back(pos);
    }

    for (uint8_t i = 0; i < SIZE; i++)
    {
        //set to walls
        grid[0][i].atr = Wall;
        grid[SIZE - 1][i].atr = Wall;
        grid[i][0].atr = Wall;
        grid[i][SIZE - 1].atr = Wall;
        //set to visited for min_steps
        grid[0][i].gen = Visited;
        grid[SIZE - 1][i].gen = Visited;
        grid[i][0].gen = Visited;
        grid[i][SIZE - 1].gen = Visited;
    }

    for (uint8_t x = 0; x < SIZE; x++)
    {
        for (uint8_t y = 0; y < SIZE; y++)
        {
            grid[x][y].x = x;
            grid[x][y].y = y;
        }
    }
};

/* get_directions
This function may look a little confusing. Here's the basics:
 - If isGen is true, we do a DFS check (check the next two blocks) to see if the
   blocks in question have been assigned an attribute yet.
 -lse, we do a basic check (only the next block) to see if the
   block is open or the exit.

Regardless of isGen's state, if the evaluation is true, we add the char
representing a direction to the string that we're returning. d is down, l is
left, and yeah you get the point. This string gets returned and is dealt with
accordingly.
*/
std::string Maze2dGenerator::get_directions(const uint8_t &x, const uint8_t &y, bool isGen) const
{
    std::string dir;
    dir.clear(); //ensure the string is empty before starting

    //check if we can check right
    if (x < SIZE - 1)
    { //if x is at least 1 less than SIZE, check right
        if (isGen)
        { //if the function was called from gen_main
            if (grid[x + 1][y].atr == Unassigned && grid[x + 2][y].atr == Unassigned)
                dir += "r";
        }
        else
        { //other purposes
            if (grid[x + 1][y].atr == Open || grid[x + 1][y].atr == Exit)
                dir += "r";
        }
    }
    //check if we can check up
    if (y < SIZE - 1)
    { //if y is at least 1 less than the SIZE, check up
        if (isGen)
        { //if the function was called from gen_main
            if (grid[x][y + 1].atr == Unassigned && grid[x][y + 2].atr == Unassigned)
                dir += "u";
        }
        else
        { //other purposes
            if (grid[x][y + 1].atr == Open || grid[x][y + 1].atr == Exit)
                dir += "u";
        }
    }
    //check if we can check left
    if (x > 0)
    { //if x is at least 1, check left
        if (isGen)
        { //if the function was called from gen_main
            if (grid[x - 1][y].atr == Unassigned && grid[x - 2][y].atr == Unassigned)
                dir += "l";
        }
        else
        { //other purposes
            if (grid[x - 1][y].atr == Open || grid[x - 1][y].atr == Exit)
                dir += "l";
        }
    }
    //check if we can check up
    if (y > 0)
    { //if y is at least 1, check up
        if (isGen)
        { //if the function was called from gen_main
            if (grid[x][y - 1].atr == Unassigned && grid[x][y - 2].atr == Unassigned)
                dir += "d";
        }
        else
        { //other purposes
            if (grid[x][y - 1].atr == Open || grid[x][y - 1].atr == Exit)
                dir += "d";
        }
    }

    return dir; //return string
}

char Maze2dGenerator::gen_next(const std::string &dir)
{
    if (dir.length() <= 0)
        return ' ';

    uniform_int_distribution<uint8_t> letter(0, dir.length() - 1);

    return dir[letter(randmaze)];
}

void Maze2dGenerator::gen_walls()
{
    for (uint8_t x = 0; x < SIZE; x++)
    {
        for (uint8_t y = 0; y < SIZE; y++)
        {
            if (grid[x][y].atr == Unassigned)
                grid[x][y].atr = Wall;
        }
    }
}

void Maze2dGenerator::gen_start()
{
    uint8_t swtch;
    /* Walls:
        0 = left
        1 = up
        2 = right
        3 = down */
    uniform_int_distribution<uint8_t> wall(0, 3);

    swtch = wall(randmaze); //we store the value bc we'll use it later

    gen_switch_case(swtch, true); //set the entrance
    gen_exit(swtch);
}

void Maze2dGenerator::gen_exit(const uint8_t &ent)
{
    uint8_t swtch;
    uniform_int_distribution<uint8_t> wall(0, 3);

    do
    {
        swtch = wall(randmaze);
    } while (swtch == ent); //this ensures the start and end will be on diff sides

    gen_switch_case(swtch, false); //set the exit
}

void Maze2dGenerator::gen_switch_case(const uint8_t &swtch, const bool &isEnter)
{
    uint8_t x, y;
    uniform_int_distribution<uint8_t> Position(0, SIZE - 1);

    /* This switch statement looks to see what side of the wall was determined
    and looks to ensure the block next to the entrance/exit is open. Until it is
    open, it keeps trying a new random value until it is in a valid spot. */

    switch (swtch)
    {
    case 0: //left
        x = 0;
        y = 0;
        while (grid[x + 1][y].atr != Open)
            y = Position(randmaze);
        break;
    case 1: //up
        x = 0;
        y = SIZE - 1;
        while (grid[x][y - 1].atr != Open)
            x = Position(randmaze);
        break;
    case 2: //right
        x = SIZE - 1;
        y = 0;
        while (grid[x - 1][y].atr != Open)
            y = Position(randmaze);
        break;
    case 3: //down
        x = 0;
        y = 0;
        while (grid[x][y + 1].atr != Open)
            x = Position(randmaze);
        break;
    default:
        cout << "gen_switch_case failed.\n";
        exit(1); //stop
        break;
    }

    if (isEnter)
    { //this is called in the case of gen_start
        grid[x][y].atr = Enter;
        cout << "Enter is: x: " << (int)grid[x][y].x << " y: " << (int)grid[x][y].y << '\n';
        Start = grid[x][y];
    }
    else
    { //is exit

        grid[x][y].atr = Exit;
        cout << "Exit is: x: " << (int)grid[x][y].x << " y: " << (int)grid[x][y].y << '\n';
        grid[x][y].gen = Unvisited; //for min_steps
        End = grid[x][y];
    }
}

void Maze2dGenerator::printTest(vector<vector<Position>> gridTest)
{

    for (uint8_t h = 0; h < SIZE; h++)
    {                             //y >= 0 does not work with uint8_t, so change approach
        uint8_t y = SIZE - 1 - h; //y axis, inverted so (0,0) is bot left,
        for (uint8_t x = 0; x < SIZE; x++)
        {
            switch (gridTest[x][y].atr)
            {
            case Enter:
                if (gridTest[x][y].has_player) //check for a player
                    cout << "P";               //Player
                else
                    cout << "B"; //Start/Beginning
                break;
            case Exit:
                if (gridTest[x][y].has_player) //check for a player
                    cout << "P";               //Player
                else
                    cout << "E"; //Exit/End
                break;
            case Open:
                if (gridTest[x][y].has_player) //check for a player
                    cout << "P";               //Player
                else
                    cout << "0"; //Open
                break;
            case Wall:
                cout << "1"; //Wall
                break;
            case Unassigned:
                cout << "n"; //Invalid (Unassigned)
                break;
            default:
                std::cerr << "ERROR\n"; //In case of error
                break;
            }            //end switch
            cout << " "; //Space to make the formatting look nicer
        }                //end x
        cout << '\n';    //newline for each new line
    }                    //end y
}
