#include<windows.h>
int WINAPI WinMain (HINSTANCE hInstance,
                    HINSTANCE hPrevInstance,
                    LPSTR lpCmdLine,
                    int nCmdShow)

{
    LPWSTR szUnicode = L"This is a Unicode String;";//����LPWSTR���͵Ŀ��ַ���
    LPSTR szMultiByte = "This is not a Unicode String;";//����LPSTR���͵�խ�ַ���
    LPTSTR szString = TEXT("This String is Unicode or not depends on the option;");//����LPTSTR���͵��������ַ���

    MessageBoxW( NULL, szUnicode, L"<Style1>", MB_OK );//ʹ��W�汾��API����,�Կ��ַ���Ϊ����
    MessageBoxA( NULL, szMultiByte, "<Style2>", MB_OK );//ʹ��A�汾��API����,��խ�ַ���Ϊ����
    MessageBox( NULL, szString, TEXT("<Style3>"), MB_OK );//ʹ��W�汾��API����,�Կ��ַ���Ϊ����

    return 0;
}
//���ַ�Ϊ������MinGW��ʾ������󡰴���converting to execution character set��Illegal byte sequence����
//ԭ�����ҵĴ�����ʹ�� <wstring>��g++��Ҫ�����ѡ��ָ�������ļ��ı����ʽ��
//ʹ��g++ test.cpp -finput-charset=GBK����GB2312������ͨ�����롣
