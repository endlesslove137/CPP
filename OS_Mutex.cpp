#include <stdio.h>
#include <iostream>
#include <conio.h>
#include <sys/types.h>
#include "vector"
// #include <unistd.h>
using namespace std;

#define MAX 255
#include <iostream>   
#include <windows.h>   
using namespace std;   
HANDLE hMutex;
  
DWORD WINAPI Fun(LPVOID lpParamter)   
{   
      while(1) {
		WaitForSingleObject(hMutex, INFINITE);         
      	cout<<"Fun display!"<<endl;
      	_sleep(1000);
      	ReleaseMutex(hMutex);
      }   
}   
  
int main()   
{   
    HANDLE hThread = CreateThread(NULL, 0, Fun, NULL, 0, NULL);   
    CloseHandle(hThread);   
    hMutex = CreateMutex(NULL, FALSE, "screen");   
    while(1) {
		WaitForSingleObject(hMutex, INFINITE);   
    	cout<<"main display!"<<endl;
    	_sleep(2000);
    	ReleaseMutex(hMutex);
	}   
    return 0;   
} 

