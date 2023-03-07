#include <iostream>
using namespace std;

int dx[8] = {-1,-1,-1,0,0,1,1,1};
int dy[8] = {-1,0,1,-1,1,-1,0,1};

void NhapMaTran(int** &a,int &m,int &n)
{
    cout << "Nhap so dong cua ma tran: ";
    cin >> m;
    cout << "Nhap so cot cua ma tran: ";
    cin >> n;
    a = new int* [m];
    for(int i=0;i<m;++i)
    {
        a[i] = new int[n];
        for(int j=0;j<n;++j)
        {
            cout << "Nhap a[" << i << "][" << j << "]: ";
            cin >> a[i][j];
        }
    }
}

void XuatMaTran(int** a,int m,int n)
{
    for(int i=0;i<m;++i)
    {
        for(int j=0;j<n;++j)
        {
            cout << a[i][j] << ' ';
        }
        cout << endl;
    }
}

bool isOK(int i,int j,int m,int n)
{
    return (i>=0 && i<m && j>=0 && j<n);
}

void solve(int** &a,int m,int n,bool &flag)
{
    for(int i=0;i<m;++i)
    {
        for(int j=0;j<n;++j)
        {
            if(a[i][j]<0)
            {
                for(int k=1;k<=max(m,n);++k)
                {
                    bool done = 0;
                    for(int l=1;l<=min(k,max(m,n)) && !done;++l)
                    {
                        for(int o=0;o<8 && !done;++o)
                        {
                            int x = i+dx[o]*k;
                            int y = j+dy[o]*l;
                            if(isOK(x,y,m,n) && a[x][y]>0)
                            {
                                done = flag = 1;
                                a[i][j] = a[x][y];
                            }
                        }
                    }
                    if(done) break;
                }   
            }
        }
    }
}

int main()
{
    int m,n;
    int** a;
    NhapMaTran(a,m,n);
    cout << "Ma tran da nhap la: \n";
    XuatMaTran(a,m,n);
    bool flag = 0;
    solve(a,m,n,flag);
    if(!flag) cout << "Khong co so nguyen duong trong ma tran\n";
    else cout << "Ma tran sau khi duoc xu ly la\n";
    XuatMaTran(a,m,n);
    delete a;
    return 0;
}