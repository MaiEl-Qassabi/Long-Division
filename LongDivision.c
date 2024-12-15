#include <stdio.h>
#include <stdlib.h>

void EnterCoefficient(double numcoefficient[], double denocofficient[], int* numeratorPower, int* DenoPower)
{
    int x ;
    printf("enter the highest degree of the numerator: ");
    scanf("%d", numeratorPower);

    for (x = 0; x < *numeratorPower; x++)
    {
        if (*numeratorPower - x == 1)
        {
            printf("Enter the coefficient of X : ");
            scanf("%lf", &numcoefficient[x]);
        }
        else
        {
            printf("Enter the coefficient of X^%d : ", *numeratorPower - x);
            scanf("%lf", &numcoefficient[x]);
        }
    }

    printf("Enter the constant term value : ");
    scanf("%lf", &numcoefficient[x]);
    printf("enter the highest degree of the denominator: ");
    scanf("%d", DenoPower);

    for (x = 0; x < *DenoPower; x++)
    {
        if (*DenoPower - x == 1)
        {
            printf("Enter the coefficient of X : ");
            scanf("%lf", &denocofficient[x]);
        }
        else
        {
            printf("Enter the coefficient of X^%d : ", *DenoPower - x);
            scanf("%lf", &denocofficient[x]);
        }
    }
    printf("Enter the constant term value : ");
    scanf("%lf", &denocofficient[x]);
}

int Divisioncondition(int numeratorPower, int DenoPower)
{
    if (numeratorPower >= DenoPower)
        {
            return 1;
        }
    else
    {
        return 0;
    }
}

int Divide(int numeratorPower, double numcoefficient[], int DenoPower, double denocofficient[], double outputCoef[])
{

    int theOutPower, i, j;
    double subtractionumcoefficient[50];
    theOutPower = numeratorPower - DenoPower;

    for (i = 0; i < numeratorPower; i++)
    {
        if (Divisioncondition(numeratorPower - i, DenoPower))
        {
            outputCoef[i] = numcoefficient[i] / denocofficient[0];
            for (j = 0; j <= DenoPower; j++)
            {
                subtractionumcoefficient[j] = outputCoef[i] * denocofficient[j];
            }
            for (j = 0; j <= DenoPower; j++)
            {
                numcoefficient[j + i] = numcoefficient[j + i] - subtractionumcoefficient[j];
            }
        }
        else
            break;
    }
    return theOutPower;
}

void Poly(int theOutPower, double theOutCoefficient[])
{

    int p;
    char sign;

    printf("The output is : ");
    for (p = 0; p < theOutPower; p++)
    {
        if (theOutCoefficient[p] < 0)
        {
            theOutCoefficient[p] = -theOutCoefficient[p];
            sign = -1;
        }
        else if (theOutCoefficient[p] > 0)
            sign = 1;
        else
            continue;

        if (theOutCoefficient[p] == 1)
        {
            if (theOutPower - p == 1)
            {
                if (sign == 1)
                {
                    if (p == 0)
                        printf("X ");
                    else
                        printf("+ X ");
                }
                else if (sign == -1)
                {
                    if (p == 0)
                        printf("-X ");
                    else
                        printf("- X ");
                }
            }
            else
            {
                if (sign == 1)
                {
                      if (p == 0)
                      printf("X^%d ", theOutPower - p);
                      else
                      printf("+ X^%d ", theOutPower - p);
                }
                else if (sign == -1)
                {
                      if (p == 0)
                      printf("-X^%d ", theOutPower - p);
                      else
                      printf("- X^%d ", theOutPower - p);
                }
            }
        }
        else
        {
            if (theOutPower - p == 1)
            {
                if (p == 0)
                    printf("%0.4lfX ", sign * theOutCoefficient[p]);
                else if (sign == 1)
                    printf("+ %0.4lfX ", theOutCoefficient[p]);
                else if (sign == -1)
                    printf("- %0.4lfX ", theOutCoefficient[p]);
            }
            else
            {
                if (p == 0)
                    printf("%0.4lfX^%d ", sign * theOutCoefficient[p], theOutPower);
                else if (sign == 1)
                    printf("+ %0.4lfX^%d ", theOutCoefficient[p], theOutPower - p);
                else if (sign == -1)
                    printf("- %0.4lfX^%d ", theOutCoefficient[p], theOutPower - p);
            }
        }

    }
    if (!theOutPower)
        printf("%0.4lf ", theOutCoefficient[p]);
    else if (theOutCoefficient[p] > 0)
        printf("+ %0.4lf ", theOutCoefficient[p]);
    else if (theOutCoefficient[p] < 0)
        printf("- %0.4lf ", -theOutCoefficient[p]);

}

int RemainderCondition(int numeratorPower, double numcoefficient[])
{
    int y;
    for (y= 0; y <= numeratorPower; y++)
        if (numcoefficient[y])
            return 1;
    return 0;
}

void RemainderConditionder(int numeratorPower, double numcoefficient[], int DenoPower, double denocofficient[])
{
    int i;
    char sign;
    for (i = 0; i <= numeratorPower; i++)
    {
        if (numcoefficient[i])
        {
            if (numcoefficient[i] > 0)
                sign = 1;
            else
            {
                sign = -1;
                numcoefficient[i] = -numcoefficient[i];
            }

            if (i != 0 && !numcoefficient[i - 1])
            {
                printf("+ (");
                if (numeratorPower - i == 0)
                {
                    if (sign == 1)
                        printf(" %0.4lf ", numcoefficient[i]);
                    else if (sign == -1)
                        printf("- %0.2lf ", numcoefficient[i]);
                }
                else if (numeratorPower - i == 1)
                {
                    if (sign == 1)
                        printf(" %0.4lfX ", numcoefficient[i]);
                    else if (sign == -1)
                        printf("- %0.4lfX ", numcoefficient[i]);
                }
                else if (numeratorPower - i > 1)
                {
                    if (sign == 1)
                        printf(" %0.4lfX^%d ", numcoefficient[i], numeratorPower - i);
                    else if (sign == -1)
                        printf("- %0.4lfX^%d ", numcoefficient[i], numeratorPower - i);
                }
            }
            else if (i == 0)
            {
                printf("(");
                if (numeratorPower - i == 0)
                {
                    if (sign == 1)
                        printf(" %0.4lf ", numcoefficient[i]);
                    else if (sign == -1)
                        printf("- %0.4lf ", numcoefficient[i]);
                }
                else if (numeratorPower - i == 1)
                {
                    if (sign == 1)
                        printf(" %0.4lfX ", numcoefficient[i]);
                    else if (sign == -1)
                        printf("- %0.4lfX ", numcoefficient[i]);
                }
                else if (numeratorPower - i > 1)
                {
                    if (sign == 1)
                        printf(" %0.4lfX^%d ", numcoefficient[i], numeratorPower - i);
                    else if (sign == -1)
                        printf("- %0.4lfX^%d ", numcoefficient[i], numeratorPower - i);
                }
            }
            else
            {
                if (numeratorPower - i == 0)
                {
                    if (sign == 1)
                        printf("+ %0.4lf ", numcoefficient[i]);
                    else if (sign == -1)
                        printf("- %0.4lf ", numcoefficient[i]);
                }
                else if (numeratorPower - i == 1)
                {
                    if (sign == 1)
                        printf("+ %0.4lfX ", numcoefficient[i]);
                    else if (sign == -1)
                        printf("- %0.4lfX ", numcoefficient[i]);
                }
                else if (numeratorPower - i > 1)
                {
                    if (sign == 1)
                        printf("+ %0.4lfX^%d ", numcoefficient[i], numeratorPower - i);
                    else if (sign == -1)
                        printf("- %0.4lfX^%d ", numcoefficient[i], numeratorPower - i);
                }
            }
        }
    }
    printf(") / (");
    for (i = 0; i < DenoPower; i++)
    {
        if (denocofficient[i] < 0)
        {
            denocofficient[i] = -denocofficient[i];
            sign = -1;
        }
        else if (denocofficient[i] > 0)
            sign = 1;
        else
            continue;

        if (denocofficient[i] == 1)
        {
            if (DenoPower - i == 1)
            {
                if (i == 0)
                    printf("X ");
                else
                    printf("+ X ");
            }
            else
            {
                if (i == 0)
                    printf("X^%d ", DenoPower - i);
                else
                    printf("+ X^%d ", DenoPower - i);
            }
        }
        else if (denocofficient[i] == -1)
        {
            if (DenoPower - i == 1)
            {
                printf("- X ");
            }
            else
            {
                printf("- X^%d ", DenoPower - i);
            }
        }
        else
        {
            if (DenoPower - i == 1)
            {
                if (i == 0)
                    printf("%0.4lfX ", sign * denocofficient[i]);
                else if (sign == 1)
                    printf("+ %0.4lfX ", denocofficient[i]);
                else if (sign == -1)
                    printf("- %0.4lfX ", denocofficient[i]);
            }
            else
            {
                if (i == 0)
                    printf("%0.4lfX^%d ", sign * denocofficient[i], DenoPower);
                else if (sign == 1)
                    printf("+ %0.4lfX^%d ", denocofficient[i], DenoPower - i);
                else if (sign == -1)
                    printf("- %0.4lfX^%d ", denocofficient[i], DenoPower - i);
            }
        }

    }
    if (denocofficient[i] > 0)
        printf("+ %0.4lf ", denocofficient[i]);
    else if (denocofficient[i] < 0)
        printf("- %0.4lf ", -denocofficient[i]);
    printf(")");
}

int main()
{
    double numcoefficient[50];
    double denocofficient[50];
    double theOutCoefficient[50];
    int numeratorPower, DenoPower, theOutPower;
    EnterCoefficient(numcoefficient, denocofficient, &numeratorPower, &DenoPower);
    if (Divisioncondition(numeratorPower, DenoPower))
    {
        theOutPower = Divide(numeratorPower, numcoefficient, DenoPower, denocofficient, theOutCoefficient);
        Poly(theOutPower, theOutCoefficient);
        if (RemainderCondition(numeratorPower, numcoefficient))
            RemainderConditionder(numeratorPower, numcoefficient, DenoPower, denocofficient);
    }
    else
        RemainderConditionder(numeratorPower, numcoefficient, DenoPower,denocofficient);

}
