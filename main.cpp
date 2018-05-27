#include <iostream>

using namespace std;

float average(int array_size, float *numbers)
{
    float sum = 0;
    for(int i=0; i<array_size; i++)
    {
        cout<<"Type "<<i+1<<" number: "<<endl;
        cin >>*numbers;
        sum += *numbers;
        numbers++;
    }
    return sum/array_size;
}

int main()
{
    float *arr;
    arr=new float[5];
    cout <<"Average: "<<average(5,arr);
    return 0;
}
