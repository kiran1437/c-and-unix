#define MTEXTSIZE 500
struct mymsgbuf
  {
    long int mtype;             /* type of received/sent message */
    char mtext[MTEXTSIZE];              /* text of the message */
  };

