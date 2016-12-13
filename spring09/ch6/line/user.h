/*************************************/
/* user.h                            */
/*************************************/

#ifndef _user
#define _user

extern status writeline ( char *s );
extern int readfile ( char *filename, double_list *p_L ) ;
extern int writefile ( char *filename, double_list *p_L );
extern int insertlines ( char *linespec, double_list *p_head, double_list *p_current );
extern int deletelines ( char *linespec, double_list *p_head, double_list *p_current );
extern int movelines   ( char *linespec, double_list *p_head, double_list *p_current );
extern int printlines  ( char *linespec, double_list *p_head, double_list *p_current );
extern status parse_number ( char *numberspec, double_list head, double_list current, double_list *p_node );
extern int parse_linespec ( char *linespec, double_list head, double_list current, double_list *p_start, double_list *p_end );


#endif
