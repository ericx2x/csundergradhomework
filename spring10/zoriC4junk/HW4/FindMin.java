/**
 * FindMin visitor operation class.
 * 
 * @author Zori Babroudi
 * 
 */
public class FindMin implements IListVisitor {

	/**
	 * Singleton constructor for the FindMin class.
	 */
	public static final FindMin Singleton = new FindMin();

	private FindMin() {
	}

	/**
	 * @throws Empty
	 *             List has no min.
	 */
	public Object visitEmptyList(EmptyList host, Object input) {

		throw new IllegalArgumentException("Empty List has no min.");

	}

	/**
	 * @return integer min value in list.
	 */
	public Object visitNEList(NEList host, Object input) {

		return host.getRest().invite(new FindMinHelper(), host.getFirst());

	}
}

/**
 * FindMin Helper class.
 * 
 * @author Zori Babroudi
 * 
 */
class FindMinHelper implements IListVisitor {

	public Object visitEmptyList(EmptyList host, Object input) {

		return input; // input is the curr_min

	}

	public Object visitNEList(NEList host, Object input) {

		if ((Integer) host.getFirst() < (Integer) input) {

			return host.getRest().invite(this, host.getFirst());

		} else {

			return host.getRest().invite(this, input);

		}
	}
}
