#include<bits/stdc++.h>
using namespace std;

int A[27],B[27],C[27];

int main ()
{
    int q;
    cin>>q;

    while(q--)
    {

        string s,t,p,q;
        cin>>s>>t>>p;
        int chk=0;



        for(int i=0; i<t.length(); i++)
        {
            q="";
            int check=0;
            if(s[i]==t[i])continue;
            for(int j=0; j<p.size(); j++)
            {
                if(p[j]==t[i])
                {
                    check=1;
                    p[j]='*';
                    for(int k=0; k<s.size()+1; k++)
                    {
                        if(k==i)
                        {
                            q+=t[i];
                            continue;
                        }
                        if(k>i)q+=s[k-1];
                        else q+=s[k];
                    }

                    break;
                }
            }
            if(check==0)
            {
                cout<<"NO"<<endl;
                chk=1;
                break;
            }
            //cout<<q;

            s="";
            s=q;
            q="";
            //cout<<" "<<s<<endl;
        }
        //cout<<s<<" bahir "<<t<<endl;

        if(s==t)cout<<"YES"<<endl;
        else if(!chk)cout<<"NO"<<endl;
    }

}