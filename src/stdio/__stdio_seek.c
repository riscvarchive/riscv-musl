#include "stdio_impl.h"

#if defined(SYS__llseek) && !defined(SYS_llseek)
#define SYS_llseek SYS__llseek
#endif

off_t __stdio_seek(FILE *f, off_t off, int whence)
{
	off_t ret;
#ifdef SYS_llseek
	if (syscall(SYS_llseek, f->fd, off>>32, off, &ret, whence)<0)
		ret = -1;
#else
	ret = syscall(SYS_lseek, f->fd, off, whence);
#endif
	return ret;
}
