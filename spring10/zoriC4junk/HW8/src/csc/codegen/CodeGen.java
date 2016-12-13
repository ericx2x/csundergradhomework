package csc.codegen;

import org.jdom.*;

public class CodeGen {
	private Document ast;
	private IRProgram prog;
	
	public CodeGen(Document a_ast) {
		ast = a_ast;
		prog = new IRProgram(ast.getRootElement());
	}	
	
	public String genCode() {
		return prog.genCode();
	}
}
