package csc;

import csc.codegen.CodeGen;

import org.antlr.runtime.ANTLRFileStream;
import org.antlr.runtime.CharStream;
import org.antlr.runtime.CommonTokenStream;

import org.jdom.*;

public class TestCodeGen {
    public static void main(String[] args) {
	try {
	    CharStream input = new ANTLRFileStream(args[0]);
	    csliteLexer lexer = new csliteLexer(input);
	    
	    CommonTokenStream tokens = new CommonTokenStream(lexer);
	    csliteParser parser = new csliteParser(tokens);
	    Document parser_doc = parser.program(); // parse input use the program rule
	    CodeGen codegen = new CodeGen(parser_doc);
	    System.out.printf("%s\n", codegen.genCode());
        }catch (Exception ex) {
	    System.out.println("Exception: "+ex);
	    ex.printStackTrace();
        }
    }	
}
