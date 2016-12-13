/**
 * LastElement visitor operation class.
 * 
 * @author Zori Babroudi
 * 
 */
public class LastElement implements IListVisitor {

	/**
	 * Singleton constructor for the LastElement class.
	 */
	public static final LastElement Singleton = new LastElement();

	private LastElement() {
	}

	/**
	 * @return EmptyList.
	 */
	public Object visitEmptyList(EmptyList host, Object input) {

		return EmptyList.Singleton;

	}

	/**
	 * @return the last element object.
	 */
	public Object visitNEList(NEList host, Object input) {

		return host.invite(GetNth.Singleton, (Integer) host.invite(
				Length.Singleton, null) - 1);

	}

}
