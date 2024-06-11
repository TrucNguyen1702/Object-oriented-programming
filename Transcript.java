package com.hvthao.srs;

import java.util.ArrayList;

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
