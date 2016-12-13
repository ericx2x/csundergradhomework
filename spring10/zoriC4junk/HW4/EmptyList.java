/**
 * EmptyList class.
 * 
 * @author Zori Babroudi
 * 
 */
public class EmptyList extends AList {

	/**
	 * Singleton constructor for EmptyList.
	 */
	public final static EmptyList Singleton = new EmptyList();

	private EmptyList() {
	}

	public Object getFirst() {

		throw new IllegalArgumentException("EmptyList has no first");

	}

	public AList getRest() {

		throw new IllegalArgumentException("EmptyList has no rest");

	}

	public Object invite(IListVisitor v, Object input) {

		return v.visitEmptyList(this, input);

	}
}
