#include<windows.h>
int WINAPI WinMain (HINSTANCE hInstance,
                    HINSTANCE hPrevInstance,
                    LPSTR lpCmdLine,
                    int nCmdShow)

{
    LPWSTR szUnicode = L"This is a Unicode String;";//定义LPWSTR类型的宽字符串
    LPSTR szMultiByte = "This is not a Unicode String;";//定义LPSTR类型的窄字符串
    LPTSTR szString = TEXT("This String is Unicode or not depends on the option;");//定义LPTSTR类型的自适用字符串

    MessageBoxW( NULL, szUnicode, L"<Style1>", MB_OK );//使用W版本的API函数,以宽字符串为参数
    MessageBoxA( NULL, szMultiByte, "<Style2>", MB_OK );//使用A版本的API函数,以窄字符串为参数
    MessageBox( NULL, szString, TEXT("<Style3>"), MB_OK );//使用W版本的API函数,以宽字符串为参数

    return 0;
}
//当字符为中文是MinGW显示编译错误“错误：converting to execution character set：Illegal byte sequence”。
//原因是我的代码中使用 <wstring>，g++需要额外的选项指定输入文件的编码格式。
//使用g++ test.cpp -finput-charset=GBK（或GB2312）即可通过编译。
