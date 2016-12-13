// $ANTLR 3.1.3 Mar 18, 2009 10:09:25 src/csc/cslite.g 2009-05-10 19:47:43

package csc;


import org.antlr.runtime.*;
import java.util.Stack;
import java.util.List;
import java.util.ArrayList;

@SuppressWarnings("unused")
public class csliteLexer extends Lexer {
    public static final int LT=30;
    public static final int WHILE=18;
    public static final int FOR=12;
    public static final int NOT=10;
    public static final int AND=33;
    public static final int ID=4;
    public static final int EOF=-1;
    public static final int BREAK=11;
    public static final int IF=21;
    public static final int R_CURLY=9;
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

    public csliteLexer() {;} 
    public csliteLexer(CharStream input) {
        this(input, new RecognizerSharedState());
    }
    public csliteLexer(CharStream input, RecognizerSharedState state) {
        super(input,state);

    }
    public String getGrammarFileName() { return "src/csc/cslite.g"; }

    // $ANTLR start "INT"
    public final void mINT() throws RecognitionException {
        try {
            int _type = INT;
            int _channel = DEFAULT_TOKEN_CHANNEL;
            // src/csc/cslite.g:271:5: ( 'int' )
            // src/csc/cslite.g:271:7: 'int'
            {
            match("int"); 


            }

            state.type = _type;
            state.channel = _channel;
        }
        finally {
        }
    }
    // $ANTLR end "INT"

    // $ANTLR start "BYTE"
    public final void mBYTE() throws RecognitionException {
        try {
            int _type = BYTE;
            int _channel = DEFAULT_TOKEN_CHANNEL;
            // src/csc/cslite.g:272:6: ( 'byte' )
            // src/csc/cslite.g:272:8: 'byte'
            {
            match("byte"); 


            }

            state.type = _type;
            state.channel = _channel;
        }
        finally {
        }
    }
    // $ANTLR end "BYTE"

    // $ANTLR start "IF"
    public final void mIF() throws RecognitionException {
        try {
            int _type = IF;
            int _channel = DEFAULT_TOKEN_CHANNEL;
            // src/csc/cslite.g:273:4: ( 'if' )
            // src/csc/cslite.g:273:6: 'if'
            {
            match("if"); 


            }

            state.type = _type;
            state.channel = _channel;
        }
        finally {
        }
    }
    // $ANTLR end "IF"

    // $ANTLR start "ELSE"
    public final void mELSE() throws RecognitionException {
        try {
            int _type = ELSE;
            int _channel = DEFAULT_TOKEN_CHANNEL;
            // src/csc/cslite.g:274:6: ( 'else' )
            // src/csc/cslite.g:274:8: 'else'
            {
            match("else"); 


            }

            state.type = _type;
            state.channel = _channel;
        }
        finally {
        }
    }
    // $ANTLR end "ELSE"

    // $ANTLR start "BREAK"
    public final void mBREAK() throws RecognitionException {
        try {
            int _type = BREAK;
            int _channel = DEFAULT_TOKEN_CHANNEL;
            // src/csc/cslite.g:276:6: ( 'break' )
            // src/csc/cslite.g:276:8: 'break'
            {
            match("break"); 


            }

            state.type = _type;
            state.channel = _channel;
        }
        finally {
        }
    }
    // $ANTLR end "BREAK"

    // $ANTLR start "LOOP"
    public final void mLOOP() throws RecognitionException {
        try {
            int _type = LOOP;
            int _channel = DEFAULT_TOKEN_CHANNEL;
            // src/csc/cslite.g:277:5: ( 'loop' )
            // src/csc/cslite.g:277:7: 'loop'
            {
            match("loop"); 


            }

            state.type = _type;
            state.channel = _channel;
        }
        finally {
        }
    }
    // $ANTLR end "LOOP"

    // $ANTLR start "WHILE"
    public final void mWHILE() throws RecognitionException {
        try {
            int _type = WHILE;
            int _channel = DEFAULT_TOKEN_CHANNEL;
            // src/csc/cslite.g:278:6: ( 'while' )
            // src/csc/cslite.g:278:8: 'while'
            {
            match("while"); 


            }

            state.type = _type;
            state.channel = _channel;
        }
        finally {
        }
    }
    // $ANTLR end "WHILE"

    // $ANTLR start "UNTIL"
    public final void mUNTIL() throws RecognitionException {
        try {
            int _type = UNTIL;
            int _channel = DEFAULT_TOKEN_CHANNEL;
            // src/csc/cslite.g:279:6: ( 'until' )
            // src/csc/cslite.g:279:8: 'until'
            {
            match("until"); 


            }

            state.type = _type;
            state.channel = _channel;
        }
        finally {
        }
    }
    // $ANTLR end "UNTIL"

    // $ANTLR start "FOR"
    public final void mFOR() throws RecognitionException {
        try {
            int _type = FOR;
            int _channel = DEFAULT_TOKEN_CHANNEL;
            // src/csc/cslite.g:280:4: ( 'for' )
            // src/csc/cslite.g:280:6: 'for'
            {
            match("for"); 


            }

            state.type = _type;
            state.channel = _channel;
        }
        finally {
        }
    }
    // $ANTLR end "FOR"

    // $ANTLR start "WS"
    public final void mWS() throws RecognitionException {
        try {
            int _type = WS;
            int _channel = DEFAULT_TOKEN_CHANNEL;
            // src/csc/cslite.g:288:4: ( ( ' ' | '\\t' | '\\n' | '\\r' ) )
            // src/csc/cslite.g:288:6: ( ' ' | '\\t' | '\\n' | '\\r' )
            {
            if ( (input.LA(1)>='\t' && input.LA(1)<='\n')||input.LA(1)=='\r'||input.LA(1)==' ' ) {
                input.consume();

            }
            else {
                MismatchedSetException mse = new MismatchedSetException(null,input);
                recover(mse);
                throw mse;}

              _channel=HIDDEN; 

            }

            state.type = _type;
            state.channel = _channel;
        }
        finally {
        }
    }
    // $ANTLR end "WS"

    // $ANTLR start "COMMENT"
    public final void mCOMMENT() throws RecognitionException {
        try {
            int _type = COMMENT;
            int _channel = DEFAULT_TOKEN_CHANNEL;
            // src/csc/cslite.g:293:5: ( '/*' ( options {greedy=false; } : . )* '*/' )
            // src/csc/cslite.g:293:9: '/*' ( options {greedy=false; } : . )* '*/'
            {
            match("/*"); 

            // src/csc/cslite.g:293:14: ( options {greedy=false; } : . )*
            loop1:
            do {
                int alt1=2;
                int LA1_0 = input.LA(1);

                if ( (LA1_0=='*') ) {
                    int LA1_1 = input.LA(2);

                    if ( (LA1_1=='/') ) {
                        alt1=2;
                    }
                    else if ( ((LA1_1>='\u0000' && LA1_1<='.')||(LA1_1>='0' && LA1_1<='\uFFFF')) ) {
                        alt1=1;
                    }


                }
                else if ( ((LA1_0>='\u0000' && LA1_0<=')')||(LA1_0>='+' && LA1_0<='\uFFFF')) ) {
                    alt1=1;
                }


                switch (alt1) {
            	case 1 :
            	    // src/csc/cslite.g:293:42: .
            	    {
            	    matchAny(); 

            	    }
            	    break;

            	default :
            	    break loop1;
                }
            } while (true);

            match("*/"); 

            _channel=HIDDEN;

            }

            state.type = _type;
            state.channel = _channel;
        }
        finally {
        }
    }
    // $ANTLR end "COMMENT"

    // $ANTLR start "LINE_COMMENT"
    public final void mLINE_COMMENT() throws RecognitionException {
        try {
            int _type = LINE_COMMENT;
            int _channel = DEFAULT_TOKEN_CHANNEL;
            // src/csc/cslite.g:297:5: ( '//' (~ ( '\\n' | '\\r' ) )* ( '\\r' )? '\\n' )
            // src/csc/cslite.g:297:7: '//' (~ ( '\\n' | '\\r' ) )* ( '\\r' )? '\\n'
            {
            match("//"); 

            // src/csc/cslite.g:297:12: (~ ( '\\n' | '\\r' ) )*
            loop2:
            do {
                int alt2=2;
                int LA2_0 = input.LA(1);

                if ( ((LA2_0>='\u0000' && LA2_0<='\t')||(LA2_0>='\u000B' && LA2_0<='\f')||(LA2_0>='\u000E' && LA2_0<='\uFFFF')) ) {
                    alt2=1;
                }


                switch (alt2) {
            	case 1 :
            	    // src/csc/cslite.g:297:12: ~ ( '\\n' | '\\r' )
            	    {
            	    if ( (input.LA(1)>='\u0000' && input.LA(1)<='\t')||(input.LA(1)>='\u000B' && input.LA(1)<='\f')||(input.LA(1)>='\u000E' && input.LA(1)<='\uFFFF') ) {
            	        input.consume();

            	    }
            	    else {
            	        MismatchedSetException mse = new MismatchedSetException(null,input);
            	        recover(mse);
            	        throw mse;}


            	    }
            	    break;

            	default :
            	    break loop2;
                }
            } while (true);

            // src/csc/cslite.g:297:26: ( '\\r' )?
            int alt3=2;
            int LA3_0 = input.LA(1);

            if ( (LA3_0=='\r') ) {
                alt3=1;
            }
            switch (alt3) {
                case 1 :
                    // src/csc/cslite.g:297:26: '\\r'
                    {
                    match('\r'); 

                    }
                    break;

            }

            match('\n'); 
            _channel=HIDDEN;

            }

            state.type = _type;
            state.channel = _channel;
        }
        finally {
        }
    }
    // $ANTLR end "LINE_COMMENT"

    // $ANTLR start "L_PAREN"
    public final void mL_PAREN() throws RecognitionException {
        try {
            int _type = L_PAREN;
            int _channel = DEFAULT_TOKEN_CHANNEL;
            // src/csc/cslite.g:300:9: ( '(' )
            // src/csc/cslite.g:300:11: '('
            {
            match('('); 

            }

            state.type = _type;
            state.channel = _channel;
        }
        finally {
        }
    }
    // $ANTLR end "L_PAREN"

    // $ANTLR start "R_PAREN"
    public final void mR_PAREN() throws RecognitionException {
        try {
            int _type = R_PAREN;
            int _channel = DEFAULT_TOKEN_CHANNEL;
            // src/csc/cslite.g:301:9: ( ')' )
            // src/csc/cslite.g:301:11: ')'
            {
            match(')'); 

            }

            state.type = _type;
            state.channel = _channel;
        }
        finally {
        }
    }
    // $ANTLR end "R_PAREN"

    // $ANTLR start "L_CURLY"
    public final void mL_CURLY() throws RecognitionException {
        try {
            int _type = L_CURLY;
            int _channel = DEFAULT_TOKEN_CHANNEL;
            // src/csc/cslite.g:303:9: ( '{' )
            // src/csc/cslite.g:303:11: '{'
            {
            match('{'); 

            }

            state.type = _type;
            state.channel = _channel;
        }
        finally {
        }
    }
    // $ANTLR end "L_CURLY"

    // $ANTLR start "R_CURLY"
    public final void mR_CURLY() throws RecognitionException {
        try {
            int _type = R_CURLY;
            int _channel = DEFAULT_TOKEN_CHANNEL;
            // src/csc/cslite.g:304:9: ( '}' )
            // src/csc/cslite.g:304:11: '}'
            {
            match('}'); 

            }

            state.type = _type;
            state.channel = _channel;
        }
        finally {
        }
    }
    // $ANTLR end "R_CURLY"

    // $ANTLR start "PLUS"
    public final void mPLUS() throws RecognitionException {
        try {
            int _type = PLUS;
            int _channel = DEFAULT_TOKEN_CHANNEL;
            // src/csc/cslite.g:306:6: ( '+' )
            // src/csc/cslite.g:306:8: '+'
            {
            match('+'); 

            }

            state.type = _type;
            state.channel = _channel;
        }
        finally {
        }
    }
    // $ANTLR end "PLUS"

    // $ANTLR start "MINUS"
    public final void mMINUS() throws RecognitionException {
        try {
            int _type = MINUS;
            int _channel = DEFAULT_TOKEN_CHANNEL;
            // src/csc/cslite.g:307:7: ( '-' )
            // src/csc/cslite.g:307:9: '-'
            {
            match('-'); 

            }

            state.type = _type;
            state.channel = _channel;
        }
        finally {
        }
    }
    // $ANTLR end "MINUS"

    // $ANTLR start "TIMES"
    public final void mTIMES() throws RecognitionException {
        try {
            int _type = TIMES;
            int _channel = DEFAULT_TOKEN_CHANNEL;
            // src/csc/cslite.g:308:7: ( '*' )
            // src/csc/cslite.g:308:9: '*'
            {
            match('*'); 

            }

            state.type = _type;
            state.channel = _channel;
        }
        finally {
        }
    }
    // $ANTLR end "TIMES"

    // $ANTLR start "DIVIDES"
    public final void mDIVIDES() throws RecognitionException {
        try {
            int _type = DIVIDES;
            int _channel = DEFAULT_TOKEN_CHANNEL;
            // src/csc/cslite.g:309:9: ( '/' )
            // src/csc/cslite.g:309:11: '/'
            {
            match('/'); 

            }

            state.type = _type;
            state.channel = _channel;
        }
        finally {
        }
    }
    // $ANTLR end "DIVIDES"

    // $ANTLR start "MODS"
    public final void mMODS() throws RecognitionException {
        try {
            int _type = MODS;
            int _channel = DEFAULT_TOKEN_CHANNEL;
            // src/csc/cslite.g:310:6: ( '%' )
            // src/csc/cslite.g:310:8: '%'
            {
            match('%'); 

            }

            state.type = _type;
            state.channel = _channel;
        }
        finally {
        }
    }
    // $ANTLR end "MODS"

    // $ANTLR start "ASSIGN"
    public final void mASSIGN() throws RecognitionException {
        try {
            int _type = ASSIGN;
            int _channel = DEFAULT_TOKEN_CHANNEL;
            // src/csc/cslite.g:312:8: ( '=' )
            // src/csc/cslite.g:312:10: '='
            {
            match('='); 

            }

            state.type = _type;
            state.channel = _channel;
        }
        finally {
        }
    }
    // $ANTLR end "ASSIGN"

    // $ANTLR start "SEMI"
    public final void mSEMI() throws RecognitionException {
        try {
            int _type = SEMI;
            int _channel = DEFAULT_TOKEN_CHANNEL;
            // src/csc/cslite.g:313:6: ( ';' )
            // src/csc/cslite.g:313:8: ';'
            {
            match(';'); 

            }

            state.type = _type;
            state.channel = _channel;
        }
        finally {
        }
    }
    // $ANTLR end "SEMI"

    // $ANTLR start "COMMA"
    public final void mCOMMA() throws RecognitionException {
        try {
            int _type = COMMA;
            int _channel = DEFAULT_TOKEN_CHANNEL;
            // src/csc/cslite.g:314:7: ( ',' )
            // src/csc/cslite.g:314:9: ','
            {
            match(','); 

            }

            state.type = _type;
            state.channel = _channel;
        }
        finally {
        }
    }
    // $ANTLR end "COMMA"

    // $ANTLR start "COLON"
    public final void mCOLON() throws RecognitionException {
        try {
            int _type = COLON;
            int _channel = DEFAULT_TOKEN_CHANNEL;
            // src/csc/cslite.g:315:6: ( ':' )
            // src/csc/cslite.g:315:8: ':'
            {
            match(':'); 

            }

            state.type = _type;
            state.channel = _channel;
        }
        finally {
        }
    }
    // $ANTLR end "COLON"

    // $ANTLR start "DOT"
    public final void mDOT() throws RecognitionException {
        try {
            int _type = DOT;
            int _channel = DEFAULT_TOKEN_CHANNEL;
            // src/csc/cslite.g:316:5: ( '.' )
            // src/csc/cslite.g:316:7: '.'
            {
            match('.'); 

            }

            state.type = _type;
            state.channel = _channel;
        }
        finally {
        }
    }
    // $ANTLR end "DOT"

    // $ANTLR start "NOT"
    public final void mNOT() throws RecognitionException {
        try {
            int _type = NOT;
            int _channel = DEFAULT_TOKEN_CHANNEL;
            // src/csc/cslite.g:317:5: ( '!' )
            // src/csc/cslite.g:317:7: '!'
            {
            match('!'); 

            }

            state.type = _type;
            state.channel = _channel;
        }
        finally {
        }
    }
    // $ANTLR end "NOT"

    // $ANTLR start "AND"
    public final void mAND() throws RecognitionException {
        try {
            int _type = AND;
            int _channel = DEFAULT_TOKEN_CHANNEL;
            // src/csc/cslite.g:318:5: ( '&&' )
            // src/csc/cslite.g:318:7: '&&'
            {
            match("&&"); 


            }

            state.type = _type;
            state.channel = _channel;
        }
        finally {
        }
    }
    // $ANTLR end "AND"

    // $ANTLR start "OR"
    public final void mOR() throws RecognitionException {
        try {
            int _type = OR;
            int _channel = DEFAULT_TOKEN_CHANNEL;
            // src/csc/cslite.g:319:4: ( '||' )
            // src/csc/cslite.g:319:6: '||'
            {
            match("||"); 


            }

            state.type = _type;
            state.channel = _channel;
        }
        finally {
        }
    }
    // $ANTLR end "OR"

    // $ANTLR start "EQ"
    public final void mEQ() throws RecognitionException {
        try {
            int _type = EQ;
            int _channel = DEFAULT_TOKEN_CHANNEL;
            // src/csc/cslite.g:320:4: ( '==' )
            // src/csc/cslite.g:320:6: '=='
            {
            match("=="); 


            }

            state.type = _type;
            state.channel = _channel;
        }
        finally {
        }
    }
    // $ANTLR end "EQ"

    // $ANTLR start "NE"
    public final void mNE() throws RecognitionException {
        try {
            int _type = NE;
            int _channel = DEFAULT_TOKEN_CHANNEL;
            // src/csc/cslite.g:321:3: ( '!=' )
            // src/csc/cslite.g:321:5: '!='
            {
            match("!="); 


            }

            state.type = _type;
            state.channel = _channel;
        }
        finally {
        }
    }
    // $ANTLR end "NE"

    // $ANTLR start "LE"
    public final void mLE() throws RecognitionException {
        try {
            int _type = LE;
            int _channel = DEFAULT_TOKEN_CHANNEL;
            // src/csc/cslite.g:322:3: ( '<=' )
            // src/csc/cslite.g:322:5: '<='
            {
            match("<="); 


            }

            state.type = _type;
            state.channel = _channel;
        }
        finally {
        }
    }
    // $ANTLR end "LE"

    // $ANTLR start "GE"
    public final void mGE() throws RecognitionException {
        try {
            int _type = GE;
            int _channel = DEFAULT_TOKEN_CHANNEL;
            // src/csc/cslite.g:323:3: ( '>=' )
            // src/csc/cslite.g:323:5: '>='
            {
            match(">="); 


            }

            state.type = _type;
            state.channel = _channel;
        }
        finally {
        }
    }
    // $ANTLR end "GE"

    // $ANTLR start "LT"
    public final void mLT() throws RecognitionException {
        try {
            int _type = LT;
            int _channel = DEFAULT_TOKEN_CHANNEL;
            // src/csc/cslite.g:324:4: ( '<' )
            // src/csc/cslite.g:324:6: '<'
            {
            match('<'); 

            }

            state.type = _type;
            state.channel = _channel;
        }
        finally {
        }
    }
    // $ANTLR end "LT"

    // $ANTLR start "GT"
    public final void mGT() throws RecognitionException {
        try {
            int _type = GT;
            int _channel = DEFAULT_TOKEN_CHANNEL;
            // src/csc/cslite.g:325:4: ( '>' )
            // src/csc/cslite.g:325:6: '>'
            {
            match('>'); 

            }

            state.type = _type;
            state.channel = _channel;
        }
        finally {
        }
    }
    // $ANTLR end "GT"

    // $ANTLR start "DIGIT"
    public final void mDIGIT() throws RecognitionException {
        try {
            // src/csc/cslite.g:328:7: ( '0' .. '9' )
            // src/csc/cslite.g:328:9: '0' .. '9'
            {
            matchRange('0','9'); 

            }

        }
        finally {
        }
    }
    // $ANTLR end "DIGIT"

    // $ANTLR start "ALPHA"
    public final void mALPHA() throws RecognitionException {
        try {
            // src/csc/cslite.g:331:7: ( 'a' .. 'z' | 'A' .. 'Z' | '_' )
            // src/csc/cslite.g:
            {
            if ( (input.LA(1)>='A' && input.LA(1)<='Z')||input.LA(1)=='_'||(input.LA(1)>='a' && input.LA(1)<='z') ) {
                input.consume();

            }
            else {
                MismatchedSetException mse = new MismatchedSetException(null,input);
                recover(mse);
                throw mse;}


            }

        }
        finally {
        }
    }
    // $ANTLR end "ALPHA"

    // $ANTLR start "NUM"
    public final void mNUM() throws RecognitionException {
        try {
            int _type = NUM;
            int _channel = DEFAULT_TOKEN_CHANNEL;
            // src/csc/cslite.g:333:5: ( ( DIGIT )+ )
            // src/csc/cslite.g:333:7: ( DIGIT )+
            {
            // src/csc/cslite.g:333:7: ( DIGIT )+
            int cnt4=0;
            loop4:
            do {
                int alt4=2;
                int LA4_0 = input.LA(1);

                if ( ((LA4_0>='0' && LA4_0<='9')) ) {
                    alt4=1;
                }


                switch (alt4) {
            	case 1 :
            	    // src/csc/cslite.g:333:8: DIGIT
            	    {
            	    mDIGIT(); 

            	    }
            	    break;

            	default :
            	    if ( cnt4 >= 1 ) break loop4;
                        EarlyExitException eee =
                            new EarlyExitException(4, input);
                        throw eee;
                }
                cnt4++;
            } while (true);


            }

            state.type = _type;
            state.channel = _channel;
        }
        finally {
        }
    }
    // $ANTLR end "NUM"

    // $ANTLR start "ID"
    public final void mID() throws RecognitionException {
        try {
            int _type = ID;
            int _channel = DEFAULT_TOKEN_CHANNEL;
            // src/csc/cslite.g:335:4: ( ALPHA ( ALPHA | DIGIT )* )
            // src/csc/cslite.g:335:6: ALPHA ( ALPHA | DIGIT )*
            {
            mALPHA(); 
            // src/csc/cslite.g:335:12: ( ALPHA | DIGIT )*
            loop5:
            do {
                int alt5=2;
                int LA5_0 = input.LA(1);

                if ( ((LA5_0>='0' && LA5_0<='9')||(LA5_0>='A' && LA5_0<='Z')||LA5_0=='_'||(LA5_0>='a' && LA5_0<='z')) ) {
                    alt5=1;
                }


                switch (alt5) {
            	case 1 :
            	    // src/csc/cslite.g:
            	    {
            	    if ( (input.LA(1)>='0' && input.LA(1)<='9')||(input.LA(1)>='A' && input.LA(1)<='Z')||input.LA(1)=='_'||(input.LA(1)>='a' && input.LA(1)<='z') ) {
            	        input.consume();

            	    }
            	    else {
            	        MismatchedSetException mse = new MismatchedSetException(null,input);
            	        recover(mse);
            	        throw mse;}


            	    }
            	    break;

            	default :
            	    break loop5;
                }
            } while (true);


            }

            state.type = _type;
            state.channel = _channel;
        }
        finally {
        }
    }
    // $ANTLR end "ID"

    // $ANTLR start "STRING"
    public final void mSTRING() throws RecognitionException {
        try {
            int _type = STRING;
            int _channel = DEFAULT_TOKEN_CHANNEL;
            // src/csc/cslite.g:337:8: ( '\"' (~ '\"' )* '\"' )
            // src/csc/cslite.g:337:10: '\"' (~ '\"' )* '\"'
            {
            match('\"'); 
            // src/csc/cslite.g:337:14: (~ '\"' )*
            loop6:
            do {
                int alt6=2;
                int LA6_0 = input.LA(1);

                if ( ((LA6_0>='\u0000' && LA6_0<='!')||(LA6_0>='#' && LA6_0<='\uFFFF')) ) {
                    alt6=1;
                }


                switch (alt6) {
            	case 1 :
            	    // src/csc/cslite.g:337:15: ~ '\"'
            	    {
            	    if ( (input.LA(1)>='\u0000' && input.LA(1)<='!')||(input.LA(1)>='#' && input.LA(1)<='\uFFFF') ) {
            	        input.consume();

            	    }
            	    else {
            	        MismatchedSetException mse = new MismatchedSetException(null,input);
            	        recover(mse);
            	        throw mse;}


            	    }
            	    break;

            	default :
            	    break loop6;
                }
            } while (true);

            match('\"'); 

            }

            state.type = _type;
            state.channel = _channel;
        }
        finally {
        }
    }
    // $ANTLR end "STRING"

    public void mTokens() throws RecognitionException {
        // src/csc/cslite.g:1:8: ( INT | BYTE | IF | ELSE | BREAK | LOOP | WHILE | UNTIL | FOR | WS | COMMENT | LINE_COMMENT | L_PAREN | R_PAREN | L_CURLY | R_CURLY | PLUS | MINUS | TIMES | DIVIDES | MODS | ASSIGN | SEMI | COMMA | COLON | DOT | NOT | AND | OR | EQ | NE | LE | GE | LT | GT | NUM | ID | STRING )
        int alt7=38;
        alt7 = dfa7.predict(input);
        switch (alt7) {
            case 1 :
                // src/csc/cslite.g:1:10: INT
                {
                mINT(); 

                }
                break;
            case 2 :
                // src/csc/cslite.g:1:14: BYTE
                {
                mBYTE(); 

                }
                break;
            case 3 :
                // src/csc/cslite.g:1:19: IF
                {
                mIF(); 

                }
                break;
            case 4 :
                // src/csc/cslite.g:1:22: ELSE
                {
                mELSE(); 

                }
                break;
            case 5 :
                // src/csc/cslite.g:1:27: BREAK
                {
                mBREAK(); 

                }
                break;
            case 6 :
                // src/csc/cslite.g:1:33: LOOP
                {
                mLOOP(); 

                }
                break;
            case 7 :
                // src/csc/cslite.g:1:38: WHILE
                {
                mWHILE(); 

                }
                break;
            case 8 :
                // src/csc/cslite.g:1:44: UNTIL
                {
                mUNTIL(); 

                }
                break;
            case 9 :
                // src/csc/cslite.g:1:50: FOR
                {
                mFOR(); 

                }
                break;
            case 10 :
                // src/csc/cslite.g:1:54: WS
                {
                mWS(); 

                }
                break;
            case 11 :
                // src/csc/cslite.g:1:57: COMMENT
                {
                mCOMMENT(); 

                }
                break;
            case 12 :
                // src/csc/cslite.g:1:65: LINE_COMMENT
                {
                mLINE_COMMENT(); 

                }
                break;
            case 13 :
                // src/csc/cslite.g:1:78: L_PAREN
                {
                mL_PAREN(); 

                }
                break;
            case 14 :
                // src/csc/cslite.g:1:86: R_PAREN
                {
                mR_PAREN(); 

                }
                break;
            case 15 :
                // src/csc/cslite.g:1:94: L_CURLY
                {
                mL_CURLY(); 

                }
                break;
            case 16 :
                // src/csc/cslite.g:1:102: R_CURLY
                {
                mR_CURLY(); 

                }
                break;
            case 17 :
                // src/csc/cslite.g:1:110: PLUS
                {
                mPLUS(); 

                }
                break;
            case 18 :
                // src/csc/cslite.g:1:115: MINUS
                {
                mMINUS(); 

                }
                break;
            case 19 :
                // src/csc/cslite.g:1:121: TIMES
                {
                mTIMES(); 

                }
                break;
            case 20 :
                // src/csc/cslite.g:1:127: DIVIDES
                {
                mDIVIDES(); 

                }
                break;
            case 21 :
                // src/csc/cslite.g:1:135: MODS
                {
                mMODS(); 

                }
                break;
            case 22 :
                // src/csc/cslite.g:1:140: ASSIGN
                {
                mASSIGN(); 

                }
                break;
            case 23 :
                // src/csc/cslite.g:1:147: SEMI
                {
                mSEMI(); 

                }
                break;
            case 24 :
                // src/csc/cslite.g:1:152: COMMA
                {
                mCOMMA(); 

                }
                break;
            case 25 :
                // src/csc/cslite.g:1:158: COLON
                {
                mCOLON(); 

                }
                break;
            case 26 :
                // src/csc/cslite.g:1:164: DOT
                {
                mDOT(); 

                }
                break;
            case 27 :
                // src/csc/cslite.g:1:168: NOT
                {
                mNOT(); 

                }
                break;
            case 28 :
                // src/csc/cslite.g:1:172: AND
                {
                mAND(); 

                }
                break;
            case 29 :
                // src/csc/cslite.g:1:176: OR
                {
                mOR(); 

                }
                break;
            case 30 :
                // src/csc/cslite.g:1:179: EQ
                {
                mEQ(); 

                }
                break;
            case 31 :
                // src/csc/cslite.g:1:182: NE
                {
                mNE(); 

                }
                break;
            case 32 :
                // src/csc/cslite.g:1:185: LE
                {
                mLE(); 

                }
                break;
            case 33 :
                // src/csc/cslite.g:1:188: GE
                {
                mGE(); 

                }
                break;
            case 34 :
                // src/csc/cslite.g:1:191: LT
                {
                mLT(); 

                }
                break;
            case 35 :
                // src/csc/cslite.g:1:194: GT
                {
                mGT(); 

                }
                break;
            case 36 :
                // src/csc/cslite.g:1:197: NUM
                {
                mNUM(); 

                }
                break;
            case 37 :
                // src/csc/cslite.g:1:201: ID
                {
                mID(); 

                }
                break;
            case 38 :
                // src/csc/cslite.g:1:204: STRING
                {
                mSTRING(); 

                }
                break;

        }

    }


    protected DFA7 dfa7 = new DFA7(this);
    static final String DFA7_eotS =
        "\1\uffff\7\35\1\uffff\1\52\10\uffff\1\54\4\uffff\1\56\2\uffff\1"+
        "\60\1\62\3\uffff\1\35\1\64\7\35\13\uffff\1\74\1\uffff\6\35\1\103"+
        "\1\uffff\1\104\1\35\1\106\1\107\2\35\2\uffff\1\112\2\uffff\1\113"+
        "\1\114\3\uffff";
    static final String DFA7_eofS =
        "\115\uffff";
    static final String DFA7_minS =
        "\1\11\1\146\1\162\1\154\1\157\1\150\1\156\1\157\1\uffff\1\52\10"+
        "\uffff\1\75\4\uffff\1\75\2\uffff\2\75\3\uffff\1\164\1\60\1\164\1"+
        "\145\1\163\1\157\1\151\1\164\1\162\13\uffff\1\60\1\uffff\1\145\1"+
        "\141\1\145\1\160\1\154\1\151\1\60\1\uffff\1\60\1\153\2\60\1\145"+
        "\1\154\2\uffff\1\60\2\uffff\2\60\3\uffff";
    static final String DFA7_maxS =
        "\1\175\1\156\1\171\1\154\1\157\1\150\1\156\1\157\1\uffff\1\57\10"+
        "\uffff\1\75\4\uffff\1\75\2\uffff\2\75\3\uffff\1\164\1\172\1\164"+
        "\1\145\1\163\1\157\1\151\1\164\1\162\13\uffff\1\172\1\uffff\1\145"+
        "\1\141\1\145\1\160\1\154\1\151\1\172\1\uffff\1\172\1\153\2\172\1"+
        "\145\1\154\2\uffff\1\172\2\uffff\2\172\3\uffff";
    static final String DFA7_acceptS =
        "\10\uffff\1\12\1\uffff\1\15\1\16\1\17\1\20\1\21\1\22\1\23\1\25"+
        "\1\uffff\1\27\1\30\1\31\1\32\1\uffff\1\34\1\35\2\uffff\1\44\1\45"+
        "\1\46\11\uffff\1\13\1\14\1\24\1\36\1\26\1\37\1\33\1\40\1\42\1\41"+
        "\1\43\1\uffff\1\3\7\uffff\1\1\6\uffff\1\11\1\2\1\uffff\1\4\1\6\2"+
        "\uffff\1\5\1\7\1\10";
    static final String DFA7_specialS =
        "\115\uffff}>";
    static final String[] DFA7_transitionS = {
            "\2\10\2\uffff\1\10\22\uffff\1\10\1\27\1\36\2\uffff\1\21\1\30"+
            "\1\uffff\1\12\1\13\1\20\1\16\1\24\1\17\1\26\1\11\12\34\1\25"+
            "\1\23\1\32\1\22\1\33\2\uffff\32\35\4\uffff\1\35\1\uffff\1\35"+
            "\1\2\2\35\1\3\1\7\2\35\1\1\2\35\1\4\10\35\1\6\1\35\1\5\3\35"+
            "\1\14\1\31\1\15",
            "\1\40\7\uffff\1\37",
            "\1\42\6\uffff\1\41",
            "\1\43",
            "\1\44",
            "\1\45",
            "\1\46",
            "\1\47",
            "",
            "\1\50\4\uffff\1\51",
            "",
            "",
            "",
            "",
            "",
            "",
            "",
            "",
            "\1\53",
            "",
            "",
            "",
            "",
            "\1\55",
            "",
            "",
            "\1\57",
            "\1\61",
            "",
            "",
            "",
            "\1\63",
            "\12\35\7\uffff\32\35\4\uffff\1\35\1\uffff\32\35",
            "\1\65",
            "\1\66",
            "\1\67",
            "\1\70",
            "\1\71",
            "\1\72",
            "\1\73",
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
            "\12\35\7\uffff\32\35\4\uffff\1\35\1\uffff\32\35",
            "",
            "\1\75",
            "\1\76",
            "\1\77",
            "\1\100",
            "\1\101",
            "\1\102",
            "\12\35\7\uffff\32\35\4\uffff\1\35\1\uffff\32\35",
            "",
            "\12\35\7\uffff\32\35\4\uffff\1\35\1\uffff\32\35",
            "\1\105",
            "\12\35\7\uffff\32\35\4\uffff\1\35\1\uffff\32\35",
            "\12\35\7\uffff\32\35\4\uffff\1\35\1\uffff\32\35",
            "\1\110",
            "\1\111",
            "",
            "",
            "\12\35\7\uffff\32\35\4\uffff\1\35\1\uffff\32\35",
            "",
            "",
            "\12\35\7\uffff\32\35\4\uffff\1\35\1\uffff\32\35",
            "\12\35\7\uffff\32\35\4\uffff\1\35\1\uffff\32\35",
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
            return "1:1: Tokens : ( INT | BYTE | IF | ELSE | BREAK | LOOP | WHILE | UNTIL | FOR | WS | COMMENT | LINE_COMMENT | L_PAREN | R_PAREN | L_CURLY | R_CURLY | PLUS | MINUS | TIMES | DIVIDES | MODS | ASSIGN | SEMI | COMMA | COLON | DOT | NOT | AND | OR | EQ | NE | LE | GE | LT | GT | NUM | ID | STRING );";
        }
    }
 

}