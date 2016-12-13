package csc;

import java.io.*;

import org.jdom.Document;
import org.jdom.input.SAXBuilder;
import org.jdom.output.Format;
import org.jdom.output.XMLOutputter;

import org.antlr.runtime.ANTLRFileStream;
import org.antlr.runtime.CharStream;
import org.antlr.runtime.CommonTokenStream;
import jdomtool.*;

public class TestParser {
    public static void main(String[] args) {
	try {
	    CharStream input = new ANTLRFileStream(args[0]);
	    csliteLexer lexer = new csliteLexer(input);

	    CommonTokenStream tokens = new CommonTokenStream(lexer);
	    csliteParser parser = new csliteParser(tokens);
	    Document parser_doc = parser.program(); // parse input use the program rule
	    // write ast tree to stdout and file
	    XMLOutputter out = new XMLOutputter(Format.getPrettyFormat());
	    out.output(parser_doc, System.out);
	    out.output(parser_doc, new FileWriter(args[0]+".ast.xml"));
	    // read ast file, display GUI tree
	    Document parser_back = new SAXBuilder().build(new File(args[0]+".ast.xml"));
	    new XMLTreeView(parser_back, "File:"+args[0]);
        }catch (Exception ex) {
	    System.out.println("Exception: "+ex);
	    ex.printStackTrace();
        }
    }	
}
