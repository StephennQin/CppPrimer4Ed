#include<windows.h>
#pragma comment ( lib, "user32.lib" )
#pragma comment ( lib, "gdi32.lib" ) //��"Settings->Compiler->Linker Settings->Other Linker Options"���-mwindows
//ȫ�ֱ���
HINSTANCE hinst;
//��������
LRESULT CALLBACK MainWndProc( HWND, UINT, WPARAM, LPARAM );
//
int WINAPI WinMain(
    HINSTANCE hinstance,
    HINSTANCE hPrevInstance,
    LPSTR lpCmdLine,
    int nCmdShow)
{
    WNDCLASSEX wcx;     //  ������
    HWND hwnd;          //  ���ھ��
    MSG msg;            //  ��Ϣ
    BOOL fGotMessage;   //  �Ƿ�ɹ���ȡ��Ϣ
    hinst = hinstance;  //  Ӧ�ó���ʵ�����,����Ϊȫ�ֱ���

    //��䴰��������ݽṹ
    wcx.cbSize = sizeof( wcx );                                 //�ṹ��Ĵ�С
    wcx.style = CS_HREDRAW | CS_VREDRAW;                        //��ʽ:��С�ı�ʱ�ػؽ���
    wcx.lpfnWndProc = MainWndProc;                              //������Ϣ������
    wcx.cbClsExtra = 0;                                         //��ʹ�����ڴ�
    wcx.cbWndExtra = 0;                                         //��ʹ�ô����ڴ�
    wcx.hInstance = hinstance;                                  //������Ӧ�ó���ʵ�����
    wcx.hIcon = LoadIcon( NULL, IDI_APPLICATION );              //ͼ��:Ĭ��
    wcx.hCursor = LoadCursor( NULL, IDC_ARROW );                //���:Ĭ��
    wcx.hbrBackground = (HBRUSH) ( WHITE_BRUSH ); //����:��ɫ
    wcx.lpszMenuName = NULL;                                    //�˵�:��ʹ��
    wcx.lpszClassName = "MainWClass";                           //��������
    wcx.hIconSm = (HICON)LoadImage(
                      hinstance,
                      MAKEINTRESOURCE(5),
                      IMAGE_ICON,
                      GetSystemMetrics(SM_CXSMICON),
                      GetSystemMetrics(SM_CXSMICON),
                      LR_DEFAULTCOLOR);                         //Сͼ��
    //ע�ᴰ����
    if( !RegisterClassEx(&wcx) )
    {
        return 1;
    }
    //��������
    hwnd = CreateWindowA(
               "MainWClass",       //������
               "CH 2-3",           //���ڱ���
               WS_OVERLAPPEDWINDOW,//������ʽ
               CW_USEDEFAULT,      //ˮƽλ��X:Ĭ��
               CW_USEDEFAULT,      //��ֱλ��Y:Ĭ��
               CW_USEDEFAULT,      //���:Ĭ��
               CW_USEDEFAULT,      //�߶�:Ĭ��
               (HWND) NULL,        //������:��
               (HMENU) NULL,       //�˵�:ʹ�ô�����Ĳ˵�
               hinstance,          //Ӧ�ó���ʵ�����
               (LPVOID) NULL );    //���ڴ���ʱ����:��

    if( !hwnd )
    {
        return 1;
    }
    //��ʾ����
    ShowWindow( hwnd, nCmdShow );
    UpdateWindow( hwnd );
    //��Ϣѭ��
    while(
        ( fGotMessage = GetMessage( &msg, (HWND)NULL, 0, 0 ) != 0)
        && fGotMessage != 1 )
    {
        TranslateMessage( &msg );
        DispatchMessage( &msg );
    }
    return msg.wParam;
}
/*
    MainWndProc
    ����: ������Ϣ������,��������Ϣ��ʹ��Ĭ�ϴ�����
*/
LRESULT CALLBACK MainWndProc(
    HWND hwnd,
    UINT uMsg,
    WPARAM wParam,
    LPARAM lParam)
{
    switch ( uMsg )
    {
    case WM_DESTROY :
        ExitThread(0);
        return 0;
    default :
        return DefWindowProc( hwnd, uMsg, wParam, lParam );
    }
}
