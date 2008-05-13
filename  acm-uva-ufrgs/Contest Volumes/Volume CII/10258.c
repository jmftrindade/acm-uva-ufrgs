<pre><p>#include &lt;stdio.h&gt;
#include &lt;string.h&gt;

int arr [101][10][2];

int conte [101][3];

int n;

void le (char arrb[100], char * cor, int * time, int * prob, int * cont) {
  int i;
  i = 0;
  *cont = 0;
  while ((arrb[i] &gt;= 48) &amp;&amp; (arrb[i] &lt;= 57)) {
    *cont = ((*cont) * 10) + (arrb[i] -48);
    i++;
  };
  while ((arrb[i] &lt; 48) || (arrb[i] &gt; 57)) {
    i++;
  };
  *prob = 0;  
  while ((arrb[i] &gt;= 48) &amp;&amp; (arrb[i] &lt;= 57)) {
    *prob = ((*prob) * 10) + (arrb[i] - 48);
    i++;
  };
  while ((arrb[i] &lt; 48) || (arrb[i] &gt; 57)) {
    i++;
  };
  *time = 0;  
  while ((arrb[i] &gt;= 48) &amp;&amp; (arrb[i] &lt;= 57)) {
    *time = ((*time) * 10) + (arrb[i] - 48);
    i++;
  };
  while (arrb[i] == ' ') {
    i++;
  };
  *cor = arrb[i];
};

int compara(int * a1, int * a2) {
  if (a1[0] == 0) {
    return 1;
  } else if (a2[0] == 0) {
    return -1;
  };
  if ((a1)[1] &gt; (a2)[1]) {
    return 1;
  } else if ((a1)[1] &lt; (a2)[1]) {
    return -1;
  } else {
    if ((a1)[2] &lt; (a2)[2]) {
      return 1;
    } else if ((a1)[2] &gt; (a2)[2]) {
      return -1;
    } else {
      return  (a2)[0] - (a1)[0];
    };     
  };
};

int main() {
  int i,j,k;
  char a[100];
  char * b;
  char cor;
  int time;
  int prob;
  int cont;
  scanf(&quot;%d&quot;,&amp;n);
  fgets(a,100,stdin);
  fgets(a,100,stdin);
  for (i=0;i&lt;n;i++) {
    if (i != 0) {
      printf(&quot;\n&quot;);
    };
    for (j=0;j&lt;101;j++) {
      for (k=0;k&lt;10;k++) {
	arr[j][k][0] = 0;
	arr[j][k][1] = 0;
      };
      conte[j][0] = 0;
      conte[j][1] = 0;
      conte[j][2] = 0;
    };
    b = fgets(a,100,stdin);
    while (b &amp;&amp; (a[0] != '\n')) {
      le(a,&amp;cor,&amp;time,&amp;prob,&amp;cont);
      if (cor == 'I') {
	if (arr[cont][prob][1] == 0) {
	  arr[cont][prob][0] += 20;
	  if (conte[cont][0] == 0) {
	    conte[cont][0] = cont;
	  };
	};
      } else if (cor == 'C') {
	if (arr[cont][prob][1] == 0) {
	  arr[cont][prob][0] += time;
	  arr[cont][prob][1] = 1;
	  conte[cont][0] = cont;
	  (conte[cont][1])++;
	  conte[cont][2] += arr[cont][prob][0];
	};
      } else {
	conte[cont][0] = cont;
      };
      b = fgets(a,100,stdin);
    };
    qsort(conte,101,3*sizeof(int),*compara);
    for (j=101;j&gt;=0;j--) {
      if(conte[j][0] != 0) {
	printf(&quot;%d %d %d\n&quot;,conte[j][0],conte[j][1],conte[j][2]);
      };
    };
  };
  return 0;
};
</p></pre>