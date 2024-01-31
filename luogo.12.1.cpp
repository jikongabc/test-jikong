//#include <bits/stdc++.h>
//using namespace std;
//
//int main()
//{
//    int n;
//    string s;      // 约等于 一个自动边长的 char数组
//    cin >> n >> s; // 输入
//    int vis[26];
//    for (int i = 0; i < 26; i++)
//    {
//        vis[i] = 0;
//    }
//
//    for (int i = 0; i < n; i++)
//    {
//        if (s[i] >= 'a' && s[i] <= 'z')
//        {
//            s[i] -= 32;
//        }
//    }
//
//    for (int i = 0; i < n; i++)
//    {
//        vis[s[i] - 'A'] = 1;
//    }
//
//    int flag = 0;
//    for (int i = 0; i < 26; i++)
//    {
//        if (vis[i] == 0)
//        {
//            flag = 1;
//        }
//    }
//
//    if (flag == 0)
//        cout << "YES" << endl;
//    else
//        cout << "NO" << endl;
//}


//#include <iostream>
//#include <algorithm>
//using namespace std; // 暂时不用管为啥，目前初学加上就对了
//int main()
//{
//    int n;
//    int sum = 0;
//    int arr[105];
//    cin >> n; // 输入
//    for (int i = 0; i < n; i++)
//    {
//        cin >> arr[i];
//        sum += arr[i];
//    }
//    sort(arr, arr + n, greater<int>()); // 把数组 arr[0]~arr[n-1] 进行从大到小排序。换C++是不是很轻松？
//
//    int all = sum;
//    int cnt = 0;
//    for (int i = 0; i < n; i++)
//    {
//        all -= arr[i];
//        if (sum - all > all)
//        {
//            cnt = i + 1;
//            break;
//        }
//    }
//    cout << cnt; // 输出
//}


//#include <iostream>
//using namespace std;
//
//int main()
//{
//    int k, r;
//    cin >> k >> r;
//    for (int i = 1; i <= 10; i++)
//    {
//        int sum = i * k;                    // 买i件商品
//        if (sum % 10 == 0 || sum % 10 == r) // 使用若干十元支付 或 使用若干十元+r元支付
//        {
//            cout << i << '\n';
//            break;
//        }
//    }
//    return 0;
//}


//#include <iostream>
//
//using namespace std;
//
//int main()
//{
//    int n;
//    cin>>n;
//    cout<<25; 
//    return 0;
//}


//#include <iostream>
//using namespace std;
//
//int main()
//{
//    int t;
//    cin >> t;
//    while (t--)
//    {
//        int n, x;
//        cin >> n >> x;
//        int vis[205] = {}; //={}的意思是初始化数组
//                           // 因为x的最大值为100，a的最大值也为100 ，所以答案最大可能是200.
//                           // vis[i] = 1 的意义为，i数字在arr数组中出现过
//        int arr[105] = {};
//        for (int i = 1; i <= n; i++)
//        {
//            cin >> arr[i];
//            vis[arr[i]] = 1; // vis[arr[i]] = 1 代表 arr[i] 在 数组中出现过
//        }
//        for (int i = 1; i <= 201; i++)
//        {
//            if (vis[i] > 0) // 如果数字i出现过，就继续
//                continue;
//            else // 如果没出现过，看x是否大于0，如果大于零，x-1 继续。如果不大于0，代表i达不到，则直接输出i-1
//            {
//                if (x > 0)
//                {
//                    x--;
//                    continue;
//                }
//                else
//                {
//                    printf("%d\n", i - 1);
//                    break;
//                }
//            }
//        }
//    }
//}

//#include<iostream> 
//using namespace std;
//int main(){
//	int n, k, i=0,sum=0;
//	cin >> n >> k;
//	while(sum<=(240-k) && i<=n){
//		i++;
//		sum+=i*5;
//	}
//	cout<<i-1;
//}





