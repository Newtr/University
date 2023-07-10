#include <iostream>
#include <clocale>
#include <ctime>

#include "ErrorMsgText.h"
#include "Windows.h"

#define STOP "STOP"
#define NAME L"\\\\.\\pipe\\Tube"

using namespace std;

int main()
{
    setlocale(LC_ALL, "rus");

    HANDLE cH;
    DWORD lp;
    char ibuf[50], obuf[50] = "Hello from ClientNPct ";

    try {
        cout << "ClientNPсt\n\n"; 

            if (!CallNamedPipe(NAME,
                obuf,  sizeof(obuf), 
                ibuf, sizeof(ibuf), 
                &lp, 
                NULL))
            {                  
                throw SetPipeError("CallNamedPipe: ", GetLastError());
            }
            cout << ibuf << endl;

        system("pause");
    }
    catch (string ErrorPipeText) {
        cout << endl << ErrorPipeText;
    }
}