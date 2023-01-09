**
 * @input A : Read only ( DON'T MODIFY ) Integer array
 * @input n1 : Integer array's ( A ) length
 * 
 * @Output Integer
 */
int maxProfit(const int* A, int n1) {
    int i;
    int buy = A[0], max_profit = 0;
	for ( i = 1; i < n1; i++) {

		// Checking for lower buy value
		if (buy > A[i])
			buy = A[i];

		// Checking for higher profit
		else if (A[i] - buy > max_profit)
			max_profit = A[i] - buy;
	}
	return max_profit;

}
