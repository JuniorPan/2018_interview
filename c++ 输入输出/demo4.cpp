#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;

int MinimumDifference(int n, int* pOilmines, int nNoOfMines)
{
	if (nNoOfMines < n)
	{
		return -1;
	}
	if (pOilmines != nullptr && nNoOfMines > 0 && n > 0)
	{
		double nMeanVal = 0.0;

		for (int i = 0; i < nNoOfMines; i++)
		{
			nMeanVal += pOilmines[i];
		}

		nMeanVal /= n;

		int *pCurrentAllocation = (int*)malloc(n * sizeof(int));
		int j = 0;
		int nMaxAllocation = 0, nMinAllocation = 0;

		for (int i = 0; i < n; i++)
		{
			pCurrentAllocation[i] = 0;

			if (n == nNoOfMines)
			{
				pCurrentAllocation[i] = pOilmines[i];
			}
			else
			{
				while (j < nNoOfMines && pCurrentAllocation[i] < nMeanVal)
				{
					pCurrentAllocation[i] += pOilmines[j];
					j++;
				}

				if (j < nNoOfMines)
				{
					if ((pCurrentAllocation[i] - nMeanVal) > (nMeanVal - (pCurrentAllocation[i] - pOilmines[j - 1])))
					{
						pCurrentAllocation[i] = pCurrentAllocation[i] - pOilmines[j - 1];
						j--;
					}
				}
			}
			if (pCurrentAllocation[i] > nMaxAllocation)
			{
				nMaxAllocation = pCurrentAllocation[i];
			}
			if (0 == i)
			{
				nMinAllocation = pCurrentAllocation[i];
			}
			if (pCurrentAllocation[i] < nMinAllocation)
			{
				nMinAllocation = pCurrentAllocation[i];
			}
		}

		free(pCurrentAllocation);

		return nMaxAllocation - nMinAllocation;
	}

	return -1;
}

int main()
{
	int nNoOfCompanies = 2;
	int nNoOfMines = 4;

	if (nNoOfMines < nNoOfCompanies)
	{
		printf("-1"); // Error
		return -1;
	}
    int pArr[] = {6,13,10,2};




	/**************************************************************************
	Run MinimumDifference Algo
	**************************************************************************/
	printf("\n Min Diff = %d\n", MinimumDifference(nNoOfCompanies, pArr, nNoOfMines));


	return 0;
}