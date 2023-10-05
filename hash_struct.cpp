// belom

#include <iostream>
#include <string>

using namespace std;

struct HashTable
{
    string username, password;
} dataAccount[26];

int HashFunction(string password)
{
    return tolower(password[0]) - 97;
}

void printAll(){
    for (int i; i < 26; i++) {
        cout << i << "\t||\t" << dataAccount[i].username << " - " << dataAccount[i].password << "\n";
    }
}

void Menu()
{
    int userInput;

    while (true)
    {
        cout << "--- HOME PAGE  ---\n"
             << "1. Register\n"
             << "2. Login\n"
             << "3. Exit\n\n"
             << "Please input a number to proceed: ";

        cin >> userInput;
        cout << endl;

        if (userInput == 1)
        {
            string username, password;

            cout << "Insert username: ";
            cin >> username;
            cout << "Insert password: ";
            cin >> password;

            int index = HashFunction(password);

            dataAccount[index].username = username;
            dataAccount[index].password = password;
        }
        else if (userInput == 2)
        {
            cout << "--- LOGIN ----";
        } 
        else if (userInput == 3){
            printAll();

            break;
        } else {
            cout << "Invalid input!\n\n";
            return Menu();
        }
    }
}

int main()
{
    Menu();

}