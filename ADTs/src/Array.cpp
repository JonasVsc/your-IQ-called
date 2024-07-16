#include<iostream>

// Definition of the Array data structure
struct Array
{

	int A[20];  // Fixed-size array to store elements
	int size;   // Maximum size of the array
	int length; // Current number of elements in the array


	// Display elements of the array
	void Display() const
	{
		std::cout << "Array: ";
		for (int i = 0; i < length; i++)
			std::cout << A[i] << ' ';
		std::cout << std::endl;
	}
	
	// Get the value at a specific index
	int Get(int index) const
	{
		if (index >= 0 && index < length)
			return A[index];
		else
			std::cout << "Out of range" << std::endl;
	}
	
	// Set the value at a specific index
	void Set(int index, int value)
	{
		if (index >= 0 && index < length)
		{
			A[index] = value;
		}
	}
	
	// Find the maximum value in the array
	int Max() const
	{
		int max = A[0];

		for (int i = 0; i < length; i++)
		{
			if (max < A[i]) 
				max = A[i];
		}
		return max;
	}
	
	// Find the minimum value in the array
	int Min() const
	{
		int min = A[0];
		for (int i = 0; i < length; i++)
		{
			if (min > A[i])
				min = A[i];
		}
		return min;
	}
	
	// Calculate the sum of all elements in the array
	int Sum() const
	{
		int total = 0;
		for (int i = 0; i < length; i++)
		{
			total += A[i];
		}
		return total;
	}
	
	// Calculate the average of all elements in the array
	float Avg() const
	{
		return static_cast<float>(Sum() / length);
	}
	
	// Check if the array is sorted in ascending order
	bool isSorted() const
	{
		for (int i = 0; i < length - 1; i++)
		{
			if (A[i + 1] < A[i])
				return false;
		}
		return true;
	}
	
	// Linear search for a value in the array
	static void LinearSearch(const struct Array& arr, int value)
	{ 
		for (int i = 0; i < arr.length; i++)
		{
			if (arr.A[i] == value)
			{
				std::cout << "Found at index " << i << std::endl;
				return;
			}
		}
		std::cout << "Not Found!" << std::endl;
	}

	// Binary search for a value in the array (requires sorted array)
	static void BinarySearch(const struct Array& arr, int value) 
	{

		int low = 0;
		int high = arr.length - 1;
		int mid = (low + high) / 2;

		while (low < high)
		{
			if (value > arr.A[mid])
			{
				low = mid + 1;
				mid = (low + high) / 2;
			}
			else if ( value < arr.A[mid])
			{
				high = mid - 1;
				mid = (low + high) / 2;
			}

			if (arr.A[mid] == value)
			{
				std::cout << "Found value at index: " << mid << std::endl;
				return;
			}
		}
		std::cout << "Value not found" << std::endl;
	}
	
	// Delete an element at a specific index
	void Delete(int index)
	{
		if (index > length - 1)
		{
			std::cout << "Error, Invalid index!\n";
			return;
		}

		for (int i = index; i < length - 1; i++)
		{
			A[i] = A[i + 1];
		}
		length--;
	}

	// Append a value to the end of the array
	void Append(int x)
	{
		if (isFull())
		{
			std::cout << "Error, array is full!\n";
			return;
		}
		A[length++] = x;
	}

	// Insert a value at a specific index
	void Insert(int index, int x)
	{
		if (isFull())
		{
			std::cout << "Error, array is full!\n";
			return;
		}

		for (int i = length++; i > index; --i)
		{
			A[i] = A[i - 1];
		}
		A[index] = x;
	}

	// Remove the first element and shift all other elements to the left
	int Shift()
	{
		int x = A[0];

		for (int i = 0; i < length - 1; i++)
		{
			A[i] = A[i + 1];
		}
		A[length - 1] = 0;
		return x;
	}

	// Rotate the array left by one position
	void Rotate()
	{
		int x = A[0];
		for (int i = 0; i < length - 1; i++)
		{
			A[i] = A[i + 1];
		}
		A[length - 1] = x;
	}

	// Reverse the elements of the array
	void Reverse()
	{
		int i = 0;
		int j = length - 1;
		while(i != j)
		{
			int temp = A[i];
			A[i] = A[j];
			A[j] = temp;

			i++; j--;
		}
	}
	
	// Check if the array is full
	bool isFull() const
	{
		if (size == length)
		{
			return true;
		}
		return false;
	}

	// Check if the array is empty
	bool isEmpty() const
	{
		if (size == 0)
		{
			return true;
		}
		return false;
	}

};



int main()
{
	struct Array arr { { 1, 5, 40, 200, 343, 660, 9999 }, 10, 7 };
	arr.Display();

	return 0;
}