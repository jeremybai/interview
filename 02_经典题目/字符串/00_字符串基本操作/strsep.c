/****************************************************************************
 * @file     strsep.c
 * @brief    strtok的实现，
 * @version  V1.00
 * @date     2014.9.24
 * @note     从Fri Jun 25 1999，Linux kernel中strtok()已经被strsep()取代，因
 *           为strsep()是可重入的（未使用静态指针来保存下一段地址）而且更快。
 *           strtok中可以调用strpbrk和strspn函数来实现代码的精简
****************************************************************************/
#include <stdio.h>

//#define LINUX_KERNEL
//#define MICROSOFT
#define BAIXIANG

#ifdef LINUX_KERNEL
    /**     strpbrk和strsep函数的实现
    *     
    *       from Linux kernel，功能参见函数注释
    */  
    /**
    * strpbrk - Find the first occurrence of a set of characters
    * @cs: The string to be searched
    * @ct: The characters to search for
    */
    char *strpbrk(const char *cs, const char *ct)
    {
           const char *sc1, *sc2;

            for (sc1 = cs; *sc1 != '\0'; ++sc1) {
                    for (sc2 = ct; *sc2 != '\0'; ++sc2) {
                            if (*sc1 == *sc2)
                                    return (char *)sc1;
                    }
            }
            return NULL;
    }
    /**
    * strsep - Split a string into tokens
    * @s: The string to be searched
    * @ct: The characters to search for
    *
    * strsep() updates @s to point after the token, ready for the next call.
    *
    * It returns empty tokens, too, behaving exactly like the libc function
    * of that name. In fact, it was stolen from glibc2 and de-fancy-fied.
    * Same semantics, slimmer shape. ;)
    */
    char *strsep(char **s, const char *ct)
    {
            char *sbegin = *s;
            char *end;

            if (sbegin == NULL)
                    return NULL;

            end = strpbrk(sbegin, ct);
            if (end)
                    *end++ = '\0';
            *s = end;
            return sbegin;
    }
#endif

#ifdef MICROSOFT
    /**     strtok函数的实现
    *     
    *       from microsoft，功能参见函数注释
    */
	/* String searching functions as per ISO/IEC 9899 section 7.11.5 */

	/* 7.11.5.6. Return length of initial segment of s of chars in set -jvh */
	size_t  __cdecl _tcsspn(const _TCHAR *s, const _TCHAR *set)
	{
		const _TCHAR *x;
		size_t i;

		for (i = 0; *s; s++, i++) {
			for (x = set; *x; x++)
				if (*s == *x)
					goto continue_outer;
			break;
		continue_outer:;
		}
		return i;
	}
    /* ISO/IEC 9899 7.11.5.8 strtok. DEPRECATED.
     * Split string into tokens, and return one at a time while retaining state
     * internally.
     *
     * WARNING: Only one set of state is held and this means that the
     * WARNING: function is not thread-safe nor safe for multiple uses within
     * WARNING: one thread.
     *
     * NOTE: No library may call this function.
     */ 
    char * __cdecl strtok(char *s1, const char *delimit)
    {
        static char *lastToken = NULL; /* UNSAFE SHARED STATE! */
        char *tmp;

        /* Skip leading delimiters if new string. */
        if ( s1 == NULL ) {
            s1 = lastToken;
            if (s1 == NULL)         /* End of story? */
                return NULL;
        } else {
            s1 += strspn(s1, delimit);
        }

        /* Find end of segment */
        tmp = strpbrk(s1, delimit);
        if (tmp) {
            /* Found another delimiter, split string and save state. */
            *tmp = '\0';
            lastToken = tmp + 1;
        } else {
            /* Last segment, remember that. */
            lastToken = NULL;
        }

        return s1;
    }
#endif

#ifdef APPLE
/*
 * Span the string s2 (skip characters that are in s2).
 */
size_t
strspn(s1, s2)
	const char *s1;
	register const char *s2;
{
	register const char *p = s1, *spanp;
	register char c, sc;

	/*
	 * Skip any characters in s2, excluding the terminating \0.
	 */
cont:
	c = *p++;
	for (spanp = s2; (sc = *spanp++) != 0;)
		if (sc == c)
			goto cont;
	return (p - 1 - s1);
}


char *
strtok(s, delim)
	register char *s;
	register const char *delim;
{
	register char *spanp;
	register int c, sc;
	char *tok;
	static char *last;


	if (s == NULL && (s = last) == NULL)
		return (NULL);

	/*
	 * Skip (span) leading delimiters (s += strspn(s, delim), sort of).
	 */
cont:
	c = *s++;
	for (spanp = (char *)delim; (sc = *spanp++) != 0;) {
		if (c == sc)
			goto cont;
	}

	if (c == 0) {		/* no non-delimiter characters */
		last = NULL;
		return (NULL);
	}
	tok = s - 1;

	/*
	 * Scan token (scan for delimiters: s += strcspn(s, delim), sort of).
	 * Note that delim must have one NUL; we stop if we see that, too.
	 */
	for (;;) {
		c = *s++;
		spanp = (char *)delim;
		do {
			if ((sc = *spanp++) == c) {
				if (c == 0)
					s = NULL;
				else
					s[-1] = 0;
				last = s;
				return (tok);
			}
		} while (sc != 0);
	}
	/* NOTREACHED */
}

#endif
#ifdef BAIXIANG
    /**
    * strspn_bx - Compute the length of the maximum initial segment of "string"
    *	       whose characters all are in "chars".(skip characters that are
    *	       in chars)
    * @string: String to search.
    * @chars:  Characters to look for in string. 
    */
	size_t strspn_bx(char* string, char* chars) {
		char* s,*c;
		for(s = string; *s != '\0'; s++) {
			for(c = chars; *c != '\0'; c++) {
				if(*s == *c)
					break;
			}
			if(*c == '\0')
				break;
		}
		return (s - string);
	}

	char* strpbrk_bx(char *s1, const char *delimit)
	{
		const char* src, *des;
		for(src = s1; *src != '\0'; src++){
			for(des = delimit; *des != '\0'; des++){
				if(*src == *des)
					return (char*)src;
			}
		}
		return NULL; 		
	}
	
	char* strtok_bx(char **s1, const char *delimit)
	{
		char* pos;
		char* begin;
		while(*s1)
		{
			*s1 += strspn_bx(*s1, (char *)delimit);
			begin = *s1;
			if(NULL == begin)
				return NULL;
			pos = strpbrk_bx(begin, delimit);
			if(pos)
			{
				*pos++ = '\0';
				printf("%s\n",begin);
			}
			*s1 = pos;
		} 		
	}
	
	char* strtok_nocall(char **s1, const char *delimit)
	{
		char* pos;
		char* begin;
		char* s,*c;
		const char* src, *des;
		while(*s1)
		{
			//找到*s1中第一个不在delimit中，实现strspn功能
			for(s = *s1; *s != '\0'; s++)	{
				for(c = (char *)delimit; *c != '\0'; c++)	{
					if(*s == *c)
						break;
				}
				if(*c == '\0')
					break;
			}
			*s1 += (s - *s1);
			begin = *s1;
			if(NULL == begin)
				return NULL;
			//找到此时*s1中第一个在delimit中的字符的位置，实现strtok功能
			//*s1到该位置便是分割的第一个字符串的位置
			for(src = begin; *src != '\0'; src++){
				for(des = delimit; *des != '\0'; des++){
					if(*src == *des)
						break;
				}
				if(*src == *des)
					break;
			}		
			//若*src等于'\0'，表明未找到delimit中字符
			//若*src不等于'\0'，表明找到delimit中字符
			if(*src == '\0')
				pos = NULL;
			else
				pos = (char*)src;
			if(pos)
			{
				*pos++ = '\0';
			}
			printf("%s\n",begin);
			//将*s1指向pos后面的一个字节（没找到时为NULL）
			*s1 = pos;
		} 
		return NULL;
	}
#endif

int main()
{
    char array[] = "./451234567896/4*89-578";
    char iparray[] = "192.168.1.114";
    char *begin = array;
	char *ip = iparray;
#ifdef LINUX_KERNEL
    char *p = strsep(&begin,"6");
    printf("%s\n",p);
    p = strsep(&begin,"6");
    printf("%s\n",p);
#endif
#ifdef MICROSOFT
    char *p = strtok(begin,"6");
    printf("%s\n",p);
    p = strtok(NULL,"6");
    printf("%s\n",p);
#endif
#ifdef BAIXIANG
    //strtok_nocall(&begin,"456");
	strtok_nocall(&ip,".");
#endif
}
