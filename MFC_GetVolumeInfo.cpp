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
    // ��ȡ�߼������������
    GetLogicalDriveStrings( BUFSIZE-1, szLogicalDriveStrings );
    szDrive = (PCHAR)szLogicalDriveStrings;
    // ѭ������ÿ����
    do
    {
        if ( !GetDriverInfo(szDrive) )
            printf( "\nGet Volume Information Error: %d", GetLastError() );
        szDrive += (lstrlen(szDrive)+1);
    }while( *szDrive != '\x00' );
}
