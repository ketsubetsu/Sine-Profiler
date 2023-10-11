/**
 * A program to profile sine approximation algorithms that use 
 * the Taylor series expansion of the sine function: 
 * sine(x) = x - x^3/3! + x^5/5! - x^7/7! + x^9/9! .....   
 * @author ketsubetsu
 * @see SineUtil.h
 * <pre>
 * File:SineProfiler.cpp
 * </pre>
 */
 
#include <iostream>
#include <chrono>
#include <iomanip>

#include "SineUtil.h"

using namespace std;
using namespace std::chrono;

int main()
{
    double x;
    double n;
    cout<<"Please enter an angle θ in radians: ";
    cin>>x;
    cout<<endl;
    
    cout<<"naiveSine("<<x<<") = "<<SineUtil::naiveSine(x, n = 100)<<endl;
    cout<<"fastSine("<<x<<") = "<<SineUtil::fastSine(x, n = 100)<<endl<<endl;
    
    cout<<"n"<<setw(30)<<"Naive Time(μs)"<<setw(19)<<"Fast Time(μs)"<<setfill(' ')<<endl;
    cout<<setfill('-')<<setw(48)<<'-'<<endl;
    
    n = 1000;
    
    for(int i = 1; i <= 15; i++)
    {
        auto start = chrono::high_resolution_clock::now();
        SineUtil::naiveSine(x, n);
        auto elapsed = chrono::high_resolution_clock::now() - start;
        long nTime = chrono::duration_cast<std::chrono::nanoseconds>(elapsed).count();
    
        start = chrono::high_resolution_clock::now();
        SineUtil::fastSine(x, n);
        elapsed = chrono::high_resolution_clock::now() - start;
        long fTime = chrono::duration_cast<std::chrono::nanoseconds>(elapsed).count();
        
        cout<<setfill(' ')<<setw(5)<<n<<"|"<<setfill(' ')<<left<<setw(20)<<right<<nTime<<"|"<<setw(20)<<right<<fTime<<"|"<<endl;
        
        n = n + 1000;
    }
	return 0;
}