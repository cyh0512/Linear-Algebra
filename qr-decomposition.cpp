#include <cmath>
#include <iostream>
#include <fstream>
#include <cstdlib>
using namespace std;
double innerproduct(double inner_a[],double inner_b[])
{
    double output1=0.00;
    double output2=0.00;
    double output=0.00;
    for(int s=0;s<10;s++){
        output1=output1+inner_a[s]*inner_b[s];
        output2=output2+inner_b[s]*inner_b[s];
    }
    output=output1/output2;
    return output;
}

int main(){

    int cases,m,n;
    
    ifstream infile("input.txt",ios::in);
    if(!infile){
        cerr<<"failed opening"<<endl;
        exit(1);
    }
    ofstream outfile("output.txt",ios::out);
    if(!outfile)
    {
        cerr<<"failed opening"<<endl;
        exit(1);
    }

    infile>>cases;
    for(int c=0;c<cases;c++) //load cases
    {
        double A[10][10]={0.00};
        double u[10][10]={0.00};
        double r[10][10]={0.00};
        double u_length[10]={0.00};
        /*
        double u1_length=0.00;
        double u2_length=0.00;
        double u3_length=0.00;
        */
        for(int i=0;i<10;i++)
            r[i][i]=1.00;
        double inner1[10]={0.00};
        double inner2[10]={0.00};
        infile>>m>>n;        //update m,n,A[][]
        for(int i=0;i<m;i++)
            for(int j=0;j<n;j++)
                infile>>A[i][j];

        for(int i=0;i<m;i++)
        {
            u[i][0]=A[i][0]; //compute u1
        }
                for(int i=0;i<m;i++)
                {
                    inner1[i]=A[i][1]; //assign v2
                    inner2[i]=u[i][0]; //assign u1
                }
                r[0][1]=innerproduct(inner1,inner2);
                for(int i=0;i<m;i++)
                    u[i][1]=A[i][1]-r[0][1]*u[i][0]; //compute u2
                
                for(int i=0;i<m;i++)
                {
                    inner1[i]=A[i][2];
                    inner2[i]=u[i][0];
                }
                r[0][2]=innerproduct(inner1,inner2);
                for(int i=0;i<m;i++)
                {
                    inner1[i]=A[i][2];
                    inner2[i]=u[i][1];
                }
                r[1][2]=innerproduct(inner1,inner2);
                for(int i=0;i<m;i++)
                    u[i][2]=A[i][2]-r[0][2]*u[i][0]-r[1][2]*u[i][1]; //compute u3
                
                for(int i=0;i<m;i++)
                {
                    inner1[i]=A[i][3];
                    inner2[i]=u[i][0];
                }
                r[0][3]=innerproduct(inner1,inner2);
                for(int i=0;i<m;i++)
                {
                    inner1[i]=A[i][3];
                    inner2[i]=u[i][1];
                }
                r[1][3]=innerproduct(inner1,inner2);
                for(int i=0;i<m;i++)
                {
                    inner1[i]=A[i][3];
                    inner2[i]=u[i][2];
                }
                r[2][3]=innerproduct(inner1,inner2);
                for(int i=0;i<m;i++)
                    u[i][3]=A[i][3]-r[0][3]*u[i][0]-r[1][3]*u[i][1]-r[2][3]*u[i][2]; //compute u4

                for(int i=0;i<m;i++)
                {
                    inner1[i]=A[i][4];
                    inner2[i]=u[i][0];
                }
                r[0][4]=innerproduct(inner1,inner2);
                for(int i=0;i<m;i++)
                {
                    inner1[i]=A[i][4];
                    inner2[i]=u[i][1];
                }
                r[1][4]=innerproduct(inner1,inner2);
                for(int i=0;i<m;i++)
                {
                    inner1[i]=A[i][4];
                    inner2[i]=u[i][2];
                }
                r[2][4]=innerproduct(inner1,inner2);
                for(int i=0;i<m;i++)
                {
                    inner1[i]=A[i][4];
                    inner2[i]=u[i][3];
                }
                r[3][4]=innerproduct(inner1,inner2);

                for(int i=0;i<m;i++)
                    u[i][4]=A[i][4]-r[0][4]*u[i][0]-r[1][4]*u[i][1]-r[2][4]*u[i][2]-r[3][4]*u[i][3]; //compute u5

                for(int g=0;g<5;g++)
                {
                    for(int i=0;i<m;i++)
                    {
                        inner1[i]=A[i][5];
                        inner2[i]=u[i][g];
                    }
                    r[g][5]=innerproduct(inner1,inner2);
                }
                for(int i=0;i<m;i++)
                    u[i][5]=A[i][5]-r[0][5]*u[i][0]-r[1][5]*u[i][1]-r[2][5]*u[i][2]-r[3][5]*u[i][3]-r[4][5]*u[i][4]; //compute u6


    for(int g=0;g<6;g++)
    {
        for(int i=0;i<m;i++)
        {
            inner1[i]=A[i][6];
            inner2[i]=u[i][g];
        }
        r[g][6]=innerproduct(inner1,inner2);
    }
    for(int i=0;i<m;i++)
        u[i][6]=A[i][6]-r[0][6]*u[i][0]-r[1][6]*u[i][1]-r[2][6]*u[i][2]-r[3][6]*u[i][3]-r[4][6]*u[i][4]-r[5][6]*u[i][5]; //compute u7


    for(int g=0;g<7;g++)
    {
        for(int i=0;i<m;i++)
        {
            inner1[i]=A[i][7];
            inner2[i]=u[i][g];
        }
        r[g][7]=innerproduct(inner1,inner2);
    }
    for(int i=0;i<m;i++)
        u[i][7]=A[i][7]-r[0][7]*u[i][0]-r[1][7]*u[i][1]-r[2][7]*u[i][2]-r[3][7]*u[i][3]-r[4][7]*u[i][4]-r[5][7]*u[i][5]-r[6][7]*u[i][6]; //compute u8

    for(int g=0;g<8;g++)
    {
        for(int i=0;i<m;i++)
        {
            inner1[i]=A[i][8];
            inner2[i]=u[i][g];
        }
        r[g][8]=innerproduct(inner1,inner2);
    }
    for(int i=0;i<m;i++)
        u[i][8]=A[i][8]-r[0][8]*u[i][0]-r[1][8]*u[i][1]-r[2][8]*u[i][2]-r[3][8]*u[i][3]-r[4][8]*u[i][4]-r[5][8]*u[i][5]-r[6][8]*u[i][6]-r[7][8]*u[i][7]; //compute u9

    
    for(int g=0;g<9;g++)
    {
        for(int i=0;i<m;i++)
        {
            inner1[i]=A[i][9];
            inner2[i]=u[i][g];
        }
        r[g][9]=innerproduct(inner1,inner2);
    }
    for(int i=0;i<m;i++)
        u[i][9]=A[i][9]-r[0][9]*u[i][0]-r[1][9]*u[i][1]-r[2][9]*u[i][2]-r[3][9]*u[i][3]-r[4][9]*u[i][4]-r[5][9]*u[i][5]-r[6][9]*u[i][6]-r[    7][9]*u[i][7]-r[8][9]*u[i][8]; //compute u10



                //Q,R array divided by u_length
                for(int j=0;j<10;j++)
                    for(int i=0;i<m;i++) 
                        u_length[j]=u_length[j]+u[i][j]*u[i][j];
                for(int i=0;i<10;i++)
                    u_length[i]=pow(u_length[i],0.5);

                //output for all n
                cout<<m<<" "<<n<<endl; //first array
                outfile<<m<<" "<<n<<endl;
                for(int i=0;i<m;i++)
                {
                    for(int j=0;j<n;j++)
                    {
                    cout<<round(u[i][j]/u_length[j]*100)/100<<" ";
                    outfile<<round(u[i][j]/u_length[j]*100)/100<<" ";
                    }
                    cout<<endl;
                    outfile<<endl;
                }
                cout<<n<<" "<<n<<endl; //second array
                outfile<<n<<" "<<n<<endl;
                for(int i=0;i<n;i++)
                {
                    for(int j=0;j<n;j++)
                    {
                        cout<<round(r[i][j]*u_length[i]*100)/100<<" ";
                        outfile<<round(r[i][j]*u_length[i]*100)/100<<" ";
                    }
                    cout<<endl;
                    outfile<<endl;
                }
    }

    return 0;
}
