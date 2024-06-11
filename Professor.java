package com.hvthao.srs;

import java.util.ArrayList;

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
