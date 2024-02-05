
#include <iostream>
using namespace std;

template<class T>
class Matrix
{
private:
    T** matrix;
    int ROWS;
    int COLS;
public:
    
    Matrix() : matrix{ nullptr }, ROWS{ 0 }, COLS{ 0 } {}
    Matrix(int rows, int cols) : ROWS{ rows }, COLS{ cols }
    {
        matrix = new T * [ROWS];
        for (int i = 0; i < ROWS; i++)
        {
            matrix[i] = new T[COLS];
        }
    }
   
    Matrix(const Matrix& matrix2) : ROWS{ matrix2.ROWS }, COLS{ matrix2.COLS }
    {
        matrix = new T * [ROWS];
        for (int i = 0; i < ROWS; i++)
        {
            matrix[i] = new T[COLS];
            for (int j = 0; j < COLS; j++)
            {
                matrix[i][j] = matrix2.matrix[i][j];
            }
        }
    }
    ~Matrix()
    {
        for (int i = 0; i < ROWS; i++)
        {
            delete[]matrix[i];
        }
        delete[]matrix;
    }

    void fill_random()
    {
        srand(time(NULL));
        for (int i = 0; i < ROWS; i++)
        {
            for (int j = 0; j < COLS; j++)
            {
                matrix[i][j] = rand() % 10;
            }
        }
    }

    friend istream& operator>>(istream& in, Matrix& mat)
    {
        for (int i = 0; i < mat.ROWS; i++)
        {
            for (int j = 0; j < mat.COLS; j++)
            {
                in >> mat.matrix[i][j];
            }
        }
        return in;
    }

    friend ostream& operator<<(ostream& out, Matrix& mat)
    {
        for (int i = 0; i < mat.ROWS; i++)
        {
            for (int j = 0; j < mat.COLS; j++)
            {
                out << mat.matrix[i][j]<<' ';
            }
            out << endl;
        }
        return out;
    }

    void operator+(Matrix& matrix2)
    {
        for (int i = 0; i < ROWS; i++)
        {
            for (int j = 0; j < COLS; j++)
            {
                matrix[i][j] += matrix2.matrix[i][j];
            }
        }  
    }

    void operator-(Matrix& matrix2)
    {
        for (int i = 0; i < ROWS; i++)
        {
            for (int j = 0; j < COLS; j++)
            {
                matrix[i][j] -= matrix2.matrix[i][j];
            }
        }
    }

    void operator*(Matrix& matrix2)
    {
        for (int i = 0; i < ROWS; i++)
        {
            for (int j = 0; j < COLS; j++)
            {
                matrix[i][j] *= matrix2.matrix[i][j];
            }
        }
    }

    void operator/(Matrix& matrix2)
    {
        int zero_finder = 0;// шукаємо, чи є в масиві на який ми будемо ділити  0, якщо так, то виводимо помилку;
        for (int i = 0; i < matrix2.ROWS; i++)
        {
            for (int j = 0; j < matrix2.COLS; j++)
            {
                {
                    if (matrix2.matrix[i][j] == 0)
                    {
                        zero_finder++;
                    }
                }

            }
        }
        if (zero_finder == 0)
        {
            for (int i = 0; i < ROWS; i++)
            {
                for (int j = 0; j < COLS; j++)
                {
                    {
                        matrix[i][j] /= matrix2.matrix[i][j];
                    }

                }
            }
        }
        else 
        {
            cout << "\nError!\nDevision by zero is impossible"<<endl;
        }
    }
    void show_max()
    {
        T max = matrix[0][0];
        for (int i = 0; i < ROWS; i++)
        {
            for (int j = 0; j < COLS; j++)
            {
                if(max <= matrix[i][j])
                {
                    max = matrix[i][j];
                }
            }
        }
        cout <<"Max element is: " << max << endl;
    }

    void show_min()
    {
        T min = matrix[0][0];
        for (int i = 0; i < ROWS; i++)
        {
            for (int j = 0; j < COLS; j++)
            {
                if (min >= matrix[i][j])
                {
                    min = matrix[i][j];
                }
            }
        }
        cout <<"Min element is: " << min << endl;
    }
};

int main()
{
    Matrix<int>f(4,4);
    f.fill_random();
    cout << f;
    cout << endl;

    Matrix<int>k(f);
    cout << k << endl;
   
    k / f;
    cout << k;

    k.show_max();
    k.show_min();

}

