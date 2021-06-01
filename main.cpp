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
class movie{
    public:
        char name[1000];
        char genre[1000];
        char director[1000];
        char firstAct[1000];
        char secondAct[1000];
        char thirdAct[1000];
        char reserve[1000];
};

void Addmovie(){
    FILE *ptr;
    FILE *ptr2;
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
    char w[1000] = "F:\\Cinema Project\\";
    strcat(w,genre);
    strcat(w, ".txt");
    ptr2 = fopen(w,"a");
    fprintf(ptr2, "%s\n", name);
    fclose(ptr2);
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
    char reserve[1000];
    cout << "Please enter the number of seats available" << endl;
    cin >> reserve;
    fprintf(ptr, "%s",reserve);
    fclose(ptr);
    movie ob;
    strcpy(ob.name, name);
    strcpy(ob.director, director);
    strcpy(ob.firstAct, firstAct);
    strcpy(ob.secondAct, secondAct);
    strcpy(ob.thirdAct, thirdAct);
    ptr = fopen("F:\\Cinema Project\\AllMovies.txt", "a");
    fprintf(ptr, "%s\n", ob.name);
    fclose(ptr);
}

void Removemovie(){
    int st;
    do{
        char name[1000];
        cout << "Enter the name of the movie which you want to delete" << endl;
        gets(name);
        char s[1000] = "F:\\Cinema Project\\movies\\";
        strcat(s,name);
        strcat(s,".txt");
        int status;
        status = remove(s);
        st = status;
        if( status == 0){
            FILE *ptr;
            char nam[1000];
            ptr = fopen("F:\\Cinema Project\\AllMovies.txt", "r");
            int size = 0;
            while( !feof(ptr)){
                fscanf(ptr, " %[^\n]s", nam);
                size++;
                if(feof(ptr))break;
            }
            fclose(ptr);
            char names[size][1000];
            ptr = fopen("F:\\Cinema Project\\AllMovies.txt", "r");
            for ( int i=0; i<size; i++){
                fscanf(ptr, " %[^\n]s", names[i]);
            }
            fclose(ptr);
            ptr = fopen("F:\\Cinema Project\\AllMovies.txt", "w");
            for ( int i =0; i < size; i++){
                if ( strcmp(names[i], name) != 0){
                    fprintf(ptr, "%s\n", names[i]);
                }
            } fclose(ptr);
        }
        else if ( status != 0)cout << "No movie matches your given movie name!!  Please try again" << endl;
    }while ( st != 0);
}

void EditMovie(){
    int st;
    do{
        char name[1000];
        cout << "Please enter the name of the movie you want to edit" << endl;
        gets(name);
        char s[1000] = "F:\\Cinema Project\\movies\\";
        strcat(s, name);
        strcat(s, ".txt");
        int status;
        status = remove(s);
        st = status;
        if ( status == 0)break;
        else if ( status != 0)cout << "No movie matches this name. Please try again" << endl;
    }while (  st != 0);
    cout << "Now please enter the changed information" << endl;
    Addmovie();
}

void DisplayAllMovies(){
    char name[1000];
    FILE * ptr;
    int size = 0;
    ptr = fopen("F:\\Cinema Project\\AllMovies.txt", "a+");
    while (!feof(ptr)){
        fscanf(ptr, "%s", name);
        size++;
        if(feof(ptr))break;
    }
    if ( size == 1)cout << "There is no movie available" << endl;
    fclose(ptr);
    ptr = fopen("F:\\Cinema Project\\AllMovies.txt", "r");
    while ( ! feof(ptr)){
        fscanf(ptr, "%[^\n]s", name);
        if (feof(ptr))break;
        cout << name << endl;
    }
    fclose(ptr);
}

void DisplayMoviesofSameGenre(){
    FILE *ptr;
    char name[1000];
    int size = 0;
    char genre[1000];
    cout << "Please choose your Genre" << endl;
    gets(genre);
    char s[1000] = "F:\\Cinema Project\\";
    strcat(s, genre);
    strcat(s, ".txt");
    ptr = fopen(s,"a+");
    while (!feof(ptr)){
        fscanf(ptr, "%s", name);
        size++;
        if(feof(ptr))break;
    }
    fclose(ptr);
    if (size == 1)cout << "There is no movie matching your criteria" << endl;
    ptr = fopen(s,"a+");
    while( !feof(ptr)){
        fscanf(ptr," %[^\n]s", name);
        if (feof(ptr))break;
        cout << name << endl;
    }
    fclose(ptr);
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

void reserveseat(){
    FILE * baseda;
    bool flag = false;
    char name[1000];
    char all[6][1000];
    int nada=0;
    char chosenname[1000];
    do {
        cout << "Enter the name of your movie" << endl;
        gets(chosenname);
        baseda = fopen("F:\\Cinema Project\\AllMovies.txt","r");
        while( ! feof(baseda)){
            fscanf(baseda, " %[^\n]s", name);
            if ( strcmp(name, chosenname) == 0)flag = true;
            if ( feof(baseda) )break;
        } fclose(baseda);
        if ( flag == false)cout << "There is no movie in the list with your given information. Please try again" << endl;
    } while ( flag == false);
    fclose(baseda);

    char s[1000] = "F:\\Cinema Project\\movies\\";
    strcat(s, chosenname);
    strcat(s, ".txt");
    baseda = fopen(s, "r");
    char adad[1000];
    while ( ! feof(baseda)){
        fscanf(baseda, " %[^\n]s", adad);
        if ( feof(baseda))break;
        strcpy(all[nada], adad);
        nada++;
    }
    string tedad;
    int i=0;
    while ( adad[i] != NULL){
        i++;
    }
    for ( int q = 0; q < i; q++){
        tedad = tedad + adad[q];
    }
    i = stoi(tedad);
    cout << "Number of seats available is" << " " << i << endl;
    if ( i == 0){cout << "Unfortunately there is no availabe seat " << endl; return;}
    int hala;
    cout << "How many seats would you like to reserve?" << endl;
    cin >> hala;
    while ( hala > i){
        cout << "Please enter a valid number of seats" << endl;
        cin >> hala;
    }
    i = i - hala;
    tedad = to_string(i);
    strcpy(adad, tedad.c_str());
    fclose(baseda);
    baseda = fopen(s, "w");
    for ( int j = 0; j < nada-1; j++){
        fprintf(baseda, "%s\n", all[j]);
    }
    fprintf(baseda, "%s\n", adad);
    fclose(baseda);
    cout << "Your reserve has been successful!" << endl;
    return;
}

void choicesForAdmin(){
    int cmd;
    cout << "choose " << endl << endl;
    cout << "1. Add a new movie" << endl;
    cout << "2. Remove a movie" << endl;
    cout << "3. Edit a movie" << endl;
    cout << "4. Display all movies" << endl;
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
    if ( cmd == 3){
        cin.ignore();
        EditMovie();
        choicesForAdmin();
    }
    if ( cmd == 4){
        DisplayAllMovies();
        choicesForAdmin();
    }
    if ( cmd == 7){
        cin.ignore();
        DisplayMoviesofSameGenre();
        choicesForAdmin();
    }
    if ( cmd == 8)return;

}

void choicesForUser(){
    int cmd;
    cout << "choose " << endl << endl;
    cout << "1. Display all movies" << endl;
    cout << "2. Smart Search (SS)" << endl;
    cout << "3. Group Sreach" << endl;
    cout << "4. Display all movies of the same group(genre)" << endl;
    cout << "5. Reserve" << endl;
    cout << "6. Exit" << endl;
    cin >> cmd;
    if( cmd == 1){
        DisplayAllMovies();
        choicesForUser();
    }
    if ( cmd == 4){
        cin.ignore();
        DisplayMoviesofSameGenre();
        choicesForUser();
    }
    if ( cmd == 5){
        cin.ignore();
        reserveseat();
        choicesForUser();
    }
    if ( cmd == 6)return;
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
        choicesForUser();
    }
}
