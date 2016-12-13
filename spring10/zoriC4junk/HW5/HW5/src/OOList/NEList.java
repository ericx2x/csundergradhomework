package OOList;

/**
 * NEList class.
 * 
 * @author Zori Babroudi
 */
public class NEList extends Alist {

	private Object first;
	private Alist rest;

	/**
	 * NEList Public constructor.
	 * 
	 * @param a_first
	 *            The first element in the list (the one you wish to add).
	 * @param a_rest
	 *            The rest of the list.
	 */
	public NEList(Object a_first, Alist a_rest) {

		first = a_first;
		rest = a_rest;

	}

	public Object getFirst() {

		return first;

	}

	public Alist getRest() {

		return rest;

	}

	public Object invite(IListVisitor v, Object input) {

		return v.visitNEList(this, input);

	}
}
