#include<iostream>
#include<array>


// 01
template<int N>
void FindingSingleMissingElementInASequence(std::array<int, N>& arr);

// 01.2
template<int N>
void FindingSingleMissingElementInASequenceNotFromBegin(std::array<int, N>& arr);


// 02
template<int N>
void FindingMultipleMissingElementInASequence(std::array<int, N>& arr);


int main()
{
	FindingSingleMissingElementInASequenceNotFromBegin(std::array<int, 7> {12, 13, 14, 15, 17, 18, 19});
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

// 01.2
template<int N>
void FindingSingleMissingElementInASequenceNotFromBegin(std::array<int, N>& arr)
{
	int low = arr[0];
	for (int i = 0; i < arr.size(); i++)
	{
		if (arr[i] - low - i != 0)
		{
			int n = low + i;
			std::cout << "Missing element is " << n << std::endl;
			break;
		}
	}
}


// 02
template<int N>
void FindingMultipleMissingElementInASequence(std::array<int, N>& arr)
{

}