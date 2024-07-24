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

void sort(vector<int> &a)
{
    if(a.size() <= 1)
    {
        return;
    }

    vector<int> b;

    int endOfA = a.size() -1;

    for(int r = a.size()-1, i = a.size()-2 ; i>=0; i--)
    {
        if(a[i] > a[r])
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

    return;
}

int main()
{
    openFile();

    int n;
    cin>>n;

    vector<int> temp(n);
    for(int i=0;i<temp.size();i++)
    {
        cin>>temp[i];
    }
    /*for(int i=0;i<temp.size();i++)
    {
        cout<<temp[i]<<" ";
    }
    cout<<endl;*/

    //sort(temp.begin(), temp.end());

    sort(temp);

    /*for(int i=0;i<temp.size();i++)
    {
        cout<<temp[i]<<" ";
    }*/

    return 0;
}
