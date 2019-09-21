#include <iostream>
#include <stdlib.h>
#include <ctime>

using namespace std;

int main(){
    srand(time(NULL));
    time_t start1, end1, start2, end2;
    int Ar[1000];
    for(int i=0; i<1000; i++){
        Ar[i] = 0+rand()%100;
    }
    int s = 0;
    time(&start1);
    for(int i=0; i<1000; i++){
        s+=Ar[i];
    }
    time(&end1);
    double seconds1 = difftime(end1, start1);
    int m = 0;
    time(&start2);
    int *q = Ar+1000;
    for(int *p=Ar; p!=q; p++){
        m+=*p;
    }
    time(&end2);
    double seconds2 = difftime(end2, start2);
    if(seconds1>seconds2){
        cout<<"Second algorithm is more quickly than first";
    }
    else if(seconds1==seconds2){
        cout<<"Both algorithms take the same time";
    }
    else{
        cout<<"First algorithm is more quickly than second";
    }
    return 0;
}
