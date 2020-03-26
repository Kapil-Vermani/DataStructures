// Merge Sort in c++
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
using namespace std;

void merge(std::vector<int>& a,int s,int e)
{
      std::vector<int> temp(e-s+1);
      auto mid = (s+e)/2; 
      auto i = s;
      auto j =  mid+1;
      auto  k = 0;
      while( (i<=mid) && (j<=e))
      {
         if(a[i] <= a[j])
         {
            temp[k++] = a[i++];
         }
         else
         {
           temp[k++] = a[j++];
         }
      }
      while(i<=mid)
      {
            temp[k++]=a[i++];
      }
      while(j<=e)
      {
          temp[k++]=a[j++];
      }      
      auto idx = 0;
      for(int cntr=s;cntr<=e;cntr++)
      {
          a[cntr] = temp[idx++];
      }
}
void mergesort(std::vector<int>& a,int s,int e)
{
     if((e-s) <= 0)
     {
    	 return;
     }
     //divide
     int mid = (s+e)/2;
     //sort
     mergesort(a,s,mid);
     mergesort(a,mid+1,e);
     //merge
     merge(a,s,e);
}
int main() {
	srand(time(0));
	auto generated_rand_number = rand() % 20;
    while (generated_rand_number <=0)
    {
       generated_rand_number = rand()%20;
    }
	vector<int> input_vec(generated_rand_number);
	srand(time(0));	
    for(int i=0;i<generated_rand_number;i++)
	{
		auto temp = rand();
        input_vec[i] = temp;
	}
    std::cout<<"Array before sorting ...."<<std::endl;
    for(int i=0;i<input_vec.size();i++)
    {
        std::cout<<input_vec[i]<<"\t";
    }
    std::cout<<std::endl;
	mergesort(input_vec,0,generated_rand_number-1);	
    std::cout<<"Array after sorting... "<<std::endl;
    for(int i=0;i<input_vec.size();i++)
    {
        std::cout<<input_vec[i]<<"\t";
    } 
	return 0;
}
