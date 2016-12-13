/**
 * Copy visitor operation class.
 * @author Zori Babroudi
 *
 */
public class Copy implements IListVisitor {

	/**
	 * Singleton constructor for the Copy class.
	 */
	public static final Copy Singleton = new Copy();

	private Copy() {
	}

	/**
	 * @return EmptyList.
	 */
	public Object visitEmptyList(EmptyList host, Object input) {

		return EmptyList.Singleton;

	}

	/**
	 * @return a copy of the given list.
	 */
	public Object visitNEList(NEList host, Object input) {

		return new NEList(host.getFirst(), (AList) host.getRest().invite(this,
				null));

	}

}
