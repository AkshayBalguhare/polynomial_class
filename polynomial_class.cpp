#include<iostream>
#include<math.h>
using namespace std;
class term
{
   public: int coeff;
           int expo;

};
class polynomial
{
    private: int n;
             term *t;
    public:
           polynomial(int n)
           {
               this->n=n;
               t=new term[this->n];
           }
           void create()
           {cout<<endl;
               cout<<"enter coefficent and exponent"<<endl;
               for(int i=0;i<n;i++)
               {cout<<"enter term "<<i+1<<": ";
                   cin>>t[i].coeff>>t[i].expo;
           }}
           void display()
           {
               cout<<endl;
               for(int i=0;i<n;i++)
               {
                   cout<<t[i].coeff<<"x"<<"^"<<t[i].expo;
                   if(i!=n-1)
                    cout<<"+";
               }
               cout<<endl;
           }
        polynomial add(polynomial &p)
        {
            polynomial *sum=new polynomial(n+p.n);
            int i=0,j=0,k=0;
            while(i<n&&j<p.n)
            {
                if(t[i].expo>p.t[j].expo)
                    sum->t[k++]=t[i++];
                else if(t[i].expo<p.t[j].expo)
                    sum->t[k++]=p.t[j++];
                else
                {
                    sum->t[k].expo=t[i].expo;
                    sum->t[k++].coeff=t[i++].coeff+p.t[j++].coeff;
                }
            }
            for(;i<n;i++)
                sum->t[k++]=t[i];
            for(;j<p.n;j++)
                sum->t[k++]=p.t[j];
            sum->n=k;
            return *sum;
        }
  friend istream & operator>>(istream &is,polynomial &p);
  friend ostream &operator<<(ostream &os , polynomial &p);
  polynomial operator +(polynomial &p);
};
istream & operator>>(istream &is,polynomial &p)
  {cout<<endl;
               cout<<"enter coefficent and exponent"<<endl;
               for(int i=0;i<p.n;i++)
               {cout<<"enter term "<<i+1<<": ";
                   cin>>p.t[i].coeff>>p.t[i].expo;

           }
           return is;
           }
ostream &operator<<(ostream &os , polynomial &p)
{
               cout<<endl;
               for(int i=0;i<p.n;i++)
               {
                   cout<<p.t[i].coeff<<"x"<<"^"<<p.t[i].expo;
                   if(i!=p.n-1)
                    cout<<"+";
               }
               cout<<endl;
               return os;
           }
polynomial polynomial::operator +(polynomial &p)
  {
            polynomial *sum=new polynomial(n+p.n);
            int i=0,j=0,k=0;
            while(i<n&&j<p.n)
            {
                if(t[i].expo>p.t[j].expo)
                    sum->t[k++]=t[i++];
                else if(t[i].expo<p.t[j].expo)
                    sum->t[k++]=p.t[j++];
                else
                {
                    sum->t[k].expo=t[i].expo;
                    sum->t[k++].coeff=t[i++].coeff+p.t[j++].coeff;
                }
            }
            for(;i<n;i++)
                sum->t[k++]=t[i];
            for(;j<p.n;j++)
                sum->t[k++]=p.t[j];
            sum->n=k;
            return *sum;
        }


int main()
{    cout<<"enter the no. of terms "<<endl;
     int t;
     cin>>t;
    polynomial p(t);
    cin>>p;
    cout<<"first polynomial";
    cout<<p;
    cout<<"enter the no. of terms "<<endl;
    cin>>t;
    polynomial p1(t);
    cin>>p1;
    cout<<"second polynomial";
    cout<<p1;
    polynomial sum=p+p1;
    cout<<endl<<"sum";
    cout<<sum;

}
