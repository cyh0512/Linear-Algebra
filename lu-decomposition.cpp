#include <cstdlib>
#include <iostream>
#include <cmath>
using namespace std;
int main()
{
    int ques_case,array_row,array_col;
    double temp_element; 
    double array[10][10]={0.00};
    double array_copy[10][10]={0.00};
    double array_L[10][10]={0.00};
    double array_A[10][10]={0.00};
    bool A=true;
    cin>>ques_case;
    cout<<ques_case<<endl;
    for(int c=0;c<ques_case;c++)
    {
        for(int i=0;i<10;i++)
            for(int j=0;j<10;j++)
            {
                array_L[i][j]=0;
                array_A[i][j]=0;
            }
        for(int i=0;i<10;i++)
            array_A[i][i]=1.00;
    cin>>array_row>>array_col;
    // input array
    for(int i=0;i<array_row;i++)
    {
        for(int j=0;j<array_col;j++)
        {
            cin>>temp_element;
            array[i][j]=temp_element;
            array_copy[i][j]=temp_element;
        }

    }
    //do row substract
    double row_sub;
    for(int i=0;i<array_row-1;i++)
    {
        for(int j=i+1;j<array_row;j++)
        {
            if(array[i][i]==0.0) //check whether(n,n) is 0.
            {
                A=false;
                double temp_row[10]={0.00};
                double temp_row_A[10]={0.00};
                //init array to input data.
                for(int p=0;p<array_row;p++)
                {
                    for(int q=0;q<array_col;q++)
                    {
                        array[p][q]=array_copy[p][q];
                    }
                }
                //do row swap.
                for(int k=0;k<array_col;k++)
                {
                    int a=i+1;
                    temp_row[k]=array[i][k];
                    temp_row_A[k]=array_A[i][k];
                    if(i==array_row-1)
                        a=0;
                    array[i][k]=array[a][k];
                    array_A[i][k]=array_A[a][k];
                    array[a][k]=temp_row[k];
                    array_A[a][k]=temp_row_A[k];
                    //do array_A swap.
                }
                //init i and j.
                i=0;
                j=1;
            }
            row_sub=array[j][i]/array[i][i];
            array_L[j][i]=row_sub; //update array_L
            //cout<<row_sub<<endl; //for check
            //array_sub
            for(int k=0;k<array_col;k++)
            {   
                array[j][k]=array[j][k]-row_sub*array[i][k];
            }
        }
    }
    // print array
    if(A==1)
        cout<<"True"<<endl;
    else
    {
        cout<<"False"<<endl;
        cout<<array_row<<" "<<array_row<<endl;//print dimension
        for(int i=0;i<array_row;i++)
        {    for(int j=0;j<array_row;j++)
             {
                 cout<<array_A[i][j]<<" ";
             }
             cout<<endl;
        }
    }
    //cout<<"array L: "<<endl;
    cout<<array_row<<" "<<array_row<<endl;//print dimension
    for(int i=0;i<array_row;i++)
        array_L[i][i]=1.00; // set 1 at(n,n) in array_L.
    for(int i=0;i<array_row;i++)
    {
        for(int j=0;j<array_row;j++)
        {
            cout<<round(array_L[i][j]*100)/100<<" ";
        }
        cout<<endl;
    }
    //cout<<"array U: "<<endl;
    cout<<array_row<<" "<<array_col<<endl;//print dimension
    for(int i=0;i<array_row;i++)
    {
        for(int j=0;j<array_col;j++)
        {
            cout<<array[i][j]<<" ";
        }
        cout<<endl;
    }
    }
    return 0;
}
