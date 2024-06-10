#include <iostream>
#include <math.h>
#include <stack>
#include <sstream>
#include <vector>
#include <unordered_map>
using namespace std;

// basics of calculator
class basics
{
public:
    // addition
    double addition(double a, double b)
    {
        return a + b;
    }

    // subtraction
    double subtraction(double a, double b)
    {
        return a > b ? a - b : b - a;
    }

    // multiply
    double multiply(double a, double b)
    {
        return a * b;
    }

    // divide
    double division(double a, double b)
    {
        try
        {
            if (b == 0)
            {
                throw runtime_error("Divide by zero");
            }

            return a / b;
        }
        catch (exception &e)
        {
            cerr << e.what() << endl;
        }
    }

    // modulus
    double modulus(double a, double b)
    {
        return fmod(a, b);
    }

    // exponentiation
    double power(double a, double b)
    {
        return pow(a, b);
    }
};

// some more common computations
class advanced
{
public:
    // square root
    double squareRoot(double a)
    {
        return sqrt(a);
    }

    // cube root
    double cubeRoot(double a)
    {
        return cbrt(a);
    }

    // nth root
    double nthRoot(double a, double root)
    {
        double power = 1 / root;
        return pow(a, power);
    }

    // exponentiation
    double exponent(double a)
    {
        return exp(a);
    }

    // common logarithm
    double cLog(double a)
    {
        return log10(a);
    }

    // natural logarithm
    double nLog(double a)
    {
        return log(a);
    }

    // arbitrary base logarithm
    double aLog(double val, double base)
    {
        return log(val) / log(base);
    }

    // factorial
    double factorial(double a)
    {
        double res = 1;
        for (int i = 1; i <= a; i++)
        {
            res *= i;
        }

        return res;
    }
};

// trigonometric computations
class trigonometry
{
public:
    // single trigonometry
    double trig(double a, string func)
    {
        try
        {
            if (func == "sin")
            {
                return sin(a);
            }

            else if (func == "cos")
            {
                return cos(a);
            }

            else if (func == "tan")
            {
                return tan(a);
            }

            else if (func == "cosec")
            {
                return 1 / sin(a);
            }

            else if (func == "sec")
            {
                return 1 / cos(a);
            }

            else if (func == "cot")
            {
                return 1 / tan(a);
            }
            else
            {
                cout << "Invalid input";
            }
        }

        catch (exception &e)
        {
            cout << e.what() << endl;
        }
    }

    // inverse trigonometric function
    double iTrig(double a, string func)
    {
        try
        {
            if (func == "sin")
            {
                return asin(a);
            }

            else if (func == "cos")
            {
                return acos(a);
            }

            else if (func == "tan")
            {
                return atan(a);
            }

            else if (func == "cosec")
            {
                return 1 / asin(a);
            }

            else if (func == "sec")
            {
                return 1 / acos(a);
            }

            else if (func == "cot")
            {
                return 1 / atan(a);
            }
            else
            {
                cout << "Invalid input";
            }
        }

        catch (exception &e)
        {
            cout << e.what() << endl;
        }
    }

    // hyperbolic function
    double htrig(double a, string hyperbolic)
    {
        try
        {
            if (hyperbolic == "sin")
            {
                return sinh(a);
            }

            else if (hyperbolic == "cos")
            {
                return cosh(a);
            }

            else if (hyperbolic == "tan")
            {
                return tanh(a);
            }

            else
            {
                cout << "Invalid input";
            }
        }

        catch (exception &e)
        {
            cout << e.what() << endl;
        }
    }
};

// complex number
class complex
{
    double re, im;

public:
    complex(int real, int imaginary)
    {
        this->re = real;
        this->im = imaginary;
    }

    // dummy constructor to store the output
    complex() {}

    // addition od complex numbers
    void cAdd(complex c1, complex c2)
    {
        complex c3;
        c3.re = c1.re + c2.re;
        c3.im = c1.im + c2.im;

        cout << c3.re << "+ i(" << c3.im << ")" << endl;
    }

    // subtration of complex number
    void cSub(complex c1, complex c2)
    {
        complex c3;
        c3.re = c1.re - c2.re;
        c3.im = c1.im - c2.im;

        cout << c3.re << "+ i(" << c3.im << ")" << endl;
    }

    // multiplication of complex number
    void cMul(complex c1, complex c2)
    {
        complex c3;
        c3.re = c1.re * c2.re + c1.im * c2.im;
        c3.im = c1.re * c2.im + c1.im * c2.re;

        cout << c3.re << "+ i(" << c3.im << ")" << endl;
    }

    // division of complex number
    void cDiv(complex c1, complex c2)
    {
        complex c3;
        double deno = c2.re * c2.re + c2.im * c2.im;
        double numReal = c1.re * c2.re + c1.im * c2.im;
        double numImag = c1.im * c2.re - c1.re * c2.im;

        c3.re = numReal / deno;
        c3.im = numImag / deno;

        cout << c3.re << "+ i(" << c3.im << ")" << endl;
    }
};

// matrix solver
class matrix
{
public:
    // create matrix
    double *createMatrix(int rows, int cols)
    {
        double *matrix = new double[rows * cols];
        return matrix;
    }

    void fillMatrix(double *matrix, int rows, int cols)
    {
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                cin >> matrix[i * cols + j];
            }
        }
    }

    // print matrix
    void printMatrix(double *mat, int rows, int cols)
    {
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                cout << mat[i * cols + j] << " ";
            }
            cout << endl;
        }
    }

    // addition
    void mAdd(double *mat1, double *mat2, int rows, int cols)
    {
        double *result = createMatrix(rows, cols);
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                result[i * cols + j] = mat1[i * cols + j] + mat2[i * cols + j];
            }
        }

        printMatrix(result, rows, cols);
    }

    // subtration
    void mSub(double *mat1, double *mat2, int rows, int cols)
    {
        double *result = createMatrix(rows, cols);
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                result[i * cols + j] = mat1[i * cols + j] - mat2[i * cols + j];
            }
        }

        printMatrix(result, rows, cols);
    }

    // multiplication
    void mMul(double *mat1, double *mat2, int rows, int cols)
    {
        double *result = new double[rows * cols];

        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                result[i * cols + j] = 0; // Initialize result matrix element

                for (int k = 0; k < cols; k++)
                {
                    // Perform matrix multiplication
                    result[i * cols + j] += mat1[i * cols + k] * mat2[k * cols + j];
                }
            }
        }

        printMatrix(result, rows, cols);
    }

    // division
    void mDiv(double *mat1, double *mat2, int rows, int cols)
    {
        double *result = new double[rows * cols];

        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                if (mat2[i * cols + j] != 0)
                {
                    result[i * cols + j] = mat1[i * cols + j] / mat2[i * cols + j];
                }
                else
                {
                    result[i * cols + j] = 0;
                }
            }
        }

        printMatrix(result, rows, cols);
    }
};

// statistical function
class statistics
{
public:
    // mean
    double mean(int *arr)
    {
        int n = sizeof(arr) / sizeof(arr[0]);
        int sum = 0;
        for (int i = 0; i < n; i++)
        {
            sum += arr[i];
        }

        return sum / n;
    }

    // median
    double median(int *arr)
    {
        int n = sizeof(arr) / sizeof(arr[0]);
        int odd = (n + 1) / 2;
        int even = n / 2;

        // even
        if (n % 2 == 0)
        {
            double res = (arr[even] + arr[even + 1]) / 2;
            return res;
        }

        else
        {
            double res = arr[odd];
            return res;
        }
    }

    // mode
    double mode(int *arr)
    {
        double m = mean(arr);
        double med = median(arr);

        double mod = 3 * med - 2 * m;
        return mod;
    }

    // standard deviation
    double standardDeviation(int *arr)
    {
        vector<double> vec;
        int n = sizeof(arr) / sizeof(arr[0]);
        double avg = mean(arr);
        for (int i = 0; i < n; i++)
        {
            double x = arr[i] - avg;
            vec.push_back(x * x);
        }
        int sum = 0;
        for (int i = 0; i < vec.size(); i++)
        {
            sum += vec[i];
        }

        double sd = sqrt(sum / (n - 1));

        return sd;
    }

    // variance
    double variance(int *arr)
    {
        double sd = standardDeviation(arr);
        double var = sd * sd;
        return var;
    }
};

// infix expression solver
class Infix
{
public:
    // handle operators
    double applyOp(double a, double b, char op)
    {
        switch (op)
        {
        case '+':
            return a + b;

        case '-':
            return a - b;

        case '*':
            return a * b;

        case '/':
            if (b == 0)
                throw runtime_error("Division by zero");
            return a / b;

        case '^':
            return pow(a, b);

        default:
            throw runtime_error("Invalid operator");
        }
    }

    // convert infix to postfix
    string toPostfix(const string &infix)
    {
        stack<char> opStack;
        unordered_map<char, int> precedenceMap = {
            {'+', 1}, {'-', 1}, {'*', 2}, {'/', 2}, {'^', 3}};
        stringstream postfix;

        for (size_t i = 0; i < infix.length(); ++i)
        {
            char token = infix[i];

            if (isspace(token))
            {
                continue;
            }

            if (isdigit(token))
            {
                while (i < infix.length() && (isdigit(infix[i]) || infix[i] == '.'))
                {
                    postfix << infix[i];
                    ++i;
                }
                postfix << ' ';
                --i;
            }
            else if (token == '(')
            {
                opStack.push(token);
            }
            else if (token == ')')
            {
                while (!opStack.empty() && opStack.top() != '(')
                {
                    postfix << opStack.top() << ' ';
                    opStack.pop();
                }
                if (!opStack.empty())
                {
                    opStack.pop();
                }
            }
            else if (precedenceMap.find(token) != precedenceMap.end())
            {
                while (!opStack.empty() && precedenceMap[opStack.top()] >= precedenceMap[token])
                {
                    postfix << opStack.top() << ' ';
                    opStack.pop();
                }
                opStack.push(token);
            }
        }

        while (!opStack.empty())
        {
            postfix << opStack.top() << ' ';
            opStack.pop();
        }

        return postfix.str();
    }

    // evaluate postfix expression
    double evaluatePostfix(const string &postfix)
    {
        stringstream stream(postfix);
        stack<double> values;
        string token;

        while (stream >> token)
        {
            if (isdigit(token[0]))
            {
                values.push(stod(token));
            }
            else
            {
                double b = values.top();
                values.pop();
                double a = values.top();
                values.pop();
                double res = applyOp(a, b, token[0]);
                values.push(res);
            }
        }

        return values.top();
    }

    // evaluate infix
    double evaluateInfix(const string &infix)
    {
        string postfix = toPostfix(infix);
        return evaluatePostfix(postfix);
    }
};

// other functions
class pAndc
{
    advanced ad;

public:
    // permutation = (n!/(n-r)! * r!)
    double permutation(int n, int r)
    {
        double factn = ad.factorial(n);
        double factr = ad.factorial(r);
        double factnr = ad.factorial(n - r);

        double npr = factn / (factnr * factr);
        return npr;
    }

    // combination
    double combination(int n, int r)
    {
        double factn = ad.factorial(n);
        double factnr = ad.factorial(n - r);

        double ncr = factn / factnr;
        return ncr;
    }
};

int main()
{
    // testing complex class functions
    complex c1(4, 5);
    complex c2(2, 3);

    complex calc; // Dummy object to call functions

    cout << "Addition: ";
    calc.cAdd(c1, c2); // Expected output: 6 + i8

    cout << "Subtraction: ";
    calc.cSub(c1, c2); // Expected output: 2 - i2

    cout << "Multiplication: ";
    calc.cMul(c1, c2); // Expected output: -7 + i22

    cout << "Division: ";
    calc.cDiv(c1, c2); // Expected output: 1.7692−0.1538i

    // testing matrix functions
    matrix m;

    int rows = 2, cols = 2;

    double *mat1 = m.createMatrix(rows, cols);
    double *mat2 = m.createMatrix(rows, cols);

    // Fill matrices
    cout << "Matrix 1:" << endl;
    m.fillMatrix(mat1, rows, cols);
    cout << "Matrix 2:" << endl;
    m.fillMatrix(mat2, rows, cols);

    // Display matrices
    cout << "Matrix 1:" << endl;
    m.printMatrix(mat1, rows, cols);
    cout << "Matrix 2:" << endl;
    m.printMatrix(mat2, rows, cols);

    // Matrix addition
    cout << "Matrix Addition:" << endl;
    m.mAdd(mat1, mat2, rows, cols);
    /*
    6  8
    10 12
    */

    // Matrix subtraction
    cout << "Matrix Subtraction:" << endl;
    m.mSub(mat1, mat2, rows, cols);

    /*
    -4 -4
    -4 -4

    */

    // Matrix multiplication
    cout << "Matrix Multiplication:" << endl;
    m.mMul(mat1, mat2, rows, cols);

    /*
    19 22
    43 50
    */

    // Matrix division
    cout << "Matrix Division:" << endl;
    m.mDiv(mat1, mat2, rows, cols);

    /*
    0.2    0.3333
    0.4286 0.5
    */

    // Clean up dynamically allocated memory
    delete[] mat1;
    delete[] mat2;

    // infix test case
    Infix infixEvaluator;
    string infixExpr;

    // Test case 1
    infixExpr = "3 + 4 * 2 / ( 1 - 5 ) ^ 2 ^ 3";
    cout << "Infix: " << infixExpr << endl;
    cout << "Result: " << infixEvaluator.evaluateInfix(infixExpr) << endl; //3.00012207
    cout << endl;

    // Test case 2
    infixExpr = "10 + 2 * 6";
    cout << "Infix: " << infixExpr << endl;
    cout << "Result: " << infixEvaluator.evaluateInfix(infixExpr) << endl; //22
    cout << endl;

    // Test case 3
    infixExpr = "100 * 2 + 12";
    cout << "Infix: " << infixExpr << endl;
    cout << "Result: " << infixEvaluator.evaluateInfix(infixExpr) << endl;  //212
    cout << endl;

    // Test case 4
    infixExpr = "100 * ( 2 + 12 )";
    cout << "Infix: " << infixExpr << endl;
    cout << "Result: " << infixEvaluator.evaluateInfix(infixExpr) << endl;  //1400
    cout << endl;

    // Test case 5
    infixExpr = "100 * ( 2 + 12 ) / 14";
    cout << "Infix: " << infixExpr << endl;
    cout << "Result: " << infixEvaluator.evaluateInfix(infixExpr) << endl; //100
    cout << endl;

    return 0;
}