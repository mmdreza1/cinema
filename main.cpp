#include<bits/stdc++.h>
#include<QMap>
#include<QList>
using namespace std;

typedef long long ll ;
FILE *users;
FILE *admins;

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
            users = fopen("F:\\Cinema Project\\Users.txt","r");
        }
        else if ( cmd1 == "No"){
            char username[1000];
            char password[1000];
            user ob;
            users = fopen("F:\\Cinema Project\\Users.txt","a+");
            bool flag = false;

            do {

                cout << "Enter your username" << endl;
                cin >> ob.username;
                // checking if the username was already registered or not
                if (users != NULL){
                    while ( !feof(users)){
                        fscanf(users,"%s",username);
                        if( ob.username == username ){
                            flag = true;
                            cout << " this username has been already registered." << "      " << "Try again" << endl;
                            break;
                        }
                        if( feof(users))break;
                    }
                }
            } while( flag == true);
            cout << "Enter a password" << endl;
            cin >> ob.password;
            strcpy(username, ob.username.c_str());
            strcpy( password, ob.password.c_str());
            fprintf(users,"%s\n%s\n",username,password);
        }
    }
}
