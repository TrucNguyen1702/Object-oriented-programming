package com.hvthao.srs;

import java.util.HashMap;

public class ScheduleOfClasses {
	private String semester;
	// This HashMap stores Section object references, using
	// a String concatenation of course no. and section no. as the
	// key, for example, "MATH101 - 1".
	private HashMap<String, Section> sectionsOffered;

	public void addSection(Section s) {
		// We formulate a key by concatenating the course no.
		// and section no., separated by a hyphen.
		String key = s.getRepresentedCourse().getCourseNo() + " - " + s.getSectionNo();
		sectionsOffered.put(key, s);
		// Bidirectionally link the ScheduleOfClasses back to the Section.
		s.setOfferedIn(this);
	}

	// The full section number is a concatenation of the
	// course no. and section no., separated by a hyphen;
	// e.g., "ART101 - 1".
	public Section findSection(String fullSectionNo) {
		return sectionsOffered.get(fullSectionNo);
	}

	public boolean isEmpty() {
		if (sectionsOffered.size() == 0)
			return true;
		else
			return false;
	}

}
