//#include <bits/stdc++.h>
//using namespace std;
//
//int main()
//{
//    int n;
//    string s;      // Լ���� һ���Զ��߳��� char����
//    cin >> n >> s; // ����
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
//using namespace std; // ��ʱ���ù�Ϊɶ��Ŀǰ��ѧ���ϾͶ���
//int main()
//{
//    int n;
//    int sum = 0;
//    int arr[105];
//    cin >> n; // ����
//    for (int i = 0; i < n; i++)
//    {
//        cin >> arr[i];
//        sum += arr[i];
//    }
//    sort(arr, arr + n, greater<int>()); // ������ arr[0]~arr[n-1] ���дӴ�С���򡣻�C++�ǲ��Ǻ����ɣ�
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
//    cout << cnt; // ���
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
//        int sum = i * k;                    // ��i����Ʒ
//        if (sum % 10 == 0 || sum % 10 == r) // ʹ������ʮԪ֧�� �� ʹ������ʮԪ+rԪ֧��
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
//        int vis[205] = {}; //={}����˼�ǳ�ʼ������
//                           // ��Ϊx�����ֵΪ100��a�����ֵҲΪ100 �����Դ���������200.
//                           // vis[i] = 1 ������Ϊ��i������arr�����г��ֹ�
//        int arr[105] = {};
//        for (int i = 1; i <= n; i++)
//        {
//            cin >> arr[i];
//            vis[arr[i]] = 1; // vis[arr[i]] = 1 ���� arr[i] �� �����г��ֹ�
//        }
//        for (int i = 1; i <= 201; i++)
//        {
//            if (vis[i] > 0) // �������i���ֹ����ͼ���
//                continue;
//            else // ���û���ֹ�����x�Ƿ����0����������㣬x-1 ���������������0������i�ﲻ������ֱ�����i-1
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





