#include "GuitarTab.h"

GuitarTab& FirstHarmony(GuitarTab& file)
{
	file.AddStave();
	file.SetString(GuitarTab::B_String)
	.AddNote({11, 11})
	.AddBarLine()
	.AddNote({12, 9, 11})
	.PrevString()	// G
	.AddNote({11})
	.NextString()	// B
	.AddNote({9})
	.AddBarLine()
	.PrevString()	// G
	.AddNote({10})
	.AddSpace(1)
	.AddNote({8, 10})
	.NextString()	// B
	.AddNote({12, 11, 9})
	.AddBarLine()
	.PrevString()	// G
	.AddNote({11, 10, 8})
	.AddSpace(2);
	return file;
}

GuitarTab& SecondHarmony(GuitarTab& file)
{
	file.AddStave();
	file.SetString(GuitarTab::G_String)
	.AddNote({7, 8, 10})
	.PrevString()	// A
	.AddSlideUp(8, 9)
	.AddSpace(2)
	.AddSlideUp(6, 8)
	.AddBarLine()
	.AddNote({6})
	.NextString()	// G
	.AddNote({7})
	.PrevString()
	.AddSpace()
	.AddNote({9})
	.NextString()
	.AddNote({7})
	.PrevString()
	.AddNote({9})
	.AddBarLine()
	.AddNote({8});

	return file;
}

GuitarTab& FirstRhythm(GuitarTab& file)
{
	file.AddStave();
	file.SetString(GuitarTab::A_String)
	.AddNote({6})
	.AddChordOrInterval({{GuitarTab::G_String, 8}, {GuitarTab::B_String, 7}})
	.AddBarLine()
	.AddNote({6})
	.AddChordOrInterval({{GuitarTab::G_String, 8}, {GuitarTab::B_String, 7}})
	.AddBarLine()

	.SetString(GuitarTab::E_String)
	.AddNote({9})
	.AddChordOrInterval({{GuitarTab::G_String, 10}, {GuitarTab::D_String, 11}})
	.AddBarLine()
	.AddNote({9})
	.AddChordOrInterval({{GuitarTab::G_String, 10}, {GuitarTab::D_String, 11}})
	.AddBarLine()

	.AddNote({6})
	.AddChordOrInterval({{GuitarTab::G_String, 7}, {GuitarTab::D_String, 6}})
	.AddBarLine()

	.AddNote({4})
	.AddChordOrInterval({{GuitarTab::G_String, 4}, {GuitarTab::D_String, 6}});

	return file;
}

GuitarTab& SecondRhythm(GuitarTab& file)
{
	file.AddStave();
	file.SetString(GuitarTab::A_String)
	.AddNote({6})
	.AddChordOrInterval({{GuitarTab::G_String, 8}, {GuitarTab::B_String, 7}})
	.AddBarLine()
	.AddNote({6})
	.AddChordOrInterval({{GuitarTab::G_String, 8}, {GuitarTab::B_String, 7}})
	.AddBarLine()

	.SetString(GuitarTab::E_String)
	.AddNote({9})
	.AddChordOrInterval({{GuitarTab::G_String, 10}, {GuitarTab::D_String, 11}})
	.AddBarLine()
	.AddNote({9})
	.AddChordOrInterval({{GuitarTab::G_String, 10}, {GuitarTab::D_String, 11}})
	.AddBarLine()

	.AddNote({6})
	.AddChordOrInterval({{GuitarTab::G_String, 7}, {GuitarTab::D_String, 6}})
	.AddBarLine()

	.AddNote({4})
	.AddChordOrInterval({{GuitarTab::G_String, 4}, {GuitarTab::D_String, 6}})
	.AddBarLine()

	.AddNote({4})
	.AddChordOrInterval({{GuitarTab::G_String, 4}, {GuitarTab::D_String, 6}});
	return file;
}

GuitarTab& ThirdRhythm(GuitarTab& file)
{
	file.AddStave();
	file.SetString(GuitarTab::A_String)
	.AddNote({6})
	.AddChordOrInterval({{GuitarTab::G_String, 8}, {GuitarTab::B_String, 7}})
	.AddBarLine()
	.AddNote({6})
	.AddChordOrInterval({{GuitarTab::G_String, 8}, {GuitarTab::B_String, 7}})
	.AddBarLine()

	.SetString(GuitarTab::E_String)
	.AddNote({9})
	.AddChordOrInterval({{GuitarTab::G_String, 10}, {GuitarTab::D_String, 11}})
	.AddBarLine()
	.AddNote({9})
	.AddChordOrInterval({{GuitarTab::G_String, 10}, {GuitarTab::D_String, 11}})
	.AddBarLine()

	.AddNote({6})
	.AddChordOrInterval({{GuitarTab::G_String, 7}, {GuitarTab::D_String, 6}})
	.AddBarLine()

	.AddNote({4})
	.AddChordOrInterval({{GuitarTab::G_String, 4}, {GuitarTab::D_String, 6}})
	.AddBarLine()

	.AddNote({4})
	.AddChordOrInterval({{GuitarTab::G_String, 4}, {GuitarTab::D_String, 6}});
	return file;
}

GuitarTab& FinalRhythm(GuitarTab& file)
{
	file.AddStave();
	file.SetString(GuitarTab::E_String)
	.AddNote({7})
	.AddChordOrInterval({{GuitarTab::G_String, 8}, {GuitarTab::D_String, 9}})
	.AddBarLine()

	.AddNote({7})
	.AddChordOrInterval({{GuitarTab::G_String, 8}, {GuitarTab::D_String, 9}})
	.AddBarLine()

	.AddNote({6})
	.AddBarLine()
	.AddChordOrInterval({{GuitarTab::G_String, 7}, {GuitarTab::D_String, 6}});
	return file;
}

int main(int argc, char const *argv[])
{
	// GuitarTab{}.Header("This is a test for GuitarTab").Body("Test of the body section of the Markdown file. We can add **Bold** and *Italic* text as well")
	// .Separator().Header("Subsection", 2).Body("We can add SubSections too!")
	// .BeginTable(3)
	// .Row({"HEADING 1", "Second Heading That is very long", " s "})
	// .Row({"Item 11", "Item 12", ""})
	// .Row({"Item 21", "Item 22", "Item 23"})
	// .Row({"Item 31", "Item 32", "Item 33"})
	// .Row({"Item 41", "Item 42", "Item 43"})
	// .Row({0, 10, 31.412})
	// .Row({31.31, "DATA", 'C'})
	// .Row({31e2f, 31.3, "float data as well"})
	// .EndTable().Write("Output.md");

	// GuitarTab{}.Header("Schedule Fall 2023").BeginTable(5)
	// .Row({"Course", "Days", "Time", "Credits", "CRNs"})
	// .Row({"Senior Project 2", "NA", "NA", 2, 15849})
	// .Row({"Individual lessions in a musical instrument (Guitar)", "NA", "NA", 1, 17813})
	// .Row({"General Elective: Introduction to Cyber Security", "MR", "11:30 - 12:45", 3, 16930})
	// .Row({"Statistical Inference", "WU", "10:00 - 11:15", 3, 17598})
	// .Row({"Total", "", "", 9, ""})
	// .EndTable()
	// .Separator()
	// .Header("CRNs", 2)
	// .Body("15849 17813 16930 17598")
	// .Write("Schedule_Fall23.md");

	GuitarTab file{};
	file.BeginGuitarTab(3).AddKey("E Minor").AddTimeSignature(4, 4);

	FirstHarmony(file);
	SecondHarmony(file).SetString(GuitarTab::B_String).AddNote({11});
	FirstHarmony(file);
	SecondHarmony(file);
	FirstRhythm(file);
	FirstRhythm(file);
	SecondRhythm(file);
	SecondRhythm(file);
	FirstHarmony(file);
	SecondHarmony(file);
	FirstRhythm(file);
	FirstRhythm(file);
	ThirdRhythm(file);
	ThirdRhythm(file);
	FirstHarmony(file);
	SecondHarmony(file).SetString(GuitarTab::B_String).AddNote({11});
	FirstHarmony(file);
	SecondHarmony(file);
	FirstRhythm(file);
	ThirdRhythm(file);
	FinalRhythm(file).EndGuitarTab().Write("Tamino indigo night.md");
	return 0;
}
