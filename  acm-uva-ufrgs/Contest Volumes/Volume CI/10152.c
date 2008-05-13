<pre><p>#include &lt;stdio.h&gt;
#include &lt;stdlib.h&gt;

typedef struct TURTLE {
  int nt;
  char nome[256];
} turtle;

typedef struct LIST {
  turtle * turtl;
  struct LIST * next;
} lturtle;  

void inserelista(turtle ** turt, lturtle ** lturt) {
  lturtle * aux;
  aux = (lturtle *) malloc(sizeof(lturtle));
  aux-&gt;turtl = *turt;
  aux-&gt;next = *(lturt);
  *(lturt) = aux;
  return (void) 0;
};

void limpalista(lturtle ** lturt, int b) {
  lturtle * aux, * aux2;
  aux = *(lturt);
  while (aux != NULL) {
    aux2 = aux;
    aux = aux-&gt;next;
    if (b) {
      free(aux2-&gt;turtl);
    };
    free(aux2);
  };
  *lturt = NULL;
};

void deleteitem(lturtle * anterior) {
  lturtle * aux;
  aux = anterior-&gt;next;
  anterior-&gt;next = (anterior-&gt;next)-&gt;next;
  free(aux);
};

turtle ** procurastr(char a[256],lturtle * lturt) {
  lturtle * aux;
  int i;
  for (aux = lturt;aux != NULL;aux = aux-&gt;next) {
    for (i=0;((a[i] == ((aux-&gt;turtl)-&gt;nome)[i]) &amp;&amp; (a[i] != 0) &amp;&amp; (((aux-&gt;turtl)-&gt;nome)[i] != 0));i++);
    if ((a[i] == 0) &amp;&amp; (((aux-&gt;turtl)-&gt;nome)[i] == 0)) {
      return &amp;(aux-&gt;turtl);
    };
  };
  return NULL;
};

int main() {
  int i,j;
  int n,d;
  lturtle * aux2, * aux3;
  turtle * aux;
  lturtle * lista;
  lturtle * lista2;
  lturtle * lista3;
  lturtle * ant;
  lista = NULL;
  lista2 = NULL;
  lista3 = NULL;
  char str[256];
  scanf(&quot;%d&quot;,&amp;n);
  for (i=0;i&lt;n;i++) {
    scanf(&quot;%d&quot;,&amp;d);
    limpalista(&amp;lista,1);
    limpalista(&amp;lista2,0);
    fgets(str,256,stdin);
    for (j=0;j&lt;d;j++) {
      aux = (turtle *) malloc(sizeof(turtle));
      aux-&gt;nt = 0;
      fgets(aux-&gt;nome,256,stdin);
      inserelista(&amp;aux,&amp;(lista));
    };
    for (j=0;j&lt;d;j++) {
      fgets(str,256,stdin);
      inserelista(procurastr(str,lista),&amp;lista2);
      (lista2-&gt;turtl)-&gt;nt = j;
    };

    aux2 = lista;
    aux3 = lista2;
    ant = NULL;

    while (aux2 != NULL) {
      if (aux3-&gt;turtl == aux2-&gt;turtl) {
	aux3 = aux3-&gt;next;
      };
      aux2 = aux2-&gt;next;
    };

    while(aux3 != NULL) {
      printf(&quot;%s&quot;,(aux3-&gt;turtl)-&gt;nome);
      aux3 = aux3-&gt;next;
    };
    printf(&quot;\n&quot;);
  };

  return 0;
};
</p></pre>