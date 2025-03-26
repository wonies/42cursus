#include <iostream>
#include <string>

using namespace std;

int main(void)
{
    char a[10] = "wonie";
    char b[20] = "konie";
    char c[20];

    int len = strlen(a);
    strcat(b, a);
    cout<<"len :"<<len<<endl;
    cout<<"cat :"<<b<<endl;
    strcpy(c, b);
    cout<<"cpy :"<<c<<endl;

    if (strcmp(c, b))
        cout<<"is it not same??"<<a<<endl;
    else
        cout<<"is it same??"<<b<<endl;
    return 0;

}