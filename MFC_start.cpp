#include<windows.h>
//������ʹ��User32.lib
#pragma comment ( lib, "User32.lib" )
//
int WinMain(
                HINSTANCE hInstance,
                HINSTANCE hPrevInstance,
                LPSTR lpCmdLine,
                int nCmdShow
            )
{
    MessageBox(
                NULL,
                TEXT("��ʼѧϰWindows���"),
                TEXT("��Ϣ�Ի���"),
                MB_OK
               );
    return 0;
}
