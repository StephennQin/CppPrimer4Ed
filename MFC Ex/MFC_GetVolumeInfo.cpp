#include<windows.h>
#include<stdlib.h>
#include<stdio.h>

#define BUFSIZE 1024

BOOL GetDirverInfo( LPSTR szDrive );

int main()
{
    CHAR szLogicalDriveStrings( BUFSIZE );
    PCHAR szDrive;
    ZeroMemory( szLogicalDriveStrings, BUFSIZE );
    // 获取逻辑驱动器卷标名
    GetLogicalDriveStrings( BUFSIZE-1, szLogicalDriveStrings );
    szDrive = (PCHAR)szLogicalDriveStrings;
    // 循环处理每个卷
    do
    {
        if ( !GetDriverInfo(szDrive) )
            printf( "\nGet Volume Information Error: %d", GetLastError() );
        szDrive += (lstrlen(szDrive)+1);
    }while( *szDrive != '\x00' );
}
