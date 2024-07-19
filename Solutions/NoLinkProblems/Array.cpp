#include<iostream>
#include<array>


// 01
template<int N>
void FindSingleMissingElementInASequence(std::array<int, N>& arr);

// 01.2
template<int N>
void FindSingleMissingElementInASequenceNotFromBegin(std::array<int, N>& arr);

// 02
template<int N>
void FindMultipleMissingElementInASequence(std::array<int, N>& arr);

// 03 / Hashtable/Bitset
template<int N>
void FindMissingElements(std::array<int, N>& arr);

// 04
template<int N>
void FindDuplicateElements(std::array<int, N>& arr);


int main()
{
	return 0;
}




// Solutions


// 01
template<int N>
void FindSingleMissingElementInASequence(std::array<int, N>& arr)
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
void FindSingleMissingElementInASequenceNotFromBegin(std::array<int, N>& arr)
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
void FindMultipleMissingElementInASequence(std::array<int, N>& arr)
{
	int low = arr[0];
	for (int i = 0; i < arr.size(); i++)
	{
		if (arr[i] - (low + i) != 0)
		{
			std::cout << "Missing element: " << low + i << std::endl;
			low++;
		}
	}
}


// 03
template<int N>
void FindMissingElements(std::array<int, N>& arr)
{
	std::array<int, 50> miss_arr{};
	int low, high;
	low = high = arr[0];

	for (int i = 0; i < arr.size(); i++)
	{
		miss_arr[arr[i]] = 1;

		if (low > arr[i])
			low = arr[i];

		if (high < arr[i])
			high = arr[i];
	}

	for (int j = low; j < high; j++)
	{
		if (miss_arr[j] == 0)
			std::cout << "Miss Element: " << j << std::endl;
	}
}


// 04
template<int N>
void FindDuplicateElements(std::array<int, N>& arr)
{
	
}