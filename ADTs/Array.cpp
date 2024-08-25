#include<iostream>

// Definition of the Array data structure
class Array
{
private:
	int *A;     // Fixed-size array to store elements
	int size;   // Maximum size of the array
	int length; // Current number of elements in the array

public:

	Array();

	Array(int sz);

	~Array();

	// Display elements of the array
	void Display() const;

	// Get the value at a specific index
	int Get(int index) const;

	// Set the value at a specific index
	void Set(int index, int value);

	// Find the maximum value in the array
	int Max() const;

	// Find the minimum value in the array
	int Min() const;

	// Calculate the sum of all elements in the array
	int Sum() const;

	// Calculate the average of all elements in the array
	float Avg() const;

	// Check if the array is sorted in ascending order
	bool isSorted() const;

	// Linear search for a value in the array
	void LinearSearch(int value);

	// Binary search for a value in the array (requires sorted array)
	void BinarySearch(int value);

	// Delete an element at a specific index
	void Delete(int index);

	// Append a value to the end of the array
	void Append(int x);

	// Insert a value at a specific index
	void Insert(int index, int x);

	// Insert a value at a specific index (requires sorted array)
	void InsertSort(int value);

	// Remove the first element and shift all other elements to the left
	int Shift();

	// Rotate the array left by one position
	void Rotate();

	// Reverse the elements of the array
	void Reverse();

	// Check if the array is full
	bool isFull() const;

	// Check if the array is empty
	bool isEmpty() const;

	// Merge for sorted arrays
	Array* Merge(const Array& arr2);
};



int main()
{
	Array arr1;
	std::string log;
	while (true)
	{
		std::cout
			<< "0 - Append" << std::endl
			<< "1 - Delete" << std::endl
			<< "2 - LinearSearch" << std::endl
			<< "3 - BinarySearch" << std::endl
			<< "4 - Insert" << std::endl
			<< "5 - Shift" << std::endl
			<< "6 - Rotate" << std::endl
			<< "7 - Reverse" << std::endl
			<< "8 - Average" << std::endl
			<< "9 - Exit" << std::endl << std::endl;
		arr1.Display();
		std::cout << std::endl;
		std::cout << log << std::endl << std::endl;
		std::cout << "__: ";
		int ch, x, i;
		std::cin >> ch;

		switch (ch)
		{
		case 0:
			std::cin >> x;
			arr1.Append(x);
			break;
		case 1:
			std::cin >> x;
			arr1.Delete(x);
			break;
		case 2:
			std::cin >> x;
			arr1.LinearSearch(x);
			system("pause");
			break;
		case 3:
			std::cin >> x;
			arr1.BinarySearch(x);
			system("pause");
			break;
		case 4:
			std::cin >> i >> x;
			arr1.Insert(i, x);
			break;
		case 5:
			arr1.Shift();
			break;
		case 6:
			arr1.Rotate();
			break;
		case 7:
			arr1.Reverse();
			break;
		case 8:
			std::cout << "Average: " << arr1.Avg() << std::endl;
			system("pause");
			break;
		case 9:
			return 0;
		}

		system("cls");
	}
	

	arr1.Display();

	return 0;
}



Array::Array()
{
	size = 10;
	length = 0;
	A = new int[size];
}

Array::Array(int sz)
{
	size = sz;
	length = 0;
	A = new int[size];
}

Array::~Array()
{
	delete[]A;
}

// Display elements of the array
void Array::Display() const
{
	std::cout << "Array: ";
	for (int i = 0; i < length; i++)
		std::cout << A[i] << ' ';
	std::cout << std::endl;
}

// Get the value at a specific index
int Array::Get(int index) const
{
	if (index >= 0 && index < length)
		return A[index];
	else
		std::cout << "Out of range" << std::endl;
}

// Set the value at a specific index
void Array::Set(int index, int value)
{
	if (index >= 0 && index < length)
	{
		A[index] = value;
	}
}

// Find the maximum value in the array
int Array::Max() const
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
int Array::Min() const
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
int Array::Sum() const
{
	int total = 0;
	for (int i = 0; i < length; i++)
	{
		total += A[i];
	}
	return total;
}

// Calculate the average of all elements in the array
float Array::Avg() const
{
	if (length == 0)
		return 0;
	return static_cast<float>(Sum() / length);
}

// Check if the array is sorted in ascending order
bool Array::isSorted() const
{
	for (int i = 0; i < length - 1; i++)
	{
		if (A[i + 1] < A[i])
			return false;
	}
	return true;
}

// Linear search for a value in the array
void Array::LinearSearch(int value)
{
	for (int i = 0; i < length; i++)
	{
		if (A[i] == value)
		{
			std::cout << "Found at index " << i << std::endl;
			return;
		}
	}
	std::cout << "Not Found!" << std::endl;
}

// Binary search for a value in the array (requires sorted array)
void Array::BinarySearch(int value)
{

	int low = 0;
	int high = length - 1;
	int mid = (low + high) / 2;

	while (low < high)
	{
		if (value > A[mid])
		{
			low = mid + 1;
			mid = (low + high) / 2;
		}
		else if (value < A[mid])
		{
			high = mid - 1;
			mid = (low + high) / 2;
		}

		if (A[mid] == value)
		{
			std::cout << "Found value at index: " << mid << std::endl;
			return;
		}
	}
	std::cout << "Value not found" << std::endl;
}

// Delete an element at a specific index
void Array::Delete(int index)
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
void Array::Append(int x)
{
	if (isFull())
	{
		std::cout << "Error, array is full!\n";
		return;
	}
	A[length++] = x;
}

// Insert a value at a specific index
void Array::Insert(int index, int x)
{
	if (index < 0 || index > length)
	{
		std::cout << "Error, invalid index\n";
		return;
	}

	for (int i = length++; i > index; --i)
	{
		A[i] = A[i - 1];
	}
	A[index] = x;
}

void Array::InsertSort(int value)
{
	if (isFull())
	{
		std::cout << "Error, array is full!\n";
		return;
	}
	int i{};
	for (i = length - 1; i >= 0 && A[i] > value; i--)
	{
		A[i + 1] = A[i];
	}
	A[i + 1] = value;
	length++;
}

// Remove the first element and shift all other elements to the left
int Array::Shift()
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
void Array::Rotate()
{
	int x = A[0];
	for (int i = 0; i < length - 1; i++)
	{
		A[i] = A[i + 1];
	}
	A[length - 1] = x;
}

// Reverse the elements of the array
void Array::Reverse()
{
	int i = 0;
	int j = length - 1;
	while (i < j)
	{
		int temp = A[i];
		A[i] = A[j];
		A[j] = temp;

		i++; 
		j--;
	}
}

// Check if the array is full
bool Array::isFull() const
{
	if (size == length)
	{
		return true;
	}
	return false;
}

// Check if the array is empty
bool Array::isEmpty() const
{
	if (length == 0)
	{
		return true;
	}
	return false;
}

// Merge for sorted arrays
Array* Array::Merge(const Array& arr2)
{
	Array* res = new Array(size + arr2.size);

	int i, j, k;
	i = j = k = 0;
	for (; i < length && j < arr2.length; k++)
	{
		if (A[i] < arr2.A[j])
		{
			res->A[k] = A[i];
			i++;
		}
		else
		{
			res->A[k] = arr2.A[j];
			j++;
		}
	}

	for (; i < length; i++, k++)
		res->A[k] = A[i];
	for (; j < arr2.length; j++, k++)
		res->A[k] = arr2.A[j];

	return res;
}