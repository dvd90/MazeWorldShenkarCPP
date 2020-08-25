#include "Interface.h"
#include "Maze2dGenerator.h"

string Interface::getName()
{
    cout << " Welcome to Maze planet... " << endl
         << "Please choose a name for your maze, for exit, enter '1'" << endl;
    string name;
    cin >> name;
    if (name == "1")
        exit(1);

    return name;
}

vector<int> Interface::genMenu()
{
    int maze_size = 0;
    int creation_method;

    while (maze_size % 2 == 0)
    {
        cout << endl
             << "Please choose an ODD maze size" << endl;
        cin >> maze_size;
    };

    cout << "Choose Maze creation method:" << endl
         << "#1 Simple method" << endl
         << "#2 DFS method" << endl
         << "#3 Astar Solving" << endl
         << "#4 BFS Solving" << endl
         << "#5 create DFS maze and compress" << endl
         << "#6 Print all folder files" << endl;
    cin >> creation_method;

    vector<int> choices;
    choices.push_back(maze_size);
    choices.push_back(creation_method);
    return choices;
};

void Interface::print(Maze2d to_print)
{

    for (uint8_t h = 0; h < to_print._Size; h++)
    {                                       //y >= 0 does not work with uint8_t, so change approach
        uint8_t y = to_print._Size - 1 - h; //y axis, inverted so (0,0) is bot left,
        for (uint8_t x = 0; x < to_print._Size; x++)
        { //x axis
            // add _x , _y
            switch (to_print._grid[x][y].atr)
            {
            case Enter:
                if (to_print._grid[x][y].has_player) //check for a player
                    cout << "P";                     //Player
                else
                    cout << "B"; //Start/Beginning
                break;
            case Exit:
                if (to_print._grid[x][y].has_player) //check for a player
                    cout << "P";                     //Player
                else
                    cout << "E"; //Exit/End
                break;
            case Open:
                if (to_print._grid[x][y].has_player) //check for a player
                    cout << "P";                     //Player
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
            } //end switch

            cout << " "; //Space to make the formatting look nicer
        }                //end x
        cout << '\n';    //newline for each new line
    }                    //end y
}

void Interface::afterSave()
{
    cout << endl
         << "file is compressed" << endl
         << "now you can load from file" << endl;
}

void Interface::showFiles()
{
    std::__fs::filesystem::path path = std::__fs::filesystem::current_path();
    for (const auto &entry : std::__fs::filesystem ::directory_iterator(path.parent_path()))
        std::cout << entry.path() << std::endl;
}

void Interface::printName(Maze2d to_print)
{
    cout << to_print._name << endl;
}

void Interface::mazeSize(Maze2d to_print)
{
    cout << "the maze size is: " << to_print._Size << endl;
}

void Interface::fileSize(vector<int> compressed)
{
    cout << "The size of the maze from file is: " << sizeof(compressed) << endl;
}
