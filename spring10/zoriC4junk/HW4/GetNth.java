/**
 * GetNth visitor operation class.
 * 
 * @author Zori Babroudi
 * 
 */
public class GetNth implements IListVisitor {

	/**
	 * Singleton constructor for the GetNth class.
	 */
	public static final GetNth Singleton = new GetNth();

	private GetNth() {
	}

	/**
	 * @throws An
	 *             Empty List has no data.
	 */
	public Object visitEmptyList(EmptyList host, Object input) {

		throw new IllegalArgumentException("An Empty List has no data.");

	}

	/**
	 * @return the Nth element object of the list.
	 */
	public Object visitNEList(NEList host, Object input) {

		int n = (Integer) input;

		if (n == 0)
			return host.getFirst();

		return host.getRest().invite(this, n - 1);
	}

}
