package com.hvthao.srs;

import java.util.ArrayList;

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
