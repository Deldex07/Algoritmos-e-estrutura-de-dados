typedef struct no_s {
	int					valor;
	int					tamanho;
	int					altura;
	struct no_s *		esq;
	struct no_s *		dir;
} no_t;

static int Altura( const no_t *n ) {
	return n ? n->altura : 0;
}

static int Tamanho( const no_t *n ) {
	return n ? n->tamanho : 0;
}

static void Atualizar( no_t *n ) {
	int		he;
	int		hd;

	he = Altura( n->esq );
	hd = Altura( n->dir );
	n->altura = ( he > hd ? he : hd ) + 1;
	n->tamanho = 1 + Tamanho( n->esq ) + Tamanho( n->dir );
}

static no_t *RotacaoDireita( no_t *y ) {
	no_t *	x;

	x = y->esq;
	y->esq = x->dir;
	x->dir = y;
	Atualizar( y );
	Atualizar( x );
	return x;
}

static no_t *RotacaoEsquerda( no_t *x ) {
	no_t *	y;

	y = x->dir;
	x->dir = y->esq;
	y->esq = x;
	Atualizar( x );
	Atualizar( y );
	return y;
}

static int FatorBalanceamento( const no_t *n ) {
	return Altura( n->esq ) - Altura( n->dir );
}

static no_t *Rebalancear( no_t *n ) {
	int		fb;

	Atualizar( n );
	fb = FatorBalanceamento( n );

	if ( fb > 1 ) {
		if ( FatorBalanceamento( n->esq ) < 0 ) {
			n->esq = RotacaoEsquerda( n->esq );
		}
		return RotacaoDireita( n );
	}
	if ( fb < -1 ) {
		if ( FatorBalanceamento( n->dir ) > 0 ) {
			n->dir = RotacaoDireita( n->dir );
		}
		return RotacaoEsquerda( n );
	}
	return n;
}

no_t *Inserir_r( no_t *raiz, int valor ) {
	no_t *	n;

	if ( !raiz ) {
		n = malloc( sizeof( no_t ) );
		n->valor = valor;
		n->tamanho = 1;
		n->altura = 1;
		n->esq = NULL;
		n->dir = NULL;
		return n;
	}
	if ( valor < raiz->valor ) {
		raiz->esq = Inserir_r( raiz->esq, valor );
	} else {
		raiz->dir = Inserir_r( raiz->dir, valor );
	}
	return Rebalancear( raiz );
}

void Liberar_r( no_t *n ) {
	if ( !n ) {
		return;
	}
	Liberar_r( n->esq );
	Liberar_r( n->dir );
	free( n );
}

long long contarMenores(no_t* root, int val) {
    if (!root) return 0;

    if ( val < root->valor ) {
        return contarMenores(root->esq, val);
    } else if ( val > root->valor ) {
        return 1LL + Tamanho(root->esq) + contarMenores(root->dir, val);
    }
    return (long long)Tamanho(root->esq);
}

bool isIdealPermutation( int *nums, int numsSize ) {
    long long   local = 0;  
    long long   global = 0; 
    int         i;

    for ( i = 0; i < numsSize - 1; i ++ ) {
        if (nums[i] > nums[i+1]) {
            local++;
        }
    }

    no_t* root = NULL;

    for ( i = numsSize - 1; i >= 0 ; i -- ) {
        global += contarMenores(root, nums[i]);
        root = Inserir_r(root, nums[i]);
    }

    Liberar_r(root); 

    return global == local;
}