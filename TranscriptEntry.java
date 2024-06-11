package com.hvthao.srs;

public class TranscriptEntry {
	private String grade;
	private Student student;
	private Section section;
	private Transcript transcript;

	// ----------------
	// Constructor(s).
	// ----------------
	public TranscriptEntry(Student s, String grade, Section se) {
		this.setStudent(s);
		this.setSection(se);
		// Obtain the Student's transcript ...
		Transcript t = s.getTranscript();
		// ... and then link the Transcript and the TranscriptEntry
		// together bidirectionally.
		this.setTranscript(t);
		t.addTranscriptEntry(this);
	}

	public static boolean validateGrade(String grade) {
		boolean outcome = false;
		if (grade.equals("F") || grade.equals("I")) {
			outcome = true;
		}
		if (grade.startsWith("A") || grade.startsWith("B") || grade.startsWith("C") || grade.startsWith("D")) {
			if (grade.length() == 1)
				outcome = true;
			else if (grade.length() == 2) {
				if (grade.endsWith("+") || grade.endsWith("-")) {
					outcome = true;
				}
			}
		}
		return outcome;
	}

	public static boolean passingGrade(String grade) {
		boolean outcome = false;
		// First, make sure it is a valid grade.
		if (validateGrade(grade)) {
			// Next, make sure that the grade is a D or better.
			if (grade.startsWith("A") || grade.startsWith("B") || grade.startsWith("C") || grade.startsWith("D")) {
				outcome = true;
			}
		}
		return outcome;
	}
}
