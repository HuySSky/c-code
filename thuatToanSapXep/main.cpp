#include <bits/stdc++.h>

using namespace std;

#define fi first
#define se second
#define pb push_back
#define mienbai ""

typedef unsigned long long ull;
typedef long long ll;

enum TestingType
{
    cio,
    fio,
    fico
};

enum FileExtensionType{
    lower,
    upper,
    stdcpp
};

const bool isTesting = 1;
FileExtensionType fileExtensionType = lower;
TestingType testingType = fico;

void openFile()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(0);
    if(isTesting)
    {
        if(testingType == cio)
        {}
        else if(testingType == fio)
        {
            freopen("test.inp","r",stdin);
            freopen("test.out","w",stdout);
        }
        else if(testingType == fico)
        {
            freopen("test.inp","r",stdin);
        }
    }
    else
    {
        if(fileExtensionType == lower)
        {
            freopen(mienbai".inp","r",stdin);
            freopen(mienbai".out","w",stdout);
        }
        else if(fileExtensionType == upper)
        {
            freopen(mienbai".INP","r",stdin);
            freopen(mienbai".OUT","w",stdout);
        }
        else if(fileExtensionType == stdcpp)
        {}
    }
}

void fallenChildSort(int *l, int *r)
{
    if(r - l <= 1)
    {
        return;
    }

    int size = r - l;

    int *b = new int[size];
    int *pb = b;

    int endOfA = size;

    for(int *pr =l , *i = l+1; i < r; i++)
    {
        if(*pr > *i)
        {
            *pb = *i;
            pb++;

            *i = -2e9;

            endOfA--;
        }
        else
        {
            pr = i;
        }
    }

    if(pb - b == 0)
    {
        return;
    }

    for(int *pl= l, *pr = l;pl< l + endOfA;)
    {
        if(*pl == -2e9)
        {
            if(*pr != -2e9)
            {
                *pl = *pr;
                *pr = -2e9;
                pl++, pr++;
            }
            else
            {
               pr++;
            }
        }
        else
        {
            pl++, pr++;
        }
    }

    fallenChildSort(b, pb);

    int *p1 = l + (endOfA -1), *p2 = r - 1, *p3 = pb - 1;

    while(p1 - l >= 0 && p3 - b >= 0)
    {
        if(*p1 < *p3)
        {
            *p2 = *p3;
            p3--;
        }
        else
        {
            *p2 = *p1;
            p1--;
        }

        p2--;
    }

    while(p1 - l >= 0)
    {
        *p2 = *p1;
        p2--;
        p1--;
    }

    while(p3 - b >= 0)
    {
        *p2 = *p3;
        p2--;
        p3--;
    }

    return;
}

int A[1000001];

//int A[] = {-1, -2, 3, 15, -6, 4, 1, 2, 3, 49, -87, 4, 13};

int main()
{
    openFile();

    int n;
    cin>>n;

    for(int i=1;i<=n;i++)
    {
        cin>>A[i];
    }

    /*sort(A, A+n, [](int a, int b)
         {
             return a >= b;
         });*/

    //int n = sizeof(A) / sizeof(A[0]);

    fallenChildSort(A+1, A + n+1);

    //sort(A, A+n);

    /*for(int i=0;i<n;i++)
    {
        cout<<A[i]<<' ';
    }*/

    for(int i=1;i<=n-1;i++)
    {
        if(A[i] > A[i+1])
        {
            cout<<"Not Valid";
            return 0;
        }
    }

    cout<<"It's OK";

    return 0;
}
