/*-
 * Copyright (c) 1982, 1985, 1986, 1988, 1993, 1994
 *      The Regents of the University of California.  All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 * 4. Neither the name of the University nor the names of its contributors
 *    may be used to endorse or promote products derived from this software
 *    without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS
 * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY
 * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
 * SUCH DAMAGE.
 *
 *      @(#)socket.h    8.4 (Berkeley) 2/21/94
 * $FreeBSD: stable/10/sys/sys/socket.h 254925 2013-08-26 18:16:05Z jhb $
 */

#ifndef MISC_SYS_SOCKET_H
#define	MISC_SYS_SOCKET_H

#include <sys/types.h>
#if defined(__linux__)
 /*
  * While we may have more groups than this, the cmsgcred struct must
  * be able to fit in an mbuf and we have historically supported a
  * maximum of 16 groups.
 */
 #define CMGROUP_MAX 16

 /*
  * Credentials structure, used to verify the identity of a peer
  * process that has sent us a message. This is allocated by the
  * peer process but filled in by the kernel. This prevents the
  * peer from lying about its identity. (Note that cmcred_groups[0]
  * is the effective GID.)
  */
 struct cmsgcred {
         pid_t   cmcred_pid;             /* PID of sending process */
         uid_t   cmcred_uid;             /* real UID of sending process */
         uid_t   cmcred_euid;            /* effective UID of sending process */
         gid_t   cmcred_gid;             /* real GID of sending process */
         short   cmcred_ngroups;         /* number or groups */
         gid_t   cmcred_groups[CMGROUP_MAX];     /* groups */
 };

#endif /* __linux__ */

#endif /* MISC_SYS_SOCKET_H */
