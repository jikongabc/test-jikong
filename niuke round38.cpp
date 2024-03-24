// #include<iostream>
// #include<algorithm>
// #include<cstring>
// using namespace std;
// int main(){
//     long long n;
//     cin >> n;
//     if(n%10==0) cout << 0;
// else     cout << (long long)(10 - n % 10);
//     return 0;
// }

// #include <iostream>
// #include <algorithm>
// #include <cstring>
// using namespace std;
// const int N = 1e5 + 5;
// int main(){
//     int n, m;
//     cin >> n >> m;
//     char ch[N];
//     for (int i = 0; i < n;i++){
//         ch[i]=
//     }
// }

#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
using namespace std;
const int N = 1e6 + 5;
int a[N], b[N];
char s[N];
int main()
{
    cin >> s;
    for (int i = 1; i <= strlen(s); i++)
    {
        a[i] = s[i] - '0';
        b[i] = b[i] + a[i];
    }
    int sum = 0;
    for (int i = strlen(s); i >= 1; i--)
    {
        if (b[i] % 9 == 0)
            sum++;
    }
    cout << sum;
    return 0;
}
