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

    sort(b, pb);

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

/*void fallenChildSort(vector<int> &a)
{
    /*cout<<"first : "<<endl;
    for(auto &fe: a)
    {
        cout<<fe<<' ';
    }
    cout<<endl;

    if(a.size() <= 1)
    {
        return;
    }

    vector<int> b;

    int endOfA = a.size() -1;

    for(int r =0 , i = 1; i < a.size(); i++)
    {
        if(a[r] > a[i])
        {
            b.pb(a[i]);
            a[i] = NULL;

            endOfA--;
        }
        else
        {
            r = i;
        }
    }

    if(b.size() == 0)
    {
        return;
    }

    /*cout<<"second : "<<endl;
    for(auto &fe: a)
    {
        cout<<fe<<' ';
    }
    cout<<endl;*

    for(int l=0, r=0;l<=endOfA;)
    {
        if(a[l] == NULL)
        {
            if(a[r] != NULL)
            {
                a[l] = a[r];
                a[r] = NULL;
                l++, r++;
            }
            else
            {
                r++;
            }
        }
        else
        {
            l++, r++;
        }
    }

    /*cout<<"third : "<<endl;
    for(auto &fe: a)
    {
        cout<<fe<<' ';
    }
    cout<<endl;*


    sort(b);

    int p1 = endOfA, p2 = a.size() -1, p3 = b.size() -1;

    for(int i=1;i<=a.size();i++)
    {
        if(p1 == -1)
        {
            a[p2] = b[p3];;
            p2--;
            p3--;
        }
        else if(p3 == -1)
        {
            a[p2] = a[p1];
            p2--;
            p1--;
        }
        else if(a[p1] < b[p3])
        {
            a[p2] = b[p3];
            p2--;
            p3--;
        }
        else if (a[p1] >= b[p3])
        {
            a[p2] = a[p1];
            p2--;
            p1--;
        }
    }

    /*cout<<"fourth : "<<endl;
    for(auto &fe: a)
    {
        cout<<fe<<' ';
    }
    cout<<endl;*


    return;
}*/

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
