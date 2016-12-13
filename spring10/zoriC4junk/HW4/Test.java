/**
 * Main tester for the AList class using the visitor pattern.
 * 
 * @author Zori Babroudi
 * 
 */
public class Test {
	/**
	 * 
	 * @param argv
	 *            a list of integers separated by spaces to be used as the test
	 *            AList. ex. 1 2 3 4 5
	 */
	public static void main(String[] argv) {

		int i = 0;
		AList l = EmptyList.Singleton;

		while (i < argv.length) {

			int temp = Integer.parseInt(argv[argv.length - 1 - i]);
			l = new NEList(new Integer(temp), l);

			++i;

		}

		try {

			System.out.println(

			"Length visitor on list: "
					+ l.invite(Length.Singleton, null)

					+ "\nToString visitor on list: "
					+ l.invite(ToString.Singleton, null)

					+ "\nSum visitor on list: "
					+ l.invite(Sum.Singleton, null)

					+ "\nCopy of the List: "
					+ ((AList) l.invite(Copy.Singleton, null)).invite(
							ToString.Singleton, null)

					+ "\nReverse of the List: "
					+ ((AList) l.invite(Reverse.Singleton, null)).invite(
							ToString.Singleton, null)

					+ "\n2nd node of the List: "
					+ l.invite(GetNth.Singleton, 1)

					+ "\nLastElement visitor on list: "
					+ l.invite(LastElement.Singleton, null)

					+ "\nGetMax visitor on list: "
					+ l.invite(GetMax.Singleton, null)

					+ "\nFindMin visitor on list: "
					+ l.invite(FindMin.Singleton, null)

			);

		} catch (IllegalArgumentException exp) {

			System.out.println("Illegal argument exception: "
					+ exp.getMessage());

		}

		System.exit(0);

	}
}
