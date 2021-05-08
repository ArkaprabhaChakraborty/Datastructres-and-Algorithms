#include<iostream>
using namespace std;
typedef long long unsigned llu;
int main(void)
{
    char hp,fch,prevfch;
    cin>>hp;
    llu res=0,rem=0,op1,op2;
    cin>>op1;
    if(!(op1>=0&&op1<=9))
    {
        cout<<"-1";
        return 0;
    }
    if(hp=='*')
    {
        llu count=0;
        while(1)
        {
            cin>>fch>>op2;
            if(fch==';') break;
            if((op2>=0&&op2<=9)&&(fch=='+'||fch=='*')) 
            {
                prevfch=fch;
                if(op1==0&&prevfch==fch) count++;
                else count=0;
                if(fch=='*')
                {
                    res=op1*op2;
                    op1=res;
                }
                else 
                {
                    rem+=op1;
                    op1=op2;
                }
            } 
            else 
            {
                cout<<"-1";
                return 0;
            }
            if(count>=10000) 
            {
                cout<<"-1";
                return 0;
            }
        }
        if(fch==';') cout<<res+rem;
        else cout<<"-1";
    }
    else 
    {
        llu count=0;
        rem=1;
        while(1)
        {
            cin>>fch>>op2;
            if(fch==';') break;
            if((op2>=0&&op2<=9)&&(fch=='+'||fch=='*')) 
            {
                prevfch=fch;
                if(op1==op2&&prevfch==fch) count++;
                else count=0;
                if(fch=='+')
                {
                    res=op1+op2;
                    op1=res;
                }
                else 
                {
                    rem*=op1;
                    op1=op2;
                }
            } 
            else 
            {
                cout<<"-1";
                return 0;
            }
            if(count>=10000) 
            {
                cout<<"-1";
                return 0;
            }
        }
        if(fch==';') cout<<rem*op1;
        else cout<<"-1";
    }
    return 0;
}