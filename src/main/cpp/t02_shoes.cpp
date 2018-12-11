//В обувном магазине продается обувь разного размера. 
// Известно, что одну пару обуви можно надеть на другую, 
// если она хотя бы на три размера больше. 
// В магазин пришел покупатель. 
// Требуется определить, какое наибольшее количество пар обуви сможет предложить ему продавец так,
// чтобы он смог надеть их все одновременно.
//
//Входные данные
//
//Сначала вводится размер ноги покупателя 
// (обувь меньшего размера он надеть не сможет),
// затем количество пар обуви в магазине и размер каждой пары.
// Размер — натуральное число, не превосходящее 100, 
// количество пар обуви в магазине не превосходит 1000.
//
//Выходные данные
//
//Выведите единственное число — максимальное количество пар обуви.
//
//Sample Input:
//
//26
//5
//30 35 40 41 42
//Sample Output:
//
//3

#include "t02_shoes.h"
#include <algorithm>
#include <iostream>
#include <vector>


using namespace std;

int t02_shoes() {
    int n, cur, ind = 0, ans = 0;
    cin >> cur >> n;
    vector< int > a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    sort(a.begin(), a.end());
    while (ind < n && a[ind] < cur)
        ind++;
    if (ind != n) {
        cur = a[ind];
        ind++;
        ans++;
    }
    for (int i = ind; i < n; i++)
        if (a[i] >= cur + 3) {
            cur = a[i];
            ans++;
        }

    cout << ans;
}
