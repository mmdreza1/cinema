#include<bits/stdc++.h>
using namespace std;

int main(){
    int n = 5;

    FILE * ptr;

    for (int i=0; i<n; i++){

        char a[1000];

        gets(a);

        char s[1000] = "F:\\";

        strcat(s,a);

        strcat(s,".txt");

        ptr = fopen(s, "w");

        fprintf(ptr, "%d\n", i);

        fclose(ptr);
    }
}
