package csc.codegen;

import org.jdom.*;

import java.util.*;

public abstract class IRNode {
	public abstract String genCode();
}

class StmtBuilder {
	public static IRNode newIRStmt(Element e) {
		if (e.getName().equals("ASSIGN_STMT")) {
			return new IRAssign(e);
		} else if (e.getName().equals("CALL_STMT")) {
			return new IRCall(e);
		}
		if (e.getName().equals("IF_ELSE_STMT")) {
			return new IRIfElse(e);
		}
		if (e.getName().equals("MY_LOOP_STMT")) {
			return new IRLoop(e);
		}
		if (e.getName().equals("MY_WHILE_STMT")) {
			return new IRWhile(e);
		}
		if (e.getName().equals("MY_FOR_STMT")) {
			return new IRFor(e);
		} else if (e.getName().equals("BLOCK")) {
			return new IRBlock(e);
		} else if (e.getName().equals("MY_BREAK_STMT")) {
			return new IRBreak();
		} else {
			throw new IllegalArgumentException("Unsupported Stmt: " + e);
		}
	}
}

class ExprBuilder {
	public static IRNode newIRExpr(Element e) {
		if (e.getName().equals("VAR")) {
			return new IRExprVar(e);
		} else if (e.getName().equals("INT")) {
			return new IRExprInt(e);
		} else if (e.getName().equals("STRING")) {
			return new IRExprString(e);
		} else if (e.getName().equals("INT")) {
			return new IRExprInt(e);
		} else if (e.getName().equals("NOT_EXPR")) {
			return new IRExprNot(e);
		} else
			return new IRExprBinop(e);
	}
}

class IRExprNot extends IRNode {

	IRExprNot(Element e) {

	}

	public String genCode() {

		return null;
	}
}

class IRProgram extends IRNode {
	IRDataSec dsec;
	IRCodeSec csec;

	IRProgram(Element e) {
		dsec = new IRDataSec((Element) e.getChildren().get(0));
		csec = new IRCodeSec((Element) e.getChildren().get(1));
	}

	private String genPrologue() {
		StringBuffer code = new StringBuffer();

		code.append("' {$STAMP BS2}\n");
		code.append("' {$PBASIC 2.5}\n\n");

		code.append("light_right_pin PIN 0\n");
		code.append("light_center_pin PIN 1\n");
		code.append("light_left_pin PIN 2\n");
		code.append("line_enable_pin PIN 3\n");
		code.append("line_right_pin PIN 4\n");
		code.append("line_left_pin PIN 5\n");
		code.append("obj_recv_pin PIN 6\n");
		code.append("stall_pin PIN 7\n");
		code.append("LED_right PIN 8\n");
		code.append("LED_center PIN 9\n");
		code.append("LED_left PIN   10\n");
		code.append("speaker_pin PIN 11\n");
		code.append("motor_right_pin PIN 12\n");
		code.append("motor_left_pin PIN 13\n");
		code.append("obj_send_right_pin PIN 14\n");
		code.append("obj_send_left_pin PIN 15\n");

		return code.toString();
	}

	private String genEpilogue() {
		StringBuffer code = new StringBuffer();
		code.append("END").append("\n");
		return code.toString();
	}

	public String genCode() {
		StringBuffer code = new StringBuffer();
		code.append(this.genPrologue());
		code.append("\n");
		code.append(dsec.genCode());
		code.append("\n");
		code.append(csec.genCode());
		code.append("\n");
		code.append(this.genEpilogue());

		return code.toString();
	}
}

class IRDataSec extends IRNode {
	List<IRNode> var_def_list;

	IRDataSec(Element e) {
		assert (e.getName().equals("DATA_SEC"));

		var_def_list = new ArrayList<IRNode>();

		for (Object o : e.getChildren()) {
			Element child = (Element) o;
			assert (child.getName().equals("VAR_DEF"));
			// System.out.printf("gen var def:\n %s\n", child);
			var_def_list.add(new IRVarDef(child));
		}
	}

	public String genCode() {
		StringBuffer code = new StringBuffer();
		for (IRNode v : var_def_list) {
			code.append(v.genCode());
			code.append("\n");
		}
		return code.toString();
	}
}

class IRCodeSec extends IRNode {
	IRStmtList stmt_list;

	IRCodeSec(Element e) {
		assert (e.getName().equals("CODE_SEC"));
		stmt_list = new IRStmtList();

		for (Object o : e.getChildren()) {
			Element child = (Element) o;
			// System.out.printf("gen stmt:\n %s\n", child);
			stmt_list.addStmt(child);
		}
	}

	public String genCode() {
		StringBuffer code = new StringBuffer();
		code.append(stmt_list.genCode());
		return code.toString();
	}
}

class IRStmtList extends IRNode {
	private List<IRNode> stmt_list;

	IRStmtList() {
		stmt_list = new ArrayList<IRNode>();
	}

	void addStmt(Element e) {
		stmt_list.add(StmtBuilder.newIRStmt(e));
	}

	public String genCode() {
		StringBuffer code = new StringBuffer();
		for (IRNode s : stmt_list) {
			code.append(s.genCode());
		}
		return code.toString();
	}
}

enum VarType {
	TYPE_INT, TYPE_BYTE
}

class IRVarDef extends IRNode {
	private VarType vtype;
	private String vname;

	private VarType getType(Element type_e) {
		if (type_e.getText().equals("int")) {
			return VarType.TYPE_INT;
		} else if (type_e.getText().equals("byte")) {
			return VarType.TYPE_BYTE;
		} else {
			throw new IllegalArgumentException("Unknown type node: " + type_e);
		}
	}

	private String getBSType() {
		switch (vtype) {
		case TYPE_INT:
			return "WORD";
		case TYPE_BYTE:
			return "BYTE";
		default:
			throw new IllegalArgumentException("Cannot happen");
		}
	}

	IRVarDef(Element e) {
		Element type_e = (Element) e.getChildren().get(0);
		vtype = getType(type_e);
		Element name_e = (Element) e.getChildren().get(1);
		vname = name_e.getText();
	}

	public String genCode() {
		StringBuffer code = new StringBuffer();
		code.append(vname).append(" VAR ").append(getBSType());
		return code.toString();
	}
}

class IRAssign extends IRNode {
	private String vname;
	private IRNode expr;

	IRAssign(Element e) {
		Element var_e = (Element) e.getChildren().get(0);
		vname = var_e.getText();
		Element expr_e = (Element) e.getChildren().get(1);
		expr = ExprBuilder.newIRExpr(expr_e);
	}

	public String genCode() {
		StringBuffer code = new StringBuffer();
		code.append(vname).append(" = ").append(expr.genCode()).append("\n");
		return code.toString();
	}
}

class IRIfElse extends IRNode {
	private IRNode cond_expr;
	private IRNode true_stmt;
	private IRNode false_stmt;

	IRIfElse(Element e) {
		if (e.getChildren().size() != 3)
			throw new IllegalArgumentException("Error if-then-else: " + e);

		Element c_e = (Element) e.getChildren().get(0);
		// System.out.printf("cond e:%s\n", c_e);
		cond_expr = ExprBuilder.newIRExpr(c_e);

		Element t_e = (Element) e.getChildren().get(1);
		true_stmt = StmtBuilder.newIRStmt(t_e);
		Element f_e = (Element) e.getChildren().get(2);
		false_stmt = StmtBuilder.newIRStmt(f_e);
	}

	public String genCode() {
		StringBuffer code = new StringBuffer();
		code.append("IF (").append(cond_expr.genCode()).append(") THEN")
				.append("\n");
		code.append(true_stmt.genCode());
		code.append("ELSE").append("\n");
		code.append(false_stmt.genCode());
		code.append("ENDIF\n");

		return code.toString();
	}
}

class IRCall extends IRNode {
	private String func_name;
	private List<IRNode> arg_list;

	IRCall(Element e) {
		arg_list = new ArrayList<IRNode>();

		Element func_e = (Element) e.getChildren().get(0);
		func_name = func_e.getText();
		for (int i = 1; i < e.getChildren().size(); i++) {
			Element expr_e = (Element) e.getChildren().get(i);
			IRNode expr = ExprBuilder.newIRExpr(expr_e);
			arg_list.add(expr);
		}
	}

	private String genScribblerWait() {
		StringBuffer code = new StringBuffer();
		code.append("PAUSE ");
		code.append(arg_list.get(0).genCode());
		code.append("\n");

		return code.toString();
	}

	private String genScribblerSound() {

		StringBuffer code = new StringBuffer();
		code.append("FREQOUT speaker_pin, ");
		code.append(arg_list.get(1).genCode()).append(", ");
		code.append(arg_list.get(0).genCode());
		if (arg_list.size() == 3)
			code.append(", ").append(arg_list.get(2).genCode());
		code.append("\n");

		return code.toString();

	}

	private String genScribblerInput() {

		StringBuffer code = new StringBuffer();
		code.append("DEBUGIN ");
		boolean first = true;
		String arg_code;
		for (Iterator<IRNode> it = arg_list.iterator(); it.hasNext(); code
				.append(arg_code)) {
			IRNode e = (IRNode) it.next();
			if (!first)
				code.append(", ");
			else
				first = false;
			arg_code = e.genCode();
			code.append("DEC ");
		}

		code.append("\n");
		return code.toString();

	}

	private String genScribblerSenseStall() {

		StringBuffer code = new StringBuffer();
		code.append("\n").append(((IRNode) arg_list.get(0)).genCode()).append(
				" = stall_pin\n");
		return code.toString();

	}

	private String genScribblerSenseLight() {

		StringBuffer code = new StringBuffer();
		code.append("FREQOUT obj_send_left_pin, 1, 38500\n");
		code.append(((IRNode) arg_list.get(0)).genCode()).append(
				" = obj_recv_pin\n");
		code.append("LOW obj_send_left_pin\n");
		code.append("\n");
		return code.toString();

	}

	private String genSystemPrint() {
		StringBuffer code = new StringBuffer();
		code.append("DEBUG ");
		for (IRNode e : arg_list) {
			String arg_code = e.genCode();
			if (!arg_code.startsWith("\""))
				code.append("DEC ");
			code.append(arg_code).append(", ");
		}
		code.append("CR\n");
		return code.toString();
	}

	private String genScribblerSenseLine() {

		StringBuffer code = new StringBuffer();
		code.append("HIGH line_enable_pin\n");
		code.append(((IRNode) arg_list.get(0)).genCode()).append(
				" = line_left_pin\n");
		code.append(((IRNode) arg_list.get(1)).genCode()).append(
				" = line_right_pin\n");
		code.append("LOW line_enable_pin\n");
		code.append("\n");
		return code.toString();

	}

	private String genScribblerSenseObjLeft() {

		StringBuffer code = new StringBuffer();
		code.append("FREQOUT obj_send_left_pin, 1, 38500\n");
		code.append(((IRNode) arg_list.get(0)).genCode()).append(
				" = obj_recv_pin\n");
		code.append("LOW obj_send_left_pin\n");
		code.append("\n");
		return code.toString();

	}

	private String genScribblerSenseObjRight() {

		StringBuffer code = new StringBuffer();
		code.append("FREQOUT obj_send_right_pin, 1, 38500\n");
		code.append(((IRNode) arg_list.get(0)).genCode()).append(
				" = obj_recv_pin\n");
		code.append("LOW obj_send_right_pin\n");
		code.append("\n");
		return code.toString();

	}

	private String genScribblerMoveForward() {

		StringBuffer code = new StringBuffer();
		code.append("PULSOUT motor_left_pin, ").append("2000+(100*(");
		code.append(((IRNode) arg_list.get(0)).genCode()).append("))\n");
		code.append("PULSOUT motor_right_pin, ").append("2000+(100*(");
		code.append(((IRNode) arg_list.get(1)).genCode()).append("))\n");
		code.append("\n");
		return code.toString();

	}

	private String genScribblerMoveBackward() {

		StringBuffer code = new StringBuffer();
		code.append("PULSOUT motor_left_pin, ").append("2000-(100*(");
		code.append(((IRNode) arg_list.get(0)).genCode()).append("))\n");
		code.append("PULSOUT motor_right_pin, ").append("2000-(100*(");
		code.append(((IRNode) arg_list.get(1)).genCode()).append("))\n");
		code.append("\n");
		return code.toString();

	}

	private String genScribblerTurnFront() {

		StringBuffer code = new StringBuffer();
		code.append("PULSOUT motor_left_pin, ").append("2000+(100*(");
		code.append(((IRNode) arg_list.get(0)).genCode()).append("))\n");
		code.append("PAUSE 1\n");
		code.append("PULSOUT motor_left_pin, (");
		code.append(((IRNode) arg_list.get(2)).genCode());
		code.append(")*4/10\n");
		code.append("PULSOUT motor_right_pin, ").append("2000+(100*(");
		code.append(((IRNode) arg_list.get(1)).genCode()).append("))\n");
		code.append("PAUSE 1\n");
		code.append("PULSOUT motor_right_pin, (");
		code.append(((IRNode) arg_list.get(2)).genCode());
		code.append(")*4/10\n");
		code.append("\n");
		return code.toString();

	}

	private String genScribblerTurnBack() {

		StringBuffer code = new StringBuffer();
		code.append("PULSOUT motor_left_pin, ").append("1000+100*(");
		code.append(((IRNode) arg_list.get(0)).genCode()).append(")\n");
		code.append("PAUSE 1\n");
		code.append("PULSOUT motor_left_pin, (");
		code.append(((IRNode) arg_list.get(2)).genCode());
		code.append(")*4/10\n");
		code.append("PULSOUT motor_right_pin, ").append("1000+100*(");
		code.append(((IRNode) arg_list.get(1)).genCode()).append(")\n");
		code.append("PAUSE 1\n");
		code.append("PULSOUT motor_right_pin, (");
		code.append(((IRNode) arg_list.get(2)).genCode());
		code.append(")*4/10\n");
		code.append("\n");
		return code.toString();

	}

	private String genScribblerStop() {

		StringBuffer code = new StringBuffer();
		code.append("PULSOUT motor_left_pin, 2000\n");
		code.append("PULSOUT motor_right_pin, 2000\n");
		code.append("\n");
		return code.toString();

	}

	private String genScribblerSetLED() {
		StringBuffer code = new StringBuffer();
		code.append("OUTPUT LED_left").append("\n");
		code.append("OUTPUT LED_center").append("\n");
		code.append("OUTPUT LED_right").append("\n");
		if (arg_list.size() != 3)
			throw new IllegalArgumentException(
					"Wrong number of args in Scribbler.setLED");

		code.append("LED_left = ").append(arg_list.get(0).genCode()).append(
				"\n");
		code.append("LED_center = ").append(arg_list.get(1).genCode()).append(
				"\n");
		code.append("LED_right = ").append(arg_list.get(2).genCode()).append(
				"\n");
		return code.toString();
	}

	public String genCode() {
		if (func_name.equals("System.Scribbler.print"))
			return genSystemPrint();
		else if (func_name.equals("System.Scribbler.setLED"))
			return genScribblerSetLED();
		else if (func_name.equals("System.Scribbler.wait"))
			return genScribblerWait();
		else if (func_name.equals("System.Scribbler.sound"))
			return genScribblerSound();
		else if (func_name.equals("System.Scribbler.input"))
			return genScribblerInput();
		else if (func_name.equals("System.Scribbler.senseStall"))
			return genScribblerSenseStall();
		else if (func_name.equals("System.Scribbler.senseLight"))
			return genScribblerSenseLight();
		else if (func_name.equals("System.Scribbler.senseObjLeft"))
			return genScribblerSenseObjLeft();
		else if (func_name.equals("System.Scribbler.senseObjRight"))
			return genScribblerSenseObjRight();
		else if (func_name.equals("System.Scribbler.senseLine"))
			return genScribblerSenseLine();
		else if (func_name.equals("System.Scribbler.moveForward"))
			return genScribblerMoveForward();
		else if (func_name.equals("System.Scribbler.moveBackward"))
			return genScribblerMoveBackward();
		else if (func_name.equals("System.Scribbler.turnFront"))
			return genScribblerTurnFront();
		else if (func_name.equals("System.Scribbler.turnBack"))
			return genScribblerTurnBack();
		else if (func_name.equals("System.Scribbler.stop"))
			return genScribblerStop();
		else
			throw new IllegalArgumentException("Unsupported function: "
					+ func_name);
	}
}

class IRBlock extends IRNode {
	IRStmtList stmt_list;

	IRBlock(Element e) {
		stmt_list = new IRStmtList();
		for (Object o : e.getChildren()) {
			Element child = (Element) o;
			stmt_list.addStmt(child);
		}
	}

	public String genCode() {
		return stmt_list.genCode();
	}
}

class IRBreak extends IRNode {
	
	public String genCode() {
		return "EXIT\n";
	}
	
}

class IRLoop extends IRNode {
	private IRNode block;
	private IRNode cond_expr;
	private boolean until;

	IRLoop(Element e) {

		if (!((e.getChildren().size() == 1) || (e.getChildren().size() == 2)))
			throw new IllegalArgumentException((new StringBuilder()).append(
					"Error for: ").append(e).toString());

		block = StmtBuilder.newIRStmt((Element) e.getChild("BLOCK"));

		if (e.getChildren().size() == 2) {

			cond_expr = ExprBuilder.newIRExpr((Element) ((Element) e
					.getChild("UNTIL")).getChildren().get(0));
			until = true;

		} else
			until = false;

	}

	public String genCode() {

		StringBuffer code = new StringBuffer();

		code.append("\nDO\n");
		code.append(block.genCode());
		code.append("LOOP ");
		if (until)
			code.append("UNTIL ").append(cond_expr.genCode()).append("\n\n");
		else
			code.append("\n\n");

		return code.toString();
	}

}

class IRWhile extends IRNode {
	private IRNode block;
	private IRNode cond_expr;

	IRWhile(Element e) {

		if (!((e.getChildren().size() == 1) || (e.getChildren().size() == 2)))
			throw new IllegalArgumentException((new StringBuilder()).append(
					"Error for: ").append(e).toString());

		block = StmtBuilder.newIRStmt((Element) e.getChild("BLOCK"));

		cond_expr = ExprBuilder.newIRExpr((Element) ((Element) e
				.getChild("WHILE")).getChildren().get(0));

	}

	public String genCode() {

		StringBuffer code = new StringBuffer();

		 code.append("\nDO WHILE "); 
		 code.append(cond_expr.genCode()).append("\n");
		 code.append(block.genCode());
		 code.append("LOOP \n\n"); 
		 
		return code.toString();
	}

}

class IRFor extends IRNode {
	private String var;
	private int first;
	private int last;
	private int step;
	private IRNode block;

	IRFor(Element e) {
		if (((e.getChildren().size() < 4) || (e.getChildren().size() > 5)))
			throw new IllegalArgumentException((new StringBuilder()).append(
					"Error for: ").append(e).toString());

		var = ((Element) e.getChild("ID")).getText();
		first = Integer.valueOf(((Element) e.getChild("FIRST")).getText());
		last = Integer.valueOf(((Element) e.getChild("LAST")).getText());
		block = StmtBuilder.newIRStmt((Element) e.getChild("BLOCK"));

		step = 1;

		if (e.getChildren().size() == 5)
			step = Integer.valueOf(((Element) e.getChild("STEP")).getText());

	}

	public String genCode() {
		StringBuffer code = new StringBuffer();

		code.append("\nFOR ").append(var).append("=").append(first).append(" TO ").append(last).append(" STEP ").append(step).append("\n");
		code.append(block.genCode());
		code.append("NEXT\n\n");

		return code.toString();
	}

}

class IRExprVar extends IRNode {
	private String vname;

	IRExprVar(Element e) {
		vname = e.getText();
	}

	public String genCode() {
		return vname;
	}
}

class IRExprString extends IRNode {
	private String s;

	IRExprString(Element e) {
		s = e.getText();
	}

	public String genCode() {
		return s;
	}
}

class IRExprInt extends IRNode {
	private int i;

	IRExprInt(Element e) {
		i = Integer.parseInt(e.getText());

	}

	public String genCode() {
		return Integer.toString(i);
	}
}

enum ExprOpcode {
	PLUS, MINUS, TIMES, DIVIDES, MODS, EQUALS, NE, LT, GT, LE, GE, AND, OR, NOT
}

class IRExprBinop extends IRNode {
	private ExprOpcode opcode;
	private IRNode op1;
	private IRNode op2;

	IRExprBinop(Element e) {
		if (e.getName().equals("PLUS_EXPR")) {
			opcode = ExprOpcode.PLUS;
		} else if (e.getName().equals("MINUS_EXPR")) {
			opcode = ExprOpcode.MINUS;
		} else if (e.getName().equals("TIMES_EXPR")) {
			opcode = ExprOpcode.TIMES;
		} else if (e.getName().equals("DIVIDES_EXPR")) {
			opcode = ExprOpcode.DIVIDES;
		} else if (e.getName().equals("MODS_EXPR")) {
			opcode = ExprOpcode.MODS;

		} else if (e.getName().equals("EQUALS_EXPR")) {
			opcode = ExprOpcode.EQUALS;

		} else if (e.getName().equals("NOT_EQUAL_EXPR")) {
			opcode = ExprOpcode.NE;

		} else if (e.getName().equals("LT")) {
			opcode = ExprOpcode.LT;

		} else if (e.getName().equals("GT")) {
			opcode = ExprOpcode.GT;

		} else if (e.getName().equals("LE")) {
			opcode = ExprOpcode.LE;

		} else if (e.getName().equals("AND")) {
			opcode = ExprOpcode.AND;

		} else if (e.getName().equals("OR")) {
			opcode = ExprOpcode.OR;

		} else if (e.getName().equals("NOT")) {
			opcode = ExprOpcode.NOT;

		} else
			throw new IllegalArgumentException("Unsupported expression: " + e);

		Element op1_e = (Element) e.getChildren().get(0);
		op1 = ExprBuilder.newIRExpr(op1_e);
		Element op2_e = (Element) e.getChildren().get(1);
		op2 = ExprBuilder.newIRExpr(op2_e);
	}

	private String getBSOpcode() {
		switch (opcode) {
		case PLUS:
			return "+";
		case MINUS:
			return "-";
		case TIMES:
			return "*";
		case DIVIDES:
			return "/";
		case MODS:
			return "//";
		case EQUALS:
			return "==";
		case NE:
			return "!=";
		case LT:
			return "<";
		case GT:
			return ">";
		case LE:
			return "<=";
		case GE:
			return ">=";
		case AND:
			return "&&";
		case OR:
			return "||";

		default:
			throw new IllegalArgumentException("Cannot happen");
		}
	}

	public String genCode() {
		StringBuffer code = new StringBuffer();
		code.append("(").append(op1.genCode()).append(")");
		code.append(this.getBSOpcode());
		code.append("(").append(op2.genCode()).append(")");

		return code.toString();
	}
}
