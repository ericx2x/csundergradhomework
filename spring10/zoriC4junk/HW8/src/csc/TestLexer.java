package csc;

import java.io.*;

import org.antlr.runtime.ANTLRFileStream;
import org.antlr.runtime.Token;

import org.jdom.*;
import org.jdom.input.*;
import org.jdom.output.*;
import jdomtool.*;

public class TestLexer {	
    public static void main(String[] args) {
	try {
	    // initialize Token XML tree
	    Document lexer_doc = new Document();
	    Element root = new Element("TokenIR");
	    lexer_doc.addContent(root);
	    
	    //			CSLexer lexer = new CSLexer(new DataInputStream(new FileInputStream(args[0])));
	    csliteLexer lexer = new csliteLexer(new ANTLRFileStream(args[0]));
	    boolean done = false;
	    while (!done) {
		Token token = lexer.nextToken();
		// print out token stream
		System.out.printf("token type:(%s), token text:'%s'\n",token.getType(), token.getText());
		
		// create token tree node
		Element et = new Element("token");
		
		if (token.getType() == csliteParser.EOF) {
		    done = true;
		    et.setAttribute("type", "EOF");			
		    et.setAttribute("text", "EOF");
		} else {
		    et.setAttribute("type", csliteParser.tokenNames[token.getType()]);				
		    et.setAttribute("text", token.getText());
		}
		root.addContent(et);
	    }
	    
	    // print XML tree to stdout and file
	    XMLOutputter out = new XMLOutputter(Format.getPrettyFormat());
	    out.output(lexer_doc, System.out);
	    out.output(lexer_doc, new FileWriter(args[0]+".token.xml"));
	    
	    // read XML file, display GUI tree view
	    Document lexer_back = new SAXBuilder().build(new File(args[0]+".token.xml"));
	    new XMLTreeView(lexer_back, "File:"+args[0]);
        }catch (Exception ex) {
	    System.out.println("Exception: "+ex);
        }
    }	
}
