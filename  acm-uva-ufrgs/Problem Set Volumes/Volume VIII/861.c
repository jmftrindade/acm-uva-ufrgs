<pre><p>#include &lt;stdio.h&gt;

long long int salvar[33][8];
int cheios[8][8];
int matriz_xadrez[8][8];

void enxadrifica() {
  int i,j;
  for (i=0;i&lt;8;i++) {
    for (j=0;j&lt;8;j++) {
      matriz_xadrez[i][j] = (i+j) % 2;
    };
  };
  for (i=0;i&lt;33;i++) {
    for (j=0;j&lt;8;j++) {
      salvar[i][j] = 0;
    };
  };
};

int max (int a, int b) {
  if (a &gt; b) {
    return a;
  } else {
    return b;
  };
};

int min (int a, int b) {
  if (a &lt; b) {
    return a;
  } else {
    return b;
  };
};

long long int calcula_real(int pecas, int atual, int total, int mat[8][8], int linha, int coluna) {
  int mat_local[8][8];
  int i,j;
  int k,l;
  long long int retorno;
  if (pecas == 0) {
    return 1;
  } else {
    mat_local[linha][coluna] = 2;
    for (i=coluna+1;i&lt;total;i++) {
      if (matriz_xadrez[linha][i] == atual) {
	mat_local[linha][i] = mat[linha][i];
      };
    };
    for (i=linha+1;i&lt;total;i++) {
      for (j=0;j&lt;total;j++) {
	if (matriz_xadrez[i][j] == atual) {
	  if (((i-linha) == (j-coluna)) || ((i-linha) == (coluna-j))) {
	    mat_local[i][j] = 1;
	  } else {
	    mat_local[i][j] = mat[i][j];
	  };
	};
      };
    };
    retorno = 0;
    for (i=coluna+1;i&lt;total;i++) {
      if ((matriz_xadrez[linha][i] == atual) &amp;&amp; (mat_local[linha][i] == 0)) {
	retorno += calcula_real(pecas-1, atual, total, mat_local, linha, i);
      };
    };
    for (i=linha+1;i&lt;total;i++) {
      for (j=0;j&lt;total;j++) {
	if ((matriz_xadrez[i][j] == atual) &amp;&amp; (mat_local[i][j] == 0)) {
	  retorno += calcula_real(pecas-1, atual, total, mat_local, i, j);
	};
      };
    };
    return retorno;
  };
};

long long int calcula(int casas, int pecas, int atual, int total) {
  int mat_local[8][8];
  int i,j;
  long long int a;
  if (salvar[casas][pecas]) {
    return salvar[casas][pecas];
  } else if (pecas == 0) {
    return 1;
  } else {
    for (i=0;i&lt;total;i++) {
      for (j=0;j&lt;total;j++) {
	mat_local[i][j] = 0;
      };
    };
    for (i=0;i&lt;total;i++) {
      for (j=0;j&lt;total;j++) {
	if (matriz_xadrez[i][j] == atual) {
	  a = calcula_real(pecas-1,atual,total,mat_local,i,j);
	  salvar[casas][pecas] += a;
	};
      };
    };
    return salvar[casas][pecas];
  };
};

int main() {
  int n,k,i;
  long long int retorno;
  long long int a,b;
  
  enxadrifica();
  
  scanf(&quot;%d&quot;,&amp;n);
  scanf(&quot;%d&quot;,&amp;k);

  while (n || k) {

    if (k == 1) {
      printf(&quot;%d\n&quot;,n*n);
    } else if (k == 0) {
      printf(&quot;1\n&quot;);
    } else {
      retorno = 0;
      for (i=max(k-n+1,0);i&lt;=min(n-1,k);i++) {
	a = calcula(((n*n)/2)+(n%2),i,0,n);
	b = calcula((n*n)/2,k-i,1,n);
	retorno += a * b;
      };
      printf(&quot;%lld\n&quot;,retorno);
    };
    
    scanf(&quot;%d&quot;,&amp;n);
    scanf(&quot;%d&quot;,&amp;k);
  };

  return 0;
};
</p></pre>