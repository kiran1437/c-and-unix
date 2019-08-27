set number 
set tabstop=8
set cindent
syntax off
se ignorecase

iab #i          #include <.h>
iab #s          #include <stdio.h><CR>
iab #d          #define 
iab mn          int main(int argc, char * argv[])<CR>{<CR> return 0;<CR>}
iab pf          printf("\n");
iab sf          scanf("",);
iab dpvi        #define pvi(V)     printf("%-15s=%-12d\n",#V,V)<CR>
iab dpviu       #define pviu(V)    printf("%-15s=%-12u\n",#V,V)<CR>
iab dpvix       #define pvix(V)    printf("%-15s=%#010x\n",#V,V)<CR>
iab dpvs        #define pvs(V)     printf("%-15s=%-12hd\n",#V,V)<CR>
iab dpvsu       #define pvsu(V)    printf("%-15s=%-12hu\n",#V,V)<CR>
iab dpvsx       #define pvsx(V)    printf("%-15s=%#06hx\n",#V,V)<CR>
iab dpvf        #define pvf(V)     printf("%-15s=%-12f\n",#V,V)<CR>
iab dpvll       #define pvll(V)    printf("%-15s=%-12lld\n", #V,V)<CR>
iab dpvstr      #define pvstr(V)   printf("%-15s=%-12s\n", #V,V)<CR>
iab dpvp        #define pvp(V)     printf("%-15s=%-12p\n",#V,V)<CR>
iab dpvc        #define pvc(V)     printf("%-15s=%-12c\n",#V,V)<CR>
iab dpvcx       #define pvcx(V)    printf("%-15s=%-12hhx\n",#V,V)<CR>
iab svi         printf("Enter value for :",);<CR> scanf("%d",)<CR>

iab csep     printf("----------------------------------------------------\n");

iab sep  ___________________________________________________________<CR>
iab hsep _____________________________<CR>

iab sp System.out.println();
iab sp2 #define pl(a) System.out.print(#a + " = " + a) <CR>pl();<ESC>hi
iab sl System.out.println();
iab sl2 #define pl(a) System.out.println(#a + " = " + a) <CR>pl();<ESC>hi
iab jsep System.out.println("\n---------------------------------------------\n");

iab maw $(warning "MYDEBUG:var" $(var))


se hls 

map <F2> :se nu<CR>
imap <F2> <ESC>:se nu<CR>i
cmap <F2> se nu<CR>:

map <F3> :!make <CR>
imap <F3> <ESC>:!make <CR>i
cmap <F3> !make <CR>:

imap <F4> <ESC>k!j cpp\|sed '/\#/d'<CR>

map <F5>  :w<CR> :!gcc %<CR>
imap <F5>  <ESC>:w<CR>:!gcc %<CR>
cmap <F5>  w<CR>:!gcc %<CR>

map <F6>  :w<CR>:!g++ %<CR>
imap <F6>  <ESC>:w <CR>:!g++ %<CR>
cmap <F6>  w<CR>:!g++ %<CR>

map <F7>  :!./a.out<CR>
imap <F7>  <ESC>:!./a.out<CR>
cmap <F7>  !./a.out<CR>


map <F8>  :w<CR> : ! javac % <CR>
imap <F8>  <ESC>:w<CR> : ! javac % <CR>
cmap <F8>  w<CR> : ! javac % <CR>

map <F9>  : ! clear; java `echo %\| cut -d '.' -f1` <CR>
imap <F9>  <ESC> : !clear;  java `echo %\| cut -d '.' -f1`  <CR>
cmap <F9>   ! clear; java `echo %\| cut -d '.' -f1` <CR>

iab #n   #include<iostream><CR>using namespace std;<CR>

iab dc     class X<CR>{<CR>int private_int;<CR>protected:<CR>int protected_int;<CR>public:<CR>int public_int;<CR>void display()<CR>{<CR>pv(private_int);<CR>pv(protected_int);<CR>pv(public_int);<CR>}<CR>}x;

iab dcd     class Y<CR>{<CR>int private_int_Y;<CR>protected:<CR>int protected_int_Y;<CR>public:<CR>int public_int_Y;<CR>void display()<CR>{<CR>pv(private_int_Y);<CR>pv(protected_int_Y);<CR>pv(public_int_Y);<CR>}<CR>}y;

iab pv         #define pv(V)     cout<<#V<<"\t=\t"<<V<<endl<CR>pv();<ESC>hi 
iab cv          cout<<"Variable                  ="<<Varaible<<endl ;
iab coin        cout<<"Enter the value for Variable:";<CR>cin>>Variable;


iab cpsep     cout<<"----------------------------------------------------"<<endl;


autocmd FileType * setlocal formatoptions-=c formatoptions-=r formatoptions-=o
