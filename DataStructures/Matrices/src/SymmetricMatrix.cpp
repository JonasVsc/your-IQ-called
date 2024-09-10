// P.S. This file will be refactored.

#include<iostream>
using namespace std;

class SymmetricMatrix
{

public:

	SymmetricMatrix()
		: size_{2}
	{
		A_ = new int[size_*(size_+1)/2] {1,1,1};
	}

	SymmetricMatrix(int sz)
	{
		size_ = sz;
		A_ = new int[size_*(size_+1)/2] {};
	}

	void set(int i, int j, int v)
	{
		i++; j++;
		if(i > size_ || j > size_)
			throw runtime_error("index out of bounds");
		A_[(i*(i-1)/2) + j-1] = v;
	}

	int get(int i, int j)
	{
		i++; j++;
		if(i > size_ || j > size_)
			throw runtime_error("index out of bounds");
		if(i >= j)
			return 	A_[(i*(i-1)/2)+j-1];
		else
			return 	A_[(j*(j-1)/2)+i-1];
	}

	void display()
	{
		int k = 0;
		for(int i = 1; i < size_ + 1; i++)
		{
			for(int j = 1; j < size_ + 1; j++)
			{
				if(i>= j)
					cout << A_[(i*(i-1)/2)+j-1] << ' ';
				else
					cout << A_[(j*(j-1)/2)+i-1] << ' ';
			}
			cout << endl;
		}
	}


private:
	int* A_;
	int size_;


};


int main()
{
	SymmetricMatrix matrix(5);

	matrix.set(0,0, 5);
	matrix.set(1,0, 2);
	matrix.set(3,1, 7);
	matrix.set(4,2, 3);
	matrix.set(4,4, 3);

	matrix.display();

	cout << "get " << matrix.get(0,1) << '\n';
	return 0;
}