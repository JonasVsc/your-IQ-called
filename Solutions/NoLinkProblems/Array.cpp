#include<iostream>
#include<array>


// 01
template<int N>
void FindingSingleMissingElementInASequence(std::array<int, N>& arr);


// 02
template<int N>
void FindingMultipleMissingElementInASequence(std::array<int, N>& arr);


int main()
{
	FindingSingleMissingElementInASequence(std::array<int, 7> {1, 2, 3, 4, 6, 7, 8});
	return 0;
}












// Solutions


// 01
template<int N>
void FindingSingleMissingElementInASequence(std::array<int, N>& arr)
{
	int sum = 0;

	for (const auto& i : arr)
	{
		sum = sum + i;
	}
	std::cout << "Sum of array = " << sum << std::endl;

	int n = arr.at(arr.size() - 1);
	int S = (n * (n + 1)) / 2;
	std::cout << "Sum of the sequence without missing elements is " << S << std::endl;
	std::cout << "Missing element is " << S << " - " << sum << " = " << S - sum << std::endl;
}


// 02
template<int N>
void FindingMultipleMissingElementInASequence(std::array<int, N>& arr)
{

}