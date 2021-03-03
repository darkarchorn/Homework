#include<bits/stdc++.h>
using namespace std;
int ngauNhien()
{
    int n;
    n=rand()%10+1;
    return n;
}
int main()
{
    srand(time(0));
    int rua, tho;
    int so1, so2;
    while(rua<70 && tho <70)
    {
        so1=ngauNhien();
        if(so1>=1 && so1<=5) {rua+=3; cout << "Rua tien dai: " <<rua<<endl;}
        else if(so1<=8) {rua+=1; cout <<"Rua tien ngan: "<<rua<<endl;}
        else {rua-=6; cout <<"Rua truot: "<<rua<<endl;}
        if(rua<0) {rua=0; cout << "Do rua<0 -> ve vach xuat phat!"<<endl;}

        so2=ngauNhien();
        if(so2>=1&&so2<=2) cout<<"Tho ngu: "<< tho << endl;
        else if(so2<=4) {tho+=9; cout <<"Tho tien dai: "<<tho<<endl;}
        else if(so2==5) {tho-=12; cout <<"Tho truot dai: "<<tho<<endl;}
        else if(so2<=8) {tho+=1; cout << "Tho tien ngan: "<<tho<<endl;}
        else {tho-=2; cout<<"Tho truot ngan: "<<tho<<endl;}
        if(tho<0) {tho=0; cout << "Do rua>70 -> ve vach xuat phat!"<<endl;}
        cout<< endl;
    }
    if(tho >= 70) cout<< "Tho win!";
    else if(rua >= 70) cout<<"Rua win!";
}
