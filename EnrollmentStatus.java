package com.hvthao.srs;

public enum EnrollmentStatus {
	// Enumerate the values that the enum can assume.
	success("enrollment successful! :o)"), secFull("enrollment failed: section was full. :op"),
	prereq("enrollment failed; prerequisites not satisfied. :op"),
	prevEnroll("enrollment failed; previously enrolled. :op");

	// This represents the value of an enum instance.
	private final String value;

	// A "constructor" of sorts (used above).
	EnrollmentStatus(String value) {
		this.value = value;
	}

	// Accessor for the value of an enum instance.
	public String value() {
		return value;
	}
}
