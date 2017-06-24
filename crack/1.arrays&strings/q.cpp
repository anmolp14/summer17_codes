vector<int> Solution::maxset(vector<int> &A) {
	int n = A.length();
	int maxa = 0;
	int tempa = 0 ;
	int ls=0,h=0,l;
	for( int i=0; i<n ; i++)
	{
		if( A[i] < 0 )
		{
			if( maxa <= tempa)
			{      if(maxa < tempa)
				{
					l = ls;
					h = i-1;
					maxa =  tempa
				}
				else
				{
					if( i-1-ls > h-l)
					{
						h=i-1;
						l=ls;
					}
				}
			}
			tempa = 0;
			ls = i+1;
		}
		else
			tempa+=A[i];

	}
	if( maxa <= tempa)
	{
		if( maxa < tempa)
		{
			h=n-1; l = ls;maxa = tempa;
		} 
		else{
			if(n-1-ls>h-l)
				h=n-1;
			l=ls;
		}
	}
	vector < int > re;
	for( int i=l ; i <h-l+1 ; i++)
		re.push_back(A[i]);

	return re;
}

