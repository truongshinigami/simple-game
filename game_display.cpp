#include "display_game.h"


using namespace std;


const std :: string Welcome=
"\t\t\t\tWelcome to MY SMALL SUDOKU GAME !!!! \n"
"\t\t\t\tPress any key to continue \n";



void clrscr()
{
    CONSOLE_SCREEN_BUFFER_INFO  csbiInfo;
    HANDLE  hConsoleOut;
    COORD   Home = { 0, 0 };
    DWORD   dummy;
    hConsoleOut = GetStdHandle(STD_OUTPUT_HANDLE);
    GetConsoleScreenBufferInfo(hConsoleOut, &csbiInfo);
    FillConsoleOutputCharacter(hConsoleOut, ' ', csbiInfo.dwSize.X * csbiInfo.dwSize.Y, Home, &dummy);
    csbiInfo.dwCursorPosition.X = 0;
    csbiInfo.dwCursorPosition.Y = 0;
    SetConsoleCursorPosition(hConsoleOut, csbiInfo.dwCursorPosition);
}

void GoTo(short x, short y){
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void textColor(int color)
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

int main()
{
    prepare();
    srand(time(NULL));
    string b = choosePuzzle();
    givenumtoSolverArray(b);
    givenumtoPlayground(b);
    givenumtoCantchange(b);
    Interact();

}

string choosePuzzle(){
    int randomrows;
    string h;
    vector <string> numarray;
    ifstream game("puzzle.txt");
        if (game.is_open())
        {
            while (getline(game,h))
            {
                numarray.push_back(h);
            }
        }
        game.close();
    if (numarray.size()>0){
        randomrows = rand() % numarray.size();
        return numarray[randomrows];
    }
    else
        return " ";

}


void givenumtoPlayground(string b)
{
    int i,j,k=0;
    for ( i=0;i<N;i++){
        for ( j=0;j<N;j++)
        {
            if (b[k]=='1')
                playground[i][j]=1;
            if (b[k]=='2')
                playground[i][j]=2;
            if (b[k]=='3')
                playground[i][j]=3;
            if (b[k]=='4')
                playground[i][j]=4;
            if (b[k]=='5')
                playground[i][j]=5;
            if (b[k]=='6')
                playground[i][j]=6;
            if (b[k]=='7')
                playground[i][j]=7;
            if (b[k]=='8')
                playground[i][j]=8;
            if (b[k]=='9')
                playground[i][j]=9;
            k++;
        }
    }


}

void givenumtoSolverArray(string b)
{
    int i,j,k=0;
    for ( i=0;i<N;i++){
        for ( j=0;j<N;j++)
        {
            if (b[k]=='0')
                solverarray[i][j]=0;
            if (b[k]=='1')
                solverarray[i][j]=1;
            if (b[k]=='2')
                solverarray[i][j]=2;
            if (b[k]=='3')
                solverarray[i][j]=3;
            if (b[k]=='4')
                solverarray[i][j]=4;
            if (b[k]=='5')
                solverarray[i][j]=5;
            if (b[k]=='6')
                solverarray[i][j]=6;
            if (b[k]=='7')
                solverarray[i][j]=7;
            if (b[k]=='8')
                solverarray[i][j]=8;
            if (b[k]=='9')
                solverarray[i][j]=9;
            k++;
        }
    }

}

void givenumtoCantchange(string b)
{
    int i,j,k=0;
    for ( i=0;i<N;i++){
        for ( j=0;j<N;j++)
        {
            if (b[k]=='0')
                cantchange[i][j]=0;
            if (b[k]=='1')
                cantchange[i][j]=1;
            if (b[k]=='2')
                cantchange[i][j]=2;
            if (b[k]=='3')
                cantchange[i][j]=3;
            if (b[k]=='4')
                cantchange[i][j]=4;
            if (b[k]=='5')
                cantchange[i][j]=5;
            if (b[k]=='6')
                cantchange[i][j]=6;
            if (b[k]=='7')
                cantchange[i][j]=7;
            if (b[k]=='8')
               cantchange[i][j]=8;
            if (b[k]=='9')
                cantchange[i][j]=9;
            k++;
        }
    }

}


void prepare ()
{
    while(1)
    {
        textColor(rand()%15);
        cout << Welcome;
        if(kbhit())
        {
            getch();
            break;
        }
        Sleep(500);
        clrscr();
    }
    clrscr();
    textColor(7);
}

void display()
{

    cout << "   A B C D E F G H I" << endl;
    cout << endl;
    for (int i=0;i<N;i++){
        cout << i+1 << "  ";
        for (int j=0;j<N;j++)
        {

            if (playground[i][j] == cantchange[i][j] && playground[i][j] != 0){
                textColor(3);
                cout << playground[i][j];
                textColor(7);
            }
            else if (playground[i][j] == 0)
                cout << " ";
            else
                cout << playground[i][j];
            if ((j+1)%3==0 && j+1 != 9)
                cout << "|";
            else
                cout << " ";
        }
    cout << endl;
    if ((i+1)%3 == 0 && (i+1) != N)
         cout << "   -----+-----+-----" << endl;
    }
    displayMenu();

}

int cantChangeElements(int x,int y)
{
     if (cantchange[x][y] == 0 )
        return 1;
     else
        return 2;

}


void checking()
{
    clrscr();
    cout << "   A B C D E F G H I" << endl;
    cout << endl;
    for (int i=0;i<N;i++){
        cout << i+1 << "  ";
        for (int j=0;j<N;j++)
        {
            if (playground[i][j] == cantchange[i][j] && playground[i][j] != 0){
                textColor(3);
                cout << playground[i][j];
                textColor(7);
            }
            else if (playground[i][j] == solverarray[i][j] ){
                textColor(10);
                cout << playground[i][j];
                textColor(7);
            }
            else if (playground[i][j] == 0){
                cout << " ";
            }
            else
            {
                textColor(4);
                cout << playground[i][j];
                textColor(7);
            }
            if ((j+1)%3==0 && j+1 != 9)
                    cout << "|";
            else
                    cout << " ";
        }
    cout << endl;
    if ((i+1)%3 == 0 && (i+1) != N)
         cout << "   -----+-----+-----" << endl;
    }

    Sleep(2000);
    clrscr();
}

void printAnswer(){

int i,j;
cout << "   A B C D E F G H I" << endl;
    cout << endl;
    for ( i=0;i<N;i++){

        cout << i+1 << "  ";
        for ( j=0;j<N;j++) {
        {
            cout << solverarray[i][j];

        }
            if ((j+1)%3==0 && j+1 != 9)
                cout << "|";
            else
                cout << " ";
        }
    cout << endl;
    if ((i+1)%3 == 0 && (i+1) != N)
         cout << "   -----+-----+-----" << endl;
  }
}



void playing(int num,int x,int y)
{

    if (cantChangeElements(y-1,x-1) == 2){
        GoTo(14,14);
        cout << "You can't change that element" << endl;
        Sleep(2000);
    }
    else
        playground[y-1][x-1] = num;
    return;
}

void displayMenu()
{
   GoTo(32,2);
   cout << " Rules ";
   GoTo(32,3);
   cout << " p nYou job is fill all empty block with number !! \n";
   GoTo(32,4);
   cout << " Use W A S D to move to the place you want to change number!!\n";
   GoTo(32,5);
   cout << " Use number button (1~9) to change element on changeable block !! \n";
   GoTo(32,6);
   cout << " Use number button 0 to remove number you think it not right !! \n";
   GoTo(32,7);
   cout << " But fill all empty block isn't all !! \n";
   GoTo(32,8);
   cout << " Remember every sudoku puzzle have unique solutions : \n";
   GoTo(32,9);
   cout << " Each number can only appear in 1 row , 1 columns and 1 3x3 square only !!";
   GoTo(32,10);
   cout << " Use C to check how you are doing !! \n";
   GoTo(32,11);
   cout << " If the puzzle too hard :< \n";
   GoTo(32,12);
   cout << " Use Q to give up and show the answer!! \n";
   return;
}

int IfgameisCleared()
{
    int i,j,count1=0;
    for (i=0;i<N;i++)
        for (j=0;j<N;j++)
    {
        if (SolveSudoku(solverarray) == true)
            if (solverarray[i][j] == playground[i][j])
                count1++;
    }
    if (count1==81)
        return 1;
    return 0;
}

void Interact(){

    display();
    int interacttimes=0;
    clock_t begin,end;
    int time_spend;
    bool done = false;
    int giveup = 0;
    int x=3; int y=2;   // x sang ngang y len xuong


    begin = clock();

while ( done != true  ){

        int num;
        GoTo(x,y);
        char option = getch();
        switch(option){
        case 'w' :  case 'W':         // go up
           {
            if (y > 2)
                y=y-1;
            if (y == 5 || y == 9)
                y=y-1;
            break;
            }
        case 's' : case 'S':       // go down
            {
            if (y<12 )
                y=y+1;
            if (y == 5 || y == 9)
                y=y+1;
            break;
            }
        case 'a' : case 'A':              // turn left
            {
            if (x > 3)
                x=x-2;
            break;
            }
        case 'd' : case 'D':              // turn right
            {
            if (x < 19)
                x=x+2;
            break;
            }
        case 'q':{
            giveup = 1;
            done = true;
            clrscr();
            break;
        }
        case 'c':
            interacttimes+=1;
            if (SolveSudoku(solverarray) == true)
                checking();
            clrscr();
            display();
            break;
        case '1':
            {
                int ev;
                int locx=((x-1)/2);
                if (y < 5)
                    ev=0;
                if (5 <= y && y < 9)
                    ev=1;
                if (y >= 9 && y <= 12)
                    ev=2;
                int locy=(y-1)-ev;
                num=1;
                playing(num,locx,locy);
                if (IfgameisCleared()==1)
                    done = true;
                clrscr();
                display();
                break;
            }
        case '2':
            {
                int ev;
                int locx=((x-1)/2);
                if (y < 5)
                    ev=0;
                if (5 <= y && y < 9)
                    ev=1;
                if (y >= 9 && y <= 12)
                    ev=2;
                int locy=(y-1)-ev;
                num=2;
                playing(num,locx,locy);
                if (IfgameisCleared()==1)
                    done = true;
                clrscr();
                display();
                break;
            }
        case '3':
            {
                int ev;
                int locx=((x-1)/2);
                if (y < 5)
                    ev=0;
                if (5 <= y && y < 9)
                    ev=1;
                if (y >= 9 && y <= 12)
                    ev=2;
                int locy=(y-1)-ev;
                num=3;
                playing(num,locx,locy);
                if (IfgameisCleared()==1)
                    done = true;
                clrscr();
                display();
                break;
            }
        case '4':
            {
                int ev;
                int locx=((x-1)/2);
                if (y < 5)
                    ev=0;
                if (5 <= y && y < 9)
                    ev=1;
                if (y >= 9 && y <= 12)
                    ev=2;
                int locy=(y-1)-ev;
                num=4;
                playing(num,locx,locy);
                if (IfgameisCleared()==1)
                    done = true;
                clrscr();
                display();
                break;
            }
        case '5':
            {
                int ev;
                int locx=((x-1)/2);
                if (y < 5)
                    ev=0;
                if (5 <= y && y < 9)
                    ev=1;
                if (y >= 9 && y <= 12)
                    ev=2;
                int locy=(y-1)-ev;
                num=5;
                playing(num,locx,locy);
                if (IfgameisCleared()==1)
                    done = true;
                clrscr();
                display();
                break;
            }
        case '6':
            {
                int ev;
                int locx=((x-1)/2);
                if (y < 5)
                    ev=0;
                if (5 <= y && y < 9)
                    ev=1;
                if (y >= 9 && y <= 12)
                    ev=2;
                int locy=(y-1)-ev;
                num=6;
                playing(num,locx,locy);
                if (IfgameisCleared()==1)
                    done = true;
                clrscr();
                display();
                break;
            }
        case '7':
            {
                int ev;
                int locx=((x-1)/2);
                if (y < 5)
                    ev=0;
                if (5 <= y && y < 9)
                    ev=1;
                if (y >= 9 && y <= 12)
                    ev=2;
                int locy=(y-1)-ev;
                num=7;
                playing(num,locx,locy);
                if (IfgameisCleared()==1)
                    done = true;
                clrscr();
                display();
                break;
            }
        case '8':
            {
                int ev;
                int locx=((x-1)/2);
                if (y < 5)
                    ev=0;
                if (5 <= y && y < 9)
                    ev=1;
                if (y >= 9 && y <= 12)
                    ev=2;
                int locy=(y-1)-ev;
                num=8;
                playing(num,locx,locy);
                if (IfgameisCleared()==1)
                    done = true;
                clrscr();
                display();
                break;
            }
        case '9':
            {
                int ev;
                int locx=((x-1)/2);
                if (y < 5)
                    ev=0;
                if (5 <= y && y < 9)
                    ev=1;
                if (y >= 9 && y <= 12)
                    ev=2;
                int locy=(y-1)-ev;
                num=9;
                playing(num,locx,locy);
                if (IfgameisCleared()==1)
                    done = true;
                clrscr();
                display();
                break;
            }
        case '0':
            {
                int ev;
                int locx=((x-1)/2);
                if (y < 5)
                    ev=0;
                if (5 <= y && y < 9)
                    ev=1;
                if (y >= 9 && y <= 12)
                    ev=2;
                int locy=(y-1)-ev;
                num=0;
                playing(num,locx,locy);
                if (IfgameisCleared()==1)
                    done = true;
                clrscr();
                display();
                break;
            }
        default :
            GoTo(14,14);
            cout << "Your choice are invalid. Please choose again!";
            Sleep(2000);
            clrscr();
            display();
            break;
        }

   }

            end = clock();
            time_spend = (int)(end-begin)/ CLOCKS_PER_SEC;  // time counting
            int sec = time_spend;
            int minu = 0;
            minu = minu + (sec/60);
            sec = sec % 60;
            clrscr();
            if (done == true && giveup == 1){
                cout << "You can't make it !!" << endl;
                cout << "Game Over !!" << endl;
                if (SolveSudoku(solverarray) == true)
                    printAnswer();
                cout << "Try harder next time !! ^^";
            }
            if (done == true && giveup != 1){

            cout << "GAME OVER !!" << endl;
            cout << "Congratulation !! You Finished It" << endl;
            cout << "Total check time : " << interacttimes << endl;
            cout << "Play Times : " <<  minu << " minutes " << sec << " sec" << endl;
            if (SolveSudoku(solverarray) == true)
                printAnswer();

            if (sec<=300 && interacttimes<=1  )
                cout << "Fast as Barry Allen (:0)";
            if ((sec<=600 && sec > 300) && (interacttimes <=3 && interacttimes > 1))
                cout << "Fast and Furious !!";
            if ((sec<=900 && sec < 600) && (interacttimes <=6 && interacttimes > 3))
                cout << "You made it just in time !! ^^";
            if (sec>900 || interacttimes > 10)
                cout << "At least you try !! :v";
            }
    return;
}
