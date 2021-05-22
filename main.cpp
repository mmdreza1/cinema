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
        ll password;
};
class admin{
    public:
        string username;
        ll password;
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
            users = fopen("F:\\Cinema Project\\Users.txt","a+");

            int cnt=0;
            if( users != NULL){
                while ( !feof(users)){
                    cnt++;
                    if( feof(users))break;
                }
            }
            // seeing if the username was already registered or not

            if (users != NULL){
                string compare[cnt];
                while ( !feof(users)){
                    fscanf(users,"%s",username);
                    if( feof(users))break;
                }
            }

            user ob;
            cout << "Enter your username" << endl;
            cin >> ob.username;
            for (int i=0; i<cnt; i++){

                if( )
            }
        }
    }
}
