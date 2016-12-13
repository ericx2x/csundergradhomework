/**
 * Sum visitor operation class.
 * 
 * @author Zori Babroudi
 * 
 */
public class Sum implements IListVisitor {

	/**
	 * Singleton constructor for the Sum class.
	 */
	public static final Sum Singleton = new Sum();

	private Sum() {
	}

	/**
	 * @throws EmptyList
	 *             has no sum.
	 */
	public Object visitEmptyList(EmptyList host, Object input) {
		throw new IllegalArgumentException("EmptyList has no sum.");
	}

	/**
	 * @return an integer, the sum.
	 */
	public Object visitNEList(NEList host, Object input) {
		return host.invite(new SumHelper(), 0);
	}
}

/**
 * Sum Helper class.
 * 
 * @author Zori Babroudi
 * 
 */
class SumHelper implements IListVisitor {
	public Object visitEmptyList(EmptyList host, Object input) {
		return new Integer(0);
	}

	public Object visitNEList(NEList host, Object input) {
		return new Integer((Integer) host.getFirst()
				+ (Integer) host.getRest().invite(this, input));
	}
}
