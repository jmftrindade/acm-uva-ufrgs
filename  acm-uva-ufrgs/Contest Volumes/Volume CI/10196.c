<pre><p>#include &lt;stdio.h&gt;

#define chuta(a) (a + (bw*32))

char arr[8][9];

int acha (int a, int b, int bw) {
  int recebe,val;
  int i,j;

  i = a-1;
  j = b-1;
  while ((i &gt;= 0) &amp;&amp; (j &gt;= 0) &amp;&amp; (i &lt; 8) &amp;&amp; (j &lt; 8) &amp;&amp; (arr[i][j] == '.')) {
    i--;
    j--;
  };
  if ((i &gt;= 0) &amp;&amp; (j &gt;= 0) &amp;&amp; (i &lt; 8) &amp;&amp; (j &lt; 8)) {
    if ((arr[i][j] == chuta('B')) || (arr[i][j] == chuta('Q'))) {
      return 1;
    };
  };

  i = a+1;
  j = b-1;
  while ((i &gt;= 0) &amp;&amp; (j &gt;= 0) &amp;&amp; (i &lt; 8) &amp;&amp; (j &lt; 8) &amp;&amp; (arr[i][j] == '.')) {
    i++;
    j--;
  };
  if ((i &gt;= 0) &amp;&amp; (j &gt;= 0) &amp;&amp; (i &lt; 8) &amp;&amp; (j &lt; 8)) {
    if ((arr[i][j] == chuta('B')) || (arr[i][j] == chuta('Q'))) {
      return 1;
    };
  };

  i = a-1;
  j = b+1;
  while ((i &gt;= 0) &amp;&amp; (j &gt;= 0) &amp;&amp; (i &lt; 8) &amp;&amp; (j &lt; 8) &amp;&amp; (arr[i][j] == '.')) {
    i--;
    j++;
  };
  if ((i &gt;= 0) &amp;&amp; (j &gt;= 0) &amp;&amp; (i &lt; 8) &amp;&amp; (j &lt; 8)) {
    if ((arr[i][j] == chuta('B')) || (arr[i][j] == chuta('Q'))) {
      return 1;
    };
  };

  i = a+1;
  j = b+1;
  while ((i &gt;= 0) &amp;&amp; (j &gt;= 0) &amp;&amp; (i &lt; 8) &amp;&amp; (j &lt; 8) &amp;&amp; (arr[i][j] == '.')) {
    i++;
    j++;
  };
  if ((i &gt;= 0) &amp;&amp; (j &gt;= 0) &amp;&amp; (i &lt; 8) &amp;&amp; (j &lt; 8)) {
    if ((arr[i][j] == chuta('B')) || (arr[i][j] == chuta('Q'))) {
      return 1;
    };
  };

  i = a+1;
  j = b;
  while ((i &gt;= 0) &amp;&amp; (j &gt;= 0) &amp;&amp; (i &lt; 8) &amp;&amp; (j &lt; 8) &amp;&amp; (arr[i][j] == '.')) {
    i++;
  };
  if ((i &gt;= 0) &amp;&amp; (j &gt;= 0) &amp;&amp; (i &lt; 8) &amp;&amp; (j &lt; 8)) {
    if ((arr[i][j] == chuta('R')) || (arr[i][j] == chuta('Q'))) {
      return 1;
    };
  };

  i = a-1;
  j = b;
  while ((i &gt;= 0) &amp;&amp; (j &gt;= 0) &amp;&amp; (i &lt; 8) &amp;&amp; (j &lt; 8) &amp;&amp; (arr[i][j] == '.')) {
    i--;
  };
  if ((i &gt;= 0) &amp;&amp; (j &gt;= 0) &amp;&amp; (i &lt; 8) &amp;&amp; (j &lt; 8)) {
    if ((arr[i][j] == chuta('R')) || (arr[i][j] == chuta('Q'))) {
      return 1;
    };
  };

  i = a;
  j = b+1;
  while ((i &gt;= 0) &amp;&amp; (j &gt;= 0) &amp;&amp; (i &lt; 8) &amp;&amp; (j &lt; 8) &amp;&amp; (arr[i][j] == '.')) {
    j++;
  };
  if ((i &gt;= 0) &amp;&amp; (j &gt;= 0) &amp;&amp; (i &lt; 8) &amp;&amp; (j &lt; 8)) {
    if ((arr[i][j] == chuta('R')) || (arr[i][j] == chuta('Q'))) {
      return 1;
    };
  };

  i = a;
  j = b-1;
  while ((i &gt;= 0) &amp;&amp; (j &gt;= 0) &amp;&amp; (i &lt; 8) &amp;&amp; (j &lt; 8) &amp;&amp; (arr[i][j] == '.')) {
    j--;
  };
  if ((i &gt;= 0) &amp;&amp; (j &gt;= 0) &amp;&amp; (i &lt; 8) &amp;&amp; (j &lt; 8)) {
    if ((arr[i][j] == chuta('R')) || (arr[i][j] == chuta('Q'))) {
      return 1;
    };
  };

  if (bw) {
    i = a-1;
    j = b-1;
  } else {
    i = a+1;
    j = b-1;
  };
  if ((i &gt;= 0) &amp;&amp; (j &gt;= 0) &amp;&amp; (i &lt; 8) &amp;&amp; (j &lt; 8)) {
    if (arr[i][j] == chuta('P')) {
      return 1;
    };
  };

  if (bw) {
    i = a-1;
    j = b+1;
  } else {
    i = a+1;
    j = b+1;
  };
  if ((i &gt;= 0) &amp;&amp; (j &gt;= 0) &amp;&amp; (i &lt; 8) &amp;&amp; (j &lt; 8)) {
    if (arr[i][j] == chuta('P')) {
      return 1;
    };
  };

  i = a-2;
  j = b+1;
  if ((i &gt;= 0) &amp;&amp; (j &gt;= 0) &amp;&amp; (i &lt; 8) &amp;&amp; (j &lt; 8)) {
    if (arr[i][j] == chuta('N')) {
      return 1;
    };
  };

  i = a-1;
  j = b+2;
  if ((i &gt;= 0) &amp;&amp; (j &gt;= 0) &amp;&amp; (i &lt; 8) &amp;&amp; (j &lt; 8)) {
    if (arr[i][j] == chuta('N')) {
      return 1;
    };
  };

  i = a-2;
  j = b-1;
  if ((i &gt;= 0) &amp;&amp; (j &gt;= 0) &amp;&amp; (i &lt; 8) &amp;&amp; (j &lt; 8)) {
    if (arr[i][j] == chuta('N')) {
      return 1;
    };
  };

  i = a-1;
  j = b-2;
  if ((i &gt;= 0) &amp;&amp; (j &gt;= 0) &amp;&amp; (i &lt; 8) &amp;&amp; (j &lt; 8)) {
    if (arr[i][j] == chuta('N')) {
      return 1;
    };
  };

  i = a+2;
  j = b-1;
  if ((i &gt;= 0) &amp;&amp; (j &gt;= 0) &amp;&amp; (i &lt; 8) &amp;&amp; (j &lt; 8)) {
    if (arr[i][j] == chuta('N')) {
      return 1;
    };
  };

  i = a+1;
  j = b-2;
  if ((i &gt;= 0) &amp;&amp; (j &gt;= 0) &amp;&amp; (i &lt; 8) &amp;&amp; (j &lt; 8)) {
    if (arr[i][j] == chuta('N')) {
      return 1;
    };
  };

  i = a+2;
  j = b+1;
  if ((i &gt;= 0) &amp;&amp; (j &gt;= 0) &amp;&amp; (i &lt; 8) &amp;&amp; (j &lt; 8)) {
    if (arr[i][j] == chuta('N')) {
      return 1;
    };
  };

  i = a+1;
  j = b+2;
  if ((i &gt;= 0) &amp;&amp; (j &gt;= 0) &amp;&amp; (i &lt; 8) &amp;&amp; (j &lt; 8)) {
    if (arr[i][j] == chuta('N')) {
      return 1;
    };
  };

  return 0;

};

int main() {

  int i,j,x,bool;

  bool = 0;

  for (i=0;i&lt;8;i++) {
    scanf(&quot;%s&quot;,arr[i]);
    for (j=0;j&lt;8;j++) {
      if (arr[i][j] != '.') {
	bool = 1;
	break;
      };
    };
  };
  
  getchar();
  getchar();

  x = 1;
  
  while (bool) {

    bool = 0;

    for (i=0;i&lt;8;i++) {
      for (j=0;j&lt;8;j++) {
	if (arr[i][j] == 'k') {
	  bool = bool | acha(i,j,0);
	};
	if (arr[i][j] == 'K') {
	  bool = bool | (acha(i,j,1) * 2);
	};
      };
    };

    if (bool == 2) {
      printf(&quot;Game #%d: white king is in check.\n&quot;,x);
    } else if (bool == 1) {
      printf(&quot;Game #%d: black king is in check.\n&quot;,x);
    } else {
      printf(&quot;Game #%d: no king is in check.\n&quot;,x);
    };

    x++;

    bool = 0;

    for (i=0;i&lt;8;i++) {
      scanf(&quot;%s&quot;,arr[i]);
      for (j=0;j&lt;8;j++) {
	if (arr[i][j] != '.') {
	  bool = 1;
	  break;
	};
      };
    };
    getchar();
    getchar();
  };
  
  return 0;
};
</p></pre>