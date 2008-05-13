<pre><p>#include &lt;stdio.h&gt;
#include &lt;stdlib.h&gt;

int pancakes[31];
int pancakes2[31];
int n;

void preenche(char * a) {
  int i;
  n = 0;
  i = 0;
  while (a[i] != '\n') {
    if ((a[i] &gt;= 48) &amp;&amp; (a[i]&lt;=57)) {
      pancakes[n] = a[i] - 48;
      i++;
      while ((a[i] &gt;= 48) &amp;&amp; (a[i]&lt;=57)) {
	pancakes[n] = (pancakes[n]*10) + (a[i]-48);
	i++;
      };
      n++;
    } else {
      i++;
    };
  };
};

void swap1(int a, int b) {
  int aux;
  aux = pancakes[a];
  pancakes[a] = pancakes[b];
  pancakes[b] = aux;
};

void inverte (int a) {
  int i,j;
  for (i=0,j=a;i&lt;j;i++,j--) {
    swap1(i,j);
  };
};

void calcula() {
  int i;
  int j;
  int t;
  for (i=0;i&lt;(n-1);i++) {
    if (pancakes[0] == pancakes2[i]) {
      inverte(n-1-i);
      printf(&quot;%d &quot;,i+1);
    } else {
      j = 1;
      t = -1;
      while ((j&lt;(n-1-i))) {
	if (pancakes[j] == pancakes2[i]) {
	  t = j;
	  break;
	};
	j++;
      };
      if (t != -1) {
	inverte(t);
	inverte(n-1-i);
	printf(&quot;%d &quot;,n-t);
	printf(&quot;%d &quot;,i+1);
      };
    };
  };
};

void swap(int a, int b) {
  int aux;
  aux = pancakes2[a];
  pancakes2[a] = pancakes2[b];
  pancakes2[b] = aux;
};

int heapify(int g, int a, int b) {
  int d1,d2;
  if (a &gt; b) {
    return 0;
  };
  d1 = heapify(g,a*2,b);
  d2 = heapify(g,a*2+1,b);
  if (d1 &gt; d2) {
    if (pancakes2[g+a-1] &lt; d1) {
      swap(g+a-1,g+a*2-1);
    };
  } else {
    if (pancakes2[g+a-1] &lt; d2) {
      swap(g+a-1,g+a*2);
    };
  };
  return pancakes2[g+a-1];
};

void heapsort(){
  int i;
  for (i=0;i&lt;n;i++) {
    heapify(i,1,n-i);
  };
};

int main() {
  char * a;
  int i;
  a = (char *) malloc(sizeof(char)*100);
  a = fgets(a,100,stdin);
  while (a) {
    preenche(a);
    for (i=0;i&lt;n;i++) {
      if (i&gt;0) {
	printf(&quot; &quot;);
      };
      printf(&quot;%d&quot;,pancakes[i]);
      pancakes2[i] = pancakes[i];
    };
    printf(&quot;\n&quot;);

    heapsort();

    calcula();

    printf(&quot;0\n&quot;);

    a = fgets(a,100,stdin);
  };
  return 0;
};
</p></pre>