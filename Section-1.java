package com.hvthao.srs;

import java.util.HashMap;

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
