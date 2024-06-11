package com.hvthao.srs;

import java.util.ArrayList;

public class Course {
	// ------------
	// Attributes.
	// ------------
	private String courseNo;
	private String courseName;
	private double credits;
	private ArrayList<Section> offeredAsSection;
	private ArrayList<Course> prerequisites;

	public boolean hasPrerequisites() {
		if (prerequisites.size() > 0)
			return true;
		else
			return false;
	}

	public Collection<Course> getPrerequisites() {
		return prerequisites;
	}

	public Section scheduleSection(char day, String time, String room, int capacity) {
		// Create a new Section (note the creative way in
		// which we are assigning a section number) ...
		Section s = new Section(offeredAsSection.size() + 1, day, time, this, room, capacity);
		// ... and then remember it!
		this.addSection(s);
		return s;
	}
}
