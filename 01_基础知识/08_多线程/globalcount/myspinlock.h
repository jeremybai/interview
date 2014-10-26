/* Compile read-write barrier */
#define barrier() asm volatile("": : :"memory")

static inline unsigned xchg_32(void *ptr, unsigned x)
{
	__asm__ __volatile__("xchgl %0,%1"
				:"=r" ((unsigned) x)
				:"m" (*(volatile unsigned *)ptr), "0" (x)
				:"memory");

	return x;
}

#define EBUSY 1
typedef unsigned spinlock;

static void spin_lock(spinlock *lock)
{
	while (xchg_32(lock, EBUSY));
}

static void spin_unlock(spinlock *lock)
{
	barrier();
	*lock = 0;
}

static int spin_trylock(spinlock *lock)
{
	return xchg_32(lock, EBUSY);
}