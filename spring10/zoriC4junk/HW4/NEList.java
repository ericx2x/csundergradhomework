/**
 * NEList class.
 * 
 * @author Zori Babroudi
 */
public class NEList extends AList {

	private Object first;
	private AList rest;

	/**
	 * NEList Public constructor.
	 * 
	 * @param a_first
	 *            The first element in the list (the one you wish to add).
	 * @param a_rest
	 *            The rest of the list.
	 */
	public NEList(Object a_first, AList a_rest) {

		first = a_first;
		rest = a_rest;

	}

	public Object getFirst() {

		return first;

	}

	public AList getRest() {

		return rest;

	}

	public Object invite(IListVisitor v, Object input) {

		return v.visitNEList(this, input);

	}
}
