#include <iostream>

using namespace std;

void user_input(int array_size, float *numbers)
{
    for(int i=0; i<array_size; i++)
    {
        cout<<"Type "<<i+1<<" number: "<<endl;
        cin >>*numbers;
        numbers++;
    }
}

float average(int array_size, float *numbers)
{
    float sum = 0;
    for(int i=0; i<array_size; i++)
    {
        sum += *numbers;
        numbers++;
    }
    return sum/array_size;
}
float max_number(int array_size, float *numbers)
{
    float highest=*numbers;
    numbers++;
    for(int i =1; i<array_size; i++)
    {
        if(*numbers>highest){highest=*numbers;}
        numbers++;
    }
    return highest;
}
float close_to_ave(int array_size, float ave, float *numbers)
{
    float *sec_arr, *w, lowest_dif,closest_to_ave;
    sec_arr = new float[array_size];
    w=sec_arr;

    for(int i=0; i<array_size; i++)
    { /// tutaj skoñczy³em
        if((ave-*numbers)<0)
        {
            *w=(ave-*numbers)*(-1);
        }
        else
        {
            *w=ave-*numbers;
        }
        if(i==0)
        {
            lowest_dif=*w;
            closest_to_ave=*numbers;
        }
        else if (i>0 && *w<lowest_dif)
        {
            lowest_dif=*w;
            closest_to_ave=*numbers;
        }
        cout<<*w<<endl;
        w++;
        numbers++;
    }
    return closest_to_ave;
}
int main()
{
    float *arr;
    arr=new float[5];

    user_input(5,arr);
    cout <<"Average: "<<average(5,arr)<<endl;
    cout <<"The biggest number is: "<<max_number(5,arr)<<endl;
    cout<<"Number closest to average: "<<close_to_ave(5,average(5,arr),arr);

    return 0;
}
