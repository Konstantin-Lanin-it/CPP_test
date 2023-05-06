#include <iostream>
#include <sstream>
#include <cstring>

using namespace std;
static const char * errorMessage = "[error]";

#define error() { cout << errorMessage << endl; delete [] arr; arr=nullptr; return 0; }

int main(void)
{
    static size_t i, _j, j, cnt, bufSize = 64;
    size_t newBufSize = bufSize;
    signed long long int N;
 
    // примем то, что для такой простой задачи - std::string
    // и std::vector - слишком жино
    char * buf   = nullptr;
    long double * arr = nullptr;
 
    buf = new char[bufSize];
 
    char * buf_ptr = buf;
 
    //string buf;
 
    while (true)
    {
        cin.get(buf_ptr, bufSize, '\n');
        if ( cin.peek() != '\n')
        {
            if (!strlen(buf)) break;
            char * newBuf = new char[newBufSize+bufSize];
            memcpy(newBuf, buf, newBufSize);
            delete [] buf;
            buf = newBuf;
            newBufSize += bufSize;
            buf[newBufSize-1] = '\0';
            buf_ptr = buf + strlen(buf);
        }else
        {
            break;
        }
    }
    stringstream in (buf);
    delete [] buf;
 
    in >> N;
    if (in.peek() == '\\'  || in.peek() == '/')
    {
        in.get();
        if (in.peek() == 'n') in.get();
        in.clear();
    }
    if ( N >= 2 && in.peek() != EOF ) { }
    else 
    {
        error();
    }
 
    arr = new long double [N];
 
    for ( size_t n = 0; n < N; ++n )
    {
        if ( !isdigit(in.peek()) && in.peek() != ' ' && in.peek() != '\t' && in.peek() != '+' &&  in.peek() != '-' )
        {
            error();
        }
 
        in >> arr[n];
 
        if (cin.fail()) {error();}
 
        if ( in.peek() != ' ' && in.peek() != '\t' && in.peek()!=EOF )
        {
            error();
        }
        while(in.peek()==' ') { in.get(); }
 
    }
 
    for ( ; i < N-1; ++i )
    {
        size_t new_cnt = 0;
        if ( (*(arr+i) <= *(arr+i+1)) )
        {
            j = i;
            while ( *(arr+i) <= *(arr+i+1) )
            {
                ++i; ++new_cnt;
            }
            if (new_cnt > cnt) { cnt = new_cnt; _j=j; }
        }
    }
 
    if ( 0 == cnt )
        cout << 0 << '\n';
    else
    {
        cout << ++cnt << ' ';
        cout << ++_j << endl;
    }
 
    delete [] arr;
    return 0;
}
