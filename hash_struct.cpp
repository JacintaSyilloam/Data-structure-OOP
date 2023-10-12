// Jacinta Syilloam
// 5027221036

#include <iostream>
#include <string>

using namespace std;

struct HashTable
{
    string username, password;
} dataAccount[26];

// custom basic hash function: combining ascii with xor
int HashFunction(string password)
{
    int hash = 0;

    // iterate through each character in the password
    for (char c : password)
    {
        // XOR the hash with the ASCII value of the character
        // static_cast: casting operator in cpp
        // static_cast<int>(c): convert character c to integer
        hash ^= static_cast<int>(c);
    }

    // ensure the index is within the array size (26)
    int index = hash % 26;

    return index;
}

void printAll()
{
    for (int i; i < 26; i++)
    {
        cout << i << "\t||\t" << dataAccount[i].username << " - " << dataAccount[i].password << "\n";
    }
}

void Menu()
{
    int userInput;

    while (true)
    {
        cout << "--- HOME PAGE ---\n"
             << "1. Register\n"
             << "2. Login\n"
             << "3. Exit and print accounts\n\n"
             << "Please input a number to proceed: ";

        cin >> userInput;
        cout << endl;

        if (userInput == 1)
        {
            string username, password;

            cout << "--- REGISTER ---\n";
            cout << "Insert username: ";
            cin >> username;
            cout << "Insert password: ";
            cin >> password;

            int index = HashFunction(password);

            if (dataAccount[index].username.empty() && dataAccount[index].password.empty())
            {
                dataAccount[index].username = username;
                dataAccount[index].password = password;
            }
            else
            {
                cout << "Account already exists!" << endl;
            }
        }
        else if (userInput == 2)
        {
            cout << "--- LOGIN ----"
                 << "\nUnder construction";
        }
        else if (userInput == 3)
        {
            printAll();

            return Menu();
        }
        else
        {
            cout << "Invalid input!\n\n";
            return Menu();
        }
    }
}

int main()
{
    Menu();
}