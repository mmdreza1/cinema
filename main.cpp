#include<bits/stdc++.h>
#include<QMap>
#include<QSet>
#include<QVector>
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

void Addmovie(){
    FILE *ptr;
    char name[1000];
    cout << "Enter the name of the movie" << endl;
    gets(name);
    char s[100] ="F:\\Cinema Project\\movies\\";
    strcat(s,name);
    strcat(s,".txt");
    ptr = fopen(s,"a");
    fprintf(ptr,"%s\n",name);
    char genre[1000];
    cout << "Please specify which group(genre) this movie belongs to" << endl;
    gets(genre);
    fprintf(ptr, "%s\n",genre);
    char director[1000];
    cout << "Please enter the name of the director" << endl;
    gets(director);
    fprintf(ptr,"%s\n",director);
    char firstAct[1000];
    char secondAct[1000];
    char thirdAct[1000];
    cout << "Please enter the name of the leading actor/actress of the movie" << endl;
    gets(firstAct);
    fprintf(ptr, "%s\n",firstAct);
    cout << "Please enter the name of the second main actor/actress of the movie" << endl;
    gets(secondAct);
    fprintf(ptr,"%s\n",secondAct);
    cout << "Please enter the name of the third main actor/actress of the movie" << endl;
    gets(thirdAct);
    fprintf(ptr,"%s\n",thirdAct);
    fclose(ptr);
}

void Removemovie(){
    char name[1000];
    cout << "Enter the name of the movie which you want to delete" << endl;
    gets(name);
    char s[1000] = "F:\\Cinema Project\\movies\\";
    strcat(s,name);
    strcat(s,".txt");
    cout << s << endl;
    int status;
    status = remove(s);
    if( status == 0)cout << "Movie was successfuly removed from the list " << endl;
    else if ( status != 0)cout << "No movie matches your given movie name!!" << endl;
}

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

void choicesForAdmin(){
    int cmd;
    cout << "choose " << endl << endl;
    cout << "1. Add a new movie" << endl;
    cout << "2. Remove a movie" << endl;
    cout << "3. Edit a movie" << endl;
    cout << "4. Display all movies" << endl;
                                              //      cout << "5. Categorization" << endl;
    cout << "5. Smart Search (SS)" << endl;
    cout << "6. Group Sreach" << endl;
    cout << "7. Display all movies of the same group" << endl;
    cout << "8. Exit" << endl;
    cin  >> cmd;
    if( cmd == 1){
        cin.ignore();
        Addmovie();
        choicesForAdmin();
    }
    if ( cmd == 2){
        cin.ignore();
        Removemovie();
        choicesForAdmin();
    }

    if ( cmd == 8)return;

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
        choicesForAdmin();
    }
    if ( Entryforuser == true){
        int cmd;
        cout << "choose " << endl << endl;
        cout << "1. Display all movies" << endl;
        cout << "2. Smart Search (SS)" << endl;
        cout << "3. Group Sreach" << endl;
        cout << "4. Display all movies of the same group" << endl;
        cout << "5. Reserve" << endl;
        cout << "6. Exit" << endl;
        cin >> cmd;
    }
}
