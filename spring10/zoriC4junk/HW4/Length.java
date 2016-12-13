/**
 * Length visitor operation class.
 * @author Zori Babroudi
 *
 */
public class Length implements IListVisitor {

	/**
	 * Singleton constructor for the Length class.
	 */
	public static final Length Singleton = new Length();

	private Length() {
	}

	/**
	 * @return integer 0.
	 */
	public Object visitEmptyList(EmptyList host, Object input) {

		return new Integer(0);

	}

	/**
	 * @return integer length.
	 */
	public Object visitNEList(NEList host, Object input) {

		return new Integer((Integer) host.getRest().invite(this, input) + 1);

	}
}
