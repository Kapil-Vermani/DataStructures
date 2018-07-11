#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
	// your code goes here
	std::vector<int> v = {3,4,5,6,7,8,9};
	auto found = std::binary_search(v.begin(),v.end(),10);
	if(found)
	{
		std::cout<<"Element found "<<std::endl;
	}
	else
	{
		std::cout<<"Element not found "<<std::endl;
	}
	auto itr = std::lower_bound(v.begin(),v.end(),6);
	if(itr != v.end())
	{
	   if(*itr == 6)
	   {
		auto pos = itr - v.begin();
		std::cout<<"Element found at position "<<pos<<std::endl;
	   }
	   else
	   {
	   	std::cout<<"Element not found ..."<<std::endl;
	   }
	   
	}
	else
	{
		std::cout<<"Element not found ..."<<std::endl;
	}
	
	
	return 0;
}