package OOList;

/**
 * Visitor Pattern Visitor Class.
 * 
 * @author Zori Babroudi
 */
public interface IListVisitor {

	/**
	 * This method defines what the visitor should do in the EmptyList case.
	 * 
	 * @param host
	 *            the List passed to the operations.
	 * @param input
	 *            the objects that are passed to the operations.
	 * @return the operation.
	 */
	public Object visitEmptyList(EmptyList host, Object input);

	/**
	 * This method defines what the visitor should do in the NEList case.
	 * 
	 * @param host
	 *            the List passed to the operations.
	 * @param input
	 *            the objects that are passed to the operations.
	 * @return the operation.
	 */
	public Object visitNEList(NEList host, Object input);

}
