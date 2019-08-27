
echo --------------------------- FROM LIMITS.H-------------------
echo SCHAR_MAX  = `getconf SCHAR_MAX`
echo UCHAR_MAX  = `getconf UCHAR_MAX`
echo CHAR_MIN  = `getconf CHAR_MIN`
echo CHAR_MAX  = `getconf CHAR_MAX`
echo CHAR_MIN  = `getconf CHAR_MIN`
echo CHAR_MAX  = `getconf CHAR_MAX`
echo SHRT_MIN  = `getconf SHRT_MIN`
echo SHRT_MAX  = `getconf SHRT_MAX`
echo USHRT_MAX  = `getconf USHRT_MAX`
echo INT_MIN  = `getconf INT_MIN`
echo INT_MAX  = `getconf INT_MAX`
echo UINT_MAX  = `getconf UINT_MAX`
#echo LONG_MAX  = `getconf LONG_MAX`
#echo LONG_MAX  = `getconf LONG_MAX`
#echo LONG_MIN  = `getconf LONG_MIN`
echo ULONG_MAX  = `getconf ULONG_MAX`
echo ULONG_MAX  = `getconf ULONG_MAX`
#echo LLONG_MAX  = `getconf LLONG_MAX`
#echo LLONG_MIN  = `getconf LLONG_MIN`
#echo ULLONG_MAX  = `getconf ULLONG_MAX`
#echo LLONG_MIN  = `getconf LLONG_MIN`
#echo LLONG_MAX  = `getconf LLONG_MAX`
#echo ULLONG_MAX  = `getconf ULLONG_MAX`
echo 

echo "---------------------------FROM sysconf() -------------------"
echo ARG_MAX  = `getconf ARG_MAX`
echo CHILD_MAX  = `getconf CHILD_MAX`
echo HOST_NAME_MAX  = `getconf HOST_NAME_MAX`
echo LOGIN_NAME_MAX  = `getconf LOGIN_NAME_MAX`
echo OPEN_MAX  = `getconf OPEN_MAX`
echo PAGESIZE  = `getconf PAGESIZE`
echo RE_DUP_MAX  = `getconf RE_DUP_MAX`
echo STREAM_MAX  = `getconf STREAM_MAX`
echo SYMLOOP_MAX  = `getconf SYMLOOP_MAX`
echo TTY_NAME_MAX  = `getconf TTY_NAME_MAX`
echo TZNAME_MAX  = `getconf TZNAME_MAX`
echo _POSIX_VERSION  = `getconf _POSIX_VERSION`
echo


echo "---------------------------FROM sysconf() -------------------"
echo LINK_MAX  = `getconf LINK_MAX $0`
echo MAX_CANON  = `getconf MAX_CANON $0`
echo MAX_INPUT  = `getconf MAX_INPUT $0`
echo NAME_MAX  = `getconf NAME_MAX $0`
echo PATH_MAX  = `getconf PATH_MAX $0`
echo PIPE_BUF  = `getconf PIPE_BUF $0`
echo CHOWN_RESTRICTED  = `getconf CHOWN_RESTRICTED $0`
echo NO_TRUNC  = `getconf NO_TRUNC $0`
echo VDISABLE  = `getconf VDISABLE $0`





