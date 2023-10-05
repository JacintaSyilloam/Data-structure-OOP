/* Tugas
Buatlah program yang menyimpan banyak data (datanya bebas) minimal sebanyak 10 data.
Program bisa:
• Menampilkan data
• Menambah data baru
• Menghapus data
• Mengubah data
• Mencari data */

// Struct assignment

// Jacinta Syilloam
// NRP 5027221036
// Struktur Data dan Pemrograman Berbasis Objek
// kelas A

// Simple CPP Program for a VNL tournament player database

#include <iostream>
#include <string>

using namespace std;

int n = 7; // as counter to keep track of newly registered users

struct player
{
    int id;
    string name;
    string gender;
    string country;
    string position;
    int age;
    int height;
    int weight;
    int jerseyNum;
    int point;
} players[500];

// Option 2: Register a new player
void proceed_register(string name, string gender, string country, string position, int age, int height, int weight, int jerseyNum)
{
    // struct new player
    struct player new_player; // variable for newly registered players
    new_player.id = n;
    new_player.point = 0; // initial score
    new_player.name = name;
    new_player.gender = gender;
    new_player.country = country;
    new_player.position = position;
    new_player.age = age;
    new_player.height = height;
    new_player.weight = weight;
    new_player.jerseyNum = jerseyNum;

    // store data to struct players
    players[n] = new_player;
    n++; // increment player count

    cout << "\n== Player " << name << " is successfully registered in the VNL database. =="
         << "\nPlayer ID is " << n - 1
         << "\n\nEnter another choice: ";
}

// Option 3: Add point
void proceed_addPoint(int id, int addPoint)
{
    player *player = &players[id]; // retrieve address of player, access the data
    //The pointer player now points to the memory location where the player's data is stored

    player->point += addPoint; // access members of struct and modify point
    cout << addPoint << " point(s) successfully added to player " << player->name << "."
         << "\nPlayer " << player->name << " now has " << player->point << "point(s)."
         << "\n\nEnter another choice: ";
}

// Option 4: Subtract point
void proceed_subPoint(int id, int subPoint)
{
    player *player = &players[id];

    if (player->point >= subPoint)
    {
        player->point -= subPoint;
        cout << subPoint << " point(s) successfully subtracted from player " << player->name << "."
             << "\nPlayer " << player->name << " now has " << player->point << "point(s).";
    }
    else
    {
        cout << "Error! Insufficient point(s). No points is subtracted from player " << player->name;
    }

    cout << "\n\nEnter another choice: ";
}

// Option 5: Find player information from id
void findPlayer(int id)
{
    if (id <= n)
    {
        player *player = &players[id];
        cout << "== Profile of player =="
             << "\nName\t\t: " << player->name
             << "\nGender\t\t: " << player->gender
             << "\nCountry\t\t: " << player->country
             << "\nPosition\t: " << player->position
             << "\nAge\t\t: " << player->age
             << "\nHeight (cm)\t: " << player->height
             << "\nWeight (kg)\t: " << player->weight
             << "\nJersey Number\t: " << player->jerseyNum
             << "\nPoint(s)\t: " << player->point
             << "\n\nEnter another choice: ";
    }
    else
    {
        cout << "Error! This id has not been registered to the VNL database."
             << "\n\nEnter another choice: ";
    }
}

int main()  
{
    // Players data sample
    players[1] = {1, "Miyaken", "Men", "Japan", "Opposite spiker", 24, 190, 87, 4, 101};
    players[2] = {2, "Tobio", "Men", "Japan", "Setter", 21, 189, 82, 20, 120};
    players[3] = {3, "Jac", "Women", "Poland", "Outside hitter", 19, 161, 52, 9, 50};
    players[4] = {4, "Barbie", "Women", "US", "Middle blocker", 26, 175, 65, 13, 90};
    players[5] = {5, "Eren", "Men", "German", "Libero", 20, 170, 60, 15, 10};
    players[6] = {6, "Ran", "Men", "Japan", "Outside hitter", 20, 189, 84, 15, 120};


    // Main menu
    int userChoice;
    cout << "==== Welcome to the Volleyball National League players database ====\n\nChoose an option below to Proceed." << endl;
    cout << "1. Show players statistics\n2. Register a new player\n3. Add score to player\n4. Subtract score from player\n5. Find player information from id\n6. Remove player by id\n7. About Volleyball Nationals League\n\n";
    cout << "Enter your choice: ";

    while (cin >> userChoice)
    {
        if (userChoice == 1) // Code to show all players statistics
        {
            cout << "\n ==== VNL Players Statistics ====\n\n"
                 << "ID ||\tName\t\t||\tCountry\t\t||\tPoints";

            for (int i = 1; i < n; i++)
            {
                cout << "\n"
                     << players[i].id << "\t" << players[i].name << "\t\t\t" << players[i].country << "\t\t\t" << players[i].point << endl;
            }

            cout << "\nEnter another choice: ";
        }
        else if (userChoice == 2)
        {
            // Code to register a new player
            string name, gender, country, position;
            int age, height, weight, jerseyNum;

            cout << "\n==== Register a new player ====\n\n";

            cout << "Enter player name: ";
            cin >> name;

            cout << "Enter team gender (men/women): ";
            cin >> gender;

            cout << "Enter the player's representing country: ";
            cin >> country;

            cout << "Choose volleyball position at VNL\n> Outside hitter\n> Opposite spiker\n> Middle blocker\n> Setter\n> Libero\n"
                 << "Enter player position: ";
            cin.ignore();
            getline(cin, position);

            cout << "Enter player age: ";
            cin >> age;

            cout << "Enter player height (cm): ";
            cin >> height;

            cout << "Enter player weight (kg): ";
            cin >> weight;

            cout << "Enter player jersey number: ";
            cin >> jerseyNum;

            proceed_register(name, gender, country, position, age, height, weight, jerseyNum);
        }
        else if (userChoice == 3)
        {
            // Code to add score to a player
            int id, addPoint;
            cout << "\n\n==== Add point(s) to a player ===="
                 << "\n\nEnter player id: ";
            cin >> id;
            cout << "Player name is " << players[id].name;
            cout << "\nEnter number of points to add: ";
            cin >> addPoint;

            proceed_addPoint(id, addPoint);
        }
        else if (userChoice == 4)
        {
            // Code to subtract score from a player
            int id, subPoint;
            cout << "\n\n==== Subtract point(s) from a player ===="
                 << "\n\nEnter player id: ";
            cin >> id;
            cout << "Player name is " << players[id].name;
            cout << "\nEnter number of points to subtract: ";
            cin >> subPoint;

            proceed_subPoint(id, subPoint);
        }
        else if (userChoice == 5)
        {
            // Code to find player information from their id
            int id;
            cout << "\n\n==== Find player information from id ===="
                 << "\n\nEnter player id: ";
            cin >> id;
            findPlayer(id);
        }
        else if (userChoice == 6)
        {
            // Code to delete player from their id
            int id;
            cout << "\n==== Remove player by ID ====" << endl;
            cout << "Enter player ID to remove: ";
            cin >> id;

            if (id >= 1 && id < n)
            {
                cout << "Player " << players[id].name << " has been removed from the VNL database." << endl;
                // Mark the slot as empty or inactive
                players[id].name = "Player has been removed from the database";
                players[id].gender = "";
                players[id].country = "";
                players[id].point = 0;
            }
            else
            {
                cout << "Error! Invalid player ID." << endl;
            }

            cout << "\nEnter another choice: ";
        }
        else if (userChoice == 7)
        {
            cout << "\n==== About Volleyball Nations League ====\n"
                 << "\nThe Volleyball Nations League (VNL) is a\n"
                 << "top-tier international volleyball tournament organized\n"
                 << "by the International Volleyball Federation (FIVB). It\n"
                 << "features both men's and women's competitions and follows\n"
                 << "a round-robin format, where participating national teams\n"
                 << "from around the world compete against each other in a series\n"
                 << "of preliminary rounds. The VNL serves as a crucial preparation\n"
                 << "tournament for teams leading up to major events like the\n"
                 << "Olympics and World Championships, attracting some of the best\n"
                 << "volleyball talent globally. Matches are hosted in various countries,\n"
                 << "providing fans worldwide with high-quality volleyball action and\n"
                 << "global viewership."
                 << "\n\nEnter another choice: ";
        }

        else
        {
            cout << "Invalid choice. Please choose a valid option.\n\nEnter your choice:" << endl;
        }
    }
}