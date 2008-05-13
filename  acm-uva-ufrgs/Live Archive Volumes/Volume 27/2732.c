<pre><p>#include &lt;stdio.h&gt;
#include &lt;stdlib.h&gt;

char str[51][102];

int max (int a, int b) {
  if (a &gt; b) {
    return a;
  } else {
    return b;
  };
};

int main() {
  int co,j,k;
  int i;
  i = 0;
  fgets(str[i],102,stdin);
  while (!((str[i][0] == '#') &amp;&amp; (str[i][1] == '\n'))) {
    i++;
    fgets(str[i],102,stdin);
  };
  co = 0;
  for (j=0;j&lt;i;j++) {
    k = 0;
    while (str[j][k] != '\n') {
      k++;
    };
    co = max(co,k);
    while (k &lt; 102) {
      str[j][k] = ' ';
      k++;
    };
  };
  printf(&quot;-&quot;);
  for (k=0;k&lt;i;k++) {
    printf(&quot;--&quot;);
  };
  printf(&quot;\n&quot;);
  for (j=0;j&lt;36;j++) {
    printf(&quot;|&quot;);
    for (k=0;k&lt;i;k++) {
      printf(&quot;%c|&quot;,str[k][j]);
    };
    printf(&quot;\n&quot;);
  };
  printf(&quot;-&quot;);
  for (k=0;k&lt;i;k++) {
    printf(&quot;--&quot;);
  };
  printf(&quot;\n&quot;);
  return 0;
}
</p></pre>