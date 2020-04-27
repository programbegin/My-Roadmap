# include <stdio.h>
#include <windows.h>
int main(){
    while(1){
        for (long i = 0; i < 4000000;i++){//忙
        }
        Sleep(10);//闲
    }
    return 0;
}