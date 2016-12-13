// $ANTLR 3.1.3 Mar 18, 2009 10:09:25 src/csc/cslite.g 2009-05-10 19:47:41

package csc;
import org.jdom.*;


import org.antlr.runtime.*;
import java.util.Stack;
import java.util.List;
import java.util.ArrayList;
import java.util.Map;
import java.util.HashMap;
public class csliteParser extends Parser {
    public static final String[] tokenNames = new String[] {
        "<invalid>", "<EOR>", "<DOWN>", "<UP>", "ID", "SEMI", "INT", "BYTE", "L_CURLY", "R_CURLY", "NOT", "BREAK", "FOR", "L_PAREN", "NUM", "COLON", "R_PAREN", "LOOP", "WHILE", "UNTIL", "ASSIGN", "IF", "ELSE", "DOT", "COMMA", "PLUS", "MINUS", "EQ", "NE", "GT", "LT", "LE", "GE", "AND", "OR", "TIMES", "DIVIDES", "MODS", "STRING", "WS", "COMMENT", "LINE_COMMENT", "DIGIT", "ALPHA"
    };
    public static final int LT=30;
    public static final int WHILE=18;
    public static final int FOR=12;
    public static final int NOT=10;
    public static final int ID=4;
    public static final int AND=33;
    public static final int EOF=-1;
    public static final int BREAK=11;
    public static final int R_CURLY=9;
    public static final int IF=21;
    public static final int MODS=37;
    public static final int COMMA=24;
    public static final int LOOP=17;
    public static final int L_PAREN=13;
    public static final int PLUS=25;
    public static final int DIGIT=42;
    public static final int EQ=27;
    public static final int DOT=23;
    public static final int COMMENT=40;
    public static final int NE=28;
    public static final int BYTE=7;
    public static final int GE=32;
    public static final int LINE_COMMENT=41;
    public static final int ELSE=22;
    public static final int INT=6;
    public static final int MINUS=26;
    public static final int SEMI=5;
    public static final int R_PAREN=16;
    public static final int NUM=14;
    public static final int ALPHA=43;
    public static final int COLON=15;
    public static final int DIVIDES=36;
    public static final int WS=39;
    public static final int UNTIL=19;
    public static final int OR=34;
    public static final int ASSIGN=20;
    public static final int GT=29;
    public static final int L_CURLY=8;
    public static final int TIMES=35;
    public static final int LE=31;
    public static final int STRING=38;

    // delegates
    // delegators


        public csliteParser(TokenStream input) {
            this(input, new RecognizerSharedState());
        }
        public csliteParser(TokenStream input, RecognizerSharedState state) {
            super(input, state);
             
        }
        

    public String[] getTokenNames() { return csliteParser.tokenNames; }
    public String getGrammarFileName() { return "src/csc/cslite.g"; }


      Element newVar(String tag, Element vtype, String vname) {
            Element el = new Element(tag);
            el.addContent(vtype);
            Element e = new Element("Name");
            e.setText(vname);
            el.addContent(e);
            return el;
      }



    // $ANTLR start "program"
    // src/csc/cslite.g:28:1: program returns [Document doc = new Document()] : d= data_sec c= code_sec EOF ;
    public final Document program() throws RecognitionException {
        Document doc =  new Document();

        Element d = null;

        Element c = null;


         Element root_e = new Element("AST_IR");
          doc.addContent(root_e);

        try {
            // src/csc/cslite.g:37:1: (d= data_sec c= code_sec EOF )
            // src/csc/cslite.g:37:3: d= data_sec c= code_sec EOF
            {
            pushFollow(FOLLOW_data_sec_in_program69);
            d=data_sec();

            state._fsp--;
            if (state.failed) return doc;
            if ( state.backtracking==0 ) {
               root_e.addContent(d);
            }
            pushFollow(FOLLOW_code_sec_in_program78);
            c=code_sec();

            state._fsp--;
            if (state.failed) return doc;
            if ( state.backtracking==0 ) {
               root_e.addContent(c);
            }
            match(input,EOF,FOLLOW_EOF_in_program82); if (state.failed) return doc;

            }

        }
        catch (RecognitionException re) {
            reportError(re);
            recover(input,re);
        }
        finally {
        }
        return doc;
    }
    // $ANTLR end "program"


    // $ANTLR start "data_sec"
    // src/csc/cslite.g:41:1: data_sec returns [Element el = new Element(\"DATA_SEC\")] : (e= var_def )* ;
    public final Element data_sec() throws RecognitionException {
        Element el =  new Element("DATA_SEC");

        Element e = null;


        try {
            // src/csc/cslite.g:43:1: ( (e= var_def )* )
            // src/csc/cslite.g:43:3: (e= var_def )*
            {
            // src/csc/cslite.g:43:3: (e= var_def )*
            loop1:
            do {
                int alt1=2;
                alt1 = dfa1.predict(input);
                switch (alt1) {
            	case 1 :
            	    // src/csc/cslite.g:43:4: e= var_def
            	    {
            	    pushFollow(FOLLOW_var_def_in_data_sec99);
            	    e=var_def();

            	    state._fsp--;
            	    if (state.failed) return el;
            	    if ( state.backtracking==0 ) {
            	       el.addContent(e);
            	    }

            	    }
            	    break;

            	default :
            	    break loop1;
                }
            } while (true);


            }

        }
        catch (RecognitionException re) {
            reportError(re);
            recover(input,re);
        }
        finally {
        }
        return el;
    }
    // $ANTLR end "data_sec"


    // $ANTLR start "code_sec"
    // src/csc/cslite.g:46:1: code_sec returns [Element el = new Element(\"CODE_SEC\")] : (e= stmt )* ;
    public final Element code_sec() throws RecognitionException {
        Element el =  new Element("CODE_SEC");

        Element e = null;


        try {
            // src/csc/cslite.g:48:1: ( (e= stmt )* )
            // src/csc/cslite.g:48:3: (e= stmt )*
            {
            // src/csc/cslite.g:48:3: (e= stmt )*
            loop2:
            do {
                int alt2=2;
                int LA2_0 = input.LA(1);

                if ( (LA2_0==ID||LA2_0==L_CURLY||(LA2_0>=NOT && LA2_0<=FOR)||LA2_0==LOOP||LA2_0==IF) ) {
                    alt2=1;
                }


                switch (alt2) {
            	case 1 :
            	    // src/csc/cslite.g:48:4: e= stmt
            	    {
            	    pushFollow(FOLLOW_stmt_in_code_sec122);
            	    e=stmt();

            	    state._fsp--;
            	    if (state.failed) return el;
            	    if ( state.backtracking==0 ) {
            	       el.addContent(e);
            	    }

            	    }
            	    break;

            	default :
            	    break loop2;
                }
            } while (true);


            }

        }
        catch (RecognitionException re) {
            reportError(re);
            recover(input,re);
        }
        finally {
        }
        return el;
    }
    // $ANTLR end "code_sec"


    // $ANTLR start "var_def"
    // src/csc/cslite.g:52:1: var_def returns [Element el = null] : d= base_type ID SEMI ;
    public final Element var_def() throws RecognitionException {
        Element el =  null;

        Token ID1=null;
        Element d = null;


        try {
            // src/csc/cslite.g:54:1: (d= base_type ID SEMI )
            // src/csc/cslite.g:54:3: d= base_type ID SEMI
            {
            pushFollow(FOLLOW_base_type_in_var_def147);
            d=base_type();

            state._fsp--;
            if (state.failed) return el;
            ID1=(Token)match(input,ID,FOLLOW_ID_in_var_def149); if (state.failed) return el;
            match(input,SEMI,FOLLOW_SEMI_in_var_def151); if (state.failed) return el;
            if ( state.backtracking==0 ) {
               el = newVar("VAR_DEF", d, (ID1!=null?ID1.getText():null));
                  
            }

            }

        }
        catch (RecognitionException re) {
            reportError(re);
            recover(input,re);
        }
        finally {
        }
        return el;
    }
    // $ANTLR end "var_def"


    // $ANTLR start "base_type"
    // src/csc/cslite.g:60:1: base_type returns [Element el = null] : ( INT | BYTE );
    public final Element base_type() throws RecognitionException {
        Element el =  null;

        try {
            // src/csc/cslite.g:62:1: ( INT | BYTE )
            int alt3=2;
            int LA3_0 = input.LA(1);

            if ( (LA3_0==INT) ) {
                alt3=1;
            }
            else if ( (LA3_0==BYTE) ) {
                alt3=2;
            }
            else {
                if (state.backtracking>0) {state.failed=true; return el;}
                NoViableAltException nvae =
                    new NoViableAltException("", 3, 0, input);

                throw nvae;
            }
            switch (alt3) {
                case 1 :
                    // src/csc/cslite.g:62:3: INT
                    {
                    match(input,INT,FOLLOW_INT_in_base_type171); if (state.failed) return el;
                    if ( state.backtracking==0 ) {
                       el = new Element("Type");
                            el.setText("int");
                          
                    }

                    }
                    break;
                case 2 :
                    // src/csc/cslite.g:66:3: BYTE
                    {
                    match(input,BYTE,FOLLOW_BYTE_in_base_type182); if (state.failed) return el;
                    if ( state.backtracking==0 ) {
                       el = new Element("Type");
                            el.setText("byte");
                          
                    }

                    }
                    break;

            }
        }
        catch (RecognitionException re) {
            reportError(re);
            recover(input,re);
        }
        finally {
        }
        return el;
    }
    // $ANTLR end "base_type"


    // $ANTLR start "block"
    // src/csc/cslite.g:73:1: block returns [Element el = new Element(\"BLOCK\")] : L_CURLY (s= stmt )* R_CURLY ;
    public final Element block() throws RecognitionException {
        Element el =  new Element("BLOCK");

        Element s = null;


        try {
            // src/csc/cslite.g:75:1: ( L_CURLY (s= stmt )* R_CURLY )
            // src/csc/cslite.g:75:3: L_CURLY (s= stmt )* R_CURLY
            {
            match(input,L_CURLY,FOLLOW_L_CURLY_in_block203); if (state.failed) return el;
            // src/csc/cslite.g:75:11: (s= stmt )*
            loop4:
            do {
                int alt4=2;
                int LA4_0 = input.LA(1);

                if ( (LA4_0==ID||LA4_0==L_CURLY||(LA4_0>=NOT && LA4_0<=FOR)||LA4_0==LOOP||LA4_0==IF) ) {
                    alt4=1;
                }


                switch (alt4) {
            	case 1 :
            	    // src/csc/cslite.g:75:13: s= stmt
            	    {
            	    pushFollow(FOLLOW_stmt_in_block211);
            	    s=stmt();

            	    state._fsp--;
            	    if (state.failed) return el;
            	    if ( state.backtracking==0 ) {
            	      el.addContent(s);
            	    }

            	    }
            	    break;

            	default :
            	    break loop4;
                }
            } while (true);

            match(input,R_CURLY,FOLLOW_R_CURLY_in_block218); if (state.failed) return el;

            }

        }
        catch (RecognitionException re) {
            reportError(re);
            recover(input,re);
        }
        finally {
        }
        return el;
    }
    // $ANTLR end "block"


    // $ANTLR start "stmt"
    // src/csc/cslite.g:79:1: stmt returns [Element el = null] : (e= assign_stmt SEMI | e= if_else_stmt | e= func_call SEMI | e= block | e= loop_until_uncond_stmt | e= while_stmt | e= for_stmt | e= break_stmt SEMI | e= not_stmt );
    public final Element stmt() throws RecognitionException {
        Element el =  null;

        Element e = null;


        try {
            // src/csc/cslite.g:81:3: (e= assign_stmt SEMI | e= if_else_stmt | e= func_call SEMI | e= block | e= loop_until_uncond_stmt | e= while_stmt | e= for_stmt | e= break_stmt SEMI | e= not_stmt )
            int alt5=9;
            alt5 = dfa5.predict(input);
            switch (alt5) {
                case 1 :
                    // src/csc/cslite.g:81:5: e= assign_stmt SEMI
                    {
                    pushFollow(FOLLOW_assign_stmt_in_stmt238);
                    e=assign_stmt();

                    state._fsp--;
                    if (state.failed) return el;
                    match(input,SEMI,FOLLOW_SEMI_in_stmt240); if (state.failed) return el;
                    if ( state.backtracking==0 ) {
                      el=e;
                    }

                    }
                    break;
                case 2 :
                    // src/csc/cslite.g:82:5: e= if_else_stmt
                    {
                    pushFollow(FOLLOW_if_else_stmt_in_stmt252);
                    e=if_else_stmt();

                    state._fsp--;
                    if (state.failed) return el;
                    if ( state.backtracking==0 ) {
                      el=e;
                    }

                    }
                    break;
                case 3 :
                    // src/csc/cslite.g:83:5: e= func_call SEMI
                    {
                    pushFollow(FOLLOW_func_call_in_stmt265);
                    e=func_call();

                    state._fsp--;
                    if (state.failed) return el;
                    match(input,SEMI,FOLLOW_SEMI_in_stmt267); if (state.failed) return el;
                    if ( state.backtracking==0 ) {
                      el=e;
                    }

                    }
                    break;
                case 4 :
                    // src/csc/cslite.g:84:5: e= block
                    {
                    pushFollow(FOLLOW_block_in_stmt280);
                    e=block();

                    state._fsp--;
                    if (state.failed) return el;
                    if ( state.backtracking==0 ) {
                      el=e;
                    }

                    }
                    break;
                case 5 :
                    // src/csc/cslite.g:85:5: e= loop_until_uncond_stmt
                    {
                    pushFollow(FOLLOW_loop_until_uncond_stmt_in_stmt293);
                    e=loop_until_uncond_stmt();

                    state._fsp--;
                    if (state.failed) return el;
                    if ( state.backtracking==0 ) {
                      el=e;
                    }

                    }
                    break;
                case 6 :
                    // src/csc/cslite.g:86:5: e= while_stmt
                    {
                    pushFollow(FOLLOW_while_stmt_in_stmt305);
                    e=while_stmt();

                    state._fsp--;
                    if (state.failed) return el;
                    if ( state.backtracking==0 ) {
                      el=e;
                    }

                    }
                    break;
                case 7 :
                    // src/csc/cslite.g:87:5: e= for_stmt
                    {
                    pushFollow(FOLLOW_for_stmt_in_stmt317);
                    e=for_stmt();

                    state._fsp--;
                    if (state.failed) return el;
                    if ( state.backtracking==0 ) {
                      el=e;
                    }

                    }
                    break;
                case 8 :
                    // src/csc/cslite.g:88:5: e= break_stmt SEMI
                    {
                    pushFollow(FOLLOW_break_stmt_in_stmt329);
                    e=break_stmt();

                    state._fsp--;
                    if (state.failed) return el;
                    match(input,SEMI,FOLLOW_SEMI_in_stmt331); if (state.failed) return el;
                    if ( state.backtracking==0 ) {
                      el=e;
                    }

                    }
                    break;
                case 9 :
                    // src/csc/cslite.g:89:5: e= not_stmt
                    {
                    pushFollow(FOLLOW_not_stmt_in_stmt343);
                    e=not_stmt();

                    state._fsp--;
                    if (state.failed) return el;
                    if ( state.backtracking==0 ) {
                      el=e;
                    }

                    }
                    break;

            }
        }
        catch (RecognitionException re) {
            reportError(re);
            recover(input,re);
        }
        finally {
        }
        return el;
    }
    // $ANTLR end "stmt"


    // $ANTLR start "not_stmt"
    // src/csc/cslite.g:93:1: not_stmt returns [Element el = null] : NOT e= expr ;
    public final Element not_stmt() throws RecognitionException {
        Element el =  null;

        Element e = null;


        try {
            // src/csc/cslite.g:95:1: ( NOT e= expr )
            // src/csc/cslite.g:95:3: NOT e= expr
            {
            match(input,NOT,FOLLOW_NOT_in_not_stmt363); if (state.failed) return el;
            pushFollow(FOLLOW_expr_in_not_stmt369);
            e=expr();

            state._fsp--;
            if (state.failed) return el;
            if ( state.backtracking==0 ) {
               el = new Element("NOT");
                el.setContent(e);

            }

            }

        }
        catch (RecognitionException re) {
            reportError(re);
            recover(input,re);
        }
        finally {
        }
        return el;
    }
    // $ANTLR end "not_stmt"


    // $ANTLR start "break_stmt"
    // src/csc/cslite.g:102:1: break_stmt returns [Element el = null] : BREAK ;
    public final Element break_stmt() throws RecognitionException {
        Element el =  null;

        try {
            // src/csc/cslite.g:104:1: ( BREAK )
            // src/csc/cslite.g:104:3: BREAK
            {
            match(input,BREAK,FOLLOW_BREAK_in_break_stmt387); if (state.failed) return el;
            if ( state.backtracking==0 ) {
               el = new Element("MY_BREAK_STMT");
                      
            }

            }

        }
        catch (RecognitionException re) {
            reportError(re);
            recover(input,re);
        }
        finally {
        }
        return el;
    }
    // $ANTLR end "break_stmt"


    // $ANTLR start "for_stmt"
    // src/csc/cslite.g:109:1: for_stmt returns [Element el = null] : FOR i= ID L_PAREN f= NUM COLON s= NUM ( COLON t= NUM )? R_PAREN b= block ;
    public final Element for_stmt() throws RecognitionException {
        Element el =  null;

        Token i=null;
        Token f=null;
        Token s=null;
        Token t=null;
        Element b = null;


         
          String id = null, first = null, last = null, step = null;

        try {
            // src/csc/cslite.g:114:1: ( FOR i= ID L_PAREN f= NUM COLON s= NUM ( COLON t= NUM )? R_PAREN b= block )
            // src/csc/cslite.g:114:3: FOR i= ID L_PAREN f= NUM COLON s= NUM ( COLON t= NUM )? R_PAREN b= block
            {
            match(input,FOR,FOLLOW_FOR_in_for_stmt414); if (state.failed) return el;
            i=(Token)match(input,ID,FOLLOW_ID_in_for_stmt419); if (state.failed) return el;
            if ( state.backtracking==0 ) {
              id = i.getText();
            }
            match(input,L_PAREN,FOLLOW_L_PAREN_in_for_stmt423); if (state.failed) return el;
            f=(Token)match(input,NUM,FOLLOW_NUM_in_for_stmt427); if (state.failed) return el;
            if ( state.backtracking==0 ) {
              first = f.getText();
            }
            match(input,COLON,FOLLOW_COLON_in_for_stmt431); if (state.failed) return el;
            s=(Token)match(input,NUM,FOLLOW_NUM_in_for_stmt435); if (state.failed) return el;
            if ( state.backtracking==0 ) {
              last = s.getText();
            }
            // src/csc/cslite.g:114:104: ( COLON t= NUM )?
            int alt6=2;
            int LA6_0 = input.LA(1);

            if ( (LA6_0==COLON) ) {
                alt6=1;
            }
            switch (alt6) {
                case 1 :
                    // src/csc/cslite.g:114:105: COLON t= NUM
                    {
                    match(input,COLON,FOLLOW_COLON_in_for_stmt440); if (state.failed) return el;
                    t=(Token)match(input,NUM,FOLLOW_NUM_in_for_stmt444); if (state.failed) return el;
                    if ( state.backtracking==0 ) {
                      step = t.getText();
                    }

                    }
                    break;

            }

            match(input,R_PAREN,FOLLOW_R_PAREN_in_for_stmt450); if (state.failed) return el;
            pushFollow(FOLLOW_block_in_for_stmt454);
            b=block();

            state._fsp--;
            if (state.failed) return el;
            if ( state.backtracking==0 ) {
               el = new Element("MY_FOR_STMT");
                      
                      Element af = new Element ("ID");
                      af.setText(id);
                      el.addContent(af);
                      
                      Element bf = new Element ("FIRST");
                      bf.setText (first);
                      el.addContent(bf);
                      
                      Element cf = new Element ("LAST");
                      cf.setText (last);
                      el.addContent(cf);

                      Element df = null;

                      if ( step != null ) {
                              df = new Element ("STEP");
                              df.setText(step);
                              el.addContent(df);
                        }
                        
                      el.addContent(b);
                        

            }

            }

        }
        catch (RecognitionException re) {
            reportError(re);
            recover(input,re);
        }
        finally {
        }
        return el;
    }
    // $ANTLR end "for_stmt"


    // $ANTLR start "while_stmt"
    // src/csc/cslite.g:142:1: while_stmt returns [Element el = null] : LOOP WHILE L_PAREN e= expr R_PAREN b= block ;
    public final Element while_stmt() throws RecognitionException {
        Element el =  null;

        Element e = null;

        Element b = null;


        try {
            // src/csc/cslite.g:144:1: ( LOOP WHILE L_PAREN e= expr R_PAREN b= block )
            // src/csc/cslite.g:144:3: LOOP WHILE L_PAREN e= expr R_PAREN b= block
            {
            match(input,LOOP,FOLLOW_LOOP_in_while_stmt477); if (state.failed) return el;
            match(input,WHILE,FOLLOW_WHILE_in_while_stmt479); if (state.failed) return el;
            match(input,L_PAREN,FOLLOW_L_PAREN_in_while_stmt481); if (state.failed) return el;
            pushFollow(FOLLOW_expr_in_while_stmt487);
            e=expr();

            state._fsp--;
            if (state.failed) return el;
            match(input,R_PAREN,FOLLOW_R_PAREN_in_while_stmt489); if (state.failed) return el;
            pushFollow(FOLLOW_block_in_while_stmt493);
            b=block();

            state._fsp--;
            if (state.failed) return el;
            if ( state.backtracking==0 ) {
               
                      el = new Element("MY_WHILE_STMT");
                      
                      Element a = new Element("WHILE");
                      a.setContent(e);        
                      
                      el.addContent(a);
                      el.addContent(b);
                        

            }

            }

        }
        catch (RecognitionException re) {
            reportError(re);
            recover(input,re);
        }
        finally {
        }
        return el;
    }
    // $ANTLR end "while_stmt"


    // $ANTLR start "loop_until_uncond_stmt"
    // src/csc/cslite.g:157:1: loop_until_uncond_stmt returns [Element el = null] : LOOP b= block ( UNTIL L_PAREN e= expr R_PAREN )? ;
    public final Element loop_until_uncond_stmt() throws RecognitionException {
        Element el =  null;

        Element b = null;

        Element e = null;


         int is_until = 0; 
        try {
            // src/csc/cslite.g:160:1: ( LOOP b= block ( UNTIL L_PAREN e= expr R_PAREN )? )
            // src/csc/cslite.g:160:3: LOOP b= block ( UNTIL L_PAREN e= expr R_PAREN )?
            {
            match(input,LOOP,FOLLOW_LOOP_in_loop_until_uncond_stmt520); if (state.failed) return el;
            pushFollow(FOLLOW_block_in_loop_until_uncond_stmt524);
            b=block();

            state._fsp--;
            if (state.failed) return el;
            // src/csc/cslite.g:160:16: ( UNTIL L_PAREN e= expr R_PAREN )?
            int alt7=2;
            alt7 = dfa7.predict(input);
            switch (alt7) {
                case 1 :
                    // src/csc/cslite.g:160:17: UNTIL L_PAREN e= expr R_PAREN
                    {
                    match(input,UNTIL,FOLLOW_UNTIL_in_loop_until_uncond_stmt527); if (state.failed) return el;
                    match(input,L_PAREN,FOLLOW_L_PAREN_in_loop_until_uncond_stmt529); if (state.failed) return el;
                    pushFollow(FOLLOW_expr_in_loop_until_uncond_stmt533);
                    e=expr();

                    state._fsp--;
                    if (state.failed) return el;
                    match(input,R_PAREN,FOLLOW_R_PAREN_in_loop_until_uncond_stmt535); if (state.failed) return el;
                    if ( state.backtracking==0 ) {
                      is_until = 1;
                    }

                    }
                    break;

            }

            if ( state.backtracking==0 ) {
               
                      el = new Element("MY_LOOP_STMT");       
               
                        Element a = null;          
                                  
                        if ( is_until == 1 ){
                              a = new Element ("UNTIL");
                              a.setContent(e);
                              el.addContent(a);
                        }
                        
                        el.addContent(b);
                              
                      
            }

            }

        }
        catch (RecognitionException re) {
            reportError(re);
            recover(input,re);
        }
        finally {
        }
        return el;
    }
    // $ANTLR end "loop_until_uncond_stmt"


    // $ANTLR start "assign_stmt"
    // src/csc/cslite.g:178:1: assign_stmt returns [Element el = null] : ID ASSIGN e= expr ;
    public final Element assign_stmt() throws RecognitionException {
        Element el =  null;

        Token ID2=null;
        Element e = null;


        try {
            // src/csc/cslite.g:180:1: ( ID ASSIGN e= expr )
            // src/csc/cslite.g:180:3: ID ASSIGN e= expr
            {
            ID2=(Token)match(input,ID,FOLLOW_ID_in_assign_stmt572); if (state.failed) return el;
            match(input,ASSIGN,FOLLOW_ASSIGN_in_assign_stmt574); if (state.failed) return el;
            pushFollow(FOLLOW_expr_in_assign_stmt578);
            e=expr();

            state._fsp--;
            if (state.failed) return el;
            if ( state.backtracking==0 ) {
               el = new Element("ASSIGN_STMT");
                   Element v = new Element("Var");
                   v.setText(ID2.getText());
                   el.addContent(v);
                   el.addContent(e);
                 
            }

            }

        }
        catch (RecognitionException re) {
            reportError(re);
            recover(input,re);
        }
        finally {
        }
        return el;
    }
    // $ANTLR end "assign_stmt"


    // $ANTLR start "if_else_stmt"
    // src/csc/cslite.g:190:1: if_else_stmt returns [Element el = null] : IF L_PAREN e= expr R_PAREN s1= stmt ELSE s2= stmt ;
    public final Element if_else_stmt() throws RecognitionException {
        Element el =  null;

        Element e = null;

        Element s1 = null;

        Element s2 = null;


        try {
            // src/csc/cslite.g:192:1: ( IF L_PAREN e= expr R_PAREN s1= stmt ELSE s2= stmt )
            // src/csc/cslite.g:192:3: IF L_PAREN e= expr R_PAREN s1= stmt ELSE s2= stmt
            {
            match(input,IF,FOLLOW_IF_in_if_else_stmt599); if (state.failed) return el;
            match(input,L_PAREN,FOLLOW_L_PAREN_in_if_else_stmt601); if (state.failed) return el;
            pushFollow(FOLLOW_expr_in_if_else_stmt607);
            e=expr();

            state._fsp--;
            if (state.failed) return el;
            match(input,R_PAREN,FOLLOW_R_PAREN_in_if_else_stmt609); if (state.failed) return el;
            pushFollow(FOLLOW_stmt_in_if_else_stmt615);
            s1=stmt();

            state._fsp--;
            if (state.failed) return el;
            match(input,ELSE,FOLLOW_ELSE_in_if_else_stmt617); if (state.failed) return el;
            pushFollow(FOLLOW_stmt_in_if_else_stmt623);
            s2=stmt();

            state._fsp--;
            if (state.failed) return el;
            if ( state.backtracking==0 ) {
               el = new Element("IF_ELSE_STMT");
                   el.addContent(e);
                   el.addContent(s1);
                   el.addContent(s2);
                 
            }

            }

        }
        catch (RecognitionException re) {
            reportError(re);
            recover(input,re);
        }
        finally {
        }
        return el;
    }
    // $ANTLR end "if_else_stmt"


    // $ANTLR start "func_call"
    // src/csc/cslite.g:201:1: func_call returns [Element el = new Element(\"CALL_STMT\")] : i= ID ( DOT i2= ID )* L_PAREN (e1= expr ( COMMA e2= expr )* )? R_PAREN ;
    public final Element func_call() throws RecognitionException {
        Element el =  new Element("CALL_STMT");

        Token i=null;
        Token i2=null;
        Element e1 = null;

        Element e2 = null;


         Element func_e;
          String func_name=null;

        try {
            // src/csc/cslite.g:206:3: (i= ID ( DOT i2= ID )* L_PAREN (e1= expr ( COMMA e2= expr )* )? R_PAREN )
            // src/csc/cslite.g:206:5: i= ID ( DOT i2= ID )* L_PAREN (e1= expr ( COMMA e2= expr )* )? R_PAREN
            {
            i=(Token)match(input,ID,FOLLOW_ID_in_func_call650); if (state.failed) return el;
            if ( state.backtracking==0 ) {
              func_name = i.getText();
            }
            // src/csc/cslite.g:207:5: ( DOT i2= ID )*
            loop8:
            do {
                int alt8=2;
                int LA8_0 = input.LA(1);

                if ( (LA8_0==DOT) ) {
                    alt8=1;
                }


                switch (alt8) {
            	case 1 :
            	    // src/csc/cslite.g:207:6: DOT i2= ID
            	    {
            	    match(input,DOT,FOLLOW_DOT_in_func_call660); if (state.failed) return el;
            	    i2=(Token)match(input,ID,FOLLOW_ID_in_func_call664); if (state.failed) return el;
            	    if ( state.backtracking==0 ) {
            	      func_name += "."+i2.getText();
            	    }

            	    }
            	    break;

            	default :
            	    break loop8;
                }
            } while (true);

            if ( state.backtracking==0 ) {
               func_e = new Element("Name");
                    func_e.setText(func_name);
                    el.addContent(func_e); 
            }
            match(input,L_PAREN,FOLLOW_L_PAREN_in_func_call682); if (state.failed) return el;
            // src/csc/cslite.g:211:13: (e1= expr ( COMMA e2= expr )* )?
            int alt10=2;
            int LA10_0 = input.LA(1);

            if ( (LA10_0==ID||(LA10_0>=L_PAREN && LA10_0<=NUM)||LA10_0==STRING) ) {
                alt10=1;
            }
            switch (alt10) {
                case 1 :
                    // src/csc/cslite.g:211:14: e1= expr ( COMMA e2= expr )*
                    {
                    pushFollow(FOLLOW_expr_in_func_call689);
                    e1=expr();

                    state._fsp--;
                    if (state.failed) return el;
                    if ( state.backtracking==0 ) {
                      el.addContent(e1);
                    }
                    // src/csc/cslite.g:211:45: ( COMMA e2= expr )*
                    loop9:
                    do {
                        int alt9=2;
                        int LA9_0 = input.LA(1);

                        if ( (LA9_0==COMMA) ) {
                            alt9=1;
                        }


                        switch (alt9) {
                    	case 1 :
                    	    // src/csc/cslite.g:211:46: COMMA e2= expr
                    	    {
                    	    match(input,COMMA,FOLLOW_COMMA_in_func_call694); if (state.failed) return el;
                    	    pushFollow(FOLLOW_expr_in_func_call700);
                    	    e2=expr();

                    	    state._fsp--;
                    	    if (state.failed) return el;
                    	    if ( state.backtracking==0 ) {
                    	      el.addContent(e2);
                    	    }

                    	    }
                    	    break;

                    	default :
                    	    break loop9;
                        }
                    } while (true);


                    }
                    break;

            }

            match(input,R_PAREN,FOLLOW_R_PAREN_in_func_call709); if (state.failed) return el;

            }

        }
        catch (RecognitionException re) {
            reportError(re);
            recover(input,re);
        }
        finally {
        }
        return el;
    }
    // $ANTLR end "func_call"


    // $ANTLR start "expr"
    // src/csc/cslite.g:216:1: expr returns [Element el = null] : e= term ( ( PLUS | MINUS | EQ | NE | GT | LT | LE | GE | AND | OR | NOT ) e= term )* ;
    public final Element expr() throws RecognitionException {
        Element el =  null;

        Element e = null;


         Element left_e = null;
          boolean one_sub = true;
        try {
            // src/csc/cslite.g:220:1: (e= term ( ( PLUS | MINUS | EQ | NE | GT | LT | LE | GE | AND | OR | NOT ) e= term )* )
            // src/csc/cslite.g:220:3: e= term ( ( PLUS | MINUS | EQ | NE | GT | LT | LE | GE | AND | OR | NOT ) e= term )*
            {
            pushFollow(FOLLOW_term_in_expr734);
            e=term();

            state._fsp--;
            if (state.failed) return el;
            if ( state.backtracking==0 ) {
              left_e = e; 
            }
            // src/csc/cslite.g:221:3: ( ( PLUS | MINUS | EQ | NE | GT | LT | LE | GE | AND | OR | NOT ) e= term )*
            loop12:
            do {
                int alt12=2;
                alt12 = dfa12.predict(input);
                switch (alt12) {
            	case 1 :
            	    // src/csc/cslite.g:221:4: ( PLUS | MINUS | EQ | NE | GT | LT | LE | GE | AND | OR | NOT ) e= term
            	    {
            	    // src/csc/cslite.g:221:4: ( PLUS | MINUS | EQ | NE | GT | LT | LE | GE | AND | OR | NOT )
            	    int alt11=11;
            	    alt11 = dfa11.predict(input);
            	    switch (alt11) {
            	        case 1 :
            	            // src/csc/cslite.g:221:5: PLUS
            	            {
            	            match(input,PLUS,FOLLOW_PLUS_in_expr742); if (state.failed) return el;
            	            if ( state.backtracking==0 ) {
            	               el = new Element("PLUS_EXPR"); el.addContent(left_e);
            	            }

            	            }
            	            break;
            	        case 2 :
            	            // src/csc/cslite.g:222:20: MINUS
            	            {
            	            match(input,MINUS,FOLLOW_MINUS_in_expr765); if (state.failed) return el;
            	            if ( state.backtracking==0 ) {
            	               el = new Element("MINUS_EXPR"); el.addContent(left_e);
            	            }

            	            }
            	            break;
            	        case 3 :
            	            // src/csc/cslite.g:223:20: EQ
            	            {
            	            match(input,EQ,FOLLOW_EQ_in_expr789); if (state.failed) return el;
            	            if ( state.backtracking==0 ) {
            	               el = new Element("EQUALS_EXPR"); el.addContent(left_e);
            	            }

            	            }
            	            break;
            	        case 4 :
            	            // src/csc/cslite.g:224:20: NE
            	            {
            	            match(input,NE,FOLLOW_NE_in_expr812); if (state.failed) return el;
            	            if ( state.backtracking==0 ) {
            	               el = new Element("NOT_EQUAL_EXPR"); el.addContent(left_e);
            	            }

            	            }
            	            break;
            	        case 5 :
            	            // src/csc/cslite.g:225:20: GT
            	            {
            	            match(input,GT,FOLLOW_GT_in_expr835); if (state.failed) return el;
            	            if ( state.backtracking==0 ) {
            	               el = new Element("GT_EXPR"); el.addContent(left_e);
            	            }

            	            }
            	            break;
            	        case 6 :
            	            // src/csc/cslite.g:226:20: LT
            	            {
            	            match(input,LT,FOLLOW_LT_in_expr858); if (state.failed) return el;
            	            if ( state.backtracking==0 ) {
            	               el = new Element("LT_EXPR"); el.addContent(left_e);
            	            }

            	            }
            	            break;
            	        case 7 :
            	            // src/csc/cslite.g:227:20: LE
            	            {
            	            match(input,LE,FOLLOW_LE_in_expr881); if (state.failed) return el;
            	            if ( state.backtracking==0 ) {
            	               el = new Element("LE_EXPR"); el.addContent(left_e);
            	            }

            	            }
            	            break;
            	        case 8 :
            	            // src/csc/cslite.g:228:20: GE
            	            {
            	            match(input,GE,FOLLOW_GE_in_expr904); if (state.failed) return el;
            	            if ( state.backtracking==0 ) {
            	               el = new Element("GE_EXPR"); el.addContent(left_e);
            	            }

            	            }
            	            break;
            	        case 9 :
            	            // src/csc/cslite.g:229:20: AND
            	            {
            	            match(input,AND,FOLLOW_AND_in_expr927); if (state.failed) return el;
            	            if ( state.backtracking==0 ) {
            	               el = new Element("AND_EXPR"); el.addContent(left_e);
            	            }

            	            }
            	            break;
            	        case 10 :
            	            // src/csc/cslite.g:230:20: OR
            	            {
            	            match(input,OR,FOLLOW_OR_in_expr950); if (state.failed) return el;
            	            if ( state.backtracking==0 ) {
            	               el = new Element("OR_EXPR"); el.addContent(left_e);
            	            }

            	            }
            	            break;
            	        case 11 :
            	            // src/csc/cslite.g:231:20: NOT
            	            {
            	            match(input,NOT,FOLLOW_NOT_in_expr973); if (state.failed) return el;
            	            if ( state.backtracking==0 ) {
            	               el = new Element("NOT_EXPR"); el.addContent(left_e);
            	            }

            	            }
            	            break;

            	    }

            	    pushFollow(FOLLOW_term_in_expr1019);
            	    e=term();

            	    state._fsp--;
            	    if (state.failed) return el;
            	    if ( state.backtracking==0 ) {
            	       el.addContent(e); left_e = el; one_sub = false; 
            	    }

            	    }
            	    break;

            	default :
            	    break loop12;
                }
            } while (true);

            if ( state.backtracking==0 ) {
               if (one_sub) 
                     el = left_e;
                 
            }

            }

        }
        catch (RecognitionException re) {
            reportError(re);
            recover(input,re);
        }
        finally {
        }
        return el;
    }
    // $ANTLR end "expr"


    // $ANTLR start "term"
    // src/csc/cslite.g:239:1: term returns [Element el = null] : e= factor ( ( ( TIMES ) | ( DIVIDES ) | ( MODS ) ) e= factor )* ;
    public final Element term() throws RecognitionException {
        Element el =  null;

        Element e = null;


         Element left_e = null; 
          boolean one_sub = true;
        try {
            // src/csc/cslite.g:243:3: (e= factor ( ( ( TIMES ) | ( DIVIDES ) | ( MODS ) ) e= factor )* )
            // src/csc/cslite.g:243:5: e= factor ( ( ( TIMES ) | ( DIVIDES ) | ( MODS ) ) e= factor )*
            {
            pushFollow(FOLLOW_factor_in_term1082);
            e=factor();

            state._fsp--;
            if (state.failed) return el;
            if ( state.backtracking==0 ) {
              left_e = e; 
            }
            // src/csc/cslite.g:244:4: ( ( ( TIMES ) | ( DIVIDES ) | ( MODS ) ) e= factor )*
            loop14:
            do {
                int alt14=2;
                alt14 = dfa14.predict(input);
                switch (alt14) {
            	case 1 :
            	    // src/csc/cslite.g:244:5: ( ( TIMES ) | ( DIVIDES ) | ( MODS ) ) e= factor
            	    {
            	    // src/csc/cslite.g:244:5: ( ( TIMES ) | ( DIVIDES ) | ( MODS ) )
            	    int alt13=3;
            	    switch ( input.LA(1) ) {
            	    case TIMES:
            	        {
            	        alt13=1;
            	        }
            	        break;
            	    case DIVIDES:
            	        {
            	        alt13=2;
            	        }
            	        break;
            	    case MODS:
            	        {
            	        alt13=3;
            	        }
            	        break;
            	    default:
            	        if (state.backtracking>0) {state.failed=true; return el;}
            	        NoViableAltException nvae =
            	            new NoViableAltException("", 13, 0, input);

            	        throw nvae;
            	    }

            	    switch (alt13) {
            	        case 1 :
            	            // src/csc/cslite.g:244:6: ( TIMES )
            	            {
            	            // src/csc/cslite.g:244:6: ( TIMES )
            	            // src/csc/cslite.g:244:7: TIMES
            	            {
            	            match(input,TIMES,FOLLOW_TIMES_in_term1092); if (state.failed) return el;
            	            if ( state.backtracking==0 ) {
            	               el = new Element("TIMES_EXPR"); el.addContent(left_e);
            	            }

            	            }


            	            }
            	            break;
            	        case 2 :
            	            // src/csc/cslite.g:245:22: ( DIVIDES )
            	            {
            	            // src/csc/cslite.g:245:22: ( DIVIDES )
            	            // src/csc/cslite.g:245:23: DIVIDES
            	            {
            	            match(input,DIVIDES,FOLLOW_DIVIDES_in_term1120); if (state.failed) return el;
            	            if ( state.backtracking==0 ) {
            	               el = new Element("DIVIDES_EXPR"); el.addContent(left_e);
            	            }

            	            }


            	            }
            	            break;
            	        case 3 :
            	            // src/csc/cslite.g:246:22: ( MODS )
            	            {
            	            // src/csc/cslite.g:246:22: ( MODS )
            	            // src/csc/cslite.g:246:23: MODS
            	            {
            	            match(input,MODS,FOLLOW_MODS_in_term1148); if (state.failed) return el;
            	            if ( state.backtracking==0 ) {
            	               el = new Element("MODS_EXPR"); el.addContent(left_e);
            	            }

            	            }


            	            }
            	            break;

            	    }

            	    pushFollow(FOLLOW_factor_in_term1181);
            	    e=factor();

            	    state._fsp--;
            	    if (state.failed) return el;
            	    if ( state.backtracking==0 ) {
            	       el.addContent(e); left_e = el; one_sub = false; 
            	    }

            	    }
            	    break;

            	default :
            	    break loop14;
                }
            } while (true);

            if ( state.backtracking==0 ) {
               if (one_sub) 
                     el = left_e;
                 
            }

            }

        }
        catch (RecognitionException re) {
            reportError(re);
            recover(input,re);
        }
        finally {
        }
        return el;
    }
    // $ANTLR end "term"


    // $ANTLR start "factor"
    // src/csc/cslite.g:253:1: factor returns [Element el = null] : (id= ID | i= NUM | s= STRING | L_PAREN e= expr R_PAREN );
    public final Element factor() throws RecognitionException {
        Element el =  null;

        Token id=null;
        Token i=null;
        Token s=null;
        Element e = null;


        try {
            // src/csc/cslite.g:255:3: (id= ID | i= NUM | s= STRING | L_PAREN e= expr R_PAREN )
            int alt15=4;
            switch ( input.LA(1) ) {
            case ID:
                {
                alt15=1;
                }
                break;
            case NUM:
                {
                alt15=2;
                }
                break;
            case STRING:
                {
                alt15=3;
                }
                break;
            case L_PAREN:
                {
                alt15=4;
                }
                break;
            default:
                if (state.backtracking>0) {state.failed=true; return el;}
                NoViableAltException nvae =
                    new NoViableAltException("", 15, 0, input);

                throw nvae;
            }

            switch (alt15) {
                case 1 :
                    // src/csc/cslite.g:255:5: id= ID
                    {
                    id=(Token)match(input,ID,FOLLOW_ID_in_factor1239); if (state.failed) return el;
                    if ( state.backtracking==0 ) {
                       el = new Element("VAR");
                           el.setText(id.getText());
                         
                    }

                    }
                    break;
                case 2 :
                    // src/csc/cslite.g:259:5: i= NUM
                    {
                    i=(Token)match(input,NUM,FOLLOW_NUM_in_factor1252); if (state.failed) return el;
                    if ( state.backtracking==0 ) {
                       el = new Element("INT");
                           el.setText(i.getText());
                         
                    }

                    }
                    break;
                case 3 :
                    // src/csc/cslite.g:263:5: s= STRING
                    {
                    s=(Token)match(input,STRING,FOLLOW_STRING_in_factor1265); if (state.failed) return el;
                    if ( state.backtracking==0 ) {
                       el = new Element("STRING");
                           el.setText(s.getText());
                         
                    }

                    }
                    break;
                case 4 :
                    // src/csc/cslite.g:267:5: L_PAREN e= expr R_PAREN
                    {
                    match(input,L_PAREN,FOLLOW_L_PAREN_in_factor1276); if (state.failed) return el;
                    pushFollow(FOLLOW_expr_in_factor1282);
                    e=expr();

                    state._fsp--;
                    if (state.failed) return el;
                    match(input,R_PAREN,FOLLOW_R_PAREN_in_factor1284); if (state.failed) return el;
                    if ( state.backtracking==0 ) {
                       el = e; 
                    }

                    }
                    break;

            }
        }
        catch (RecognitionException re) {
            reportError(re);
            recover(input,re);
        }
        finally {
        }
        return el;
    }
    // $ANTLR end "factor"

    // $ANTLR start synpred28_cslite
    public final void synpred28_cslite_fragment() throws RecognitionException {   
        // src/csc/cslite.g:221:4: ( ( PLUS | MINUS | EQ | NE | GT | LT | LE | GE | AND | OR | NOT ) e= term )
        // src/csc/cslite.g:221:4: ( PLUS | MINUS | EQ | NE | GT | LT | LE | GE | AND | OR | NOT ) e= term
        {
        if ( input.LA(1)==NOT||(input.LA(1)>=PLUS && input.LA(1)<=OR) ) {
            input.consume();
            state.errorRecovery=false;state.failed=false;
        }
        else {
            if (state.backtracking>0) {state.failed=true; return ;}
            MismatchedSetException mse = new MismatchedSetException(null,input);
            throw mse;
        }

        pushFollow(FOLLOW_term_in_synpred28_cslite1019);
        term();

        state._fsp--;
        if (state.failed) return ;

        }
    }
    // $ANTLR end synpred28_cslite

    // Delegated rules

    public final boolean synpred28_cslite() {
        state.backtracking++;
        int start = input.mark();
        try {
            synpred28_cslite_fragment(); // can never throw exception
        } catch (RecognitionException re) {
            System.err.println("impossible: "+re);
        }
        boolean success = !state.failed;
        input.rewind(start);
        state.backtracking--;
        state.failed=false;
        return success;
    }


    protected DFA1 dfa1 = new DFA1(this);
    protected DFA5 dfa5 = new DFA5(this);
    protected DFA7 dfa7 = new DFA7(this);
    protected DFA12 dfa12 = new DFA12(this);
    protected DFA11 dfa11 = new DFA11(this);
    protected DFA14 dfa14 = new DFA14(this);
    static final String DFA1_eotS =
        "\13\uffff";
    static final String DFA1_eofS =
        "\1\1\12\uffff";
    static final String DFA1_minS =
        "\1\4\12\uffff";
    static final String DFA1_maxS =
        "\1\25\12\uffff";
    static final String DFA1_acceptS =
        "\1\uffff\1\2\7\uffff\1\1\1\uffff";
    static final String DFA1_specialS =
        "\13\uffff}>";
    static final String[] DFA1_transitionS = {
            "\1\1\1\uffff\2\11\1\1\1\uffff\3\1\4\uffff\1\1\3\uffff\1\1",
            "",
            "",
            "",
            "",
            "",
            "",
            "",
            "",
            "",
            ""
    };

    static final short[] DFA1_eot = DFA.unpackEncodedString(DFA1_eotS);
    static final short[] DFA1_eof = DFA.unpackEncodedString(DFA1_eofS);
    static final char[] DFA1_min = DFA.unpackEncodedStringToUnsignedChars(DFA1_minS);
    static final char[] DFA1_max = DFA.unpackEncodedStringToUnsignedChars(DFA1_maxS);
    static final short[] DFA1_accept = DFA.unpackEncodedString(DFA1_acceptS);
    static final short[] DFA1_special = DFA.unpackEncodedString(DFA1_specialS);
    static final short[][] DFA1_transition;

    static {
        int numStates = DFA1_transitionS.length;
        DFA1_transition = new short[numStates][];
        for (int i=0; i<numStates; i++) {
            DFA1_transition[i] = DFA.unpackEncodedString(DFA1_transitionS[i]);
        }
    }

    class DFA1 extends DFA {

        public DFA1(BaseRecognizer recognizer) {
            this.recognizer = recognizer;
            this.decisionNumber = 1;
            this.eot = DFA1_eot;
            this.eof = DFA1_eof;
            this.min = DFA1_min;
            this.max = DFA1_max;
            this.accept = DFA1_accept;
            this.special = DFA1_special;
            this.transition = DFA1_transition;
        }
        public String getDescription() {
            return "()* loopback of 43:3: (e= var_def )*";
        }
    }
    static final String DFA5_eotS =
        "\15\uffff";
    static final String DFA5_eofS =
        "\15\uffff";
    static final String DFA5_minS =
        "\1\4\1\15\2\uffff\1\10\10\uffff";
    static final String DFA5_maxS =
        "\1\25\1\27\2\uffff\1\22\10\uffff";
    static final String DFA5_acceptS =
        "\2\uffff\1\2\1\4\1\uffff\1\7\1\10\1\11\1\1\1\3\1\uffff\1\6\1\5";
    static final String DFA5_specialS =
        "\15\uffff}>";
    static final String[] DFA5_transitionS = {
            "\1\1\3\uffff\1\3\1\uffff\1\7\1\6\1\5\4\uffff\1\4\3\uffff\1"+
            "\2",
            "\1\11\6\uffff\1\10\2\uffff\1\11",
            "",
            "",
            "\1\14\11\uffff\1\13",
            "",
            "",
            "",
            "",
            "",
            "",
            "",
            ""
    };

    static final short[] DFA5_eot = DFA.unpackEncodedString(DFA5_eotS);
    static final short[] DFA5_eof = DFA.unpackEncodedString(DFA5_eofS);
    static final char[] DFA5_min = DFA.unpackEncodedStringToUnsignedChars(DFA5_minS);
    static final char[] DFA5_max = DFA.unpackEncodedStringToUnsignedChars(DFA5_maxS);
    static final short[] DFA5_accept = DFA.unpackEncodedString(DFA5_acceptS);
    static final short[] DFA5_special = DFA.unpackEncodedString(DFA5_specialS);
    static final short[][] DFA5_transition;

    static {
        int numStates = DFA5_transitionS.length;
        DFA5_transition = new short[numStates][];
        for (int i=0; i<numStates; i++) {
            DFA5_transition[i] = DFA.unpackEncodedString(DFA5_transitionS[i]);
        }
    }

    class DFA5 extends DFA {

        public DFA5(BaseRecognizer recognizer) {
            this.recognizer = recognizer;
            this.decisionNumber = 5;
            this.eot = DFA5_eot;
            this.eof = DFA5_eof;
            this.min = DFA5_min;
            this.max = DFA5_max;
            this.accept = DFA5_accept;
            this.special = DFA5_special;
            this.transition = DFA5_transition;
        }
        public String getDescription() {
            return "79:1: stmt returns [Element el = null] : (e= assign_stmt SEMI | e= if_else_stmt | e= func_call SEMI | e= block | e= loop_until_uncond_stmt | e= while_stmt | e= for_stmt | e= break_stmt SEMI | e= not_stmt );";
        }
    }
    static final String DFA7_eotS =
        "\14\uffff";
    static final String DFA7_eofS =
        "\1\2\13\uffff";
    static final String DFA7_minS =
        "\1\4\13\uffff";
    static final String DFA7_maxS =
        "\1\26\13\uffff";
    static final String DFA7_acceptS =
        "\1\uffff\1\1\1\2\11\uffff";
    static final String DFA7_specialS =
        "\14\uffff}>";
    static final String[] DFA7_transitionS = {
            "\1\2\3\uffff\5\2\4\uffff\1\2\1\uffff\1\1\1\uffff\2\2",
            "",
            "",
            "",
            "",
            "",
            "",
            "",
            "",
            "",
            "",
            ""
    };

    static final short[] DFA7_eot = DFA.unpackEncodedString(DFA7_eotS);
    static final short[] DFA7_eof = DFA.unpackEncodedString(DFA7_eofS);
    static final char[] DFA7_min = DFA.unpackEncodedStringToUnsignedChars(DFA7_minS);
    static final char[] DFA7_max = DFA.unpackEncodedStringToUnsignedChars(DFA7_maxS);
    static final short[] DFA7_accept = DFA.unpackEncodedString(DFA7_acceptS);
    static final short[] DFA7_special = DFA.unpackEncodedString(DFA7_specialS);
    static final short[][] DFA7_transition;

    static {
        int numStates = DFA7_transitionS.length;
        DFA7_transition = new short[numStates][];
        for (int i=0; i<numStates; i++) {
            DFA7_transition[i] = DFA.unpackEncodedString(DFA7_transitionS[i]);
        }
    }

    class DFA7 extends DFA {

        public DFA7(BaseRecognizer recognizer) {
            this.recognizer = recognizer;
            this.decisionNumber = 7;
            this.eot = DFA7_eot;
            this.eof = DFA7_eof;
            this.min = DFA7_min;
            this.max = DFA7_max;
            this.accept = DFA7_accept;
            this.special = DFA7_special;
            this.transition = DFA7_transition;
        }
        public String getDescription() {
            return "160:16: ( UNTIL L_PAREN e= expr R_PAREN )?";
        }
    }
    static final String DFA12_eotS =
        "\34\uffff";
    static final String DFA12_eofS =
        "\1\1\33\uffff";
    static final String DFA12_minS =
        "\1\4\7\uffff\1\4\17\uffff\4\0";
    static final String DFA12_maxS =
        "\1\42\7\uffff\1\46\17\uffff\4\0";
    static final String DFA12_acceptS =
        "\1\uffff\1\2\14\uffff\1\1\15\uffff";
    static final String DFA12_specialS =
        "\30\uffff\1\0\1\1\1\2\1\3}>";
    static final String[] DFA12_transitionS = {
            "\2\1\2\uffff\2\1\1\10\2\1\3\uffff\2\1\3\uffff\2\1\1\uffff\1"+
            "\1\12\16",
            "",
            "",
            "",
            "",
            "",
            "",
            "",
            "\1\30\10\uffff\1\33\1\31\27\uffff\1\32",
            "",
            "",
            "",
            "",
            "",
            "",
            "",
            "",
            "",
            "",
            "",
            "",
            "",
            "",
            "",
            "\1\uffff",
            "\1\uffff",
            "\1\uffff",
            "\1\uffff"
    };

    static final short[] DFA12_eot = DFA.unpackEncodedString(DFA12_eotS);
    static final short[] DFA12_eof = DFA.unpackEncodedString(DFA12_eofS);
    static final char[] DFA12_min = DFA.unpackEncodedStringToUnsignedChars(DFA12_minS);
    static final char[] DFA12_max = DFA.unpackEncodedStringToUnsignedChars(DFA12_maxS);
    static final short[] DFA12_accept = DFA.unpackEncodedString(DFA12_acceptS);
    static final short[] DFA12_special = DFA.unpackEncodedString(DFA12_specialS);
    static final short[][] DFA12_transition;

    static {
        int numStates = DFA12_transitionS.length;
        DFA12_transition = new short[numStates][];
        for (int i=0; i<numStates; i++) {
            DFA12_transition[i] = DFA.unpackEncodedString(DFA12_transitionS[i]);
        }
    }

    class DFA12 extends DFA {

        public DFA12(BaseRecognizer recognizer) {
            this.recognizer = recognizer;
            this.decisionNumber = 12;
            this.eot = DFA12_eot;
            this.eof = DFA12_eof;
            this.min = DFA12_min;
            this.max = DFA12_max;
            this.accept = DFA12_accept;
            this.special = DFA12_special;
            this.transition = DFA12_transition;
        }
        public String getDescription() {
            return "()* loopback of 221:3: ( ( PLUS | MINUS | EQ | NE | GT | LT | LE | GE | AND | OR | NOT ) e= term )*";
        }
        public int specialStateTransition(int s, IntStream _input) throws NoViableAltException {
            TokenStream input = (TokenStream)_input;
        	int _s = s;
            switch ( s ) {
                    case 0 : 
                        input.LA(1);

                         
                        int index12_24 = input.index();
                        input.rewind();
                        s = -1;
                        if ( (synpred28_cslite()) ) {s = 14;}

                        else if ( (true) ) {s = 1;}

                         
                        input.seek(index12_24);
                        if ( s>=0 ) return s;
                        break;
                    case 1 : 
                        input.LA(1);

                         
                        int index12_25 = input.index();
                        input.rewind();
                        s = -1;
                        if ( (synpred28_cslite()) ) {s = 14;}

                        else if ( (true) ) {s = 1;}

                         
                        input.seek(index12_25);
                        if ( s>=0 ) return s;
                        break;
                    case 2 : 
                        input.LA(1);

                         
                        int index12_26 = input.index();
                        input.rewind();
                        s = -1;
                        if ( (synpred28_cslite()) ) {s = 14;}

                        else if ( (true) ) {s = 1;}

                         
                        input.seek(index12_26);
                        if ( s>=0 ) return s;
                        break;
                    case 3 : 
                        input.LA(1);

                         
                        int index12_27 = input.index();
                        input.rewind();
                        s = -1;
                        if ( (synpred28_cslite()) ) {s = 14;}

                        else if ( (true) ) {s = 1;}

                         
                        input.seek(index12_27);
                        if ( s>=0 ) return s;
                        break;
            }
            if (state.backtracking>0) {state.failed=true; return -1;}
            NoViableAltException nvae =
                new NoViableAltException(getDescription(), 12, _s, input);
            error(nvae);
            throw nvae;
        }
    }
    static final String DFA11_eotS =
        "\14\uffff";
    static final String DFA11_eofS =
        "\14\uffff";
    static final String DFA11_minS =
        "\1\12\13\uffff";
    static final String DFA11_maxS =
        "\1\42\13\uffff";
    static final String DFA11_acceptS =
        "\1\uffff\1\1\1\2\1\3\1\4\1\5\1\6\1\7\1\10\1\11\1\12\1\13";
    static final String DFA11_specialS =
        "\14\uffff}>";
    static final String[] DFA11_transitionS = {
            "\1\13\16\uffff\1\1\1\2\1\3\1\4\1\5\1\6\1\7\1\10\1\11\1\12",
            "",
            "",
            "",
            "",
            "",
            "",
            "",
            "",
            "",
            "",
            ""
    };

    static final short[] DFA11_eot = DFA.unpackEncodedString(DFA11_eotS);
    static final short[] DFA11_eof = DFA.unpackEncodedString(DFA11_eofS);
    static final char[] DFA11_min = DFA.unpackEncodedStringToUnsignedChars(DFA11_minS);
    static final char[] DFA11_max = DFA.unpackEncodedStringToUnsignedChars(DFA11_maxS);
    static final short[] DFA11_accept = DFA.unpackEncodedString(DFA11_acceptS);
    static final short[] DFA11_special = DFA.unpackEncodedString(DFA11_specialS);
    static final short[][] DFA11_transition;

    static {
        int numStates = DFA11_transitionS.length;
        DFA11_transition = new short[numStates][];
        for (int i=0; i<numStates; i++) {
            DFA11_transition[i] = DFA.unpackEncodedString(DFA11_transitionS[i]);
        }
    }

    class DFA11 extends DFA {

        public DFA11(BaseRecognizer recognizer) {
            this.recognizer = recognizer;
            this.decisionNumber = 11;
            this.eot = DFA11_eot;
            this.eof = DFA11_eof;
            this.min = DFA11_min;
            this.max = DFA11_max;
            this.accept = DFA11_accept;
            this.special = DFA11_special;
            this.transition = DFA11_transition;
        }
        public String getDescription() {
            return "221:4: ( PLUS | MINUS | EQ | NE | GT | LT | LE | GE | AND | OR | NOT )";
        }
    }
    static final String DFA14_eotS =
        "\33\uffff";
    static final String DFA14_eofS =
        "\1\1\32\uffff";
    static final String DFA14_minS =
        "\1\4\32\uffff";
    static final String DFA14_maxS =
        "\1\45\32\uffff";
    static final String DFA14_acceptS =
        "\1\uffff\1\2\26\uffff\1\1\2\uffff";
    static final String DFA14_specialS =
        "\33\uffff}>";
    static final String[] DFA14_transitionS = {
            "\2\1\2\uffff\5\1\3\uffff\2\1\3\uffff\2\1\1\uffff\13\1\3\30",
            "",
            "",
            "",
            "",
            "",
            "",
            "",
            "",
            "",
            "",
            "",
            "",
            "",
            "",
            "",
            "",
            "",
            "",
            "",
            "",
            "",
            "",
            "",
            "",
            "",
            ""
    };

    static final short[] DFA14_eot = DFA.unpackEncodedString(DFA14_eotS);
    static final short[] DFA14_eof = DFA.unpackEncodedString(DFA14_eofS);
    static final char[] DFA14_min = DFA.unpackEncodedStringToUnsignedChars(DFA14_minS);
    static final char[] DFA14_max = DFA.unpackEncodedStringToUnsignedChars(DFA14_maxS);
    static final short[] DFA14_accept = DFA.unpackEncodedString(DFA14_acceptS);
    static final short[] DFA14_special = DFA.unpackEncodedString(DFA14_specialS);
    static final short[][] DFA14_transition;

    static {
        int numStates = DFA14_transitionS.length;
        DFA14_transition = new short[numStates][];
        for (int i=0; i<numStates; i++) {
            DFA14_transition[i] = DFA.unpackEncodedString(DFA14_transitionS[i]);
        }
    }

    class DFA14 extends DFA {

        public DFA14(BaseRecognizer recognizer) {
            this.recognizer = recognizer;
            this.decisionNumber = 14;
            this.eot = DFA14_eot;
            this.eof = DFA14_eof;
            this.min = DFA14_min;
            this.max = DFA14_max;
            this.accept = DFA14_accept;
            this.special = DFA14_special;
            this.transition = DFA14_transition;
        }
        public String getDescription() {
            return "()* loopback of 244:4: ( ( ( TIMES ) | ( DIVIDES ) | ( MODS ) ) e= factor )*";
        }
    }
 

    public static final BitSet FOLLOW_data_sec_in_program69 = new BitSet(new long[]{0x0000000000221D10L});
    public static final BitSet FOLLOW_code_sec_in_program78 = new BitSet(new long[]{0x0000000000000000L});
    public static final BitSet FOLLOW_EOF_in_program82 = new BitSet(new long[]{0x0000000000000002L});
    public static final BitSet FOLLOW_var_def_in_data_sec99 = new BitSet(new long[]{0x00000000000000C2L});
    public static final BitSet FOLLOW_stmt_in_code_sec122 = new BitSet(new long[]{0x0000000000221D12L});
    public static final BitSet FOLLOW_base_type_in_var_def147 = new BitSet(new long[]{0x0000000000000010L});
    public static final BitSet FOLLOW_ID_in_var_def149 = new BitSet(new long[]{0x0000000000000020L});
    public static final BitSet FOLLOW_SEMI_in_var_def151 = new BitSet(new long[]{0x0000000000000002L});
    public static final BitSet FOLLOW_INT_in_base_type171 = new BitSet(new long[]{0x0000000000000002L});
    public static final BitSet FOLLOW_BYTE_in_base_type182 = new BitSet(new long[]{0x0000000000000002L});
    public static final BitSet FOLLOW_L_CURLY_in_block203 = new BitSet(new long[]{0x0000000000221F10L});
    public static final BitSet FOLLOW_stmt_in_block211 = new BitSet(new long[]{0x0000000000221F10L});
    public static final BitSet FOLLOW_R_CURLY_in_block218 = new BitSet(new long[]{0x0000000000000002L});
    public static final BitSet FOLLOW_assign_stmt_in_stmt238 = new BitSet(new long[]{0x0000000000000020L});
    public static final BitSet FOLLOW_SEMI_in_stmt240 = new BitSet(new long[]{0x0000000000000002L});
    public static final BitSet FOLLOW_if_else_stmt_in_stmt252 = new BitSet(new long[]{0x0000000000000002L});
    public static final BitSet FOLLOW_func_call_in_stmt265 = new BitSet(new long[]{0x0000000000000020L});
    public static final BitSet FOLLOW_SEMI_in_stmt267 = new BitSet(new long[]{0x0000000000000002L});
    public static final BitSet FOLLOW_block_in_stmt280 = new BitSet(new long[]{0x0000000000000002L});
    public static final BitSet FOLLOW_loop_until_uncond_stmt_in_stmt293 = new BitSet(new long[]{0x0000000000000002L});
    public static final BitSet FOLLOW_while_stmt_in_stmt305 = new BitSet(new long[]{0x0000000000000002L});
    public static final BitSet FOLLOW_for_stmt_in_stmt317 = new BitSet(new long[]{0x0000000000000002L});
    public static final BitSet FOLLOW_break_stmt_in_stmt329 = new BitSet(new long[]{0x0000000000000020L});
    public static final BitSet FOLLOW_SEMI_in_stmt331 = new BitSet(new long[]{0x0000000000000002L});
    public static final BitSet FOLLOW_not_stmt_in_stmt343 = new BitSet(new long[]{0x0000000000000002L});
    public static final BitSet FOLLOW_NOT_in_not_stmt363 = new BitSet(new long[]{0x0000004000006010L});
    public static final BitSet FOLLOW_expr_in_not_stmt369 = new BitSet(new long[]{0x0000000000000002L});
    public static final BitSet FOLLOW_BREAK_in_break_stmt387 = new BitSet(new long[]{0x0000000000000002L});
    public static final BitSet FOLLOW_FOR_in_for_stmt414 = new BitSet(new long[]{0x0000000000000010L});
    public static final BitSet FOLLOW_ID_in_for_stmt419 = new BitSet(new long[]{0x0000000000002000L});
    public static final BitSet FOLLOW_L_PAREN_in_for_stmt423 = new BitSet(new long[]{0x0000000000004000L});
    public static final BitSet FOLLOW_NUM_in_for_stmt427 = new BitSet(new long[]{0x0000000000008000L});
    public static final BitSet FOLLOW_COLON_in_for_stmt431 = new BitSet(new long[]{0x0000000000004000L});
    public static final BitSet FOLLOW_NUM_in_for_stmt435 = new BitSet(new long[]{0x0000000000018000L});
    public static final BitSet FOLLOW_COLON_in_for_stmt440 = new BitSet(new long[]{0x0000000000004000L});
    public static final BitSet FOLLOW_NUM_in_for_stmt444 = new BitSet(new long[]{0x0000000000010000L});
    public static final BitSet FOLLOW_R_PAREN_in_for_stmt450 = new BitSet(new long[]{0x0000000000000100L});
    public static final BitSet FOLLOW_block_in_for_stmt454 = new BitSet(new long[]{0x0000000000000002L});
    public static final BitSet FOLLOW_LOOP_in_while_stmt477 = new BitSet(new long[]{0x0000000000040000L});
    public static final BitSet FOLLOW_WHILE_in_while_stmt479 = new BitSet(new long[]{0x0000000000002000L});
    public static final BitSet FOLLOW_L_PAREN_in_while_stmt481 = new BitSet(new long[]{0x0000004000006010L});
    public static final BitSet FOLLOW_expr_in_while_stmt487 = new BitSet(new long[]{0x0000000000010000L});
    public static final BitSet FOLLOW_R_PAREN_in_while_stmt489 = new BitSet(new long[]{0x0000000000000100L});
    public static final BitSet FOLLOW_block_in_while_stmt493 = new BitSet(new long[]{0x0000000000000002L});
    public static final BitSet FOLLOW_LOOP_in_loop_until_uncond_stmt520 = new BitSet(new long[]{0x0000000000000100L});
    public static final BitSet FOLLOW_block_in_loop_until_uncond_stmt524 = new BitSet(new long[]{0x0000000000080002L});
    public static final BitSet FOLLOW_UNTIL_in_loop_until_uncond_stmt527 = new BitSet(new long[]{0x0000000000002000L});
    public static final BitSet FOLLOW_L_PAREN_in_loop_until_uncond_stmt529 = new BitSet(new long[]{0x0000004000006010L});
    public static final BitSet FOLLOW_expr_in_loop_until_uncond_stmt533 = new BitSet(new long[]{0x0000000000010000L});
    public static final BitSet FOLLOW_R_PAREN_in_loop_until_uncond_stmt535 = new BitSet(new long[]{0x0000000000000002L});
    public static final BitSet FOLLOW_ID_in_assign_stmt572 = new BitSet(new long[]{0x0000000000100000L});
    public static final BitSet FOLLOW_ASSIGN_in_assign_stmt574 = new BitSet(new long[]{0x0000004000006010L});
    public static final BitSet FOLLOW_expr_in_assign_stmt578 = new BitSet(new long[]{0x0000000000000002L});
    public static final BitSet FOLLOW_IF_in_if_else_stmt599 = new BitSet(new long[]{0x0000000000002000L});
    public static final BitSet FOLLOW_L_PAREN_in_if_else_stmt601 = new BitSet(new long[]{0x0000004000006010L});
    public static final BitSet FOLLOW_expr_in_if_else_stmt607 = new BitSet(new long[]{0x0000000000010000L});
    public static final BitSet FOLLOW_R_PAREN_in_if_else_stmt609 = new BitSet(new long[]{0x0000000000221D10L});
    public static final BitSet FOLLOW_stmt_in_if_else_stmt615 = new BitSet(new long[]{0x0000000000400000L});
    public static final BitSet FOLLOW_ELSE_in_if_else_stmt617 = new BitSet(new long[]{0x0000000000221D10L});
    public static final BitSet FOLLOW_stmt_in_if_else_stmt623 = new BitSet(new long[]{0x0000000000000002L});
    public static final BitSet FOLLOW_ID_in_func_call650 = new BitSet(new long[]{0x0000000000802000L});
    public static final BitSet FOLLOW_DOT_in_func_call660 = new BitSet(new long[]{0x0000000000000010L});
    public static final BitSet FOLLOW_ID_in_func_call664 = new BitSet(new long[]{0x0000000000802000L});
    public static final BitSet FOLLOW_L_PAREN_in_func_call682 = new BitSet(new long[]{0x0000004000016010L});
    public static final BitSet FOLLOW_expr_in_func_call689 = new BitSet(new long[]{0x0000000001010000L});
    public static final BitSet FOLLOW_COMMA_in_func_call694 = new BitSet(new long[]{0x0000004000006010L});
    public static final BitSet FOLLOW_expr_in_func_call700 = new BitSet(new long[]{0x0000000001010000L});
    public static final BitSet FOLLOW_R_PAREN_in_func_call709 = new BitSet(new long[]{0x0000000000000002L});
    public static final BitSet FOLLOW_term_in_expr734 = new BitSet(new long[]{0x00000007FE000402L});
    public static final BitSet FOLLOW_PLUS_in_expr742 = new BitSet(new long[]{0x0000004000006010L});
    public static final BitSet FOLLOW_MINUS_in_expr765 = new BitSet(new long[]{0x0000004000006010L});
    public static final BitSet FOLLOW_EQ_in_expr789 = new BitSet(new long[]{0x0000004000006010L});
    public static final BitSet FOLLOW_NE_in_expr812 = new BitSet(new long[]{0x0000004000006010L});
    public static final BitSet FOLLOW_GT_in_expr835 = new BitSet(new long[]{0x0000004000006010L});
    public static final BitSet FOLLOW_LT_in_expr858 = new BitSet(new long[]{0x0000004000006010L});
    public static final BitSet FOLLOW_LE_in_expr881 = new BitSet(new long[]{0x0000004000006010L});
    public static final BitSet FOLLOW_GE_in_expr904 = new BitSet(new long[]{0x0000004000006010L});
    public static final BitSet FOLLOW_AND_in_expr927 = new BitSet(new long[]{0x0000004000006010L});
    public static final BitSet FOLLOW_OR_in_expr950 = new BitSet(new long[]{0x0000004000006010L});
    public static final BitSet FOLLOW_NOT_in_expr973 = new BitSet(new long[]{0x0000004000006010L});
    public static final BitSet FOLLOW_term_in_expr1019 = new BitSet(new long[]{0x00000007FE000402L});
    public static final BitSet FOLLOW_factor_in_term1082 = new BitSet(new long[]{0x0000003800000002L});
    public static final BitSet FOLLOW_TIMES_in_term1092 = new BitSet(new long[]{0x0000004000006010L});
    public static final BitSet FOLLOW_DIVIDES_in_term1120 = new BitSet(new long[]{0x0000004000006010L});
    public static final BitSet FOLLOW_MODS_in_term1148 = new BitSet(new long[]{0x0000004000006010L});
    public static final BitSet FOLLOW_factor_in_term1181 = new BitSet(new long[]{0x0000003800000002L});
    public static final BitSet FOLLOW_ID_in_factor1239 = new BitSet(new long[]{0x0000000000000002L});
    public static final BitSet FOLLOW_NUM_in_factor1252 = new BitSet(new long[]{0x0000000000000002L});
    public static final BitSet FOLLOW_STRING_in_factor1265 = new BitSet(new long[]{0x0000000000000002L});
    public static final BitSet FOLLOW_L_PAREN_in_factor1276 = new BitSet(new long[]{0x0000004000006010L});
    public static final BitSet FOLLOW_expr_in_factor1282 = new BitSet(new long[]{0x0000000000010000L});
    public static final BitSet FOLLOW_R_PAREN_in_factor1284 = new BitSet(new long[]{0x0000000000000002L});
    public static final BitSet FOLLOW_set_in_synpred28_cslite741 = new BitSet(new long[]{0x0000004000006010L});
    public static final BitSet FOLLOW_term_in_synpred28_cslite1019 = new BitSet(new long[]{0x0000000000000002L});

}