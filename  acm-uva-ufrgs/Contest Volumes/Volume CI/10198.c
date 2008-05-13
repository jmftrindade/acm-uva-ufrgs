<pre><p>#include &lt;stdio.h&gt;
#include &lt;stdlib.h&gt;

#define	MAXDIGITS	500		/* maximum length bignum */ 

#define PLUS		1		/* positive sign bit */
#define MINUS		-1		/* negative sign bit */

typedef struct {
        char digits[MAXDIGITS];         /* represent the number */
	int signbit;			/* 1 if positive, -1 if negative */ 
        int lastdigit;			/* index of high-order digit */
} bignum;



copy_bignum(bignum *a1, bignum *a2) {
	int i;
	a1-&gt;signbit = a2-&gt;signbit;
	a1-&gt;lastdigit = a2-&gt;lastdigit;
	for (i=0;i&lt;=(a2-&gt;lastdigit);i++) {
		(a1-&gt;digits)[i] = (a2-&gt;digits)[i];
	};
};

print_bignum(bignum *n)
{
	int i;

	if (n-&gt;signbit == MINUS) printf(&quot;- &quot;);
	for (i=n-&gt;lastdigit; i&gt;=0; i--)
		printf(&quot;%c&quot;,'0'+ n-&gt;digits[i]);

	printf(&quot;\n&quot;);
}

int_to_bignum(int s, bignum *n)
{
	int i;				/* counter */
	int t;				/* int to work with */

	if (s &gt;= 0) n-&gt;signbit = PLUS;
	else n-&gt;signbit = MINUS;

	for (i=0; i&lt;MAXDIGITS; i++) n-&gt;digits[i] = (char) 0;

	n-&gt;lastdigit = -1;

	t = abs(s);

	while (t &gt; 0) {
		n-&gt;lastdigit ++;
		n-&gt;digits[ n-&gt;lastdigit ] = (t % 10);
		t = t / 10;
	}

	if (s == 0) n-&gt;lastdigit = 0;
}

initialize_bignum(bignum *n)
{
	int_to_bignum(0,n);
}


int max(int a, int b)
{
	if (a &gt; b) return(a); else return(b);
}

/*	c = a +-/* b;	*/

add_bignum(bignum *a, bignum *b, bignum *c)
{
	int carry;			/* carry digit */
	int i;				/* counter */

	initialize_bignum(c);

	if (a-&gt;signbit == b-&gt;signbit) c-&gt;signbit = a-&gt;signbit;
	else {
		if (a-&gt;signbit == MINUS) {
			a-&gt;signbit = PLUS;
			subtract_bignum(b,a,c);
			a-&gt;signbit = MINUS;
		} else {
                        b-&gt;signbit = PLUS;
                        subtract_bignum(a,b,c);
                        b-&gt;signbit = MINUS;
		}
		return;
	}

	c-&gt;lastdigit = max(a-&gt;lastdigit,b-&gt;lastdigit)+1;
	carry = 0;

	for (i=0; i&lt;=(c-&gt;lastdigit); i++) {
		c-&gt;digits[i] = (char) (carry+a-&gt;digits[i]+b-&gt;digits[i]) % 10;
		carry = (carry + a-&gt;digits[i] + b-&gt;digits[i]) / 10;
	}

	zero_justify(c);
}


subtract_bignum(bignum *a, bignum *b, bignum *c)
{
	int borrow;			/* has anything been borrowed? */
	int v;				/* placeholder digit */
	int i;				/* counter */

	initialize_bignum(c);

	if ((a-&gt;signbit == MINUS) || (b-&gt;signbit == MINUS)) {
                b-&gt;signbit = -1 * b-&gt;signbit;
                add_bignum(a,b,c);
                b-&gt;signbit = -1 * b-&gt;signbit;
		return;
        }

	if (compare_bignum(a,b) == PLUS) {
		subtract_bignum(b,a,c);
		c-&gt;signbit = MINUS;
		return;
	}

        c-&gt;lastdigit = max(a-&gt;lastdigit,b-&gt;lastdigit);
        borrow = 0;

        for (i=0; i&lt;=(c-&gt;lastdigit); i++) {
		v = (a-&gt;digits[i] - borrow - b-&gt;digits[i]);
		if (a-&gt;digits[i] &gt; 0)
			borrow = 0;
		if (v &lt; 0) {
			v = v + 10;
			borrow = 1;
		}

                c-&gt;digits[i] = (char) v % 10;
        }

	zero_justify(c);
}

compare_bignum(bignum *a, bignum *b)
{
	int i;				/* counter */

	if ((a-&gt;signbit == MINUS) &amp;&amp; (b-&gt;signbit == PLUS)) return(PLUS);
	if ((a-&gt;signbit == PLUS) &amp;&amp; (b-&gt;signbit == MINUS)) return(MINUS);

	if (b-&gt;lastdigit &gt; a-&gt;lastdigit) return (PLUS * a-&gt;signbit);
	if (a-&gt;lastdigit &gt; b-&gt;lastdigit) return (MINUS * a-&gt;signbit);

	for (i = a-&gt;lastdigit; i&gt;=0; i--) {
		if (a-&gt;digits[i] &gt; b-&gt;digits[i]) return(MINUS * a-&gt;signbit);
		if (b-&gt;digits[i] &gt; a-&gt;digits[i]) return(PLUS * a-&gt;signbit);
	}

	return(0);
}

zero_justify(bignum *n)
{
	while ((n-&gt;lastdigit &gt; 0) &amp;&amp; (n-&gt;digits[ n-&gt;lastdigit ] == 0))
		n-&gt;lastdigit --;

        if ((n-&gt;lastdigit == 0) &amp;&amp; (n-&gt;digits[0] == 0))
		n-&gt;signbit = PLUS;	/* hack to avoid -0 */
}


digit_shift(bignum *n, int d)		/* multiply n by 10^d */
{
	int i;				/* counter */

	if ((n-&gt;lastdigit == 0) &amp;&amp; (n-&gt;digits[0] == 0)) return;

	for (i=n-&gt;lastdigit; i&gt;=0; i--)
		n-&gt;digits[i+d] = n-&gt;digits[i];

	for (i=0; i&lt;d; i++) n-&gt;digits[i] = 0;

	n-&gt;lastdigit = n-&gt;lastdigit + d;
}



multiply_bignum(bignum *a, bignum *b, bignum *c)
{
	bignum row;			/* represent shifted row */
	bignum tmp;			/* placeholder bignum */
	int i,j;			/* counters */

	initialize_bignum(c);

	row = *a;

	for (i=0; i&lt;=b-&gt;lastdigit; i++) {
		for (j=1; j&lt;=b-&gt;digits[i]; j++) {
			add_bignum(c,&amp;row,&amp;tmp);
			*c = tmp;
		}
		digit_shift(&amp;row,1);
	}

	c-&gt;signbit = a-&gt;signbit * b-&gt;signbit;

	zero_justify(c);
}


divide_bignum(bignum *a, bignum *b, bignum *c)
{
        bignum row;                     /* represent shifted row */
        bignum tmp;                     /* placeholder bignum */
	int asign, bsign;		/* temporary signs */
        int i,j;                        /* counters */

	initialize_bignum(c);

	c-&gt;signbit = a-&gt;signbit * b-&gt;signbit;

	asign = a-&gt;signbit;
	bsign = b-&gt;signbit;

	a-&gt;signbit = PLUS;
        b-&gt;signbit = PLUS;

	initialize_bignum(&amp;row);
	initialize_bignum(&amp;tmp);

	c-&gt;lastdigit = a-&gt;lastdigit;

	for (i=a-&gt;lastdigit; i&gt;=0; i--) {
		digit_shift(&amp;row,1);
		row.digits[0] = a-&gt;digits[i];
		c-&gt;digits[i] = 0;
		while (compare_bignum(&amp;row,b) != PLUS) {
			c-&gt;digits[i] ++;
			subtract_bignum(&amp;row,b,&amp;tmp);
			row = tmp;
		}
	}

	zero_justify(c);

	a-&gt;signbit = asign;
	b-&gt;signbit = bsign;
}

bignum * pd[1001];

int main() {
	int i;
	int bool;
	int n;
	int tam;
	bignum mult;
	bignum soma,soma2,soma3;
	pd[1] = (bignum *) malloc(sizeof(bignum));
	pd[2] = (bignum *) malloc(sizeof(bignum));
	pd[3] = (bignum *) malloc(sizeof(bignum));
	int_to_bignum(2,pd[1]);
	int_to_bignum(5,pd[2]);
	int_to_bignum(13,pd[3]);
	int_to_bignum(2,&amp;mult);
	tam = 3;
	bool = scanf(&quot;%d&quot;,&amp;n);
	while (bool == 1) {
		if (n &lt;= tam) {
			print_bignum(pd[n]);
		} else {
			for (i=(tam+1);i&lt;=n;i++) {
				add_bignum(pd[i-3], pd[i-2], &amp;soma2);
				multiply_bignum(pd[i-1],&amp;mult,&amp;soma3);
				pd[i] = (bignum *) malloc(sizeof(bignum));
				add_bignum(&amp;soma2,&amp;soma3,pd[i]);
			};
			tam = n;
			print_bignum(pd[n]);
		};
		bool = scanf(&quot;%d&quot;,&amp;n);
	};
	return 0;
};
</p></pre>