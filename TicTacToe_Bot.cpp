#include<iostream>
using namespace std;
char grid[5][11], botgrid[5][11];
bool gameover = false;
int n, x, y;
int i, j, br;
int bp;
void SetGrid(){
    grid[0][0] = ' ';
    grid[0][1] = '1';//Chislo
    grid[0][2] = ' ';
    grid[0][3] = '|';
    grid[0][4] = ' ';
    grid[0][5] = '2';//Chislo
    grid[0][6] = ' ';
    grid[0][7] = '|';
    grid[0][8] = ' ';
    grid[0][9] = '3';//Chislo
    grid[0][10] = ' ';

    grid[1][0] = '-';
    grid[1][1] = '-';
    grid[1][2] = '-';
    grid[1][3] = '+';
    grid[1][4] = '-';
    grid[1][5] = '-';
    grid[1][6] = '-';
    grid[1][7] = '+';
    grid[1][8] = '-';
    grid[1][9] = '-';
    grid[1][10] = '-';

    grid[2][0] = ' ';
    grid[2][1] = '4';//Chislo
    grid[2][2] = ' ';
    grid[2][3] = '|';
    grid[2][4] = ' ';
    grid[2][5] = '5';//Chislo
    grid[2][6] = ' ';
    grid[2][7] = '|';
    grid[2][8] = ' ';
    grid[2][9] = '6';//Chislo
    grid[2][10] = ' ';

    grid[3][0] = '-';
    grid[3][1] = '-';
    grid[3][2] = '-';
    grid[3][3] = '+';
    grid[3][4] = '-';
    grid[3][5] = '-';
    grid[3][6] = '-';
    grid[3][7] = '+';
    grid[3][8] = '-';
    grid[3][9] = '-';
    grid[3][10] = '-';

    grid[4][0] = ' ';
    grid[4][1] = '7';//Chislo
    grid[4][2] = ' ';
    grid[4][3] = '|';
    grid[4][4] = ' ';
    grid[4][5] = '8';//Chislo
    grid[4][6] = ' ';
    grid[4][7] = '|';
    grid[4][8] = ' ';
    grid[4][9] = '9';//Chislo
    grid[4][10] = ' ';
}

void DrawGrid(){
    for(i = 0;i < 5;i++){
        for(j = 0;j < 11;j++){
            cout<<grid[i][j];
        }
        cout<<endl;
    }
}

void NextMove(int n, char p){
    int x, y;
    if(n % 3 == 0){
        x = (n / 3 - 1) * 2;
    }else{
        x = (n / 3) * 2;
    }
    y = 4 * n - 4 - 6 * x + 1;

    if(grid[x][y] == ' '){
        grid[x][y] = p;
    }
}

void ShouldDo(char c){
    br = 0;
    if(botgrid[0][1] == botgrid[0][5] && botgrid[0][9] == ' '){
        br++;
        botgrid[0][9] = c;
        cout<<3<<endl;
    }else if(botgrid[0][1] == botgrid[0][9] && botgrid[0][5] == ' '){
        br++;
        botgrid[0][5] = c;
        cout<<2<<endl;
    }else if(botgrid[0][5] == botgrid[0][9] && botgrid[0][1] == ' '){
        br++;
        botgrid[0][1] = c;
        cout<<1<<endl;
    }

    else if(botgrid[2][1] == botgrid[2][5] && botgrid[2][9] == ' '){
        br++;
        botgrid[2][9] = c;
        cout<<6<<endl;
    }else if(botgrid[2][1] == botgrid[2][9] && botgrid[2][5] == ' '){
        br++;
        botgrid[2][5] = c;
        cout<<5<<endl;
    }else if(botgrid[2][5] == botgrid[2][9] && botgrid[2][1] == ' '){
        br++;
        botgrid[2][1] = c;
        cout<<4<<endl;
    }

    else if(botgrid[4][1] == botgrid[4][5] && botgrid[4][9] == ' '){
        br++;
        botgrid[4][9] = c;
        cout<<9<<endl;
    }else if(botgrid[4][1] == botgrid[4][9] && botgrid[4][5] == ' '){
        br++;
        botgrid[4][5] = c;
        cout<<8<<endl;
    }else if(botgrid[4][5] == botgrid[4][9] && botgrid[4][1] == ' '){
        br++;
        botgrid[4][1] = c;
        cout<<7<<endl;
    }

    else if(botgrid[0][1] == botgrid[2][1] && botgrid[4][1] == ' '){
        br++;
        botgrid[4][1] = c;
        cout<<7<<endl;
    }else if(botgrid[0][1] == botgrid[4][1] && botgrid[2][1] == ' '){
        br++;
        botgrid[2][1] = c;
        cout<<4<<endl;
    }else if(botgrid[2][1] == botgrid[4][1] && botgrid[0][1] == ' '){
        br++;
        botgrid[0][1] = c;
        cout<<1<<endl;
    }

    else if(botgrid[0][5] == botgrid[2][5] && botgrid[4][5] == ' '){
        br++;
        botgrid[4][5] = c;
        cout<<8<<endl;
    }else if(botgrid[0][5] == botgrid[4][5] && botgrid[2][5] == ' '){
        br++;
        botgrid[2][5] = c;
        cout<<5<<endl;
    }else if(botgrid[2][5] == botgrid[4][5] && botgrid[0][5] == ' '){
        br++;
        botgrid[0][5] = c;
        cout<<2<<endl;
    }

    else if(botgrid[0][9] == botgrid[2][9] && botgrid[4][9] == ' '){
        br++;
        botgrid[4][9] = c;
        cout<<9<<endl;
    }else if(botgrid[0][9] == botgrid[4][9] && botgrid[2][9] == ' '){
        br++;
        botgrid[2][9] = c;
        cout<<6<<endl;
    }else if(botgrid[2][9] == botgrid[4][9] && botgrid[0][9] == ' '){
        br++;
        botgrid[0][9] = c;
        cout<<3<<endl;
    }

    else if(botgrid[0][1] == botgrid[2][5] && botgrid[4][9] == ' '){
        br++;
        botgrid[4][9] = c;
        cout<<9<<endl;
    }else if(botgrid[0][1] == botgrid[4][9] && botgrid[2][5] == ' '){
        br++;
        botgrid[2][5] = c;
        cout<<5<<endl;
    }else if(botgrid[2][5] == botgrid[4][9] && botgrid[0][1] == ' '){
        br++;
        botgrid[0][1] = c;
        cout<<1<<endl;
    }

    else if(botgrid[0][9] == botgrid[2][5] && botgrid[4][1] == ' '){
        br++;
        botgrid[4][1] = c;
        cout<<7<<endl;
    }else if(botgrid[0][9] == botgrid[4][1] && botgrid[2][5] == ' '){
        br++;
        botgrid[2][5] = c;
        cout<<5<<endl;
    }else if(botgrid[2][5] == botgrid[4][1] && botgrid[0][9] == ' '){
        br++;
        botgrid[0][9] = c;
        cout<<3<<endl;
    }
}

void Think(){
    char k;
    int m = 0;
    if(m % 2 == 0){

    }
    for(i = 0;i < 5;i++){
        for(j = 0;j < 11;j++){
            botgrid[i][j] = grid[i][j];
        }
    }

    while(true){
        ShouldDo(k);
        if(br == 0){

        }
    }


}

int main(){
    int r = rand()%2;
    char player, bot;

    SetGrid();

    while(!gameover){
        system("cls");

        if(r == 1){
            cout<<"I'm first!"<<endl;
            bot = 'X';
            player = 'O';
        }else{
            cout<<"You are first!"<<endl;
            bot = 'O';
            player = 'X';
        }

        DrawGrid();

        if(r == 1){
            cout<<"You: ";
            cin>>n;
            if(n % 3 == 0){
                x = (n / 3 - 1) * 2;
            }else{
                x = (n / 3) * 2;
            }
            y = 4 * n - 4 - 6 * x + 1;
            grid[x][y] = player;
        }

        Think();


    }
    return 0;
}

