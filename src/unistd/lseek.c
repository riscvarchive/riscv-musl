#include <unistd.h>
#include "syscall.h"
#include "libc.h"

#if defined(SYS__llseek) && !defined(SYS_llseek)
#define SYS_llseek SYS__llseek
#endif

off_t lseek(int fd, off_t offset, int whence)
{
#ifdef SYS_llseek
	off_t result;
	return syscall(SYS_llseek, fd, offset>>32, offset, &result, whence) ? -1 : result;
#else
	return syscall(SYS_lseek, fd, offset, whence);
#endif
}

LFS64(lseek);
