#include<bits/stdc++.h>
#include<QMap>
#include<QList>
using namespace std;

typedef long long ll ;
FILE *users;
FILE *admins;
bool Entryforadmin = false;
bool Entryforuser = false;
class user{
    public:
        string username;
        string password;
};
class admin{
    public:
        string username;
        string password;
};

void adminEntry(){
    cout << "Already have an account ?" << endl << "Yes" << endl << "No" << endl;
    string cmd1;
    cin >> cmd1;
    if ( cmd1 == "Yes"){
        user ob1;
        char user1name[1000];
        char pass1word[1000];
        bool flag2 = true;


        do {
            admins = fopen("F:\\Cinema Project\\Admins.txt","r");
            cout << "Enter your previously registered username." << endl;
            cin >> ob1.username;
            cout << "Enter your password" << endl;
            cin >> ob1.password;
            while( !feof(admins)){
                fscanf(admins, "%s%s", user1name, pass1word);
                if (ob1.username == user1name && ob1.password == pass1word){
                    cout << "Entry Granted" << endl;
                    Entryforadmin = true;
                    fclose(admins);
                    flag2 = false;
                    break;
                }
                if( feof(admins)){
                    fclose(admins);
                    break;
                }
            }
        } while( flag2 == true );
    }
    else if ( cmd1 == "No"){
        char username[1000];
        char password[1000];
        user ob;
        bool flag = false;

        do {
            admins = fopen("F:\\Cinema Project\\Admins.txt","a+");
            cout << "Enter your username" << endl;
            cin >> ob.username;
            // checking if the username was already registered or not
            if (admins != NULL){
                while ( !feof(admins)){
                    fscanf(admins,"%s",username);
                    if( ob.username == username ){
                        flag = true;
                        cout << "this username has been already registered." << "      " << "Try again" << endl;
                        break;
                    }
                    if( feof(admins) && ob.username != username){
                        flag = false;
                        fclose(admins);
                        break;
                    }
                }
                fclose(admins);
            }
        } while( flag == true);
        cout << "Enter a password" << endl;
        cin >> ob.password;
        strcpy(username, ob.username.c_str());
        strcpy( password, ob.password.c_str());
        admins = fopen("F:\\Cinema Project\\Admins.txt","a+");
        fprintf(admins,"%s\n%s\n",username,password);
        cout << "Your registration is complete." << "       " << "Please re-enter the program " << endl;
        fclose(admins);
    }
}

int main(){
    cout << endl << "           " << "Welcome to MovieTown" << endl;
    cout << "Would you like to enter as an user or as an admin ?" << endl;
    cout << "Either type 'user' or type 'admin'" << endl;
    string cmd0;
    cin >> cmd0;

    if ( cmd0 == "user"){
        cout << "Already have an account ?" << endl << "Yes" << endl << "No" << endl;
        string cmd1;
        cin >> cmd1;
        if ( cmd1 == "Yes"){
            user ob1;
            char user1name[1000];
            char pass1word[1000];
            bool flag2 = true;


            do {
                users = fopen("F:\\Cinema Project\\Users.txt","r");
                cout << "Enter your previously registered username." << endl;
                cin >> ob1.username;
                cout << "Enter your password" << endl;
                cin >> ob1.password;
                while( !feof(users)){
                    fscanf(users, "%s%s", user1name, pass1word);
                    if (ob1.username == user1name && ob1.password == pass1word){
                        cout << "Entry Granted" << endl;
                        Entryforuser = true;
                        fclose(users);
                        flag2 = false;
                        break;
                    }
                    if( feof(users)){
                        fclose(users);
                        break;
                    }
                }
            } while( flag2 == true );
        }
        else if ( cmd1 == "No"){
            char username[1000];
            char password[1000];
            user ob;         
            bool flag = false;

            do {
                users = fopen("F:\\Cinema Project\\Users.txt","a+");
                cout << "Enter your username" << endl;
                cin >> ob.username;
                // checking if the username was already registered or not
                if (users != NULL){
                    while ( !feof(users)){
                        fscanf(users,"%s",username);
                        if( ob.username == username ){
                            flag = true;
                            cout << "this username has been already registered." << "      " << "Try again" << endl;
                            break;
                        }
                        if( feof(users) && ob.username != username){
                            flag = false;
                            fclose(users);
                            break;
                        }
                    }
                    fclose(users);
                }
            } while( flag == true);
            cout << "Enter a password" << endl;
            cin >> ob.password;
            strcpy(username, ob.username.c_str());
            strcpy( password, ob.password.c_str());
            users = fopen("F:\\Cinema Project\\Users.txt","a+");
            fprintf(users,"%s\n%s\n",username,password);
            cout << "Your registration is complete." << "       " << "Please re-enter the program " << endl;
            fclose(users);
        }
    }
    if ( cmd0 == "admin"){
        adminEntry();
    }
    if ( Entryforadmin == true){
        cout << "choose " << endl << endl;
        cout << "1. Add a new movie" << endl;
        cout << "2. Remove a movie" << endl;
        cout << "3. Edit a movie" << endl;
        cout << "4. Display all movies" << endl;
        cout << "5. Categorization" << endl;
        cout << "6. Smart Search (SS)" << endl;
        cout << "7. Group Sreach" << endl;
        cout << "8. Display all movies of the same group" << endl;
    }
    if ( Entryforuser == true){
        cout << "choose " << endl << endl;
        cout << "1. Display all movies" << endl;
        cout << "2. Smart Search (SS)" << endl;
        cout << "3. Group Sreach" << endl;
        cout << "4. Display all movies of the same group" << endl;
        cout << "5. Reserve" << endl;
    }
}
