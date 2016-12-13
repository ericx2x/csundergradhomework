grammar cslite; 

options {
  backtrack=true;
  k=2;
}


@header {
  package csc;
  import org.jdom.*;
}

@lexer::header {
  package csc;
}

@members {
  Element newVar(String tag, Element vtype, String vname) {
    Element el = new Element(tag);
    el.addContent(vtype);
    Element e = new Element("Name");
    e.setText(vname);
    el.addContent(e);
    return el;
  }
}

/*************************************************************
 * parser
 *************************************************************/
// rule program: list of decls
program
returns [Document doc = new Document()] // create root AST tree node
@init
{ 
  Element root_e = new Element("AST_IR");
  doc.addContent(root_e);
}
: d=data_sec { root_e.addContent(d);} 
  c=code_sec { root_e.addContent(c);} EOF // add decl subtree
;

data_sec
returns [Element el = new Element("DATA_SEC")]
: (e=var_def { el.addContent(e);} )*
;

code_sec
returns [Element el = new Element("CODE_SEC")]
: (e = stmt { el.addContent(e);} )* 
;

// rule var_def: 
var_def
returns [Element el = null] 
: d = base_type ID SEMI
  { 
    el = newVar("VAR_DEF", d, $ID.text);
  }
;

// rule data_type:
base_type
returns [Element el = null]
: INT 
  { 
     el = new Element("Type");
     el.setText("int");
  }
| BYTE 
  { 
     el = new Element("Type");
     el.setText("byte");
  }
;

// rule block: { stmt_list }
block
returns [Element el = new Element("BLOCK")]
: L_CURLY ( s = stmt {el.addContent(s);} )* R_CURLY
;

// rule stmt
stmt
returns [Element el = null]
  : e = assign_stmt SEMI {el=e;}
  | e = if_else_stmt  {el=e;}
  | e = func_call SEMI  {el=e;}
  | e = block  {el=e;}
  | e = loop_until_uncond_stmt {el=e;}
  | e = while_stmt {el=e;}
  | e = for_stmt {el=e;}
  | e = break_stmt SEMI {el=e;}
  | e = not_stmt {el=e;}
  ;
  
//not_stmt
not_stmt
returns [Element el = null]
: NOT e = expr
  { 
    el = new Element("NOT");
    el.setContent(e);
  }
;

  
// rule break statement
break_stmt
returns [Element el = null]
: BREAK
  { 
    el = new Element("MY_BREAK_STMT");
  }
;

// rule for statement
for_stmt
returns [Element el = null]
@init
{ 
  String step = null;
}
: FOR i=ID L_PAREN f=NUM COLON s=NUM (COLON t=NUM {step = t.getText();})? R_PAREN b=block
  { 
    el = new Element("MY_FOR_STMT");
            
    el.addContent((new Element("ID")).setText(i.getText()));
    el.addContent((new Element("FIRST")).setText(f.getText()));
    el.addContent((new Element("LAST")).setText(s.getText()));
   
    if ( step != null ) 
      el.addContent((new Element("STEP")).setText(t.getText()));

          
    el.addContent(b);
          
  }
;

// rule while statement
while_stmt
returns [Element el = null]
: LOOP WHILE L_PAREN e = expr R_PAREN b=block
  { 
    el = new Element("MY_WHILE_STMT");
        
    el.addContent((new Element("WHILE")).setContent(e));
    el.addContent(b);
          
  }
;

// rule loop statement
loop_until_uncond_stmt
returns [Element el = null]
@init{ int is_until = 0; }
: LOOP b=block (UNTIL L_PAREN e=expr R_PAREN {is_until = 1;})?
  { 
    el = new Element("MY_LOOP_STMT");       
                    
    if ( is_until == 1 )
      el.addContent((new Element("UNTIL")).setContent(e));      
          
    el.addContent(b);
                
  }
;

// rule assignment stmt
assign_stmt 
returns [Element el = null]
: ID ASSIGN e=expr
   { 
    el = new Element("ASSIGN_STMT");
    Element v = new Element("Var");
    v.setText($ID.getText());
    el.addContent(v);
    el.addContent(e);
   }
  ;

// rule if-else stmt
if_else_stmt
returns [Element el = null]
: IF L_PAREN e = expr R_PAREN s1 = stmt ELSE s2 = stmt
  { 
    el = new Element("IF_ELSE_STMT");
    el.addContent(e);
    el.addContent(s1);
    el.addContent(s2);
   }
;

// rule call stmt
func_call
returns [Element el = new Element("CALL_STMT")]
@init{ Element func_e;
  String func_name=null;
}
  : i=ID {func_name = i.getText();} 
    (DOT i2=ID {func_name += "."+i2.getText();} )*
    { func_e = new Element("Name");
      func_e.setText(func_name);
      el.addContent(func_e); } 
    L_PAREN (e1 = expr {el.addContent(e1);} (COMMA e2 = expr {el.addContent(e2);} )*)? R_PAREN
  ;


// rule arithmetic expression
expr
returns [Element el = null]
@init{ Element left_e = null;
  boolean one_sub = true;}
: e = term {left_e = e; }
  ((PLUS { el = new Element("PLUS_EXPR"); el.addContent(left_e);}
    |MINUS { el = new Element("MINUS_EXPR"); el.addContent(left_e);} 
    |EQ { el = new Element("EQUALS_EXPR"); el.addContent(left_e);}
    |NE { el = new Element("NOT_EQUAL_EXPR"); el.addContent(left_e);}
    |GT { el = new Element("GT_EXPR"); el.addContent(left_e);}
    |LT { el = new Element("LT_EXPR"); el.addContent(left_e);}
    |LE { el = new Element("LE_EXPR"); el.addContent(left_e);}
    |GE { el = new Element("GE_EXPR"); el.addContent(left_e);}
    |AND { el = new Element("AND_EXPR"); el.addContent(left_e);}
    |OR { el = new Element("OR_EXPR"); el.addContent(left_e);}
    |NOT { el = new Element("NOT_EXPR"); el.addContent(left_e);})
                  
    e = term { el.addContent(e); left_e = el; one_sub = false; } )*
   { 
      if (one_sub) 
       el = left_e;
   }                             
;

term 
returns [Element el = null]
@init{ Element left_e = null; 
  boolean one_sub = true;}
  : e = factor {left_e = e; }
   (((TIMES  { el = new Element("TIMES_EXPR"); el.addContent(left_e);})
                    |(DIVIDES  { el = new Element("DIVIDES_EXPR"); el.addContent(left_e);})
                    |(MODS  { el = new Element("MODS_EXPR"); el.addContent(left_e);}) ) 
                    e = factor { el.addContent(e); left_e = el; one_sub = false; } )*
   { 
      if (one_sub) 
       el = left_e;
   }                             
  ;

factor
returns [Element el = null]
  : id=ID
   { el = new Element("VAR");
     el.setText(id.getText());
   }
  | i=NUM
   { el = new Element("INT");
     el.setText(i.getText());
   }
  | s=STRING
   { el = new Element("STRING");
     el.setText(s.getText());
   }
  | L_PAREN e = expr R_PAREN
   { el = e; }
  ;      

INT : 'int';
BYTE : 'byte';
IF : 'if';
ELSE : 'else';

BREAK: 'break';
LOOP: 'loop';
WHILE: 'while';
UNTIL: 'until';
FOR: 'for';

WS : (' ' | '\t' | '\n' | '\r') /* white space */
     {  $channel=HIDDEN; }
   ;

COMMENT
    :   '/*' ( options {greedy=false;} : . )* '*/' {$channel=HIDDEN;}
    ;

LINE_COMMENT
    : '//' ~('\n'|'\r')* '\r'? '\n' {$channel=HIDDEN;}
    ;

L_PAREN : '(';
R_PAREN : ')';

L_CURLY : '{';
R_CURLY : '}';

PLUS : '+';
MINUS : '-';
TIMES : '*';
DIVIDES : '/';
MODS : '%';

ASSIGN : '=';
SEMI : ';';
COMMA : ',';
COLON: ':';
DOT : '.';
NOT : '!';
AND : '&&';
OR : '||';
EQ : '==';
NE: '!=';
LE: '<=';
GE: '>=';
LT : '<';
GT : '>';

fragment
DIGIT : '0'..'9';

fragment
ALPHA : 'a'..'z' | 'A'..'Z' | '_';

NUM : (MINUS)?(DIGIT)+;

ID : ALPHA (ALPHA | DIGIT)*;

STRING : '"' (~'"')* '"'; 
