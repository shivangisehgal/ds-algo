//TC: O(logN + 9p) //p = precision
//The only diffence between square root and Nth root is that we use binary exponentiation

//For fractional/precision, we can use linear search, as it will have only 0-9 digits.

#define ll long long

ll binaryExponentiation (ll x, int n) //x^n  // make 
{
	if(x == 0 || x == 1)
		return x;

	ll ans = 1;

	while(n)
	{
		if(n & 1)
			ans = ans * x;

		x = x * x;
		n = n >> 1;
	}

	return ans;
}

double squareRoot(ll n, int d) 
{		
	//Integer Part

	ll low = 0;
	ll high = n;

	ll mid;

	double ans = 0;

	while(low <= high)
	{
		mid = low + (high - low) / 2;

		ll mult = binaryExponentiation(mid, 2);

		if(mult == n)
		{
			ans = mid;
			break;
		}

		else if(mult < n)
		{
			ans = mid;
			low = mid + 1;
		}

		else
			high = mid - 1;
	}

	//Fractional Part

	double inc = 0.1;

	for(int place = 1; place <= d; place++)
	{
		while(ans * ans <= n)
			ans += inc;
		
		ans = ans - inc;

		inc = inc / 10.0;
	}

	return ans;
