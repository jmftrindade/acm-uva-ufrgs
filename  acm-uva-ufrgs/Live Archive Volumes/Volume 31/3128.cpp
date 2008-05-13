<pre><p>#include &lt;stdlib.h&gt;
#include &lt;iostream&gt;
#include &lt;string&gt;
using namespace std;

#define NCARDS 52
#define NSUITS 4

char values[] = &quot;23456789TJQKA&quot;;
char suits[] = &quot;CDSH&quot;;

int intcompare(const void *h, const void *k) {
  int i;
  int j;
  i = (int) *((int *) h);
  j = (int) *((int *) k);
  if (i &gt; j) return (1);
  if (i &lt; j) return (-1);
  return (0);
}

int rank_card(char value, char suit) {

  int i,j;
  for (i=0; i&lt;(NCARDS/NSUITS); i++) {
    if (values[i]==value) {
      for (j=0; j&lt;NSUITS; j++) {
	if (suits[j] == suit) {
	  return i*NSUITS + j + 1;
	};
      }
    }
  }
}

int main() {
  int k,h;
  int nc;
  int n;
  string card;
  int adam[26];
  int eve[26];
  int counter;
  
  std::cin &gt;&gt; nc;
  
  for (int i=0; i&lt;nc; i++) {
    
    
    memset(adam, 0, 26*sizeof(int));
    memset(eve, 0, 26*sizeof(int));        
    
    std::cin &gt;&gt; n;
    
    
    for (int j=0; j&lt;n; j++) {
      std::cin &gt;&gt; card;
      adam[j] = rank_card(card.c_str()[0],card.c_str()[1]);
    }       
    for (int j=0; j&lt;n; j++) {
      std::cin &gt;&gt; card;
      eve[j] = rank_card(card.c_str()[0],card.c_str()[1]);
    }
    
    
    qsort(adam, 26, sizeof(int), intcompare);
    qsort(eve, 26, sizeof(int), intcompare);
    
    k = 0;
    h = 0;
    counter = 0;
    
    while (h &lt; 26) {
      if (eve[h] == 0) {
	h++;
	k++;
      } else {
	if (eve[h] &gt; adam[k]) {
	  counter++;
	  h++;
	  k++;
	} else {
	  h++;
	};
      };
    };

    cout &lt;&lt; counter &lt;&lt; endl;
    
  }
  
}
</p></pre>