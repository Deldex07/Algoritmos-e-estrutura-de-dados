int maxSubArray( int *nums, int numsSize ) {
	int maxArr = nums[0];
	int maxS = 0;

	for ( int i = 0; i < numsSize; i++ ) {
		maxS += nums[i];

		if ( maxArr < maxS ) {
			maxArr = maxS;
		}

		if ( maxS < 0 ) {
			maxS = 0;
		}
	}


	return maxArr;
}