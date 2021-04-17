#include<iostream>
#include<time.h>
#include<windows.h>
#include<vector>
using namespace std;

vector <int> n;
int i;
int kr2, bu2;

bool Example(int k1, int l1, int m1, int n1, int k2, int l2, int m2, int n2, int bu, int kr){

    kr2 = 0;
    bu2 = 0;

    if(k1 != k2){
        if(k1 == l2 || k1 == m2 || k1 == n2){
            kr2++;
        }
    }else{
        bu2++;
    }


    if(l1 != l2){
        if(l1 == k2 || l1 == m2 || l1 == n2){
            kr2++;
        }
    }else{
        bu2++;
    }


    if(m1 != m2){
        if(m1 == k2 || m1 == l2 || m1 == n2){
            kr2++;
        }
    }else{
        bu2++;
    }


    if(n1 != n2){
        if(n1 == k2 || n1 == l2 || n1 == m2){
            kr2++;
        }
    }else{
        bu2++;
    }


    return (bu2 == bu && kr2 == kr);
}

void Number(){
    for(int i = 1000;i < 10000;i++){
        if((i/1000)%10 != (i/100)%10 &&
           (i/1000)%10 != (i/10)%10 &&
           (i/1000)%10 != i%10 &&
           (i/100)%10 != (i/10)%10 &&
           (i/100)%10 != i%10 &&
           (i/10)%10 != i%10){
            n.push_back(i);
        }
    }
}

void BC(int k1, int l1, int m1, int n1, int k2, int l2, int m2, int n2){
    kr2 = 0;
    bu2 = 0;

    if(k1 != k2){
        if(k1 == l2 || k1 == m2 || k1 == n2){
            kr2++;
        }
    }else{
        bu2++;
    }


    if(l1 != l2){
        if(l1 == k2 || l1 == m2 || l1 == n2){
            kr2++;
        }
    }else{
        bu2++;
    }


    if(m1 != m2){
        if(m1 == k2 || m1 == l2 || m1 == n2){
            kr2++;
        }
    }else{
        bu2++;
    }


    if(n1 != n2){
        if(n1 == k2 || n1 == l2 || n1 == m2){
            kr2++;
        }
    }else{
        bu2++;
    }


    cout<<"B: "<<bu2<<endl<<"K: "<<kr2<<endl;
}

int main(){

    HANDLE h;
    h = GetStdHandle(STD_OUTPUT_HANDLE);

    int opit, turn = 1;
    int a1, b1, c1, d1, kr1, bu1;
    int chislo, myn, trai;
    int r;

    srand (time(NULL));
    chislo = rand() % 2;

    Number();

    myn = n[rand()%(n.size())];

    SetConsoleTextAttribute(h, 9);
    if(chislo == 1){
        cout<<"I am first!"<<endl;
    }else{
        cout<<"You are first!"<<endl;
    }

    srand (time(NULL));

    while(true){
        SetConsoleTextAttribute(h, 5);
        cout<<"Turn: "<<turn<<endl;

        r = rand()%(n.size());

        if(chislo != 1){
            SetConsoleTextAttribute(h, 10);
            cout<<"You: ";
            cin>>trai;
            BC((trai/1000)%10, (trai/100)%10, (trai/10)%10, trai%10, (myn/1000)%10, (myn/100)%10, (myn/10)%10, myn%10);
        }

        SetConsoleTextAttribute(h, 4);
        cout<<"Mee: ";
        cout<<n[r]<<endl<<"B: ";

        cin>>bu1;

        cout<<"K: ";

        cin>>kr1;

        a1 = (n[r]/1000)%10;
        b1 = (n[r]/100)%10;
        c1 = (n[r]/10)%10;
        d1 = (n[r]/1)%10;

        for(i = 0;i < n.size();){
            if(!Example(a1, b1, c1, d1, (n[i]/1000)%10, (n[i]/100)%10, (n[i]/10)%10, n[i]%10, bu1, kr1)){
                n[i] = n[n.size()-1];
                n.pop_back();
            }else{
                i++;
            }
        }

        if(chislo == 1){
            SetConsoleTextAttribute(h, 10);
            cout<<"You: ";
            cin>>trai;
            BC((trai/1000)%10, (trai/100)%10, (trai/10)%10, trai%10, (myn/1000)%10, (myn/100)%10, (myn/10)%10, myn%10);
        }

        if(bu1 == 4 && (trai/1000)%10 == (myn/1000)%10 && (trai/100)%10 == (myn/100)%10 && (trai/10)%10 == (myn/10)%10 && (trai/1)%10 == (myn/1)%10){
            SetConsoleTextAttribute(h, 6);
            cout<<"Draw!";
            SetConsoleTextAttribute(h, 15);
            return 0;
        }

        if(bu1 == 4){
            SetConsoleTextAttribute(h, 6);
            cout<<endl<<"Haha i win your number is ";
            SetConsoleTextAttribute(h, 4);
            cout<<n[r];
            SetConsoleTextAttribute(h, 15);

            SetConsoleTextAttribute(h, 6);
            cout<<endl<<"My number was: ";
            SetConsoleTextAttribute(h, 4);
            cout<<myn;
            SetConsoleTextAttribute(h, 15);
            return 0;
        }

        if((trai/1000)%10 == (myn/1000)%10 && (trai/100)%10 == (myn/100)%10 && (trai/10)%10 == (myn/10)%10 && (trai/1)%10 == (myn/1)%10){
            SetConsoleTextAttribute(h, 6);
            cout<<"You have beaten me!";
            SetConsoleTextAttribute(h, 15);
            return 0;
        }

        if(n.size() == 0){
            SetConsoleTextAttribute(h, 6);
            cout<<"You have lied! I win!"<<endl<<"My number was: "<<myn;
            SetConsoleTextAttribute(h, 15);
            return 0;
        }

        //cout<<"Razmer: "<<n.size()<<endl;
        cout<<endl;
        turn++;
    }

    return 0;
}
