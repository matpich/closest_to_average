#include <iostream>

using namespace std;

void user_input(int array_size, float *numbers); //takes input from the user

float average(int array_size, float *numbers); //returns an average of input numbers

float max_number(int array_size, float *numbers); //finds the biggest number

float close_to_ave(int array_size, float ave, float *numbers); //finds the number closest to average

int main()
{
    const int five_numbers = 5; //it's my choice to get only 5 numbers from user, so I define "5" as a constant
    float *arr;
    arr=new float[five_numbers];

    user_input(5,arr);
    cout <<"Average: "<<average(five_numbers,arr)<<endl;
    cout <<"The biggest number is: "<<max_number(five_numbers,arr)<<endl;
    cout<<"Number closest to average: "<<close_to_ave(five_numbers,average(five_numbers,arr),arr);

    delete [] arr;
    return 0;
}

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
    float highest=*numbers; //I assume that first number is the biggest one, next I compare values in the loop
    numbers++;
    for(int i =1; i<array_size; i++) //I don't need first value so I start with "i=1"
    {
        if(*numbers>highest){highest=*numbers;}
        numbers++;
    }
    return highest;
}
float close_to_ave(int array_size, float ave, float *numbers)
{
    float *w, lowest_dif,closest_to_ave;
    w = new float[array_size];

    for(int i=0; i<array_size; i++)
    {
        if((ave-*numbers)<0)
        {
            *w=(ave-*numbers)*(-1);
        }
        else
        {
            *w=ave-*numbers;
        }
        if(i==0) //same tick as in "max_number" function, but now I can't assign values before loop, so I used if statement to handle with this problem
        {
            lowest_dif=*w;
            closest_to_ave=*numbers;
        }
        else if (i>0 && *w<lowest_dif)
        {
            lowest_dif=*w;
            closest_to_ave=*numbers;
        }
        w++;
        numbers++;
    }
    delete [] w;
    return closest_to_ave;
}
