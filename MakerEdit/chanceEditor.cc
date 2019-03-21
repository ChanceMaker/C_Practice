#include <unistd.h>
#include <Windows.h>

#define STDIN_FILENO 0


int main(){
    HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleMode(h,ENABLE_ECHO_INPUT);
    char c;
    while(read(STDIN_FILENO, &c,1) == 1 && c != 'q');

    return 0;
	
}