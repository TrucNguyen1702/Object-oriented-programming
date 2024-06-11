Course.java
Person.java
Professor.java
ScheduleOfClasses.java
Section.java
Student.java
Transcript.java
TranscriptEntry.java
public abstract class Person {
	// ------------
	// Attributes.
	// ------------
	private String name;
	private String ssn;

	// ----------------
	// Constructor(s).
	// ----------------
	public Person(String name, String ssn) {
		this.setName(name);
		this.setSsn(ssn);
	}

	public Person() {
		this.setName("?");
		this.setSsn("???-??-????");
	}

	// ------------------
	// Accessor methods.
	// ------------------
	public void setName(String n) {
		name = n;
	}

	public String getName() {
		return name;
	}

	public void setSsn(String s) {
		ssn = s;
	}

	public String getSsn() {
		return ssn;
	}

	// -----------------------------
	// Miscellaneous other methods.
	// -----------------------------
	// We'll let each subclass determine how it wishes to be
	// represented as a String value.
	public abstract String toString();

	public void display() {
		System.out.println("Person Information:");
		System.out.println("\tName: " + this.getName());
		System.out.println("\tSoc. Security No.: " + this.getSsn());
	}
}
public class Professor extends Person {
	// ------------
	// Attributes.
	// ------------
	private String title;
	private String department;
	private ArrayList<Section> teaches;

	public void agreeToTeach(Section s) {
		teaches.add(s);
		// We want to link these objects bidirectionally.
		s.setInstructor(this);
	}
	
	@Override
	public String toString() {
		// TODO Auto-generated method stub
		return null;
	}

}
public class Student extends Person {
	// ------------
	// Attributes.
	// ------------
	private String major;
	private String degree;
	private Transcript transcript;
	private ArrayList<Section> attends;

	public void addSection(Section s) {
		this.attends.add(s);
	}

	public void dropSection(Section s) {
		this.attends.remove(s);
	}

	// Determine whether the Student is already enrolled in THIS
	// EXACT Section.
	public boolean isEnrolledIn(Section s) {
		if (this.attends.contains(s))
			return true;
		else
			return false;
	}

	public void printTranscript() {
		this.getTranscript().display();
	}

	public void displayCourseSchedule() {
		// Display a title first.
		System.out.println("Course Schedule for " + this.getName());
		// Step through the ArrayList of Section objects,
		// processing these one by one.
		for (Section s : this.attends) {
			// Since the attends ArrayList contains Sections that the
			// Student took in the past as well as those for which
			// the Student is currently enrolled, we only want to
			// report on those for which a grade has not yet been
			// assigned.
			if (s.getGrade(this) == null) {
				System.out.println("\tCourse No.: " + s.getRepresentedCourse().getCourseNo());
				System.out.println("\tSection No.: " + s.getSectionNo());
				System.out.println("\tCourse Name: " + s.getRepresentedCourse().getCourseName());
				System.out.println("\tMeeting Day and Time Held: " + s.getDayOfWeek() + " - " + s.getTimeOfDay());
				System.out.println("\tRoom Location: " + s.getRoom());
				System.out.println("\tProfessor's Name: " + s.getInstructor().getName());
				System.out.println("\t-----");
			}
		}
	}

	// ----------------
	// Constructor(s).
	// ----------------
	public Student(String name, String ssn, String major, String degree) {
		// Reuse the code of the parent's constructor.
		super(name, ssn);
		this.setMajor(major);
		this.setDegree(degree);

		// Create a brand new Transcript to serve as this Student's
		// transcript.
		this.setTranscript(new Transcript(this));
		// Note that we're instantiating empty support Collection(s).
		this.attends = new ArrayList<Section>();
	}

	public Student(String ssn) {
		// Reuse the code of the first Student constructor.
		this("TBD", ssn, "TBD", "TBD");
	}

	// ------------------
	// Accessor methods.
	// ------------------
	public void setMajor(String major) {
		this.major = major;
	}

	public String getMajor() {
		return major;
	}

	public void setDegree(String degree) {
		this.degree = degree;
	}

	public String getDegree() {
		return degree;
	}

	public void setTranscript(Transcript t) {
		transcript = t;
	}

	public Transcript getTranscript() {
		return transcript;
	}

	public Collection<Section> getEnrolledSections() {
		return attends;
	}

	public void display() {
		// First, let's display the generic Person info.
		super.display();
		// Then, display Student-specific info.
		System.out.println("Student-Specific Information:");
		System.out.println("\tMajor: " + this.getMajor());
		System.out.println("\tDegree: " + this.getDegree());
		this.displayCourseSchedule();
		this.printTranscript();
		// Finish with a blank line.
		System.out.println();
	}

	// For a Student, we wish to return a String as follows:
	//
	// Joe Blow (123-45-6789) [Master of Science - Math]
	@Override
	public String toString() {
		return this.getName() + " (" + this.getSsn() + ") [" + this.getDegree() + " - " + this.getMajor() + "]";
	}

}
mport java.util.HashMap;

public class Section {
	// ------------
	// Attributes.
	// ------------
	private int sectionNo;
	private char dayOfWeek;
	private String timeOfDay;
	private String room;
	private int seatingCapacity;

	private Course representedCourse;
	private ScheduleOfClasses offeredIn;
	private Professor instructor;

	// The enrolledStudents HashMap stores Student object references,
	// using each Student's ssn as a String key.
	private HashMap<String, Student> enrolledStudents;

	// The assignedGrades HashMap stores TranscriptEntry object
	// references, using a reference to the Student to whom it belongs
	// as the key.
	private HashMap<Student, TranscriptEntry> assignedGrades;

	public EnrollmentStatus enroll(Student s) {
		// First, make sure that this Student is not already
		// enrolled for this Section, and that he/she has
		// NEVER taken and passed the course before.
		Transcript transcript = s.getTranscript();
		if (s.isEnrolledIn(this) || transcript.verifyCompletion(this.getRepresentedCourse())) {
			return EnrollmentStatus.prevEnroll;
		}

		// If there are any prerequisites for this course,
		// check to ensure that the Student has completed them.
		Course c = this.getRepresentedCourse();
		if (c.hasPrerequisites()) {
			for (Course pre : c.getPrerequisites()) {
				// See if the Student's Transcript reflects
				// successful completion of the prerequisite.
				if (!transcript.verifyCompletion(pre)) {
					return EnrollmentStatus.prereq;
				}
			}
		}
		// If the total enrollment is already at the
		// the capacity for this Section, we reject this
		// enrollment request.
		if (!this.confirmSeatAvailability()) {
			return EnrollmentStatus.secFull;
		}
		// If we made it to here in the code, we're ready to
		// officially enroll the Student.

		// Note bidirectionality: this Section holds
		// on to the Student via the HashMap, and then
		// the Student is given a handle on this Section.
		enrolledStudents.put(s.getSsn(), s);
		s.addSection(this);
		return EnrollmentStatus.success;
	}

	public boolean drop(Student s) {
		// We may only drop a student if he/she is enrolled.
		if (!s.isEnrolledIn(this))
			return false;
		else {
			// Find the student in our HashMap, and remove it.
			enrolledStudents.remove(s.getSsn());
			// Note bidirectionality.
			s.dropSection(this);
			return true;
		}
	}

	public boolean postGrade(Student s, String grade) {
		// First, validate that the grade is properly formed by calling
		// a utility method provided by the TranscriptEntry class.
		if (!TranscriptEntry.validateGrade(grade)) return false;

		// Make sure that we haven't previously assigned a
		// grade to this Student by looking in the HashMap
		// for an entry using this Student as the key. If
		// we discover that a grade has already been assigned,
		// we return a value of false to indicate that
		// we are at risk of overwriting an existing grade.
		// (A different method, eraseGrade(), can then be written
		// to allow a Professor to change his/her mind.)
		if (assignedGrades.get(s) != null)
			return false;

		// First, we create a new TranscriptEntry object. Note
		// that we are passing in a reference to THIS Section,
		// because we want the TranscriptEntry object,
		// as an association class ..., to maintain
		// "handles" on the Section as well as on the Student.
		// (We'll let the TranscriptEntry constructor take care of
		// linking this T.E. to the correct Transcript.)
		TranscriptEntry te = new TranscriptEntry(s, grade, this);

		// Then, we "remember" this grade because we wish for
		// the connection between a T.E. and a Section to be
		// bidirectional.
		assignedGrades.put(s, te);
		return true;
	}

	public String getGrade(Student s) {
		String grade = null;
		// Retrieve the associated TranscriptEntry object for this specific
		// student from the assignedGrades HashMap, if one exists, and in turn
		// retrieve its assigned grade.
		TranscriptEntry te = assignedGrades.get(s);
		if (te != null) {
			grade = te.getGrade();
		}
		// If we found no TranscriptEntry for this Student, a null value
		// will be returned to signal this.
		return grade;
	}

	private boolean confirmSeatAvailability() {
		if (enrolledStudents.size() < this.getSeatingCapacity())
			return true;
		else
			return false;
	}
}
public class Transcript {
	private ArrayList<TranscriptEntry> transcriptEntries;
	private Student studentOwner;

	public boolean verifyCompletion(Course c) {
		boolean outcome = false;
		// Step through all TranscriptEntries, looking for one
		// that reflects a Section of the Course of interest.
		for (TranscriptEntry te : transcriptEntries) {
			Section s = te.getSection();
			if (s.isSectionOf(c)) {
				// Ensure that the grade was high enough.
				if (TranscriptEntry.passingGrade(te.getGrade())) {
					outcome = true;
					// We've found one, so we can afford to
					// terminate the loop now.
					break;
				}
			}
		}
	}
}