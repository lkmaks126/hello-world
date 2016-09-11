#include <iostream>
#include <vector>
#include <iomanip>
#include <conio.h>
#include <windows.h>
using namespace std;
int p(int n){
    if (n == 1)
        return 2;
    if (n == 2)
        return 1;
}
int CheckFive(vector<vector<char> > a){
    for (int i = 0; i < 11; i++){
        for (int j = 0; j < 15; j++){
            if ((a[i][j] == a[i + 1][j]) && (a[i][j] == a[i + 2][j]) && (a[i][j] == a[i + 3][j]) && (a[i][j] == a[i + 4][j]) && (a[i][j] != 48))
                return a[i][j] - 48;
        }
    }
    for (int i = 0; i < 11; i++){
        for (int j = 0; j < 15; j++){
            if ((a[i][j] == a[i][j + 1]) && (a[i][j] == a[i][j + 2]) && (a[i][j] == a[i][j + 3]) && (a[i][j] == a[i][j + 4]) && (a[i][j] != 48))
                return a[i][j] - 48;
        }
    }
    for (int i = 0; i < 11; i++){
        for (int j = 0; j < 11; j++){
            if ((a[i][j] == a[i + 1][j + 1]) && (a[i][j] == a[i + 2][j + 2]) && (a[i][j] == a[i + 3][j + 3]) && (a[i][j] == a[i + 4][j + 4]) && (a[i][j] != 48))
                return a[i][j] - 48;
        }
    }
    for (int i = 4; i < 15; i++){
        for (int j = 0; j < 11; j++){
            if ((a[i][j] == a[i - 1][j + 1]) && (a[i][j] == a[i - 2][j + 2]) && (a[i][j] == a[i - 3][j + 3]) && (a[i][j] == a[i - 4][j + 4]) && (a[i][j] != 48))
                return a[i][j] - 48;
        }
    }
    return 0;
}
void print(vector<vector<char> > a, int n = 15, int m = 15){
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++)
            cout << a[i][j] << " ";
        cout << endl;
    }
}


int Mark(vector<vector<char> > a, int color, int start_color){
    int flag = 0;
    if (CheckFive(a) != 0)
        return CheckFive(a);
    for (int i = 0; i < 15; i++){
        for (int j = 0; j < 15; j++){
            if (a[i][j] == 48){
                vector <vector<char> > b = a;
                b[i][j] = color;
                system("CLS");
                print(b);
                if (CheckFive(b) == color + 48)
                    return color;
                for(int i = 0; i < 15; i++){
                    for (int j = 0; j < 15; j++){
                        if (b[i][j] == 48){
                            vector <vector<char> > c = b;
                            c[i][j] = p(color) + 48;
                            system("CLS");
                            print(c);
                            if (Mark(c, color, start_color) == color)
                                return color;
                        }
                    }
                }
            }
        }
    }
}


int main()
{
    vector <vector<char> > a(15);
    for (int i = 0; i < 15; i++)
        a[i].resize(15);
    for (int i = 0; i < 15; i++){
        for (int j = 0; j < 15; j++){
            a[i][j] = '0' ;
        }
    }
    int insert_point_x = 7, insert_point_y = 7;
    char before = '0';
    char key, inserting;
    while (key != 0){
        print(a);
        cout << CheckFive(a);
        a[insert_point_x][insert_point_y] = before;
        key = _getch();
        if ((key == 'a') && (insert_point_y != 0))
            insert_point_y--;
        else if ((key == 'w') && (insert_point_x != 0))
            insert_point_x--;
        else if ((key == 'd') && (insert_point_y != 14))
            insert_point_y++;
        else if ((key == 's') && (insert_point_x != 14))
            insert_point_x++;
        else if ((key == 'q') || (key == 'e')){
            if (key == 'q')
                a[insert_point_x][insert_point_y] = '1';
            else
                a[insert_point_x][insert_point_y] = '2';
            before = a[insert_point_x][insert_point_y];
            system("CLS");
            continue;
        }
        else if (key == 'r')
            cout << Mark(a, 1, 1);
        before = a[insert_point_x][insert_point_y];
        a[insert_point_x][insert_point_y] = '+';
        system("CLS");
    }

    return 0;
}
