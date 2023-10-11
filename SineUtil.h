/**
 * Provides implementations for the Sine Approximation Algorithms
 * and related auxiliary functions
 * @author ketsubetsu 
 * <pre>
 * File: SineUtil.h
 * </pre>
 */

using namespace std;

class SineUtil
{
    private:
    /**
     * Computes the factorial of the specified number
     * @param n the number whose factorial is to be determined
     * @return n!
     * @throw invalid_argument when n < 0 
     */
    static double factorial(int n)
    {
        if (n < 0)
        {
            throw invalid_argument("Terminating program - indeterminate");
        }

        double facto = 1;
        for (int i = 1; i <= n; ++i)
        {
            facto *= i;
        }
        return facto;
    }
    /**
     * Computes the specified power
     * @param x the base of the power
     * @param n the exponent of the power
     * @return x^n
     * @throw invalid_argument when x = 0 and n <= 0 
     */
    static double pow(double x, int n)
    {
        if (x == 0 && n < 0)
        {
            throw invalid_argument("Terminating program - indeterminate");
        }

        double soln = 1;
        
        for (int i = 0; i < n; i++)
        {
            soln *= x;
        }
        return soln;
	}
    
    public:
    /**
     * Computes the sine of an angle using the Taylor Series approximation of the
     * sine function and naive exponentiation
     * @param x angle in radians
     * @param n number of terms
     * @return sine(x) = x - x^3/3! + x^5/5! - x^7/7! .....
     * @throw invalid_argument when n <= 0
     */
    static double naiveSine(double x, int n)
    {
        if (n <= 0) 
        {
            throw invalid_argument("Terminating program - indeterminate");
        }

        double soln = 0;

        for (int i = 1; i <= n; i++)
        {
            if (i % 2 == 0) 
            {
                soln = soln - pow(x, 2 * i - 1) / factorial(2 * i - 1);
            } 
        
            else 
            {
                soln = soln + pow(x, 2 * i - 1) / factorial(2 * i - 1);
            }   
        }
        return soln;
    }
    /**
     * Computes the sine of an angle using the Taylor Series approximation of the
     * sine function and fast exponentiation
     * @param x angle in radians
     * @param n number of terms
     * @return sine(x) = x - x^3/3! + x^5/5! - x^7/7! .....
     * @throw invalid_argument when n <= 0
     */
    static double fastSine(double x, int n)
    {
        if (n <= 0) 
        {
            throw invalid_argument("Terminating program - indeterminate");
        }

        double soln = x;

        int den = 3;
        int pf = -1;
        double init = x;

        for (int i = 2; i <= n; i++)
        {
            init = (init * (x / den) * (x / (den - 1)));
            den = (den + 2);
            soln = (soln + (pf * init));
            pf = (pf * (-1));
        }
        return soln;
	}
};