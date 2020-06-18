/*
COMPACTIFY-LIST(L,F)
*/
#include <bits/stdc++.h>
using namespace std;
#define NIL -1
const int MAXN = 20;
int NEXT[MAXN], key[MAXN], PREV[MAXN];
int m, n, k, L, F;
void change(int lp, int fp)
{
    int a = NEXT[lp];
    int b = NEXT[fp];
    if (NEXT[a] != NIL)
        PREV[NEXT[a]] = b;
    /*
    if (NEXT[b] != NIL)
        PREV[NEXT[b]] = a;
    */
    if (PREV[a] != NIL)
        NEXT[PREV[a]] = b;
    NEXT[fp] = a;
    swap(NEXT[a], NEXT[b]);
    swap(key[a], key[b]);
    swap(PREV[a], PREV[b]);
}
void COMPACTIFY_LIST()
{
    int lp = L, fp = F;
    if (lp > n)
    {
        if (fp <= n)
        {
            key[fp] = key[lp];
            key[lp] = NIL;
            PREV[NEXT[lp]] = fp;
            swap(NEXT[lp], NEXT[fp]);
            swap(lp, fp);
        }
        else
            change(lp, 1), lp = 1;
    }
    L = lp;
    F = fp;
    for (int i = 1; i < n; i++)
    {
        if (NEXT[lp] > n)
        {
            while (NEXT[fp] > n)
                fp = NEXT[fp];
            change(lp, fp);
        }
        lp = NEXT[lp];
    }
}
void initial()
{
    scanf("%d%d%d%d%d", &m, &n, &k, &L, &F);
    for (int i = 1; i <= m; i++)
        scanf("%d", &NEXT[i]);
    for (int i = 1; i <= m; i++)
        scanf("%d", &key[i]);
    for (int i = 1; i <= m; i++)
        scanf("%d", &PREV[i]);
}
void check()
{
    int lp = L, p;
    while (lp != NIL)
    {
        printf("%d ", key[lp]);
        if (NEXT[lp] == NIL)
            p = lp;
        lp = NEXT[lp];
    }
    puts("");
    while (p != NIL)
    {
        printf("%d ", key[p]);
        p = PREV[p];
    }
    puts("");
}
int main()
{
    freopen("10.3-5", "r", stdin);
    initial();
    check();
    COMPACTIFY_LIST();
    check();
    return 0;
}