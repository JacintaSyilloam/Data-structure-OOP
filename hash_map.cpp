#include <iostream>
#include <map>

using namespace std;

// initialize map that associates string with a map of string
map<string, map<string, string>> dataAkun;

// hash function
int hashFunction(string password)
{
  unsigned long hash = 5381; // initialize prime number

  for (char c : password) // loop each character in password
  {
    hash = ((hash << 5) + hash) ^ static_cast<unsigned long>(c);
    // hash << 5: shift binary bits of hash by 5 positions to the left
    // + hash: result added to original hash value
    // static_cast<unsigned long>(c): convert to ascii
    // ^ = XOR
  }

  return hash;
}

void registerAkun()
{
  string username, password, fullname;
  cout << "Masukkan Username: " << endl;
  cin >> username;
  cout << "Masukkan Password: " << endl;
  cin >> password;
  cout << "Masukkan Nama Lengkap: " << endl;
  cin >> fullname;

  string hash_key = to_string(hashFunction(password));

  map<string, string> dataDetail;
  dataDetail["username"] = username;
  dataDetail["fullname"] = fullname;

  // insert to map
  dataAkun[hash_key] = dataDetail;
}

void loginAkun()
{
  string username, password;
  cout << "Insert Username: " << endl;
  cin >> username;
  cout << "Insert Password: " << endl;
  cin >> password;

  string hash_key = to_string(hashFunction(password));

  cout << endl;
  if (dataAkun.find(hash_key) != dataAkun.end())
  {
    cout << "Login succeeds!\n"
         << endl
         << endl;
    cout << "==== Account Details ====\n"
         << endl;
    cout << "Username: " << dataAkun[hash_key]["username"] << endl;
    cout << "Fullname: " << dataAkun[hash_key]["fullname"] << endl;
  }
  else
  {
    cout << "\nLogin failed!" << endl
         << endl;
  }
}

void printAkun()
{
  cout << endl;
  for (auto i = dataAkun.begin(); i != dataAkun.end(); i++)
  {
    cout << "Key: " << i->first << "\t"
         << " Username: " << i->second["username"] << " Fullname: " << i->second["fullname"] << endl;
  }
}

// Menu
void menu()
{
  while (true)
  {
    int input_user;

    cout << endl;
    cout << "==== MENU ====" << endl;
    cout << "1. Register" << endl;
    cout << "2. Login" << endl;
    cout << "3. Exit" << endl;

    cout << endl;
    cout << "\nInsert number from menu: " << endl;
    cin >> input_user;

    if (input_user == 1)
    {
      registerAkun();
    }
    else if (input_user == 2)
    {
      loginAkun();
    }
    else if (input_user == 3)
    {
      printAkun();
      break;
    }
    else
    {
      cout << "Invalid!" << endl;
    }
  }
}

int main()
{
  menu();
}