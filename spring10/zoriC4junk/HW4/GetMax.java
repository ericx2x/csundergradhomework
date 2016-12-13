/**
 * GetMax visitor operation class.
 * 
 * @author Zori Babroudi
 * 
 */
public class GetMax implements IListVisitor {

	/**
	 * Singleton constructor for the GetMax class.
	 */
	public static final GetMax Singleton = new GetMax();

	private GetMax() {
	}

	/**
	 * @throws An
	 *             Empty List has no max.
	 */
	public Object visitEmptyList(EmptyList host, Object input) {

		throw new IllegalArgumentException("An Empty List has no max.");

	}

	/**
	 * @return integer max.
	 */
	public Object visitNEList(NEList host, Object input) {

		return host.getRest().invite(new GetMaxHelper(), host.getFirst());

	}

}

/**
 * GetMax Helper class.
 * 
 * @author Zori Babroudi
 * 
 */
class GetMaxHelper implements IListVisitor {

	public Object visitEmptyList(EmptyList host, Object input) {

		return input;

	}

	public Object visitNEList(NEList host, Object input) {

		if ((Integer) host.getFirst() > (Integer) input)
			return host.getRest().invite(new GetMaxHelper(), host.getFirst());

		return host.getRest().invite(new GetMaxHelper(), input);

	}

}
