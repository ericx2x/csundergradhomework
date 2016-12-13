/**
 * Reverse visitor operation class.
 * 
 * @author Zori Babroudi
 * 
 */
public class Reverse implements IListVisitor {

	/**
	 * Singleton constructor for the Reverse class.
	 */
	public static final Reverse Singleton = new Reverse();

	private Reverse() {
	}

	/**
	 * @return an EmptyList.
	 */
	public Object visitEmptyList(EmptyList host, Object input) {

		return EmptyList.Singleton;

	}

	/**
	 * @return a reverse of the given list.
	 */
	public Object visitNEList(NEList host, Object input) {

		AList tlist = EmptyList.Singleton;

		return host.invite(new ReverseListHelper(), tlist);
	}

}

/**
 * The Reverse Helper class.
 * 
 * @author Zori Babroudi
 * 
 */
class ReverseListHelper implements IListVisitor {

	public Object visitEmptyList(EmptyList host, Object input) {

		return input;

	}

	public Object visitNEList(NEList host, Object input) {

		AList t2list = new NEList(host.getFirst(), (AList) input);

		return host.getRest().invite(new ReverseListHelper(), t2list);

	}

}