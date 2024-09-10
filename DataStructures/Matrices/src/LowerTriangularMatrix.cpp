// P.S. This file will be refactored.


#include<iostream>
using namespace std;

class LowerTriangularMatrix
{

public:

	LowerTriangularMatrix()
		: size_{2}
	{
		A_ = new int[size_*(size_+1)/2] {1,1,1};
	}

	LowerTriangularMatrix(int sz)
	{
		size_ = sz;
		A_ = new int[size_*(size_+1)/2] {};
	}

	void set(int m, int n, int v)
	{
		m++; n++;
		if(m > size_ || n > size_)
			throw runtime_error("index out of bounds");
		if(m < n)
			return;

		A_[(m*(m-1)/2) + n-1] = v;
	}

	int get(int m, int n)
	{
		m++; n++;
		if(m > size_ || n > size_)
			throw runtime_error("index out of bounds");
		if(m >= n)
			return 	A_[(m*(m-1)/2)+n-1];
		else
			return 0;
	}

	void display()
	{
		int k = 0;
		for(int i = 0; i < size_; i++)
		{
			for(int j = 0; j < size_; j++)
			{
				if(i >= j)
				{
					cout << A_[k] << ' ';
					k++;
				}
				else
					cout << '0' << ' ';
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
	LowerTriangularMatrix matrix(5);
	matrix.set(4,4, 3);
	matrix.display();
	cout << endl;
	cout << matrix.get(1,1);

	return 0;
}