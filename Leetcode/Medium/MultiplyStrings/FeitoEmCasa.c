char *multiply( char *num1, char *num2 ) {

	int len1 = strlen(num1);
	int len2 = strlen(num2);

	if( (len1 == 1 && num1[0] == '0') || ( len2 == 1 && num2[0] == '0') ) {
		char* ans = ( char * )malloc( 2 );
		ans[0] = '0';
		ans[1] = '\0';
		return ans;
	}

	int* ans = ( int* )calloc( len1 + len2, sizeof( int ) );

	for ( int i = len1 - 1; i >= 0; i-- ) {

		for ( int j = len2 - 1; j >= 0; j-- ) {

			int mul = ( num1[i] - '0' ) * ( num2[j] - '0' );
			int sum = mul + ans[ i + j + 1 ];
			ans[ i + j + 1 ] = sum % 10;
			ans[ i + j ] += sum / 10;

		}

	}

	int i = 0;

	while ( i < len1 + len2 && ans[i] == 0) i++;

	int tam = len1 + len2 - i;

	char* result = (char *)malloc( tam + 1);

	for( int k = 0; k < tam; k++ ) {

		result[k] = ans[ i + k ] + '0';

	}

	result[tam] = '\0';

	free(ans);

	return result;

}